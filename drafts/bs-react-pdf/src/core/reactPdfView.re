[@bs.module "@react-pdf/core"] external view : ReasonReact.reactClass = "View";

let make = (~style: ReactPdfStyleSheet.t('a)=Js.Obj.empty(), children) =>
  ReasonReact.wrapJsForReason(~reactClass=view, ~props={"style": style}, children);
