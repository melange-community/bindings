type mocha
and done_callback = Js.Nullable.t(Js.Exn.t) => unit
and test_fn('arg, 'result) =
  (~description: string=?, [@bs.this] ((mocha, 'arg) => 'result)) => unit;

module Fn_Type = {
  /* Internal representation of mocha test functions */
  type internal_callback =
    (~description: string=?, [@bs.this] ((mocha, done_callback) => unit)) =>
    unit
  /* Internal representation with `unit => unit` callback (special-cased to
     ensure compiled JS is a nullary function) */
  and internal_nullary('result) =
    (~description: string=?, [@bs.this] (mocha => 'result)) => unit
  /* Nicer representation of mocha test functions */
  and fn('arg, 'result) =
    (
      ~description: string=?,
      ~timeout: int=?,
      ~retries: int=?,
      ~slow: int=?,
      'arg => 'result
    ) =>
    unit
  /* For `describe` and `it`, which require a mandatory description */
  and test('arg, 'result) =
    (
      string,
      ~timeout: int=?,
      ~retries: int=?,
      ~slow: int=?,
      'arg => 'result
    ) =>
    unit;
};

/* Mocha bindings on `this` for `describe` and `it` functions */
module This = {
  [@bs.send] external timeout: (mocha, int) => unit = "timeout";
  [@bs.send] external retries: (mocha, int) => unit = "retries";
  [@bs.send] external slow: (mocha, int) => unit = "slow";
  [@bs.send] external skip: (mocha, unit) => unit = "skip";
};

module Sync = {
  [@bs.val]
  external describe:
    (~description: string=?, [@bs.this] (mocha => unit)) => unit =
    "describe";
  [@bs.val]
  external describe_only:
    (~description: string=?, [@bs.this] (mocha => unit)) => unit =
    "describe.only";
  [@bs.val]
  external describe_skip:
    (~description: string=?, [@bs.this] (mocha => unit)) => unit =
    "describe.skip";
  [@bs.val]
  external it: (~description: string=?, [@bs.this] (mocha => unit)) => unit =
    "it";
  [@bs.val]
  external it_only:
    (~description: string=?, [@bs.this] (mocha => unit)) => unit =
    "it.only";
  [@bs.val]
  external it_skip:
    (~description: string=?, [@bs.this] (mocha => unit)) => unit =
    "it.skip";
  [@bs.val]
  external before: (~description: string=?, [@bs.this] (mocha => unit)) => unit =
    "before";
  [@bs.val]
  external after: (~description: string=?, [@bs.this] (mocha => unit)) => unit =
    "after";
  [@bs.val]
  external before_each:
    (~description: string=?, [@bs.this] (mocha => unit)) => unit =
    "beforeEach";
  [@bs.val]
  external after_each:
    (~description: string=?, [@bs.this] (mocha => unit)) => unit =
    "afterEach";
};

module Async = {
  [@bs.val]
  external it:
    (~description: string=?, [@bs.this] ((mocha, done_callback) => unit)) =>
    unit =
    "it";
  [@bs.val]
  external it_only:
    (~description: string=?, [@bs.this] ((mocha, done_callback) => unit)) =>
    unit =
    "it.only";
  [@bs.val]
  external it_skip:
    (~description: string=?, [@bs.this] ((mocha, done_callback) => unit)) =>
    unit =
    "it.skip";
  [@bs.val]
  external before:
    (~description: string=?, [@bs.this] ((mocha, done_callback) => unit)) =>
    unit =
    "before";
  [@bs.val]
  external after:
    (~description: string=?, [@bs.this] ((mocha, done_callback) => unit)) =>
    unit =
    "after";
  [@bs.val]
  external before_each:
    (~description: string=?, [@bs.this] ((mocha, done_callback) => unit)) =>
    unit =
    "beforeEach";
  [@bs.val]
  external after_each:
    (~description: string=?, [@bs.this] ((mocha, done_callback) => unit)) =>
    unit =
    "afterEach";
};

module Promise = {
  [@bs.val]
  external it:
    (~description: string=?, [@bs.this] (mocha => Js.Promise.t('a))) => unit =
    "it";
  [@bs.val]
  external it_only:
    (~description: string=?, [@bs.this] (mocha => Js.Promise.t('a))) => unit =
    "it.only";
  [@bs.val]
  external it_skip:
    (~description: string=?, [@bs.this] (mocha => Js.Promise.t('a))) => unit =
    "it.skip";
  [@bs.val]
  external before:
    (~description: string=?, [@bs.this] (mocha => Js.Promise.t('a))) => unit =
    "before";
  [@bs.val]
  external after:
    (~description: string=?, [@bs.this] (mocha => Js.Promise.t('a))) => unit =
    "after";
  [@bs.val]
  external before_each:
    (~description: string=?, [@bs.this] (mocha => Js.Promise.t('a))) => unit =
    "beforeEach";
  [@bs.val]
  external after_each:
    (~description: string=?, [@bs.this] (mocha => Js.Promise.t('a))) => unit =
    "afterEach";
};

/* Constructs a function that can take the options that are normally set with `this` in mocha */
module With_Options = {
  let make: Fn_Type.internal_nullary('result) => Fn_Type.fn(unit, 'result) =
    (fn, ~description=?, ~timeout=?, ~retries=?, ~slow=?, done_callback) =>
      fn(
        ~description?,
        [@bs.this] this => {
          switch (timeout) {
          | Some(milliseconds) => This.timeout(this, milliseconds)
          | None => ()
          };
          switch (retries) {
          | Some(max_retries) => This.retries(this, max_retries)
          | None => ()
          };
          switch (slow) {
          | Some(milliseconds) => This.slow(this, milliseconds)
          | None => ()
          };
          done_callback();
        },
      );

  let make':
    Fn_Type.internal_callback =>
    Fn_Type.fn((~error: Js.Exn.t=?, unit) => unit, unit) =
    (fn, ~description=?, ~timeout=?, ~retries=?, ~slow=?, done_callback) =>
      fn(
        ~description?,
        [@bs.this] (this, done_callback') => {
          switch (timeout) {
          | Some(milliseconds) => This.timeout(this, milliseconds)
          | None => ()
          };
          switch (retries) {
          | Some(max_retries) => This.retries(this, max_retries)
          | None => ()
          };
          switch (slow) {
          | Some(milliseconds) => This.slow(this, milliseconds)
          | None => ()
          };

          let done_fn = (~error=?, ()) =>
            done_callback'(Js.Nullable.fromOption(error));
          done_callback(done_fn);
        },
      );
};
