module Types = Mapbox__LngLat__Types
module InstanceMember = (
  T: {
    type t
  },
) => {
  @send external contains: (T.t, Types.lngLatLike) => bool = "contains"
  // TODO {extends(obj)}
  @send external getCenter: T.t => Types.lngLat = "getCenter"
  @send external getEast: T.t => float = "getEast"
  @send external getNorth: T.t => float = "getNorth"
  @send external getNorthEast: T.t => float = "getNorthEast"
  @send external getNorthWest: T.t => float = "getNorthWest"
  @send external getSouth: T.t => float = "getSouth"
  @send external getSouthEast: T.t => float = "getSouthEast"
  @send external getSouthWest: T.t => float = "getSouthWest"
  @send external getWest: T.t => float = "getWest"
  @send external isEmpty: T.t => bool = "isEmpty"
  @send external setNorthEast: (T.t, Types.lngLatLike) => T.t = "setNorthEast"
  @send external setSouthWest: (T.t, Types.lngLatLike) => T.t = "setSouthWest"
}

type t = Types.lngLatBounds 
// note : official mapbox-gl-js use LngLatLike for make LngLatBounds but for here
// we use LngLat.t and if you want use LngLatLike.t so you need use LngLatLike.t->LngLat.convert
@module("mapbox-gl") @new external make: (Types.lngLat, Types.lngLat) => t = "LngLatBonds"
// static method
@module("mapbox-gl") @scope("LngLatBounds")
external convert: Types.lngLatBoundsLike => t = "convert"
// instance method
include Mapbox__Common.Impl({
  type nonrec t = t
})
include InstanceMember({
  type nonrec t = t
})
