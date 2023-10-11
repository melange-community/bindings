open Ava

module P = Res_parser

test("Error position", t => {
  let parser = P.string("hello world")

  switch P.run(parser, "hel1o world") {
  | Ok(_) => t->fail()
  | Error(error) => {
      let {position} = error.state
      t->is(position.col, 4, ())
      t->is(position.index, 3, ())
      t->is(position.lineStart, 0, ())
      t->is(position.line, 1, ())
      t->true_(position.prevLines == list{}, ())
    }
  }

  let parser = P.char('a')->P.keepLeft(P.many(P.anyOf([' ', '\n'])))->P.andThen(P.char('b'))

  switch P.run(
    parser,
    `a
c`,
  ) {
  | Ok(_) => t->fail()
  | Error(error) => {
      let {position} = error.state

      t->is(position.col, 1, ())
      t->is(position.index, 2, ())
      t->is(position.lineStart, 2, ())
      t->is(position.line, 2, ())
      t->true_(position.prevLines == list{(0, 1)}, ())
    }
  }
})
