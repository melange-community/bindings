module Exn = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    name: string,
    [@bs.optional] [@bs.as "message"]
    msg: string,
    [@bs.optional]
    code: string,
    [@bs.optional]
    errno: int,
    [@bs.optional]
    sql: string,
    [@bs.optional]
    sqlState: string,
    [@bs.optional]
    sqlMessage: string,
  };

  // Shady conversion to cast thrown error objects.
  external fromJs: Js.Json.t => t = "%identity";
};

module ID = {
  type t = Js.Json.t;
};

module Connection = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    mutable failed: bool,
  };

  module Config = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      host: string,
      [@bs.optional]
      port: int,
      [@bs.optional]
      user: string,
      [@bs.optional]
      password: string,
      [@bs.optional]
      database: string,
    };
  };

  [@bs.module "mysql2"] external make: Config.t => t = "createConnection";
  [@bs.send] external close: t => unit = "end";
  [@bs.send]
  external on:
    (t, [@bs.string] [ | `error([@bs.this] ((t, Exn.t) => unit))]) => t;
};

module Options = {
  [@bs.deriving abstract]
  type t = {
    sql: string,
    values: Js.Nullable.t(Js.Json.t),
    namedPlaceholders: bool,
  };
};

module Response = {
  module Mutation = {
    [@bs.deriving {abstract: light}]
    type t = {
      [@bs.optional]
      insertId: ID.t,
      fieldCount: int,
      affectedRows: int,
      info: string,
      serverStatus: int,
      warningStatus: int,
    };
  };

  /* https://mariadb.com/kb/en/library/packet_resultset/ */
  /**
  * There will be a meta data packet for each column within the
  * response.
  * @TODO - determine the meaning of the characterSet field
  * @TODO - determine the meaning of the flags field.
  */
  module Meta = {
    [@bs.deriving {abstract: light}]
    type t = {
      catalog: string,
      schema: string,
      name: string,
      orgName: string,
      table: string,
      orgTable: string,
      characterSet: int,
      columnLength: int,
      columnType: int,
      flags: int,
      decimals: int,
    };
  };

  module Select = {
    [@bs.deriving {abstract: light}]
    type t = {
      rows: array(Js.Json.t),
      meta: array(Meta.t),
    };
  };
};

/**
 * Using this conversion here so we don't need to use the JSON decoding.
 * Since this will be used on every mutation query, we don't want the overhead
 * of JSON parsing. It's only unsafe if the MySQL library changes its output.
 * @TODO - figure out if there is a "fast" way to detect a change.
 */
external shadyMutationConversion: Js.Json.t => Response.Mutation.t =
  "%identity";

[@bs.send]
external execute:
  (
    Connection.t,
    Options.t,
    (Js.Nullable.t(Exn.t), Js.Json.t, array(Response.Meta.t)) => unit
  ) =>
  unit;

[@bs.send]
external query:
  (
    Connection.t,
    Options.t,
    (Js.Nullable.t(Exn.t), Js.Json.t, array(Response.Meta.t)) => unit
  ) =>
  unit;
