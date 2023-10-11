open BsFirebase;

open Jest;

open ExpectJs;

open Utilities;

open Utilities.Jest;

let app =
  ReasonFirebase.initializeApp(
    ~options={
      "apiKey": requiredEnvVar("FIREBASE_API_KEY"),
      "authDomain": requiredEnvVar("FIREBASE_AUTH_DOMAIN"),
      "databaseURL": requiredEnvVar("FIREBASE_DATABASE_URL"),
      "storageBucket": requiredEnvVar("FIREBASE_STORAGE_BUCKET"),
      "messagingSenderId": requiredEnvVar("FIREBASE_MESSAGING_SENDER_ID")
    }
  );

let reference: ref(option(ReasonFirebase.Database.Reference.t)) = ref(None);

let geoFire: ref(option(GeoFire.t)) = ref(None);

let geoQueries: ref(list(GeoFire.GeoQuery.t)) = ref([]);

beforeEach(
  () => {
    let database = ReasonFirebase.App.database(app);
    let root_reference = ReasonFirebase.Database.ref(database, ());
    let temporary_reference = ReasonFirebase.Database.Reference.push(root_reference, ());
    reference := Some(temporary_reference);
    geoFire := Some(GeoFire.make(temporary_reference));
    geoQueries := []
  }
);

afterEachPromise(
  () => {
    geoQueries^ |> List.map(GeoFire.GeoQuery.cancel) |> ignore;
    let temporary_reference = reference^ |> Js.Option.getExn;
    reference := None;
    geoFire := None;
    geoQueries := [];
    /* TODO: Use ReasonFirebase.Database.Reference.remove */
    ReasonFirebase.Database.Reference.set(temporary_reference, ~value=Js.null, ())
    |> Js.Promise.then_(() => Promise.wait(50))
  }
);

describe(
  "GeoFire",
  () => {
    test(
      "GeoFire.ref() returns the Firebase reference",
      () => {
        let reference = reference^ |> Js.Option.getExn;
        let geoFire = geoFire^ |> Js.Option.getExn;
        expect(GeoFire.ref(geoFire)) |> toBe(reference)
      }
    );
    test(
      "GeoFire.get(invalidKey) throws",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        expect(() => GeoFire.get(geoFire, "foo#bar")) |> toThrow
      }
    );
    testPromise(
      "GeoFire.get(nonexistentKey) returns None",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        GeoFire.get(geoFire, "foo") |> Promise.map((location) => expect(location) |> toBe(None))
      }
    );
    test(
      "GeoFire.set(invalidKey, location) throws",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        expect(() => GeoFire.set(geoFire, "foo/bar", (23.0, 74.0))) |> toThrow
      }
    );
    test(
      "GeoFire.set(key, invalidLocation) throws",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        expect(() => GeoFire.set(geoFire, "foo", (0.0, 181.0))) |> toThrow
      }
    );
    testPromise(
      "GeoFire.get(key) returns location set by GeoFire.set(key, location)",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        GeoFire.set(geoFire, "foo", (47.235124363, 127.2379654226))
        |> Js.Promise.then_(() => GeoFire.get(geoFire, "foo"))
        |> Promise.map(
             (location) => expect(location) |> toEqual(Some((47.235124363, 127.2379654226)))
           )
      }
    );
    testPromise(
      "GeoFire.get(key)... return locations set by GeoFire.set(keyedLocations)",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let keyedLocations =
          [|("foo", (0.0, 0.0)), ("bar", (90.0, (-180.0)))|] |> Js.Dict.fromArray;
        GeoFire.setMany(geoFire, keyedLocations)
        |> Js.Promise.then_(
             () => Js.Promise.all2((GeoFire.get(geoFire, "foo"), GeoFire.get(geoFire, "bar")))
           )
        |> Promise.map(
             (locations) =>
               expect(locations) |> toEqual((Some((0.0, 0.0)), Some((90.0, (-180.0)))))
           )
      }
    );
    testPromise(
      "GeoFire.remove(nonexistentKey) succeeds",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        GeoFire.remove(geoFire, "foo") |> Promise.map(() => pass)
      }
    );
    testPromise(
      "GeoFire.remove(key) removes location set by GeoFire.set(key, location)",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        GeoFire.set(geoFire, "foo", ((-90.0), 180.0))
        |> Js.Promise.then_(() => GeoFire.get(geoFire, "foo"))
        |> Js.Promise.then_(
             (before) =>
               GeoFire.remove(geoFire, "foo")
               |> Js.Promise.then_(() => GeoFire.get(geoFire, "foo"))
               |> Promise.map(
                    (after) => expect((before, after)) |> toEqual((Some(((-90.0), 180.0)), None))
                  )
           )
      }
    );
    test(
      "GeoFire.query({invalidCenter, radius}) throws",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        expect(
          () => {
            let geoQuery = GeoFire.query(geoFire, ~center=(91.0, 2.0), ~radius=1000.0);
            geoQueries := [geoQuery, ...geoQueries^]
          }
        )
        |> toThrow
      }
    );
    test(
      "GeoFire.query({center, invalidRadius}) throws",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        expect(
          () => {
            let geoQuery = GeoFire.query(geoFire, ~center=(1.0, 2.0), ~radius=(-10.0));
            geoQueries := [geoQuery, ...geoQueries^]
          }
        )
        |> toThrow
      }
    );
    test(
      "GeoFire.query({center, radius}) succeeds",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let geoQuery = GeoFire.query(geoFire, ~center=(1.0, 2.0), ~radius=1000.0);
        geoQueries := [geoQuery, ...geoQueries^];
        expect(geoQuery) |> toBeTruthy
      }
    )
  }
);

describe(
  "GeoQuery",
  () => {
    test(
      "GeoQuery.center() returns the center",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let geoQuery = GeoFire.query(geoFire, ~center=(2.0, 3.0), ~radius=1000.0);
        geoQueries := [geoQuery, ...geoQueries^];
        expect(GeoFire.GeoQuery.center(geoQuery)) |> toEqual((2.0, 3.0))
      }
    );
    test(
      "GeoQuery.radius() returns the radius",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let geoQuery = GeoFire.query(geoFire, ~center=(2.0, 3.0), ~radius=1000.0);
        geoQueries := [geoQuery, ...geoQueries^];
        expect(GeoFire.GeoQuery.radius(geoQuery)) |> toEqual(1000.0)
      }
    );
    test(
      "GeoQuery.updateCriteria({invalidCenter}) throws",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let geoQuery = GeoFire.query(geoFire, ~center=(2.0, 3.0), ~radius=1000.0);
        geoQueries := [geoQuery, ...geoQueries^];
        expect(() => GeoFire.GeoQuery.updateCenter(geoQuery, (1.0, (-181.0)))) |> toThrow
      }
    );
    test(
      "GeoQuery.updateCriteria({invalidRadius}) throws",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let geoQuery = GeoFire.query(geoFire, ~center=(2.0, 3.0), ~radius=1000.0);
        geoQueries := [geoQuery, ...geoQueries^];
        expect(() => GeoFire.GeoQuery.updateRadius(geoQuery, (-1.0))) |> toThrow
      }
    );
    test(
      "GeoQuery.updateCriteria({center}) updates the center",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let geoQuery = GeoFire.query(geoFire, ~center=(2.0, 3.0), ~radius=1000.0);
        geoQueries := [geoQuery, ...geoQueries^];
        let before = GeoFire.GeoQuery.center(geoQuery);
        GeoFire.GeoQuery.updateCenter(geoQuery, (0.0, 0.0));
        let after = GeoFire.GeoQuery.center(geoQuery);
        expect((before, after)) |> toEqual(((2.0, 3.0), (0.0, 0.0)))
      }
    );
    test(
      "GeoQuery.updateCriteria({radius}) updates the radius",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let geoQuery = GeoFire.query(geoFire, ~center=(2.0, 3.0), ~radius=1000.0);
        geoQueries := [geoQuery, ...geoQueries^];
        let before = GeoFire.GeoQuery.radius(geoQuery);
        GeoFire.GeoQuery.updateRadius(geoQuery, 1.78);
        let after = GeoFire.GeoQuery.radius(geoQuery);
        expect((before, after)) |> toEqual((1000.0, 1.78))
      }
    );
    test(
      "GeoQuery.updateCriteria({center, radius}) updates the center and radius",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let geoQuery = GeoFire.query(geoFire, ~center=(2.0, 3.0), ~radius=1000.0);
        geoQueries := [geoQuery, ...geoQueries^];
        let before = (GeoFire.GeoQuery.center(geoQuery), GeoFire.GeoQuery.radius(geoQuery));
        GeoFire.GeoQuery.updateCriteria(geoQuery, ~center=(22.22, (-107.77)), ~radius=1.0);
        let after = (GeoFire.GeoQuery.center(geoQuery), GeoFire.GeoQuery.radius(geoQuery));
        expect((before, after)) |> toEqual((((2.0, 3.0), 1000.0), ((22.22, (-107.77)), 1.0)))
      }
    );
    testAsync(
      "GeoQuery.on('ready', callback) fires",
      (done_) => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let geoQuery = GeoFire.query(geoFire, ~center=(2.0, 3.0), ~radius=1000.0);
        geoQueries := [geoQuery, ...geoQueries^];
        GeoFire.GeoQuery.on(geoQuery, `ready(() => done_(pass))) |> ignore
      }
    );
    testAsync(
      "GeoQuery.on('key_entered', callback) fires with location data",
      (done_) => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let geoQuery = GeoFire.query(geoFire, ~center=(45.0, (-100.0)), ~radius=100.0);
        geoQueries := [geoQuery, ...geoQueries^];
        GeoFire.GeoQuery.on(
          geoQuery,
          `key_entered(
            (key, location, distance) =>
              done_(
                expect((key, location, distance |> int_of_float))
                |> toEqual(("foo", (45.1, (-100.0)), 11))
              )
          )
        )
        |> ignore;
        GeoFire.set(geoFire, "foo", (45.1, (-100.0))) |> ignore
      }
    );
    testAsync(
      "GeoQuery.on('key_exited', callback) fires with only the key when a key is removed",
      (done_) => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        GeoFire.set(geoFire, "foo", (37.7853074, (-122.4054274))) |> ignore;
        let geoQuery = GeoFire.query(geoFire, ~center=(37.8, (-122.4)), ~radius=100.0);
        geoQueries := [geoQuery, ...geoQueries^];
        GeoFire.GeoQuery.on(
          geoQuery,
          `key_exited(
            (key, location, distance) =>
              done_(expect((key, location, distance)) |> toEqual(("foo", None, None)))
          )
        )
        |> ignore;
        GeoFire.remove(geoFire, "foo") |> ignore
      }
    );
    testAsync(
      "GeoQuery.on('key_exited', callback) fires with location data when a key moves away",
      (done_) => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        GeoFire.set(geoFire, "foo", (37.7853074, (-122.4054274))) |> ignore;
        let geoQuery = GeoFire.query(geoFire, ~center=(37.8, (-122.4)), ~radius=100.0);
        geoQueries := [geoQuery, ...geoQueries^];
        GeoFire.GeoQuery.on(
          geoQuery,
          `key_exited(
            (key, location, distance) =>
              done_(
                expect((key, location, distance |> Option.map(int_of_float)))
                |> toEqual(("foo", Some((80.0, 120.0)), Some(6373)))
              )
          )
        )
        |> ignore;
        GeoFire.set(geoFire, "foo", (80.0, 120.0)) |> ignore
      }
    );
    testAsync(
      "GeoQuery.on('key_moved', callback) fires with data",
      (done_) => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        GeoFire.set(geoFire, "foo", (50.0, 50.0)) |> ignore;
        let geoQuery = GeoFire.query(geoFire, ~center=(50.0, 50.0), ~radius=10.0);
        geoQueries := [geoQuery, ...geoQueries^];
        GeoFire.GeoQuery.on(
          geoQuery,
          `key_moved(
            (key, location, distance) =>
              done_(
                expect((key, location, distance |> int_of_float))
                |> toEqual(("foo", (50.01, 50.01), 1))
              )
          )
        )
        |> ignore;
        GeoFire.set(geoFire, "foo", (50.01, 50.01)) |> ignore
      }
    );
    testPromise(
      "GeoQuery.cancel() prevents further callbacks from firing",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let geoQuery = GeoFire.query(geoFire, ~center=(50.0, 50.0), ~radius=100.0);
        geoQueries := [geoQuery, ...geoQueries^];
        let mockFn = JestJs.inferred_fn();
        let fn = MockJs.fn(mockFn);
        let key_entered = (key, _location, _distance) => [@bs] fn(key) |> ignore;
        GeoFire.GeoQuery.on(geoQuery, `key_entered(key_entered)) |> ignore;
        GeoFire.set(geoFire, "foo", (50.02, 50.02)) |> ignore;
        GeoFire.GeoQuery.cancel(geoQuery);
        GeoFire.set(geoFire, "bar", (50.01, 50.01)) |> ignore;
        Promise.wait(1000)
        |> Promise.map(() => expect(mockFn |> MockJs.calls) |> toEqual([|"foo"|]))
      }
    )
  }
);

describe(
  "GeoCallbackRegistration",
  () =>
    testPromise(
      "GeoCallbackRegistration.cancel() prevents further callbacks from firing",
      () => {
        let geoFire = geoFire^ |> Js.Option.getExn;
        let geoQuery = GeoFire.query(geoFire, ~center=(50.0, 50.0), ~radius=100.0);
        geoQueries := [geoQuery, ...geoQueries^];
        let mockFn = JestJs.inferred_fn();
        let fn = MockJs.fn(mockFn);
        let key_entered = (key, _location, _distance) => [@bs] fn(key) |> ignore;
        let geoCallbackRegistration = GeoFire.GeoQuery.on(geoQuery, `key_entered(key_entered));
        GeoFire.set(geoFire, "foo", (50.02, 50.02)) |> ignore;
        GeoFire.GeoCallbackRegistration.cancel(geoCallbackRegistration);
        GeoFire.set(geoFire, "bar", (50.01, 50.01)) |> ignore;
        Promise.wait(1000)
        |> Promise.map(() => expect(mockFn |> MockJs.calls) |> toEqual([|"foo"|]))
      }
    )
);

describe(
  "Helper Methods",
  () =>
    test(
      "GeoFire.distance",
      () =>
        expect(GeoFire.distance(((-54.933333), (-67.616667)), ((-54.0), (-67.0))))
        |> toBeSoCloseTo(111.0, ~digits=0)
    )
);
