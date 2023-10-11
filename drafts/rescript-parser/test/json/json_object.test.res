let decorate = Belt.Array.map(_, ((a, b)) => (a, b, ""))

Test_runners.runTests(
  ~makeName=(input, _) => `[JSON Object] Run with "${input}"`,
  ~parser=Json.parse,
  ~specs=[
    ("{}", Json.Object(list{})),
    ("    {  }       ", Json.Object(list{})),
    (` { "a":1  }       `, Json.Object(list{("a", Number("1"))})),
    (` { "":""  }  `, Json.Object(list{("", String(""))})),
    (
      ` { "foo": {"bar  "   : { "baz":1 }}  }  `,
      Json.Object(list{("foo", Object(list{("bar  ", Object(list{("baz", Number("1"))}))}))}),
    ),
    (` { "foo": [1]  }  `, Object(list{("foo", Array(list{Number("1")}))})),
    (
      ` { "foo": [1, [[2]]]  }  `,
      Object(list{("foo", Array(list{Number("1"), Array(list{Array(list{Number("2")})})}))}),
    ),
    (
      ` { "foo": [1, [[2, 2]]]  }  `,
      Object(list{
        ("foo", Array(list{Number("1"), Array(list{Array(list{Number("2"), Number("2")})})})),
      }),
    ),
    (
      ` { "foo": [1, [[2, 2, []]]]  }  `,
      Object(list{
        (
          "foo",
          Array(list{
            Number("1"),
            Array(list{Array(list{Number("2"), Number("2"), Array(list{})})}),
          }),
        ),
      }),
    ),
    (
      ` { "foo": [1, [[2   ,2,[[3         ]]] ]]  }  `,
      Object(list{
        (
          "foo",
          Array(list{
            Number("1"),
            Array(list{
              Array(list{Number("2"), Number("2"), Array(list{Array(list{Number("3")})})}),
            }),
          }),
        ),
      }),
    ),
    (
      ` { "foo": [1, [[2   ,2,[[3        , {"b_": [1234]} ]]] ]]  }  `,
      Object(list{
        (
          "foo",
          Array(list{
            Number("1"),
            Array(list{
              Array(list{
                Number("2"),
                Number("2"),
                Array(list{
                  Array(list{Number("3"), Object(list{("b_", Array(list{Number("1234")}))})}),
                }),
              }),
            }),
          }),
        ),
      }),
    ),
  ]->decorate,
)

Test_runners.runTests(
  ~makeName=(input, _) => `[JSON Object] Run with "${input}"`,
  ~parser=Json.parse,
  ~specs=[
    ("{}a", Json.Object(list{}), "a"),
    (`{ "hello": 1234 }}}`, Json.Object(list{("hello", Number("1234"))}), "}}"),
    (`{ "hello": 1234 }]]`, Json.Object(list{("hello", Number("1234"))}), "]]"),
    (`{ "hello": [1234] }-)`, Json.Object(list{("hello", Array(list{Number("1234")}))}), "-)"),
  ],
)

Test_runners.runFailureTests(
  ~makeName=input => `[JSON Object] Run with "${input}"`,
  ~parser=Json.parse,
  ~specs=[
    //
    "       +{}",
    "_{}",
    `|{"hello": 1}`,
    `a{}`,
    `~{f}`,
  ],
)
