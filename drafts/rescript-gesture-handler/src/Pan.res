module Offset = {
  type t
  type asFloat = float
  type asTuple = (float, float)

  external float: asFloat => t = "%identity"
  external tuple: asTuple => t = "%identity"
}

type handlerStateChangeEventPayload = {
  //  Pan specific
  x: float,
  y: float,
  absoluteX: float,
  absoluteY: float,
  translationX: float,
  translationY: float,
  velocityX: float,
  velocityY: float,
  // Common
  handlerTag: int,
  numberOfPointers: int,
  state: GestureHandlerCommon.state,
  oldState: GestureHandlerCommon.state,
}

module GestureHandlerCallbacks = GestureHandlerCommon.GestureHandlerCallbacks.Make({
  type gestureStateChangeEvent = handlerStateChangeEventPayload
})

type config = {
  // Pan specific
  activeOffsetYStart: option<float>,
  activeOffsetYEnd: option<float>,
  activeOffsetXStart: option<float>,
  activeOffsetXEnd: option<float>,
  failOffsetYStart: option<float>,
  failOffsetYEnd: option<float>,
  failOffsetXStart: option<float>,
  failOffsetXEnd: option<float>,
  activeOffsetY: option<Offset.t>,
  activeOffsetX: option<Offset.t>,
  failOffsetX: option<Offset.t>,
  failOffsetY: option<Offset.t>,
  // Common
  enabled: option<bool>,
  shouldCancelWhenOutside: option<bool>,
  hitSlop: option<GestureHandlerCommon.HitSlop.t>,
  ref: option<Js.Nullable.t<React.ref<GestureHandlerCommon.GestureType.t>>>,
  requireToFail: option<array<GestureHandlerCommon.GestureRef.t>>,
  simultaneousWith: option<array<GestureHandlerCommon.GestureRef.t>>,
  needsPointerData: option<bool>,
  manualActivation: option<bool>,
}

type t = {
  // Pan specific
  config: config,
  // Common
  handlerTag: int,
  handlerName: string,
  handlers: GestureHandlerCallbacks.t,
}

// Pan specific
type onChangeArg = {
  x: float,
  y: float,
  absoluteX: float,
  absoluteY: float,
  translationX: float,
  translationY: float,
  velocityX: float,
  velocityY: float,
  changeX: float,
  changeY: float,
  handlerTag: int,
  numberOfPointers: int,
  state: GestureHandlerCommon.state,
}
type onChangeCallback = onChangeArg => unit
@send external activeOffsetY: (t, Offset.t) => t = "activeOffsetY"
@send external activeOffsetX: (t, Offset.t) => t = "activeOffsetX"
@send external failOffsetY: (t, Offset.t) => t = "failOffsetY"
@send external failOffsetX: (t, Offset.t) => t = "failOffsetX"
@send external minPointers: (t, int) => t = "minPointers"
@send external maxPointers: (t, int) => t = "maxPointers"
@send external minDistance: (t, int) => t = "minDistance"
@send external minVelocity: (t, int) => t = "minVelocity"
@send external minVelocityX: (t, int) => t = "minVelocityX"
@send external minVelocityY: (t, int) => t = "minVelocityY"
@send external averageTouches: (t, bool) => t = "averageTouches"
@send external enableTrackpadTwoFingerGesture: (t, bool) => t = "enableTrackpadTwoFingerGesture"
@send external onChange: (t, onChangeCallback) => t = "onChange"
// Common
include GestureHandlerCommon.Methods({
  type t = t
  type gestureStateChangeEvent = handlerStateChangeEventPayload
})
