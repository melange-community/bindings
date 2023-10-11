open Jest;

let connect = () =>
  MySql2.Pool.make(
    ~connectionLimit=2,
    ~queueLimit=0,
    ~waitForConnections=true,
    ~host="127.0.0.1",
    ~port=3306,
    ~user="root",
    ~password=ExampleEnv.getPassword(),
    ~database="test",
    (),
  );

let select = (db, sql, params, cb) => {
  let returnError = e =>
    e->Js.Json.stringifyAny->Belt.Option.getExn->Belt.Result.Error->cb;

  let gotMutation = weird => {
    let result = weird->Js.Json.stringifyAny->Belt.Option.getExn;
    {j|Expected select, go mutation :: $result|j}->Belt.Result.Error->cb;
  };

  MySql2.execute(db, sql, params, response =>
    switch (response) {
    | `Error(e) => returnError(e)
    | `Mutation(weird) => gotMutation(weird)
    | `Select(result) => result->Belt.Result.Ok->cb
    }
  );
};

describe("MySql2.Pool", () => {
  let getDb = (poolRef, poolFn, callback) => {
    let pool = poolFn();

    poolRef := Some(pool);

    MySql2.Pool.getConnection(pool, (error, db) =>
      switch (
        error->Js.Null_undefined.toOption,
        db->Js.Null_undefined.toOption,
      ) {
      | (Some(e), _) =>
        failwith(
          e
          ->Js.Exn.message
          ->Belt.Option.getWithDefault("unknown_connection_exception"),
        )
      | (None, Some(db)) => callback(db)
      | (None, None) => failwith("Unknown connection error")
      }
    );
  };

  let getFirstRow = result =>
    switch (result->MySql2.Select.rows->Belt.Array.get(0)) {
    | Some(row) => Belt.Result.Ok(row)
    | None => Belt.Result.Error("No rows in result set")
    };

  let decodeRow = row =>
    switch (row->Js.Json.classify) {
    | Js.Json.JSONObject(dict) =>
      switch (dict->Js.Dict.get("result")) {
      | Some(result) =>
        switch (result->Js.Json.classify) {
        | Js.Json.JSONNumber(number) => Belt.Result.Ok(number)
        | Js.Json.JSONString(string) =>
          Belt.Result.Ok(string->float_of_string)
        | _ => Belt.Result.Error({j|Result wasn't a number: $result|j})
        }
      | None =>
        Belt.Result.Error({j|Could not find result key in row: $dict|j})
      }
    | _ => Belt.Result.Error({j|Could not decode row object: $row|j})
    };

  let drain = (poolRef, finish) =>
    switch (poolRef^) {
    | None => finish()
    | Some(pool) =>
      MySql2.Pool.drain(pool, error =>
        switch (error->Js.Null_undefined.toOption) {
        | None => finish()
        | Some(error) =>
          Js.Console.error2("Could not drain connection pool ::", error);
          finish();
        }
      )
    };

  describe("connect :: with params :: ", () => {
    let poolRef = ref(None);

    afterAllAsync(drain(poolRef));

    testAsync("should connect and allow a query", finish =>
      getDb(poolRef, connect, db =>
        select(db, "SELECT 1 + 1 AS result", None, response =>
          switch (
            response
            ->Belt.Result.flatMap(getFirstRow)
            ->Belt.Result.flatMap(decodeRow)
            ->Belt.Result.map(x => x |> Expect.expect |> Expect.toEqual(2.0))
          ) {
          | Belt.Result.Ok(assertion) => assertion->finish
          | Belt.Result.Error(message) => message->fail->finish
          }
        )
      )
    );
  });

  describe("valid connection", () => {
    let poolRef = ref(None);

    afterAllAsync(drain(poolRef));

    testAsync("getConnection should return a valid connection", finish =>
      getDb(poolRef, connect, db =>
        MySql2.Connection.isValid(db)
        |> Expect.expect
        |> Expect.toBe(true)
        |> finish
      )
    );
  });

  describe("events", () => {
    let makeTest = (label, installEventListener) =>
      testAsync(
        label,
        finish => {
          let pool = connect();
          let counter = ref(0);

          let exnToFail = (e, unknown) =>
            e->Js.Exn.message->Belt.Option.getWithDefault(unknown)->fail;

          installEventListener(pool, _ => counter := counter^ + 1)
          ->MySql2.Pool.getConnection((error, db) =>
              switch (
                error->Js.Null_undefined.toOption,
                db->Js.Null_undefined.toOption,
              ) {
              | (Some(e), _) =>
                e->exnToFail("unknown_connection_exception")->finish
              | (None, None) => fail("unknown_connection_error")->finish
              | (None, Some(db)) =>
                MySql2.Pool.release(db);
                MySql2.Pool.drain(pool, error =>
                  switch (error->Js.Null_undefined.toOption) {
                  | Some(e) => e->exnToFail("unknown_drain_failure")->finish
                  | None =>
                    Expect.expect(counter^) |> Expect.toEqual(1) |> finish
                  }
                );
              }
            );
        },
      );

    makeTest("should call acquire", (pool, increment) =>
      pool->MySql2.Pool.on(`acquire(increment))
    );

    makeTest("should call release", (pool, increment) =>
      pool->MySql2.Pool.on(`release(increment))
    );
  });
});
