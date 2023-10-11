# Changelog of `@rescript-react-native/datetimepicker`

## 3.0.3 - 2021-05-03

ReScript

## 3.0.2 - 2020-12-29

- Fixed minuteInterval prop (number, not string)

## 3.0.1 - 2020-11-17

Fix npm description

## 3.0.0 - 2020-11-06

- Adjust to match react-native-datetimepicker 3.0.0
- Adjust to match with rescript-react-native 0.63

## 2.6.0 - 2020-07-27

- Adjust to match react-native-datetimepicker 2.6.0
- Adjust to match with rescript-react-native 0.62

## 2.1.0 - 2019-10-05

Initial release.

As part of the Lean Core effort, `DatePickerIOS`, `DatePickerAndroid` and
`TimePickerAndroid` are marked for removal from React Native. They have been
merged into a single component called `DateTimePicker`, which itself, has been
removed into a
[community repo](https://github.com/react-native-community/react-native-datetimepicker).
These bindings target the community package.

You may refer to the relevant
[issue](https://github.com/facebook/react-native/issues/23313) for further
information.
