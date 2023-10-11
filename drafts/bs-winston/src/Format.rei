type t;

let combine: list(t) => t;

let createAlign: unit => t;

let createCli: (
  ~level: bool =?,
  ~all: bool =?,
  ~message: bool =?,
  ~colors: Js.Dict.t(string) =?,
  ~levels: Js.Dict.t(int) =?,
  unit
) => t;

let createColorize: (
  ~level: bool =?,
  ~all: bool =?,
  ~message: bool =?,
  ~colors: Js.Dict.t(string) =?,
  unit
) => t;

let createJson: (
  ~replacer: (. string, Js.Json.t) => Js.Json.t =?,
  ~space: int =?,
  unit
) => t;

let createLabel: (
  ~label: string =?,
  ~message: bool =?,
  unit
) => t;

let createLogstash: unit => t;

let createMetadata: (
  ~key: string =?,
  ~fillExcept: list(string) =?,
  ~fillWith: list(string) =?,
  unit
) => t;

let createMs: unit => t;

let createPadLevels: (
  ~levels: Js.Dict.t(int) =?,
  unit
) => t;

let createPrettyPrint: (
  ~depth: int =?,
  ~colorize: bool =?,
  unit
) => t;

let createPrintf: (Js.Json.t => string) => t;

let createSimple: unit => t;

let createSplat: unit => t;

let createTimestamp: (
  ~format: string =?,
  ~alias: string =?,
  unit
) => t;

let createUncolorize: (
  ~level: bool =?,
  ~message: bool =?,
  ~raw: bool =?,
  unit
) => t;

let fromMapFn: (Js.Dict.t(Js.Json.t) => Js.Dict.t(Js.Json.t)) => t;
