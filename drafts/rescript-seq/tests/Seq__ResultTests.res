open Belt

module T = Seq__Test
module R = Seq__Result

let expectEqual = (~title, ~expectation, ~a, ~b) =>
  T.fromPredicate(~category="Result", ~title, ~expectation, () => a() == b)

let mapError =
  [
    ("when Error, map the error", Error(3), Error(6)),
    ("when Ok, return Ok", Ok("a"), Ok("a")),
  ]->Array.map(((expectation, input, expected)) =>
    expectEqual(
      ~title="mapError",
      ~expectation,
      ~a=() => input->R.mapError(i => i * 2),
      ~b=expected,
    )
  )

let fromTryCatch = [
  T.fromPredicate(
    ~category="Result",
    ~title="fromTryCatch",
    ~expectation="when throw, return as Error",
    () => {
      let r = R.fromTryCatch(() => Js.Exn.raiseError("banana"))
      switch r {
      | Ok(_) => false
      | Error(e) =>
        switch e->Js.Exn.asJsExn {
        | Some(err) => err->Js.Exn.message == Some("banana")
        | _ => false
        }
      }
    },
  ),
  T.fromPredicate(
    ~category="Result",
    ~title="fromTryCatch",
    ~expectation="when not throw, return result as Ok",
    () => R.fromTryCatch(() => 3) == Ok(3),
  ),
]

let toOption = [
  expectEqual(
    ~title="toOption",
    ~expectation="when Ok, return Some",
    ~a=() => Ok(4)->R.toOption,
    ~b=Some(4),
  ),
  expectEqual(
    ~title="toOption",
    ~expectation="when Error, return None",
    ~a=() => Error(4)->R.toOption,
    ~b=None,
  ),
]

let allTests = [toOption, fromTryCatch, mapError]->Array.concatMany
