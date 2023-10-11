open! Big.Operators

let a = 201.57512->Big.fromFloat
let b = 1.->Big.fromFloat
Js.log(a->Big.toFixed(2))
Js.log(a *. b)
