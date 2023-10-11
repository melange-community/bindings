[@bs.module "@react-pdf/core"] external page : ReasonReact.reactClass = "Page";

let make = (~size="A4", ~orientation="portrait") =>
  ReactPdfCommon.make(page, {"size": size, "orientation": orientation});
