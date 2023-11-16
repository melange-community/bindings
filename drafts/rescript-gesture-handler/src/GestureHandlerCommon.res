type state = [#0 | #1 | #2 | #3 | #4 | #5]

type eventType = [#0 | #1 | #2 | #3 | #4]

type touchData = {id: int, x: float, y: float, absoluteX: float, absoluteY: float}

type gestureEventPayload = {numberOfPointers: int, state: state}

type gestureTouchEvent = {
  handlerTag: int,
  numberOfTouches: int,
  state: state,
  eventType: eventType,
  allTouches: array<touchData>,
  changedTouches: array<touchData>,
}

module HitSlop = {
  type t
  type asFloat = float
  type asAllSides = {
    top: option<float>,
    bottom: option<float>,
    left: option<float>,
    right: option<float>,
    vertical: option<float>,
    horizontal: option<float>,
  }
  type asWidthLeft = {
    width: float,
    left: float,
  }
  type asWidthRight = {
    width: float,
    right: float,
  }
  type asHeightTop = {
    height: float,
    top: float,
  }
  type asHeightBottom = {
    height: float,
    bottom: float,
  }

  external float: asFloat => t = "%identity"
  external allSides: asAllSides => t = "%identity"
  external widthLeft: asWidthLeft => t = "%identity"
  external widthRight: asWidthRight => t = "%identity"
  external heightTop: asHeightTop => t = "%identity"
  external heightBottom: asHeightBottom => t = "%identity"
}

type touchEventHandlerType = (gestureTouchEvent, GestureStateManager.t) => unit

module GestureHandlerCallbacks = {
  module Make = (
    T: {
      type gestureStateChangeEvent
    },
  ) => {
    type t = {
      handlerTag: int,
      onBegin: option<T.gestureStateChangeEvent => unit>,
      onStart: option<T.gestureStateChangeEvent => unit>,
      onEnd: option<(T.gestureStateChangeEvent, bool) => unit>,
      onFinalize: option<(T.gestureStateChangeEvent, bool) => unit>,
      // handlerStateUpdateEvent?
      onUpdate: option<T.gestureStateChangeEvent => unit>,
      onChange: option<T.gestureStateChangeEvent => unit>,
      onTouchesDown: option<touchEventHandlerType>,
      onTouchesMove: option<touchEventHandlerType>,
      onTouchesUp: option<touchEventHandlerType>,
      onTouchesCancelled: option<touchEventHandlerType>,
      changeEventCalculator: option<
        (gestureEventPayload, option<gestureEventPayload>) => gestureEventPayload,
      >,
      isWorklet: bool,
    }
  }
}

// FIXME This is extremely hard since this has to be some twisted
// recursive type. This literally has to be `Fling.t` | `Pan.t` | ... type
module GestureType = {
  type t
}

module GestureRef = {
  type t
  type asFloat = float
  type asGestureType = GestureType.t
  type asRef = Js.Nullable.t<React.ref<GestureType.t>>

  external float: asFloat => t = "%identity"
  external gestureType: asGestureType => t = "%identity"
  external ref: asRef => t = "%identity"
}

module Methods = (
  T: {
    type t
    type gestureStateChangeEvent
  },
) => {
  type onEndCallback = (T.gestureStateChangeEvent, bool) => unit
  type onFinalizeCallback = (T.gestureStateChangeEvent, bool) => unit
  @send external onBegin: (T.t, T.gestureStateChangeEvent => unit) => T.t = "onBegin"
  @send external onStart: (T.t, T.gestureStateChangeEvent => unit) => T.t = "onStart"
  @send external onEnd: (T.t, onEndCallback) => T.t = "onEnd"
  @send external onFinalize: (T.t, onFinalizeCallback) => T.t = "onFinalize"
  @send external onUpdate: (T.t, T.gestureStateChangeEvent => unit) => T.t = "onUpdate"
  @send
  external onTouchesDown: (T.t, touchEventHandlerType) => T.t = "onTouchesDown"
  @send external onTouchesUp: (T.t, touchEventHandlerType) => T.t = "onTouchesUp"
  @send
  external onTouchesMove: (T.t, touchEventHandlerType) => T.t = "onTouchesMove"
  @send
  external onTouchesCancelled: (T.t, touchEventHandlerType) => T.t = "onTouchesCancelled"
  @send external enabled: (T.t, bool) => T.t = "enabled"
  @send external shouldCancelWhenOutside: (T.t, bool) => T.t = "shouldCancelWhenOutside"
  @send external hitSlop: (T.t, HitSlop.t) => T.t = "hitSlop"
  // @send external simultaneousWithExternalGesture: - TODO too hard to type right now. Appears like React.ref<T.t>
  // @send external requireExternalGestureToFail: - TODO too hard to type right now. Appears like React.ref<T.t>
  @send external initialize: (T.t, unit) => unit = "initialize"
  @send external toGestureArray: (T.t, unit) => array<T.t> = "toGestureArray"
  @send external prepare: (T.t, unit) => unit = "prepare"
}
