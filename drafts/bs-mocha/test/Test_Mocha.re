let (it', it_skip') = Async.(it, it_skip);
open Mocha;

describe("Mocha", () => {
  describe("Success", () =>
    describe("List", () => {
      it("should map the values", () =>
        Assert.deep_equal(List.map(( * )(2), [1, 2, 3]), [2, 4, 6])
      );

      it("should work with an empty list", () =>
        Assert.equal(List.map(( * )(2), []), [])
      );
    })
  );

  describe_skip("Error", () => it("should fail", () =>
                                 Assert.equal(1, 2)
                               ));

  describe("Hooks", () => {
    let hooks =
      ref({
        "before": false,
        "before_each": 0,
        "after": false,
        "after_each": 0,
      });

    before(() =>
      hooks :=
        {"before": true, "before_each": 0, "after": false, "after_each": 0}
    );

    before_each(() => {
      let hooks' = hooks^;
      hooks :=
        {
          "before": hooks'##before,
          "before_each": hooks'##before_each + 1,
          "after": hooks'##after,
          "after_each": hooks'##after_each,
        };
    });

    it("is the first test", () =>
      ()
    );
    it("is the second test", () =>
      ()
    );
    it("is the third test", () =>
      ()
    );

    after_each(() => {
      let hooks' = hooks^;
      hooks :=
        {
          "before": hooks'##before,
          "before_each": hooks'##before_each,
          "after": hooks'##after,
          "after_each": hooks'##after_each + 1,
        };
    });

    after(() => {
      let hooks' = hooks^;
      hooks :=
        {
          "before": hooks'##before,
          "before_each": hooks'##before_each,
          "after": true,
          "after_each": hooks'##after_each,
        };

      /* TODO: this is pretty ugly, caused by (facebook/reason issue #2108) */
      let hooks'' = hooks^;
      Assert.ok(hooks''##before);
      Assert.equal(hooks''##before_each, 3);
      Assert.equal(hooks''##after_each, 3);
      Assert.ok(hooks''##after);
    });
  });

  describe(
    "Timeout",
    ~timeout=50,
    () => {
      it_skip'("should time out", done_ =>
        Js.Global.setTimeout(() => done_(), 51) |> ignore
      );

      it'("should not time out", done_ =>
        Js.Global.setTimeout(() => done_(), 40) |> ignore
      );

      it_skip(
        "should time out",
        ~timeout=1,
        () => {
          let result = ref(1);
          for (x in 1 to 100000) {
            result := result^ + x;
          };
          Assert.ok(result^ > 1);
        },
      );
    },
  );

  describe("Retries", () => {
    let retry_count = ref(0);
    it(
      "should succeed",
      ~retries=2,
      () => {
        retry_count := retry_count^ + 1;
        Assert.ok(retry_count^ == 1);
      },
    );

    it_skip(
      "should fail",
      ~retries=3,
      () => {
        retry_count := retry_count^ + 1;
        Assert.ok(retry_count^ == 6);
      },
    );
  });

  describe("Slow", () =>
    it(
      "should be considered slow",
      ~slow=1,
      () => {
        let result = ref(1);
        for (x in 1 to 100000) {
          result := result^ + x;
        };
        Assert.ok(result^ > 1);
      },
    )
  );
});
