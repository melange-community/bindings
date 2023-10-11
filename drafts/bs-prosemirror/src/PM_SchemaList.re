module Command = PM_Command;

[@bs.module "prosemirror-schema-list"] external orderedList: PM_Model.NodeSpec.t = "orderedList";

[@bs.module "prosemirror-schema-list"] external bulletList: PM_Model.NodeSpec.t = "bulletList";

[@bs.module "prosemirror-schema-list"] external listItem: PM_Model.NodeSpec.t = "listItem";

[@bs.module "prosemirror-schema-list"]
external addListNodes:
  (~nodes: OrderedMap.t(PM_Model.NodeSpec.t), ~itemContent: string, ~listGroup: string=?, unit) =>
  OrderedMap.t(PM_Model.NodeSpec.t) =
  "addListNodes";

[@bs.module "prosemirror-schema-list"]
external wrapInListExt:
  (~nodeType: PM_Model.NodeType.t, ~attrs: PM_Model.Attrs.t=?, unit) => Command.ext =
  "wrapInList";

let wrapInList = (~nodeType, ~attrs, ~state, ~dispatch=?, ~view=?, ()) => {
  let fromOption = Js.Undefined.fromOption;
  let fn = wrapInListExt(~nodeType, ~attrs, ());
  fn(. state, dispatch->fromOption, view->fromOption);
};

[@bs.module "prosemirror-schema-list"]
external splitListItemExt: (~nodeType: PM_Model.NodeType.t) => Command.ext = "splitListItem";

let splitListItem = (~nodeType, ~state, ~dispatch=?, ~view=?, ()) => {
  let fromOption = Js.Undefined.fromOption;
  let fn = splitListItemExt(~nodeType);
  fn(. state, dispatch->fromOption, view->fromOption);
};

[@bs.module "prosemirror-schema-list"]
external sinkListItemExt: (~nodeType: PM_Model.NodeType.t) => Command.ext = "sinkListItem";

let sinkListItem = (~nodeType, ~state, ~dispatch=?, ~view=?, ()) => {
  let fromOption = Js.Undefined.fromOption;
  let fn = sinkListItemExt(~nodeType);
  fn(. state, dispatch->fromOption, view->fromOption);
};

[@bs.module "prosemirror-schema-list"]
external liftListItemExt: (~nodeType: PM_Model.NodeType.t) => Command.ext = "liftListItem";

let liftListItem = (~nodeType, ~state, ~dispatch=?, ~view=?, ()) => {
  let fromOption = Js.Undefined.fromOption;
  let fn = liftListItemExt(~nodeType);
  fn(. state, dispatch->fromOption, view->fromOption);
};
