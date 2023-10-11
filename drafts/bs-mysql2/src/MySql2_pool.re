type t;

/* Alias for internal use only */
type pool = t;

module Connection = MySql2_binding.Connection;

[@bs.send]
external on:
  (
    pool,
    [@bs.string] [
      | `acquire(Connection.t => unit)
      | `enqueue(unit => unit)
      | `release(Connection.t => unit)
    ]
  ) =>
  pool =
  "";

/**
 * ## Connection Pool Options
 * This is a union of the database [connection options][connection-options]
 * and options specifically targeted for the pool.
 *
 * [connection-options]: https://github.com/mysqljs/mysql#connection-options
*/
module Options = {
  [@bs.deriving abstract]
  type t = {
    /* Connection Pool Options */
    [@bs.optional]
    connectionLimit: int,
    [@bs.optional]
    queueLimit: int,
    [@bs.optional]
    waitForConnections: bool,
    /* Connection Options */
    [@bs.optional]
    charset: string,
    [@bs.optional]
    connectTimeout: int,
    [@bs.optional]
    database: string,
    [@bs.optional]
    host: string,
    [@bs.optional]
    port: int,
    [@bs.optional]
    timezome: string,
    /* Connection Authentication */
    [@bs.optional]
    password: string,
    [@bs.optional]
    user: string,
    /* Data Type Handling */
    [@bs.optional] [@bs.as "supportBigNumbers"]
    bigNumberSupport: bool,
    [@bs.optional]
    bigNumberStrings: bool,
    [@bs.optional]
    dateStrings: bool,
    [@bs.optional]
    stringifyObjects: bool,
    [@bs.optional]
    typeCast: bool,
    /* Debugging */
    [@bs.optional]
    debug: bool,
    [@bs.optional]
    trace: bool,
  };
};

[@bs.module "mysql2"] external createPool: Options.t => pool = "";

[@bs.send]
external drain: (pool, Js.Null_undefined.t(Js.Exn.t) => unit) => unit = "end";

[@bs.send]
external getConnection:
  (
    pool,
    (Js.Null_undefined.t(Js.Exn.t), Js.Null_undefined.t(Connection.t)) =>
    unit
  ) =>
  unit =
  "";

[@bs.send] external release: Connection.t => unit = "";

let make =
    (
      ~connectionLimit=?,
      ~queueLimit=?,
      ~waitForConnections=?,
      ~host=?,
      ~port=?,
      ~user=?,
      ~password=?,
      ~database=?,
      _,
    ) => {
  let config =
    Options.t(
      ~connectionLimit?,
      ~queueLimit?,
      ~waitForConnections?,
      ~host?,
      ~port?,
      ~user?,
      ~password?,
      ~database?,
      /* Setting this by default to eliminate type confusion. */
      ~bigNumberSupport=true,
      ~bigNumberStrings=true,
      (),
    );
  createPool(config);
};
