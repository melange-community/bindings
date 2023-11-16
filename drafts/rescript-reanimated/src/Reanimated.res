type animationCallback<'t> = (option<bool>, option<'t>) => unit
// Reanimated Style is ViewStyle + TextStyle + easing, originX, and originY
type reanimatedStyle
@obj
external reanimatedStyle: (
  ~alignContent: ReanimatedStyle.alignContent=?,
  ~alignItems: ReanimatedStyle.alignItems=?,
  ~alignSelf: ReanimatedStyle.alignSelf=?,
  ~aspectRatio: float=?,
  ~backfaceVisibility: ReanimatedStyle.backfaceVisibility=?,
  ~backgroundColor: ReactNative.Color.t=?,
  ~borderBottomColor: ReactNative.Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: ReactNative.Color.t=?,
  ~borderEndColor: ReactNative.Color.t=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: ReactNative.Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: ReactNative.Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: ReactNative.Color.t=?,
  ~borderStartWidth: float=?,
  ~borderStyle: ReanimatedStyle.borderStyle=?,
  ~borderTopColor: ReactNative.Color.t=?,
  ~borderTopEndRadius: float=?,
  ~borderTopLeftRadius: float=?,
  ~borderTopRightRadius: float=?,
  ~borderTopStartRadius: float=?,
  ~borderTopWidth: float=?,
  ~borderWidth: float=?,
  ~bottom: ReanimatedStyle.size=?,
  ~direction: ReanimatedStyle.direction=?,
  ~display: ReanimatedStyle.display=?,
  ~easing: float => float=?,
  ~elevation: float=?,
  ~end: ReanimatedStyle.size=?,
  ~flex: float=?,
  ~flexBasis: ReanimatedStyle.margin=?,
  ~flexDirection: ReanimatedStyle.flexDirection=?,
  ~flexGrow: float=?,
  ~flexShrink: float=?,
  ~flexWrap: ReanimatedStyle.flexWrap=?,
  ~height: ReanimatedStyle.size=?,
  ~justifyContent: ReanimatedStyle.justifyContent=?,
  ~left: ReanimatedStyle.size=?,
  ~margin: ReanimatedStyle.margin=?,
  ~marginBottom: ReanimatedStyle.margin=?,
  ~marginEnd: ReanimatedStyle.margin=?,
  ~marginHorizontal: ReanimatedStyle.margin=?,
  ~marginLeft: ReanimatedStyle.margin=?,
  ~marginRight: ReanimatedStyle.margin=?,
  ~marginStart: ReanimatedStyle.margin=?,
  ~marginTop: ReanimatedStyle.margin=?,
  ~marginVertical: ReanimatedStyle.margin=?,
  ~maxHeight: ReanimatedStyle.size=?,
  ~maxWidth: ReanimatedStyle.size=?,
  ~minHeight: ReanimatedStyle.size=?,
  ~minWidth: ReanimatedStyle.size=?,
  ~opacity: float=?,
  ~originX: float=?,
  ~originY: float=?,
  ~overflow: ReanimatedStyle.overflow=?,
  ~padding: ReanimatedStyle.size=?,
  ~paddingBottom: ReanimatedStyle.size=?,
  ~paddingEnd: ReanimatedStyle.size=?,
  ~paddingHorizontal: ReanimatedStyle.size=?,
  ~paddingLeft: ReanimatedStyle.size=?,
  ~paddingRight: ReanimatedStyle.size=?,
  ~paddingStart: ReanimatedStyle.size=?,
  ~paddingTop: ReanimatedStyle.size=?,
  ~paddingVertical: ReanimatedStyle.size=?,
  ~position: ReanimatedStyle.position=?,
  ~right: ReanimatedStyle.size=?,
  ~shadowColor: ReactNative.Color.t=?,
  ~shadowOffset: ReanimatedStyle.offset=?,
  ~shadowOpacity: float=?,
  ~shadowRadius: float=?,
  ~start: ReanimatedStyle.size=?,
  ~top: ReanimatedStyle.size=?,
  ~transform: array<ReanimatedStyle.transform>=?,
  ~width: ReanimatedStyle.size=?,
  ~zIndex: int=?,
  unit,
) => reanimatedStyle = ""

module LayoutAnimation = {
  type t
  module Modifiers = {
    @send
    external duration: (t, float) => t = "duration"
    @send
    external delay: (t, float) => t = "delay"
    @send
    external easing: ('c, t, animationCallback<'c>) => t = "easing"
    @send
    external springify: t => t = "springify"
    @send
    external damping: (t, float) => t = "damping"
    @send
    external mass: (t, float) => t = "mass"
    @send
    external stiffness: (t, float) => t = "stiffness"
    @send
    external overshootClamping: (t, bool) => t = "overshootClamping"
    @send
    external restDisplacementThreshold: (t, float) => t = "restDisplacementThreshold"
    @send
    external restSpeedThreshold: (t, float) => t = "restSpeedThreshold"
    @send
    external withCallback: (t, bool => unit) => t = "withCallback"
    @send
    external withInitialValues: (t, float) => t = "withInitialValues"
    @send
    external randomDelay: t => t = "randomDelay"
  }
  include Modifiers

  @module("react-native-reanimated")
  external fadeIn: t = "FadeIn"
  @module("react-native-reanimated")
  external fadeInRight: t = "FadeInRight"
  @module("react-native-reanimated")
  external fadeInLeft: t = "FadeInLeft"
  @module("react-native-reanimated")
  external fadeInUp: t = "FadeInUp"
  @module("react-native-reanimated")
  external fadeInDown: t = "FadeInDown"
  @module("react-native-reanimated")
  external bounceIn: t = "BounceIn"
  @module("react-native-reanimated")
  external bounceInRight: t = "BounceInRight"
  @module("react-native-reanimated")
  external bounceInLeft: t = "BounceInLeft"
  @module("react-native-reanimated")
  external bounceInUp: t = "BounceInUp"
  @module("react-native-reanimated")
  external bounceInDown: t = "BounceInDown"
  @module("react-native-reanimated")
  external flipInYRight: t = "FlipInYRight"
  @module("react-native-reanimated")
  external flipInYLeft: t = "FlipInYLeft"
  @module("react-native-reanimated")
  external flipInXUp: t = "FlipInXUp"
  @module("react-native-reanimated")
  external flipInXDown: t = "FlipInXDown"
  @module("react-native-reanimated")
  external flipInEasyX: t = "FlipInEasyX"
  @module("react-native-reanimated")
  external flipInEasyY: t = "FlipInEasyY"
  @module("react-native-reanimated")
  external stretchInX: t = "StretchInX"
  @module("react-native-reanimated")
  external stretchInY: t = "StretchInY"
  @module("react-native-reanimated")
  external zoomIn: t = "ZoomIn"
  @module("react-native-reanimated")
  external zoomInRotate: t = "ZoomInRotate"
  @module("react-native-reanimated")
  external zoomInRight: t = "ZoomInRight"
  @module("react-native-reanimated")
  external zoomInLeft: t = "ZoomInLeft"
  @module("react-native-reanimated")
  external zoomInUp: t = "ZoomInUp"
  @module("react-native-reanimated")
  external zoomInDown: t = "ZoomInDown"
  @module("react-native-reanimated")
  external zoomInEasyUp: t = "ZoomInEasyUp"
  @module("react-native-reanimated")
  external zoomInEasyDown: t = "ZoomInEasyDown"
  @module("react-native-reanimated")
  external slideInRight: t = "SlideInRight"
  @module("react-native-reanimated")
  external slideInLeft: t = "SlideInLeft"
  @module("react-native-reanimated")
  external slideInUp: t = "SlideInUp"
  @module("react-native-reanimated")
  external slideInDown: t = "SlideInDown"
  @module("react-native-reanimated")
  external lightSpeedInRight: t = "LightSpeedInRight"
  @module("react-native-reanimated")
  external lightSpeedInLeft: t = "LightSpeedInLeft"
  @module("react-native-reanimated")
  external pinwheelIn: t = "PinwheelIn"
  @module("react-native-reanimated")
  external rollInLeft: t = "RollInLeft"
  @module("react-native-reanimated")
  external rollInRight: t = "RollInRight"
  @module("react-native-reanimated")
  external rotateInDownLeft: t = "RotateInDownLeft"
  @module("react-native-reanimated")
  external rotateInDownRight: t = "RotateInDownRight"
  @module("react-native-reanimated")
  external rotateInUpLeft: t = "RotateInUpLeft"
  @module("react-native-reanimated")
  external rotateInUpRight: t = "RotateInUpRight"
}
include LayoutAnimation

module KeyFrame = {
  type keyframeConfig = {
    from?: reanimatedStyle,
    to?: reanimatedStyle,
    // This looks a little bit stupid, but this has better developer experience and type inference than using a dict/object.
    @as("0") _0?: reanimatedStyle,
    @as("1") _1?: reanimatedStyle,
    @as("2") _2?: reanimatedStyle,
    @as("3") _3?: reanimatedStyle,
    @as("4") _4?: reanimatedStyle,
    @as("5") _5?: reanimatedStyle,
    @as("6") _6?: reanimatedStyle,
    @as("7") _7?: reanimatedStyle,
    @as("8") _8?: reanimatedStyle,
    @as("9") _9?: reanimatedStyle,
    @as("10") _10?: reanimatedStyle,
    @as("11") _11?: reanimatedStyle,
    @as("12") _12?: reanimatedStyle,
    @as("13") _13?: reanimatedStyle,
    @as("14") _14?: reanimatedStyle,
    @as("15") _15?: reanimatedStyle,
    @as("16") _16?: reanimatedStyle,
    @as("17") _17?: reanimatedStyle,
    @as("18") _18?: reanimatedStyle,
    @as("19") _19?: reanimatedStyle,
    @as("20") _20?: reanimatedStyle,
    @as("21") _21?: reanimatedStyle,
    @as("22") _22?: reanimatedStyle,
    @as("23") _23?: reanimatedStyle,
    @as("24") _24?: reanimatedStyle,
    @as("25") _25?: reanimatedStyle,
    @as("26") _26?: reanimatedStyle,
    @as("27") _27?: reanimatedStyle,
    @as("28") _28?: reanimatedStyle,
    @as("29") _29?: reanimatedStyle,
    @as("30") _30?: reanimatedStyle,
    @as("31") _31?: reanimatedStyle,
    @as("32") _32?: reanimatedStyle,
    @as("33") _33?: reanimatedStyle,
    @as("34") _34?: reanimatedStyle,
    @as("35") _35?: reanimatedStyle,
    @as("36") _36?: reanimatedStyle,
    @as("37") _37?: reanimatedStyle,
    @as("38") _38?: reanimatedStyle,
    @as("39") _39?: reanimatedStyle,
    @as("40") _40?: reanimatedStyle,
    @as("41") _41?: reanimatedStyle,
    @as("42") _42?: reanimatedStyle,
    @as("43") _43?: reanimatedStyle,
    @as("44") _44?: reanimatedStyle,
    @as("45") _45?: reanimatedStyle,
    @as("46") _46?: reanimatedStyle,
    @as("47") _47?: reanimatedStyle,
    @as("48") _48?: reanimatedStyle,
    @as("49") _49?: reanimatedStyle,
    @as("50") _50?: reanimatedStyle,
    @as("51") _51?: reanimatedStyle,
    @as("52") _52?: reanimatedStyle,
    @as("53") _53?: reanimatedStyle,
    @as("54") _54?: reanimatedStyle,
    @as("55") _55?: reanimatedStyle,
    @as("56") _56?: reanimatedStyle,
    @as("57") _57?: reanimatedStyle,
    @as("58") _58?: reanimatedStyle,
    @as("59") _59?: reanimatedStyle,
    @as("60") _60?: reanimatedStyle,
    @as("61") _61?: reanimatedStyle,
    @as("62") _62?: reanimatedStyle,
    @as("63") _63?: reanimatedStyle,
    @as("64") _64?: reanimatedStyle,
    @as("65") _65?: reanimatedStyle,
    @as("66") _66?: reanimatedStyle,
    @as("67") _67?: reanimatedStyle,
    @as("68") _68?: reanimatedStyle,
    @as("69") _69?: reanimatedStyle,
    @as("70") _70?: reanimatedStyle,
    @as("71") _71?: reanimatedStyle,
    @as("72") _72?: reanimatedStyle,
    @as("73") _73?: reanimatedStyle,
    @as("74") _74?: reanimatedStyle,
    @as("75") _75?: reanimatedStyle,
    @as("76") _76?: reanimatedStyle,
    @as("77") _77?: reanimatedStyle,
    @as("78") _78?: reanimatedStyle,
    @as("79") _79?: reanimatedStyle,
    @as("80") _80?: reanimatedStyle,
    @as("81") _81?: reanimatedStyle,
    @as("82") _82?: reanimatedStyle,
    @as("83") _83?: reanimatedStyle,
    @as("84") _84?: reanimatedStyle,
    @as("85") _85?: reanimatedStyle,
    @as("86") _86?: reanimatedStyle,
    @as("87") _87?: reanimatedStyle,
    @as("88") _88?: reanimatedStyle,
    @as("89") _89?: reanimatedStyle,
    @as("90") _90?: reanimatedStyle,
    @as("91") _91?: reanimatedStyle,
    @as("92") _92?: reanimatedStyle,
    @as("93") _93?: reanimatedStyle,
    @as("94") _94?: reanimatedStyle,
    @as("95") _95?: reanimatedStyle,
    @as("96") _96?: reanimatedStyle,
    @as("97") _97?: reanimatedStyle,
    @as("98") _98?: reanimatedStyle,
    @as("99") _99?: reanimatedStyle,
    @as("100") _100?: reanimatedStyle,
  }
  @new
  @module("react-native-reanimated")
  /** 
Receives a keyframe config with the style of each step. It returns a layout animation that can be used with modifiers, like duration.

Example:
 ```
  let exitKeyframe = keyframe({
    from: reanimatedStyle(~transform=[translateY(~translateY=0.)], ~opacity=1., ()),
    to: reanimatedStyle(~transform=[translateY(~translateY=-60.)], ~opacity=0., ()),
  })->duration(50.)

  <Reanimated.View exiting=exitKeyframe />
  ```
 */
  external keyframe: keyframeConfig => LayoutAnimation.t = "Keyframe"
}
include KeyFrame

module View = {
  @react.component @module("./exports")
  external make: (
    ~style: ReactNative.Style.t=?,
    ~children: React.element=?,
    ~onLayout: ReactNative.Event.layoutEvent => unit=?,
    ~entering: LayoutAnimation.t=?,
    ~exiting: LayoutAnimation.t=?,
    ~pointerEvents: @string
    [
      | #auto
      | #none
      | @as("box-none") #boxNone
      | @as("box-only") #boxOnly
    ]=?,
  ) => React.element = "AnimatedView"
}

module Text = {
  @react.component @module("./exports")
  external make: (
    ~style: ReactNative.Style.t=?,
    ~children: React.element=?,
    ~entering: LayoutAnimation.t=?,
    ~exiting: LayoutAnimation.t=?,
  ) => React.element = "AnimatedText"
}
module ScrollView = {
  @react.component @module("./exports")
  external make: (
    ~entering: LayoutAnimation.t=?,
    ~exiting: LayoutAnimation.t=?,
    ~alwaysBounceHorizontal: bool=?,
    ~alwaysBounceVertical: bool=?,
    ~automaticallyAdjustContentInsets: bool=?,
    ~bounces: bool=?,
    ~bouncesZoom: bool=?,
    ~canCancelContentTouches: bool=?,
    ~centerContent: bool=?,
    ~contentContainerStyle: ReactNative.Style.t=?,
    ~contentInset: ReactNative.View.edgeInsets=?,
    ~contentInsetAdjustmentBehavior: ReactNative.ScrollView.contentInsetAdjustmentBehavior=?,
    ~contentOffset: ReactNative.ScrollView.contentOffset=?,
    ~decelerationRate: ReactNative.ScrollView.decelerationRate=?,
    ~directionalLockEnabled: bool=?,
    ~endFillColor: ReactNative.Color.t=?,
    ~fadingEdgeLength: float=?,
    ~horizontal: bool=?,
    ~indicatorStyle: ReactNative.ScrollView.indicatorStyle=?,
    ~keyboardDismissMode: @string
    [
      | #none
      | #interactive
      | @as("on-drag") #onDrag
    ]=?,
    ~keyboardShouldPersistTaps: ReactNative.ScrollView.keyboardShouldPersistTaps=?,
    ~maximumZoomScale: float=?,
    ~minimumZoomScale: float=?,
    ~nestedScrollEnabled: bool=?,
    ~onContentSizeChange: ((float, float)) => unit=?,
    ~onMomentumScrollBegin: ReactNative.Event.scrollEvent => unit=?,
    ~onMomentumScrollEnd: ReactNative.Event.scrollEvent => unit=?,
    ~onScroll: ReactNative.Event.scrollEvent => unit=?,
    ~onScrollBeginDrag: ReactNative.Event.scrollEvent => unit=?,
    ~onScrollEndDrag: ReactNative.Event.scrollEvent => unit=?,
    ~overScrollMode: ReactNative.ScrollView.overScrollMode=?,
    ~pagingEnabled: bool=?,
    ~pinchGestureEnabled: bool=?,
    ~refreshControl: React.element=?,
    ~scrollEnabled: bool=?,
    ~scrollEventThrottle: int=?,
    ~scrollIndicatorInsets: ReactNative.View.edgeInsets=?,
    ~scrollPerfTag: string=?,
    ~scrollsToTop: bool=?,
    ~scrollToOverflowEnabled: bool=?,
    ~showsHorizontalScrollIndicator: bool=?,
    ~showsVerticalScrollIndicator: bool=?,
    ~snapToAlignment: ReactNative.ScrollView.snapToAlignment=?,
    ~snapToEnd: bool=?,
    ~snapToInterval: float=?,
    ~snapToOffsets: array<float>=?,
    ~snapToStart: bool=?,
    ~stickyHeaderHiddenOnScroll: bool=?,
    ~stickyHeaderIndices: array<int>=?,
    ~zoomScale: float=?,
    // rescript-react-native 0.64 || 0.65 || 0.66 View props
    ~accessibilityActions: array<ReactNative.Accessibility.actionInfo>=?,
    ~accessibilityElementsHidden: bool=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityLabel: string=?,
    ~accessibilityLiveRegion: ReactNative.Accessibility.liveRegion=?,
    ~accessibilityRole: ReactNative.Accessibility.role=?,
    ~accessibilityState: ReactNative.Accessibility.state=?,
    ~accessibilityValue: ReactNative.Accessibility.value=?,
    ~accessibilityViewIsModal: bool=?,
    ~accessible: bool=?,
    ~collapsable: bool=?,
    ~hitSlop: ReactNative.View.edgeInsets=?,
    ~importantForAccessibility: @string
    [
      | #auto
      | #yes
      | #no
      | @as("no-hide-descendants") #noHideDescendants
    ]=?,
    ~nativeID: string=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~onAccessibilityAction: ReactNative.Accessibility.actionEvent => unit=?,
    ~onAccessibilityEscape: unit => unit=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: ReactNative.Event.layoutEvent => unit=?,
    ~onMagicTap: unit => unit=?,
    // Gesture Responder props
    ~onMoveShouldSetResponder: ReactNative.Event.pressEvent => bool=?,
    ~onMoveShouldSetResponderCapture: ReactNative.Event.pressEvent => bool=?,
    ~onResponderEnd: ReactNative.Event.pressEvent => unit=?,
    ~onResponderGrant: ReactNative.Event.pressEvent => unit=?,
    ~onResponderMove: ReactNative.Event.pressEvent => unit=?,
    ~onResponderReject: ReactNative.Event.pressEvent => unit=?,
    ~onResponderRelease: ReactNative.Event.pressEvent => unit=?,
    ~onResponderStart: ReactNative.Event.pressEvent => unit=?,
    ~onResponderTerminate: ReactNative.Event.pressEvent => unit=?,
    ~onResponderTerminationRequest: ReactNative.Event.pressEvent => bool=?,
    ~onStartShouldSetResponder: ReactNative.Event.pressEvent => bool=?,
    ~onStartShouldSetResponderCapture: ReactNative.Event.pressEvent => bool=?,
    ~pointerEvents: @string
    [
      | #auto
      | #none
      | @as("box-none") #boxNone
      | @as("box-only") #boxOnly
    ]=?,
    ~removeClippedSubviews: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~style: ReactNative.Style.t=?,
    ~testID: string=?,
    ~children: React.element=?,
    // react-native-web 0.16 View props
    ~href: string=?,
    ~hrefAttrs: ReactNative.Web.hrefAttrs=?,
    ~onMouseDown: ReactEvent.Mouse.t => unit=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onMouseMove: ReactEvent.Mouse.t => unit=?,
    ~onMouseOver: ReactEvent.Mouse.t => unit=?,
    ~onMouseOut: ReactEvent.Mouse.t => unit=?,
    ~onMouseUp: ReactEvent.Mouse.t => unit=?,
  ) => React.element = "AnimatedScrollView"
}

type reanimatedScrollHandler = ReactNative.Event.ScrollEvent.payload => unit

type handlers = {
  onMomentumEnd?: reanimatedScrollHandler,
  onBeginDrag?: reanimatedScrollHandler,
  onEndDrag?: reanimatedScrollHandler,
  onMomentumBegin?: reanimatedScrollHandler,
  onScroll?: reanimatedScrollHandler,
}

type scrollHandler = ReactNative.Event.scrollEvent => unit

@module("react-native-reanimated")
/** 
Receives a record of scroll event handlers and returns a single handler that can be passed to Reanimated.ScrollView


Example:
 ```
let scrollHandler = useAnimatedScrollHandler({
    onScroll: event => {
      translationY.value = event.contentOffset.y
    },
  })

  <Reanimated.ScrollView onScroll=scrollHandler />
  ```
 */
external useAnimatedScrollHandler: handlers => scrollHandler = "useAnimatedScrollHandler"

module AnimatedGestureHandler = {
  module Make = (
    Arguments: {
      type event
      type ctx
    },
  ) => {
    type t = {
      onStart: option<(Arguments.event, Arguments.ctx) => unit>,
      onActive: option<(Arguments.event, Arguments.ctx) => unit>,
      onEnd: option<(Arguments.event, Arguments.ctx) => unit>,
      onFail: option<(Arguments.event, Arguments.ctx) => unit>,
      onCancel: option<(Arguments.event, Arguments.ctx) => unit>,
      onFinish: option<(Arguments.event, Arguments.ctx) => unit>,
    }

    @obj
    external makeGestureHandlers: (
      ~onStart: (Arguments.event, Arguments.ctx) => unit=?,
      ~onActive: (Arguments.event, Arguments.ctx) => unit=?,
      ~onEnd: (Arguments.event, Arguments.ctx) => unit=?,
      ~onFail: (Arguments.event, Arguments.ctx) => unit=?,
      ~onCancel: (Arguments.event, Arguments.ctx) => unit=?,
      ~onFinish: (Arguments.event, Arguments.ctx) => unit=?,
      unit,
    ) => t = ""

    type _returnType = Arguments.event => unit
    type _gestureHandlers = t

    @module("react-native-reanimated")
    external useAnimatedGestureHandler: _gestureHandlers => _returnType =
      "useAnimatedGestureHandler"
    @module("react-native-reanimated")
    external useAnimatedGestureHandler0: (_gestureHandlers, @as(json`[]`) _) => _returnType =
      "useAnimatedGestureHandler"
    @module("react-native-reanimated")
    external useAnimatedGestureHandle1: (_gestureHandlers, array<'a>) => _returnType =
      "useAnimatedGestureHandler"
    @module("react-native-reanimated")
    external useAnimatedGestureHandle2: (_gestureHandlers, ('a, 'b)) => _returnType =
      "useAnimatedGestureHandler"
    @module("react-native-reanimated")
    external useAnimatedGestureHandle3: (_gestureHandlers, ('a, 'b, 'c)) => _returnType =
      "useAnimatedGestureHandler"
    @module("react-native-reanimated")
    external useAnimatedGestureHandle4: (_gestureHandlers, ('a, 'b, 'c, 'd)) => _returnType =
      "useAnimatedGestureHandler"
  }
}

@module("react-native-reanimated")
external runOnUI: ('arg => 'return, . 'arg) => unit = "runOnUI"

@module("react-native-reanimated")
external runOnJS: ('arg => 'return, . 'arg) => unit = "runOnJS"

module SharedValue = {
  type t<'t> = {mutable value: 't}
  let make: 't => t<'t> = smth => {value: smth}
}

@module("react-native-reanimated")
external useSharedValue: 't => SharedValue.t<'t> = "useSharedValue"

module Timing = {
  type justDuration = {duration: float}

  type justEasing = {easing: ReactNative.Easing.t}

  type both = {
    duration: float,
    easing: ReactNative.Easing.t,
  }

  let makeConfig = (~duration: option<float>=?, ~easing: option<ReactNative.Easing.t>=?, ()) => {
    switch (duration, easing) {
    | (Some(duration), None) => Some(#Duration({duration: duration}))
    | (None, Some(easing)) => Some(#Easing({easing: easing}))
    | (Some(duration), Some(easing)) => Some(#Both({duration, easing}))
    | (None, None) => None
    }
  }

  // DO NOT USE OR YOU WILL GET FIRED ;)
  @module("react-native-reanimated")
  external withTiming_: (
    't,
    @unwrap
    [#Duration(justDuration) | #Easing(justEasing) | #Both(both) | #Nothing(option<string>)],
    option<animationCallback<'t>>,
  ) => float = "withTiming"
}

let withTiming = (
  ~toValue: 't,
  ~userConfig: option<
    [#Duration(Timing.justDuration) | #Easing(Timing.justEasing) | #Both(Timing.both)],
  >,
  ~callback: option<animationCallback<'t>>=?,
  (),
) => {
  Timing.withTiming_(
    toValue,
    switch userConfig {
    | Some(#Duration(durationObj)) => #Duration(durationObj)
    | Some(#Easing(easingObj)) => #Easing(easingObj)
    | Some(#Both(bothObj)) => #Both(bothObj)
    | None => #Nothing(None)
    },
    callback,
  )
}

module Spring = {
  type config = {
    mass: option<float>,
    stiffness: option<float>,
    overshootClamping: option<bool>,
    restDisplacementThreshold: option<float>,
    restSpeedThreshold: option<float>,
    velocity: option<float>,
    damping: option<float>,
  }
  let makeConfig = (
    ~mass: option<float>=?,
    ~stiffness: option<float>=?,
    ~overshootClamping: option<bool>=?,
    ~restDisplacementThreshold: option<float>=?,
    ~restSpeedThreshold: option<float>=?,
    ~velocity: option<float>=?,
    ~damping: option<float>=?,
    (),
  ) => {
    mass,
    stiffness,
    overshootClamping,
    restDisplacementThreshold,
    restSpeedThreshold,
    velocity,
    damping,
  }
  @module("react-native-reanimated")
  external withSpring_: ('t, option<config>, option<animationCallback<'t>>) => float = "withSpring"
}

let withSpring = (
  ~toValue: 't,
  ~userConfig: option<Spring.config>=?,
  ~callback: option<animationCallback<'t>>=?,
  (),
) => {
  Spring.withSpring_(toValue, userConfig, callback)
}

@module("react-native-reanimated")
external useAnimatedStyle: (@uncurry (unit => ReactNative.Style.t)) => ReactNative.Style.t =
  "useAnimatedStyle"
@module("react-native-reanimated")
external useAnimatedStyle0: (
  @uncurry (unit => ReactNative.Style.t),
  @as(json`[]`) _,
) => ReactNative.Style.t = "useAnimatedStyle"
@module("react-native-reanimated")
external useAnimatedStyle1: (
  @uncurry (unit => ReactNative.Style.t),
  array<'a>,
) => ReactNative.Style.t = "useAnimatedStyle"
@module("react-native-reanimated")
external useAnimatedStyle2: (
  @uncurry (unit => ReactNative.Style.t),
  ('a, 'b),
) => ReactNative.Style.t = "useAnimatedStyle"
@module("react-native-reanimated")
external useAnimatedStyle3: (
  @uncurry (unit => ReactNative.Style.t),
  ('a, 'b, 'c),
) => ReactNative.Style.t = "useAnimatedStyle"
@module("react-native-reanimated")
external useAnimatedStyle4: (
  @uncurry (unit => ReactNative.Style.t),
  ('a, 'b, 'c, 'd),
) => ReactNative.Style.t = "useAnimatedStyle"

module Extrapolation = {
  type t

  type extrapolation = {
    @as("IDENTITY") identity: [#identity],
    @as("CLAMP") clamp: [#clamp],
    @as("EXTEND") extend: [#extend],
  }

  external asExtrapolation: extrapolation => t = "%identity"
  external asString: string => t = "%identity"
}

type extrapolationConfig = {
  extrapolateLeft: option<Extrapolation.t>,
  extrapolateRight: option<Extrapolation.t>,
}

module ExtrapolationType = {
  type t

  external asExtrapolation: Extrapolation.extrapolation => t = "%identity"
  external asExtrapolationConfig: extrapolationConfig => t = "%identity"
  external asString: string => t = "%identity"
}

module Interpolate = {
  type x = float
  type input = array<float>
  type output = array<float>
  type type_ = option<ExtrapolationType.t>
}

// Turn into named arguments maybe?
@module("react-native-reanimated")
external interpolate: (
  Interpolate.x,
  Interpolate.input,
  Interpolate.output,
  Interpolate.type_,
) => float = "interpolate"

@module("react-native-reanimated")
external interpolateColor: (
  float,
  array<float>,
  array<ReactNative.Color.t>,
  option<[#RGB | #HSV]>,
) => ReactNative.Color.t = "interpolateColor"
