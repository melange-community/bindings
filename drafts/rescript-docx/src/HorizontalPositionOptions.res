type horizontalPositionAlign = [
  | #center
  | #inside
  | #left
  | #outside
  | #right
]

type horizontalPositionRelativeFrom = [
  | #character
  | #column
  | #insideMargin
  | #leftMargin
  | #margin
  | #outsideMargin
  | #page
  | #rightMargin
]

/** @see https://docx.js.org/api/interfaces/IHorizontalPositionOptions.html */
type t = {
  align?: horizontalPositionAlign,
  offset?: float,
  relative?: horizontalPositionRelativeFrom,
}
