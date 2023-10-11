module Types = Mapbox__LngLat__Types
// @see https://docs.mapbox.com/mapbox-gl-js/api/geography/#mercatorcoordinate-instance-members
module InstanceMember = (
  T: {
    type t
  },
) => {
  @send external meterInMercatorCoordinateUnits: T.t => float = "meterInMercatorCoordinateUnits"
  @send external toAltitude: T.t => float = "toAltitude"
  @send external toLngLat: T.t => Types.lngLat = "toLngLat"
}
type t = Types.mercatorCoordinate
@module("mapbox-gl") @new external make: (float, float, float) => t = "MercatorCoordinate"
@module("mapbox-gl") @scope("MercatorCoordinate")
external fromLngLat: (Types.lngLatLike, float) => t = "fromLngLat"
include InstanceMember({ type nonrec t = t })
