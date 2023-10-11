type resultObj = {
  glob: string,
  regex: Js.Re.t,
  input: string,
  output: string,
}

@deriving(abstract)
type options = {
  @optional basename: bool,
  @optional bash: bool,
  @optional contains: bool,
  @optional cwd: string,
  @optional debug: bool,
  @optional dot: bool,
  @optional expandRange: (. string, string) => string,
  @optional failglob: bool,
  @optional fastpaths: bool,
  @optional flags: string,
  @optional format: (. string) => string,
  @optional ignore: array<string>,
  @optional keepQuotes: bool,
  @optional literalBrackets: bool,
  @optional maxLength: int,
  @optional nobrace: bool,
  @optional nobracket: bool,
  @optional nocase: bool,
  @optional noextglob: bool,
  @optional noglobstar: bool,
  @optional nonegate: bool,
  @optional noquantifiers: bool,
  @optional posix: bool,
  @optional posixSlashes: bool,
  @optional prepend: string,
  @optional regex: bool,
  @optional strictBrackets: bool,
  @optional strictSlashes: bool,
  @optional unescape: bool,
  @optional onIgnore: (. resultObj) => unit,
  @optional onResult: (. resultObj) => unit,
  @optional onMatch: (. resultObj) => unit,

  // I don't quite understand what this is for,
  // but it appears to change return type of some functions.
  // Might be tricky to add.
  // If you need this, open an issue or a PR.
  //
  // @optional capture: bool
}

type matcherFn = string => bool

@module external matchAll: (array<string>, option<options>) => matcherFn = "picomatch"
@ocaml.doc("https://github.com/micromatch/picomatch#picomatch-1")
let matchAll = (~options=?, patterns) => matchAll(patterns, options)

@module external match: (string, option<options>) => matcherFn = "picomatch"
@ocaml.doc("https://github.com/micromatch/picomatch#picomatch-1")
let match = (~options=?, pattern) => match(pattern, options)

type testResult = {isMatch: bool, match: array<string>, output: bool}
@module("picomatch") @val external test: (string, Js.Re.t, option<options>) => testResult = "test"
@ocaml.doc("https://github.com/micromatch/picomatch#test")
let test = (~options=?, input, regex) => test(input, regex, options)

@module("picomatch") @val
external matchBase: (string, string, option<options>) => bool = "matchBase"
@ocaml.doc("https://github.com/micromatch/picomatch#matchbase")
let matchBase = (~options=?, input, glob) => matchBase(input, glob, options)

@module("picomatch") @val
external matchBaseRe: (string, Js.Re.t, option<options>) => bool = "matchBase"
@ocaml.doc("https://github.com/micromatch/picomatch#matchbase")
let matchBaseRe = (~options=?, input, regex) => matchBaseRe(input, regex, options)

type token = {
  value: string,
  depth: int,
  isGlob: bool,
  negated: option<bool>,
  isPrefix: option<bool>,
}
type scanResult = {
  prefix: string,
  input: string,
  start: int,
  base: string,
  glob: string,
  isBrace: bool,
  isBracket: bool,
  isGlob: bool,
  isExtglob: bool,
  isGlobstar: bool,
  negated: bool,
  tokens: option<array<token>>,
  slashes: option<array<int>>,
  parts: option<array<string>>,
}
@module("picomatch") @val external scan: (string, option<options>) => scanResult = "scan"

@ocaml.doc("https://github.com/micromatch/picomatch#scan-options")
let scanWithTokens = (~options: option<options>=?, input) =>
  switch options {
  | None => scan(input, {"tokens": true}->Obj.magic->Some)
  | Some(options) => {
      options->Obj.magic->Js.Dict.set("tokens", true)
      scan(input, Some(options))
    }
  }

@ocaml.doc("https://github.com/micromatch/picomatch#scan-options")
let scanWithParts = (~options: option<options>=?, input) =>
  switch options {
  | None => scan(input, {"parts": true}->Obj.magic->Some)
  | Some(options) => {
      options->Obj.magic->Js.Dict.set("parts", true)
      scan(input, Some(options))
    }
  }

@ocaml.doc("https://github.com/micromatch/picomatch#scan")
let scan = (~options=?, input) => scan(input, options)

// "Returns an object with useful properties and output to be used as a regex source string."
//
// Documentation doens't specify properties, so it's left as an abstract type.
// You can define getters similar to `getOutput` in your codebase if you need other properties.
type parseResult
@get external getOutput: parseResult => string = "output"

@module("picomatch") @val
external parse: (string, option<options>) => parseResult = "parse"
@ocaml.doc("https://github.com/micromatch/picomatch#parse")
let parse = (~options=?, glob) => parse(glob, options)

@module("picomatch") @val
external compileRe: (parseResult, option<options>) => Js.Re.t = "compileRe"
@ocaml.doc("https://github.com/micromatch/picomatch#compilere")
let compileRe = (~options=?, state) => compileRe(state, options)

@module("picomatch") @val
external makeRe: (string, option<options>) => Js.Re.t = "makeRe"
@ocaml.doc("https://github.com/micromatch/picomatch#makere")
let makeRe = (~options=?, compiledGlob) => makeRe(compiledGlob, options)

@module("picomatch") @val
external toRegex: (string, option<options>) => Js.Re.t = "toRegex"
@ocaml.doc("https://github.com/micromatch/picomatch#toregex")
let toRegex = (~options=?, source) => toRegex(source, options)
