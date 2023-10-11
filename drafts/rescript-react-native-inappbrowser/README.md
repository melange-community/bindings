# `@rescript-react-native/inappbrowser`

[![Build Status](https://github.com/rescript-react-native/inappbrowser/workflows/Build/badge.svg)](https://github.com/rescript-react-native/inappbrowser/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/inappbrowser.svg)](https://www.npmjs.com/@rescript-react-native/inappbrowser)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`react-native-inappbrowser-reborn`](https://github.com/proyecto26/react-native-inappbrowser).

Exposed as `ReactNativeInAppBrowser` module.

`@rescript-react-native/inappbrowser` X.y.\* means it's compatible with
`react-native-inappbrowser-reborn` X.y.\*

## Installation

When
[`react-native-inappbrowser-reborn`](https://github.com/proyecto26/react-native-inappbrowser)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/inappbrowser
# or
yarn add @rescript-react-native/inappbrowser
```

`@rescript-react-native/inappbrowser` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/inappbrowser"
  ],
  //...
}
```

## Usage

```rescript
open Js.Promise;
open ReactNativeInAppBrowser;

let opts = iosOptions(~preferredBarTintColor="#ff0000", ());
openBrowser("https://rescript-lang.org", `IosOptions(opts))
|> Js.Promise.then_((result: browserResult) => {
     Js.log(result.resultType);
     resolve();
   })
|> ignore;
```

```rescript
open Js.Promise;
open ReactNativeInAppBrowser;

openAuthIos("https://example.com/auth", "myschema://auth", `IosOptions(iosOptions()))
|> Js.Promise.then_((result: authResult) => {
     switch (result.url) {
       | Some(url) => Js.log(url)
       | None => Js.log("Something went wrong")
     };
     resolve();
   })
|> ignore;
```

### Types

#### `authResult`

#### `browserResult`

#### `iosOptions`

#### `androidOptions`

### Methods

#### `ReactNativeInAppBrowser.openBrowser`

```rescript
(string,  [ `AndroidOptions(androidOptions) | `IosOptions(iosOptions) ]) => Js.Promise.t(browserResult)
```

#### `ReactNativeInAppBrowser.close`

```rescript
unit => unit
```

#### `ReactNativeInAppBrowser.openAuth`

```rescript
(string, [ `AndroidOptions(androidOptions) | `IosOptions(iosOptions) ]) => Js.Promise.t(authResult)
```

#### `ReactNativeInAppBrowser.closeAuth`

```rescript
unit => unit
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
