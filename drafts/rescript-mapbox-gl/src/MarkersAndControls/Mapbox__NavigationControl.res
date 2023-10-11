include Mapbox__Control
type options
@obj
external makeOptions: (
  ~showCompass: bool=?,
  ~showZoom: bool=?,
  ~visualizePitch: bool=?,
  unit,
) => options = ""
@module("mapbox-gl") @new external make: unit => t = "NavigationControl"
@module("mapbox-gl") @new external makeWithOptions: options => t = "NavigationControl"
