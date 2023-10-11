module Map = Mapbox__Map
module LngLat = Mapbox__LngLat
module LngLatLike = Mapbox__LngLatLike
module Point = Mapbox__Point
module PointLike = Mapbox__PointLike

// @see https://docs.mapbox.com/mapbox-gl-js/api/markers/#popup-instance-members 
module InstanceMember = (
  T: {
    type t
  },
) => {
  @send external addClassName: (T.t, string) => T.t = "addClassName"
  @send external addTo: (T.t, Map.t) => T.t = "addTo"
  @send external getElement: T.t => Dom.element = "getElement"
  @send external getLngLat: T.t => LngLatLike.t = "getLngLat"
  @send external getMaxWidth: T.t => string = "getMaxWidth"
  @send external isOpen: T.t => bool = "isOpen"
  @send external remove: T.t => T.t = "remove"
  @send external removeClassName: (T.t, string) => T.t = "removeClassName"
  @send external setDOMContent: (T.t, Dom.node) => T.t = "setDOMContent"
  @send external setHTML: (T.t, string) => T.t ="setHTML"
  @send external setLngLat: (T.t, LngLatLike.t) => T.t = "setLngLat"
  @send external setOffset: (T.t, PointLike.t) => T.t = "setOffset"
  @send external setMaxWidth: (T.t, string) => T.t ="setMaxWidth"
  @send external setText: (T.t, string) => T.t ="setText"
  @send external toggleClassName: (T.t, string) => T.t ="toggleClassName"
  @send external trackPointer: (T.t) => T.t= "trackPointer"
}

/**
TODO isn't implemented 
module Event = (T: { type t }) => {
  // read here https://docs.mapbox.com/mapbox-gl-js/api/markers/#popup-events
}
**/

type t
type options

// @see https://docs.mapbox.com/mapbox-gl-js/api/markers/#popup-parameters
@obj
external makeOptions: (
  ~closeButton: bool=?,
  ~closeOnClick: bool=?,
  ~closeOnMove: bool=?,
  ~focusAfterOpen: bool=?,
  ~anchor: @string
  [
    | #center
    | #top
    | #bottom
    | #left
    | #right
    | @as("top-left") #topLeft
    | @as("top-right") #topRight
    | @as("bottom-left") #bottomLeft
    | @as("bottom-right") #bottomRight
  ]=?,
  ~offset: PointLike.t=?,
  ~className: string=?,
  ~maxWidth: string=?,
  unit,
) => options = ""

@module("mapbox-gl") @new external make: unit => t = "Popup"
@module("mapbox-gl") @new external makeWithOptions: options => t = "Popup"

include InstanceMember({
  type nonrec t = t
})
