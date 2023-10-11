include Mapbox__Control
// see https://developer.mozilla.org/en-US/docs/Web/API/PositionOptions
type options;
type positionOptions
@obj external positionOptions: (
  ~enableHighAccuracy:bool=?,
  ~timeout:float=?,
  ~maximumAge: float=?,
  unit
) => positionOptions = ""
@obj external makeOptions: (
  ~positionOptions:positionOptions=?,
  // TODO isn't implemented fitBoundsOptions
  ~trackUserLocation:bool=?,
  ~showAccuracyCircle:bool=?,
  ~showUserLocation:bool=?,
  unit
) => options = ""
@module("mapbox-gl") @new external make: unit => t = "GeolocateControl"
@module("mapbox-gl") @new external makeWithOptions: options => t = "GeolocateControl"
// instance member 
@send external trigger: t => bool = "trigger"
// TODO events https://docs.mapbox.com/mapbox-gl-js/api/markers/#geolocatecontrol-events
