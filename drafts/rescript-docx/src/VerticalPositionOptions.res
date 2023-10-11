type horizontalPositionAlign = [
  | #center
  | #inside
  | #bottom
  | #outside
  | #top
]

type horizontalPositionRelativeFrom = [
  | #character
  | #column
  | #insideMargin
  | #bottomMargin
  | #margin
  | #outsideMargin
  | #page
  | #topMargin
]

/** @see https://docx.js.org/api/interfaces/IHorizontalPositionOptions.html */
type t = {
  align?: horizontalPositionAlign,
  offset?: float,
  relative?: horizontalPositionRelativeFrom,
}
