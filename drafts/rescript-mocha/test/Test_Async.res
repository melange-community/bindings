let describe = Mocha.describe
open Async

describe("Async", () => {
  /* Calls given function after a small delay */
  let delay = fn => Js.Global.setTimeout(() => fn(), 300) |> ignore

  describe("Success", () =>
    it("should be successful", done_ => Js.Global.setTimeout(() => {
        Assert.equal(3, 3)
        done_()
      }, 500) |> ignore)
  )

  describe("Error", () =>
    it_skip("should error out", done_ => {
      let error: Js.Exn.t = %raw(` new Error("error out") `)
      done_(~error, ())
    })
  )

  describe("Hooks", () => {
    let hooks = ref({
      "before": false,
      "before_each": 0,
      "after": false,
      "after_each": 0,
    })

    before(done_ =>
      delay(() => {
        hooks := {"before": true, "before_each": 0, "after": false, "after_each": 0}
        done_()
      })
    )

    before_each(done_ =>
      delay(() => {
        let hooks' = hooks.contents
        hooks :=
          {
            "before": hooks'["before"],
            "before_each": hooks'["before_each"] + 1,
            "after": hooks'["after"],
            "after_each": hooks'["after_each"],
          }
        done_()
      })
    )

    it("is the first test", done_ => done_())
    it("is the second test", done_ => done_())
    it("is the third test", done_ => done_())

    after_each(done_ =>
      delay(() => {
        let hooks' = hooks.contents
        hooks :=
          {
            "before": hooks'["before"],
            "before_each": hooks'["before_each"],
            "after": hooks'["after"],
            "after_each": hooks'["after_each"] + 1,
          }
        done_()
      })
    )

    after(done_ =>
      delay(() => {
        let hooks' = hooks.contents
        hooks :=
          {
            "before": hooks'["before"],
            "before_each": hooks'["before_each"],
            "after": true,
            "after_each": hooks'["after_each"],
          }

        /* TODO: this is pretty ugly, caused by (facebook/reason issue #2108) */
        let hooks'' = hooks.contents
        Assert.ok(hooks''["before"])
        Assert.equal(hooks''["before_each"], 3)
        Assert.equal(hooks''["after_each"], 3)
        Assert.ok(hooks''["after"])
        done_()
      })
    )
  })

  describe("Timeout", () => {
    it_skip("should time out", ~timeout=50, done_ =>
      Js.Global.setTimeout(() => done_(), 51) |> ignore
    )

    it("should not time out", ~timeout=50, done_ =>
      Js.Global.setTimeout(() => done_(), 40) |> ignore
    )
  })

  describe("Retries", () => {
    let retry_count = ref(0)
    it("should succeed", ~retries=2, done_ => {
      retry_count := retry_count.contents + 1
      Assert.ok(retry_count.contents == 1)
      done_()
    })

    it_skip("should fail", ~retries=3, done_ => {
      retry_count := retry_count.contents + 1
      Assert.ok(retry_count.contents == 6)
      done_()
    })
  })

  describe("Slow", () =>
    it("should be considered slow", ~slow=50, done_ =>
      Js.Global.setTimeout(() => done_(), 40) |> ignore
    )
  )
})
