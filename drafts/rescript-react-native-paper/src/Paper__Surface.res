@module("react-native-paper") @react.component
external make: (
  ~theme: Paper__ThemeProvider.Theme.t=?,
  ~style: ReactNative.Style.t=?,
  ~children: React.element=?,
) => React.element = "Surface"
