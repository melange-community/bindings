@module("react-native-paper") @react.component
external make: (
  ~disabled: bool=?,
  ~animated: bool=?,
  ~icon: Paper__Icon.t=?,
  ~color: string=?,
  ~accessibilityLabel: string=?,
  ~style: ReactNative.Style.t=?,
  ~size: int=?,
  ~onPress: ReactNative.Event.pressEvent => unit=?,
  ~theme: Paper__ThemeProvider.Theme.t=?,
) => React.element = "IconButton"
