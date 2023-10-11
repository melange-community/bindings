[@bs.deriving {jsConverter: newType}]
type t =
  [@bs.as 1] | Greater
  [@bs.as 0] | Equal
  [@bs.as (-1)] | Less;