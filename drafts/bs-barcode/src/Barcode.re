[@bs.deriving abstract]
type options = {
  [@bs.optional]
  format: string,
  [@bs.optional]
  width: float,
  [@bs.optional]
  height: float,
  [@bs.optional]
  displayValue: bool,
  [@bs.optional]
  text: string,
  [@bs.optional]
  fontOptions: string,
  [@bs.optional]
  font: string,
  [@bs.optional]
  textAlign: string,
  [@bs.optional]
  textPosition: string,
  [@bs.optional]
  textMargin: float,
  [@bs.optional]
  fontSize: float,
  [@bs.optional]
  background: string,
  [@bs.optional]
  lineColor: string,
  [@bs.optional]
  margin: float,
  [@bs.optional]
  marginTop: float,
  [@bs.optional]
  marginBottom: string,
  [@bs.optional]
  marginLeft: string,
  [@bs.optional]
  marginRight: string,
  [@bs.optional]
  valid: bool => bool,
};

[@bs.module]
external createBarcode: (Canvas.t, string, ~options: options=?, unit) => unit =
  "jsbarcode";