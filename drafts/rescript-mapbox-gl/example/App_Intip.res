/* eslint-disable import/no-webpack-loader-syntax */
open Mapbox

mapbox->setWorkerClass(mapboxGLWorker)
mapbox->setAccessToken("TOKEN")

let useMap = (~lng, ~lat, ~zoom) => {
  let container = React.useRef(Js.Nullable.null)
  let lngLat = [lng, lat]->LngLatLike.array
  React.useEffect4(() => {
    let map =
      container.current
      ->Js.Nullable.toOption
      ->Belt.Option.map(Map.element)
      ->Belt.Option.map(container =>
        Map.makeOptions(
          ~container,
          ~style="mapbox://styles/mapbox/outdoors-v11",
          ~center=lngLat,
          ~zoom,
          (),
        )->Map.makeWithOptions
      )

    let _ = map->Belt.Option.map(Marker.make()->Marker.setLngLat(lngLat)->Marker.addTo)
    let _ =
      map
      ->Belt.Option.map(
        Map.addControl(
          _,
          GeolocateControl.makeWithOptions(
            GeolocateControl.makeOptions(
              ~positionOptions=GeolocateControl.positionOptions(~enableHighAccuracy=true, ()),
              ~trackUserLocation=true,
              (),
            ),
          ),
        ),
      )
      ->Belt.Option.map(Map.addControlWithOptions(_, NavigationControl.make(), #topLeft))

    map->Belt.Option.map(Map.remove)
  }, (lng, lat, zoom, container))
  container
}

@react.component
let make = (~lng, ~lat, ~zoom, ~width, ~height) => {
  let mapContainer = useMap(~lng, ~lat, ~zoom)
  <div style={ReactDOM.Style.make(~width, ~height, ())} ref={ReactDOM.Ref.domRef(mapContainer)} />
}
