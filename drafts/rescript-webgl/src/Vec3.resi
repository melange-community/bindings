open Js.Typed_array

type t = (float, float, float)

let size: int

let add: (t, t) => t
let scale: (t, float) => t
let mix: (t, t, float) => t

let flatten: array<t> => ArrayBuffer.t
