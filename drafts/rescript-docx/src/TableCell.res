/** @see https://docx.js.org/api/classes/TableCell.html */
type t

type tableCellBorders = {
  top?: BorderOptions.t,
  right?: BorderOptions.t,
  bottom?: BorderOptions.t,
  left?: BorderOptions.t,
  end?: BorderOptions.t,
  start?: BorderOptions.t,
}

type options = {
  children: array<Util.Types.ParagraphOrTable.t>,
  borders?: tableCellBorders,
  columnSpan?: int,
  margins?: TableCellMarginOptions.t,
  rowSpan?: float,
  shading?: ShadingAttributesProperties.t,
  textDirection?: TextDirection.t,
  verticalAlign?: VerticalAlign.t,
  verticalMerge?: VerticalMergeType.t,
  width?: TableWidthProperties.t,
}

@module("docx") @new
external make: options => t = "TableCell"
