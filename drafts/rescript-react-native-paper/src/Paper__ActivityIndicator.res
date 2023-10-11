module Size: {
  type t

  let small: t
  let large: t
  let value: int => t
} = {
  type t = string

  let small: t = "small"
  let large: t = "large"
  external value: int => t = "%identity"
}

@module("react-native-paper") @react.component
external make: (
  ~animation: bool=?,
  ~hidesWhenStopped: bool=?,
  ~color: string=?,
  ~size: Size.t=?,
  ~style: ReactNative.Style.t=?,
  ~theme: Paper__ThemeProvider.Theme.t=?,
) => React.element = "ActivityIndicator"
