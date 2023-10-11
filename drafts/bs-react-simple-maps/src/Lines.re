[@bs.module "react-simple-maps"]
external linesClass : ReasonReact.reactClass = "Lines";

let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=linesClass,
    ~props=Js.Obj.empty(),
    children,
  );
