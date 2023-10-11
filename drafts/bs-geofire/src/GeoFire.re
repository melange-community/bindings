open BsFirebase;

type t;

type location = (float, float);

module GeoCallbackRegistration = {
  type t;
  [@bs.send] external cancel : t => unit = "";
};

module GeoQuery = {
  type t;
  [@bs.send] external center : t => location = "";
  [@bs.send] external radius : t => float = "";
  [@bs.send] external updateCriteria : (t, {. "center": location, "radius": float}) => unit = "";
  let updateCriteria = (geoQuery, ~center, ~radius) =>
    updateCriteria(geoQuery, {"center": center, "radius": radius});
  [@bs.send] external updateCenter : (t, {. "center": location}) => unit = "updateCriteria";
  let updateCenter = (geoQuery, center) => updateCenter(geoQuery, {"center": center});
  [@bs.send] external updateRadius : (t, {. "radius": float}) => unit = "updateCriteria";
  let updateRadius = (geoQuery, radius) => updateRadius(geoQuery, {"radius": radius});
  [@bs.send]
  external on :
    (
      t,
      [@bs.string]
      [
        | `ready(unit => unit)
        | `key_entered((string, location, float) => unit)
        | `key_exited((string, Js.nullable(location), Js.nullable(float)) => unit)
        | `key_moved((string, location, float) => unit)
      ]
    ) =>
    GeoCallbackRegistration.t =
    "";
  let on = (geoQuery, variant) =>
    switch variant {
    | `ready(callback) => on(geoQuery, `ready(callback))
    | `key_entered(callback) => on(geoQuery, `key_entered(callback))
    | `key_exited(callback) =>
      on(
        geoQuery,
        `key_exited(
          (key, location, distance) =>
            callback(key, location |> Js.toOption, distance |> Js.toOption)
        )
      )
    | `key_moved(callback) => on(geoQuery, `key_moved(callback))
    };
  [@bs.send] external cancel : t => unit = "";
};

[@bs.new] [@bs.module] external make : ReasonFirebase.Database.Reference.t => t = "geofire";

[@bs.send] external ref : t => ReasonFirebase.Database.Reference.t = "";

[@bs.send] external get : (t, string) => Js.Promise.t(Js.nullable(location)) = "";

let get = (geofire, string) : Js.Promise.t(option(location)) =>
  get(geofire, string)
  |> Js.Promise.then_((nullable) => nullable |> Js.toOption |> Js.Promise.resolve);

[@bs.send] external set : (t, string, location) => Js.Promise.t(unit) = "";

[@bs.send] external setMany : (t, Js.Dict.t(location)) => Js.Promise.t(unit) = "set";

[@bs.send] external remove : (t, string) => Js.Promise.t(unit) = "";

[@bs.send] external query : (t, {. "center": location, "radius": float}) => GeoQuery.t = "";

let query = (geoFire, ~center, ~radius) => query(geoFire, {"center": center, "radius": radius});

[@bs.module "geofire"] external distance : (location, location) => float = "";
