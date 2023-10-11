module Host = {
  @module("react-native-paper") @scope("Portal") @react.component
  external make: (~children: React.element) => React.element = "Host"
}

@module("react-native-paper") @react.component
external make: (~theme: Paper__ThemeProvider.Theme.t=?, ~children: React.element) => React.element =
  "Portal"
