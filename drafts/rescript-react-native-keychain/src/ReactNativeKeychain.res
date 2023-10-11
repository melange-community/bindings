module SecurityLevel = {
  type t

  @module("react-native-keychain") @scope("SECURITY_LEVEL")
  external any: t = "ANY"
  @module("react-native-keychain") @scope("SECURITY_LEVEL")
  external secureSoftware: t = "SECURE_SOFTWARE"
  @module("react-native-keychain") @scope("SECURITY_LEVEL")
  external secureHardware: t = "SECURE_HARDWARE"
}

module Accessible = {
  type t

  @module("react-native-keychain") @scope("ACCESSIBLE")
  external whenUnlocked: t = "WHEN_UNLOCKED"
  @module("react-native-keychain") @scope("ACCESSIBLE")
  external afterFirstUnlock: t = "AFTER_FIRST_UNLOCK"
  @module("react-native-keychain") @scope("ACCESSIBLE")
  external always: t = "ALWAYS"
  @module("react-native-keychain") @scope("ACCESSIBLE")
  external whenPasscodeSetThisDeviceOnly: t = "WHEN_PASSCODE_SET_THIS_DEVICE_ONLY"
  @module("react-native-keychain") @scope("ACCESSIBLE")
  external whenUnlockedThisDeviceOnly: t = "WHEN_UNLOCKED_THIS_DEVICE_ONLY"
  @module("react-native-keychain") @scope("ACCESSIBLE")
  external afterFirstUnlockThisDeviceOnly: t = "AFTER_FIRST_UNLOCK_THIS_DEVICE_ONLY"
  @module("react-native-keychain") @scope("ACCESSIBLE")
  external alwaysThisDeviceOnly: t = "ALWAYS_THIS_DEVICE_ONLY"
}

module AccessControl = {
  type t

  @module("react-native-keychain") @scope("ACCESS_CONTROL")
  external userPresence: t = "USER_PRESENCE"
  @module("react-native-keychain") @scope("ACCESS_CONTROL")
  external biometryAny: t = "BIOMETRY_ANY"
  @module("react-native-keychain") @scope("ACCESS_CONTROL")
  external biometryCurrentSet: t = "BIOMETRY_CURRENT_SET"
  @module("react-native-keychain") @scope("ACCESS_CONTROL")
  external devicePasscode: t = "DEVICE_PASSCODE"
  @module("react-native-keychain") @scope("ACCESS_CONTROL")
  external applicationPassword: t = "APPLICATION_PASSWORD"
  @module("react-native-keychain") @scope("ACCESS_CONTROL")
  external biometryAnyOrDevicePasscode: t = "BIOMETRY_ANY_OR_DEVICE_PASSCODE"
  @module("react-native-keychain") @scope("ACCESS_CONTROL")
  external biometryCurrentSetOrDevicePasscode: t = "BIOMETRY_CURRENT_SET_OR_DEVICE_PASSCODE"
}

module AuthenticationType = {
  type t

  @module("react-native-keychain") @scope("AUTHENTICATION_TYPE")
  external devicePasscodeOrBiometrics: t = "DEVICE_PASSCODE_OR_BIOMETRICS"
  @module("react-native-keychain") @scope("AUTHENTICATION_TYPE")
  external biometrics: t = "BIOMETRICS"
}

module BiometryType = {
  type t

  @module("react-native-keychain") @scope("BIOMETRY_TYPE")
  external touchId: t = "TOUCH_ID"
  @module("react-native-keychain") @scope("BIOMETRY_TYPE")
  external faceId: t = "FACE_ID"
  @module("react-native-keychain") @scope("BIOMETRY_TYPE")
  external fingerprint: t = "FINGERPRINT"
}

// getGenericPassword

type getGenericPasswordResult

type credentials = {
  service: string,
  username: string,
  password: string,
}

let decodeGetGenericPasswordResult = (result: getGenericPasswordResult) => {
  open Js.Json
  switch result->Obj.magic->classify {
  | JSONFalse => None
  | JSONObject(dict) =>
    switch (
      dict->Js.Dict.get("service")->Belt.Option.map(classify),
      dict->Js.Dict.get("username")->Belt.Option.map(classify),
      dict->Js.Dict.get("password")->Belt.Option.map(classify),
    ) {
    | (Some(JSONString(service)), Some(JSONString(username)), Some(JSONString(password))) =>
      Some({service: service, username: username, password: password})
    | _ => None // should not happen
    }
  | _ => None // should not happen
  }
}

type authenticationPrompt = {
  title: string,
  subtitle: option<string>,
  description: option<string>,
  cancel: option<string>,
}

@obj
external authenticationPrompt: (
  ~title: string,
  ~subtitle: option<string>=?,
  ~description: option<string>=?,
  ~cancel: option<string>=?,
  unit,
) => authenticationPrompt = ""

type getGenericPasswordOptions
@obj
external getGenericPasswordOptions: (
  ~authenticationPrompt: authenticationPrompt,
  ~service: string=?,
  unit,
) => getGenericPasswordOptions = ""

@module("react-native-keychain")
external getGenericPassword: unit => Js.Promise.t<getGenericPasswordResult> = "getGenericPassword"

@module("react-native-keychain")
external getGenericPasswordWithService: string => Js.Promise.t<getGenericPasswordResult> =
  "getGenericPassword"

@module("react-native-keychain")
external getGenericPasswordWithOptions: getGenericPasswordOptions => Js.Promise.t<
  getGenericPasswordResult,
> = "getGenericPassword"

// setGenericPassword

type setGenericPasswordOptions
@obj
external setGenericPasswordOptions: (
  ~accessControl: AccessControl.t=?,
  ~accessGroup: string=?,
  ~accessible: Accessible.t=?,
  ~service: string=?,
  ~securityLevel: SecurityLevel.t=?,
  unit,
) => setGenericPasswordOptions = ""

@module("react-native-keychain")
external setGenericPassword: (~username: string, ~password: string) => Js.Promise.t<bool> =
  "setGenericPassword"

@module("react-native-keychain")
external setGenericPasswordWithOptions: (
  ~username: string,
  ~password: string,
  ~options: setGenericPasswordOptions,
) => Js.Promise.t<bool> = "setGenericPassword"

@module("react-native-keychain")
external setGenericPasswordWithService: (
  ~username: string,
  ~password: string,
  ~service: string,
) => Js.Promise.t<bool> = "setGenericPassword"

// resetGenericPasswordOptions

type resetGenericPasswordOptions
@obj
external resetGenericPasswordOptions: (~service: string=?, unit) => resetGenericPasswordOptions = ""

@module("react-native-keychain")
external resetGenericPassword: unit => Js.Promise.t<bool> = "resetGenericPassword"

@module("react-native-keychain")
external resetGenericPasswordWithOptions: resetGenericPasswordOptions => Js.Promise.t<bool> =
  "resetGenericPassword"

@module("react-native-keychain")
external resetGenericPasswordWithService: string => Js.Promise.t<bool> = "resetGenericPassword"
/*
 @todo handle false | Result for promise

  [@module "react-native-keychain"]
  external hasInternetCredentials: string => Js.Promise.t(bool) =
    "hasInternetCredentials";

  type setInternetCredentialsOptions;
  [@obj]
  external setInternetCredentialsOptions:
    (
      ~accessControl: AccessControl.t=?,
      ~accessGroup: string=?,
      ~accessible: Accessible.t=?,
      ~securityLevel: SecurityLevel.t=?,
      unit
    ) =>
    setInternetCredentialsOptions;

  type internetCredentials = {
    username: string,
    password: string,
    service: string,
    storage: string,
  };
  [@module "react-native-keychain"]
  external setInternetCredentials:
    (string, string, string, option(setInternetCredentialsOptions)) =>
    Js.Promise.t(internetCredentials) =
    "setInternetCredentials";

  type getInternetCredentialsOptions = {authenticationPrompt};
  [@obj]
  external getInternetCredentialsOptions:
    (~authenticationPrompt: authenticationPrompt=?, unit) =>
    getInternetCredentialsOptions;

  [@module "react-native-keychain"]
  external getInternetCredentials:
    (string, option(getInternetCredentialsOptions)) => Js.Promise.t(unit) =
    "getInternetCredentials";

  [@module "react-native-keychain"]
  external resetInternetCredentials: string => Js.Promise.t(unit) =
    "resetInternetCredentials";
 */
