module P = Res_parser

Test_runners.runTests(
  ~parser={
    P.char('a')
    ->P.separatedBy1(P.char(','))
    ->P.map(Belt.List.map(_, Json.charToString))
    ->P.map(Json.concatStringList)
  },
  ~makeName=(input, expected) => `[Separated by] Simple "${input} == ${expected}"`,
  ~specs=[
    ("a,a", "aa", ""),
    ("a,,a", "a", ",,a"),
    ("a,a,a,a", "aaaa", ""),
    ("a", "a", ""),
    ("a,b,c", "a", ",b,c"),
  ],
)

Test_runners.runTests(
  ~parser={
    let manyWhitespace = P.many(P.char(' '))
    let commaWithWhitespace = P.char(',')->P.between(manyWhitespace, manyWhitespace)

    P.char('a')->P.separatedBy1(commaWithWhitespace)
  },
  ~makeName=(input, _) => `[Separated by] semi-simple "${input}"`,
  ~specs=[
    //
    ("a, a,a,   a    ,a", list{'a', 'a', 'a', 'a', 'a'}, ""),
    ("a", list{'a'}, ""),
  ],
)

Test_runners.runTests(
  ~parser={
    P.char('a')
    ->P.separatedBy(P.char(','))
    ->P.map(Belt.List.map(_, Json.charToString))
    ->P.map(Json.concatStringList)
  },
  ~makeName=(input, _) => `[Separated by many] simple "${input}"`,
  ~specs=[
    //
    ("a,a", "aa", ""),
    ("a,a,a,a", "aaaa", ""),
    ("a", "a", ""),
    ("a,b,c", "a", ",b,c"),
  ],
)

Test_runners.runTests(
  //
  ~parser={
    let atLeastOneComma = P.atLeastOne(P.char(','))

    P.char('a')
    ->P.separatedBy(atLeastOneComma)
    ->P.map(Belt.List.map(_, Json.charToString))
    ->P.map(Json.concatStringList)
  },
  ~makeName=(input, _) => `[Separated by] at least one "${input}"`,
  ~specs=[
    //
    ("a,,,a", "aa", ""),
    ("a,,,,,a,,a,a,,,a", "aaaaa", ""),
  ],
)

Test_runners.runTests(
  ~parser={
    let commaSeparatedByWhitespace = {
      Json.manyWhitespace->P.andThen(P.char(','))->P.andThen(Json.manyWhitespace)
    }

    P.char('a')
    ->P.separatedBy(commaSeparatedByWhitespace)
    ->P.map(Belt.List.map(_, Json.charToString))
    ->P.map(Json.concatStringList)
  },
  ~makeName=(input, _) => `[Separated by ++] at least one "${input}"`,
  ~specs=[
    //
    ("a, a", "aa", ""),
    ("a      ,a", "aa", ""),
    ("a      ,a,a,a      ,a", "aaaaa", ""),
  ],
)
