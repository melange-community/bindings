open Ava

module P = Res_parser

type input = string
type remaining = string

let makeTests = (
  ~parser: P.t<'t>,
  ~makeName: (input, 'a) => string,
  ~specs: array<(input, 'a, remaining)>,
) => {
  specs->Belt.Array.map(((a, b, c)) => (parser, makeName(a, b), (a, b, c)))
}

let runTests = (~parser, ~makeName, ~specs) => {
  let tests = makeTests(~parser, ~makeName, ~specs)

  tests->Belt.Array.forEach(((parser, name, (input, expected, remaining))) => {
    test("[Success] " ++ name, t => {
      switch P.run(parser, input) {
      | Ok(output, state) => {
          t->true_(output == expected, ())
          t->true_(state->P.State.remaining == remaining, ())
        }
      | Error(err) => t->fail(~message=`Should not fail with "${err.message}"`, ())
      }
    })
  })
}

let runFailureTests = (~parser, ~makeName, ~specs) => {
  let tests = makeTests(
    ~parser,
    ~makeName=(a, _) => makeName(a),
    ~specs=specs->Belt.Array.map(x => (x, "", "")),
  )

  tests->Belt.Array.forEach(((parser, name, (input, _, _))) => {
    test("[Failure] " ++ name, t => {
      switch P.run(parser, input) {
      | Ok(_, state) =>
        t->fail(~message=`Should not succeed with "${state->P.State.remaining}" remaining`, ())
      | Error(err) => t->pass(~message=`Should fail with "${err.message}"`, ())
      }
    })
  })
}
