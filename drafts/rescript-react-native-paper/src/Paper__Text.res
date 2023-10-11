@module("react-native-paper") @react.component
external make: (
  ~selectable: bool=?,
  ~acessible: bool=?,
  ~elipsizeMode: string=?,
  ~nativeID: string=?,
  ~numberOfLines: int=?,
  ~pressRetentionOffset: {..}=?,
  ~allowFontScaling: bool=?,
  ~theme: Paper__ThemeProvider.Theme.t=?,
  ~style: ReactNative.Style.t=?,
  ~onLayout: unit => unit=?,
  ~onLongPress: unit => unit=?,
  ~onPress: unit => unit=?,
  ~testID: string=?,
  ~children: React.element,
) => React.element = "Text"
