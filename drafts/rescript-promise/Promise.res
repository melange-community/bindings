type t<+'a> = Js.Promise.t<'a>

let isPromiseLike = obj =>
  Js.typeof(obj) === "object" &&
  obj->Obj.magic !== Js.Null.empty &&
  Js.typeof((obj->Obj.magic)["then"]) === "function"

@new external makeJsError: string => Js.Exn.t = "Error"
@scope("Promise") @val external reject: Js.Exn.t => t<'a> = "reject"

@scope("Promise") @val external resolve: 'a => t<'a> = "resolve"
let resolve = x => {
  if isPromiseLike(x) {
    reject(
      makeJsError(
        "Cannot create a Promise containing another Promise as this will break ReScript static types",
      ),
    )
  } else {
    resolve(x)
  }
}

@scope("Promise") @val external all: array<t<'a>> => t<array<'a>> = "all"
@scope("Promise") @val external all2: ((t<'a>, t<'b>)) => t<('a, 'b)> = "all"
@scope("Promise") @val external all3: ((t<'a>, t<'b>, t<'c>)) => t<('a, 'b, 'c)> = "all"
@scope("Promise") @val external all4: ((t<'a>, t<'b>, t<'c>, t<'d>)) => t<('a, 'b, 'c, 'd)> = "all"
@scope("Promise") @val
external all5: ((t<'a>, t<'b>, t<'c>, t<'d>, t<'e>)) => t<('a, 'b, 'c, 'd, 'e)> = "all"
@scope("Promise") @val
external all6: ((t<'a>, t<'b>, t<'c>, t<'d>, t<'e>, t<'f>)) => t<('a, 'b, 'c, 'd, 'e, 'f)> = "all"
@scope("Promise") @val external race: array<t<'a>> => t<'a> = "race"

@new
external make: (@uncurry ((. 'a) => unit, (. Js.Exn.t) => unit) => unit) => t<'a> = "Promise"

let make = fn =>
  make((resolve, reject) =>
    fn(x => {
      if isPromiseLike(x) {
        reject(.
          makeJsError(
            "Cannot create a Promise containing another Promise as this will break ReScript static types",
          ),
        )
      } else {
        resolve(. x)
      }
    })
  )

@send
external then: (t<'a>, (. 'a) => t<'b>, option<(. Js.Promise.error) => t<'b>>) => t<'b> = "then"

let catch = (promise, fn) =>
  promise->then(
    (. x) => x->Ok->resolve,
    Some((. e) => e->Js.Exn.anyToExnInternal->fn->Error->resolve),
  )

let chain = (promise, fn) => promise->then((. x) => x->fn, None)
let map = (promise, fn) => promise->then((. x) => x->fn->resolve, None)

let crash = exn => {
  Js.Console.error("Unrecoverable Promise rejection!")
  switch exn {
  | Js.Exn.Error(jsExn) => Js.Console.error(jsExn)
  | _ => Js.Console.error(exn)
  }
  Node.Process.exit(1)
}

let done = (promise, fn) => promise->then((. x) => {
    try {
      x->fn
      resolve()
    } catch {
    | exn => crash(exn)
    }
  }, Some((. e) => e->Js.Exn.anyToExnInternal->crash))->ignore

let chainOk = (promise, fn) =>
  promise->chain(val =>
    switch val {
    | Ok(x) => fn(x)
    | Error(x) => resolve(Error(x))
    }
  )
let mapOk = (promise, fn) => promise->chainOk(val => val->fn->resolve)

let sequence = arr => {
  let rec helper = (result, i) =>
    if i === arr->Js.Array2.length {
      result
    } else {
      result->chain(r => arr[i]()->chain(x => Js.Array2.concat(r, [x])->resolve)->helper(i + 1))
    }
  helper([]->resolve, 0)
}
