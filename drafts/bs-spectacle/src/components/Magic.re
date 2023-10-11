[@bs.module "spectacle"] external reactClass: ReasonReact.reactClass = "Magic";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);