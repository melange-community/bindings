[@bs.module "spectacle"]
external reactClass: ReasonReact.reactClass = "SlideSet";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);