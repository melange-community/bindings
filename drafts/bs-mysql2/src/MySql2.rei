module Connection: {
  type t;

  let connect:
    (
      ~host: string=?,
      ~port: int=?,
      ~user: string=?,
      ~password: string=?,
      ~database: string=?,
      unit
    ) =>
    t;

  let isValid: t => bool;

  let close: t => unit;
};

module Pool: {
  type t;

  let make:
    (
      ~connectionLimit: int=?,
      ~queueLimit: int=?,
      ~waitForConnections: bool=?,
      ~host: string=?,
      ~port: int=?,
      ~user: string=?,
      ~password: string=?,
      ~database: string=?,
      unit
    ) =>
    t;

  let on:
    (
      t,
      [
        | `acquire(Connection.t => unit)
        | `enqueue(unit => unit)
        | `release(Connection.t => unit)
      ]
    ) =>
    t;

  let drain: (t, Js.Null_undefined.t(Js.Exn.t) => unit) => unit;

  let getConnection:
    (
      t,
      (Js.Null_undefined.t(Js.Exn.t), Js.Null_undefined.t(Connection.t)) =>
      unit
    ) =>
    unit;

  let release: Connection.t => unit;
};

module Exn: {
  type t;

  let toExn: t => exn;

  let fromJs: Js.Json.t => t;
};

module ID: {
  type t = MySql2_binding.ID.t;

  let fromJson: Js.Json.t => t;

  let toJson: t => Js.Json.t;

  let toString: t => string;
};

// @deprecated
module Id = ID;

module Mutation: {
  type t;

  let insertId: t => option(MySql2_binding.ID.t);

  let fieldCount: t => int;

  let affectedRows: t => int;

  let info: t => string;

  let serverStatus: t => int;

  let warningStatus: t => int;
};

module Params: {
  type t;

  let named: Js.Json.t => t;

  let positional: Js.Json.t => t;
};

module Meta: {
  type t;

  let t:
    (
      ~catalog: string,
      ~schema: string,
      ~name: string,
      ~orgName: string,
      ~table: string,
      ~orgTable: string,
      ~characterSet: int,
      ~columnLength: int,
      ~columnType: int,
      ~flags: int,
      ~decimals: int
    ) =>
    t;

  let catalog: t => string;

  let schema: t => string;

  let name: t => string;

  let orgName: t => string;

  let table: t => string;

  let orgTable: t => string;

  let characterSet: t => int;

  let columnLength: t => int;

  let columnType: t => int;

  let flags: t => int;

  let decimals: t => int;
};

module Select: {
  type t;

  // @deprecated
  module Meta = Meta;

  let make: (~rows: array(Js.Json.t), ~meta: array(Meta.t)) => t;

  let meta: t => array(Meta.t);

  let concat: (t, t) => t;

  let count: t => int;

  let flatMapWithMeta: (t, (Js.Json.t, array(Meta.t)) => 'a) => array('a);

  let flatMap: (t, Js.Json.t => 'a) => array('a);

  let rows: t => array(Js.Json.t);
};

type response = [
  | `Error(Exn.t)
  | `Mutation(Mutation.t)
  | `Select(Select.t)
];

type callback = response => unit;

let execute: (Connection.t, string, option(Params.t), callback) => unit;
