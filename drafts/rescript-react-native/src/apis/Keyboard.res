type screenRect = {
  screenX: float,
  screenY: float,
  width: float,
  height: float,
}

type eventType = [
  | #keyboardWillShow
  | #keyboardDidShow
  | #keyboardWillHide
  | #keyboardDidHide
  | #keyboardWillChangeFrame
  | #keyboardDidChangeFrame
]

type keyboardEvent = {
  duration: float,
  easing: LayoutAnimation.animationType,
  endCoordinates: screenRect,
  startCoordinates: screenRect,
  isEventFromThisApp: bool,
}

type listener = keyboardEvent => unit

@module("react-native") @scope("Keyboard")
external addListener: (eventType, listener) => EventSubscription.t = "addListener"

@module("react-native") @scope("Keyboard")
external removeListener: (eventType, listener) => EventSubscription.t = "removeListener"

@module("react-native") @scope("Keyboard")
external dismiss: unit => unit = "dismiss"
