# rescript-mocha

ReScript bindings for mocha

## Install 

```
npm install rescript-mocha --save-dev 
```

## Usage 

```rescript
open RescriptMocha
let {it:it', it_skip:it_skip'} = module (Promise)
open Mocha
open Belt

describe("Some Test Suite", () =>
  describe("List.map", () => {
    it("should map the values", () =>
      Assert.deep_equal(Array.map([1, 2, 3], (i) => i * 2), [2, 4, 6])
    )

    it("should work with an empty list", () =>
      Assert.deep_equal(Array.map([], (i) => i * 2), [])
    )

    it'("should be successful", () =>
      Js.Promise.make((~resolve, ~reject as _) =>
        Js.Global.setTimeout(() => {
          Assert.equal(3, 3)
          resolve(. true)
        }, 300)
        ->ignore
      )
    )
  })
)


```

## License and Credits

All code is licensed as MIT. See [LICENSE](LICENSE).

This project was forked from [bs-mocha](https://github.com/reasonml-community/bs-mocha) after it was abandoned.
