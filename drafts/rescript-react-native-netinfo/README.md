# `@rescript-react-native/netinfo`

[![Build Status](https://github.com/rescript-react-native/netinfo/workflows/Build/badge.svg)](https://github.com/rescript-react-native/netinfo/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/netinfo.svg)](https://www.npmjs.com/@rescript-react-native/netinfo)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`@react-native-community/netinfo`](https://github.com/react-native-netinfo/react-native-netinfo).

Exposed as `ReactNativeNetInfo` module.

`@rescript-react-native/netinfo` X.y.\* means it's compatible with
`@react-native-community/netinfo` X.y.\*

## Installation

When
[`@react-native-community/netinfo`](https://github.com/react-native-netinfo/react-native-netinfo)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/netinfo
# or
yarn add @rescript-react-native/netinfo
```

`@rescript-react-native/netinfo` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/netinfo"
  ],
  //...
}
```

## Usage

### Types

#### `netInfoConfiguration`

To be used only when the platform does not natively supply information on
internet reachability.

| Property                     | Type               | Description                                                                                                                                                                |
| ---------------------------- | ------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `reachabilityUrl`            | `string`           | URL used to test if the internet is reachable.                                                                                                                             |
| `reachabilityTest`           | `response => bool` | A function to handle the `response` object returned when the reachability URL is called. It should return `true` if the response indicates that the internet is reachable. |
| `reachabilityShortTimeout`   | `float`            | Number of seconds between internet reachability checks when the internet was not previously detected.                                                                      |
| `reachabilityLongTimeout`    | `float`            | Number of seconds between internet reachability checks when the internet was previously detected.                                                                          |
| `reachabilityRequestTimeout` | `float`            | Number of milliseconds allowed before reachability check fails.                                                                                                            |

#### `netInfoStateType`

Kind of the current network connection. Valid values are:

| Value       | Platforms             | Connection State |
| ----------- | --------------------- | ---------------- |
| `none`      | Android, iOS, Windows | Not active       |
| `unknown`   | Android, iOS, Windows | Undetermined     |
| `cellular`  | Android, iOS, Windows | Active           |
| `wifi`      | Android, iOS, Windows | Active           |
| `bluetooth` | Android               | Active           |
| `ethernet`  | Android, Windows      | Active           |
| `wimax`     | Android               | Active           |
| `vpn`       | Android               | Active           |
| `other`     | Android, iOS, Windows | Active           |

#### `netInfoCellularGeneration`

Cellular generation of the current network connection. Valid values are:

| Value   | Notes                                                                               |
| ------- | ----------------------------------------------------------------------------------- |
| `net2g` | Inlined as "2g". Returned for CDMA, EDGE, GPRS and IDEN connections                 |
| `net3g` | Inlined as "3g". Returned for EHRPD, EVDO, HSPA, HSUPA, HSDPA and UTMS connections. |
| `net4g` | Inlined as "4g". Returned for HSPAP and LTE connections                             |

#### `netInfoState`

```rescript
type netInfoState = {
  .
  "_type": netInfoStateType,
  "isConnected": bool,
  "isInternetReachable": bool,
  "isWifiEnabled": bool,
  "details": Js.Null.t(details),
};
```

- `isConnected` will be `true` if there is an active connection (but not imply
  that the internet is necessarily reachable).
- `isInternetReachable` will be `true` if the internet can be reached using the
  active connection
- `isWifiEnabled` will be `true` if WiFi is enabled on the device, and `false`
  otherwise. _Android only_.

`details` key will have value `Js.Null.empty` (`null`) when `_type` is `null` or
`unknown`.

#### `details`

`details` depends on `_type` given within [`netInfoState`](#netInfoState). If
`_type` is not `null` or `unknown`, `details` is an object as below:

```rescript
type details = {
  .
  "isConnectionExpensive": bool,
  "ssid": Js.Nullable.t(string),
  "strength": Js.Nullable.t(int),
  "ipAddress": Js.Nullable.t(string),
  "subnet": Js.Nullable.t(string),
  "cellularGeneration": Js.Nullable.t(netInfoCellularGeneration),
  "carrier": Js.Nullable.t(string),
};
```

| Property                | Platform              | Type   | Description                                                                         |
| ----------------------- | --------------------- | ------ | ----------------------------------------------------------------------------------- |
| `isConnectionExpensive` | Android, iOS, Windows | `bool` | If network connection is considered _expensive_ in either energy or monetary terms. |

Note that some keys may only exist in the JS object when `_type` is `wifi` or
`cellular`. Accordingly, in Reason, keys may have values
`Js.Nullable.undefined`.

- `ssid`, `strength`, `ipAddress` and `subnet` will have value
  `Js.Nullable.undefined` unless `_type` is `wifi`.
- `cellularGeneration` and `carrier` will have value `Js.Nullable.undefined`
  unless `_type` is cellular.

##### `_type` is `wifi`

| Property    | Platform                | Type                    | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| ----------- | ----------------------- | ----------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| `ssid`      | Android, iOS (not tvOS) | `Js.Nullable.t(string)` | SSID of the network. May have value `Js.Nullable.undefined`, `Js.Nullable.null`, or be an empty string if undetermined. **On iOS, make sure your app meets at least one of the [following requirements](https://developer.apple.com/documentation/systemconfiguration/1614126-cncopycurrentnetworkinfo?language=objc#discussion). On Android, make sure the `ACCESS_FINE_LOCATION` permission is listed in `AndroidManifest.xml` and accepted by the user**. |
| `strength`  | Android                 | `Js.Nullable.t(string)` | If signal strength can be determined, will be an integer number from `0` to `5`. May have value `Js.Nullable.undefined` otherwise.                                                                                                                                                                                                                                                                                                                           |
| `ipAddress` | Android, iOS            | `Js.Nullable.t(string)` | External IP address. Can be in IPv4 or IPv6 format. May have value `Js.Nullable.undefined` if undetermined.                                                                                                                                                                                                                                                                                                                                                  |
| `subnet`    | Android, iOS            | `Js.Nullable.t(string)` | The subnet mask in IPv4 format. May have value `Js.Nullable.undefined` if undetermined.                                                                                                                                                                                                                                                                                                                                                                      |

##### `type` is `cellular`

| Property             | Platform              | Type                                                      | Description                                                                                                                                                                         |
| -------------------- | --------------------- | --------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `cellularGeneration` | Android, iOS, Windows | [`NetInfoCellularGeneration`](#netinfocellulargeneration) | Generation of cell network the user is connected to. This can give an indication of speed, but no guarantees. May have value `Js.Nullable.null` if generation cannot be determined. |
| `carrier`            | Android, iOS          | `string`                                                  | The network carrier name. May have value `Js.Nullable.undefined` or may be empty if undetermined.                                                                                   |

### Methods

#### `configure`

```rescript
configure: netInfoConfiguration => unit
```

#### `fetch`

To query state of the active connection, returns `netInfoState` wrapped in a
`Promise`.

```rescript
fetch: unit => Js.Promise.t(netInfoState)
```

Below example demonstrates determination of the cellular connection generation,
using this method.

```rescript
React.useEffect0(() => {
  Js.Promise.(
    ReactNativeNetInfo.fetch()
    |> then_(w =>
         {
           switch (w##details->Js.Null.toOption) {
           | None => "Connection type is none or unknown"->Js.Console.warn
           | Some(x) =>
             let y = x##cellularGeneration;
             switch (y->Js.Nullable.toOption) {
             | None =>
               if (y == Js.Nullable.undefined) {
                 "Connection type is wifi, bluetooth, ethernet, wimax, vpn or other"
                 ->Js.Console.warn;
               } else {
                 "Connection generation unknown"->Js.Console.warn;
               }
             | Some(z) =>
               if (z == ReactNativeNetInfo.net2G) {
                 "2G connection"->Js.Console.warn;
               } else if (z == ReactNativeNetInfo.net3G) {
                 "3G connection"->Js.Console.warn;
               } else {
                 "4G connection"->Js.Console.warn;
               }
             };
           };
         }
         ->resolve
       )
    |> catch(err => "error"->Js.Console.warn->resolve)
    |> ignore
  );
  None;
});
```

#### `fetchInterface`

To query the connection state for a particular interface.

```rescript
fetchInterface: [ | `cellular | `ethernet | `wifi] => Js.Promise.t(netInfoState)
```

#### `addEventListener`

To subscribe to the connection state; accepts a listener of type
`netInfoState => unit` and returns an unsubscribe method of type `unit => unit`.
The listener will be called once following subscription and each time connection
state changes.

```rescript
addEventListener: (netInfoState => unit) => t
```

where

```rescript
type t = unit => unit
```

Below example demonstrates subscribing to changes in connection state:

```rescript
React.useEffect0(() => {
  let remove =
    ReactNativeNetInfo.addEventListener(w =>
      (
        switch (w##details->Js.Null.toOption) {
        | None => "Connection type is none or unknown"
        | Some(x) =>
          let y = x##cellularGeneration;
          switch (y->Js.Nullable.toOption) {
          | None =>
            if (y == Js.Nullable.undefined) {
              "Connection type is wifi, bluetooth, ethernet, wimax, vpn or other";
            } else {
              "Connection generation unknown";
            }
          | Some(z) =>
            if (z == ReactNativeNetInfo.net2G) {
              "2G connection";
            } else if (z == ReactNativeNetInfo.net3G) {
              "3G connection";
            } else {
              "4G connection";
            }
          };
        }
      )
      ->Js.Console.warn
    );
  Js.Console.warn(remove);
  Some(() => remove());
});
```

#### `useNetInfo`

This method returns a React Hook with type `netInfoState`

```rescript
useNetInfo: unit => netInfoState
```

Below example demonstrates its use within a `Text` component:

```rescript
<Text>
  (
    switch (ReactNativeNetInfo.useNetInfo()##details->Js.Null.toOption) {
    | None => "Connection type is none or unknown"
    | Some(x) =>
      let y = x##cellularGeneration;
      switch (y->Js.Nullable.toOption) {
      | None =>
        if (y == Js.Nullable.undefined) {
          "Connection type is wifi, bluetooth, ethernet, wimax, vpn or other";
        } else {
          "Connection generation unknown";
        }
      | Some(z) =>
        if (z == ReactNativeNetInfo.net2G) {
          "2G connection";
        } else if (z == ReactNativeNetInfo.net3G) {
          "3G connection";
        } else {
          "4G connection";
        }
      };
    }
  )
  ->React.string
</Text>
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
