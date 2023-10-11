type t = unit => unit

type netInfoStateType = string

@inline
let none = "none"

@inline
let unknown = "unknown"

@inline
let cellular = "cellular"

@inline
let wifi = "wifi"

@inline
let bluetooth = "bluetooth"

@inline
let ethernet = "ethernet"

@inline
let wimax = "wimax"

@inline
let vpn = "vpn"

@inline
let other = "other"

type netInfoCellularGeneration = string

@inline
let net2G = "2g"

@inline
let net3G = "3g"

@inline
let net4G = "4g"

type response

@get external status: response => int = "status"

type netInfoConfiguration

@obj
external netInfoConfiguration: (
  ~reachabilityUrl: string=?,
  ~reachabilityTest: response => bool=?,
  ~reachabilityShortTimeout: float=?,
  ~reachabilityLongTimeout: float=?,
  ~reachabilityRequestTimeout: float=?,
  unit,
) => netInfoConfiguration = ""

type details = {
  "isConnectionExpensive": bool,
  "ssid": Js.Nullable.t<string>,
  "bssid": Js.Nullable.t<string>,
  "strength": Js.Nullable.t<int>,
  "ipAddress": Js.Nullable.t<string>,
  "subnet": Js.Nullable.t<string>,
  "frequency": Js.Nullable.t<float>,
  "cellularGeneration": Js.Nullable.t<netInfoCellularGeneration>,
  "carrier": Js.Nullable.t<string>,
}

type netInfoState = {
  "_type": netInfoStateType,
  "isConnected": bool,
  "isInternetReachable": bool,
  "isWifiEnabled": bool,
  "details": Js.Null.t<details>,
}

@module("@react-native-community/netinfo")
external configure: netInfoConfiguration => unit = "configure"

@module("@react-native-community/netinfo")
external fetch: unit => Js.Promise.t<netInfoState> = "fetch"

@module("@react-native-community/netinfo")
external fetchInterface: [#cellular | #ethernet | #wifi] => Js.Promise.t<netInfoState> = "fetch"

@module("@react-native-community/netinfo")
external addEventListener: (netInfoState => unit) => t = "addEventListener"

@module("@react-native-community/netinfo")
external useNetInfo: unit => netInfoState = "useNetInfo"

module ConnectionType = {
  type t = string

  @inline
  let bluetooth = "bluetooth"

  @inline
  let cellular = "cellular"

  @inline
  let ethernet = "ethernet"

  @inline
  let unknown = "unknown"

  @inline
  let wifi = "wifi"

  @inline
  let wimax = "wimax"
}

module EffectiveConnectionType = {
  type t = string

  @inline
  let net2G = "2g"

  @inline
  let net3G = "3g"

  @inline
  let net4G = "4g"

  @inline
  let unknown = "unknown"
}

type info = {"_type": ConnectionType.t, "effectiveType": EffectiveConnectionType.t}
