module Icon = {
  @module("react-native-paper") @scope("Avatar") @react.component
  external make: (
    ~icon: Paper__Icon.t=?,
    ~size: int=?,
    ~color: string=?,
    ~style: ReactNative.Style.t=?,
    ~theme: Paper__ThemeProvider.Theme.t=?,
  ) => React.element = "Icon"
}

module Image = {
  @module("react-native-paper") @scope("Avatar") @react.component
  external make: (
    ~source: 'source,
    ~size: int=?,
    ~style: ReactNative.Style.t=?,
    ~theme: Paper__ThemeProvider.Theme.t=?,
  ) => React.element = "Image"
}

module Text = {
  @module("react-native-paper") @scope("Avatar") @react.component
  external make: (
    ~label: string,
    ~size: int=?,
    ~color: string=?,
    ~style: ReactNative.Style.t=?,
    ~labelStyle: ReactNative.Style.t=?,
    ~theme: Paper__ThemeProvider.Theme.t=?,
  ) => React.element = "Text"
}
