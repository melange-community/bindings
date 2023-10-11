// In ReScript v11:
// type t =
//   | @as("single") Single
//   | @as("words") Words
//   | @as("double") Double
//   | @as("thick") Thick
//   | @as("dotted") Dotted
//   | @as("dottedHeavy") DottedHeavy
//   | @as("dash") Dash
//   | @as("dashedHeavy") DashedHeavy
//   | @as("dashLong") DashLong
//   | @as("dashLongHeavy") DashLongHeavy
//   | @as("dotdash") DotDash
//   | @as("dashDotHeavy") DashDotHeavy
//   | @as("dotDotDash") DotDotDash
//   | @as("dashDotDotHeavy") DashDotDotHeavy
//   | @as("wave") Wave
//   | @as("wavyHeavy") WavyHeavy
//   | @as("wavyDouble") WavyDouble
//   | @as("none") None

type t = [
  | #single
  | #words
  | #double
  | #thick
  | #dotted
  | #dottedHeavy
  | #dash
  | #dashedHeavy
  | #dashLong
  | #dashLongHeavy
  | #dotdash
  | #dashDotHeavy
  | #dotDotDash
  | #dashDotDotHeavy
  | #wave
  | #wavyHeavy
  | #wavyDouble
  | #none
]
