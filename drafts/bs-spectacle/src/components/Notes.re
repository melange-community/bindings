[@bs.module "spectacle"] external reactClass: ReasonReact.reactClass = "Notes";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);