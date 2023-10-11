type t = unit => unit

type netInfoStateType

@bs.inline("none")
let none: netInfoStateType

@bs.inline("unknown")
let unknown: netInfoStateType

@bs.inline("cellular")
let cellular: netInfoStateType

@bs.inline("wifi")
let wifi: netInfoStateType

@bs.inline("bluetooth")
let bluetooth: netInfoStateType

@bs.inline("ethernet")
let ethernet: netInfoStateType

@bs.inline("wimax")
let wimax: netInfoStateType

@bs.inline("vpn")
let vpn: netInfoStateType

@bs.inline("other")
let other: netInfoStateType

type netInfoCellularGeneration

@bs.inline("2g")
let net2G: netInfoCellularGeneration

@bs.inline("3g")
let net3G: netInfoCellularGeneration

@bs.inline("4g")
let net4G: netInfoCellularGeneration

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

module ConnectionType: {
  type t

  @bs.inline("bluetooth")
  let bluetooth: t

  @bs.inline("cellular")
  let cellular: t

  @bs.inline("ethernet")
  let ethernet: t

  @bs.inline("unknown")
  let unknown: t

  @bs.inline("wifi")
  let wifi: t

  @bs.inline("wimax")
  let wimax: t
}

module EffectiveConnectionType: {
  type t

  @bs.inline("2g")
  let net2G: t

  @bs.inline("3g")
  let net3G: t

  @bs.inline("4g")
  let net4G: t

  @bs.inline("unknown")
  let unknown: t
}

type info = {"_type": ConnectionType.t, "effectiveType": EffectiveConnectionType.t}
