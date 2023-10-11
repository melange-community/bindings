open Jest;

let connect = () =>
  MySql2.Connection.connect(
    ~host="127.0.0.1",
    ~port=3306,
    ~user="root",
    ~database="test",
    ~password=ExampleEnv.getPassword(),
    (),
  );

let table_sql = {|
  CREATE TABLE IF NOT EXISTS `test`.`mysql2` (
    `id` bigint(20) NOT NULL AUTO_INCREMENT
  , `code` varchar(32) NOT NULL
  , `display` varchar(140) DEFAULT NULL
  , PRIMARY KEY(`id`)
  )
|};

let seed_sql = {|
  INSERT IGNORE INTO `test`.`mysql2`
  (`id`, `code`, `display`)
  VALUES
  (1, "batman", "I am, Bat-man"),
  (2, "superman", "Truth, Justice and the American Way"),
  (3, "wonder_woman", "Suffering Sappho!")
|};

let mutationPromise = (db, sql, params) =>
  Js.Promise.make((~resolve, ~reject) =>
    MySql2.execute(
      db,
      sql,
      params,
      fun
      | `Error(e) => reject(. e |> MySql2.Exn.toExn)
      | `Select(_) => reject(. "unexpected_select_result"->Failure)
      | `Mutation(m) => resolve(. m),
    )
    ->ignore
  );

let selectPromise = (db, sql, params) =>
  Js.Promise.make((~resolve, ~reject) =>
    MySql2.execute(
      db,
      sql,
      params,
      fun
      | `Error(e) => reject(. e |> MySql2.Exn.toExn)
      | `Mutation(_) => reject(. "unexpected_mutation_result"->Failure)
      | `Select(select) => resolve(. select),
    )
    ->ignore
  );

describe("MySql2", () => {
  let db = ref(None);

  let getDb = () => (db^)->Belt.Option.getExn;

  beforeAllPromise(() => {
    db := connect()->Some;

    mutationPromise(getDb(), "DROP TABLE IF EXISTS `test`.`mysql2`", None)
    |> Js.Promise.then_(_ => mutationPromise(getDb(), table_sql, None))
    |> Js.Promise.then_(_ => mutationPromise(getDb(), seed_sql, None));
  });

  afterAll(() => getDb()->MySql2.Connection.close);

  describe("Mutation", () => {
    let result = ref(None);

    let getResult = () => (result^)->Belt.Option.getExn;

    beforeAllPromise(() => {
      let sql = {|
        INSERT INTO `test`.`mysql2`
        (`id`, `code`, `display`)
        VALUES
        (4, "flash", "I am the fastest man alive")
      |};

      mutationPromise(getDb(), sql, None)
      |> Js.Promise.then_(mutation => {
           result := Some(mutation);
           Js.Promise.resolve(mutation);
         });
    });

    let makeTest = (label, fn, expected) =>
      test(label, () =>
        getResult()->fn->Expect.expect |> Expect.toBe(expected)
      );

    describe("fieldCount", () =>
      makeTest("should return zero", MySql2.Mutation.fieldCount, 0)
    );

    describe("info", () =>
      makeTest("should return empty string", MySql2.Mutation.info, "")
    );

    describe("serverStatus", () =>
      makeTest("should return 2", MySql2.Mutation.serverStatus, 2)
    );

    describe("warningStatus", () =>
      makeTest("should return 0", MySql2.Mutation.warningStatus, 0)
    );
  });

  describe("Select", () => {
    let result = ref(None);

    let getResult = () => (result^)->Belt.Option.getExn;

    beforeAllPromise(() =>
      selectPromise(getDb(), "SELECT * FROM `test`.`mysql2`", None)
      |> Js.Promise.then_(select => {
           result := Some(select);
           Js.Promise.resolve(select);
         })
    );

    let makeMetaTest = (label, fn, expected) =>
      test(label, () =>
        getResult()->MySql2.Select.meta->(Belt.Array.map(fn))->Expect.expect
        |> Expect.toEqual(expected)
      );

    describe("catalog", () =>
      makeMetaTest(
        "should return the string 'def'",
        MySql2.Select.Meta.catalog,
        [|"def", "def", "def"|],
      )
    );

    describe("schema", () =>
      makeMetaTest(
        "should return the string 'test'",
        MySql2.Select.Meta.schema,
        [|"test", "test", "test"|],
      )
    );

    describe("name", () =>
      makeMetaTest(
        "should return the column name string",
        MySql2.Select.Meta.name,
        [|"id", "code", "display"|],
      )
    );

    describe("orgName", () =>
      makeMetaTest(
        "should return the schema defined column name string",
        MySql2.Select.Meta.orgName,
        [|"id", "code", "display"|],
      )
    );

    describe("table", () =>
      makeMetaTest(
        "should return the table name string",
        MySql2.Select.Meta.table,
        [|"mysql2", "mysql2", "mysql2"|],
      )
    );

    describe("orgTable", () =>
      makeMetaTest(
        "should return the schema defined table name string",
        MySql2.Select.Meta.orgTable,
        [|"mysql2", "mysql2", "mysql2"|],
      )
    );

    describe("characterSet", () =>
      makeMetaTest(
        "should return the column character sets",
        MySql2.Select.Meta.characterSet,
        [|63, 224, 224|],
      )
    );

    describe("columnLength", () =>
      makeMetaTest(
        "should return the length of each column",
        MySql2.Select.Meta.columnLength,
        [|20, 128, 560|],
      )
    );

    describe("columnType", () =>
      makeMetaTest(
        "should return the internal type code of each column",
        MySql2.Select.Meta.columnType,
        [|8, 253, 253|],
      )
    );

    describe("flags", () =>
      makeMetaTest(
        "should return the flag set for each column",
        MySql2.Select.Meta.flags,
        [|16899, 4097, 0|],
      )
    );

    describe("decimals", () =>
      makeMetaTest(
        "should return the decimal count of each column",
        MySql2.Select.Meta.decimals,
        [|0, 0, 0|],
      )
    );
  });
});
