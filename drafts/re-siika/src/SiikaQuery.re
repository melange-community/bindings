module Where = {
  module Op = {
    type t;
    [@bs.module "Sequelize.Op"] external or_ : t = "or";
  };
  type attr = string;
  type value =
    | Bool(bool)
    | String(string)
    | Int(int);
  type t =
    | And(t, t)
    | Or(t, t)
    | Gt(attr, value)
    | Ge(attr, value)
    | Lt(attr, value)
    | Le(attr, value)
    | Ne(attr, value)
    | Eq(attr, value)
    | Between(attr, value)
    | NotBetween(attr, value)
    | In(attr, value)
    | NotIn(attr, value)
    | Like(attr, value)
    | NotLike(attr, value)
    | Regexp(attr, value)
    | NotRegexp(attr, value)
    | IRegexp(attr, value)
    | NotIRegexp(attr, value)
    | Contains(attr, list(value))
    | Contained(attr, list(value))
    | Overlap(attr, list(value))
    | Adjacent(t, t)
    | StrictLeft(t, t)
    | StrictRight(t, t)
    | NoExtendRight(t, t)
    | NoExtendLight(t, t)
    | Any
    | Col;
  let (@&) = (a, b) => And(a, b);
  let (@|) = (a, b) => Or(a, b);
  let (@>) = (a, b) => Gt(a, b);
  let (@>=) = (a, b) => Ge(a, b);
  let (@<) = (a, b) => Lt(a, b);
  let (@<=) = (a, b) => Le(a, b);
  let (@==) = (a, b) => Eq(a, b);
  let (@!=) = (a, b) => Ne(a, b);
  let (@@>) = (a, b) => Contains(a, b);
  let (@@<) = (a, b) => Contained(a, b);
  let (@&&) = (a, b) => Overlap(a, b);
  let (@-|-) = (a, b) => Adjacent(a, b);
  let (@<<) = (a, b) => StrictLeft(a, b);
  let (@>>) = (a, b) => StrictRight(a, b);
  let (@&<) = (a, b) => NoExtendLight(a, b);
  let (@&>) = (a, b) => NoExtendRight(a, b);
  let valueToJSON = value =>
    switch value {
    | Bool(v) => Js.Json.boolean(Js.Boolean.to_js_boolean(v))
    | String(v) => Js.Json.string(v)
    | Int(v) => Js.Json.number(float_of_int(v))
    };
  let toJSON = where =>
    switch where {
    | Eq(attr, value) =>
      let dict = Js.Dict.empty();
      Js.Dict.set(dict, attr, valueToJSON(value));
      Js.Json.object_(dict);
    | _ => failwith("op")
    };
};

module Basic = {
  type t = {
    .
    "attributes": Js.null(unit),
    "where": Js.null(Js.Json.t)
  };
};

type t =
  | Attrs /* TODO */
  | Where(Where.t);

/*
    ex:
 let find = Query.(where(Attr("name") @== String("John") @|| "age" @!= Int(50)));
    */
let where = where => Where(where);

let toBasic = query =>
  switch query {
  | Attrs => {"attributes": Js.Null.empty, "where": Js.Null.empty}
  | Where(where) => {
      "attributes": Js.Null.empty,
      "where": Js.Null.return(Where.toJSON(where))
    }
  };