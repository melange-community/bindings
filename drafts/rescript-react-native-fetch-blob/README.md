# `@rescript-react-native/fetch-blob`

[![Build Status](https://github.com/rescript-react-native/fetch-blob/workflows/Build/badge.svg)](https://github.com/rescript-react-native/fetch-blob/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/fetch-blob.svg)](https://www.npmjs.com/@rescript-react-native/fetch-blob)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`rn-fetch-blob`](https://github.com/joltup/rn-fetch-blob).

Exposed as `ReactNativeFetchBlob` module.

**⚠️ Incomplete bindings!**

`@rescript-react-native/fetch-blob` X.y.\* means it's compatible with
`rn-fetch-blob` X.y.\*

## Installation

When [`rn-fetch-blob`](https://github.com/joltup/rn-fetch-blob) is properly
installed & configured by following their installation instructions, you can
install the bindings:

```console
npm install @rescript-react-native/fetch-blob
# or
yarn add @rescript-react-native/fetch-blob
```

`@rescript-react-native/fetch-blob` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/fetch-blob"
  ],
  //...
}
```

## Usage

@todo

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

## Contribute

Read the [contribution guidelines](https://github.com/rescript-react-native/.github/blob/master/CONTRIBUTING.md) before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/rescript-react-native/.github/blob/master/CODE_OF_CONDUCT.md) so that you can understand what
actions will and will not be tolerated.
