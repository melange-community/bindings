[@bs.module "@react-pdf/core"] external image : ReasonReact.reactClass = "Image";

let make = (~src: string) => ReactPdfCommon.make(image, {"src": src});
