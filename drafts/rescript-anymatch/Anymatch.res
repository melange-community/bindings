type matcher

external path: string => matcher = "%identity"
external glob: string => matcher = "%identity"
external regex: Js.Re.t => matcher = "%identity"
external fun: (string => bool) => matcher = "%identity"

@module
external anymatch: (array<matcher>, option<string>, option<Picomatch.options>, . string) => bool =
  "anymatch"
let anymatch = (~options=?, matchers) => {
  let fn = anymatch(matchers, None, options)
  str => fn(. str)
}

@module
external anymatchIndex: (
  array<matcher>,
  option<string>,
  option<Picomatch.options>,
  . string,
  bool,
) => int = "anymatch"
let anymatchIndex = (~options=?, matchers) => {
  let fn = anymatchIndex(matchers, None, options)
  str => fn(. str, true)
}
