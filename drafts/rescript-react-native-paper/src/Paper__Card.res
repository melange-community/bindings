open ReactNative

@module("react-native-paper") @react.component
external make: (
  ~elevation: int=?,
  ~onLongPress: Event.pressEvent => unit=?,
  ~onPress: Event.pressEvent => unit=?,
  ~style: Style.t=?,
  ~theme: 'a=?,
  ~testID: string=?,
  ~children: React.element,
) => React.element = "Card"

@deriving(abstract)
type props = {
  @optional
  elevation: int,
  @optional
  onLongPress: Event.pressEvent => unit,
  @optional
  onPress: Event.pressEvent => unit,
  @optional
  style: Style.t,
  @optional
  theme: Paper__ThemeProvider.Theme.t,
  @optional
  testID: string,
}

module Actions = {
  @module("react-native-paper") @scope("Card") @react.component
  external make: (~style: ReactNative.Style.t=?, ~children: React.element) => React.element =
    "Actions"
}

module Content = {
  @module("react-native-paper") @scope("Card") @react.component
  external make: (~style: ReactNative.Style.t=?, ~children: React.element) => React.element =
    "Content"
}
