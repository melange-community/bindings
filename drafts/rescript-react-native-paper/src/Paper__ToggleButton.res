@module("react-native-paper") @react.component
external make: (
  ~value: string=?,
  ~disabled: bool=?,
  ~loading: bool=?,
  ~status: [#checked | #unchecked]=?,
  ~icon: Paper__Icon.t=?,
  ~color: string=?,
  ~accessibilityLabel: string=?,
  ~style: ReactNative.Style.t=?,
  ~theme: Paper__ThemeProvider.Theme.t=?,
  ~onPress: string => unit=?,
) => React.element = "ToggleButton"

module Group = {
  @module("react-native-paper") @scope("ToggleButton") @react.component
  external make: (
    ~value: string,
    ~onValueChange: string => unit,
    ~children: React.element,
    ~style: ReactNative.Style.t=?,
  ) => React.element = "Group"
}

module Row = {
  @module("react-native-paper") @scope("ToggleButton") @react.component
  external make: (
    ~value: string,
    ~onValueChange: string => unit,
    ~children: React.element,
    ~style: ReactNative.Style.t=?,
  ) => React.element = "Row"
}
