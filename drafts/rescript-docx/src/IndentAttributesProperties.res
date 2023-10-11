open Util

/** @see https://docx.js.org/api/interfaces/IIndentAttributesProperties.html */
type t = {
  start?: Types.NumberOrUniversalMeasure.t,
  end?: Types.NumberOrUniversalMeasure.t,
  left?: Types.NumberOrUniversalMeasure.t,
  right?: Types.NumberOrUniversalMeasure.t,
  hanging?: Types.NumberOrPositiveUniversalMeasure.t,
  firstLine?: Types.NumberOrPositiveUniversalMeasure.t,
}
