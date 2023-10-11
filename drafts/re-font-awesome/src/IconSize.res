@deriving(jsConverter)
type t = [
  | #"2xs"
  | #xs
  | #sm
  | #lg
  | #"1x"
  | #"2x"
  | #"3x"
  | #"4x"
  | #"5x"
  | #"6x"
  | #"7x"
  | #"8x"
  | #"9x"
  | #"10x"
]

let all: array<t> = [
  #"2xs",
  #xs,
  #sm,
  #lg,
  #"1x",
  #"2x",
  #"3x",
  #"4x",
  #"5x",
  #"6x",
  #"7x",
  #"8x",
  #"9x",
  #"10x",
]
