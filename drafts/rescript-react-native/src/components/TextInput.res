include TextInputElement
module ChangeEvent = {
  type payload = {
    eventCount: int,
    target: int,
    text: string,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type changeEvent = ChangeEvent.t

module EditingEvent = {
  type payload = {
    text: string,
    eventCount: int,
    target: int,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type editingEvent = EditingEvent.t

module ContentSizeChangeEvent = {
  type contentSize = {
    width: float,
    height: float,
  }
  type payload = {
    target: int,
    contentSize: contentSize,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type contentSizeChangeEvent = ContentSizeChangeEvent.t

module ScrollEvent = {
  type contentOffset = {
    x: float,
    y: float,
  }

  type payload = {contentOffset: contentOffset}

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type scrollEvent = ScrollEvent.t

type selection = {
  start: int,
  end: int,
}

module SelectionChangeEvent = {
  type payload = {
    selection: selection,
    target: int,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type selectionChangeEvent = SelectionChangeEvent.t

module KeyPressEvent = {
  type payload = {
    key: string,
    target: Js.Nullable.t<int>,
    eventCount: Js.Nullable.t<int>,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type keyPressEvent = KeyPressEvent.t

type autoCapitalize = [#characters | #words | #sentences | #none]

type autoComplete = [
  | #"birthdate-day"
  | #"birthdate-full"
  | #"birthdate-month"
  | #"birthdate-year"
  | #"cc-csc"
  | #"cc-exp-day"
  | #"cc-exp-month"
  | #"cc-exp-year"
  | #"cc-exp"
  | #"cc-number"
  | #"name-family"
  | #"name-given"
  | #"name-middle-initial"
  | #"name-middle"
  | #"name-prefix"
  | #"name-suffix"
  | #"password-new"
  | #"postal-address-country"
  | #"postal-address-extended-postal-code"
  | #"postal-address-extended"
  | #"postal-address-locality"
  | #"postal-address-region"
  | #"postal-address"
  | #"postal-code"
  | #"sms-otp"
  | #"street-address"
  | #"tel-country-code"
  | #"tel-device"
  | #"tel-national"
  | #"username-new"
  | #email
  | #gender
  | #name
  | #off
  | #password
  | #tel
  | #username
  | #"one-time-code"
]

type t

type clearButtonMode = [
  | #never
  | #"while-editing"
  | #"unless-editing"
  | #always
]

type importantForAutofill = [
  | #auto
  | #no
  | #noExcludeDescendants
  | #yes
  | #yesExcludeDescendants
]

type keyboardAppearance = [#default | #light | #dark]

type keyboardType = [
  | #default
  | #"number-pad"
  | #"decimal-pad"
  | #numeric
  | #"email-address"
  | #"phone-pad"
  | #"ascii-capable"
  | #"numbers-and-punctuation"
  | #url
  | #"name-phone-pad"
  | #twitter
  | #"web-search"
  | #"visible-password"
]

type returnKeyType = [
  | #done
  | #go
  | #next
  | #search
  | #send
  | #none
  | #previous
  | #default
  | #"emergency-call"
  | #google
  | #join
  | #route
  | #yahoo
]

type textBreakStrategy = [#balanced | #highQuality | #simple]

type textContentType = [
  | #none
  | #URL
  | #addressCity
  | #addressCityAndState
  | #addressState
  | #countryName
  | #creditCardNumber
  | #emailAddress
  | #familyName
  | #fullStreetAddress
  | #givenName
  | #jobTitle
  | #location
  | #middleName
  | #name
  | #namePrefix
  | #nameSuffix
  | #nickname
  | #organizationName
  | #postalCode
  | #streetAddressLine1
  | #streetAddressLine2
  | #sublocality
  | #telephoneNumber
  | #username
  | #password
  | #newPassword
  | #oneTimeCode
]

type inputMode = [
  | #none
  | #text
  | #decimal
  | #numeric
  | #tel
  | #search
  | #email
  | #url
]

type enterKeyHint = [
  | #enter
  | #done
  | #next
  | #search
  | #send
  | #previous
]

type lineBreakStrategyIOS = [
  | #none
  | #standard
  | #"hangul-word"
  | #"push-out"
]

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  // TextInput props
  ~allowFontScaling: bool=?,
  ~autoCapitalize: autoCapitalize=?,
  ~autoComplete: autoComplete=?,
  ~autoCorrect: bool=?,
  ~autoFocus: bool=?,
  ~blurOnSubmit: bool=?,
  ~caretHidden: bool=?,
  ~clearButtonMode: clearButtonMode=?,
  ~clearTextOnFocus: bool=?,
  ~contextMenuHidden: bool=?,
  ~defaultValue: string=?,
  ~disableFullscreenUI: bool=?,
  ~dataDetectorTypes: array<Text.dataDetectorType>=?,
  ~editable: bool=?,
  ~enablesReturnKeyAutomatically: bool=?,
  // `enterKeyHint` has precedence over the `returnKeyType`
  ~enterKeyHint: enterKeyHint=?,
  ~importantForAutofill: importantForAutofill=?,
  ~inlineImageLeft: string=?,
  ~inlineImagePadding: float=?,
  ~inputAccessoryViewID: string=?,
  // `inputMode` has precedence over `keyboardType`
  ~inputMode: inputMode=?,
  ~keyboardAppearance: keyboardAppearance=?,
  ~keyboardType: keyboardType=?,
  ~lineBreakStrategyIOS: lineBreakStrategyIOS=?,
  ~maxFontSizeMultiplier: float=?,
  ~maxLength: int=?,
  ~multiline: bool=?,
  ~numberOfLines: int=?,
  // `rows` has precedence over `numberOfLines`
  ~rows: int=?,
  ~onBlur: Event.targetEvent => unit=?,
  ~onChange: changeEvent => unit=?,
  ~onChangeText: string => unit=?,
  ~onContentSizeChange: contentSizeChangeEvent => unit=?,
  ~onEndEditing: editingEvent => unit=?,
  ~onFocus: Event.targetEvent => unit=?,
  ~onKeyPress: keyPressEvent => unit=?,
  ~onPressIn: Event.pressEvent => bool=?,
  ~onPressOut: Event.pressEvent => bool=?,
  ~onScroll: scrollEvent => unit=?,
  ~onSelectionChange: selectionChangeEvent => unit=?,
  ~onSubmitEditing: editingEvent => unit=?,
  ~placeholder: string=?,
  ~placeholderTextColor: Color.t=?,
  // `readOnly` has precedence over `editable`
  ~readOnly: bool=?,
  ~returnKeyLabel: string=?,
  ~returnKeyType: returnKeyType=?,
  ~rejectResponderTermination: bool=?,
  ~scrollEnabled: bool=?,
  ~secureTextEntry: bool=?,
  ~selection: selection=?,
  ~selectionColor: Color.t=?,
  ~selectTextOnFocus: bool=?,
  ~showSoftInputOnFocus: bool=?,
  ~spellCheck: bool=?,
  ~textAlign: [#left | #center | #right]=?,
  ~textAlignVertical: Style.textAlignVertical=?,
  ~textBreakStrategy: textBreakStrategy=?,
  ~textContentType: textContentType=?,
  ~underlineColorAndroid: Color.t=?,
  ~value: string=?,
  // rescript-react-native 0.71.3 View props
  ~accessibilityActions: array<Accessibility.actionInfo>=?,
  ~accessibilityElementsHidden: bool=?,
  ~accessibilityHint: string=?,
  ~accessibilityIgnoresInvertColors: bool=?,
  ~accessibilityLabel: string=?,
  ~accessibilityLabelledBy: array<string>=?,
  ~accessibilityLanguage: string=?,
  ~accessibilityLiveRegion: Accessibility.liveRegion=?,
  ~accessibilityRole: Accessibility.role=?,
  // `role` has precedence over the accessibilityRole prop
  ~role: Role.t=?,
  ~accessibilityState: Accessibility.state=?,
  ~accessibilityValue: Accessibility.value=?,
  ~accessibilityViewIsModal: bool=?,
  ~accessible: bool=?,
  ~collapsable: bool=?,
  ~hitSlop: View.edgeInsets=?,
  ~importantForAccessibility: View.importantForAccessibility=?,
  ~nativeID: string=?,
  ~needsOffscreenAlphaCompositing: bool=?,
  ~onAccessibilityAction: Accessibility.actionEvent => unit=?,
  ~onAccessibilityEscape: unit => unit=?,
  ~onAccessibilityTap: unit => unit=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onMagicTap: unit => unit=?,
  // Gesture Responder props
  ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
  ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
  ~onResponderEnd: Event.pressEvent => unit=?,
  ~onResponderGrant: Event.pressEvent => unit=?,
  ~onResponderMove: Event.pressEvent => unit=?,
  ~onResponderReject: Event.pressEvent => unit=?,
  ~onResponderRelease: Event.pressEvent => unit=?,
  ~onResponderStart: Event.pressEvent => unit=?,
  ~onResponderTerminate: Event.pressEvent => unit=?,
  ~onResponderTerminationRequest: Event.pressEvent => bool=?,
  ~onStartShouldSetResponder: Event.pressEvent => bool=?,
  ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
  ~pointerEvents: View.pointerEvents=?,
  ~removeClippedSubviews: bool=?,
  ~renderToHardwareTextureAndroid: bool=?,
  ~shouldRasterizeIOS: bool=?,
  ~style: Style.t=?,
  ~testID: string=?,
  ~children: React.element=?,
  // react-native-web 0.17 View props
  ~href: string=?,
  ~hrefAttrs: Web.hrefAttrs=?,
  // react-native-web 0.17 View props, ClickProps
  ~onClick: option<ReactEvent.Mouse.t => unit>=?,
  ~onClickCapture: option<ReactEvent.Mouse.t => unit>=?,
  ~onContextMenu: option<ReactEvent.Mouse.t => unit>=?,
  // react-native-web 0.17 View props, FocusProps
  // ~onFocus: option<ReactEvent.Focus.t => unit>=?, // duplicate
  // ~onBlur: option<ReactEvent.Focus.t => unit>=?, // duplicate
  // react-native-web 0.17 View props, KeyboardProps
  ~onKeyDown: option<ReactEvent.Keyboard.t => unit>=?,
  ~onKeyDownCapture: option<ReactEvent.Keyboard.t => unit>=?,
  ~onKeyUp: option<ReactEvent.Keyboard.t => unit>=?,
  ~onKeyUpCapture: option<ReactEvent.Keyboard.t => unit>=?,
  // react-native-web 0.17 View props, Mouse forwarded props
  ~onMouseDown: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseEnter: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseLeave: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseMove: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseOut: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseOver: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseUp: option<ReactEvent.Mouse.t => unit>=?,
) => React.element = "TextInput"
