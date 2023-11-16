// Vendored from rescript-react-native 0.70 because of compatibility issues.
type t
open ReactNative

external array: array<t> => t = "%identity"
external arrayOption: array<option<t>> => t = "%identity"

// Escape hatch, in case something is added into RN but unsupported,
// Useful if you play with fancy platforms
// Use with caution
@val
external unsafeAddStyle: (@as(json`{}`) _, t, Js.t<'a>) => t = "Object.assign"

external unsafeStyle: Js.t<'a> => t = "%identity"

type size = string

external dp: float => size = "%identity"

let pct = num => num->Js.Float.toString ++ "%"

type margin = size

@inline
let auto = "auto"

type offset
@obj external offset: (~height: float, ~width: float) => offset = ""

type angle
let deg: float => angle = num => (num->Js.Float.toString ++ "deg")->Obj.magic
let rad: float => angle = num => (num->Js.Float.toString ++ "rad")->Obj.magic

type transform
@obj external perspective: (~perspective: float) => transform = ""
@obj external rotate: (~rotate: angle) => transform = ""
@obj external rotateX: (~rotateX: angle) => transform = ""
@obj external rotateY: (~rotateY: angle) => transform = ""
@obj external rotateZ: (~rotateZ: angle) => transform = ""
@obj external scale: (~scale: float) => transform = ""
@obj external scaleX: (~scaleX: float) => transform = ""
@obj external scaleY: (~scaleY: float) => transform = ""
@obj external translateX: (~translateX: float) => transform = ""
@obj external translateY: (~translateY: float) => transform = ""
@obj external skewX: (~skewX: angle) => transform = ""
@obj external skewY: (~skewY: angle) => transform = ""
// @todo matrix

external unsafeTransform: Js.t<'a> => transform = "%identity"

type resizeMode = [#cover | #contain | #stretch | #repeat | #center]

type fontStyle = [#normal | #italic]

module FontWeight = {
  // Note: we cannot model this as a polymorphic variant
  // because #"100" = #100 = the number 100 in JS, but we need the string "100" here.
  type t = string

  @inline
  let normal = "normal"
  @inline
  let bold = "bold"
  @inline
  let _100 = "100"
  @inline
  let _200 = "200"
  @inline
  let _300 = "300"
  @inline
  let _400 = "400"
  @inline
  let _500 = "500"
  @inline
  let _600 = "600"
  @inline
  let _700 = "700"
  @inline
  let _800 = "800"
  @inline
  let _900 = "900"
}

type fontWeight = FontWeight.t

type fontVariant = [
  | #"small-caps"
  | #"oldstyle-nums"
  | #"lining-nums"
  | #"tabular-nums"
  | #"proportional-nums"
]

type textAlign = [#auto | #left | #right | #center | #justify]

type textAlignVertical = [#auto | #top | #bottom | #center]

type textDecorationLine = [
  | #none
  | #underline
  | #"line-through"
  | #"underline line-through"
]

type textDecorationStyle = [#solid | #double | #dotted | #dashed]

type textTransform = [#none | #uppercase | #lowercase | #capitalize]

type writingDirection = [#auto | #ltr | #rtl]

type backfaceVisibility = [#visible | #hidden]

type borderStyle = [#solid | #dotted | #dashed]

type display = [#none | #flex]

type overflow = [#visible | #hidden | #scroll]

type flexWrap = [#wrap | #nowrap]

type position = [#absolute | #relative]

type alignContent = [
  | #"flex-start"
  | #"flex-end"
  | #center
  | #stretch
  | #"space-around"
  | #"space-between"
]

type alignItems = [
  | #"flex-start"
  | #"flex-end"
  | #center
  | #stretch
  | #baseline
]

type alignSelf = [
  | #auto
  | #"flex-start"
  | #"flex-end"
  | #center
  | #stretch
  | #baseline
]

type direction = [#inherit | #ltr | #rtl]

type flexDirection = [
  | #row
  | #"row-reverse"
  | #column
  | #"column-reverse"
]

type justifyContent = [
  | #"flex-start"
  | #"flex-end"
  | #center
  | #"space-around"
  | #"space-between"
  | #"space-evenly"
]

// Styles are documented here
// https://github.com/facebook/react-native/blob/master/Libraries/StyleSheet/StyleSheetTypes.js

// Note that all border*Width are in layout styles & view styles too
// React Native JS codebase have those in View Styles Props again but with different types
// because layout styles props don't accept animated values.
// We don't do the distinction as ReScript is an HMTS that doesn't support implicit subtyping

// Dangerous Imprecise Style
// Contains all of
// - image style
// - text style
// - view style
// - transform style
// - shadow style
// - layout style

// ____DangerouslyImpreciseStyle_Internal
// Dangerous Imprecise Style
// Contains all of
// - image style
// - text style
// - view style
// - transform style
// - shadow style
// - layout style
@obj
external style: (
  // Image Style Props (https://reactnative.dev/docs/image-style-props)
  ~resizeMode: resizeMode=?,
  ~overlayColor: Color.t=?,
  ~tintColor: Color.t=?,
  // Text Style Props (https://reactnative.dev/docs/text-style-props)
  ~color: Color.t=?,
  ~fontFamily: string=?,
  ~fontSize: float=?,
  ~fontStyle: fontStyle=?,
  ~fontVariant: array<fontVariant>=?,
  ~fontWeight: fontWeight=?,
  ~includeFontPadding: bool=?,
  ~letterSpacing: float=?,
  ~lineHeight: float=?,
  ~textAlign: textAlign=?,
  ~textAlignVertical: textAlignVertical=?,
  ~textDecorationColor: Color.t=?,
  ~textDecorationLine: textDecorationLine=?,
  ~textDecorationStyle: textDecorationStyle=?,
  ~textShadowColor: Color.t=?,
  ~textShadowOffset: offset=?,
  ~textShadowRadius: float=?,
  ~textTransform: textTransform=?,
  ~writingDirection: writingDirection=?,
  // View styles https://reactnative.dev/docs/view-style-props
  ~backfaceVisibility: backfaceVisibility=?,
  ~backgroundColor: Color.t=?,
  ~borderBottomColor: Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: Color.t=?,
  ~borderEndColor: Color.t=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: Color.t=?,
  ~borderStartWidth: float=?,
  ~borderStyle: borderStyle=?,
  ~borderTopColor: Color.t=?,
  ~borderTopEndRadius: float=?,
  ~borderTopLeftRadius: float=?,
  ~borderTopRightRadius: float=?,
  ~borderTopStartRadius: float=?,
  ~borderTopWidth: float=?,
  ~borderWidth: float=?,
  ~elevation: float=?,
  ~opacity: float=?,
  // Transform Props (https://reactnative.dev/docs/transforms#props)
  ~transform: array<transform>=?, // all other transform props are deprecated
  // Shadow Props (https://reactnative.dev/docs/shadow-props)
  ~shadowColor: Color.t=?,
  ~shadowOffset: offset=?,
  ~shadowOpacity: float=?,
  ~shadowRadius: float=?,
  // Layout Style Props (https://reactnative.dev/docs/layout-props)
  ~alignContent: alignContent=?,
  ~alignItems: alignItems=?,
  ~alignSelf: alignSelf=?,
  ~aspectRatio: float=?,
  // border*Width are commented because already in view styles props (see explanation at the top)
  // ~borderBottomWidth: float=?,
  // ~borderEndWidth: float=?,
  // ~borderLeftWidth: float=?,
  // ~borderRightWidth: float=?,
  // ~borderStartWidth: float=?,
  // ~borderTopWidth: float=?,
  // ~borderWidth: float=?,
  ~bottom: size=?,
  ~direction: direction=?,
  ~display: display=?,
  ~end: size=?,
  ~flex: float=?,
  ~flexBasis: margin=?,
  ~flexDirection: flexDirection=?,
  ~flexGrow: float=?,
  ~flexShrink: float=?,
  ~flexWrap: flexWrap=?,
  ~height: size=?,
  ~justifyContent: justifyContent=?,
  ~left: size=?,
  ~margin: margin=?,
  ~marginBottom: margin=?,
  ~marginEnd: margin=?,
  ~marginHorizontal: margin=?,
  ~marginLeft: margin=?,
  ~marginRight: margin=?,
  ~marginStart: margin=?,
  ~marginTop: margin=?,
  ~marginVertical: margin=?,
  ~maxHeight: size=?,
  ~maxWidth: size=?,
  ~minHeight: size=?,
  ~minWidth: size=?,
  ~overflow: overflow=?,
  ~padding: size=?,
  ~paddingBottom: size=?,
  ~paddingEnd: size=?,
  ~paddingHorizontal: size=?,
  ~paddingLeft: size=?,
  ~paddingRight: size=?,
  ~paddingStart: size=?,
  ~paddingTop: size=?,
  ~paddingVertical: size=?,
  ~position: position=?,
  ~right: size=?,
  ~start: size=?,
  ~top: size=?,
  ~width: size=?,
  ~zIndex: int=?,
  unit,
) => t = ""

// ____ViewStyleProp_Internal
@obj
external viewStyle: (
  // View styles https://reactnative.dev/docs/view-style-props
  ~backfaceVisibility: backfaceVisibility=?,
  ~backgroundColor: Color.t=?,
  ~borderBottomColor: Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: Color.t=?,
  ~borderEndColor: Color.t=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: Color.t=?,
  ~borderStartWidth: float=?,
  ~borderStyle: borderStyle=?,
  ~borderTopColor: Color.t=?,
  ~borderTopEndRadius: float=?,
  ~borderTopLeftRadius: float=?,
  ~borderTopRightRadius: float=?,
  ~borderTopStartRadius: float=?,
  ~borderTopWidth: float=?,
  ~borderWidth: float=?,
  ~elevation: float=?,
  ~opacity: float=?,
  // Transform Props (https://reactnative.dev/docs/transforms#props)
  ~transform: array<transform>=?, // all other transform props are deprecated
  // Shadow Props (https://reactnative.dev/docs/shadow-props)
  ~shadowColor: Color.t=?,
  ~shadowOffset: offset=?,
  ~shadowOpacity: float=?,
  ~shadowRadius: float=?,
  // Layout Style Props (https://reactnative.dev/docs/layout-props)
  ~alignContent: alignContent=?,
  ~alignItems: alignItems=?,
  ~alignSelf: alignSelf=?,
  ~aspectRatio: float=?,
  // border*Width are commented because already in view styles props (see explanation at the top)
  // ~borderBottomWidth: float=?,
  // ~borderEndWidth: float=?,
  // ~borderLeftWidth: float=?,
  // ~borderRightWidth: float=?,
  // ~borderStartWidth: float=?,
  // ~borderTopWidth: float=?,
  // ~borderWidth: float=?,
  ~bottom: size=?,
  ~direction: direction=?,
  ~display: display=?,
  ~end: size=?,
  ~flex: float=?,
  ~flexBasis: margin=?,
  ~flexDirection: flexDirection=?,
  ~flexGrow: float=?,
  ~flexShrink: float=?,
  ~flexWrap: flexWrap=?,
  ~height: size=?,
  ~justifyContent: justifyContent=?,
  ~left: size=?,
  ~margin: margin=?,
  ~marginBottom: margin=?,
  ~marginEnd: margin=?,
  ~marginHorizontal: margin=?,
  ~marginLeft: margin=?,
  ~marginRight: margin=?,
  ~marginStart: margin=?,
  ~marginTop: margin=?,
  ~marginVertical: margin=?,
  ~maxHeight: size=?,
  ~maxWidth: size=?,
  ~minHeight: size=?,
  ~minWidth: size=?,
  ~overflow: overflow=?,
  ~padding: size=?,
  ~paddingBottom: size=?,
  ~paddingEnd: size=?,
  ~paddingHorizontal: size=?,
  ~paddingLeft: size=?,
  ~paddingRight: size=?,
  ~paddingStart: size=?,
  ~paddingTop: size=?,
  ~paddingVertical: size=?,
  ~position: position=?,
  ~right: size=?,
  ~start: size=?,
  ~top: size=?,
  ~width: size=?,
  ~zIndex: int=?,
  unit,
) => t = ""

// ____TextStyleProp_Internal
@obj
external textStyle: (
  // Text Style Props (https://reactnative.dev/docs/text-style-props)
  ~color: Color.t=?,
  ~fontFamily: string=?,
  ~fontSize: float=?,
  ~fontStyle: fontStyle=?,
  ~fontVariant: array<fontVariant>=?,
  ~fontWeight: fontWeight=?,
  ~includeFontPadding: bool=?,
  ~letterSpacing: float=?,
  ~lineHeight: float=?,
  ~textAlign: textAlign=?,
  ~textAlignVertical: textAlignVertical=?,
  ~textDecorationColor: Color.t=?,
  ~textDecorationLine: textDecorationLine=?,
  ~textDecorationStyle: textDecorationStyle=?,
  ~textShadowColor: Color.t=?,
  ~textShadowOffset: offset=?,
  ~textShadowRadius: float=?,
  ~textTransform: textTransform=?,
  ~writingDirection: writingDirection=?,
  // View styles https://reactnative.dev/docs/view-style-props
  ~backfaceVisibility: backfaceVisibility=?,
  ~backgroundColor: Color.t=?,
  ~borderBottomColor: Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: Color.t=?,
  ~borderEndColor: Color.t=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: Color.t=?,
  ~borderStartWidth: float=?,
  ~borderStyle: borderStyle=?,
  ~borderTopColor: Color.t=?,
  ~borderTopEndRadius: float=?,
  ~borderTopLeftRadius: float=?,
  ~borderTopRightRadius: float=?,
  ~borderTopStartRadius: float=?,
  ~borderTopWidth: float=?,
  ~borderWidth: float=?,
  ~elevation: float=?,
  ~opacity: float=?,
  // Transform Props (https://reactnative.dev/docs/transforms#props)
  ~transform: array<transform>=?, // all other transform props are deprecated
  // Shadow Props (https://reactnative.dev/docs/shadow-props)
  ~shadowColor: Color.t=?,
  ~shadowOffset: offset=?,
  ~shadowOpacity: float=?,
  ~shadowRadius: float=?,
  // Layout Style Props (https://reactnative.dev/docs/layout-props)
  ~alignContent: alignContent=?,
  ~alignItems: alignItems=?,
  ~alignSelf: alignSelf=?,
  ~aspectRatio: float=?,
  // border*Width are commented because already in view styles props (see explanation at the top)
  // ~borderBottomWidth: float=?,
  // ~borderEndWidth: float=?,
  // ~borderLeftWidth: float=?,
  // ~borderRightWidth: float=?,
  // ~borderStartWidth: float=?,
  // ~borderTopWidth: float=?,
  // ~borderWidth: float=?,
  ~bottom: size=?,
  ~direction: direction=?,
  ~display: display=?,
  ~end: size=?,
  ~flex: float=?,
  ~flexBasis: margin=?,
  ~flexDirection: flexDirection=?,
  ~flexGrow: float=?,
  ~flexShrink: float=?,
  ~flexWrap: flexWrap=?,
  ~height: size=?,
  ~justifyContent: justifyContent=?,
  ~left: size=?,
  ~margin: margin=?,
  ~marginBottom: margin=?,
  ~marginEnd: margin=?,
  ~marginHorizontal: margin=?,
  ~marginLeft: margin=?,
  ~marginRight: margin=?,
  ~marginStart: margin=?,
  ~marginTop: margin=?,
  ~marginVertical: margin=?,
  ~maxHeight: size=?,
  ~maxWidth: size=?,
  ~minHeight: size=?,
  ~minWidth: size=?,
  ~overflow: overflow=?,
  ~padding: size=?,
  ~paddingBottom: size=?,
  ~paddingEnd: size=?,
  ~paddingHorizontal: size=?,
  ~paddingLeft: size=?,
  ~paddingRight: size=?,
  ~paddingStart: size=?,
  ~paddingTop: size=?,
  ~paddingVertical: size=?,
  ~position: position=?,
  ~right: size=?,
  ~start: size=?,
  ~top: size=?,
  ~width: size=?,
  ~zIndex: int=?,
  unit,
) => t = ""

// ____ImageStyleProp_Internal
@obj
external imageStyle: (
  // Image Style Props (https://reactnative.dev/docs/image-style-props)
  ~resizeMode: resizeMode=?,
  ~overlayColor: Color.t=?,
  ~tintColor: Color.t=?,
  // View styles https://reactnative.dev/docs/view-style-props
  ~backfaceVisibility: backfaceVisibility=?,
  ~backgroundColor: Color.t=?,
  ~borderBottomColor: Color.t=?,
  ~borderBottomEndRadius: float=?,
  ~borderBottomLeftRadius: float=?,
  ~borderBottomRightRadius: float=?,
  ~borderBottomStartRadius: float=?,
  ~borderBottomWidth: float=?,
  ~borderColor: Color.t=?,
  ~borderEndColor: Color.t=?,
  ~borderEndWidth: float=?,
  ~borderLeftColor: Color.t=?,
  ~borderLeftWidth: float=?,
  ~borderRadius: float=?,
  ~borderRightColor: Color.t=?,
  ~borderRightWidth: float=?,
  ~borderStartColor: Color.t=?,
  ~borderStartWidth: float=?,
  ~borderStyle: borderStyle=?,
  ~borderTopColor: Color.t=?,
  ~borderTopEndRadius: float=?,
  ~borderTopLeftRadius: float=?,
  ~borderTopRightRadius: float=?,
  ~borderTopStartRadius: float=?,
  ~borderTopWidth: float=?,
  ~borderWidth: float=?,
  ~elevation: float=?,
  ~opacity: float=?,
  // Transform Props (https://reactnative.dev/docs/transforms#props)
  ~transform: array<transform>=?, // all other transform props are deprecated
  // Shadow Props (https://reactnative.dev/docs/shadow-props)
  ~shadowColor: Color.t=?,
  ~shadowOffset: offset=?,
  ~shadowOpacity: float=?,
  ~shadowRadius: float=?,
  // Layout Style Props (https://reactnative.dev/docs/layout-props)
  ~alignContent: alignContent=?,
  ~alignItems: alignItems=?,
  ~alignSelf: alignSelf=?,
  ~aspectRatio: float=?,
  // border*Width are commented because already in view styles props (see explanation at the top)
  // ~borderBottomWidth: float=?,
  // ~borderEndWidth: float=?,
  // ~borderLeftWidth: float=?,
  // ~borderRightWidth: float=?,
  // ~borderStartWidth: float=?,
  // ~borderTopWidth: float=?,
  // ~borderWidth: float=?,
  ~bottom: size=?,
  ~direction: direction=?,
  ~display: display=?,
  ~end: size=?,
  ~flex: float=?,
  ~flexBasis: margin=?,
  ~flexDirection: flexDirection=?,
  ~flexGrow: float=?,
  ~flexShrink: float=?,
  ~flexWrap: flexWrap=?,
  ~height: size=?,
  ~justifyContent: justifyContent=?,
  ~left: size=?,
  ~margin: margin=?,
  ~marginBottom: margin=?,
  ~marginEnd: margin=?,
  ~marginHorizontal: margin=?,
  ~marginLeft: margin=?,
  ~marginRight: margin=?,
  ~marginStart: margin=?,
  ~marginTop: margin=?,
  ~marginVertical: margin=?,
  ~maxHeight: size=?,
  ~maxWidth: size=?,
  ~minHeight: size=?,
  ~minWidth: size=?,
  ~overflow: overflow=?,
  ~padding: size=?,
  ~paddingBottom: size=?,
  ~paddingEnd: size=?,
  ~paddingHorizontal: size=?,
  ~paddingLeft: size=?,
  ~paddingRight: size=?,
  ~paddingStart: size=?,
  ~paddingTop: size=?,
  ~paddingVertical: size=?,
  ~position: position=?,
  ~right: size=?,
  ~start: size=?,
  ~top: size=?,
  ~width: size=?,
  ~zIndex: int=?,
  unit,
) => t = ""

let empty: t = style()
