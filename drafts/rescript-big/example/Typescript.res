let a = 201.57512->Big.fromFloat
let b = 1.->Big.fromFloat

@genType
let c = a->Big.plus(b)

Js.log(c->Big.toFixed(2))
