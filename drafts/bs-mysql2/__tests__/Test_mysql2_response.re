open Jest;

describe("MySql2_response", () =>
  describe("Select", () => {
    let test_meta =
      MySql2.Meta.t(
        ~catalog="catalog",
        ~schema="schema",
        ~name="name",
        ~orgName="orgName",
        ~table="table",
        ~orgTable="orgTable",
        ~characterSet=1,
        ~columnLength=2,
        ~columnType=3,
        ~flags=4,
        ~decimals=5,
      );

    describe("concat", () =>
      test("should combine the rows of two result sets", () => {
        let rows1 = [|Js.Json.string("foo"), Js.Json.string("bar")|];
        let rows2 = [|Js.Json.string("boo"), Js.Json.string("baz")|];

        let t1 = MySql2.Select.make(~rows=rows1, ~meta=[|test_meta|]);
        let t2 = MySql2.Select.make(~rows=rows2, ~meta=[|test_meta|]);

        MySql2.Select.concat(t1, t2)
        ->(
            MySql2.Select.flatMap(x =>
              x->Js.Json.decodeString->Belt.Option.getExn
            )
          )
        ->Expect.expect
        |> Expect.toEqual([|"foo", "bar", "boo", "baz"|]);
      })
    );

    describe("count", () =>
      test("count should return 0 when rows is empty", () =>
        MySql2.Select.make(~rows=[||], ~meta=[|test_meta|])
        ->MySql2.Select.count
        ->Expect.expect
        |> Expect.toBe(0)
      )
    );

    describe("rows", () =>
      test("rows should return the current set of rows", () => {
        let rows = [|Js.Json.string("foo"), Js.Json.string("bar")|];

        MySql2.Select.make(~rows, ~meta=[|test_meta|])
        ->MySql2.Select.rows
        ->(Belt.Array.map(x => x->Js.Json.decodeString->Belt.Option.getExn))
        ->Expect.expect
        |> Expect.toEqual([|"foo", "bar"|]);
      })
    );
  })
);
