@module("react-native-paper") @react.component
external make: (
  ~mode: [#outlined | #flat],
  ~selected: bool=?,
  ~disabled: bool=?,
  ~accessibilityLabel: string=?,
  ~avatar: React.element=?,
  ~icon: Paper__Icon.t=?,
  ~style: ReactNative.Style.t=?,
  ~theme: Paper__ThemeProvider.Theme.t=?,
  ~onPress: ReactNative.Event.pressEvent => unit=?,
  ~onClose: ReactNative.Event.pressEvent => unit=?,
  ~children: React.element,
) => React.element = "Chip"
