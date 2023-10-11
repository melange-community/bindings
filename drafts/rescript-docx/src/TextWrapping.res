type distance = {
  distB?: float,
  distL?: float,
  distR?: float,
  distT?: float,
}

type textWrappingSide = [
  | #bothSides
  | #largest
  | #left
  | #right
]

/** @see https://docx.js.org/api/enums/TextWrappingType.html */
type textWrappingType =
  | None
  | Square
  | Tight
  | Top_And_Bottom

/** @see https://docx.js.org/api/interfaces/ITextWrapping.html */
type t = {
  margins?: distance,
  side?: textWrappingSide,
  @as("type") type_: textWrappingType,
}
