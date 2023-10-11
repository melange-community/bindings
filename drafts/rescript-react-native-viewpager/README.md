# `@rescript-react-native/viewpager`

[![Build Status](https://github.com/rescript-react-native/viewpager/workflows/Build/badge.svg)](https://github.com/rescript-react-native/viewpager/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/viewpager.svg)](https://www.npmjs.com/@rescript-react-native/viewpager)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`@react-native-community/viewpager`](https://github.com/callstack/react-native-viewpager).

Exposed as `ReactNativeViewPager` module.

`@rescript-react-native/viewpager` X.y.\* means it's compatible with
`@react-native-community/viewpager` X.y.\*

## Installation

When
[`@react-native-community/viewpager`](https://github.com/callstack/react-native-viewpager)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/viewpager
# or
yarn add @rescript-react-native/viewpager
```

`@rescript-react-native/viewpager` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/viewpager"
  ],
  //...
}
```

## Usage

```rescript
[@react.component]
let app = () =>
    <SafeAreaView style={styles##body}>
      <ReactNativeViewPager style={styles##body}
        initialPage=1
        pageMargin=13
        transitionStyle={`curl}
        showPageIndicator=true
        >
        <View style={styles##red}/>
        <View style={styles##blue}/>
        <View style={styles##green}/>
      </ReactNativeViewPager>
    </SafeAreaView>;
```

#### `ReactNativeViewPager` props

```rescript
~ref: ref=?,
~initialPage: int=?,
~scrollEnabled: bool=?,
~onPageScroll: PageScrollEvent.t => unit=?,
~onPageSelected: PageSelectedEvent.t => unit=?,
~onPageScrollStateChanged: PageScrollStateChangedEvent.t => unit=?,
~keyboardDismissMode: [@bs.string] [ | `none | [@bs.as "on-drag"] `onDrag]=?,
~pageMargin: int=?,
~onMoveShouldSetResponderCapture: ReactNative.Event.pressEvent => bool=?,
~style: ReactNative.Style.t=?,
~children: React.element=?,
~orientation: [@bs.string] [ | `horizontal | `vertical]=?,
~transitionStyle: [@bs.string] [ | `scroll | `curl]=?,
~showPageIndicator: bool=?
```

### Methods

#### `ReactNativeViewPager.setPage`

```rescript
setPage: (T.t, int) => unit = "setPage";
```

#### `ReactNativeViewPager.setPage`

```rescript
setPageWithoutAnimation: (T.t, int) => unit =
    "setPageWithoutAnimation";
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
