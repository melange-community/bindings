@module("react-native-paper") @react.component
external make: (
  ~progress: float,
  ~color: string=?,
  ~indeterminate: bool=?,
  ~visible: bool=?,
  ~theme: 'a=?,
  ~style: ReactNative.Style.t=?,
) => React.element = "ProgressBar"
