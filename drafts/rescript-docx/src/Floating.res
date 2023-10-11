type margins = {
  bottom?: float,
  left?: float,
  right?: float,
  top?: float,
}

/** @see https://docx.js.org/api/interfaces/IFloating.html */
type t = {
  allowOverlap?: bool,
  behindDocument?: bool,
  horizontalPosition?: HorizontalPositionOptions.t,
  layoutInCell?: bool,
  lockAnchor?: bool,
  margins?: margins,
  verticalPosition: VerticalPositionOptions.t,
  wrap?: TextWrapping.t,
  zIndex?: int,
}
