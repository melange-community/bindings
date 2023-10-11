module Labels = {
  type assertion<'a> = (~actual: 'a, ~expected: 'a, ~message: string=?) => unit

  @module("assert") external equal: assertion<'a> = "equal"
  @module("assert") external not_equal: assertion<'a> = "notEqual"

  @module("assert") external deep_equal: assertion<'a> = "deepEqual"
  @module("assert")
  external not_deep_equal: assertion<'a> = "notDeepEqual"

  @module("assert") external strict_equal: assertion<'a> = "strictEqual"
  @module("assert")
  external not_strict_equal: assertion<'a> = "notStrictEqual"

  @module("assert")
  external deep_strict_equal: assertion<'a> = "deepStrictEqual"
  @module("assert")
  external not_deep_strict_equal: assertion<'a> = "notDeepStrictEqual"

  @module("assert") external if_error: (~value: 'a) => unit = "ifError"

  @module("assert")
  external throws: (~block: 'a => 'b, ~error: Js.Exn.t, ~message: string=?) => unit = "throws"
  @module("assert")
  external does_not_throw: (~block: 'a => 'b, ~error: Js.Exn.t, ~message: string=?) => unit =
    "doesNotThrow"

  @module("assert") external ok: (~value: 'a) => unit = "ok"
  @module("assert") external fail: (~message: 'a) => unit = "fail"
  @module("assert")
  external fail': (
    ~actual: 'a,
    ~expected: 'a,
    ~message: string=?,
    ~operator: string=?,
    ~stack_start_fn: 'b => 'c=?,
  ) => unit = "fail"
}

let equal = (~message=?, actual, expected) => Labels.equal(~actual, ~expected, ~message?)
and not_equal = (~message=?, actual, expected) => Labels.not_equal(~actual, ~expected, ~message?)

let deep_equal = (~message=?, actual, expected) => Labels.deep_equal(~actual, ~expected, ~message?)
and not_deep_equal = (~message=?, actual, expected) =>
  Labels.not_deep_equal(~actual, ~expected, ~message?)

let deep_strict_equal = (~message=?, actual, expected) =>
  Labels.deep_strict_equal(~actual, ~expected, ~message?)
and not_deep_strict_equal = (~message=?, actual, expected) =>
  Labels.not_deep_strict_equal(~actual, ~expected, ~message?)

let strict_equal = (~message=?, actual, expected) =>
  Labels.strict_equal(~actual, ~expected, ~message?)
and not_strict_equal = (~message=?, actual, expected) =>
  Labels.not_strict_equal(~actual, ~expected, ~message?)

let if_error = value => Labels.if_error(~value)

let ok = value => Labels.ok(~value)
and fail = message => Labels.fail(~message)
and fail' = (~message=?, ~operator=?, ~stack_start_fn=?, actual, expected) =>
  Labels.fail'(~actual, ~expected, ~message?, ~operator?, ~stack_start_fn?)

let throws = (~message=?, block, error) => Labels.throws(~block, ~error, ~message?)
and does_not_throw = (~message=?, block, error) => Labels.does_not_throw(~block, ~error, ~message?)
