open Kanae;

module DataType = {
  type t =
    | Bool
    | String;
  [@bs.module "Sequelize"] external boolType : Js.Json.t = "BOOLEAN";
  [@bs.module "Sequelize"] external stringType : Js.Json.t = "STRING";
  let toJSON = data : Js.Json.t =>
    switch data {
    | Bool => boolType
    | String => stringType
    };
};

module Attribute = {
  module Basic = {
    type t = {
      .
      "type": Js.Json.t,
      "allowNull": option(bool),
      "defaultValue": option(Js.Json.t),
      "unique": option(bool),
      "primaryKey": option(bool),
      "field": option(string),
      "autoIncrement": option(bool),
      "comment": option(string)
    };
  };
  type t = {
    name: string,
    dataType: DataType.t,
    allowNull: option(bool),
    defaultValue: option(Js.Json.t),
    unique: option(bool),
    primaryKey: option(bool),
    autoIncrement: option(bool),
    comment: option(string),
    field: option(string)
  };
  let toBasic = attr : Basic.t => {
    let diet =
      Js.Primitive.diet({
        "type": DataType.toJSON(attr.dataType),
        "allowNull": attr.allowNull,
        "defaultValue": attr.defaultValue,
        "unique": attr.unique,
        "primaryKey": attr.primaryKey,
        "field": attr.field,
        "autoIncrement": attr.autoIncrement,
        "comment": attr.comment
      });
    diet;
  };
  let create =
      (
        ~allowNull=?,
        ~defaultValue=?,
        ~unique=?,
        ~primaryKey=?,
        ~field=?,
        ~autoIncrement=?,
        ~comment=?,
        ~dataType,
        name
      ) => {
    name,
    dataType,
    allowNull,
    defaultValue,
    unique,
    primaryKey,
    field,
    autoIncrement,
    comment
  };
};

module Attributes = {
  module Basic = {
    type t = Js.Dict.t(Attribute.Basic.t);
  };
  let toBasic = attrs : Basic.t => {
    let dict = Js.Dict.empty();
    List.iteri(attrs, ~f=(~i, ~elt as attr: Attribute.t) =>
      Js.Dict.set(dict, attr.name, Attribute.toBasic(attr))
    );
    dict;
  };
};

module Options = {
  /* TODO */
  module Basic = {
    type t = {
      .
      "modelName": option(string),
      "tableName": option(string),
      "engine": option(string),
      "comment": option(string)
    };
  };
  type t = {
    modelName: option(string),
    tableName: option(string),
    engine: option(string),
    comment: option(string)
  };
  let create = (~modelName=?, ~tableName=?, ~engine=?, ~comment=?, ()) => {
    modelName,
    tableName,
    engine,
    comment
  };
  let toBasic = opts => {
    "modelName": opts.modelName,
    "tableName": opts.tableName,
    "engine": opts.engine,
    "comment": opts.comment
  };
};

/*
 define(seq, Model.Spec.(module("name", opts)
 +> bool("name", ..)
 +> string("name", ..));
 */
module Spec = {
  type t = {
    name: string,
    attrs: list(Attribute.t),
    options: Options.t
  };
  let model = (~options=Options.create(), name) => {name, attrs: [], options};
  let (+>) = (model, attr) => {...model, attrs: [attr, ...model.attrs]};
  let string = Attribute.(create(~dataType=String));
};

module Basic = {
  type t;
  /* options */
  [@bs.send] external sync : t => Js.Promise.t(t) = "sync";
};

type t = Basic.t;

let sync = Basic.sync;