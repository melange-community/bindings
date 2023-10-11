open Belt
type t

@deriving(jsConverter)
type rgb = {
  r: int,
  g: int,
  b: int,
}

@deriving(jsConverter)
type rgba = {
  r: int,
  g: int,
  b: int,
  a: float,
}

@deriving(jsConverter)
type rgbaPercentage = {
  r: string,
  g: string,
  b: string,
  a: float,
}

@deriving(jsConverter)
type rgbRatio = {
  r: float,
  g: float,
  b: float,
}

@deriving(jsConverter)
type rgbaRatio = {
  r: float,
  g: float,
  b: float,
  a: float,
}

@deriving(jsConverter)
type hsl = {
  h: int,
  s: float,
  l: float,
}

@deriving(jsConverter)
type hsla = {
  h: int,
  s: float,
  l: float,
  a: float,
}

@deriving(jsConverter)
type hslRatio = {
  h: float,
  s: float,
  l: float,
}

@deriving(jsConverter)
type hslaRatio = {
  h: float,
  s: float,
  l: float,
  a: float,
}

@deriving(jsConverter)
type hsv = {
  h: int,
  s: float,
  v: float,
}

@deriving(jsConverter)
type hsva = {
  h: int,
  s: float,
  v: float,
  a: float,
}

@deriving(jsConverter)
type hsvRatio = {
  h: float,
  s: float,
  v: float,
}

@deriving(jsConverter)
type hsvaRatio = {
  h: float,
  s: float,
  v: float,
  a: float,
}

/* VALIDATOR UTILS */

@get external isValid: t => bool = "isValid"

let returnSomeIfValid = (color: t): option<t> =>
  if isValid(color) {
    Some(color)
  } else {
    None
  }

let isFraction = value => value >= 0.0 && value <= 1.0
let isValidHue = hue => hue >= 0 && hue <= 360

let validateColorNumber = (color: int) =>
  if color >= 0 {
    /* consider also checking if number is more than 0xffffff (16777215) */
    Some(color)
  } else {
    None
  }

let validateRgb = (color: rgb) => {
  let validRgbRange = value => value >= 0 && value <= 255
  switch color {
  | {r, g, b} if validRgbRange(r) && (validRgbRange(g) && validRgbRange(b)) => Some(color)
  | _ => None
  }
}

let validateRgba = (color: rgba) =>
  switch color {
  | {r, g, b, a} if validateRgb({r: r, g: g, b: b}) !== None && isFraction(a) => Some(color)
  | _ => None
  }

let validateHsl = (color: hsl) =>
  switch color {
  | {h, s, l} if isValidHue(h) && (isFraction(s) && isFraction(l)) => Some(color)
  | _ => None
  }

let validateHsla = (color: hsla) =>
  switch color {
  | {h, s, l, a} if validateHsl({h: h, s: s, l: l}) !== None && isFraction(a) => Some(color)
  | _ => None
  }

let validateHsv = (color: hsv) =>
  switch color {
  | {h, s, v} if isValidHue(h) && (isFraction(s) && isFraction(v)) => Some(color)
  | _ => None
  }

let validateHsva = (color: hsva) =>
  switch color {
  | {h, s, v, a} if validateHsv({h: h, s: s, v: v}) !== None && isFraction(a) => Some(color)
  | _ => None
  }

/* CREATE COLOR */

@module("@ctrl/tinycolor") external make: 'tinyColor => t = "tinycolor"

let makeFromString = (color: string) => returnSomeIfValid(make(color))
let makeFromNumber = (number: int) =>
  (number |> validateColorNumber)->Option.map(make)->Option.flatMap(returnSomeIfValid)
let makeFromRgb = (color: rgb) =>
  (color |> validateRgb)->Option.map(rgbToJs)->Option.map(make)->Option.flatMap(returnSomeIfValid)
let makeFromRgba = (color: rgba) =>
  (color |> validateRgba)->Option.map(rgbaToJs)->Option.map(make)->Option.flatMap(returnSomeIfValid)
let makeFromRgbRatio = (color: rgbRatio) => color |> rgbRatioToJs |> make |> returnSomeIfValid
let makeFromRgbaRatio = (color: rgbaRatio) => color |> rgbaRatioToJs |> make |> returnSomeIfValid
let makeFromHsl = (color: hsl) =>
  (color |> validateHsl)->Option.map(hslToJs)->Option.map(make)->Option.flatMap(returnSomeIfValid)
let makeFromHsla = (color: hsla) =>
  (color |> validateHsla)->Option.map(hslaToJs)->Option.map(make)->Option.flatMap(returnSomeIfValid)
let makeFromHslRatio = (color: hslRatio) => color |> hslRatioToJs |> make |> returnSomeIfValid
let makeFromHslaRatio = (color: hslaRatio) => color |> hslaRatioToJs |> make |> returnSomeIfValid
let makeFromHsv = (color: hsv) =>
  (color |> validateHsv)->Option.map(hsvToJs)->Option.map(make)->Option.flatMap(returnSomeIfValid)
let makeFromHsva = (color: hsva) =>
  (color |> validateHsva)->Option.map(hsvaToJs)->Option.map(make)->Option.flatMap(returnSomeIfValid)
let makeFromHsvRatio = (color: hsvRatio) => color |> hsvRatioToJs |> make |> returnSomeIfValid
let makeFromHsvaRatio = (color: hsvaRatio) => color |> hsvaRatioToJs |> make |> returnSomeIfValid

/* GET COLOR PROPERTIES */

@get external getFormat: t => string = "format"

@get external getOriginalInput: t => 'tinyColor = "originalInput"
@send external getBrightness: t => float = "getBrightness"
@send external isLight: t => bool = "isLight"
@send external isDark: t => bool = "isDark"
@send external getLuminance: t => float = "getLuminance"
@send external getAlpha: t => float = "getAlpha"
@send external setAlpha: (t, float) => t = "setAlpha"
@send external toNumber: t => int = "toNumber"
@send external clone: t => t = "clone"

let setAlpha = (alphaValue: float, color: t): t => {
  let colorClone = clone(color)
  setAlpha(colorClone, alphaValue)
}

@send external onBackground: (t, t) => t = "onBackground"

/* STRING REPRESENTATIONS */

@send external toHsv: t => 'hsv = "toHsv"
let toHsv = (color: t) => toHsv(color) |> hsvaFromJs
@send external toHsvString: t => string = "toHsvString"
@send external toHsl: t => 'hsl = "toHsl"
let toHsl = (color: t) => toHsl(color) |> hslaFromJs
@send external toHslString: t => string = "toHslString"
@send external toHex: t => string = "toHex"
@send external toHexString: t => string = "toHexString"
@send external toHex8: t => string = "toHex8"
@send external toHex8String: t => string = "toHex8String"
@send external toRgb: t => 'rgb = "toRgb"
let toRgb = (color: t) => toRgb(color) |> rgbaFromJs
@send external toRgbString: t => string = "toRgbString"
@send
external toPercentageRgb: t => 'rgbaPercent = "toPercentageRgb"
let toPercentageRgb = (color: t) => toPercentageRgb(color) |> rgbaPercentageFromJs
@send
external toPercentageRgbString: t => string = "toPercentageRgbString"
@send external toName: t => 'maybeName = "toName"
let toName = (color: t) => {
  let name = toName(color)
  if Js.typeof(name) === "string" {
    Some(name)
  } else {
    None
  }
}
@module("@ctrl/tinycolor")
external toMsFilter: (string, string) => string = "toMsFilter"

@send external toString: t => string = "toString"

/* COLOR MODIFICATION */

let callIfValidModificationValue = (value, modFun, color) =>
  if value >= 0 && value <= 100 {
    Some(modFun(color, value))
  } else {
    None
  }

@send external lighten: (t, int) => t = "lighten"
let lighten = (~value: int=10, color: t) => callIfValidModificationValue(value, lighten, color)

@send external brighten: (t, int) => t = "brighten"
let brighten = (~value: int=10, color: t) => callIfValidModificationValue(value, brighten, color)

@send external darken: (t, int) => t = "darken"
let darken = (~value: int=10, color: t) => callIfValidModificationValue(value, darken, color)

@send external tint: (t, int) => t = "tint"
let tint = (~value: int=10, color: t) => callIfValidModificationValue(value, tint, color)

@send external shade: (t, int) => t = "shade"
let shade = (~value: int=10, color: t) => callIfValidModificationValue(value, shade, color)

@send external desaturate: (t, int) => t = "desaturate"
let desaturate = (~value: int=10, color: t) =>
  callIfValidModificationValue(value, desaturate, color)

@send external saturate: (t, int) => t = "saturate"
let saturate = (~value: int=10, color: t) => callIfValidModificationValue(value, saturate, color)

@send external spin: (t, int) => t = "spin"
let spin = (~value: int=10, color: t) => spin(color, value)

@send external mix: (t, t, int) => t = "mix"
let mix = (~value: int=50, color1: t, color2: t) =>
  callIfValidModificationValue(value, mix(color1), color2)

@send external greyscale: t => t = "greyscale"

/* COLOR COMBINATIONS */

@send external analogous: (t, ~results: int=?, ~slices: int=?, unit) => array<t> = "analogous"
@send
external monochromatic: (t, ~results: int=?, unit) => array<t> = "monochromatic"
@send external splitcomplement: t => array<t> = "splitcomplement"
@send external triad: t => array<t> = "triad"
@send external tetrad: t => array<t> = "tetrad"
@send external polyad: (t, ~n: int=?, unit) => array<t> = "polyad"
@send external complement: t => t = "complement"

/* COLOR UTILITIES */

@send external equals: (t, t) => bool = "equals"

@module("@ctrl/tinycolor") external random: 'config => t = "random"
@module("@ctrl/tinycolor")
external randomMultiple: 'config => array<t> = "random"

@obj
external randomConfig: (
  ~hue: [
    | #red
    | #orange
    | #yellow
    | #green
    | #blue
    | #purple
    | #pink
    | #monochrome
  ]=?,
  ~luminosity: [#bright | #light | #dark]=?,
  ~seed: int=?,
  ~alpha: float=?,
  ~count: int=?,
  unit,
) => _ = ""

let random = (
  ~hue: option<
    [
      | #red
      | #orange
      | #yellow
      | #green
      | #blue
      | #purple
      | #pink
      | #monochrome
    ],
  >=?,
  ~luminosity: option<[#bright | #light | #dark]>=?,
  ~seed: option<int>=?,
  ~alpha: option<float>=?,
  (),
) => random(randomConfig(~hue?, ~luminosity?, ~seed?, ~alpha?, ()))

let randomMultiple = (
  ~hue: option<
    [
      | #red
      | #orange
      | #yellow
      | #green
      | #blue
      | #purple
      | #pink
      | #monochrome
    ],
  >=?,
  ~luminosity: option<[#bright | #light | #dark]>=?,
  ~seed: option<int>=?,
  ~alpha: option<float>=?,
  ~count: int,
  (),
) => randomMultiple(randomConfig(~hue?, ~luminosity?, ~seed?, ~alpha?, ~count, ()))

@module("@ctrl/tinycolor")
external readability: (t, t) => float = "readability"

@obj
external wcagOption: (~level: [#AA | #AAA]=?, ~size: [#small | #large]=?) => _ = ""

@module("@ctrl/tinycolor")
external isReadable: (t, t, 'wcagObject) => bool = "isReadable"
let isReadable = (
  ~level: option<[#AA | #AAA]>=?,
  ~size: option<[#small | #large]>=?,
  color1: t,
  color2: t,
) => isReadable(color1, color2, wcagOption(~level?, ~size?))

@obj
external mostReadableConfig: (
  ~includeFallbackColors: bool=?,
  ~level: [#AA | #AAA]=?,
  ~size: [#small | #large]=?,
) => _ = ""

@module("@ctrl/tinycolor")
external mostReadable: (t, array<t>, 'config) => t = "mostReadable"
let mostReadable = (
  ~includeFallbackColors=?,
  ~level: option<[#AA | #AAA]>=?,
  ~size: option<[#small | #large]>=?,
  compareColors: array<t>,
  color: t,
) =>
  mostReadable(color, compareColors, mostReadableConfig(~includeFallbackColors?, ~level?, ~size?))
