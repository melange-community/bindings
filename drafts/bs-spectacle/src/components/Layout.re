[@bs.module "spectacle"]
external reactClass: ReasonReact.reactClass = "Layout";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);