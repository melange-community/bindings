type rec test_fn<'a> = Internal.Fn_Type.test<unit, Js.Promise.t<'a>>
and hook<'a> = Internal.Fn_Type.fn<unit, Js.Promise.t<'a>>

let it: test_fn<'a> = description => Internal.With_Options.make(Internal.Promise.it, ~description)
and it_only: test_fn<'a> = description =>
  Internal.With_Options.make(Internal.Promise.it_only, ~description)
and it_skip: test_fn<'a> = description =>
  Internal.With_Options.make(Internal.Promise.it_skip, ~description)
and before: hook<'a> = (~description=?) =>
  Internal.With_Options.make(Internal.Promise.before, ~description?)
and after: hook<'a> = (~description=?) =>
  Internal.With_Options.make(Internal.Promise.after, ~description?)
and before_each: hook<'a> = (~description=?) =>
  Internal.With_Options.make(Internal.Promise.before_each, ~description?)
and after_each: hook<'a> = (~description=?) =>
  Internal.With_Options.make(Internal.Promise.after_each, ~description?)
