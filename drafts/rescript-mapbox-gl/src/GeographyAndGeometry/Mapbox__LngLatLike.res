module Types = Mapbox__LngLat__Types
type t = Types.lngLatLike
@obj external lngLat: (~lng: float, ~lat: float) => t = ""
@obj external lonLat: (~lon: float, ~lat: float) => t = ""
external array: array<float> => t = "%identity"
