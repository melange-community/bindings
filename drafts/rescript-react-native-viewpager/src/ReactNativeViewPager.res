open ReactNative
include ViewPagerElement

module PageScrollEvent = {
  type payload = {
    position: int,
    offset: float,
  }
  include Event.SyntheticEvent({
    type _payload = payload
  })
}

module PageSelectedEvent = {
  type payload = {position: float}
  include Event.SyntheticEvent({
    type _payload = payload
  })
}

module PageScrollStateChangedEvent = {
  // new bs new polyvar encoding
  //type payload = {pageScrollState: [ | `idle | `dragging | `settling]};
  type payload = {pageScrollState: string}
  include Event.SyntheticEvent({
    type _payload = payload
  })
}

@module("@react-native-community/viewpager") @react.component
external make: (
  ~ref: ref=?,
  ~initialPage: int=?,
  ~scrollEnabled: bool=?,
  ~onPageScroll: PageScrollEvent.t => unit=?,
  ~onPageSelected: PageSelectedEvent.t => unit=?,
  ~onPageScrollStateChanged: PageScrollStateChangedEvent.t => unit=?,
  ~keyboardDismissMode: @string [#none | @as("on-drag") #onDrag]=?,
  ~pageMargin: int=?,
  ~onMoveShouldSetResponderCapture: ReactNative.Event.pressEvent => bool=?,
  ~style: ReactNative.Style.t=?,
  ~children: React.element=?,
  ~orientation: [#horizontal | #vertical]=?,
  ~transitionStyle: [#scroll | #curl]=?,
  ~showPageIndicator: bool=?,
  ~overScrollMode: ScrollView.overScrollMode=?,
) => React.element = "default"
