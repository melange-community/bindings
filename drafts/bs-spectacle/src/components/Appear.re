[@bs.module "spectacle"]
external reactClass: ReasonReact.reactClass = "Appear";

[@bs.obj] external makeProps: (~order: int=?, ~fid: string=?, unit) => _ = "";

let make = (~order=?, ~fid=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~order?, ~fid?, ()),
    children,
  );