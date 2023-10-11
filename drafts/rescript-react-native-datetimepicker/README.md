# `@rescript-react-native/datetimepicker`

[![Build Status](https://github.com/rescript-react-native/datetimepicker/workflows/Build/badge.svg)](https://github.com/rescript-react-native/datetimepicker/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/datetimepicker.svg)](https://www.npmjs.com/@rescript-react-native/datetimepicker)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`@react-native-community/datetimepicker`](https://github.com/react-native-community/react-native-datetimepicker).

Exposed as the `ReactNativeDateTimePicker` module.

Version x.y.z of `@rescript-react-native/datetimepicker` is intended to be
compatible with version x.y.z of `@react-native-community/datetimepicker`.

## Installation

When
[`@react-native-community/datetimepicker`](https://github.com/react-native-community/datetimepicker)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/datetimepicker
# or
yarn add @rescript-react-native/datetimepicker
```

`@rescript-react-native/datetimepicker` should be added to `bs-dependencies` in
your `bsconfig.json`. For example,

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/datetimepicker"
  ],
  //...
}
```

## Usage

### Types

#### `locale = string`

Refer to
[documentation](https://developer.apple.com/library/archive/documentation/MacOSX/Conceptual/BPInternational/LanguageandLocaleIDs/LanguageandLocaleIDs.html)
for valid values.

#### `PickerEvent.t`

Assuming `pickerEvent` is `PickerEvent.t`, you can access

```rescript
pickerEvent.nativeEvent.target // => option(int)
pickerEvent.nativeEvent.timestamp // => int
```

Note that `target` is undefined on Android.

### Props

All props other than `value` are optional.

#### `value: Js.Date.t`

_required_

Current value for time and date.

#### `maximumDate: Js.Date.t`

Latest date that can be selected. For example
`maximumDate = Js.Date.makeWithYMD(2020., 10., 15., ())`. Note that months are
numbered from `0`.

#### `minimumDate: Js.Date.t`

Earliest date that can be selected. For example
`minimumDate = Js.Date.makeWithYMD(2015., 0., 18., ())`. Note that months are
numbered from `0`.

#### `` mode: [ | `date | `time | `datetime | `countdown] ``

Type of the picker. Note that

- `` `date `` is the default
- `` `datetime `` and `` `countdown `` are iOS only

#### `` display: [ | `default | `spinner | `calendar | `clock] ``

_Android only_

How the picker is displayed. Note that

- \`calendar is only for `` mode=`date ``
- \`clock is only for `` mode=`time ``

#### `onChange: (pickerEvent, Js.Date.t) => unit`

- `pickerEvent` has keys `nativeEvent` on both platforms and also `_type` on
  Android.

- _Android:_ `_type` key takes value `"set"` (when the dialog is closed via
  "OK") or `"dismissed"` (when the dialog is closed via "cancel").

#### `timeZoneOffsetInMinutes: int`

_iOS only_

Allows changing time zone of the date picker. By default device's time zone is
used. As an example, set to `60` for GMT+1.

#### `locale: locale`

_iOS only_

Allows changing locale of the component. By default device's locale is used.

Refer to
[documentation](https://developer.apple.com/library/archive/documentation/MacOSX/Conceptual/BPInternational/LanguageandLocaleIDs/LanguageandLocaleIDs.html)
for valid values.

#### `is24Hour: bool`

_Android only._

Allows changing of the time picker to a 24 hour format. Default is false.

#### `minuteInterval: [ |`\_1 | `_2 |`\_3 | `_4 |`\_5 | `_6 |`\_10 | `_12 |`\_15 | `_20 |`\_30 ]`

_iOS only._

Interval at which minutes can be selected. Polymorphic constructors are rendered
to string (that is `` `_3 `` becomes `"3"`).

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
