[@bs.module "@react-pdf/core"] external link : ReasonReact.reactClass = "Link";

let make = (~src: string) => ReactPdfCommon.make(link, {"src": src});
