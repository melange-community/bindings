module Expect = {
  type t('a);

  external expect: 'a => t('a) = "expect";

  [@mel.send] external toEqual: (t('a), 'a) => unit = "toEqual";
  [@mel.send] external toBe: (t('a), 'a) => unit = "toBe";
  [@mel.get] external not: t('a) => t('a) = "not";
  [@mel.send]
  external toMatchSnapshot: (t('a), unit) => unit = "toMatchSnapshot";

  [@mel.send] external toThrowSomething: t('a => 'b) => unit = "toThrow";

  [@mel.send] external toBeGreaterThan: (t('a), 'a) => unit = "toBeGreaterThan";
  [@mel.send] external toBeLessThan: (t('a), 'a) => unit = "toBeLessThan";
  [@mel.send]
  external toBeGreaterThanOrEqual: (t('a), 'a) => unit =
    "toBeGreaterThanOrEqual";
  [@mel.send]
  external toBeLessThanOrEqual: (t('a), 'a) => unit = "toBeLessThanOrEqual";

  [@mel.get]
  external rejects: t(Js.Promise.t('a)) => t(unit => 'a) = "rejects";

  [@mel.send] external toContain: (t(array('a)), 'a) => unit = "toContain";

  // This isn't a real string, but it can be used to construct a predicate on a string
  // expect("hello world")->toEqual(stringContaining("hello"));
  [@mel.scope "expect"]
  external stringContaining: string => string = "stringContaining";

  // This isn't a real array, but it can be used to construct a predicate on an array
  // expect([|"x", "y", "z"|])->toEqual(arrayContaining([|"x", "z"|]))
  [@mel.scope "expect"]
  external arrayContaining: array('a) => array('a) = "arrayContaining";
};

module Mock = {
  type undefined = Js.undefined(unit);

  let undefined: undefined = Js.Undefined.empty;

  type mock('a);

  type t('a) = mock('a);
  [@mel.scope "jest"] external fn: unit => 'a = "fn";
  [@mel.scope "jest"] external fnWithImplementation: 'a => 'a = "fn";
  [@mel.scope "jest"] external mockModule: string => unit = "mock";
  external getMock: 'a => t('a) = "%identity";
  [@mel.send]
  external mockReturnValue: (t('a), 'b) => undefined = "mockReturnValue";
  let mockReturnValue = (mock, value) => {
    let _ = mockReturnValue(mock, value);
    ();
  };
  [@mel.send]
  external mockImplementation: (t('a), 'a) => undefined = "mockImplementation";
  let mockImplementation = (mock, value) => {
    let _ = mockImplementation(mock, value);
    ();
  };
  [@mel.get] [@mel.scope "mock"]
  external calls: t('a) => array(array('b)) = "calls";
  [@mel.set] [@mel.scope "mock"]
  external clearCalls: (t('a), [@mel.as {json|[]|json}] _) => unit = "calls";

};

// Jest requires a function of *no arguments* to be passed into `describe`,
// hence the uncurried function.
external describeU: (string, (. unit) => unit) => unit = "describe";

let describe: (string, unit => unit) => unit =
  (name, f) => describeU(name, (.) => f());

// Tests have an optional timeout (third argument)

external testU: (string, (. unit) => unit, option(int)) => unit = "test";

let test: (~timeout: int=?, string, unit => unit) => unit =
  (~timeout=?, name, f) => testU(name, (.) => f(), timeout);

external testAsyncU:
  (string, (. unit) => Js.Promise.t(unit), option(int)) => unit =
  "test";

let testAsync: (~timeout: int=?, string, unit => Js.Promise.t(unit)) => unit =
  (~timeout=?, name, f) => testAsyncU(name, (.) => f(), timeout);

module Only = {
  [@mel.scope "describe"]
  external describeU: (string, (. unit) => unit) => unit = "only";

  let describe: (string, unit => unit) => unit =
    (name, f) => describeU(name, (.) => f());

  [@mel.scope "test"]
  external testU: (string, (. unit) => unit, option(int)) => unit = "only";

  let test: (~timeout: int=?, string, unit => unit) => unit =
    (~timeout=?, name, f) => testU(name, (.) => f(), timeout);

  [@mel.scope "test"]
  external testAsyncU:
    (string, (. unit) => Js.Promise.t(unit), option(int)) => unit =
    "only";

  let testAsync: (~timeout: int=?, string, unit => Js.Promise.t(unit)) => unit =
    (~timeout=?, name, f) => testAsyncU(name, (.) => f(), timeout);
};

module Skip = {
  [@mel.scope "describe"]
  external describeU: (string, (. unit) => unit) => unit = "skip";

  let describe: (string, unit => unit) => unit =
    (name, f) => describeU(name, (.) => f());

  [@mel.scope "test"]
  external testU: (string, (. unit) => unit, option(int)) => unit = "skip";

  let test: (~timeout: int=?, string, unit => unit) => unit =
    (~timeout=?, name, f) => testU(name, (.) => f(), timeout);

  [@mel.scope "test"]
  external testAsyncU:
    (string, (. unit) => Js.Promise.t(unit), option(int)) => unit =
    "skip";

  let testAsync: (~timeout: int=?, string, unit => Js.Promise.t(unit)) => unit =
    (~timeout=?, name, f) => testAsyncU(name, (.) => f(), timeout);
};

external beforeAllU: ((. unit) => unit) => unit = "beforeAll";

let beforeAll: (unit => unit) => unit = f => beforeAllU((.) => f());

external beforeEachU: ((. unit) => unit) => unit = "beforeEach";

let beforeEach: (unit => unit) => unit = f => beforeEachU((.) => f());

external afterAllU: ((. unit) => unit) => unit = "afterAll";

let afterAll: (unit => unit) => unit = f => afterAllU((.) => f());

external afterEachU: ((. unit) => unit) => unit = "afterEach";

let afterEach: (unit => unit) => unit = f => afterEachU((.) => f());

external beforeAllAsyncU: ((. unit) => Js.Promise.t(unit)) => unit =
  "beforeAll";
let beforeAllAsync: (unit => Js.Promise.t(unit)) => unit =
  f => beforeAllAsyncU((.) => f());

external beforeEachAsyncU: ((. unit) => Js.Promise.t(unit)) => unit =
  "beforeEach";
let beforeEachAsync: (unit => Js.Promise.t(unit)) => unit =
  f => beforeEachAsyncU((.) => f());

external afterAllAsyncU: ((. unit) => Js.Promise.t(unit)) => unit =
  "afterAll";
let afterAllAsync: (unit => Js.Promise.t(unit)) => unit =
  f => afterAllAsyncU((.) => f());

external afterEachAsyncU: ((. unit) => Js.Promise.t(unit)) => unit =
  "afterEach";
let afterEachAsync: (unit => Js.Promise.t(unit)) => unit =
  f => afterEachAsyncU((.) => f());
