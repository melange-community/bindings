open Express;

/* The tests below relies upon the ability to store in the Request
      objects abritrary JSON properties.

      Each middleware will both check that previous middleware
      have been called by making properties exists in the Request object and
      upon success will themselves adds anothe property to the Request.

   */
/* [checkProperty req next property k] makes sure [property] is
   present in [req]. If success then [k()] is invoked, otherwise
   [Next.route] is called with next */
let checkProperty = (req, next, property, k) => {
  let reqData = Request.asJsonObject(req);
  switch (Js.Dict.get(reqData, property)) {
  | None => next(Next.route)
  | Some(x) =>
    switch (Js.Json.decodeBoolean(x)) {
    | Some(b) when b => k()
    | _ => next(Next.route)
    }
  }
};

/* same as [checkProperty] but with a list of properties */
let checkProperties = (req, next, properties, k) => {
  let rec aux = (properties) =>
    switch properties {
    | [] => k()
    | [p, ...tl] => checkProperty(req, next, p, () => aux(tl))
    };
  aux(properties)
};

/* [setProperty req property] sets the [property] in the [req] Request
   value */
let setProperty = (req, property) => {
  let reqData = Request.asJsonObject(req);
  Js.Dict.set(reqData, property, Js.Json.boolean(true))
};

/* return the string value for [key], None if the key is not in [dict]
   TODO once BOption.map is released */
let getDictString = (dict, key) =>
  switch (Js.Dict.get(dict, key)) {
  | Some(json) => Js.Json.decodeString(json)
  | _ => None
  };

/* make a common JSON object representing success */
let makeSuccessJson = () => {
  let json = Js.Dict.empty();
  Js.Dict.set(json, "success", Js.Json.boolean(true));
  Js.Json.object_(json)
};

let app = express();

App.get(app, ~path="/nullCookies") @@
Middleware.from(
  (next, req) =>
    switch (Request.cookies(req)) {
    | None => Response.sendJson(makeSuccessJson())
    | Some(_) => next(Next.route)
    }
);

App.get(app, ~path="/nullSignedCookies") @@
Middleware.from(
  (next, req) =>
    switch (Request.signedCookies(req)) {
    | None => Response.sendJson(makeSuccessJson())
    | Some(_) => next(Next.route)
    }
);

App.getWithMany(app, ~path="/cookies") @@
[|
  CookieParser.make(),
  /* This will enable cookie parsing on that path */
  Middleware.from(
    (next, req) =>
      switch (Request.cookies(req)) {
      | Some(kv) =>
        switch (getDictString(kv, "key")) {
        | Some("value") => Response.sendJson(makeSuccessJson())
        | _ => next(Next.route)
        }
      | None => next(Next.route)
      }
  )
|];

App.listen(app, ~port=3000, ());
/* -- Test the server --
   npm run start && cd tests && ./test.sh
   */
