/** @see https://docx.js.org/api/interfaces/IRunOptions.html#children */
type children
external string: string => children = "%identity"
external pageNumber: PageNumber.t => children = "%identity"

type underline = {
  color?: string,
  @as("type")
  type_: [
    | #dash
    | #dashDotDotHeavy
    | #dashLong
    | #dashLongHeavy
    | #dotDash
    | #dotDotDash
    | #dotted
    | #dottedHeavy
    | #double
    | #single
    | #thick
    | #wave
    | #wavyDouble
    | #wavyHeavy
    | #words
  ],
}
/** @see https://docx.js.org/api/interfaces/IRunOptions.html */
type options = {
  text?: string,
  allCaps?: bool,
  bold?: bool,
  break?: int,
  italics?: bool,
  font?: string,
  /** @see https://docx.js.org/api/interfaces/IRunOptions.html#size */
  size?: string,
  style?: string,
  color?: string,
  underline?: underline,
  // NOTE(@EmileRolley): little hack to accept polymorphic array
  children?: array<children>,
}

@module("docx") @new
external make: string => ParagraphChild.t = "TextRun"

@module("docx") @new
external make': options => ParagraphChild.t = "TextRun"
