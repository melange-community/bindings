module Section = {
  @module("react-native-paper") @scope("List") @react.component
  external make: (
    ~title: string,
    ~children: React.element,
    ~theme: Paper__ThemeProvider.Theme.t=?,
    ~style: ReactNative.Style.t=?,
    ~titleStyle: ReactNative.Style.t=?,
  ) => React.element = "Section"
}

module AccordionGroup = {
  @module("react-native-paper") @scope("List") @react.component
  external make: (
    ~onAccordionPress: string => unit=?,
    ~expandedId: string=?,
    ~children: React.element,
  ) => React.element = "AccordionGroup"
}

module Subheader = {
  @module("react-native-paper") @scope("List") @react.component
  external make: (
    ~theme: Paper__ThemeProvider.Theme.t=?,
    ~style: ReactNative.Style.t=?,
    ~children: React.element,
  ) => React.element = "Subheader"
}

module Item = {
  type leftRightProps = {
    "color": string,
    "style": {"marginLeft": float, "marginRight": float, "marginVertical": option<float>},
  }
  @module("react-native-paper") @scope("List") @react.component
  external make: (
    ~onPress: ReactNative.Event.pressEvent => unit=?,
    ~title: string,
    ~description: string=?,
    ~theme: Paper__ThemeProvider.Theme.t=?,
    ~style: ReactNative.Style.t=?,
    ~titleStyle: ReactNative.Style.t=?,
    ~descriptionStyle: ReactNative.Style.t=?,
    ~titleNumberOfLines: int=?,
    ~descriptionNumberOfLines: int=?,
    ~titleEllipsizeMode: [#head | #middle | #tail | #clip]=?,
    ~descriptionEllipsizeMode: [#head | #middle | #tail | #clip]=?,
    ~left: leftRightProps => React.element=?,
    ~right: leftRightProps => React.element=?,
  ) => React.element = "Item"
}

module Icon = {
  @module("react-native-paper") @scope("List") @react.component
  external make: (
    ~color: string=?,
    ~style: ReactNative.Style.t=?,
    ~icon: Paper__Icon.t,
  ) => React.element = "Icon"
}

module Accordion = {
  @module("react-native-paper") @scope("List") @react.component
  external make: (
    ~title: string,
    ~description: string=?,
    ~expanded: bool=?,
    ~left: {"color": string} => React.element=?,
    ~onPress: ReactNative.Event.pressEvent => unit=?,
    ~children: React.element,
    ~theme: Paper__ThemeProvider.Theme.t=?,
    ~style: ReactNative.Style.t=?,
    ~titleStyle: ReactNative.Style.t=?,
    ~descriptionStyle: ReactNative.Style.t=?,
    ~titleNumberOfLines: int=?,
    ~descriptionNumberOfLines: int=?,
    ~id: string=?,
  ) => React.element = "Section"
}
