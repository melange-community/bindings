[@bs.module "react-simple-maps"]
external markersClass : ReasonReact.reactClass = "Markers";

let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=markersClass,
    ~props=Js.Obj.empty(),
    children,
  );
