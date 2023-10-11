# `@rescript-react-native/checkbox`

[![Build Status](https://github.com/rescript-react-native/checkbox/workflows/Build/badge.svg)](https://github.com/rescript-react-native/checkbox/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/checkbox.svg)](https://www.npmjs.com/@rescript-react-native/checkbox)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`@react-native-community/react-native-checkbox`](https://github.com/react-native-checkbox/react-native-checkbox).

The module will be exposed as `ReactNativeCheckbox`.

Version x.y.z of `@rescript-react-native/checkbox` is intended to be compatible
with version x.y.z of `@react-native-community/react-native-checkbox`.

## Installation

When
[`@react-native-community/react-native-checkbox`](https://github.com/react-native-checkbox/react-native-checkbox)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/checkbox
# or
yarn add @rescript-react-native/checkbox
```

`@rescript-react-native/checkbox` should be added to `bs-dependencies` in your
`bsconfig.json`. For example,

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/checkbox"
  ],
  //...
}
```

## Usage

### Types

#### `CheckBoxEvent.t`

Assuming `checkboxEvent` is `CheckBoxEvent.t`, you can access

```rescript
checkboxEvent.nativeEvent.target // => int
checkboxEvent.nativeEvent.value // => bool
```

`value` represents value of the checkbox as updated by the event.

#### `element`

Type to be used in `ref` and with `NativeMethods`, as with other components in
React Native bindings.

#### `ref`

is an alias for `React.Ref.t(Js.nullable(element))`.

### CheckBox common props

All props are optional.

#### `value: bool`

Value of the checkbox. When `true`, checkbox will be checked. Default value is
`false`.

#### `onChange: checkBoxEvent => unit`

Returns a [native event](#checkBoxEvent).

#### `onValueChange`

Returns the new `bool` value.

#### `testID: string`

Used to locate this view in end-to-end tests.

### CheckBox Android props

#### `disabled: bool`

When `true`, user will not be able to toggle the checkbox. Default value is
`false`.

#### `tintColors`

```rescript
tintColors:
  (~_true: int=?, ~_false: int=?, unit) => tintColors
```

Value for `_true` will be used when the checkbox is checked, and value for
`_false` will be used when it is not checked.

### CheckBox iOS props

#### `lineWidth: float`

The width of the lines of the check mark and box. Defaults to `2.0`.

#### `hideBox: bool`

Control if the box should be hidden or not. Defaults to `false`

#### `` boxType: `circle or `square ``

The type of box to use. Defaults to `` `circle ``

#### `tintColor: Color.t`

The color of the box when the checkbox is Off. Defaults to `#aaaaaa`

#### `onCheckColor: Color.t`

The color of the check mark when it is On. Defaults to `#007aff`

#### `onFillColor: Color.t`

The color of the inside of the box when it is On. Defaults to transparent

#### `onTintColor: Color.t`

The color of the line around the box when it is On. Defaults to `#007aff`

#### `animationDuration: float`

The duration in seconds of the animations. Defaults to 0.5

#### `` onAnimationType: `stroke or `fill or `bounce or `flat or `oneStroke or `fade ``

The type of animation to use when the checkbox gets checked. Defaults to
`` `stroke ``

#### `` offAnimationType: `stroke or `fill or `bounce or `flat or `oneStroke or `fade ``

The type of animation to use when the checkbox gets unchecked. Defaults to
`` `stroke ``

### `View` props

Refer to
[`rescript-react-native`](https://github.com/rescript-react-native/react-native)
[documentation](https://rescript-react-native.github.io/en/docs/components/View/).

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more information about recent
releases.

## Contribute

Read the [contribution guidelines](https://github.com/rescript-react-native/.github/blob/master/CONTRIBUTING.md) before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/rescript-react-native/.github/blob/master/CODE_OF_CONDUCT.md) so that you can understand what
actions will and will not be tolerated.
