Test_runners.runTests(
  ~parser=Json.parse,
  ~makeName=(input, _) => `[JSON] True "${input}"`,
  ~specs=[("true", Json.True, ""), ("false", False, "")],
)

Test_runners.runFailureTests(
  ~parser=Json.parse,
  ~makeName=input => `[JSON] Invalid true "${input}"`,
  ~specs=["ttrue", "-true"],
)

Test_runners.runFailureTests(
  ~parser=Json.parse,
  ~makeName=input => `[JSON] Invalid false "${input}"`,
  ~specs=["ffalse", "{false"],
)
