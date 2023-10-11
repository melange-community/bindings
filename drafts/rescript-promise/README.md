# @rpominov/rescript-promise

Another Promise bindings for ReScript. I wrote this primarily for myself to use in my own projects, so the API can be opinionated and unconventional in some places. Also, **the API is not stable** as I’m still exploring the best way to work with promises in ReScript.

Features / design decisions:

- Does not allow to create `Promise.t<Promise.t<'a>>` as this is not possible in the underlying JavaScript implementation. The library will throw an exception if you try to create such a value.
- Native `Js.Exn` is preferred to ReScript exceptions. Because of the better support in the environment. For example, stack is printed correctly for uncaught exceptions in NodeJS.
- Provides some utilities for `Promise.t<result<'a, 'b>>`.
- Might not work in the browser as it uses some NodeJS APIs like `process.exit()`.

## Installation

```sh
npm i @rpominov/rescript-promise
```

In your `bsconfig.json` add it to `bs-dependencies`

```
{
  ...,
  "bs-dependencies": [..., "@rpominov/rescript-promise"],
}
```

## API

### `type Promise.t<'a>`

Just an alias for `Js.Promise.t<'a>`

### `Promise.resolve: 'a => Promise.t<'a>`

The same as [`Promise.resolve(value)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/resolve) in JavaScript.

If the given value is a promise-like object, will create a rejected promise with a `Js.Exn` exception.
This is necessary because the underlying JavaScript implementation
automatically flattens any `Promise.t<Promise.t<'a>>` into a `Promise.t<'a>`,
but this special case behavior cannot be expressed with ReScript type system.

```rescript
// This will raise an exception!
Promise.resolve(Promise.resolve(1))
```

Note that the above issue occurs not only with promises,
but with any object that has a `then` property, that happens to be a function.

### `Promise.make: (('a => unit) => unit) => Promise.t<'a>`

`Promise.make(resolve => resolve(val))` is the same as `new Promise(resolve => resolve(val))` in JavaScript.

The reject callback is not provided by design.
Resolve with a `result`'s `Error` instead or use `Js.Promise.make`.

If you pass a promise into `resolve()`, the promise will reject with
a `Js.Exn` exception instead of resolving (same as with `Promise.resolve` above)!

### `Promise.reject: Js.Exn.t => Promise.t<'a>`

The same as [`Promise.reject(error)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/reject) in JavaScript.

### `Promise.makeJsError: string => Js.Exn.t`

The same as `new Error(string)` in JavaScript. Added to use in conjunction with `Promise.reject`.

### `Promise.catch: (Promise.t<'a>, exn => 'b) => Promise.t<result<'a, 'b>>`

Catches the error that the given promise might reject with,
passes that error to the provided function,
and returns a Promise containing `Error(fn(exn))`.

If the given promise doesn't reject, wraps the value in an `Ok()`.

```rescript
Promise.make(_ => {
  Js.Exn.raiseError("Test")
})
->Promise.catch(exn =>
  switch exn {
  | Js.Exn.Error(jsExn) => jsExn->Js.Exn.message
  | _ => Some("Unknown exception")
  }
)
->Promise.done(result => {
  switch result {
  | Ok(_) => Js.log("Not going to log this")
  | Error(msg) => Js.log(msg) // Test
  }
})
```

Note that the callback gets a ReScript exception as an argument, even if the original promise contained a JavaScript `Error`.
This works the same as in `try..catch`: https://rescript-lang.org/docs/manual/latest/exception#catching-js-exceptions

### `Promise.chain: (Promise.t<'a>, 'a => Promise.t<'b>) => Promise.t<'b>`

`promise->Promise.chain(fn)` is the same as [`promise.then(fn)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/then) in JavaScript, where `fn` returns a promise.

### `Promise.map: (Promise.t<'a>, 'a => 'b) => Promise.t<'b>`

`promise->Promise.map(fn)` is the same as [`promise.then(fn)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/then) in JavaScript, where `fn` returns something other than promise.

Note: if `fn` returns a promise, will reject with `Js.Exn` (same as with `Promise.resolve` above)!

### `Promise.done: (Promise.t<'a>, 'a => unit) => unit`

- If the given promise resolves with a value, calls the provided callback with that value as an argument.
- If the given promise rejects, logs the error and crashes the Node process.
- If the provided callback raises an exception, logs the exception and crashes the Node process.

The idea is that you catch the recoverable errors with `Promise.catch` / `try..catch`,
and in the case of unrecoverable errors, we crash the process:

```rescript
promise
->Promise.catch(catchRecoverable)
->Promise.done(result => {
  try {
    handleResult(result)
  } catch {
  | SomeRecoverableException => handleRecoverable()
  }
})
```

And if you don't expect any errors:

```rescript
promise
->Promise.done(result => {
  handleResult(result)
})
```

### `Promise.race: array<Promise.t<'a>> => Promise.t<'a>`

The same as [`Promise.race(array)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/race) in JavaScript.

### `Promise.all: array<Promise.t<'a>> => Promise.t<array<'a>>`

The same as [`Promise.all(array)`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/all) in JavaScript.

### `Promise.all2: ((Promise.t<'a>, Promise.t<'b>)) => Promise.t<('a, 'b)>`

The same as `Promise.all`, but with a two-value tuple instead of an array.

There're also `all3`, `all4`, `all5`, and `all6` with the corresponding numbers of arguments.

### `Promise.sequence: array<unit => Promise.t<'a>> => Promise.t<array<'a>>`

Given an array of functions that return promises, calls the functions in sequence:
calls the next function only after the promise returned by the previous function resolves.

If any of the promises reject, does not call the remaining functions,
and the result promise rejects with the same error.

In case of successful completion of all promises,
the result promise contains an array of values produced by the promises.

```rescript
Promise.sequence([
  () => Promise.resolve(1),
  () => Promise.resolve(2),
])->Promise.done(arr => {
  Js.log(arr) // [1, 2]
})
```

### `Promise.chainOk: (Promise.t<result<'a, 'b>>, 'a => Promise.t<result<'c, 'b>>) => Promise.t<result<'c, 'b>>`

The same as `Promise.chain`, but calls the provided function with `val` as an argument
only if the original promise contains an `Ok(val)`.

```rescript
Promise.resolve(Ok(1))->Promise.chainOk(x => Promise.resolve(Ok(x + 1))) // Promise(Ok(2))

// The function hasn't been called
Promise.resolve(Error(1))->Promise.chainOk(x => Promise.resolve(Ok(x + 1))) // Promise(Error(1))
```

### `Promise.mapOk: (Promise.t<result<'a, 'b>>, 'a => result<'c, 'b>) => Promise.t<result<'c, 'b>>`

The same as `Promise.map`, but calls the provided function with `val` as an argument
only if the original promise contains an `Ok(val)`.

```rescript
Promise.resolve(Ok(1))->Promise.mapOk(x => Ok(x + 1)) // Promise(Ok(2))

// The function hasn't been called
Promise.resolve(Error(1))->Promise.mapOk(x => Ok(x + 1)) // Promise(Error(1))
```
