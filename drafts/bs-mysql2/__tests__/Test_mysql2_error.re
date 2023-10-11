open Jest;

let connect = () =>
  MySql2.Connection.connect(
    ~host="127.0.0.1",
    ~port=3306,
    ~user="root",
    ~password=ExampleEnv.getPassword(),
    (),
  );

describe("MySql2 Error Handling", () => {
  let conn = connect();

  afterAll(() => MySql2.Connection.close(conn));

  let accessDeniedTest = "Should respond with an access denied error";
  testAsync(
    accessDeniedTest,
    finish => {
      let c = MySql2.Connection.connect(~password="s0m3 g@rb@g3 pw", ());
      let sql = "SELECT 1+1 AS result";
      MySql2.execute(c, sql, None, res =>
        switch (res) {
        | `Select(_) => fail("unexpected_select_result") |> finish
        | `Mutation(_) => fail("unexpected_mutation_result") |> finish
        | `Error(e) =>
          Expect.expect(e |> MySql2.Exn.toExn)
          |> Expect.toMatchSnapshot
          |> finish
        }
      );
    },
  );

  let syntaxErrorTest = "Should respond with an error on invalid SQL syntax.";
  testAsync(
    syntaxErrorTest,
    finish => {
      let sql = "SELECT invalid, AS result";
      MySql2.execute(conn, sql, None, res =>
        switch (res) {
        | `Select(_) => fail("unexpected_select_result") |> finish
        | `Mutation(_) => fail("unexpected_mutation_result") |> finish
        | `Error(e) =>
          Expect.expect(e |> MySql2.Exn.toExn)
          |> Expect.toMatchSnapshot
          |> finish
        }
      );
    },
  );

  test("Should parse out an empty error with defaults", () => {
    /* Use raw JS here toe retrieve a garbage object */
    let e = [%raw {| (function () { return { message: "IDKWTM" } })() |}];
    let actual = MySql2.Exn.fromJs(e)->MySql2.Exn.toExn;

    Expect.expect(actual) |> Expect.toMatchSnapshot;
  });

  test("Should return a defaulted error", () => {
    /* Use raw JS here toe retrieve a garbage object */
    let e = [%raw {| (function () { return {} })()|}];
    let actual = MySql2.Exn.fromJs(e)->MySql2.Exn.toExn;

    Expect.expect(actual) |> Expect.toMatchSnapshot;
  });

  test("should give appropriate message when only a sqlState is given", () => {
    /* Use raw JS here toe retrieve a garbage object */
    let e = [%raw {| (function () { return { sqlState: "test" } })()|}];
    let actual = MySql2.Exn.fromJs(e)->MySql2.Exn.toExn;

    Expect.expect(actual) |> Expect.toMatchSnapshot;
  });

  test("should give appropriate message when only a sqlMessage is given", () => {
    /* Use raw JS here toe retrieve a garbage object */
    let e = [%raw {| (function () { return { sqlMessage: "test" } })()|}];
    let actual = MySql2.Exn.fromJs(e)->MySql2.Exn.toExn;

    Expect.expect(actual) |> Expect.toMatchSnapshot;
  });
});
