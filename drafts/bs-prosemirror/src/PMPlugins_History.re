module Command = PM_Command;

[@bs.module "prosemirror-history"] external undo: Command.t = "undo";

[@bs.module "prosemirror-history"] external redo: Command.t = "redo";

[@bs.module "prosemirror-history"] external undoDepth: PM_State.EditorState.t => int = "undoDepth";

[@bs.module "prosemirror-history"] external redoDepth: PM_State.EditorState.t => int = "redoDepth";

[@bs.module "prosemirror-history"]
external closeHistory: PM_State.Transaction.t => PM_State.Transaction.t = "closeHistory";

[@bs.deriving abstract]
type config = {
  [@bs.optional]
  depth: int,
  [@bs.optional]
  newGroupDelay: int,
};

[@bs.module "prosemirror-history"]
external history: (~config: config=?, unit) => PM_Types.untypedPlugin = "history";
