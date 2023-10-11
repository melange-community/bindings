module Types = Mapbox__LngLat__Types
type t = Types.edgeInsets;
@module("mapbox-gl") @new external make: (float, float, float, float) => t = "EdgeInsets"
@module("mapbox-gl") @scope("EdgeInsets") external getCenter: (t, float, float) => Types.point = "getCenter"
/** isn't implemented
@see https://docs.mapbox.com/mapbox-gl-js/api/geography/#edgeinsets-static-members
interpolate(start, traget, t)
toJson()
**/
