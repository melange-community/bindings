Test_runners.runTests(
  ~parser=Json.parse,
  ~makeName=(input, _) => `[JSON Array] "${input}"`,
  ~specs=[
    ("[]", Json.Array(list{}), ""),
    (`["1"]`, Array(list{String("1")}), ""),
    (`[1]`, Array(list{Number("1")}), ""),
    (`[1, 2]`, Array(list{Number("1"), Number("2")}), ""),
    (`[1,2]`, Array(list{Number("1"), Number("2")}), ""),
    (`[1, "2"]`, Array(list{Number("1"), String("2")}), ""),
    (`[null, "1"]`, Array(list{Null, String("1")}), ""),
    (`[false, true, 14.2]`, Array(list{False, True, Number("14.2")}), ""),
    (`[      false,     true, 14.2]`, Array(list{False, True, Number("14.2")}), ""),
    (
      `[      false,     true,

  14.2]`,
      Array(list{False, True, Number("14.2")}),
      "",
    ),
    (
      `[1, [1, true, [3, null]]]`,
      Array(list{Number("1"), Array(list{Number("1"), True, Array(list{Number("3"), Null})})}),
      "",
    ),
  ],
)
