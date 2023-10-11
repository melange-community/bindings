Test_runners.runTests(
  ~parser=Json.parse,
  ~makeName=(input, _) => `[JSON Number] Run with "${input}"`,
  ~specs=[
    ("1234", Number("1234"), ""),
    ("-1234", Number("-1234"), ""),
    ("-0", Number("-0"), ""),
    ("0", Number("0"), ""),
    ("1234.1234", Number("1234.1234"), ""),
    ("1234.1e1", Number("1234.1e1"), ""),
    ("0.12E-6543", Number("0.12E-6543"), ""),
  ],
)
Test_runners.runTests(
  ~parser=Json.parse,
  ~makeName=(input, _) => `[JSON Number] Partial with "${input}"`,
  ~specs=[
    ("0.12E-6543hello", Number("0.12E-6543"), "hello"),
    ("111hello", Number("111"), "hello"),
    ("-533.1hello", Number("-533.1"), "hello"),
    ("-1234.1..1hello", Number("-1234.1"), "..1hello"),
  ],
)

Test_runners.runFailureTests(
  ~parser=Json.parse,
  ~makeName=input => `[JSON Number] Run with "${input}"`,
  ~specs=["_-1", "--0.12E-6543", "a0.12"],
)
