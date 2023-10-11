# `@rescript-react-native/push-notification-ios`

[![Build Status](https://github.com/rescript-react-native/push-notification-ios/workflows/Build/badge.svg)](https://github.com/rescript-react-native/push-notification-ios/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/push-notification-ios.svg)](https://www.npmjs.com/@rescript-react-native/push-notification-ios)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`@react-native-community/react-native-push-notification-ios`](https://github.com/react-native-push-notification-ios/push-notification-ios).

Exposed as `ReactNativePushNotificationIOS` module.

`@rescript-react-native/push-notification-ios` X.y.\* means it's compatible with
`@react-native-community/react-native-push-notification-ios` X.y.\*

## Installation

When
[`@react-native-community/react-native-push-notification-ios`](https://github.com/react-native-push-notification-ios/push-notification-ios)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/push-notification-ios
# or
yarn add @rescript-react-native/push-notification-ios
```

`@rescript-react-native/push-notification-ios` should be added to
`bs-dependencies` in your `bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/push-notification-ios"
  ],
  //...
}
```

## Usage

### Types

#### `ReactNativePushNotificationIOS.Notification.t`

```rescript
  type t; // abstract type
```

#### `ReactNativePushNotificationIOS.localNotification`

```rescript
type localNotification;

[@bs.obj]
external localNotification:
  (
    ~alertBody: string=?,
    ~alertTitle: string=?,
    ~alertAction: string=?,
    ~soundName: string=?,
    ~isSilent: bool=?,
    ~category: string=?,
    ~userInfo: Js.Json.t=?,
    ~applicationIconBadgeNumber: int=?,
    ~fireDate: Js.Date.t=?,
    ~repeatInterval: [@bs.string] [
                       | `minute
                       | `hour
                       | `day
                       | `week
                       | `month
                       | `year
                     ]
                       =?,
    unit
  ) =>
  localNotification =
  "";
```

#### `ReactNativePushNotificationIOS.deliveredNotification`

```rescript
type deliveredNotification = {
  identifier: string
  date: option(string)
  title: option(string)
  body: option(string)
  category: option(string)
  threadId: option(string)
  userInfo: option(Js.Json.t),
};
```

#### `ReactNativePushNotificationIOS.formattedLocalNotification`

```rescript
type formattedLocalNotification = {
  fireDate: option(string),
  alertAction: option(string),
  alertTitle: option(string),
  alertBody: option(string),
  applicationIconBadgeNumber: option(int),
  category: option(string),
  repeatInterval: option(string),
  soundName: option(string),
  userInfo: option(Js.Json.t),
};
```

#### `ReactNativePushNotificationIOS.registrationError`

```rescript
type registrationError('a) = {
  message: string,
  code: int,
  details: Js.t('a),
};
```

#### `ReactNativePushNotificationIOS.permissions`

```rescript
type permissions = {
  alert: bool,
  badge: bool,
  sound: bool,
  lockScreen: bool,
  notificationCenter: bool,
};
```

#### `ReactNativePushNotificationIOS.requestPermissionsOptions`

```rescript
type requestPermissionsOptions;
[@bs.obj]
external requestPermissionsOptions:
  (~alert: bool=?, ~badge: bool=?, ~sound: bool=?, unit) =>
  requestPermissionsOptions =
  "";
```

#### `ReactNativePushNotificationIOS.fetchResult`

```rescript
type fetchResult;
[@bs.obj]
external fetchResult:
  (~_NewData: string=?, ~_NoData: string=?, ~_ResultFailed: string=?, unit) =>
  fetchResult =
  "";
```

### Methods

#### `ReactNativePushNotificationIOS.Notification.getAlert`

```rescript
Notification.t => option(Js.Json.t)
```

#### `ReactNativePushNotificationIOS.Notification.getTitle`

```rescript
Notification.t => option(string)
```

#### `ReactNativePushNotificationIOS.Notification.getMessage`

```rescript
Notification.t => option(Js.Json.t)
```

#### `ReactNativePushNotificationIOS.Notification.getSound`

```rescript
Notification.t => option(string)
```

#### `ReactNativePushNotificationIOS.Notification.getCategory`

```rescript
Notification.t => option(string)
```

#### `ReactNativePushNotificationIOS.Notification.getContentAvailable`

```rescript
Notification.t => bool
```

#### `ReactNativePushNotificationIOS.Notification.getBadgeCount`

```rescript
Notification.t => option(int)
```

#### `ReactNativePushNotificationIOS.Notification.getData`

```rescript
Notification.t => option(Js.Json.t)
```

#### `ReactNativePushNotificationIOS.Notification.getThreadID`

```rescript
Notification.t => option(string)
```

#### `ReactNativePushNotificationIOS.presentLocalNotification`

```rescript
localNotification => unit
```

#### `ReactNativePushNotificationIOS.scheduleLocalNotification`

```rescript
localNotification => unit
```

#### `ReactNativePushNotificationIOS.cancelAllLocalNotifications`

```rescript
unit => unit
```

#### `ReactNativePushNotificationIOS.removeAllDeliveredNotifications`

```rescript
unit => unit
```

#### `ReactNativePushNotificationIOS.getDeliveredNotifications`

```rescript
(array(deliveredNotification) => unit)
```

#### `ReactNativePushNotificationIOS.removeDeliveredNotifications`

```rescript
(~identifiers: array(string)) => unit
```

#### `ReactNativePushNotificationIOS.setApplicationIconBadgeNumber`

```rescript
int => unit
```

#### `ReactNativePushNotificationIOS.getApplicationIconBadgeNumber`

```rescript
(int => unit) => unit
```

#### `ReactNativePushNotificationIOS.cancelLocalNotifications`

```rescript
unit => unit
```

#### `ReactNativePushNotificationIOS.cancelLocalNotificationsWithUserInfo`

```rescript
Js.Json.t => unit
```

#### `ReactNativePushNotificationIOS.getScheduledLocalNotifications`

```rescript
(array(formattedLocalNotification) => unit) => unit
```

#### `ReactNativePushNotificationIOS.addEventListener`

```rescript
  (
  [@bs.string]
  [
    | `notification(Notification.t => unit)
    | `localNotification(Notification.t => unit)
    | `register((~deviceToken: string) => unit)
    | `registrationError(registrationError('a) => unit)
  ]
  ) =>
  unit
```

#### `ReactNativePushNotificationIOS.removeEventListener`

```rescript
(
  [@bs.string]
  [
    | `notification(Notification.t => unit)
    | `localNotification(Notification.t => unit)
    | `register((~deviceToken: string) => unit)
    | `registrationError(registrationError('a) => unit)
  ]
  ) =>
  unit
```

#### `ReactNativePushNotificationIOS.requestPermissions`

```rescript
unit => Js.Promise.t(permissions)
```

#### `ReactNativePushNotificationIOS.requestPermissionsWithOptions`

```rescript
requestPermissionsOptions => Js.Promise.t(permissions)
```

#### `ReactNativePushNotificationIOS.abandonPermissions`

```rescript
unit => unit
```

#### `ReactNativePushNotificationIOS.checkPermissions`

```rescript
(unit => permissions) => unit
```

#### `ReactNativePushNotificationIOS.finish`

```rescript
fetchResult => unit
```

#### `ReactNativePushNotificationIOS.getInitialNotification`

```rescript
unit => Js.Promise.t(Js.Nullable.t(Notification.t))
```

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
