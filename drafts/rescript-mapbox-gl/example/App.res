open Mapbox

let map = Map.make()

let mapWithOpt = Map.makeOptions(~container=Map.id("app-hash-in-dom"), ())->Map.makeWithOptions

let marker = Marker.make()->Marker.setLngLat([30.5, 50.5]->LngLatLike.array)->Marker.addTo(map)

let lngLikeArr = LngLatLike.array([30.5, 50.5]) 
let lngLat= LngLatLike.lngLat(~lng=30.5, ~lat=50.5)
let convertFromArr = LngLat.convert(lngLikeArr)
let convertFromLngLat = LngLat.convert(lngLat)
