@module("react-native-paper") @react.component
external make: (
  ~dismissable: bool=?,
  ~visible: bool=?,
  ~onDismiss: unit => unit=?,
  ~children: React.element,
) => React.element = "Modal"
