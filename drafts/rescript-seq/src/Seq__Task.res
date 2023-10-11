module R = Belt.Result
module RX = Seq__Result
module Promise = Js.Promise2

type t<'a> = unit => promise<'a>

external toExn: 'a => exn = "%identity"

let make = (~promise, ~onError, ()) =>
  promise()->Promise.catch(e => e->toExn->onError->Promise.resolve)

let map = (t, f, ()) => t()->Promise.then(r => f(r)->Promise.resolve)

let toPromise = t => t()

let forEach = (t, f) => t->map(f)

let spy = (t, effect, ()) =>
  t()->Promise.then(r => {
    effect(r)
    r->Promise.resolve
  })

module Result = {
  let make = (~promise, ~onError) =>
    make(
      ~promise=() => promise()->Promise.then(ok => Ok(ok)->Promise.resolve),
      ~onError=e => Error(onError(e)),
    )

  let mapError = (t, f) => t->map(RX.mapError(_, f))

  let mapOk = (t, f) => t->map(R.map(_, f))

  let flatMap = (t, f) => t->map(R.flatMap(_, f))

  let toOption = t => t->map(RX.toOption)
}
