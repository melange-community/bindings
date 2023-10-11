module P = Res_parser

let charListToString = chars =>
  chars->Belt.List.map(Char.escaped)->Belt.List.reduce("", Js.String2.concat)

let whitespace = P.satisfy(char => {
  switch char {
  | ' ' | '\n' | '\r' | '\t' => true
  | _ => false
  }
})

let manyWhitespace = P.many(whitespace)

type rec t =
  | Int(string)
  | String(string)
  | Exp(list<t>)

let rec toString = t => {
  switch t {
  | Int(x) => `Int(${x})`
  | String(x) => `String("${x}")`
  | Exp(exps) => {
      let rec loop = lst => {
        switch lst {
        | list{} => ""
        | list{head, ...rest} => toString(head) ++ ", " ++ loop(rest)
        }
      }

      `Exp(${loop(exps)})`
    }
  }
}

let quotedString = {
  let doubleQuote = P.char('"')
  let anyChar = P.satisfy(char => char != '"')

  P.many(anyChar)
  ->P.between(doubleQuote, doubleQuote)
  ->P.map(charListToString)
  ->P.map(s => String(s))
}

let int = {
  let digit = P.satisfy(char => char >= '0' && '9' >= char)

  P.optional(P.char('-'))
  ->P.map(Belt.Option.map(_, Char.escaped))
  ->P.map(Belt.Option.getWithDefault(_, ""))
  ->P.andThen(P.atLeastOne(digit)->P.map(charListToString))
  ->P.map(((sign, rest)) => sign ++ rest)
  ->P.map(i => Int(i))
}

let parser = P.makeRecursive(p => {
  let sexp =
    P.atLeastOne(p)
    ->P.orElse(manyWhitespace->P.map(_ => list{}))
    ->P.map(xs => Exp(xs))
    ->P.between(P.char('('), P.char(')'))

  P.choice([quotedString, int, sexp])->P.between(manyWhitespace, manyWhitespace)
})
