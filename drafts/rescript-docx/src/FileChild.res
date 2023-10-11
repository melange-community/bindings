type t

type foo

/** Coerces a paragraph to a [FileChild.t] */
external fromParagraph: Util.Types.paragraph => t = "%identity"

/** Coerces a table to a [FileChild.t] */
external fromTable: Util.Types.table => t = "%identity"

/** Creates a new [Paragraph.t] */
let p = string => Paragraph.make(string)->fromParagraph

/** Creates a new [Paragraph.t] with options */
let p' = options => Paragraph.make'(options)->fromParagraph
