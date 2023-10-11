open Ava

module P = Res_parser

let run = P.run(Json.parse)

let {map, forEach} = module(Belt.Array)

let readFiles = dirname => {
  Node.Fs.readdirSync("test/json/inputs/" ++ dirname)
  ->map(name => (name, "test/json/inputs/" ++ dirname ++ "/" ++ name))
  ->map(((filename, pathname)) => (filename, Node.Fs.readFileAsUtf8Sync(pathname)))
}

let passes = readFiles("passes")
let failures = readFiles("failures")
let partials = readFiles("partials")

passes->forEach(((name, file)) => {
  test(`[JSON] File "${name}" success`, t => {
    switch run(file) {
    | Ok(_, state) => t->true_(state->P.State.remaining == "", ())
    | Error(err) => t->fail(~message=`Should not fail with "${err.message}"`, ())
    }
  })
})

partials->forEach(((name, file)) => {
  test(`[JSON] File "${name}" partial success`, t => {
    switch run(file) {
    | Ok(_, state) =>
      t->true_(
        state->P.State.remaining != "",
        ~message=`Should partially succeed with "${state->P.State.remaining}" remaining`,
        (),
      )
    | Error(err) => t->fail(~message=`Should not fail with "${err.message}"`, ())
    }
  })
})

failures->forEach(((name, file)) => {
  test(`[JSON] File "${name}" failure`, t => {
    switch run(file) {
    | Ok(ast, state) =>
      t->fail(
        ~message=`Shouldn't succeed with "${ast->Json.toString}" and "${state->P.State.remaining}" remaining`,
        (),
      )
    | Error(err) => t->pass(~message=`Should fail with "${err.message}"`, ())
    }
  })
})
