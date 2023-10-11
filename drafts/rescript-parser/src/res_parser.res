module Position = {
  type t = {
    prevLines: list<(int, int)>,
    index: int,
    lineStart: int,
    line: int,
    col: int,
  }

  let make = () => {
    prevLines: list{},
    index: 0,
    lineStart: 0,
    line: 1,
    col: 1,
  }

  let newline = t => {
    prevLines: list{(t.lineStart, t.index), ...t.prevLines},
    index: t.index + 1,
    lineStart: t.index + 1,
    line: t.line + 1,
    col: 1,
  }

  let next = t => {
    ...t,
    col: t.col + 1,
    index: t.index + 1,
  }
}

module State = {
  type t = {
    position: Position.t,
    input: string,
  }

  let getChar = t => {
    try String.get(t.input, t.position.index)->Some catch {
    | _ => None
    }
  }

  let next = t => {
    switch t->getChar {
    | Some('\n' | '\r') => {
        ...t,
        position: t.position->Position.newline,
      }
    | Some(_) => {
        ...t,
        position: t.position->Position.next,
      }
    | None => t
    }
  }

  let getPosition = t => t.position

  let fromString = input => {
    position: Position.make(),
    input: input,
  }

  let remaining = t => {
    Js.String.sliceToEnd(t.input, ~from=t.position.index)
  }

  let makeFrames = state => {
    let {input, position} = state
    let line = position.line

    let prevLines = {
      let {prevLines} = position
      let size = Js.Math.min_int(4, prevLines->Belt.List.size)
      let lines = Belt.List.take(prevLines, size)

      lines
      ->Belt.Option.getWithDefault(list{})
      ->Belt.List.mapWithIndex((index, (from, to_)) => {
        let lineNumber = line - index - 1

        (lineNumber, Js.String.slice(input, ~from, ~to_))
      })
    }

    prevLines
  }
}

module Error = {
  type t = {message: string, state: State.t}

  let fromInput = (state, message) => {
    state: state,
    message: message,
  }
}

type state = State.t
type error = Error.t
type parseResult<'a> = result<('a, state), error>
type t<'a> = Parser(state => parseResult<'a>)

type run<'a> = (t<'a>, string) => parseResult<'a>
type bind<'a, 'b> = (t<'a>, 'a => t<'b>) => t<'b>
type return<'a> = 'a => t<'a>
type map<'a, 'b> = (t<'a>, 'a => 'b) => t<'b>
type andThen<'a, 'b> = (t<'a>, t<'b>) => t<('a, 'b)>
type orElse<'a> = (t<'a>, t<'a>) => t<'a>
type satisfy = (char => bool) => t<char>
type char_ = char => t<char>
type choice<'a> = array<t<'a>> => t<'a>
type anyOf = array<char> => t<char>
type apply<'a, 'b> = (t<'a>, t<'a => 'b>) => t<'b>
type lift2<'a, 'b, 'c> = (t<'a>, ('a, 'b) => 'c, t<'b>) => t<'c>
type sequence<'a> = list<t<'a>> => t<list<'a>>
type zeroOrMore<'a> = (t<'a>, state) => (list<'a>, state)
type many<'a> = t<'a> => t<list<'a>>
type atLeastOne<'a> = t<'a> => t<list<'a>>
type keepLeft<'a, 'b> = (t<'a>, t<'b>) => t<'a>
type keepRight<'a, 'b> = (t<'a>, t<'b>) => t<'b>
type between<'a, 'b, 'c> = (t<'a>, t<'b>, t<'c>) => t<'a>
type separatedBy<'a, 'b> = (t<'a>, t<'b>) => t<list<'a>>
type separatedBy1<'a, 'b> = (t<'a>, t<'b>) => t<list<'a>>

type makeRecursive<'a> = (t<'a> => t<'a>) => t<'a>
type makeForwardRef<'a> = unit => (t<'a>, ref<t<'a>>)

let runOnInput = (t, input) => {
  let Parser(run) = t

  run(input)
}

let run: run<'a> = (t, inputString) => {
  runOnInput(t, State.fromString(inputString))
}

let bind: bind<'a, 'b> = (t, fn) => Parser(
  input =>
    switch runOnInput(t, input) {
    | Error(msg) => Error(msg)
    | Ok((value, remaining)) => value->fn->runOnInput(remaining)
    },
)

let return: return<'a> = x => Parser(input => Ok((x, input)))
let map: map<'a, 'b> = (t, fn) => t->bind(x => x->fn->return)
let andThen: andThen<'a, 'b> = (p1, p2) => p1->bind(res1 => p2->bind(res2 => return((res1, res2))))

let satisfy: satisfy = predicate => Parser(
  input => {
    let char = State.getChar(input)

    switch char {
    | None => Error({message: "No more input", state: input})
    | Some(char) if predicate(char) => Ok((char, State.next(input)))
    | Some(char) =>
      Error({
        message: `Unexpected "` ++ Char.escaped(char) ++ `".\n`,
        state: input,
      })
    }
  },
)

let char: char_ = expected => satisfy(Char.equal(expected))
let orElse: orElse<'a> = (parser1, parser2) => Parser(
  input => {
    let result = runOnInput(parser1, input)

    switch result {
    | Ok(_) => result
    | Error(_) => runOnInput(parser2, input)
    }
  },
)

let choice: choice<'a> = parsers =>
  parsers->Belt.Array.reduce(
    Parser(input => Error({message: "Initial parser", state: input})),
    orElse,
  )

let anyOf: anyOf = chars => chars->Belt.Array.map(char)->choice

let apply: apply<'a, 'b> = (parserA, parserB) =>
  parserB->bind(f => parserA->bind(x => return(f(x))))

let lift2: lift2<'a, 'b, 'c> = (parserA, fn, parserB) => apply(parserB, apply(parserA, return(fn)))

let rec sequence: sequence<'a> = (parsers: list<t<'a>>) =>
  switch parsers {
  | list{} => return(list{})
  | list{head, ...tail} => lift2(head, List.cons, sequence(tail))
  }

let rec zeroOrMore: zeroOrMore<'a> = (parser, input) =>
  switch runOnInput(parser, input) {
  | Error(_) => (list{}, input)
  | Ok((first, input)) =>
    let (values, input) = zeroOrMore(parser, input)

    (list{first, ...values}, input)
  }

let many: many<'a> = parser => Parser(input => Ok(zeroOrMore(parser, input)))

let atLeastOne: atLeastOne<'a> = parser =>
  parser->bind(head => many(parser)->bind(tail => return(list{head, ...tail})))

let keepLeft: keepLeft<'a, 'b> = (parserA, parserB) => parserA->andThen(parserB)->map(fst)

let keepRight: keepRight<'a, 'b> = (parserA, parserB) => parserA->andThen(parserB)->map(snd)

let between: between<'a, 'b, 'c> = (parserA, parserB, parserC) => {
  // Keeps parserA
  parserB->keepRight(parserA)->keepLeft(parserC)
}

let separatedBy1: separatedBy1<'a, 'b> = (parser, separator) => {
  let separators = keepRight(separator, parser)

  parser->andThen(many(separators))->map(((head, tail)) => list{head, ...tail})
}

let separatedBy: separatedBy<'a, 'b> = (parser, separator) => {
  parser->separatedBy1(separator)->orElse(return(list{}))
}

let string = x => {
  x
  ->Js.String2.split("")
  ->Belt.Array.map(String.get(_, 0))
  ->Belt.Array.map(char)
  ->Belt.List.fromArray
  ->sequence
  ->map(Belt.List.map(_, Char.escaped))
  ->map(Belt.List.toArray)
  ->map(Js.Array.joinWith(""))
}

let makeForwardRef: makeForwardRef<'t> = () => {
  let parser = Parser(_ => failwith("Not implemented"))
  let parserRef = ref(parser)

  (Parser(input => runOnInput(parserRef.contents, input)), parserRef)
}

let makeRecursive: makeRecursive<'t> = fn => {
  let (parser, parserRef) = makeForwardRef()

  parserRef := fn(parser)

  parserRef.contents
}

let optional = parser => {
  let some = parser->map(x => Some(x))
  let none = return(None)

  some->orElse(none)
}
