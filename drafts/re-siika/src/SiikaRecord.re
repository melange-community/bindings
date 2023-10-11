open Kanae;

module Model = SiikaModel;

module Query = SiikaQuery;

module Basic = {
  type t;
  [@bs.send]
  external findAll : (Model.t, Query.Basic.t) => Js.Promise.t(list(t)) =
    "findAll";
  [@bs.send] external build : Model.t => t = "build";
  /* values, options */
  external create : (Model.t, list(Js.Any.t)) => Js.Promise.t(t) = "create";
  [@bs.get] external isNew : t => bool = "isNewRecord";
  [@bs.send] external equals : (t, t) => bool = "equals";
  [@bs.send] external get : (t, string) => Js.Any.t = "get";
  [@bs.send] external set : (t, string, Js.Any.t) => unit = "set";
  [@bs.send] external save : t => Js.Promise.t(t) = "save";
  [@bs.send]
  external update : (t, Js.Json.t, Js.Json.t) => Js.Promise.t(t) = "update";
  [@bs.send] external toJSON : t => Js.Json.t = "toJSON";
};

type t = {
  basic: Basic.t,
  model: Model.t,
  values: Hashtbl.t(string, Js.Any.t)
};

module type S = {
  let init: SiikaApp.t => Model.t;
  let onGet: (t, string) => option(Js.Any.t);
  let onSet: (t, string, Js.Any.t) => unit;
  let onSave: t => unit;
};

module Generic = {
  let onGet = (_record, _key) => None;
  let onSet = (_record, _key, _value) => ();
  let onSave = _record => ();
};

module Make = (S: S) => {
  module Getter = {
    let string = Js.Any.toString;
  };
  module Setter = {
    let string = Js.Any.fromString;
  };
  let modelRef: ref(option(Model.t)) = ref(None);
  let model = () => Option.valueExn(modelRef^);
  let init = seq => modelRef := Some(S.init(seq));
  /* TODO */
  let findAll = (model, query) => Basic.findAll(model, Query.toBasic(query));
  /*
   let create = (model, values, _options) =>
     basicCreate(model, values, _options);
     */
  let create = model => model;
  let get = (record, key) =>
    /* check key for model attributes */
    Basic.get(record.basic, key);
  let set = (record, key, value) =>
    /* check key for model attributes */
    Basic.set(record.basic, key, value);
  let getter = (key: string, type_: Js.Any.t => 'a) : (t => 'a) =>
    record => type_(get(record, key));
  let setter = (key: string, type_: 'a => Js.Any.t) : ((t, 'a) => unit) =>
    (record, value) => set(record, key, type_(value));
  /*let save = record : Promise.t(Result.t(t, Error.t)) => ();*/
  let toJSON = record => Basic.toJSON(record.basic);
};