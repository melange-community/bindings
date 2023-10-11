open BsFirebase;

type t;

type location = (float, float);

module GeoCallbackRegistration: {
  type t;
  /* GeoCallbackRegistration.cancel()
   *
   * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#geocallbackregistrationcancel */
  let cancel: t => unit;
};

module GeoQuery: {
  type t;
  /* GeoQuery.center()
   *
   * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#geoquerycenter */
  let center: t => location;
  /* GeoQuery.radius()
   *
   * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#geoqueryradius */
  let radius: t => float;
  /* GeoQuery.updateCriteria(newQueryCriteria)
   *
   * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#geoqueryupdatecriterianewquerycriteria */
  let updateCriteria: (t, ~center: location, ~radius: float) => unit;
  let updateCenter: (t, location) => unit;
  let updateRadius: (t, float) => unit;
  /* GeoQuery.on(eventType, callback)
   *
   * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#geoqueryoneventtype-callback */
  let on:
    (
      t,
      [<
        | `key_entered((string, location, float) => unit)
        | `key_exited((string, option(location), option(float)) => unit)
        | `key_moved((string, location, float) => unit)
        | `ready(unit => unit)
      ]
    ) =>
    GeoCallbackRegistration.t;
  /* GeoQuery.cancel()
   *
   * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#geoquerycancel */
  let cancel: t => unit;
};

/* new GeoFire(firebaseRef)
 *
 * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#new-geofirefirebaseref */
let make: ReasonFirebase.Database.Reference.t => t;

/* GeoFire.ref()
 *
 * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#geofireref */
let ref: t => ReasonFirebase.Database.Reference.t;

/* GeoFire.get(key)
 *
 * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#geofiregetkey */
let get: (t, string) => Js.Promise.t(option(location));

/* GeoFire.set(keyOrLocations[, location])
 *
 * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#geofiresetkeyorlocations-location */
let set: (t, string, location) => Js.Promise.t(unit);

let setMany: (t, Js.Dict.t(location)) => Js.Promise.t(unit);

/* GeoFire.remove(key)
 *
 * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#geofireremovekey */
let remove: (t, string) => Js.Promise.t(unit);

/* GeoFire.query(queryCriteria)
 *
 * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#geofirequeryquerycriteria */
let query: (t, ~center: location, ~radius: float) => GeoQuery.t;

/* GeoFire.distance(location1, location2)
 *
 * https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md#geofiredistancelocation1-location2 */
let distance: (location, location) => float;
