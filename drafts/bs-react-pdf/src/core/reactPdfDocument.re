[@bs.module "@react-pdf/core"] external document : ReasonReact.reactClass = "Document";

let make = (~style=Js.Obj.empty()) => ReactPdfCommon.make(document, Js.Obj.empty(), ~style);
