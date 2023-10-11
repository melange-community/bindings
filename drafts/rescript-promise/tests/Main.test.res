open Jest

testPromise("Promise.make", () => {
  expectAssertions(1)

  Promise.make(resolve => resolve(10))->Promise.map(x => {
    expect(x)->toEqual(10)
  })
})

testPromise("Promise.make + nested promise", () => {
  expectAssertions(1)

  Promise.make(resolve => resolve(Promise.resolve(10)))
  ->Promise.catch(exn =>
    switch exn {
    | Js.Exn.Error(err) => Ok(err->Js.Exn.message)
    | _ => Error("Didn't throw a correct exception")
    }
  )
  ->Promise.map(result => {
    expect(result)->toEqual(
      Error(
        Ok(
          Some(
            "Cannot create a Promise containing another Promise as this will break ReScript static types",
          ),
        ),
      ),
    )
  })
})

testPromise("Promise.make + nested promise (async)", () => {
  expectAssertions(1)

  Promise.make(resolve => Js.Global.setTimeout(() => resolve(Promise.resolve(10)), 0)->ignore)
  ->Promise.catch(exn =>
    switch exn {
    | Js.Exn.Error(err) => Ok(err->Js.Exn.message)
    | _ => Error("Didn't throw a correct exception")
    }
  )
  ->Promise.map(result => {
    expect(result)->toEqual(
      Error(
        Ok(
          Some(
            "Cannot create a Promise containing another Promise as this will break ReScript static types",
          ),
        ),
      ),
    )
  })
})

testPromise("Promise.resolve", () => {
  expectAssertions(1)

  Promise.resolve(10)->Promise.map(x => {
    expect(x)->toEqual(10)
  })
})

testPromise("Promise.resolve + nested promise", () => {
  expectAssertions(1)

  Promise.resolve(Promise.resolve(10))
  ->Promise.catch(exn =>
    switch exn {
    | Js.Exn.Error(err) => Ok(err->Js.Exn.message)
    | _ => Error("Didn't throw a correct exception")
    }
  )
  ->Promise.map(result => {
    expect(result)->toEqual(
      Error(
        Ok(
          Some(
            "Cannot create a Promise containing another Promise as this will break ReScript static types",
          ),
        ),
      ),
    )
  })
})

testPromise("Promise.reject / Promise.catch", () => {
  expectAssertions(1)

  let err = Promise.makeJsError("Test")

  Promise.reject(err)
  ->Promise.catch(x => x)
  ->Promise.map(x =>
    switch x {
    | Error(Js.Exn.Error(e)) => expect(e)->toBe(err)
    | _ => Js.Exn.raiseError("Should not happen")
    }
  )
})

testPromise("Promise.race", () => {
  expectAssertions(1)

  Promise.race([Promise.resolve(1), Promise.resolve(1)])->Promise.map(x => expect(x)->toEqual(1))
})

testPromise("Promise.all", () => {
  expectAssertions(1)

  Promise.all([Promise.resolve(1), Promise.resolve(2)])->Promise.map(x =>
    expect(x)->toEqual([1, 2])
  )
})

testPromise("Promise.all2", () => {
  expectAssertions(1)

  Promise.all2((Promise.resolve(1), Promise.resolve(true)))->Promise.map(x =>
    expect(x)->toEqual((1, true))
  )
})

testPromise("Promise.all3", () => {
  expectAssertions(1)

  Promise.all3((Promise.resolve(1), Promise.resolve(true), Promise.resolve(2)))->Promise.map(x =>
    expect(x)->toEqual((1, true, 2))
  )
})

testPromise("Promise.all4", () => {
  expectAssertions(1)

  Promise.all4((
    Promise.resolve(1),
    Promise.resolve(true),
    Promise.resolve(2),
    Promise.resolve(3),
  ))->Promise.map(x => expect(x)->toEqual((1, true, 2, 3)))
})

testPromise("Promise.all5", () => {
  expectAssertions(1)

  Promise.all5((
    Promise.resolve(1),
    Promise.resolve(true),
    Promise.resolve(2),
    Promise.resolve(3),
    Promise.resolve(4),
  ))->Promise.map(x => expect(x)->toEqual((1, true, 2, 3, 4)))
})

testPromise("Promise.all6", () => {
  expectAssertions(1)

  Promise.all6((
    Promise.resolve(1),
    Promise.resolve(true),
    Promise.resolve(2),
    Promise.resolve(3),
    Promise.resolve(4),
    Promise.resolve(5),
  ))->Promise.map(x => expect(x)->toEqual((1, true, 2, 3, 4, 5)))
})

testPromise("Promise.chain", () => {
  expectAssertions(1)

  Promise.resolve(1)
  ->Promise.chain(x => Promise.resolve(x + 1))
  ->Promise.map(x => expect(x)->toEqual(2))
})

testPromise("Promise.map", () => {
  expectAssertions(1)

  Promise.resolve(1)->Promise.map(x => x + 1)->Promise.map(x => expect(x)->toEqual(2))
})

// TODO: test the crash case (need to mock process.exit)
testAsync("Promise.done", testDone => {
  expectAssertions(1)

  Promise.resolve(1)->Promise.done(x => {
    expect(x)->toEqual(1)
    testDone(.)
  })
})

testPromise("Promise.chainOk + Error", () => {
  expectAssertions(1)

  Promise.resolve(Error(1))
  ->Promise.chainOk(x => Promise.resolve(Ok(x + 1)))
  ->Promise.map(x => expect(x)->toEqual(Error(1)))
})

testPromise("Promise.chainOk + Ok", () => {
  expectAssertions(1)

  Promise.resolve(Ok(1))
  ->Promise.chainOk(x => Promise.resolve(Ok(x + 1)))
  ->Promise.map(x => expect(x)->toEqual(Ok(2)))
})

testPromise("Promise.mapOk + Error", () => {
  expectAssertions(1)

  Promise.resolve(Error(1))
  ->Promise.mapOk(x => Ok(x + 1))
  ->Promise.map(x => expect(x)->toEqual(Error(1)))
})

testPromise("Promise.mapOk + Ok", () => {
  expectAssertions(1)

  Promise.resolve(Ok(1))->Promise.mapOk(x => Ok(x + 1))->Promise.map(x => expect(x)->toEqual(Ok(2)))
})

testPromise("Promise.sequence", () => {
  expectAssertions(2)

  let events = []
  let push = event => events->Js.Array2.push(event)->ignore

  [
    () => {
      push("first fn called")
      Promise.resolve()->Promise.map(_ => {
        push("first resolved")
        1
      })
    },
    () => {
      push("second fn called")
      Promise.resolve()->Promise.map(_ => {
        push("second resolved")
        2
      })
    },
    () => {
      push("third fn called")
      Promise.resolve()->Promise.map(_ => {
        push("third resolved")
        3
      })
    },
  ]
  ->Promise.sequence
  ->Promise.map(x => {
    expect(x)->toEqual([1, 2, 3])
    expect(events)->toEqual([
      "first fn called",
      "first resolved",
      "second fn called",
      "second resolved",
      "third fn called",
      "third resolved",
    ])
  })
})
