type error = Js.Nullable.t({. "message": string});

type testFuncs = {
  plan: int => unit,
  endTest: unit => unit,
  endTestIfNoErr: bool => unit,
  fail: string => unit,
  pass: string => unit,
  timeoutAfter: int => unit,
  skip: string => unit,
  ok: (~message: string=?, bool) => unit,
  notOk: (~message: string=?, bool) => unit,
  error: (~message: string=?, error) => unit,
  equalStr: (~message: string=?, string, string) => unit,
  equalInt: (~message: string=?, int, int) => unit,
  equalFloat: (~message: string=?, float, float) => unit,
  notEqualStr: (~message: string=?, string, string) => unit,
  notEqualInt: (~message: string=?, int, int) => unit,
  notEqualFloat: (~message: string=?, float, float) => unit,
  throws: (~message: string=?, unit => unit) => unit,
  throwsAndMatches: (~message: string=?, unit => unit, string) => unit,
  doesNotThrow: (~message: string=?, unit => unit) => unit,
  doesNotThrowAndMatch: (~message: string=?, unit => unit, string) => unit,
  test: (string, testFuncs => unit) => unit,
  comment: string => unit,
};

let test: (string, testFuncs => unit) => unit;

let testOnly: (string, testFuncs => unit) => unit;

let testSkip: (string, testFuncs => unit) => unit;