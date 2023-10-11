include Mapbox__Global;
module Map = Mapbox__Map; 
module Marker = Mapbox__Marker; 
module LngLatLike = Mapbox__LngLatLike
module LngLat = Mapbox__LngLat;
module LngLatBoundsLike = Mapbox__LngLatBoundsLike;
module LngLatBounds = Mapbox__LngLatBounds;
module MercatorCoordinate = Mapbox__MercatorCoordinate;
module Point = Mapbox__Point
module PointLike = Mapbox__PointLike
module EdgeInsets = Mapbox__EdgeInsets
module Popup = Mapbox__Popup
module NavigationControl = Mapbox__NavigationControl
module GeolocateControl = Mapbox__GeolocateControl

/** Map **/
let map = Map.make
let mapMakeOptions = Map.makeOptions
let mapWithOptions = Map.makeWithOptions
/** Marker **/
let marker = Marker.make
let markerMakeOptions = Marker.makeOptions
let markerWithOptions = Marker.makeWithOptions
/** TODO alias make for another Module **/
