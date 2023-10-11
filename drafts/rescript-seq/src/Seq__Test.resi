type t

let fromResult: (
  ~category: string,
  ~title: string,
  ~expectation: string=?,
  unit => result<unit, string>,
) => t

let fromPredicate: (~category: string, ~title: string, ~expectation: string=?, unit => bool) => t

let expectThrow: (~category: string, ~title: string, ~expectation: string=?, unit => 'a) => t

let expectNotThrow: (~category: string, ~title: string, ~expectation: string=?, unit => 'a) => t

let fromPredicateAsync: (
  ~category: string,
  ~title: string,
  ~expectation: string=?,
  unit => promise<bool>,
) => t

let fromResultAsync: (
  ~category: string,
  ~title: string,
  ~expectation: string=?,
  unit => promise<result<unit, string>>,
) => t

let category: t => string
let title: t => string
let expectation: t => option<string>
let hasKeyword: (t, string) => bool

type summary = {
  pass: int,
  fail: int,
  ran: int,
}

let runSuite: (~filter: t => bool=?, ~onlyShowFailures: bool=?, array<t>) => promise<summary>
