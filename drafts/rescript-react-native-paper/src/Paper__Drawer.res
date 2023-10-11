module Item = {
  @module("react-native-paper") @scope("Drawer") @react.component
  external make: (
    ~label: string,
    ~icon: React.element=?,
    ~active: bool=?,
    ~theme: Paper__ThemeProvider.Theme.t=?,
    ~onPress: ReactNative.Event.targetEvent => unit=?,
    ~style: ReactNative.Style.t=?,
  ) => React.element = "Item"
}

module Section = {
  @module("react-native-paper") @scope("Drawer") @react.component
  external make: (~title: string=?, ~theme: {..}=?, ~children: React.element) => React.element =
    "Section"
}
