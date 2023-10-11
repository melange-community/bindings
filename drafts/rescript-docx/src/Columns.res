open Util

type t

type attributes = {
  space?: Types.NumberOrPositiveUniversalMeasure.t,
  count?: float,
  separate?: bool,
  equalWidth?: bool,
  children?: array<Column.t>,
}

@module("docx") @new
external make: attributes => t = "Columns"
