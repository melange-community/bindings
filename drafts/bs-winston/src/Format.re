type t;

/* 
 * Bucklescript do not support dynamic variadic arguments for external, the following:
 * [@bs.module "winston"] [@bs.scope "format"] [@bs.variadic] external combineExt: array(t) => t = "combine";
 * fails with Belt.List.toArray(formats):
 *     "Error: function call with [@@bs.val "combineExt"]  is a primitive with [@bs.splice], it expects its
 *      `bs.splice` argument to be a syntactic array in the call site and  all arguments to be supplied"
 * 
 * Therefore resorting to raw:
 */
let combineExt: (. array(t)) => t = [%bs.raw {|
  function (formats) {
    return require('winston').format.combine(...formats);
  }
|}];

let combine = formats => combineExt(. Belt.List.toArray(formats));


[@bs.module "winston"] [@bs.scope "format"] external alignExt: unit => t = "align";
let createAlign = alignExt;

module Cli {
  [@bs.deriving abstract]
  type config = {
    [@bs.optional] level: bool,
    [@bs.optional] all: bool,
    [@bs.optional] message: bool,
    [@bs.optional] colors: Js.Dict.t(string),
    [@bs.optional] levels: Js.Dict.t(int)
  };
  [@bs.module "winston"] [@bs.scope "format"] external cliExt: config => t = "cli";
  let create =
    (~level=?, ~all=?, ~message=?, ~colors=?, ~levels=?, ()) =>
      cliExt(config(~level=?level, ~all=?all, ~message=?message, ~colors=?colors, ~levels=?levels, ()));
};
let createCli = Cli.create;

module Colorize {
  [@bs.deriving abstract]
  type config = {
    [@bs.optional] level: bool,
    [@bs.optional] all: bool,
    [@bs.optional] message: bool,
    [@bs.optional] colors: Js.Dict.t(string)
  };
  [@bs.module "winston"] [@bs.scope "format"] external colorizeExt: config => t = "colorize";
  let create =
    (~level=?, ~all=?, ~message=?, ~colors=?, ()) =>
      colorizeExt(config(~level=?level, ~all=?all, ~message=?message, ~colors=?colors, ()));
};
let createColorize = Colorize.create;

module Json {
  [@bs.deriving abstract]
  type config = {
    [@bs.optional] replacer: (. string, Js.Json.t) => Js.Json.t,
    [@bs.optional] space: int
  };
  [@bs.module "winston"] [@bs.scope "format"] external jsonExt: config => t = "json";
  let create = (~replacer=?, ~space=?, ()) => jsonExt(config(~replacer=?replacer, ~space=?space, ()));
};
let createJson = Json.create;

module Label {
  [@bs.deriving abstract]
  type config = {
    [@bs.optional] label: string,
    [@bs.optional] message: bool
  };
  [@bs.module "winston"] [@bs.scope "format"] external labelExt: config => t = "label";
  let create = (~label=?, ~message=?, ()) => labelExt(config(~label=?label, ~message=?message, ()));
};
let createLabel = Label.create;

[@bs.module "winston"] [@bs.scope "format"] external logstashExt: unit => t = "logstash";
let createLogstash = logstashExt;

module Metadata {
  [@bs.deriving abstract]
  type config = {
    [@bs.optional] key: string,
    [@bs.optional] fillExcept: array(string),
    [@bs.optional] fillWith: array(string)
  };
  [@bs.module "winston"] [@bs.scope "format"] external metadataExt: config => t = "metadata";
  let create =
    (~key=?, ~fillExcept=?, ~fillWith=?, ()) =>
      metadataExt(config(~key=?key, ~fillExcept=?Belt.Option.map(fillExcept, Belt.List.toArray), ~fillWith=?Belt.Option.map(fillWith, Belt.List.toArray), ()));
};
let createMetadata = Metadata.create;

[@bs.module "winston"] [@bs.scope "format"] external msExt: unit => t = "ms";
let createMs = msExt;

module PadLevels {
  [@bs.deriving abstract]
  type config = {
    [@bs.optional] levels: Js.Dict.t(int)
  };
  [@bs.module "winston"] [@bs.scope "format"] external padLevelsExt: config => t = "padLevels";
  let create = (~levels=?, ()) => padLevelsExt(config(~levels=?levels, ()));
};
let createPadLevels = PadLevels.create;

module PrettyPrint {
  [@bs.deriving abstract]
  type config = {
    [@bs.optional] depth: int,
    [@bs.optional] colorize: bool
  };
  [@bs.module "winston"] [@bs.scope "format"] external prettyPrintExt: config => t = "prettyPrint";
  let create = (~depth=?, ~colorize=?, ()) => prettyPrintExt(config(~depth=?depth, ~colorize=?colorize, ()));
};
let createPrettyPrint = PrettyPrint.create;

[@bs.module "winston"] [@bs.scope "format"] external printfExt: (Js.Json.t => string) => t = "printf";
let createPrintf = printfExt;

[@bs.module "winston"] [@bs.scope "format"] external simpleExt: unit => t = "simple";
let createSimple = simpleExt;

[@bs.module "winston"] [@bs.scope "format"] external splatExt: unit => t = "splat";
let createSplat = splatExt;

module Timestamp {
  [@bs.deriving abstract]
  type config = {
    [@bs.optional] format: string,
    [@bs.optional] alias: string,
  };
  [@bs.module "winston"] [@bs.scope "format"] external timestampExt: config => t = "timestamp";
  let create = (~format=?, ~alias=?, ()) => timestampExt(config(~format=?format, ~alias=?alias, ()));
};
let createTimestamp = Timestamp.create;

module Uncolorize {
  [@bs.deriving abstract]
  type config = {
    [@bs.optional] level: bool,
    [@bs.optional] message: bool,
    [@bs.optional] raw: bool
  };
  [@bs.module "winston"] [@bs.scope "format"] external uncolorizeExt: config => t = "uncolorize";
  let create =
    (~level=?, ~message=?, ~raw=?, ()) => uncolorizeExt(config(~level=?level, ~message=?message, ~raw=?raw, ()));
};
let createUncolorize = Uncolorize.create;

type fnX = unit => t;
[@bs.module "winston"] external formatExt: (Js.Dict.t(Js.Json.t) => Js.Dict.t(Js.Json.t)) => fnX = "format";

let fromMapFn: (Js.Dict.t(Js.Json.t) => Js.Dict.t(Js.Json.t)) => t =
  fn => {
    /* We have to mutate the original obj in order to preserve magical members (Symbols etc.): */
    let wrapper = obj => {
      let res = fn(obj);
      res -> Js.Dict.entries -> Belt.Array.forEach(((key, value)) => {
        Js.Dict.set(obj, key, value)
      });
      obj;
    };
    formatExt(wrapper)(());
  };
