# rescript-react-hooks

Better hooks for rescript-react.

[![npm](https://img.shields.io/npm/v/@glennsl/rescript-react-hooks.svg)](https://npmjs.org/@glennsl/rescript-react-hooks)
[![Issues](https://img.shields.io/github/issues/glennsl/rescript-react-hooks.svg)](https://github.com/glennsl/rescript-react-hooks/issues)
[![Last Commit](https://img.shields.io/github/last-commit/glennsl/rescript-react-hooks.svg)](https://github.com/glennsl/rescript-react-hooks/commits/master)

This replaces most hooks that come with rescript-react with improved versions. More specifically, it provides:

- Both lazy and non-lazy versions of state hooks
- Hooks that trigger when dependencies change can be passed a custom equality function.
- Dependencies are compareed using structural equality by default, as you'd expect.
- Properly named effect hooks that don't require guessing their behaviour based on seemingly arbitrary numberical suffixes.
- More ergonomic and idiomatic API design, using optional arguments instead of idioms designed for dynamic typing.
- A `useResource` hook tailored for managing resources.

## Example

```reason
Hooks.useEffectOnce(() => Js.log("mounted"))
Hooks.useEffectAlways(~beforeRender=true, () => Js.log("about to render"))
Hooks.useEffectAlways(() => Js.log("rendered"))

// Use custom euqlity function to ignore nulls
Hooks.useEffect(
  () => Js.log2("Got element", elRef.current),
  ~equal=(a, b) => b.current == Js.Nullable.null || a == b,
  ~on=elRef,
)

// setTiemout returns a timerId that will be passed to clearTiemout on release
Hooks.useResource(
  ~on=tickEnabled,
  () => Js.Global.setTimeout(() => Js.log("tick"), 1000),
  ~release=Js.Global.clearTimeout,
)
```

## Installation

```sh
npm install --save @glennsl/rescript-react-hooks
```

Then add `@glennsl/rescript-react-hooks` to `bs-dependencies` in your `bsconfig.json`:

```js
{
  ...
  "bs-dependencies": ["@glennsl/rescript-react-hooks"]
}
```

## Documentation

See doc comments in [`Hooks.resi`](https://github.com/glennsl/rescript-react-hooks/blob/master/src/Hooks.resi)

## License

This work is dual-licensed under LGPL 3.0 and MPL 2.0.
You can choose between one of them if you use this work.
Please see [LICENSE.LGPL-3.0](https://github.com/glennsl/rescript-react-hooks/blob/master/LICENSE.LGPL-3.0)
and [LICENSE.MPL-2.0](https://github.com/glennsl/rescript-react-hooks/blob/master/LICENSE.MPL-2.0) for the full text of each license.
`SPDX-License-Identifier: LGPL-3.0 OR MPL-2.0`

## Changes

### 1.0.0
- Initial release
