@genType.import(("big.js", "Big"))
type t

// Returns a new instance of a Big number object
@module("big.js")
external fromFloat: float => t = "Big"

// Returns a string representing the value of this Big number
@send
external toFixed: (t, int) => string = "toFixed"

// Returns a Big number whose value is the value of this Big number plus n.
@send
external plus: (t, t) => t = "plus"

// Returns a Big number whose value is the value of this Big number minus n.
@send
external minus: (t, t) => t = "minus"

// Returns a Big number whose value is the value of this Big number divided by n.
@send
external div: (t, t) => t = "div"

// Returns a Big number whose value is the value of this Big number times n.
@send
external times: (t, t) => t = "times"

// Returns a string representing the value of this Big number.
@send
external valueOf: t => string = "valueOf"

// Returns a Big number whose value is the value of this Big number rounded using rounding mode rm to a maximum of dp decimal places.
@send
external round: (t, int) => t = "round"

// Returns true if the value of this Big equals the value of n, otherwise returns false.
@send
external eq: (t, t) => bool = "eq"

// Returns true if the value of this Big is greater than the value of n, otherwise returns false.
@send
external gt: (t, t) => bool = "gt"

// Returns true if the value of this Big is greater than or equal to the value of n, otherwise returns false.
@send
external gte: (t, t) => bool = "gte"

// Returns true if the value of this Big is less than the value of n, otherwise returns false.
@send
external lt: (t, t) => bool = "lt"

// Returns true if the value of this Big is less than or equal to the value of n, otherwise returns false.
@send
external lte: (t, t) => bool = "lte"

// Returns a primitive number representing the value of this Big number.
@send
external toFloat: t => float = "toNumber"

// Infix operators
module Operators = {
  let \"+." = (a: t, b: t) => a->plus(b)
  let \"*." = (a: t, b: t) => a->times(b)
  let \"-." = (a: t, b: t) => a->minus(b)
  let \"/." = (a: t, b: t) => a->div(b)
}
