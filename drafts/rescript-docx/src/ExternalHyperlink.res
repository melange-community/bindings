/** @see https://docx.js.org/api/classes/ExternalHyperlink.html */
type options = {
  link: string,
  children: array<ParagraphChild.t>,
}

@module("docx") @new
external make: options => ParagraphChild.t = "ExternalHyperlink"
