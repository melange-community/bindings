module CRS = {
  type t;
};

module Layer = {
  type t;
};

module Point = {
  type t;
  [@bs.send] external add : (t, t) => t = "";
  [@bs.send] external subtract : (t, t) => t = "";
  [@bs.send] external divideBy : (t, float) => t = "";
  [@bs.send] external multiplyBy : (t, float) => t = "";
  [@bs.send] external scaleBy : (t, float) => t = "";
  [@bs.send] external unscaleBy : (t, float) => t = "";
  [@bs.send] external distanceTo : (t, t) => float = "";
  [@bs.send] external contains : (t, t) => bool = "";
  [@bs.send] external equals : (t, t) => bool = "";
  [@bs.get] external x : t => float = "";
  [@bs.get] external y : t => float = "";
};

module LatLngBounds = {
  type t;
};

module LatLng = {
  type t;
  [@bs.get] external lat : t => float = "";
  [@bs.get] external lng : t => float = "";
  [@bs.get] external alt : t => int = "";
  [@bs.send] external toString : t => string = "";
  [@bs.send] external equals : (t, t) => bool = "";
  [@bs.send] external distanceTo : (t, t) => float = "";
  [@bs.send] external wrap : t => t = "";
  [@bs.send] external toBounds : (t, int) => LatLngBounds.t = "";
};

module Map = {
  type t;
  /* Interaction Options */
  /* Map State Options */
  [@bs.send] external crs : t => CRS.t = "";
  [@bs.send] [@bs.return undefined_to_opt]
  external center : t => option(LatLng.t) = "";
  [@bs.send] [@bs.return undefined_to_opt]
  external zoom : t => option(int) = "";
  [@bs.send] [@bs.return undefined_to_opt]
  external maxZoom : t => option(int) = "";
  [@bs.send] [@bs.return undefined_to_opt]
  external minZoom : t => option(int) = "";
  [@bs.send] external layers : t => list(Layer.t) = "";
  [@bs.send] [@bs.return null_to_opt]
  external maxBounds : t => option(LatLngBounds.t) = "";
  /* Methods for Layers and Controls */
  [@bs.send] external addLayer : (t, Layer.t) => t = "";
  [@bs.send] external removeLayer : (t, Layer.t) => t = "";
  [@bs.send] external hasLayer : (t, Layer.t) => bool = "";
};

module Control = {
  type t;
};

type map_options = {
  .
  "center": (int, int),
  "zoom": int,
};

type tile_layer_options = {
  .
  "minZoom": int,
  "maxZoom": int,
  "detectRetina": bool,
};

[@bs.module "leaflet"]
external tileLayer : (string, tile_layer_options) => Layer.t = "";

[@bs.module "leaflet"]
external latLngBounds : (LatLng.t, LatLng.t) => LatLngBounds.t = "";

[@bs.module "leaflet"] external latLng : ((float, float)) => LatLng.t = "";

[@bs.module "leaflet"]
external latLngAlt : ((float, float, float)) => LatLng.t = "latLng";

let create_lat_lng = (~latitude, ~longitude, ~altitude) =>
  switch (altitude) {
  | Some(alt) => latLngAlt((latitude, longitude, alt))
  | _ => latLng((latitude, longitude))
  };

[@bs.module "leaflet"] external point_int : (int, int) => Point.t = "point";

[@bs.module "leaflet"]
external point_float : (float, float, bool) => Point.t = "point";

[@bs.module "leaflet"]
external create_map : (string, map_options) => Map.t = "map";
