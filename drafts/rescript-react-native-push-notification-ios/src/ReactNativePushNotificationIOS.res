module FetchResult = {
  type t

  @module("@react-native-community/push-notification-ios") @scope(("default", "FetchResult"))
  external newData: t = "NewData"

  @module("@react-native-community/push-notification-ios") @scope(("default", "FetchResult"))
  external noData: t = "NoData"

  @module("@react-native-community/push-notification-ios") @scope(("default", "FetchResult"))
  external resultFailed: t = "ResultFailed"
}

@ocaml.doc("
 * Alert Object that can be included in the aps `alert` object
 ")
type notificationAlert = {
  title: option<string>,
  subtitle: option<string>,
  body: option<string>,
}

type notificationActionOptions = {
  foreground: option<bool>,
  destructive: option<bool>,
  authenticationRequired: option<bool>,
}

type notificationActionTextInput = {
  @ocaml.doc("
   * Text to be shown on button when user finishes text input.
   * Default is \"Send\" or its equivalent word in user's language setting.
   ")
  buttonTitle: option<string>,
  @ocaml.doc("
   * Placeholder for text input for text input action.
   ")
  placeholder: option<string>,
}

@ocaml.doc("
 * Notification Action that can be added to specific categories
 ")
type notificationAction = {
  @ocaml.doc("
   * Id of Action.
   * This value will be returned as actionIdentifier when notification is received.
   ")
  id: string,
  @ocaml.doc("
   * Text to be shown on notification action button.
   ")
  title: string,
  @ocaml.doc("
   * Option for notification action.
   ")
  options: option<notificationActionOptions>,
  @ocaml.doc("
   * Option for textInput action.
   * If textInput prop exists, then user action will automatically become a text input action.
   * The text user inputs will be in the userText field of the received notification.
   ")
  textInput: option<notificationActionTextInput>,
}

module Notification = {
  type t

  @send @return(nullable)
  external // string | notificationAlert
  getAlert: t => option<Js.Json.t> = "getAlert"

  @send external getTitle: t => string = "getTitle"

  @send @return(nullable)
  external // string | notificationAlert
  getMessage: t => option<Js.Json.t> = "getMessage"

  @send @return(nullable)
  external getSound: t => option<string> = "getSound"

  @send @return(nullable)
  external getCategory: t => option<string> = "getCategory"

  // Actually type ContentAvailable = 1 | null | void ...
  @send external getContentAvailable: t => bool = "getContentAvailable"

  @send @return(nullable)
  external getBadgeCount: t => option<int> = "getBadgeCount"

  @send @return(nullable)
  external getData: t => option<Js.Json.t> = "getData"

  @ocaml.doc("
   * Get's the action id of the notification action user has taken.
   ")
  @send
  @return(nullable)
  external getActionIdentifier: t => option<string> = "getActionIdentifier"

  @ocaml.doc("
   * Gets the text user has inputed if user has taken the text action response.
   ")
  @send
  @return(nullable)
  external getUserText: t => option<string> = "getUserText"

  @send @return(nullable)
  external getThreadID: t => option<string> = "getThreadID"

  @send external finish: (t, FetchResult.t) => unit = "finish"
}

type notificationRequest = {
  @ocaml.doc("
   * identifier of the notification.
   * Required in order to retrieve specific notification.
   ")
  id: string,
  @ocaml.doc("
   * A short description of the reason for the alert.
   ")
  title: option<string>,
  @ocaml.doc("
   * A secondary description of the reason for the alert.
   ")
  subtitle: option<string>,
  @ocaml.doc("
   * The message displayed in the notification alert.
   ")
  body: option<string>,
  @ocaml.doc("
   * The number to display as the app's icon badge.
   ")
  badge: option<int>,
  @ocaml.doc("
   * The sound to play when the notification is delivered.
   ")
  sound: option<string>,
  @ocaml.doc("
   * The category of this notification. Required for actionable notifications.
   ")
  category: option<string>,
  @ocaml.doc("
   * The thread identifier of this notification.
   ")
  threadId: option<string>,
  @ocaml.doc("
   * The date which notification triggers.
   ")
  fireDate: option<Js.Date.t>,
  @ocaml.doc("
   * Sets notification to repeat daily.
   * Must be used with fireDate.
   ")
  repeats: option<bool>,
  @ocaml.doc("
   * Sets notification to be silent
   ")
  isSilent: option<bool>,
  @ocaml.doc("
   * Optional data to be added to the notification
   ")
  userInfo: option<Js.Json.t>,
}

@obj
external notificationRequest: (
  ~id: string,
  ~title: string=?,
  ~subtitle: string=?,
  ~body: string=?,
  ~badge: int=?,
  ~sound: string=?,
  ~category: string=?,
  ~threadId: string=?,
  ~fireDate: Js.Date.t=?,
  ~repeats: bool=?,
  ~isSilent: bool=?,
  ~userInfo: Js.Json.t=?,
  unit,
) => notificationRequest = ""

@module("@react-native-community/push-notification-ios") @scope("default")
external addNotificationRequest: notificationRequest => unit = "addNotificationRequest"

type localNotification

@obj
external localNotification: (
  ~alertBody: string=?,
  ~alertTitle: string=?,
  ~alertAction: string=?,
  ~soundName: string=?,
  ~isSilent: bool=?,
  ~category: string=?,
  ~userInfo: Js.Json.t=?,
  ~applicationIconBadgeNumber: int=?,
  ~fireDate: Js.Date.t=?,
  ~repeatInterval: [#minute | #hour | #day | #week | #month | #year]=?,
  unit,
) => localNotification = ""

@deprecated("Please use addNotificationRequest instead")
@module("@react-native-community/push-notification-ios")
@scope("default")
external presentLocalNotification: localNotification => unit = "presentLocalNotification"

@deprecated("Please use addNotificationRequest instead")
@module("@react-native-community/push-notification-ios")
@scope("default")
external scheduleLocalNotification: localNotification => unit = "scheduleLocalNotification"

@deprecated("Please use removeAllPendingNotificationRequests instead")
@module("@react-native-community/push-notification-ios")
@scope("default")
external cancelAllLocalNotifications: unit => unit = "cancelAllLocalNotifications"

@module("@react-native-community/push-notification-ios") @scope("default")
external removeAllPendingNotificationRequests: unit => unit = "removeAllPendingNotificationRequests"

@module("@react-native-community/push-notification-ios") @scope("default")
external removeAllDeliveredNotifications: unit => unit = "removeAllDeliveredNotifications"

type deliveredNotification = {
  identifier: string,
  date: option<string>,
  title: option<string>,
  subtitle: option<string>,
  body: option<string>,
  category: option<string>,
  actionIdentifier: option<string>,
  @as("thread-id")
  threadId: option<string>,
  userText: option<string>,
  userInfo: option<Js.Json.t>,
}

@module("@react-native-community/push-notification-ios") @scope("default")
external getDeliveredNotifications: (array<deliveredNotification> => unit) => unit =
  "getDeliveredNotifications"

@module("@react-native-community/push-notification-ios") @scope("default")
external removeDeliveredNotifications: (~identifiers: array<string>) => unit =
  "removeDeliveredNotifications"

@module("@react-native-community/push-notification-ios") @scope("default")
external setApplicationIconBadgeNumber: int => unit = "setApplicationIconBadgeNumber"

@module("@react-native-community/push-notification-ios") @scope("default")
external getApplicationIconBadgeNumber: (int => unit) => unit = "getApplicationIconBadgeNumber"

// multiple externals
@module("@react-native-community/push-notification-ios") @scope("default")
external cancelLocalNotifications: unit => unit = "cancelLocalNotifications"

// multiple externals
@module("@react-native-community/push-notification-ios") @scope("default")
external cancelLocalNotificationsWithUserInfo: Js.Json.t => unit = "cancelLocalNotifications"

type formattedLocalNotification = {
  fireDate: option<string>,
  alertAction: option<string>,
  alertTitle: option<string>,
  alertBody: option<string>,
  applicationIconBadgeNumber: option<int>,
  category: option<string>,
  repeatInterval: option<string>,
  soundName: option<string>,
  userInfo: option<Js.Json.t>,
}

@deprecated("Please use getPendingNotificationRequests instead")
@module("@react-native-community/push-notification-ios")
@scope("default")
external getScheduledLocalNotifications: (array<formattedLocalNotification> => unit) => unit =
  "getScheduledLocalNotifications"

@module("@react-native-community/push-notification-ios") @scope("default")
external getPendingNotificationRequests: (array<notificationRequest> => unit) => unit =
  "getPendingNotificationRequests"

type registrationError<'a> = {
  message: string,
  code: int,
  details: Js.t<'a>,
}

@module("@react-native-community/push-notification-ios") @scope("default")
external addEventListener: @string
[
  | #notification(Notification.t => unit)
  | #localNotification(Notification.t => unit)
  | #register((~deviceToken: string) => unit)
  | #registrationError(registrationError<'a> => unit)
] => unit = "addEventListener"

@module("@react-native-community/push-notification-ios") @scope("default")
external removeEventListener: @string
[
  | #notification(Notification.t => unit)
  | #localNotification(Notification.t => unit)
  | #register((~deviceToken: string) => unit)
  | #registrationError(registrationError<'a> => unit)
] => unit = "removeEventListener"

type requestedPermissions = {
  alert: bool,
  badge: bool,
  sound: bool,
}

type checkedPermissions = {
  alert: bool,
  badge: bool,
  sound: bool,
  lockScreen: bool,
  notificationCenter: bool,
  // https://developer.apple.com/documentation/usernotifications/unauthorizationstatus
  authorizationStatus: int,
}

type requestPermissionsOptions
@obj
external requestPermissionsOptions: (
  ~alert: bool=?,
  ~badge: bool=?,
  ~sound: bool=?,
  unit,
) => requestPermissionsOptions = ""

// multiple externals
@module("@react-native-community/push-notification-ios") @scope("default")
external requestPermissions: unit => Js.Promise.t<requestedPermissions> = "requestPermissions"

// multiple externals
@module("@react-native-community/push-notification-ios") @scope("default")
external requestPermissionsWithOptions: requestPermissionsOptions => Js.Promise.t<
  requestedPermissions,
> = "requestPermissions"

@module("@react-native-community/push-notification-ios") @scope("default")
external abandonPermissions: unit => unit = "abandonPermissions"

@module("@react-native-community/push-notification-ios") @scope("default")
external checkPermissions: (unit => checkedPermissions) => unit = "checkPermissions"

@module("@react-native-community/push-notification-ios") @scope("default")
external getInitialNotification: unit => Js.Promise.t<Js.Nullable.t<Notification.t>> =
  "getInitialNotification"

@ocaml.doc("
 * Notification Category that can include specific actions
 ")
type notificationCategory = {
  id: string,
  actions: array<notificationAction>,
}
@module("@react-native-community/push-notification-ios") @scope("default")
external setNotificationCategories: array<notificationCategory> => Js.Promise.t<unit> =
  "setNotificationCategories"
