@module("react-native-paper") @react.component
external make: (
  ~label: string=?,
  ~small: bool=?,
  ~color: string=?,
  ~disabled: bool=?,
  ~onPress: ReactNative.Event.targetEvent => unit,
  ~theme: Paper__ThemeProvider.Theme.t=?,
  ~style: ReactNative.Style.t=?,
  ~accessibilityLabel: string=?,
  ~icon: Paper__Icon.t=?,
) => React.element = "FAB"
