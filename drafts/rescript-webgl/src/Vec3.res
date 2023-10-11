open Belt
open Js.Typed_array

type t = (float, float, float)

let size = 32 / 8 * 3

let add = ((x1, y1, z1): t, (x2, y2, z2): t): t => (x1 +. x2, y1 +. y2, z1 +. z2)
let scale = ((x, y, z): t, s: float): t => (x *. s, y *. s, z *. s)
let mix = (a: t, b: t, s: float): t => add(a->scale(s), b->scale(1.0 -. s))

let flatten = (vecs: array<t>): ArrayBuffer.t => {
  let arr = Float32Array.fromLength(3 * Array.length(vecs))
  Array.forEachWithIndex(vecs, (i, (x, y, z)) => {
    arr->Float32Array.unsafe_set(i * 3, x)
    arr->Float32Array.unsafe_set(1 + 3 * i, y)
    arr->Float32Array.unsafe_set(2 + 3 * i, z)
  })
  arr->Float32Array.buffer
}
