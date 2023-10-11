# rescript-clean-deep

[![NPM version](http://img.shields.io/npm/v/rescript-clean-deep.svg)](https://www.npmjs.org/package/rescript-clean-deep)
[![Build Status](https://app.travis-ci.com/mikaello/rescript-clean-deep.svg?branch=master)](https://app.travis-ci.com/github/mikaello/rescript-clean-deep)

ReScript bindings for [clean-deep](https://github.com/nunofgs/clean-deep), a library for
removing empty or nullable values from javascript objects.

## Getting started

```
yarn add rescript-clean-deep
```

Then add `rescript-clean-deep` as a dependency to `bsconfig.json`:

```diff
"bs-dependencies": [
+  "rescript-clean-deep"
]
```

## Example

```reason
open RescriptCleanDeep;

let jsObject = [%bs.raw {|
{
  bar: {},
  baz: null,
  biz: 'baz',
  foo: '',
  net: [],
  nit: undefined,
  qux: {
    baz: 'boz',
    txi: ''
  }
}
|}];

let cleaned = CleanDeep.cleanDeep(jsObject, ());

Js.log(cleaned);
/* => { biz: 'baz', qux: { baz: 'boz' } } */

let cleanedKeepStrings = jsObject->CleanDeep.cleanDeep(~emptyStrings=false, ());

Js.log(cleanedKeepStrings);
/* => { biz: 'baz', foo: '', qux: { baz: 'boz', txi: '' } } */

let cleanedCustomValues = jsObject->CleanDeep.cleanDeep(~cleanValues=[|"baz"|], ());

Js.log(cleanedCustomValues);
/* => { qux: { baz: 'boz' } } */
```

See also [example-project](./example).

## Contribute

If you find bugs or there are updates in
[clean-deep](https://github.com/nunofgs/clean-deep), feel free to open an issue
or PR. If you are upgrading any dependencies, please use yarn so `yarn.lock` is
updated.
