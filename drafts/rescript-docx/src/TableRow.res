/** @see https://docx.js.org/api/classes/TableRow.html */
type t

type height = {
  rule: HeightRule.t,
  value: Util.Types.NumberOrPositiveUniversalMeasure.t,
}

type options = {
  children: array<TableCell.t>,
  canSplit?: bool,
  height?: height,
  tableHeader?: bool,
}

@module("docx") @new
external make: options => t = "TableRow"
