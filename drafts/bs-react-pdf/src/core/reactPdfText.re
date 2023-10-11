[@bs.module "@react-pdf/core"] external text : ReasonReact.reactClass = "Text";

let make = (~style=?) => ReactPdfCommon.make(text, Js.Obj.empty(), ~style?);
