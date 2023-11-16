type handlerStateChangeEventPayload = {
  //  Flign specific
  x: float,
  y: float,
  absoluteX: float,
  absoluteY: float,
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
  // Fling specific
  direction: option<Directions.Direction.t>,
  numberOfPointers: option<int>,
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
  // Fling specific
  config: config,
  // Common
  handlerTag: int,
  handlerName: string,
  handlers: GestureHandlerCallbacks.t,
}

// Fling specific
@send external direction: (t, Directions.Direction.t) => t = "direction"
@send external numberOfPointers: (t, int) => t = "numberOfPointers"
// Common
include GestureHandlerCommon.Methods({
  type t = t
  type gestureStateChangeEvent = handlerStateChangeEventPayload
})
