/**
  Renders the child view with a mask specified in the [maskElement] prop

  {3 Example of use}
  The following example demonstrates rendering a View with red background behind a mask, defined as a [Basic mask] string.
  {[
    let component = ReasonReact.statelessComponent("MyComponent");

    let make = _children => {
      ...component,
      render: _self =>
        <MaskedViewIOS
          maskElement={
            <View
              style=Style.(
                      style([
                        flex(1.),
                        justifyContent(Center),
                        alignItems(Center),
                        backgroundColor(String("transparent")),
                      ])
                    )>
              <Text
                style=Style.(
                        style([
                          fontSize(Float(50.0)),
                          color(String("black")),
                          fontWeight(`_700),
                        ])
                      )>
                (ReasonReact.string("Basic mask"))
              </Text>
            </View>
          }>
            <View
              style=Style.(style([flex(1.), backgroundColor(String("red"))]))
            />
          </MaskedViewIOS>,
    };
  ]}

  You can read more on MaskedViewIOS component usage in official docs: {{:https://facebook.github.io/react-native/docs/maskedviewios}}

  {4 Props}

  All {{:\BsReactNative/View-BsReactNative} [View] props} are accepted.

  {4 maskElement}
  {[~maskElement: ReasonReact.reactElement]}

*/

let make:
  (
    ~maskElement: ReasonReact.reactElement,
    ~accessible: bool=?,
    ~accessibilityLabel: string=?,
    ~accessibilityComponentType: Types.accessibilityComponentType=?,
    ~accessibilityTraits: list(Types.accessibilityTrait)=?,
    ~accessibilityRole: Types.accessibilityRole=?,
    ~accessibilityStates: list(Types.accessibilityState)=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~onAccessibilityTap: unit => unit=?,
    ~hitSlop: Types.insets=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: Types.pointerEvents=?,
    ~removeClippedSubviews: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~accessibilityLiveRegion: Types.accessibilityLiveRegion=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: Types.importantForAccessibility=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );
