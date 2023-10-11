/** @see https://docx.js.org/api/classes/Table.html */
open Util.Types

type t = table

type tableBordersOptions = {
  insideHorizontal?: BorderOptions.t,
  insideVertical?: BorderOptions.t,
  top?: BorderOptions.t,
  left?: BorderOptions.t,
  right?: BorderOptions.t,
  bottom?: BorderOptions.t,
}

type tableFloatOptions = {
  absoluteHorizontalPosition?: NumberOrUniversalMeasure.t,
  absoluteVerticalPosition?: NumberOrUniversalMeasure.t,
  bottomFromText?: NumberOrPositiveUniversalMeasure.t,
  leftFromText?: NumberOrPositiveUniversalMeasure.t,
  rightFromText?: NumberOrPositiveUniversalMeasure.t,
  topFromText?: NumberOrPositiveUniversalMeasure.t,
}

type options = {
  rows: array<TableRow.t>,
  alignment?: AlignmentType.t,
  borders?: tableBordersOptions,
  columnWidths?: array<float>,
  float?: tableFloatOptions,
  indent?: TableWidthProperties.t,
  layout?: [#autofit | #fixed],
  margins?: TableCellMarginOptions.t,
  style?: string,
  visuallyRightToLeft?: bool,
  width?: TableWidthProperties.t,
}

@module("docx") @new
external make: options => t = "Table"
