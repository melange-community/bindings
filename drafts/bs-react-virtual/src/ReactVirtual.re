module Align: {
  type t = pri string;

  [@bs.inline "start"]
  let start: t;
  [@bs.inline "center"]
  let center: t;
  [@bs.inline "end"]
  let end_: t;
  [@bs.inline "auto"]
  let auto: t;
} = {
  type t = string;
  [@bs.inline]
  let start = "start";
  [@bs.inline]
  let center = "center";
  [@bs.inline]
  let end_ = "end";
  [@bs.inline]
  let auto = "auto";
};

[@bs.deriving abstract]
type options = {
  size: int,
  parentRef: React.ref(Js.Nullable.t(Dom.element)),
  estimateSize: int => int,
  [@bs.optional]
  overscan: int,
  [@bs.optional]
  horizontal: bool,
  [@bs.optional]
  scrollToFn: (int, int => unit) => unit,
};

type virtualRow = {
  index: int,
  start: int,
  size: int,
  [@bs.as "end"]
  end_: int,
  measureRef: React.ref(Js.Nullable.t(Dom.element)),
};
type scrollOptions = {align: Align.t};

type rowVirtualizer = {
  virtualItems: array(virtualRow),
  totalSize: int,
  scrollToIndex: (. ~index: int, ~options: option(scrollOptions)) => unit,
  scrollToOffset: (. ~offset: int, ~options: option(scrollOptions)) => unit,
};

[@bs.module "react-virtual"]
external useVirtual: options => rowVirtualizer = "useVirtual";

[@bs.send]
external scrollToIndex:
  (rowVirtualizer, ~index: int, ~options: scrollOptions=?, unit) => unit =
  "scrollToIndex";

[@bs.send]
external scrollToOffset:
  (rowVirtualizer, ~offset: int, ~options: scrollOptions=?, unit) => unit =
  "scrollToOffset";