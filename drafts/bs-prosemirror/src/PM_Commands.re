module Command = PM_Command;

[@bs.module "prosemirror-commands"] [@bs.variadic]
external chainCommandsExt: array(Command.t) => Command.ext = "chainCommands";

let chainCommands: array(Command.t) => Command.t =
  (cmds, ~state, ~dispatch=?, ~view=?, ()) => {
    let fromOption = Js.Undefined.fromOption;
    let fn = chainCommandsExt(cmds);
    fn(. state, dispatch->fromOption, view->fromOption);
  };

[@bs.module "prosemirror-commands"] external deleteSelection: Command.t = "deleteSelection";

[@bs.module "prosemirror-commands"] external joinBackward: Command.t = "joinBackward";

[@bs.module "prosemirror-commands"] external selectNodeBackward: Command.t = "selectNodeBackward";

[@bs.module "prosemirror-commands"] external joinForward: Command.t = "joinForward";

[@bs.module "prosemirror-commands"] external selectNodeForward: Command.t = "selectNodeForward";

[@bs.module "prosemirror-commands"] external joinUp: Command.t = "joinUp";

[@bs.module "prosemirror-commands"] external joinDown: Command.t = "joinDown";

[@bs.module "prosemirror-commands"] external lift: Command.t = "lift";

[@bs.module "prosemirror-commands"] external newlineInCode: Command.t = "newlineInCode";

[@bs.module "prosemirror-commands"] external exitCode: Command.t = "exitCode";

[@bs.module "prosemirror-commands"]
external createParagraphNear: Command.t = "createParagraphNear";

[@bs.module "prosemirror-commands"] external liftEmptyBlock: Command.t = "liftEmptyBlock";

[@bs.module "prosemirror-commands"] external splitBlock: Command.t = "splitBlock";

[@bs.module "prosemirror-commands"]
external splitBlockKeepMarks: Command.t = "splitBlockKeepMarks";

[@bs.module "prosemirror-commands"] external selectParentNode: Command.t = "selectParentNode";

[@bs.module "prosemirror-commands"] external selectAll: Command.t = "selectAll";

[@bs.module "prosemirror-commands"]
external wrapInExt:
  (~nodeType: PM_Model.NodeType.t, ~attrs: PM_Model.Attrs.t=?, unit) => Command.ext =
  "wrapIn";

let wrapIn = (~nodeType, ~attrs, ~state, ~dispatch=?, ~view=?, ()) => {
  let fromOption = Js.Undefined.fromOption;
  let fn = wrapInExt(~nodeType, ~attrs, ());
  fn(. state, dispatch->fromOption, view->fromOption);
};

[@bs.module "prosemirror-commands"]
external setBlockTypeExt:
  (~nodeType: PM_Model.NodeType.t, ~attrs: PM_Model.Attrs.t=?, unit) => Command.ext =
  "setBlockType";

let setBlockType = (~nodeType, ~attrs, ~state, ~dispatch=?, ~view=?, ()) => {
  let fromOption = Js.Undefined.fromOption;
  let fn = setBlockTypeExt(~nodeType, ~attrs, ());
  fn(. state, dispatch->fromOption, view->fromOption);
};

[@bs.module "prosemirror-commands"]
external toggleMarkExt:
  (~markType: PM_Model.MarkType.t, ~attrs: PM_Model.Attrs.t=?, unit) => Command.ext =
  "toggleMark";

let toggleMark = (~markType, ~attrs, ~state, ~dispatch=?, ~view=?, ()) => {
  let fromOption = Js.Undefined.fromOption;
  let fn = toggleMarkExt(~markType, ~attrs, ());
  fn(. state, dispatch->fromOption, view->fromOption);
};

[@bs.module "prosemirror-commands"]
external autoJoin:
  (
    ~command: Command.t,
    ~isJoinable: [@bs.unwrap] [
                   | `Predicate((PM_Model.Node.t, PM_Model.Node.t) => bool)
                   | `NodeTypeNames(array(string))
                 ]
  ) =>
  Command.t =
  "autoJoin";

[@bs.module "prosemirror-commands"] external baseKeymap: Js.Dict.t(Command.t) = "baseKeymap";

[@bs.module "prosemirror-commands"] external pcBaseKeymap: Js.Dict.t(Command.t) = "pcBaseKeymap";

[@bs.module "prosemirror-commands"]
external macBaseKeymap: Js.Dict.t(Command.t) = "macBaseKeymap";
