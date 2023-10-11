[@bs.module "spectacle"] external reactClass: ReasonReact.reactClass = "Fit";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);