@module("react-native-paper") @react.component
external make: (
  ~visible: bool,
  ~onDismiss: unit => unit,
  ~dismissable: bool=?,
  ~theme: Paper__ThemeProvider.Theme.t=?,
  ~style: ReactNative.Style.t=?,
  ~children: React.element,
) => React.element = "Dialog"

module Actions = {
  @module("react-native-paper") @scope("Dialog") @react.component
  external make: (~style: ReactNative.Style.t=?, ~children: React.element) => React.element =
    "Actions"
}

module Content = {
  @module("react-native-paper") @scope("Dialog") @react.component
  external make: (~style: ReactNative.Style.t=?, ~children: React.element) => React.element =
    "Content"
}
module ScrollArea = {
  @module("react-native-paper") @scope("Dialog") @react.component
  external reactClass: (~style: ReactNative.Style.t=?, ~children: React.element) => React.element =
    "ScrollArea"
}

module Title = {
  @module("react-native-paper") @scope("Dialog") @react.component
  external make: (
    ~style: ReactNative.Style.t=?,
    ~theme: Paper__ThemeProvider.Theme.t=?,
    ~children: React.element,
  ) => React.element = "Title"
}
