module Types = Mapbox__LngLat__Types
type t = Types.lngLatBoundsLike 
external array: array<array<float>> => t = "";
external arrayLngLat: array<Types.lngLat> => t = "";
external arrayLngLatLike: array<Types.lngLatLike> => t = "";

