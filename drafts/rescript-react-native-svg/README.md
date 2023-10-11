# `@rescript-react-native/svg`

[![Build Status](https://github.com/rescript-react-native/svg/workflows/Build/badge.svg)](https://github.com/rescript-react-native/svg/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/svg.svg)](https://www.npmjs.com/@rescript-react-native/svg)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`react-native-svg`](https://github.com/react-native-community/react-native-svg).

Exposed as `ReactNativeSvg` module.

`@rescript-react-native/svg` X.y.\* means it's compatible with `react-native-svg`
X.y.\*

## Installation

When
[`react-native-svg`](https://github.com/react-native-community/react-native-svg)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/svg
# or
yarn add @rescript-react-native/svg
```

`@rescript-react-native/svg` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/svg"
  ],
  //...
}
```

## Usage

Supported :

- SvgXml
- SvgCss
- Svg
- Rect
- Circle
- Ellipse
- Line
- Polygon
- Polyline
- Path
- Text
- TextPath
- Tspan
- Use
- G
- Symbol
- Defs
- Image
- ClipPath
- LinearGradient
- Stop
- RadialGradient
- Mask
- Pattern
- Marker
- ForeignObject

See [definition](.src/ReactNativeSvg.re) for more details.

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
