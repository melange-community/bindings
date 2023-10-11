module LngLatLike = Mapbox__LngLatLike
module Control = Mapbox__Control
// @see https://docs.mapbox.com/mapbox-gl-js/api/map/#map-instance-members
// TODO check instance member
module InstanceMember = (
  T: {
    type t
  },
) => {
  @send external addControl: (T.t, Control.t) => T.t = "addControl"
  @send external addControlWithOptions: (T.t, Control.t, Control.position) => T.t = "addControl"
  @send external remove: (T.t, unit) => unit = "remove"
}

type t
type options
type container
external id: string => container = "%identity"
external element: Dom.element => container = "%identity"
@obj
external makeOptions: (
  ~container: container=?,
  ~center: LngLatLike.t=?,
  ~zoom: float=?,
  ~minZoom: float=?,
  ~maxZoom: float=?,
  ~pitch: float=?,
  ~minPitch: float=?,
  ~maxPitch: float=?,
  ~style: string=?,
  ~accessToken: string=?,
  ~collectResourceTiming: bool=?,
  ~fadeDuration: float=?,
  ~crossSourceCollisions: bool=?,
  ~localFontFamily: string=?,
  // default: 'sans-serif'
  ~localIdeographFamily: string=?,
  ~maxTileCacheSize: float=?,
  ~renderWorldCopies: bool=?,
  ~optimizeForTerrain: bool=?,
  // TODO {LngLatBonds}
  // ~bounds =
  // ~fitBounds
  ~testMode: bool=?,
  unit,
) => options = ""
@module("mapbox-gl") @new external make: unit => t = "Map"
@module("mapbox-gl") @new external makeWithOptions: options => t = "Map"
include InstanceMember({
  type t = t
})
