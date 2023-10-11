@module("react-native-paper") @react.component
external make: (
  ~value: string,
  ~status: [#checked | #unchecked],
  ~theme: Paper__ThemeProvider.Theme.t=?,
  ~disabled: bool=?,
  ~uncheckedColor: string=?,
  ~color: string=?,
  ~onPress: ReactNative.Event.pressEvent => unit=?,
) => React.element = "RadioButton"

module Android = {
  @module("react-native-paper") @scope("RadioButton") @react.component
  external make: (
    ~value: string,
    ~status: [#checked | #unchecked],
    ~theme: Paper__ThemeProvider.Theme.t=?,
    ~disabled: bool=?,
    ~uncheckedColor: string=?,
    ~color: string=?,
    ~onPress: ReactNative.Event.pressEvent => unit=?,
  ) => React.element = "Android"
}

module IOS = {
  @module("react-native-paper") @scope("RadioButton") @react.component
  external make: (
    ~value: string,
    ~status: [#checked | #unchecked],
    ~theme: Paper__ThemeProvider.Theme.t=?,
    ~disabled: bool=?,
    ~color: string=?,
    ~onPress: ReactNative.Event.pressEvent => unit=?,
  ) => React.element = "IOS"
}

module Group = {
  @module("react-native-paper") @scope("RadioButton") @react.component
  external make: (
    ~value: string,
    ~onValueChange: string => string,
    ~children: React.element,
  ) => React.element = "Group"
}
