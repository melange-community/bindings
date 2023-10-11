@scope("default") @module("@react-native-async-storage/async-storage")
external getItem: string => Js.Promise.t<Js.Null.t<string>> = "getItem"

@scope("default") @module("@react-native-async-storage/async-storage")
external setItem: (string, string) => Js.Promise.t<unit> = "setItem"

@scope("default") @module("@react-native-async-storage/async-storage")
external removeItem: string => Js.Promise.t<unit> = "removeItem"

@scope("default") @module("@react-native-async-storage/async-storage")
external mergeItem: (string, string) => Js.Promise.t<unit> = "mergeItem"

@scope("default") @module("@react-native-async-storage/async-storage")
external clear: unit => Js.Promise.t<unit> = "clear"

@scope("default") @module("@react-native-async-storage/async-storage")
external getAllKeys: unit => Js.Promise.t<Js.Null.t<array<string>>> = "getAllKeys"

@scope("default") @module("@react-native-async-storage/async-storage")
external multiGet: array<string> => Js.Promise.t<array<(string, Js.Null.t<string>)>> = "multiGet"

@scope("default") @module("@react-native-async-storage/async-storage")
external multiSet: array<(string, string)> => Js.Promise.t<unit> = "multiSet"

@scope("default") @module("@react-native-async-storage/async-storage")
external multiMerge: array<(string, string)> => Js.Promise.t<unit> = "multiMerge"

@scope("default") @module("@react-native-async-storage/async-storage")
external multiRemove: array<string> => Js.Promise.t<unit> = "multiRemove"

@scope("default") @module("@react-native-async-storage/async-storage")
external flushGetRequests: unit => unit = "flushGetRequests"

type asyncStorageState = {
  @meth
  "getItem": unit => Js.Promise.t<Js.Null.t<string>>,
  @meth
  "setItem": string => Js.Promise.t<unit>,
  @meth
  "mergeItem": string => Js.Promise.t<unit>,
  @meth
  "removeItem": unit => Js.Promise.t<unit>,
}

@deprecated(
  "Please use `useAsyncStorage_` instead of `useAsyncStorage` to use record syntax. In next major release, `useAsyncStorage_` will become `useAsyncStorage`."
)
@module("@react-native-async-storage/async-storage")
external useAsyncStorage: string => asyncStorageState = "useAsyncStorage"
type asyncStorageStateAlt = {
  getItem: unit => Js.Promise.t<Js.Null.t<string>>,
  setItem: string => Js.Promise.t<unit>,
  mergeItem: string => Js.Promise.t<unit>,
  removeItem: unit => Js.Promise.t<unit>,
}

@module("@react-native-async-storage/async-storage")
external useAsyncStorage_: string => asyncStorageState = "useAsyncStorage"
