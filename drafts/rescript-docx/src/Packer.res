type prettifyType =
  | @as("") None
  | @as("  ") With2Blanks
  | @as("    ") With4Blanks
  | @as("\t") WithTab

@unwrap
type prettify = Bool(bool) | Pretty(prettifyType)

@module("docx") @scope("Packer")
external toString: Document.t => promise<string> = "toString"

@module("docx") @scope("Packer")
external toStringWith: (Document.t, ~prettify: prettify) => promise<string> = "toString"

@module("docx") @scope("Packer")
external toBase64String: Document.t => promise<string> = "toBase64String"

@module("docx") @scope("Packer")
external toBase64StringWith: (Document.t, ~prettify: prettify) => promise<string> = "toBase64String"

@module("docx") @scope("Packer")
external toStream: Document.t => promise<'stream> = "toStream"

@module("docx") @scope("Packer")
external toStreamWith: (Document.t, ~prettify: prettify) => promise<'stream> = "toStream"

@module("docx") @scope("Packer")
external toBlob: Document.t => promise<'blob> = "toBlob"

@module("docx") @scope("Packer")
external toBlobWith: (Document.t, ~prettify: prettify) => promise<'blob> = "toBlob"

@module("docx") @scope("Packer")
external toBuffer: Document.t => promise<'buffer> = "toBuffer"

@module("docx") @scope("Packer")
external toBufferWith: (Document.t, ~prettify: prettify) => promise<'buffer> = "toBuffer"
