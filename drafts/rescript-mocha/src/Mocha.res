type rec test_fn = Internal.Fn_Type.test<unit, unit>
and hook = Internal.Fn_Type.fn<unit, unit>

let describe: test_fn = description =>
  Internal.With_Options.make(Internal.Sync.describe, ~description)
and describe_only: test_fn = description =>
  Internal.With_Options.make(Internal.Sync.describe_only, ~description)
and describe_skip: test_fn = description =>
  Internal.With_Options.make(Internal.Sync.describe_skip, ~description)
and it: test_fn = description => Internal.With_Options.make(Internal.Sync.it, ~description)
and it_only: test_fn = description =>
  Internal.With_Options.make(Internal.Sync.it_only, ~description)
and it_skip: test_fn = description =>
  Internal.With_Options.make(Internal.Sync.it_skip, ~description)
and before: hook = (~description=?) =>
  Internal.With_Options.make(Internal.Sync.before, ~description?)
and after: hook = (~description=?) => Internal.With_Options.make(Internal.Sync.after, ~description?)
and before_each: hook = (~description=?) =>
  Internal.With_Options.make(Internal.Sync.before_each, ~description?)
and after_each: hook = (~description=?) =>
  Internal.With_Options.make(Internal.Sync.after_each, ~description?)
