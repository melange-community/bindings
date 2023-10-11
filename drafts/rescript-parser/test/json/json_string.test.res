Test_runners.runTests(
  ~parser=Json.parse,
  ~makeName=(input, _) => `[JSON String] "${input}"`,
  ~specs=[
    (`"1"`, Json.String("1"), ""),
    (`"hello"`, String("hello"), ""),
    (`"   "`, String("   "), ""),
    (`""`, String(""), ""),
    (`"\u0050"`, String("P"), ""),
    (`"\u0050\u0069\u0061n\u006F"`, String("Piano"), ""),
  ],
)
