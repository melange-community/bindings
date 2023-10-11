[@bs.deriving abstract]
type t = {
  [@bs.optional]
  dom: Dom.element,
  [@bs.optional]
  contentDOM: Dom.element,
  [@bs.optional]
  update: (~node: PM_Model.Node.t, ~decorations: array(PM_Decoration.t)) => bool,
  [@bs.optional]
  selectNode: unit => unit,
  [@bs.optional]
  deselectNode: unit => unit,
  [@bs.optional]
  setSelection: (~anchor: int, ~head: int, ~root: Dom.document) => unit,
  [@bs.optional]
  stopEvent: Dom.event => bool,
  [@bs.optional]
  ignoreMutation: Dom.mutationRecord => bool,
  [@bs.optional]
  destroy: unit => unit,
};
