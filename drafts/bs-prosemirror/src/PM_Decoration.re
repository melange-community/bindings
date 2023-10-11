module Types = PM_Types;

module Attrs = {
  type t = Js.Dict.t(string);
};

type spec = Js.Dict.t(string);

[@bs.deriving abstract]
type t = {
  from: int,
  [@bs.as "to"]
  to_: int,
  spec,
};

[@bs.deriving abstract]
type widgetSpec = {
  [@bs.optional]
  side: int,
  [@bs.optional]
  marks: array(PM_Model.Mark.t),
  [@bs.optional]
  stopEvent: Dom.event => bool,
  [@bs.optional]
  key: string,
};

[@bs.module "prosemirror-view"] [@bs.scope "Decoration"]
external widget:
  (
    ~pos: int,
    ~toDOM: [@bs.unwrap] [
              | `Node(Dom.element)
              | `Fn((Types.editorView, unit => int) => Dom.element)
            ],
    ~spec: widgetSpec=?,
    unit
  ) =>
  t =
  "widget";

[@bs.deriving abstract]
type inlineSpec = {
  [@bs.optional]
  inclusiveStart: bool,
  [@bs.optional]
  inclusiveEnd: bool,
};

[@bs.module "prosemirror-view"] [@bs.scope "Decoration"]
external inline: (~from: int, ~to_: int, ~attrs: Attrs.t, ~spec: inlineSpec=?, unit) => t =
  "inline";

[@bs.module "prosemirror-view"] [@bs.scope "Decoration"]
external node: (~from: int, ~to_: int, ~attrs: Attrs.t, ~spec: spec=?, unit) => t = "node";
