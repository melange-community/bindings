@module("react-native-paper") @react.component
external make: (~children: React.element, ~style: ReactNative.Style.t=?) => React.element =
  "DataTable"

module Cell = {
  @module("react-native-paper") @scope("DataTable") @react.component
  external make: (
    ~style: ReactNative.Style.t=?,
    ~children: React.element,
    ~onPress: unit => unit=?,
    ~numeric: bool=?,
  ) => React.element = "Cell"
}

module Header = {
  @module("react-native-paper") @scope("DataTable") @react.component
  external make: (
    ~style: ReactNative.Style.t=?,
    ~children: React.element,
    ~theme: Paper__ThemeProvider.Theme.t=?,
  ) => React.element = "Header"
}

module Pagination = {
  @module("react-native-paper") @scope("DataTable") @react.component
  external make: (
    ~page: int,
    ~numberOfPages: int,
    ~label: string=?,
    ~onPageChange: int => unit,
    ~style: ReactNative.Style.t=?,
    ~theme: Paper__ThemeProvider.Theme.t=?,
  ) => React.element = "Pagination"
}

module Row = {
  @module("react-native-paper") @scope("DataTable") @react.component
  external make: (
    ~children: React.element,
    ~style: ReactNative.Style.t=?,
    ~theme: Paper__ThemeProvider.Theme.t=?,
    ~onPress: unit => unit=?,
  ) => React.element = "Row"
}

module Title = {
  @module("react-native-paper") @scope("DataTable") @react.component
  external make: (
    ~children: React.element,
    ~style: ReactNative.Style.t=?,
    ~theme: Paper__ThemeProvider.Theme.t=?,
    ~onPress: unit => unit=?,
    ~numeric: bool=?,
    ~sortDirection: string=?,
    ~numberOfLines: int=?,
  ) => React.element = "Title"
}
