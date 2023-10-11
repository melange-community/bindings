open Belt
open Js.Typed_array

type t = (float, float)

let size = 32 / 8 * 2

let add = ((x1, y1): t, (x2, y2): t): t => (x1 +. x2, y1 +. y2)
let scale = ((x, y): t, s: float): t => (x *. s, y *. s)
let mix = (a: t, b: t, s: float): t => add(a->scale(s), b->scale(1.0 -. s))

let flatten = (vecs: array<t>): ArrayBuffer.t => {
  let arr = Float32Array.fromLength(2 * Array.length(vecs))
  Array.forEachWithIndex(vecs, (i, (x, y)) => {
    arr->Float32Array.unsafe_set(i * 2, x)
    arr->Float32Array.unsafe_set(1 + i * 2, y)
  })
  arr->Float32Array.buffer
}
