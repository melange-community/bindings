type t;

[@mel.module "numeral"]
external make:
  (
  [@mel.unwrap]
  [ | `Str(string) | `Int(int) | `Float(float) | `Numeral(t)]
  ) =>
  t =
  "default";

[@mel.module "numeral"] external makeEmpty: unit => t = "default";

module X = Js

[@mel.send] external value: t => Js.nullable(float) = "value";

let value = n => n->value->Js.toOption;

[@mel.send] external format: (t, ~format: string=?, unit) => string = "format";

[@mel.send] external clone: t => t = "clone";

[@mel.send]
external addMutable:
  (t, [@mel.unwrap] [ | `Str(string) | `Int(int) | `Float(float)]) => t =
  "add";

let add = (numeral, value) => numeral->clone->(addMutable(value));

[@mel.send]
external subtractMutable:
  (t, [@mel.unwrap] [ | `Str(string) | `Int(int) | `Float(float)]) => t =
  "subtract";

let subtract = (numeral, value) => numeral->clone->(subtractMutable(value));

[@mel.send]
external multiplyMutable:
  (t, [@mel.unwrap] [ | `Str(string) | `Int(int) | `Float(float)]) => t =
  "multiply";

let multiply = (numeral, value) => numeral->clone->(multiplyMutable(value));

[@mel.send]
external divideMutable:
  (t, [@mel.unwrap] [ | `Str(string) | `Int(int) | `Float(float)]) => t =
  "divide";

let divide = (numeral, value) => numeral->clone->(divideMutable(value));

[@mel.send]
external difference:
  (t, [@mel.unwrap] [ | `Str(string) | `Int(int) | `Float(float)]) => t =
  "add";
