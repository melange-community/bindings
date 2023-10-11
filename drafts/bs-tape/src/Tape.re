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

[@bs.module "tape"]
external _test : (string, testFuncs => unit) => unit = "test";

[@bs.send] external _plan : (testFuncs, int) => unit = "plan";

[@bs.send] external _end : (testFuncs, bool) => unit = "end";

[@bs.send] external _fail : (testFuncs, string) => unit = "fail";

[@bs.send] external _pass : (testFuncs, string) => unit = "pass";

[@bs.send] external _timeoutAfter : (testFuncs, int) => unit = "timeoutAfter";

[@bs.send] external _skip : (testFuncs, string) => unit = "skip";

[@bs.send]
external _ok : (testFuncs, bool, Js.Nullable.t(string)) => unit = "ok";

[@bs.send]
external _notOk : (testFuncs, bool, Js.Nullable.t(string)) => unit = "notOk";

[@bs.send]
external _error : (testFuncs, error, Js.Nullable.t(string)) => unit = "error";

[@bs.send]
external _equalStr :
  (testFuncs, string, string, Js.Nullable.t(string)) => unit =
  "equal";

[@bs.send]
external _equalInt : (testFuncs, int, int, Js.Nullable.t(string)) => unit =
  "equal";

[@bs.send]
external _equalFloat :
  (testFuncs, float, float, Js.Nullable.t(string)) => unit =
  "equal";

[@bs.send]
external _notEqualStr :
  (testFuncs, string, string, Js.Nullable.t(string)) => unit =
  "notEqual";

[@bs.send]
external _notEqualInt : (testFuncs, int, int, Js.Nullable.t(string)) => unit =
  "notEqual";

[@bs.send]
external _notEqualFloat :
  (testFuncs, float, float, Js.Nullable.t(string)) => unit =
  "notEqual";

[@bs.send]
external _throws :
  (testFuncs, unit => unit, Js.Nullable.t(Js.Re.t), Js.Nullable.t(string)) =>
  unit =
  "throws";

[@bs.send]
external _doesNotThrow :
  (testFuncs, unit => unit, Js.Nullable.t(Js.Re.t), Js.Nullable.t(string)) =>
  unit =
  "doesNotThrow";

[@bs.send]
external _subtest : (testFuncs, string, testFuncs => unit) => unit = "test";

[@bs.send] external _comment : (testFuncs, string) => unit = "comment";

[@bs.module "tape"] [@bs.scope "test"]
external _testOnly : (string, testFuncs => unit) => unit = "only";

[@bs.module "tape"] [@bs.scope "test"]
external _testSkip : (string, testFuncs => unit) => unit = "skip";

let rec _assertFactory = t => {
  plan: n => _plan(t, n),
  endTest: () => _end(t, false),
  endTestIfNoErr: b => _end(t, b),
  fail: s => _fail(t, s),
  pass: s => _pass(t, s),
  timeoutAfter: n => _timeoutAfter(t, n),
  skip: s => _skip(t, s),
  ok: (~message=?, b) => _ok(t, b, Js.Nullable.fromOption(message)),
  notOk: (~message=?, b) => _notOk(t, b, Js.Nullable.fromOption(message)),
  error: (~message=?, o) => _error(t, o, Js.Nullable.fromOption(message)),
  equalStr: (~message=?, actual, expected) =>
    _equalStr(t, actual, expected, Js.Nullable.fromOption(message)),
  equalInt: (~message=?, actual, expected) =>
    _equalInt(t, actual, expected, Js.Nullable.fromOption(message)),
  equalFloat: (~message=?, actual, expected) =>
    _equalFloat(t, actual, expected, Js.Nullable.fromOption(message)),
  notEqualStr: (~message=?, actual, expected) =>
    _notEqualStr(t, actual, expected, Js.Nullable.fromOption(message)),
  notEqualInt: (~message=?, actual, expected) =>
    _notEqualInt(t, actual, expected, Js.Nullable.fromOption(message)),
  notEqualFloat: (~message=?, actual, expected) =>
    _notEqualFloat(t, actual, expected, Js.Nullable.fromOption(message)),
  throws: (~message=?, f) =>
    _throws(t, f, Js.Nullable.null, Js.Nullable.fromOption(message)),
  throwsAndMatches: (~message=?, f, expected) =>
    _throws(
      t,
      f,
      Js.Nullable.return(Js.Re.fromString(expected)),
      Js.Nullable.fromOption(message),
    ),
  doesNotThrow: (~message=?, f) =>
    _doesNotThrow(t, f, Js.Nullable.null, Js.Nullable.fromOption(message)),
  doesNotThrowAndMatch: (~message=?, f, expected) =>
    _doesNotThrow(
      t,
      f,
      Js.Nullable.return(Js.Re.fromString(expected)),
      Js.Nullable.fromOption(message),
    ),
  test: (name, f) => _subtest(t, name, t => f(_assertFactory(t))),
  comment: s => _comment(t, s),
};

let test = (name, f) => _test(name, t => f(_assertFactory(t)));

let testOnly = (name, f) => _testOnly(name, t => f(_assertFactory(t)));

let testSkip = (name, f) => _testSkip(name, t => f(_assertFactory(t)));