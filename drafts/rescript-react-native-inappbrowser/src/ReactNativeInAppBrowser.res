type authResult = {
  @as("type")
  resultType: [#cancel | #dismiss | #success],
  url: option<string>,
}

type browserResult = {
  @as("type")
  resultType: [#cancel | #dismiss],
}

type iosOptions
@obj
external iosOptions: (
  ~dismissButtonStyle: @string
  [
    | @as("done") #doneButton
    | @as("close") #closeButton
    | @as("cancel") #cancelButton
  ]=?,
  ~preferredBarTintColor: string=?,
  ~preferredControlTintColor: string=?,
  ~readerMode: bool=?,
  ~animated: bool=?,
  ~modalPresentationStyle: [
    | #automatic
    | #fullScreen
    | #pageSheet
    | #formSheet
    | #currentContext
    | #custom
    | #overFullScreen
    | #overCurrentContext
    | #popover
    | #none
  ]=?,
  ~modalTransitionStyle: [
    | #coverVertical
    | #flipHorizontal
    | #crossDissolve
    | #partialCurl
  ]=?,
  ~modalEnabled: bool=?,
  ~enableBarCollapsing: bool=?,
  ~ephemeralWebSession: bool=?,
  unit,
) => iosOptions = ""

type androidAnimationOptions = {
  startEnter: string,
  startExit: string,
  endEnter: string,
  endExit: string,
}

type androidOptions
@obj
external androidOptions: (
  ~showTitle: bool=?,
  ~toolbarColor: string=?,
  ~secondaryToolbarColor: string=?,
  ~enableUrlBarHiding: bool=?,
  ~enableDefaultShare: bool=?,
  ~forceCloseOnRedirection: bool=?,
  ~animations: androidAnimationOptions=?,
  ~headers: Js.t<'a>=?,
  ~hasBackButton: bool=?,
  ~browserPackage: string=?,
  ~showInRecents: bool=?,
  unit,
) => androidOptions = ""

@module("react-native-inappbrowser-reborn") @scope("InAppBrowser")
external isAvailable: unit => Js.Promise.t<bool> = "isAvailable"

@module("react-native-inappbrowser-reborn") @scope("InAppBrowser")
external openBrowser: (
  string,
  @unwrap
  [
    | #IosOptions(iosOptions)
    | #AndroidOptions(androidOptions)
  ],
) => Js.Promise.t<browserResult> = "open"

@module("react-native-inappbrowser-reborn") @scope("InAppBrowser")
external close: unit => unit = "close"

@module("react-native-inappbrowser-reborn") @scope("InAppBrowser")
external openAuth: (
  string,
  string,
  @unwrap
  [
    | #IosOptions(iosOptions)
    | #AndroidOptions(androidOptions)
  ],
) => Js.Promise.t<authResult> = "openAuth"

@module("react-native-inappbrowser-reborn") @scope("InAppBrowser")
external closeAuth: unit => unit = "closeAuth"
