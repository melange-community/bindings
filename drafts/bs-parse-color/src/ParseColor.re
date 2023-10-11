type list3 = (int, int, int);

type list4 = (int, int, int, int);

type list4f = (int, int, int, float);

type list5f = (int, int, int, int, float);

type maybeString = option(string);

type colorObject = {
  .
  "rgb": list3,
  "hsl": list3,
  "hsv": list3,
  "cmyk": list4,
  "keyword": option(string),
  "hex": option(string),
  "rgba": list4f,
  "hsla": list4f,
  "hsva": list4f,
  "cmyka": list5f,
};

type colorMode =
  | RGB(list3)
  | RGBA(list4f)
  | HSL(list3)
  | HSLA(list4f)
  | HSV(list3)
  | HSVA(list4f)
  | CMYK(list4)
  | CMYKA(list5f)
  | HEX(string)
  | KEYWORD(string);

/* require our parse-color module and bind to it as a useable variable */
[@bs.module] external parseColor: string => colorObject = "parse-color";

type color = {
  keyword: string,
  hex: string,
  rgb: list3,
  hsv: list3,
  hsl: list3,
  cmyk: list4,
  rgba: list4f,
  hsla: list4f,
  hsva: list4f,
  cmyka: list5f,
};

type parse = string => color;

let parse = v => {
  let p = parseColor(v);
  let hex =
    switch (p##hex) {
    | Some(s) => s
    | None => ""
    };
  let keyword =
    switch (p##keyword) {
    | Some(s) => s
    | None => ""
    };
  {
    rgb: p##rgb,
    rgba: p##rgba,
    hsv: p##hsv,
    hsva: p##hsva,
    hsl: p##hsl,
    hsla: p##hsla,
    cmyk: p##cmyk,
    cmyka: p##cmyka,
    hex,
    keyword,
  };
};

type asHex = color => option(string);

let asHex = v => v.hex;

type asKeyword = color => option(string);

let asKeyword = v => v.keyword;

type asRgb = color => option(list3);

let asRgb = v => v.rgb;

type asRgba = color => option(list4f);

let asRgba = v => v.rgba;

type asHsv = color => option(list3);

let asHsv = v => v.hsv;

type asHsva = color => option(list4f);

let asHsva = v => v.hsva;

type asHsl = color => option(list3);

let asHsl = v => v.hsl;

type asHsla = color => option(list4f);

let asHsla = v => v.hsla;

type asCmyk = color => option(list4);

let asCmyk = v => v.cmyk;

type asCmyka = color => option(list5f);

let asCmyka = v => v.cmyka;