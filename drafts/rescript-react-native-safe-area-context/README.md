# `@rescript-react-native/safe-area-context`

[![Build Status](https://github.com/rescript-react-native/safe-area-context/workflows/Build/badge.svg)](https://github.com/rescript-react-native/safe-area-context/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/safe-area-context.svg)](https://www.npmjs.com/@rescript-react-native/safe-area-context)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`react-native-safe-area-context`](https://github.com/th3rdwave/react-native-safe-area-context).

Exposed as `ReactNativeSafeAreaContext` module.

`@rescript-react-native/safe-area-context` X.y.\* means it's compatible with
`react-native-safe-area-context` X.y.\*

## Installation

When
[`react-native-safe-area-context`](https://github.com/th3rdwave/react-native-safe-area-context)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/safe-area-context
# or
yarn add @rescript-react-native/safe-area-context
```

`@rescript-react-native/safe-area-context` should be added to `bs-dependencies` in
your `bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/safe-area-context"
  ],
  //...
}
```

## Usage

### Types

#### `ReactNativeSafeAreaContext.insets`

```rescript
type insets = {
  top: float,
  bottom: float,
  left: float,
  right: float,
};
```

#### `ReactNativeSafeAreaContext.frame`

```rescript
type frame = {
  x: float,
  y: float,
  width: float,
  height: float,
};
```

#### `ReactNativeSafeAreaContext.metrics`

```rescript
type metrics = {
  insets,
  frame,
};
```

### Constants

#### `initialWindowMetrics`

See <https://github.com/th3rdwave/react-native-safe-area-context#optimization>

### Methods

#### `<ReactNativeSafeAreaContext.SafeAreaProvider>`

```rescript
open ReactNative;
open ReactNativeSafeAreaContext;

[@react.component]
let make = () => {
  <SafeAreaProvider /*initialMetrics={...}*/>
    // your app...
    <View />
  <SafeAreaProvider>;
}
```

See <https://github.com/th3rdwave/react-native-safe-area-context#web-ssr> for
`initialMetrics`.

#### `ReactNativeSafeAreaContext.useSafeAreaInsets(): insets`

```rescript
open ReactNative;
open ReactNativeSafeAreaContext;

[@react.component]
let make = () => {
  let insets = useSafeAreaInsets();
  <View style=Style.(style(~paddingTop=insets.top, ())) />;
}
```

#### `ReactNativeSafeAreaContext.useSafeAreaFrame(): frame`

```rescript
open ReactNative;
open ReactNativeSafeAreaContext;

[@react.component]
let make = () => {
  let frame = useSafeAreaFrame();
  <View style=Style.(style(~height=frame.height, ())) />;
}
```

#### `<ReactNativeSafeAreaContext.SafeAreaInsetsContext.Consumer>`

```rescript
open ReactNative;
open ReactNativeSafeAreaContext;

[@react.component]
let make = () => {
  <SafeAreaInsetsContext.Consumer>
    // your component, handy for classes
    {insets => <View style=Style.(style(~paddingTop=insets##top, ())) />}
  <SafeAreaInsetsContext.Consumer>;
}
```

#### `<ReactNativeSafeAreaContext.SafeAreaView>`

```rescript
open ReactNative;
open ReactNativeSafeAreaContext;

[@react.component]
let make = () => {
  <SafeAreaView>
    <View />
  <SafeAreaView>;
}
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
