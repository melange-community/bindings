@module("react-native-paper") @react.component
external make: (
  ~mode: [#text | #outlined | #contained]=?,
  ~disabled: bool=?,
  ~compact: bool=?,
  ~raised: bool=?,
  ~loading: bool=?,
  ~dark: bool=?,
  ~icon: Paper__Icon.t=?,
  ~color: string=?,
  ~accessibilityLabel: string=?,
  ~style: ReactNative.Style.t=?,
  ~labelStyle: ReactNative.Style.t=?,
  ~theme: Paper__ThemeProvider.Theme.t=?,
  ~onPress: ReactNative.Event.pressEvent => unit=?,
  ~children: React.element,
) => React.element = "Button"
