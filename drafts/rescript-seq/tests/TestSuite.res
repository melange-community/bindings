open Belt
module Test = Seq__Test
module Task = Seq__Task
module Q = Seq
module Promise = Js.Promise2

let isLocalDevelopment = () => {
  try {
    let isLocal: bool = %raw(`process.env.NODE_ENV === "development"`)
    isLocal
  } catch {
  | _ => false
  }
}

let onlyShowFailures = false
let filter = test => []->Js.Array2.every(word => test->Test.hasKeyword(word))
let throwOnFailure = !isLocalDevelopment()

let tests =
  [
    Seq__OptionTests.tests,
    Seq__ResultTests.allTests,
    Seq__TaskTest.tests,
    Seq__SeqTests.tests,
  ]->Array.concatMany

Task.Result.make(~promise=() => Test.runSuite(tests, ~filter, ~onlyShowFailures), ~onError=e => e)
->Task.forEach(s =>
  switch (s, throwOnFailure) {
  | (Ok(s), true) if s.fail > 0 => Js.Exn.raiseError(`Tests failed: ${s.fail->Int.toString}`)
  | (Error(_), true) => Js.Exn.raiseError("Could not complete the test suite.")
  | _ => ()
  }
)
->Task.toPromise
->ignore
