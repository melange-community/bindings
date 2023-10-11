open Kanae;

module SyncOptions = {
  module Basic = {
    type t = {
      .
      "force": option(bool),
      "alter": option(bool)
    };
  };
  type t = {
    force: option(bool),
    alter: option(bool)
  };
  let create = (~force=?, ~alter=?, ()) => {force, alter};
  let toBasic = opts =>
    Js.Primitive.diet({"force": opts.force, "alter": opts.alter});
};

module Options = {
  module Basic = {
    type t = {
      .
      "host": Js.null(string),
      "port": Js.null(int),
      "database": string,
      "username": Js.null(string),
      "password": Js.null(string),
      "dialect": string,
      "storage": Js.null(string),
      "protocol": Js.null(string)
    };
  };
  type dialect =
    | MySQL
    | SQLite(string) /* storage */
    | Postgres
    | MSSQL;
  type t = {
    host: option(string),
    port: option(int),
    database: string,
    username: option(string),
    password: option(string),
    dialect,
    protocol: option(string)
  };
  let create =
      (
        ~host=?,
        ~port=?,
        ~database,
        ~username=?,
        ~password=?,
        ~dialect,
        ~protocol=?,
        ()
      )
      : t => {
    host,
    port,
    database,
    username,
    password,
    dialect,
    protocol
  };
  let toBasic = (opts: t) : Basic.t => {
    "host": Js.Null.from_opt(opts.host),
    "port": Js.Null.from_opt(opts.port),
    "database": opts.database,
    "username": Js.Null.from_opt(opts.username),
    "password": Js.Null.from_opt(opts.password),
    "dialect":
      switch opts.dialect {
      | MySQL => "mysql"
      | SQLite(_) => "sqlite"
      | Postgres => "postgres"
      | MSSQL => "mssql"
      },
    "storage":
      Js.Null.from_opt(
        switch opts.dialect {
        | SQLite(path) => Some(path)
        | _ => None
        }
      ),
    "protocol": Js.Null.from_opt(opts.protocol)
  };
};

module Basic = {
  type t;
  [@bs.module "sequelize"] [@bs.new]
  external create : Options.Basic.t => t = "Sequelize";
  [@bs.send] external close : t => Promise.t(unit) = "close";
  [@bs.send] external escape : (t, string) => string = "escape";
  [@bs.send]
  external define :
    (t, string, SiikaModel.Attributes.Basic.t, SiikaModel.Options.Basic.t) =>
    SiikaModel.t =
    "define";
  [@bs.send] external authenticate : t => Js.Promise.t(unit) = "authenticate";
  [@bs.send]
  external query :
    (t, string) => Js.Promise.t((Js.Array.t(Js.Any.t), option(string))) =
    "query";
  [@bs.send] external sync : (t, SyncOptions.Basic.t) => Promise.t(t) = "sync";
};

type t = Basic.t;

let options = Options.create;

let create = opts => Basic.create(Options.toBasic(opts));

let define = (seq: t, spec: SiikaModel.Spec.t) =>
  /*Js.log(Model.Attributes.toBasic(spec.attrs));*/
  Basic.define(
    seq,
    spec.name,
    SiikaModel.Attributes.toBasic(spec.attrs),
    SiikaModel.Options.toBasic(spec.options)
  );

let authenticate = Basic.authenticate;

let sync = (~options=?, seq) =>
  Basic.sync(
    seq,
    switch options {
    | None => SyncOptions.create() |> SyncOptions.toBasic
    | Some(opts) => SyncOptions.toBasic(opts)
    }
  );