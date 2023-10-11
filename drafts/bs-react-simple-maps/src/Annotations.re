[@bs.module "react-simple-maps"]
external annotationsClass : ReasonReact.reactClass = "Annotations";

let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=annotationsClass,
    ~props=Js.Obj.empty(),
    children,
  );
