@module("react-native-paper") @react.component
external make: (
  ~borderless: bool=?,
  ~centered: bool=?,
  ~background: 'a=?,
  ~disabled: bool=?,
  ~rippleColor: string=?,
  ~underlayColor: string=?,
  ~style: ReactNative.Style.t=?,
  ~theme: Paper__ThemeProvider.Theme.t=?,
  ~onPress: ReactNative.Event.pressEvent => unit=?,
  ~onLongPress: ReactNative.Event.pressEvent => unit=?,
  ~children: React.element,
) => React.element = "TouchableRipple"
