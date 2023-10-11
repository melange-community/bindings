module Make = (
  T: {
    type t
  },
) => {
  @send external clearFormData: T.t => unit = "clearFormData"
  @send external clearCache: T.t => unit = "clearCache"
  @send external clearHistory: T.t => unit = "clearHistory"
  @send external requestFocus: T.t => unit = "requestFocus"
  @send external goForward: T.t => unit = "goForward"
  @send external goBack: T.t => unit = "goBack"
  @send external reload: T.t => unit = "reload"
  @send external stopLoading: T.t => unit = "stopLoading"
  @send
  external injectJavaScript: (T.t, string) => unit = "injectJavaScript"
}
