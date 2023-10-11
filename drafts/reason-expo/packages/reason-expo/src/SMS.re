[@bs.module "expo-sms"]
external isAvailableAsync: unit => Js.Promise.t(bool) = "isAvailableAsync";

[@bs.deriving abstract]
type sendSMSAsyncResult = {result: string};

[@bs.module "expo-sms"]
external sendSMSAsync:
  (array(string), string) => Js.Promise.t(sendSMSAsyncResult) =
  "sendSMSAsync";