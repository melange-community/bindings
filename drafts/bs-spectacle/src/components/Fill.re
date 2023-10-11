[@bs.module "spectacle"] external reactClass: ReasonReact.reactClass = "Fill";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);