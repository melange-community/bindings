# Changelog of `@rescript-react-native/netinfo`

## 5.9.2 - 2021-05-03

ReScript

## 5.9.1 - 2020-11-17

Fix npm description

## 5.9.0 - 2020-11-06

- 5.9.0 compat

## 5.6.1 - 2020-11-06

rescript 8.2 compat

## 5.6.0

- `fetchInterface` method added
- `reachabilityRequestTimeout` field added to `netInfoConfiguration`

## 5.3.0

- `Legacy` module removed, to mirror removal of deprecated API
- `configure` method and `netInfoConfiguration` type added
- fields added to `netInfoState` and `details` types

## 4.1.0

### Breaking Changes

- Moved from
  [sgny/rescript-react-native-netinfo](https://github.com/sgny/rescript-react-native-netinfo#readme).
  `npm` package was previously named `rescript-react-native-netinfo`. Please
  update your dependencies accordingly. You may update your existing code using
  the `NetInfo` module of `rescript-react-native` by replacing references to the
  `ReactNative.NetInfo` module with `ReactNativeNetInfo.Legacy`. However, do
  note that the new API is more straightforward.

- The module is renamed to `ReactNativeNetInfo` (previously`CommunityNetInfo`).

- Releases require use of [jetifier](https://github.com/mikehardy/jetifier) for
  versions 0.59.x of React Native. You may continue to use
  [`rescript-react-native-netinfo`](https://www.npmjs.com/package/rescript-react-native-netinfo)
  version 3.2.x if you do not wish to use `jetifier`.

## 3.x

See
[sgny/rescript-react-native-netinfo](https://github.com/sgny/rescript-react-native-netinfo/tree/3.2.4])
