open Util

type t = {
  countBy?: float,
  start?: float,
  restart?: [#newPage | #newSection | #continuous],
  distance?: Types.NumberOrPositiveUniversalMeasure.t,
}
