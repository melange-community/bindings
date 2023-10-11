# bs-geofire

[BuckleScript][] bindings to [GeoFire][], written in [Reason][].

## Installation

Install NPM packages [bs-firebase][] and [bs-geofire][]—

```shell
yarn add 'bs-firebase' 'https://github.com/AndrewKvalheim/bs-geofire'
```

—and register both in [`bsconfig.json`][bs-dependencies]:

```diff
-  "bs-dependencies": []
+  "bs-dependencies": ["bs-firebase", "bs-geofire"]
```

## Usage

Refer to the [module interface][interface] and [GeoFire API][].

### Example

```reason
/* Initialize GeoFire. */
let app = ReasonFirebase.initializeApp(~options);
let database = ReasonFirebase.App.database(app);
let reference = ReasonFirebase.Database.ref(database, ~path="example", ());
let geoFire = GeoFire.make(reference);

/* Start a query. */
let geoQuery = GeoFire.query(geoFire, ~center=(49.304, -123.145), ~radius=2.0);

/* Subscribe to nearby moved locations. */
let callback = (key, location, distance) =>
  Js.log({j|$key moved to $location, which is $distance km away.|j});
let registration = GeoFire.GeoQuery.on(geoQuery, `key_moved(callback));

/* Add a location, */
GeoFire.set(geoFire, "foo", (49.306, -123.156))
/* then move it, */
|> Js.Promise.then_(() => GeoFire.set(geoFire, "foo", (49.313, -123.148)))
/* then unsubscribe and stop the query. */
|> Js.Promise.then_(() => {
     GeoFire.GeoCallbackRegistration.cancel(registration);
     GeoFire.GeoQuery.cancel(geoQuery);
     Js.Promise.resolve()
   })
```


  [bs-dependencies]: https://bucklescript.github.io/bucklescript/Manual.html#_build_with_other_bucklescript_dependencies
  [bs-firebase]: https://github.com/viskahq/bs-firebase
  [bs-geofire]: https://github.com/AndrewKvalheim/bs-geofire
  [BuckleScript]: https://bucklescript.github.io/
  [GeoFire]: https://github.com/firebase/geofire-js/
  [GeoFire API]: https://github.com/firebase/geofire-js/blob/v4.1.2/docs/reference.md
  [interface]: ./src/GeoFire.rei
  [Reason]: https://reasonml.github.io/
