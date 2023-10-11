type route = {
  "key": string,
  "title": string,
  "icon": string,
  "color": option<string>,
  "badge": option<string>,
  "accessibilityLabel": option<string>,
  "testID": option<string>,
}

type jumpTo = string => unit

@module("react-native-paper") @react.component
external make: (
  ~onIndexChange: int => unit,
  ~renderScene: {"route": route, "jumpTo": jumpTo} => React.element,
  ~renderLabel: {"route": route, "focused": bool, "color": string} => React.element=?,
  ~getLabelText: {"route": route} => string=?,
  ~getTestID: {"route": route} => option<string>=?,
  ~getBadge: {"route": route} => option<string>=?,
  ~getColor: {"route": route} => option<string>=?,
  ~onTabPress: {"route": route} => unit=?,
  ~activeColor: string=?,
  ~inactiveColor: string=?,
  ~keyboardHidesNavigationBar: bool=?,
  ~shifting: bool=?,
  ~labeled: bool=?,
  ~navigationState: {"index": int, "routes": array<route>}=?,
  ~style: ReactNative.Style.t=?,
  ~barStyle: ReactNative.Style.t=?,
  ~theme: Paper__ThemeProvider.Theme.t=?,
) => React.element = "BottomNavigation"
