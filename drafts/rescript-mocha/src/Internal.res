type rec mocha
and done_callback = Js.Nullable.t<Js.Exn.t> => unit
and test_fn<'arg, 'result> = (~description: string=?, @this (mocha, 'arg) => 'result) => unit

module Fn_Type = {
  /* Internal representation of mocha test functions */
  type rec internal_callback = (
    ~description: string=?,
    @this (mocha, done_callback) => unit,
  ) => unit
  /* Internal representation with `unit => unit` callback (special-cased to
   ensure compiled JS is a nullary function) */
  and internal_nullary<'result> = (~description: string=?, @this (mocha => 'result)) => unit
  /* Nicer representation of mocha test functions */
  and fn<'arg, 'result> = (
    ~description: string=?,
    ~timeout: int=?,
    ~retries: int=?,
    ~slow: int=?,
    'arg => 'result,
  ) => unit
  /* For `describe` and `it`, which require a mandatory description */
  and test<'arg, 'result> = (
    string,
    ~timeout: int=?,
    ~retries: int=?,
    ~slow: int=?,
    'arg => 'result,
  ) => unit
}

/* Mocha bindings on `this` for `describe` and `it` functions */
module This = {
  @send external timeout: (mocha, int) => unit = "timeout"
  @send external retries: (mocha, int) => unit = "retries"
  @send external slow: (mocha, int) => unit = "slow"
  @send external skip: (mocha, unit) => unit = "skip"
}

module Sync = {
  @val
  external describe: (~description: string=?, @this (mocha => unit)) => unit = "describe"
  @val
  external describe_only: (~description: string=?, @this (mocha => unit)) => unit = "describe.only"
  @val
  external describe_skip: (~description: string=?, @this (mocha => unit)) => unit = "describe.skip"
  @val
  external it: (~description: string=?, @this (mocha => unit)) => unit = "it"
  @val
  external it_only: (~description: string=?, @this (mocha => unit)) => unit = "it.only"
  @val
  external it_skip: (~description: string=?, @this (mocha => unit)) => unit = "it.skip"
  @val
  external before: (~description: string=?, @this (mocha => unit)) => unit = "before"
  @val
  external after: (~description: string=?, @this (mocha => unit)) => unit = "after"
  @val
  external before_each: (~description: string=?, @this (mocha => unit)) => unit = "beforeEach"
  @val
  external after_each: (~description: string=?, @this (mocha => unit)) => unit = "afterEach"
}

module Async = {
  @val
  external it: (~description: string=?, @this (mocha, done_callback) => unit) => unit = "it"
  @val
  external it_only: (~description: string=?, @this (mocha, done_callback) => unit) => unit =
    "it.only"
  @val
  external it_skip: (~description: string=?, @this (mocha, done_callback) => unit) => unit =
    "it.skip"
  @val
  external before: (~description: string=?, @this (mocha, done_callback) => unit) => unit = "before"
  @val
  external after: (~description: string=?, @this (mocha, done_callback) => unit) => unit = "after"
  @val
  external before_each: (~description: string=?, @this (mocha, done_callback) => unit) => unit =
    "beforeEach"
  @val
  external after_each: (~description: string=?, @this (mocha, done_callback) => unit) => unit =
    "afterEach"
}

module Promise = {
  @val
  external it: (~description: string=?, @this (mocha => Js.Promise.t<'a>)) => unit = "it"
  @val
  external it_only: (~description: string=?, @this (mocha => Js.Promise.t<'a>)) => unit = "it.only"
  @val
  external it_skip: (~description: string=?, @this (mocha => Js.Promise.t<'a>)) => unit = "it.skip"
  @val
  external before: (~description: string=?, @this (mocha => Js.Promise.t<'a>)) => unit = "before"
  @val
  external after: (~description: string=?, @this (mocha => Js.Promise.t<'a>)) => unit = "after"
  @val
  external before_each: (~description: string=?, @this (mocha => Js.Promise.t<'a>)) => unit =
    "beforeEach"
  @val
  external after_each: (~description: string=?, @this (mocha => Js.Promise.t<'a>)) => unit =
    "afterEach"
}

/* Constructs a function that can take the options that are normally set with `this` in mocha */
module With_Options = {
  let make: Fn_Type.internal_nullary<'result> => Fn_Type.fn<unit, 'result> = (
    fn,
    ~description=?,
    ~timeout=?,
    ~retries=?,
    ~slow=?,
    done_callback,
  ) =>
    fn(~description?, @this this => {
      switch timeout {
      | Some(milliseconds) => This.timeout(this, milliseconds)
      | None => ()
      }
      switch retries {
      | Some(max_retries) => This.retries(this, max_retries)
      | None => ()
      }
      switch slow {
      | Some(milliseconds) => This.slow(this, milliseconds)
      | None => ()
      }
      done_callback()
    })

  let make': Fn_Type.internal_callback => Fn_Type.fn<(~error: Js.Exn.t=?, unit) => unit, unit> = (
    fn,
    ~description=?,
    ~timeout=?,
    ~retries=?,
    ~slow=?,
    done_callback,
  ) =>
    fn(~description?, @this (this, done_callback') => {
      switch timeout {
      | Some(milliseconds) => This.timeout(this, milliseconds)
      | None => ()
      }
      switch retries {
      | Some(max_retries) => This.retries(this, max_retries)
      | None => ()
      }
      switch slow {
      | Some(milliseconds) => This.slow(this, milliseconds)
      | None => ()
      }

      let done_fn = (~error=?, ()) => done_callback'(Js.Nullable.fromOption(error))
      done_callback(done_fn)
    })
}
