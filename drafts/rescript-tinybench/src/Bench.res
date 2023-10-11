module Task = {
  type result = {
    error: option<{.}>,
    totalTime: float,
    min: float,
    max: float,
    hz: float,
    period: float,
    samples: array<float>,
    mean: float,
    variance: float,
    sd: float,
    sem: float,
    df: float,
    critical: float,
    moe: float,
    rme: float,
    p75: float,
    p99: float,
    p995: float,
    p999: float,
  }

  type t = {
    name: string,
    result: option<result>,
  }

  type fn = unit => unit

  @get
  external getFn: t => fn = "fn"

  type asyncFn = unit => Js.Promise2.t<unit>

  @get
  external getAsyncFn: t => asyncFn = "fn"
}

type t = {
  run: (. unit) => Js.Promise2.t<unit>,
  warmup: (. unit) => Js.Promise2.t<unit>,
  reset: (. unit) => unit,
  table: (. unit) => Js.Dict.t<string>,
  tasks: array<Task.t>,
  todos: array<Task.t>,
  results: array<option<Task.result>>,
}

type options

%%private(
  @obj
  external makeOptions: (
    ~time: option<float>=?,
    ~iterations: option<int>=?,
    ~now: option<unit => float>=?,
    ~warmupTime: option<float>=?,
    ~warmupIterations: option<int>=?,
    unit,
  ) => options = ""

  @new @module("tinybench")
  external make: options => t = "Bench"
)

let make = (~time=?, ~iterations=?, ~now=?, ~warmupTime=?, ~warmupIterations=?, ()) => {
  makeOptions(~time, ~iterations, ~now, ~warmupTime, ~warmupIterations, ())->make
}

@send
external add: (t, string, unit => unit) => t = "add"

@send
external addAsync: (t, string, unit => Js.Promise2.t<unit>) => t = "add"

@send
external todo: (t, string) => t = "todo"

@send
external remove: (t, string) => t = "remove"

@send
external run: t => Js.Promise.t<unit> = "run"

@send
external warmup: t => Js.Promise.t<unit> = "warmup"

@send
external reset: t => unit = "reset"

@send
external task: (t, string) => option<Task.t> = "task"

@get
external tasks: t => array<Task.t> = "tasks"

@get
external results: t => array<option<Task.result>> = "tasks"

@send
external table: t => Js.Dict.t<string> = "table"
