type rec t =
  | Null
  | True
  | False
  | Object(list<(string, t)>)
  | Number(string)
  | String(string)
  | Array(list<t>)

let null = _ => Null
let true_ = _ => True
let false_ = _ => False
let number = number => Number(number)
let string = string => String(string)
let array = xs => Array(xs)
let object = xs => Object(xs)

let rec toString = t => {
  switch t {
  | Null => "Null"
  | True => "True"
  | False => "False"
  | Number(amount) => `Number(${amount})`
  | String(string) => `String(${string})`
  | Object(_xs) => `Object()`
  | Array(xs) => {
      let rec stringify = xs => {
        switch xs {
        | list{} => ""
        | list{head, ...rest} => toString(head) ++ stringify(rest)
        }
      }

      "[" ++ stringify(xs) ++ "]"
    }
  }
}

module Option = Belt.Option
module P = Res_parser

@val
external hexToInt: (string, @as(16) _) => int = "parseInt"

let charToString = c => c->int_of_char->Js.String.fromCharCode

let rec concatStringList = chars => {
  switch chars {
  | list{} => ""
  | list{head, ...rest} => head ++ concatStringList(rest)
  }
}

let stringifyCharList = chars => {
  chars->Belt.List.map(charToString)->concatStringList
}

let zero = P.char('0')
let oneThroughNine = P.satisfy(c => c >= '1' && '9' >= c)
let digit = zero->P.orElse(oneThroughNine)->P.map(charToString)
let digits = P.atLeastOne(digit)->P.map(concatStringList)
let sign = P.anyOf(['+', '-'])
let fraction = P.char('.')->P.andThen(digits)->P.map(((dot, digits)) => charToString(dot) ++ digits)

let exponent = {
  P.char('e')
  ->P.orElse(P.char('E'))
  ->P.andThen(P.optional(sign))
  ->P.andThen(digits)
  ->P.map((((char, sign), digits)) => {
    char->charToString ++ sign->Option.map(charToString)->Option.getWithDefault("") ++ digits
  })
}

let integer = {
  let toString = ((sign, digits)) => charToString(sign) ++ digits
  let oneThroughNineThenDigits = oneThroughNine->P.andThen(digits)->P.map(toString)
  let signThenDigit = P.char('-')->P.andThen(digit)->P.map(toString)

  let signThenOneThroughNineThenDigits = {
    P.char('-')
    ->P.andThen(oneThroughNine)
    ->P.andThen(digits)
    ->P.map((((sign, digit), rest)) => charToString(sign) ++ charToString(digit) ++ rest)
  }

  P.choice([oneThroughNineThenDigits, digit, signThenOneThroughNineThenDigits, signThenDigit])
}

let jsonNumber = {
  let fraction = P.optional(fraction)
  let exponent = P.optional(exponent)

  integer
  ->P.andThen(fraction)
  ->P.andThen(exponent)
  ->P.map((((integer, fraction), exponent)) => {
    let get = Option.getWithDefault(_, "")

    integer ++ fraction->get ++ exponent->get
  })
}

let doubleQuote = P.char('"')

let unescapedChar = {
  P.satisfy(ch =>
    switch ch {
    | '\\' | '"' | '\b' .. '\r' => false
    | _ => true
    }
  )
  ->P.map(int_of_char)
  ->P.map(Js.String.fromCharCode)
}

let escapedChar = {
  [
    ("\\\"", '"'), // quote
    ("\\\\", '\\'), // reverse solidus
    ("\\/", '/'), // solidus
    ("\\b", '\b'), // backspace
    // ("\\f", char_of_int(12) /* '\f' */), // formfeed (not implementing)
    ("\\n", '\n'), // newline
    ("\\r", '\r'), // cr
    ("\\t", '\t'), // tab
  ]
  ->Belt.Array.map(((toMatch, result)) => {
    P.string(toMatch)->P.map(_ => result->int_of_char->Js.String.fromCharCode)
  })
  ->P.choice
}

let unicodeChar = {
  let backslash = P.char('\\')
  let uChar = P.char('u')
  let hexdigit = P.satisfy(c =>
    switch c {
    | '0' .. '9' | 'a' .. 'f' | 'A' .. 'F' => true
    | _ => false
    }
  )
  let fourHexDigits = {
    hexdigit->P.andThen(hexdigit)->P.andThen(hexdigit)->P.andThen(hexdigit)
  }

  backslash
  ->P.keepRight(uChar)
  ->P.keepRight(fourHexDigits)
  ->P.map(((((a, b), c), d)) => {
    [a, b, c, d]->Obj.magic->Js.String.fromCharCodeMany->hexToInt->Js.String.fromCharCode
  })
}

let jsonString = {
  let jsChar = unescapedChar->P.orElse(escapedChar)->P.orElse(unicodeChar)

  P.many(jsChar)->P.between(doubleQuote, doubleQuote)->P.map(concatStringList)
}

let manyWhitespace = P.many(P.anyOf([' ', '\n', '\t', '\r']))

let _charToString = c => c->int_of_char->Js.String.fromCharCode

let parse = P.makeRecursive(p => {
  let comma = P.char(',')

  let jsonArray = {
    let betweenBraces = P.between(_, P.char('['), P.char(']'))
    let empty = manyWhitespace->betweenBraces->P.map(_ => list{})
    let nonEmpty = p->P.separatedBy1(comma)->betweenBraces

    P.choice([empty, nonEmpty])
  }

  let jsonObject = {
    let betweenCurlyBraces = P.between(_, P.char('{'), P.char('}'))
    let nonEmpty = {
      let keyValuePair =
        jsonString->P.between(manyWhitespace, manyWhitespace)->P.keepLeft(P.char(':'))->P.andThen(p)

      keyValuePair->P.separatedBy1(comma)->betweenCurlyBraces
    }

    let empty = {
      manyWhitespace->betweenCurlyBraces->P.map(_ => list{})
    }

    P.choice([empty, nonEmpty])
  }

  P.choice([
    P.string("null")->P.map(null),
    P.string("true")->P.map(true_),
    P.string("false")->P.map(false_),
    jsonObject->P.map(object),
    jsonArray->P.map(array),
    jsonNumber->P.map(number),
    jsonString->P.map(string),
  ])->P.between(manyWhitespace, manyWhitespace)
})
