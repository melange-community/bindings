# `@rescript-react-native/async-storage`

[![Build Status](https://github.com/rescript-react-native/async-storage/workflows/Build/badge.svg)](https://github.com/rescript-react-native/async-storage/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/async-storage.svg)](https://www.npmjs.com/@rescript-react-native/async-storage)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`@react-native-async-storage/async-storage`](https://github.com/react-native-async-storage/async-storage).

Exposed as `ReactNativeAsyncStorage` module.

`@rescript-react-native/async-storage` X.y.\* means it's compatible with
`@react-native-async-storage/async-storage` X.y.\*

## Installation

When
[`@react-native-async-storage/async-storage`](https://github.com/react-native-async-storage/async-storage)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/async-storage
# or
yarn add @rescript-react-native/async-storage
```

`@rescript-react-native/async-storage` should be added to `bs-dependencies` in
your `bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/async-storage"
  ],
  //...
}
```

## Usage

### Types

#### `ReactNativeAsyncStorage.asyncStorageState`

```rescript
type asyncStorageState = {
  getItem: unit => Js.Promise.t(Js.Null.t(string)),
  setItem: string => Js.Promise.t(unit),
  mergeItem: string => Js.Promise.t(unit),
  removeItem: unit => Js.Promise.t(unit),
};


 let ReactNativeAsyncStorage.{getItem, setItem} =
    ReactNativeAsyncStorage.useAsyncStorage("useAsyncStorage");
```

### Methods

#### `ReactNativeAsyncStorage.getItem`

```rescript
string => Js.Promise.t(Js.Null.t(string))
```

#### `ReactNativeAsyncStorage.setItem`

```rescript
(string, string) => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.removeItem`

```rescript
string => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.mergeItem`

```rescript
(string, string) => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.clear`

```rescript
unit => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.getAllKeys`

```rescript
unit => Js.Promise.t(Js.Null.t(array(string)))
```

#### `ReactNativeAsyncStorage.multiGet`

```rescript
array(string) => Js.Promise.t(array((string, Js.Null.t(string))))
```

#### `ReactNativeAsyncStorage.multiSet`

```rescript
array((string, string)) => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.multiMerge`

```rescript
array((string, string)) => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.multiRemove`

```rescript
array(string) => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.flushGetRequests`

```rescript
unit => unit
```

#### `ReactNativeAsyncStorage.useAsyncStorage`

```rescript
string => asyncStorageState
```

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

---

## Contribute

Read the
[contribution guidelines](https://github.com/rescript-react-native/.github/blob/master/CONTRIBUTING.md)
before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/rescript-react-native/.github/blob/master/CODE_OF_CONDUCT.md)
so that you can understand what actions will and will not be tolerated.
