module Connection = {
  include MySql2_binding.Connection;

  /**
   * For now we just consider all connection level errors to be irrecoverable,
   * therefore, we invalidate the connection on any error.
   */
  let errorHandler =
    [@bs.this]
    (
      (connection, error) => {
        Js.Console.error2("bs-mysql2 :: Connection :: FAILURE ::", error);
        connection->failedSet(true);
      }
    );

  let make = (~host=?, ~port=?, ~user=?, ~password=?, ~database=?, _) =>
    Config.t(~host?, ~port?, ~user?, ~password?, ~database?, ())
    ->make
    ->on(`error(errorHandler));

  let isValid = t => t->failedGet->Belt.Option.getWithDefault(true);

  // @deprecated
  let connect = make;
};

module Pool = MySql2_pool;

module Exn = {
  include MySql2_binding.Exn;

  let nameGet = t => t->nameGet->Belt.Option.getWithDefault("UNKNOWN");

  let codeGet = t => t->codeGet->Belt.Option.getWithDefault("99999");

  let errnoGet = t => t->errnoGet->Belt.Option.getWithDefault(99999);

  let msgGet = t => t->msgGet->Belt.Option.getWithDefault("EMPTY_MESSAGE");

  //let sqlGet = t => t->sqlGet->Belt.Option.getWithDefault("SQL_NOT_PRESENT");

  let toExn = t => {
    let name = t->nameGet;
    let code = t->codeGet;
    let errno = t->errnoGet;
    let msg = t->msgGet;
    let sqlState = t->sqlStateGet;
    let sqlMessage = t->sqlMessageGet;

    switch (sqlState, sqlMessage) {
    | (Some(state), Some(message)) =>
      Failure({j|$name - $code ($errno) - $msg - ($state) $message|j})
    | (Some(state), None) =>
      Failure({j|$name - $code ($errno) - $msg - ($state)|j})
    | (None, Some(message)) =>
      Failure({j|$name - $code ($errno) - $msg - $message|j})
    | (None, None) => Failure({j|$name - $code ($errno) - $msg|j})
    };
  };

  let invalidResponseType =
    t(
      ~name="InvalidResponseType",
      ~msg="invalid_driver_result",
      ~code="UNKNOWN_RESPONSE_TYPE",
      ~errno=99999,
      (),
    );
};

module ID = {
  include MySql2_binding.ID;

  let fromJson = json =>
    switch (json->Js.Json.classify) {
    | Js.Json.JSONNumber(float) => float->Js.Float.toString->Js.Json.string
    | Js.Json.JSONString(string) => string->Js.Json.string
    | _ => failwith("unexpected_identifier_value")
    };

  let toJson = fromJson;

  let toString = t =>
    switch (t->Js.Json.classify) {
    | Js.Json.JSONNumber(float) => float->Js.Float.toString
    | Js.Json.JSONString(string) => string
    | _ => failwith("unexpected_identifier_value")
    };

  let isZero = t => t->toString === "0";
};

// @deprecated
module Id = ID;

module Params = {
  type t = [ | `Named(Js.Json.t) | `Positional(Js.Json.t)];

  let named = json => `Named(json);

  let positional = json => `Positional(json);
};

module Meta = MySql2_binding.Response.Meta;

module Mutation = {
  include MySql2_binding.Response.Mutation;

  let insertId = t =>
    t->insertId->Belt.Option.flatMap(id => id->ID.isZero ? None : Some(id));
};

module Select = {
  include MySql2_binding.Response.Select;

  // @deprecated
  module Meta = Meta;

  let make = t;

  let flatMapWithMeta = (t, fn) =>
    Belt.Array.map(t->rows, row => fn(row, t->meta));

  let flatMap = (t, decoder) => Belt.Array.map(t->rows, decoder);

  let concat = (t1, t2) =>
    t(~rows=Belt.Array.concat(t1->rows, t2->rows), ~meta=t1->meta);

  let count = t => Belt.Array.length(t->rows);

  let rows = t => t->rows;
};

module Response = MySql2_binding.Response;

module Options = {
  include MySql2_binding.Options;

  let fromParams = (sql, params) =>
    switch (params) {
    | None => t(~sql, ~values=Js.Nullable.null, ~namedPlaceholders=false)
    | Some(`Named(json)) =>
      t(~sql, ~values=Js.Nullable.return(json), ~namedPlaceholders=true)
    | Some(`Positional(json)) =>
      t(~sql, ~values=Js.Nullable.return(json), ~namedPlaceholders=false)
    };
};

type response = [
  | `Error(Exn.t)
  | `Mutation(Mutation.t)
  | `Select(Select.t)
];

type callback = response => unit;

let handler = (callback, exn, res, meta) => {
  let response =
    switch (exn->Js.Nullable.toOption) {
    | Some(e) => `Error(e)
    | None =>
      switch (res->Js.Json.classify) {
      | Js.Json.JSONArray(rows) => `Select(Response.Select.t(~rows, ~meta))
      | Js.Json.JSONObject(_) =>
        `Mutation(res->MySql2_binding.shadyMutationConversion)
      | _ => `Error(Exn.invalidResponseType)
      }
    };

  callback(response);
};

let execute = (conn, sql, params, callback) => {
  let options = Options.fromParams(sql, params);

  options->Options.namedPlaceholdersGet
    ? MySql2_binding.execute(conn, options, handler(callback))
    : MySql2_binding.query(conn, options, handler(callback));
};
