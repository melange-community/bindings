module Types = Mapbox__LngLat__Types
type t = Types.point 
// @see https://github.com/mapbox/point-geometry/blob/master/index.js
module InstanceMember = (
  T: {
    type t
  },
) => {
  @send external clone: T.t => T.t = "clone"
  @send external add: (T.t, T.t) => T.t = "add"
  @send external sub: (T.t, T.t) => T.t = "sub"
  @send external multByPoint: (T.t, T.t) => T.t = "multByPoint"
  @send external divByPoint: (T.t, T.t) => T.t = "divByPoint"
  @send external mult: (T.t, float) => T.t = "mult"
  @send external div: (T.t, T.t) => T.t = "div"
  @send external rotate: (T.t, float) => T.t = "rotate"
  @send external rotateAround: (T.t, float, T.t) => T.t = "rotateAround"
  @send external matMult: (T.t, float) => T.t = "matMult"
  @send external unit: (T.t) => T.t ="unit"
  @send external prep: (T.t) => T.t ="prep"
  @send external round: (T.t) => T.t ="round"
  @send external mag: (T.t) => float ="mag"
  @send external equals: (T.t, T.t) => bool ="equals"
  @send external dist: (T.t,T.t) => float ="dist"
  @send external distSqr: (T.t,T.t) => float ="distSqr"
  @send external angle: (T.t) => float ="angle"
  @send external angleTo: (T.t, T.t) => float ="angleTo"
  @send external angleWith: (T.t, T.t) => float ="angleWith"
  @send external angleWithSep: (T.t, float, float) => float ="angleWithSep" 
}

@module("mapbox-gl") @new external make: (float, float) => t = "Point"

include InstanceMember({ type nonrec t = t })
