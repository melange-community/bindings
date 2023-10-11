module Map = Mapbox__Map
module LngLat = Mapbox__LngLat
module LngLatLike = Mapbox__LngLatLike
module Point = Mapbox__Point
module PointLike = Mapbox__PointLike
module Popup = Mapbox__Popup

// @see https://docs.mapbox.com/mapbox-gl-js/api/markers/#marker-instance-members
module InstanceMember = (
  T: {
    type t
  },
) => {
  @send external addTo: (T.t, Map.t) => T.t = "addTo"
  @send external getElement: T.t => Dom.element = "getElement"
  @send external getLngLat: T.t => LngLatLike.t = "getLngLat"
  @send external getOffset: T.t => PointLike.t = "getLngLat"
  @send external getPitchAlignment: T.t => string = "getPitchAlignment"
  @send external getPopup: (T.t) => Popup.t = "getPopup"
  @send external getRotation: T.t => float = "getRotation"
  @send external getRotationAlignment: T.t => string = "getRotationAlignment"
  @send external isDraggable: T.t => bool = "isDraggable"
  @send external remove: T.t => T.t = "remove"
  @send external setDraggable: (T.t, bool) => T.t = "setDraggable"
  @send external setLngLat: (T.t, LngLatLike.t) => T.t = "setLngLat"
  @send external setOffset: (T.t, PointLike.t) => T.t = "setOffset"
  @send external setPitchAlignment: (T.t, string) => T.t = "setPitchAlignment"
  @send external setPopup: (T.t, Popup.t) => T.t = "getPopup"
  @send external setRotation: (T.t, float) => T.t = "setRotation"
  @send external setRotationAligment: (T.t, string) => T.t = "setRotationAligment"
  @send external togglePopup: T.t => T.t = "togglePopup"
}
/**
TODO isn't implemented 
see https://docs.mapbox.com/mapbox-gl-js/api/markers/#marker-events
module Event = (T: { type t }) => {
  drag
  dragend
  dragstart
}
**/

type t
type options

@obj
external makeOptions: (
  ~element: Dom.element=?,
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
  ~color: string=?,
  ~scale: float=?,
  ~draggable: bool=?,
  ~clickTolerance: int=?,
  ~rotation: float=?,
  ~pitchAlignment: string=?,
  ~rotationAlignment: string=?,
  unit,
) => options = ""

@module("mapbox-gl") @new external make: unit => t = "Marker"
@module("mapbox-gl") @new external makeWithOptions: options => t = "Marker"

include InstanceMember({
  type nonrec t = t
})
