# ReScript Parser

`@resinfo/parser` is a parser combinator library for ReScript.

### Note:

Please be aware that this is considered alpha quality software. While there is a test suite that includes a JSON parser and a simple s-expression parser, you might want to write your own tests before using in production.

## Installation

via NPM.

```
yarn add @resinfo/parser
# or
npm install --save @resinfo/parser
```

## Usage

```rescript
module P = Res_parser

// Define our AST
type sign = Plus | Subtract | Multiply
type number = SingleDigit(int)
type expression = Expression(number, sign, number)

// Parse sign and transform into AST node
type sign_ = P.t<sign>
let sign: sign_ = P.choice([
  P.char('+')->P.map(_ => Plus),
  P.char('-')->P.map(_ => Subtract),
  P.char('x')->P.map(_ => Multiply),
])

// Helper that returns any parser
// that's found to be wrapped in whitespace
type manyWhitespace = P.t<list<char>>
let manyWhitespace: manyWhitespace = P.many(P.char(' '))

// Parse single digit and transform into AST node
type singleDigit = P.t<number>
let singleDigit: singleDigit =
  P.satisfy(char => char >= '0' && char <= '9')
  ->P.map(Char.escaped)
  ->P.map(int_of_string)
  ->P.map(x => SingleDigit(x))
  ->P.between(manyWhitespace, manyWhitespace)

// Combine sign and digit parsers into fully typed AST.
type parser = P.t<expression>
let parser: parser =
  singleDigit
  ->P.andThen(sign)
  ->P.andThen(singleDigit)
  ->P.map((((left, sign), right)) => Expression(left, sign, right))

// Run our parser against an input string.
type result = result<(expression, string), string>
let result: result = P.run(parser, " 1 +  4  ")

// Result is a tuple of a valid AST and the state object.
result == Ok(Expression(SingleDigit(1), Plus, SingleDigit(4)), _)

```

## Notes:

Inspired by (and essentially converted from) the excellent [series](https://fsharpforfunandprofit.com/parser/) and [library](https://github.com/swlaschin/fsharpforfunandprofit.com_code/blob/master/posts/understanding-parser-combinators/understanding-parser-combinators.fsx) by Scott Wlaschin, originally written in F#. This was itself inspired by the equally excellent (though slightly more esoteric) [paper](https://www.cs.nott.ac.uk/~pszgmh/monparsing.pdf) by Graham Hutton and Erik Meijer on Monadic Parsers ([Haskell video](https://www.youtube.com/watch?v=dDtZLm7HIJs)).

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
