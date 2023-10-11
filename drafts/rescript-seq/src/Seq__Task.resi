@genType.ignoreInterface
/**
A `Task.t` is a lazy promise that never fails. You can transform the task before
execution using various functions like `map`, `forEach`, `mapOk`, and
`toOption`. When you're read to execute the promise, call the `toPromise`
function.
*/
type t<'a> = unit => promise<'a>
let make: (~promise: unit => promise<'a>, ~onError: exn => 'a) => t<'a>
let map: (t<'a>, 'a => 'b) => t<'b>
let toPromise: t<'a> => promise<'a>
let forEach: (t<'a>, 'a => unit) => t<unit>
let spy: (t<'a>, 'a => unit) => t<'a>

/**
The `Result` module contains functions that operate on a `Task.t` where the
promise returns a `Result`. These are convenience functions like `mapError` and
`mapOk`. You can accomplish the same thing by calling `Task.map`.
*/
module Result: {
  let make: (~promise: unit => promise<'a>, ~onError: exn => 'b) => t<result<'a, 'b>>
  let mapError: (t<result<'a, 'errA>>, 'errA => 'errB) => t<result<'a, 'errB>>
  let mapOk: (t<result<'a, 'err>>, 'a => 'b) => t<result<'b, 'err>>
  let flatMap: (t<result<'a, 'err>>, 'a => result<'b, 'err>) => t<result<'b, 'err>>
  let toOption: t<result<'a, 'err>> => t<option<'a>>
}
