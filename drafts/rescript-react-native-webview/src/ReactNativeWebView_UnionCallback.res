open ReactNative
include NativeElement

module Make = (
  T: {
    type union
    type navigationEvent
    type errorEvent
  },
) => {
  module WebViewEvent = {
    type payload = T.union

    include Event.SyntheticEvent({
      type _payload = payload
    })
  }

  type t = WebViewEvent.t => unit

  @get external description: T.union => option<string> = "description"
  external convert: WebViewEvent.t => 'a = "%identity"
  let make = (
    ~navigationCallback: T.navigationEvent => unit,
    ~errorCallback: T.errorEvent => unit,
  ): t =>
    x =>
      switch description(x.nativeEvent) {
      | None => navigationCallback(convert(x))
      | Some(_) => errorCallback(convert(x))
      }

  let uncurriedMake = (
    ~navigationCallback: (. T.navigationEvent) => unit,
    ~errorCallback: (. T.errorEvent) => unit,
  ): t =>
    x =>
      switch description(x.nativeEvent) {
      | None => navigationCallback(. convert(x))
      | Some(_) => errorCallback(. convert(x))
      }
}
