open Util

type t = {
  top?: Types.NumberOrUniversalMeasure.t,
  right?: Types.NumberOrPositiveUniversalMeasure.t,
  bottom?: Types.NumberOrUniversalMeasure.t,
  left?: Types.NumberOrPositiveUniversalMeasure.t,
  header?: Types.NumberOrPositiveUniversalMeasure.t,
  footer?: Types.NumberOrPositiveUniversalMeasure.t,
  gutter?: Types.NumberOrPositiveUniversalMeasure.t,
}
