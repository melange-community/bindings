let decorate = Belt.Array.map(_, ((a, b)) => (a, Json.Null, b))

Test_runners.runTests(
  ~parser=Json.parse,
  ~makeName=(input, _) => `[JSON Null] Valid with "${input}"`,
  ~specs=[
    //
    ("null", ""),
    ("     null", ""),
    ("     null           ", ""),
    ("null           ", ""),
  ]->decorate,
)

Test_runners.runTests(
  ~parser=Json.parse,
  ~makeName=(input, _) => `[JSON Null] Partially valid with "${input}"`,
  ~specs=[
    //
    ("nulla", "a"),
    ("     null   ___", "___"),
    ("     null}[]", "}[]"),
    ("null           +", "+"),
  ]->decorate,
)

Test_runners.runFailureTests(
  ~makeName=input => `[JSON Null] Invalid with "${input}"`,
  ~parser=Json.parse,
  ~specs=[
    //
    ".",
    "-null",
    "     ]null}[]",
    "tnull",
  ],
)
