# `@rescript-react-native/slider`

[![Build Status](https://github.com/rescript-react-native/slider/workflows/Build/badge.svg)](https://github.com/rescript-react-native/slider/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/slider.svg)](https://www.npmjs.com/@rescript-react-native/slider)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`@react-native-community/slider`](https://github.com/callstack/react-native-slider).

Exposed as `ReactNativeSlider` module.

`@rescript-react-native/slider` X.y.\* means it's compatible with
`@react-native-community/slider` X.y.\*

## Installation

When
[`@react-native-community/slider`](https://github.com/callstack/react-native-slider)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/slider
# or
yarn add @rescript-react-native/slider
```

`@rescript-react-native/slider` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/slider"
  ],
  //...
}
```

## Usage

```rescript
ReactNativeSlider.make(
  ~style: ReactNative.Style.t=?,
  ~value: float=?,
  ~step: float=?,
  ~minimumValue: float=?,
  ~maximumValue: float=?,
  ~minimumTrackTintColor: string=?,
  ~maximumTrackTintColor: string=?,
  ~disabled: bool=?,
  ~onSlidingStart: float => unit=?,
  ~onSlidingComplete: float => unit=?,
  ~onValueChange: float => unit=?,
  ~testID: string=?,
  ~children: React.element=?,
  // iOS Props
  ~maximumTrackImage: ReactNative.Image.Source.t=?,
  ~minimumTrackImage: ReactNative.Image.Source.t=?,
  ~thumbImage: ReactNative.Image.Source.t=?,
  ~trackImage: ReactNative.Image.Source.t=?,
  ~inverted: bool=?,
  // Android
  ~thumbTintColor: string=?

  // ... And all <View> props
)
```

### Example

```rescript
<ReactNativeSlider
  style={
    ReactNative.Style.(
      style(
        ~width=200.->dp,
        ~height=40.->dp,
        ()
      )
    )
  }
  minimumValue={0.}
  maximumValue={1.}
  minimumTrackTintColor="#FFFFFF"
  maximumTrackTintColor="#000000"
/>
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
