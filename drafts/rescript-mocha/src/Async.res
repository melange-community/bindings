type rec test_fn = Internal.Fn_Type.test<(~error: Js.Exn.t=?, unit) => unit, unit>
and hook = Internal.Fn_Type.fn<(~error: Js.Exn.t=?, unit) => unit, unit>

let it: test_fn = description => Internal.With_Options.make'(Internal.Async.it, ~description)
and it_only: test_fn = description =>
  Internal.With_Options.make'(Internal.Async.it_only, ~description)
and it_skip: test_fn = description =>
  Internal.With_Options.make'(Internal.Async.it_skip, ~description)
and before: hook = Internal.With_Options.make'(Internal.Async.before)
and after: hook = Internal.With_Options.make'(Internal.Async.after)
and before_each: hook = Internal.With_Options.make'(Internal.Async.before_each)
and after_each: hook = Internal.With_Options.make'(Internal.Async.after_each)
