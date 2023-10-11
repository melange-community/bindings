module P = Res_parser

module Simple = Simple_sexp_parser

Ava.test("[Sexps] Char list to string", t => {
  t->Ava.is(list{'h', 'e', 'l', 'l', 'o'}->Simple.charListToString, "hello", ())
})

Test_runners.runTests(
  ~parser=Simple.parser,
  ~makeName=(input, _) => `[Sexps.Simple] String "${input}"`,
  ~specs=[
    (`""`, Simple.String(""), ""),
    (`"hello"`, String("hello"), ""),
    (`    "  he ll   o  "`, String("  he ll   o  "), ""),
  ],
)

Test_runners.runTests(
  ~parser=Simple.parser,
  ~makeName=(input, _) => `[Sexps.Simple] Int "${input}"`,
  ~specs=[
    (`1`, Simple.Int("1"), ""),
    (`    4`, Int("4"), ""),
    (`192`, Int("192"), ""),
    (`  8671109    `, Int("8671109"), ""),
    (`-991344`, Int("-991344"), ""),
    (`    -9     `, Int("-9"), ""),
  ],
)

Test_runners.runTests(
  ~makeName=(input, _) => `[Sexps.Simple] Exp "${input}"`,
  ~parser=Simple.parser,
  ~specs=[
    (`()`, Simple.Exp(list{}), ""),
    (`( )`, Exp(list{}), ""),
    (`(1)`, Exp(list{Int("1")}), ""),
    (
      ` (       1 )

  `,
      Exp(list{Int("1")}),
      "",
    ),
    (`(1 "2" 3)`, Exp(list{Int("1"), String("2"), Int("3")}), ""),
    (`    (  1  "2"     3  )  `, Exp(list{Int("1"), String("2"), Int("3")}), ""),
    (`(1 ("2" 3))`, Exp(list{Int("1"), Exp(list{String("2"), Int("3")})}), ""),
    (
      `
  (     1("2"3) )       `,
      Exp(list{Int("1"), Exp(list{String("2"), Int("3")})}),
      "",
    ),
    (
      `
  (     1("2"(3 (1 (())))) )       `,
      Exp(list{
        Int("1"),
        Exp(list{String("2"), Exp(list{Int("3"), Exp(list{Int("1"), Exp(list{Exp(list{})})})})}),
      }),
      "",
    ),
  ],
)
