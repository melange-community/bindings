open ReactNative

type size = Style.size
type sizes = array<size>
type opacity = string
external opacity: float => opacity = "%identity"

type baselineShift = [#sub | #super | #baseline]
type clipRule = [#evenodd | #nonzero]
type fillRule = [#evenodd | #nonzero]
type fontStyle = [#normal | #italic | #oblique]
type fontVariant = [#normal | #smallcaps]
type fontVariantLigatures = [#normal | #none]
type gradientUnits = [#userSpaceOnUse | #objectBoundingBox]
type lengthAdjust = [#spacing | #spacingAndGlyphs]
type markerUnits = [#userSpaceOnUse | #strokeWidth]
type maskContentUnits = [#userSpaceOnUse | #objectBoundingBox]
type maskUnits = [#userSpaceOnUse | #objectBoundingBox]
type method_ = [#align | #stretch]
type midLine = [#sharp | #smooth]
type patternContentUnits = [#userSpaceOnUse | #objectBoundingBox]
type patternUnits = [#userSpaceOnUse | #objectBoundingBox]
type spacing = [#auto | #exact]
type strokeLinecap = [#butt | #square | #round]
type strokeLinejoin = [#miter | #bevel | #round]

// https://github.com/react-native-community/react-native-svg#use-with-xml-strings
module SvgXml = {
  @react.component @module("react-native-svg")
  external make: (
    ~xml: string,
    ~width: size=?,
    ~height: size=?,
    ~style: Style.t=?,
  ) => React.element = "SvgXml"
}

// https://github.com/react-native-community/react-native-svg#css-support
module SvgCss = {
  @react.component @module("react-native-svg")
  external make: (
    ~xml: string,
    ~width: size=?,
    ~height: size=?,
    ~style: Style.t=?,
  ) => React.element = "SvgCss"
}

// @todo?
// SvgFromXml
// SvgUri
// SvgFromUri
// SvgWithCss
// SvgCssUri
// SvgWithCssUri

// https://github.com/react-native-community/react-native-svg#svg
module Svg = {
  @react.component @module("react-native-svg")
  external make: (
    ~color: Color.t=?,
    ~viewBox: string=?,
    ~opacity: opacity=?,
    ~onLayout: unit => unit=?,
    ~preserveAspectRatio: string=?,
    ~style: Style.t=?,
    ~width: size=?,
    ~height: size=?,
    ~children: React.element=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "Svg"
}

module Rect = {
  @react.component @module("react-native-svg")
  external make: (
    ~width: size=?,
    ~height: size=?,
    ~rx: size=?,
    ~ry: size=?,
    ~opacity: opacity=?,
    ~children: React.element=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "Rect"
}

module Circle = {
  @react.component @module("react-native-svg")
  external make: (
    ~cx: size=?,
    ~cy: size=?,
    ~r: size=?,
    ~opacity: opacity=?,
    ~children: React.element=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "Circle"
}

module Ellipse = {
  @react.component @module("react-native-svg")
  external make: (
    ~cx: size=?,
    ~cy: size=?,
    ~rx: size=?,
    ~ry: size=?,
    ~opacity: opacity=?,
    ~children: React.element=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "Ellipse"
}

module Line = {
  @react.component @module("react-native-svg")
  external make: (
    ~x1: size=?,
    ~y1: size=?,
    ~x2: size=?,
    ~y2: size=?,
    ~opacity: opacity=?,
    ~children: React.element=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "Line"
}

module Polygon = {
  @react.component @module("react-native-svg")
  external make: (
    ~points: string=?,
    ~opacity: opacity=?,
    ~children: React.element=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "Polygon"
}

module Polyline = {
  @react.component @module("react-native-svg")
  external make: (
    ~points: string=?,
    ~opacity: opacity=?,
    ~children: React.element=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "Polyline"
}

module Path = {
  @react.component @module("react-native-svg")
  external make: (
    ~d: string=?,
    ~opacity: opacity=?,
    ~children: React.element=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "Path"
}

module Text = {
  @react.component @module("react-native-svg")
  external make: (
    ~dx: size=?,
    ~dy: size=?,
    ~rotate: size=?,
    ~inlineSize: size=?,
    ~opacity: opacity=?,
    ~children: React.element=?,
    // Text props
    ~alignmentBaseline: @string
    [
      | #baseline
      | @as("text-bottom") #textBottom
      | #alphabetic
      | #ideographic
      | #middle
      | #central
      | #mathematical
      | @as("text-top") #textTop
      | #bottom
      | #center
      | #top
      | @as("text-before-edge") #textBeforeEdge
      | @as("text-after-edge") #textAfterEdge
      | @as("before-edge") #beforeEdge
      | @as("after-edge") #afterEdge
      | #hanging
    ]=?,
    ~baselineShift: baselineShift=?,
    ~verticalAlign: size=?,
    ~lengthAdjust: lengthAdjust=?,
    ~textLength: string=?,
    // ~fontData: todo=?,
    ~fontFeatureSettings: string=?,
    // Font Props
    ~fontStyle: fontStyle=?,
    ~fontVariant: fontVariant=?,
    ~fontWeight: @string
    [
      | #normal
      | #bold
      | #bolder
      | #lighter
      | @as("100") #_100
      | @as("200") #_200
      | @as("300") #_300
      | @as("400") #_400
      | @as("500") #_500
      | @as("600") #_600
      | @as("700") #_700
      | @as("800") #_800
      | @as("900") #_900
    ]=?,
    ~fontStretch: @string
    [
      | #normal
      | #wider
      | #narrower
      | @as("ultra-condensed") #ultraCondensed
      | @as("extra-condensed") #extraCondensed
      | #condensed
      | @as("semi-condensed") #semiCondensed
      | @as("semi-expanded") #semiExpanded
      | #expanded
      | @as("extra-expanded") #extraExpanded
      | @as("ultra-expanded") #ultraExpanded
    ]=?,
    ~fontSize: size=?,
    ~fontFamily: string=?,
    ~textAnchor: @string [#start | #middle | @as("end") #_end]=?,
    ~textDecoration: @string
    [
      | #none
      | #underline
      | #overline
      | @as("line-through") #lineThrough
      | #blink
    ]=?,
    ~letterSpacing: size=?,
    ~wordSpacing: size=?,
    ~kerning: size=?,
    ~fontFeatureSettings: string=?,
    ~fontVariantLigatures: fontVariantLigatures=?,
    ~fontVariationSettings: string=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "Text"
}

module TextPath = {
  @react.component @module("react-native-svg")
  external make: (
    ~xlinkHref: string=?,
    ~href: string=?,
    ~startOffset: size=?,
    ~method: method_=?,
    ~spacing: spacing=?,
    ~midLine: midLine=?,
    ~children: React.element=?,
    // Text props
    ~alignmentBaseline: @string
    [
      | #baseline
      | @as("text-bottom") #textBottom
      | #alphabetic
      | #ideographic
      | #middle
      | #central
      | #mathematical
      | @as("text-top") #textTop
      | #bottom
      | #center
      | #top
      | @as("text-before-edge") #textBeforeEdge
      | @as("text-after-edge") #textAfterEdge
      | @as("before-edge") #beforeEdge
      | @as("after-edge") #afterEdge
      | #hanging
    ]=?,
    ~baselineShift: baselineShift=?,
    ~verticalAlign: size=?,
    ~lengthAdjust: lengthAdjust=?,
    ~textLength: string=?,
    // ~fontData: todo=?,
    ~fontFeatureSettings: string=?,
    // Font Props
    ~fontStyle: fontStyle=?,
    ~fontVariant: fontVariant=?,
    ~fontWeight: @string
    [
      | #normal
      | #bold
      | #bolder
      | #lighter
      | @as("100") #_100
      | @as("200") #_200
      | @as("300") #_300
      | @as("400") #_400
      | @as("500") #_500
      | @as("600") #_600
      | @as("700") #_700
      | @as("800") #_800
      | @as("900") #_900
    ]=?,
    ~fontStretch: @string
    [
      | #normal
      | #wider
      | #narrower
      | @as("ultra-condensed") #ultraCondensed
      | @as("extra-condensed") #extraCondensed
      | #condensed
      | @as("semi-condensed") #semiCondensed
      | @as("semi-expanded") #semiExpanded
      | #expanded
      | @as("extra-expanded") #extraExpanded
      | @as("ultra-expanded") #ultraExpanded
    ]=?,
    ~fontSize: size=?,
    ~fontFamily: string=?,
    ~textAnchor: @string [#start | #middle | @as("end") #_end]=?,
    ~textDecoration: @string
    [
      | #none
      | #underline
      | #overline
      | @as("line-through") #lineThrough
      | #blink
    ]=?,
    ~letterSpacing: size=?,
    ~wordSpacing: size=?,
    ~kerning: size=?,
    ~fontFeatureSettings: string=?,
    ~fontVariantLigatures: fontVariantLigatures=?,
    ~fontVariationSettings: string=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "TextPath"
}

module Tspan = {
  @react.component @module("react-native-svg")
  external make: (
    ~dx: string=?,
    ~dy: string=?,
    ~rotate: string=?,
    ~inlineSize: size=?,
    ~children: React.element=?,
    // Font Props
    ~fontStyle: fontStyle=?,
    ~fontVariant: fontVariant=?,
    ~fontWeight: @string
    [
      | #normal
      | #bold
      | #bolder
      | #lighter
      | @as("100") #_100
      | @as("200") #_200
      | @as("300") #_300
      | @as("400") #_400
      | @as("500") #_500
      | @as("600") #_600
      | @as("700") #_700
      | @as("800") #_800
      | @as("900") #_900
    ]=?,
    ~fontStretch: @string
    [
      | #normal
      | #wider
      | #narrower
      | @as("ultra-condensed") #ultraCondensed
      | @as("extra-condensed") #extraCondensed
      | #condensed
      | @as("semi-condensed") #semiCondensed
      | @as("semi-expanded") #semiExpanded
      | #expanded
      | @as("extra-expanded") #extraExpanded
      | @as("ultra-expanded") #ultraExpanded
    ]=?,
    ~fontSize: size=?,
    ~fontFamily: string=?,
    ~textAnchor: @string [#start | #middle | @as("end") #_end]=?,
    ~textDecoration: @string
    [
      | #none
      | #underline
      | #overline
      | @as("line-through") #lineThrough
      | #blink
    ]=?,
    ~letterSpacing: size=?,
    ~wordSpacing: size=?,
    ~kerning: size=?,
    ~fontFeatureSettings: string=?,
    ~fontVariantLigatures: fontVariantLigatures=?,
    ~fontVariationSettings: string=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "TSpan"
}

module Use = {
  @react.component @module("react-native-svg")
  external make: (
    ~xlinkHref: string=?,
    ~href: string=?,
    ~width: size=?,
    ~height: size=?,
    ~opacity: opacity=?,
    ~children: React.element=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "Use"
}

module G = {
  @react.component @module("react-native-svg")
  external make: (
    ~opacity: opacity=?,
    ~children: React.element=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "G"
}

module Symbol = {
  @react.component @module("react-native-svg")
  external make: (
    ~id: string=?,
    ~viewBox: string=?,
    ~preserveAspectRatio: string=?,
    ~opacity: opacity=?,
  ) => React.element = "Symbol"
}

module Defs = {
  @react.component @module("react-native-svg")
  external make: (~children: React.element) => React.element = "Defs"
}

module Image = {
  @react.component @module("react-native-svg")
  external make: (
    ~xlinkHref: string=?,
    ~href: string=?,
    ~width: size=?,
    ~height: size=?,
    ~preserveAspectRatio: string=?,
    ~opacity: opacity=?,
    ~children: React.element=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "Image"
}

module ClipPath = {
  @react.component @module("react-native-svg")
  external make: (~children: React.element=?, ~id: string) => React.element = "ClipPath"
}

module LinearGradient = {
  @react.component @module("react-native-svg")
  external make: (
    ~id: string=?,
    ~x1: size,
    ~x2: size,
    ~y1: size,
    ~y2: size,
    // https://github.com/react-native-svg/react-native-svg/blob/b2e2c355204ff4b10973d3afce1495f7e4167ff7/src/index.d.ts#L163
    ~children: // transform?: number[] | string | TransformProps;
    // ~gradientUnits: gradientUnits=?,
    // ~gradientTransform: (float, float, float, float, float, float)=?,
    React.element,
  ) => React.element = "LinearGradient"
}

module Stop = {
  @react.component @module("react-native-svg")
  external make: (
    ~offset: size=?,
    ~stopColor: Color.t=?,
    ~stopOpacity: opacity=?,
  ) => React.element = "Stop"
}

module RadialGradient = {
  @react.component @module("react-native-svg")
  external make: (
    ~id: string=?,
    ~fx: size=?,
    ~fy: size=?,
    ~rx: size=?,
    ~ry: size=?,
    ~cx: size=?,
    ~cy: size=?,
    ~r: size=?,
    ~gradientUnits: gradientUnits=?,
    ~gradientTransform: (float, float, float, float, float, float)=?,
    ~children: React.element,
  ) => React.element = "RadialGradient"
}

module Mask = {
  @react.component @module("react-native-svg")
  external make: (
    ~width: size=?,
    ~height: size=?,
    ~maskTransform: (float, float, float, float, float, float)=?,
    ~maskUnits: maskUnits=?,
    ~maskContentUnits: maskContentUnits=?,
    // Commons Props
    ~id: string=?,
    ~fill: Color.t=?,
    ~fillOpacity: opacity=?,
    ~fillRule: fillRule=?,
    ~stroke: Color.t=?,
    ~strokeWidth: size=?,
    ~strokeOpacity: opacity=?,
    ~strokeDasharray: array<size>=?,
    ~strokeDashoffset: size=?,
    ~strokeLinecap: strokeLinecap=?,
    ~strokeLinejoin: strokeLinejoin=?,
    ~strokeMiterlimit: size=?,
    ~clipRule: clipRule=?,
    ~clipPath: string=?,
    ~transform: string=?,
    ~vectorEffect: @string
    [
      | #none
      | #nonScalingStroke
      | #default
      | @as("inherit") #_inherit
      | #uri
    ]=?,
    ~x: size=?,
    ~y: size=?,
    ~rotation: size=?,
    ~scale: size=?,
    ~origin: string=?,
    ~originX: size=?,
    ~originY: size=?,
    // Responder Props
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~disabled: bool=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~delayLongPress: int=?,
  ) => React.element = "Mask"
}

module Pattern = {
  @react.component @module("react-native-svg")
  external make: (
    ~id: string=?,
    ~x: size=?,
    ~y: size=?,
    ~width: size=?,
    ~height: size=?,
    ~patternTransform: (float, float, float, float, float, float)=?,
    ~patternUnits: patternUnits=?,
    ~patternContentUnits: patternContentUnits=?,
    ~viewBox: string=?,
    ~preserveAspectRatio: string=?,
    ~children: React.element,
  ) => React.element = "Pattern"
}

module Marker = {
  @react.component @module("react-native-svg")
  external make: (
    ~id: string=?,
    ~viewBox: string=?,
    ~preserveAspectRatio: string=?,
    ~refX: size=?,
    ~refY: size=?,
    ~markerWidth: size=?,
    ~markerHeight: size=?,
    ~markerUnits: markerUnits=?,
    ~orient: string=?,
  ) => React.element = "Marker"
}

module ForeignObject = {
  @react.component @module("react-native-svg")
  external make: (~x: size=?, ~y: size=?, ~width: size=?, ~height: size=?) => React.element =
    "ForeignObject"
}
