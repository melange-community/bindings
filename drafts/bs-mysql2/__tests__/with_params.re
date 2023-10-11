open Jest;

let connect = () =>
  MySql2.Connection.connect(
    ~host="127.0.0.1",
    ~port=3306,
    ~user="root",
    ~password=ExampleEnv.getPassword(),
    ~database="test",
    (),
  );

type result = {result: int};

module Decoder = {
  [@bs.deriving abstract]
  type t = {result: int};

  external decode: 'a => t = "%identity";
};

describe("Test parameter interpolation", () => {
  let conn = connect();
  let decoder = Decoder.decode;

  afterAll(() => MySql2.Connection.close(conn));

  describe("Standard (positional) parameters", () =>
    testAsync("Expect parameters to be substituted properly", finish => {
      let sql = "SELECT 1 + ? + ? AS result";
      let params =
        Some(
          MySql2.Params.positional(
            Belt_Array.map([|5, 6|], float_of_int) |> Js.Json.numberArray,
          ),
        );
      MySql2.execute(conn, sql, params, res =>
        switch (res) {
        | `Error(e) => raise(e |> MySql2.Exn.toExn)
        | `Mutation(_) => fail("unexpected_mutation_result") |> finish
        | `Select(select) =>
          select->(MySql2.Select.flatMapWithMeta((row, _) => row->decoder))
          |> Belt_Array.map(_, x => x->Decoder.resultGet)
          |> Expect.expect
          |> Expect.toBeSupersetOf([|12|])
          |> finish
        }
      );
    })
  );
  describe("Named parameters", () =>
    testAsync("Expect parameters to be substituted properly", finish => {
      let sql = "SELECT :x + :y AS result";

      let obj = Js.Dict.empty();
      obj->Js.Dict.set("x", float_of_int(1)->Js.Json.number);
      obj->Js.Dict.set("y", float_of_int(2)->Js.Json.number);

      let params = Some(obj->Js.Json.object_->MySql2.Params.named);

      MySql2.execute(conn, sql, params, res =>
        switch (res) {
        | `Error(e) => raise(e |> MySql2.Exn.toExn)
        | `Mutation(_) => fail("unexpected_mutation_result") |> finish
        | `Select(select) =>
          select->(MySql2.Select.flatMap(decoder))
          |> Belt_Array.map(_, x => x->Decoder.resultGet)
          |> Expect.expect
          |> Expect.toBeSupersetOf([|3|])
          |> finish
        }
      );
    })
  );
});
