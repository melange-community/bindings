# rescript-anymatch

ReScript bindings for [anymatch](https://github.com/micromatch/anymatch)

## Installation

```sh
npm i rescript-anymatch
```

In your `bsconfig.json` add it to `bs-dependencies`

```
{
  ...,
  "bs-dependencies": [..., "rescript-anymatch"],
}
```

## Examples

```rescript
let matchers = [
  Anymatch.path("path/to/file.js"),
  Anymatch.glob("path/anyjs/**/*.js"),
  Anymatch.regex(%re("/foo.js$/")),
  Anymatch.fun(s => s->Js.String2.includes("bar") && s->Js.String2.length > 10),
]

Anymatch.anymatch(matchers, "path/to/file.js")->Js.log // true
Anymatch.anymatch(matchers, "path/anyjs/baz.js")->Js.log // true
Anymatch.anymatch(matchers, "path/to/foo.js")->Js.log // true
Anymatch.anymatch(matchers, "path/to/bar.js")->Js.log // true
Anymatch.anymatch(matchers, "bar.js")->Js.log // false

Anymatch.anymatchIndex(matchers, "foo.js")->Js.log // 2
Anymatch.anymatchIndex(matchers, "path/anyjs/foo.js")->Js.log // 1

// currying

let match = Anymatch.anymatch(matchers)
match("path/to/file.js")->Js.log // true

// options

Anymatch.anymatch(~options=Picomatch.options(~dot=true, ()), matchers, "path/anyjs/.baz.js")->Js.log // true
```

## Caveats

The original library can accept an array instead of a string as a match target. Here's what it does in that case:

> If passed as an array, the first element of the array will be used as the testString for non-function matchers, while the entire array will be applied as the arguments for function matchers.

This is difficult to define with ReScript. If you need this feature open an issue and let's discuss the options.

---

With the original library you can create a `match` function `const match = anymatch(matchers)` and then at the call time of that functions decide whether you want `index` or `boolean` as the return value. With these bindings you'll have to create two separate functions.

I didn't find a good way to support this edge-case without making normal use more difficult.
