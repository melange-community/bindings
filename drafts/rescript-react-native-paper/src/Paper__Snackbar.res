module Duration = {
  type t
  @module("react-native-paper") @scope("Snackbar")
  external short: t = "DURATION_SHORT"
  @module("react-native-paper") @scope("Snackbar")
  external medium: t = "DURATION_MEDIUM"
  @module("react-native-paper") @scope("Snackbar")
  external long: t = "DURATION_LONG"

  external value: int => t = "%identity"
}

module Action = {
  type t

  @val external none: t = "null"

  @obj external make: (~label: string, ~onPress: unit => unit) => t = ""
}

@module("react-native-paper") @react.component
external make: (
  ~theme: Paper__ThemeProvider.Theme.t=?,
  ~duration: Duration.t=?,
  ~onDismiss: unit => unit,
  ~style: ReactNative.Style.t=?,
  ~action: Action.t=?,
  ~visible: bool,
  ~children: React.element,
) => React.element = "Snackbar"
