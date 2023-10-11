module Types = Mapbox__LngLat__Types
// @see https://docs.mapbox.com/mapbox-gl-js/api/geography/#lnglat-instance-members
module InstanceMember = (
  T: {
    type t
  },
) => {
  @send external distanceTo: (T.t, T.t) => float = "distanceTo"
  @send external wrap: T.t => T.t = "wrap"
  @send external toBounds: (T.t, float) => Types.lngLatBounds = "toBounds"
}
type t = Types.lngLat
@module("mapbox-gl") @new external make: (float, float) => t = "LngLat"
@module("mapbox-gl") @scope("LngLat") external convert: Types.lngLatLike => t = "convert"
include Mapbox__Common.Impl({
  type t = t
})
include InstanceMember({
  type t = t
})
