open Util

type t

type attributes = {
  width: Types.NumberOrPositiveUniversalMeasure.t,
  space?: Types.NumberOrPositiveUniversalMeasure.t,
}

@module("docx") @new
external make: attributes => t = "Column"
