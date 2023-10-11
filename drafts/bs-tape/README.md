# bs-tape

[![CircleCI](https://circleci.com/gh/jeffreywescott/bs-tape.svg?style=svg)](https://circleci.com/gh/jeffreywescott/bs-tape) [![Coverage Status](https://coveralls.io/repos/github/jeffreywescott/bs-tape/badge.svg?branch=master)](https://coveralls.io/github/jeffreywescott/bs-tape?branch=master)

[BuckleScript][BuckleScript] bindings for [tape][tape].

There were already [bindings][bs-jest] for [jest][jest], but I find Jest to be pretty annoying to use, and a bit "too magical". So, I made this one.

Please be warned that I'm new to ReasonML / BuckleScript / OCaml, so there may be things herein that are non-idiomatic. PRs encouraged and welcomed!

## Getting Started

First, install the package:

```
yarn add --dev bs-tape
```

Then, add `bs-tape` to your `bs-dev-dependencies` in your `bsconfig.json`:

```javascript
{
  // ...
  "bs-dev-dependencies": [
    // ...
    "bs-tape"
  ],
  // ...
}
```

## Known Limitations and Differences from [tape][tape]

- `equal` has been decomposed into typesafe: `equalStr`, `equalInt`, and `equalFloat`
- `endTest` replaces `end` (which is a reserved keyword)
- `end` has been decomposed into typesafe: `endTest` and `endTestIfNoErr`
- Given that "arbitrarily shaped" data structures are non-idiomatic in ReasonML (and OCaml), the following tape assertions are not supported, but can be effectively simulated by creating the appropriate expression with the `==` and `!` operators, then invoking the `ok` assertion.
  - `deepEqual`
  - `notDeepEqual`
  - `deepLooseEqual`
  - `notDeepLooseEqual`

## License

ISC. See the [LICENSE](./LICENSE) file.

<!-- links -->
[BuckleScript]: https://bucklescript.github.io/
[tape]: https://github.com/substack/tape
[bs-jest]: https://github.com/glennsl/bs-jest
[jest]: https://github.com/facebook/jest