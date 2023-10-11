open Rebolt;

open Utils;

type config = {
  style: option(Rebolt.Style.t),
  title: option(string),
  center: option(returnsComponent),
  left: option(returnsComponent),
  right: option(returnsComponent),
}
and returnsComponent = props => ReasonReact.reactElement
and screen = {
  header: config,
  animation: Animation.t,
  key: string,
}
and props = {
  screens: array(screen),
  activeScreen: int,
  animatedValue: Animated.Interpolation.t,
  pop: string => unit,
};

let default = {
  title: None,
  style: None,
  center: None,
  left: None,
  right: None,
};

let scr = p => p.screens[p.activeScreen];

/**
 * Wrapper around `TouchableNativeFeedback` that makes sure Ripple effect
 * is used on Android devices that support this version.
 */
module TouchableItem = {
  let component = ReasonReact.statelessComponent("TouchableItem");
  let make =
      (
        ~pressColor="rgba(0, 0, 0, .32)",
        ~onPress=() => (),
        ~borderless=true,
        children,
      ) => {
    ...component,
    render: _self =>
      Platform.version() >= 21 && Platform.os() == Platform.Android ?
        <TouchableNativeFeedback
          onPress
          background=(TouchableNativeFeedback.ripple(pressColor, borderless))>
          ...children
        </TouchableNativeFeedback> :
        <TouchableOpacity onPress> ...children </TouchableOpacity>,
  };
};

module IOSImpl = {
  module Styles = {
    open Style;
    module Constants = {
      let titleOffset = 70.0;
      let appBarHeight = 44.0;
      let statusBarHeight = 20.0;
    };
    let container =
      style([
        backgroundColor(String("#fff")),
        borderBottomWidth(StyleSheet.hairlineWidth),
        borderBottomColor(String("#A7A7AA")),
      ]);
    let header =
      style([
        height(Pt(Constants.(appBarHeight))),
        position(Relative),
        /*
         * SafeAreaView doesn't work on iOS < 11 and so, we add the
         * statusBar padding manually
         */
        marginTop(
          Pt(Platform.version() < 11 ? Constants.statusBarHeight : 0.0),
        ),
      ]);
    let fill = StyleSheet.absoluteFill;
    let center =
      style([
        bottom(Pt(0.0)),
        top(Pt(0.0)),
        left(Pt(Constants.titleOffset)),
        right(Pt(Constants.titleOffset)),
        position(Absolute),
        flexDirection(Row),
        justifyContent(Center),
        alignItems(Center),
      ]);
    let headerTitle =
      style([
        fontSize(Float(17.0)),
        fontWeight(`_700),
        textAlign(Center),
        marginHorizontal(Pt(16.0)),
        color(String("rgba(0, 0, 0, .9)")),
      ]);
    let left =
      style([
        left(Pt(0.0)),
        top(Pt(0.0)),
        bottom(Pt(0.0)),
        position(Absolute),
        flexDirection(Row),
        alignItems(Center),
      ]);
    let leftTitle =
      style([fontSize(Float(17.0)), color(String("#037aff"))]);
    let leftContainer = style([flexDirection(Row), alignItems(Center)]);
    let leftIcon =
      style([
        height(Pt(21.0)),
        width(Pt(12.0)),
        marginLeft(Pt(9.0)),
        marginRight(Pt(3.0)),
        marginVertical(Pt(12.0)),
        resizeMode(Contain),
      ]);
    let iconMaskContainer =
      style([flex(1.0), flexDirection(Row), justifyContent(Center)]);
    let iconMask =
      style([
        height(Pt(21.0)),
        width(Pt(12.0)),
        marginLeft(Pt(9.0)),
        marginTop(Pt(-0.5)),
        alignSelf(Center),
        resizeMode(Contain),
      ]);
    let iconMaskFillerRect =
      style([
        flex(1.0),
        backgroundColor(String("#d8d8d8")),
        marginLeft(Pt(-1.0)),
      ]);
    let right =
      style([
        right(Pt(0.0)),
        top(Pt(0.0)),
        bottom(Pt(0.0)),
        position(Absolute),
        flexDirection(Row),
        alignItems(Center),
      ]);
  };
  /**
   * In order to be able to render `BackButton` correctly, we measure the
   * title and left container areas on each render and store the widths
   * in state.
   *
   * We use it to decide whether back button should be rendered at its full width
   * vs `Back`.
   */
  type state = {
    titleWidths: StringMap.t(float),
    leftWidths: StringMap.t(float),
  };
  type action =
    | SetTitleWidth(string, float)
    | SetLeftWidth(string, float);
  let component = ReasonReact.reducerComponent("FloatingHeader");
  let make = (~headerProps as props: props, _children) => {
    ...component,
    initialState: () => {
      titleWidths: StringMap.empty,
      leftWidths: StringMap.empty,
    },
    reducer: (action, state) =>
      switch (action) {
      | SetTitleWidth(key, width) =>
        ReasonReact.Update({
          ...state,
          titleWidths: state.titleWidths |> StringMap.add(key, width),
        })
      | SetLeftWidth(key, width) =>
        ReasonReact.Update({
          ...state,
          leftWidths: state.leftWidths |> StringMap.add(key, width),
        })
      },
    render: self => {
      let {screens, activeScreen, animatedValue} = props;
      /**
       * The animated value passed to Header is screen index -
       * gesture progress. When user starts moving its finger
       * on initial screen, this value can get negative. We do the
       * following interpolation to guard against such invalid state.
       *
       * Note: Animated seems to be not working properly when inputRange
       * starts and ends with the same number (0, 0). This can happen
       * when there's only a single route on the stack. To prevent that,
       * we make it lastIndex + 1.
       */
      let upperBound = float_of_int(Array.length(screens));
      let anim =
        Animated.Value.interpolate(
          animatedValue,
          ~inputRange=[0.0, upperBound],
          ~outputRange=`float([0.0, upperBound]),
          ~extrapolate=Animated.Interpolation.Clamp,
          (),
        );
      let mask =
        <View style=Styles.iconMaskContainer>
          <Image
            source=(
              Required(Packager.require("./assets/back-icon-mask.png"))
            )
            style=Styles.iconMask
          />
          <View style=Styles.iconMaskFillerRect />
        </View>;
      let renderLeft = p => {
        let {header, key} = scr(p);
        <Animated.View
          onLayout=(
            /**
             * We are interested in measuring the left container
             * only once to prevent infinite loops.
             */
            self.state.leftWidths
            |> StringMap.hasKey(key) ?
              _e => () :
              (
                e =>
                  self.send(
                    SetLeftWidth(
                      key,
                      RNEvent.NativeLayoutEvent.layout(e).width,
                    ),
                  )
              )
          )
          style=Style.(
                  concat([
                    Styles.left,
                    p.animatedValue
                    |> HeaderInterpolator.floating.forHeaderLeft,
                  ])
                )>
          (
            switch (header.left) {
            | Some(func) => func(p)
            | None =>
              p.activeScreen === 0 ?
                <View /> :
                <TouchableOpacity onPress=(_e => p.pop(key))>
                  <View style=Styles.leftContainer>
                    <Animated.View
                      style=(
                        p.animatedValue
                        |> HeaderInterpolator.floating.forHeaderLeftButton
                      )>
                      <Image
                        style=Styles.leftIcon
                        source=(
                          Required(
                            Packager.require("./assets/back-icon.png"),
                          )
                        )
                      />
                    </Animated.View>
                    (
                      switch (p.screens[p.activeScreen - 1].header.title) {
                      | Some(backTitle) =>
                        <Animated.View
                          style=(
                            p.animatedValue
                            |> HeaderInterpolator.floating.forHeaderLeftLabel
                          )>
                          <Text style=Styles.leftTitle numberOfLines=1>
                            (
                              ReasonReact.string(
                                /***
                                 * Measure the space left for the back button and decide
                                 * whether to print "Back" or the original back button,
                                 * which is title of the previous scene.
                                 */
                                try (
                                  {
                                    let lw =
                                      self.state.leftWidths
                                      |> StringMap.find(key);
                                    let tw =
                                      self.state.titleWidths
                                      |> StringMap.find(key);
                                    let ww =
                                      Dimensions.get(`window)##width
                                      |> float_of_int;
                                    lw +. 20.0 >= (ww -. tw) /. 2.0 ?
                                      "Back" : backTitle;
                                  }
                                ) {
                                | Not_found => backTitle
                                },
                              )
                            )
                          </Text>
                        </Animated.View>
                      | None => ReasonReact.null
                      }
                    )
                  </View>
                </TouchableOpacity>
            }
          )
        </Animated.View>;
      };
      let renderCenter = p => {
        let {key, header} = scr(p);
        let containerStyle =
          Style.(
            concat([
              Styles.center,
              p.animatedValue |> HeaderInterpolator.floating.forHeaderCenter,
            ])
          );
        <Animated.View
          style=containerStyle
          onLayout=(
            e =>
              self.send(
                SetTitleWidth(
                  key,
                  RNEvent.NativeLayoutEvent.layout(e).width,
                ),
              )
          )>
          (
            switch (header.center) {
            | Some(func) => func(p)
            | None =>
              <Text style=Styles.headerTitle numberOfLines=1>
                (
                  ReasonReact.string(
                    header.title |> Js.Option.getWithDefault(""),
                  )
                )
              </Text>
            }
          )
        </Animated.View>;
      };
      let renderRight = p =>
        <Animated.View
          style=(
            Style.concat([
              Styles.right,
              p.animatedValue |> HeaderInterpolator.floating.forHeaderRight,
            ])
          )>
          (
            switch (scr(p).header.right) {
            | Some(func) => func(p)
            | None => ReasonReact.null
            }
          )
        </Animated.View>;
      let lastIdx = Array.length(screens) - 1;
      <SafeAreaView
        style=Style.(
                concat([
                  Styles.container,
                  scr(props).header.style
                  |> Js.Option.getWithDefault(style([])),
                ])
              )>
        <View style=Styles.header>
          (
            screens
            |> Array.mapi((idx: int, screen) => {
                 /**
                  * Animated value in the header is screen index - since `interpolators`
                  * are generic, we subtract the index of the screen to make the animation
                  * a relation between -1, 0, 1 - just like in StackNavigator
                  */
                 let animatedValue =
                   Animated.Value.add(
                     anim,
                     Animated.Value.create(-. float_of_int(idx)),
                   );
                 let screenProps = {
                   ...props,
                   animatedValue,
                   activeScreen: idx,
                 };
                 /**
                  * Animated has this bug with `nativeDriver` that when you setState
                  * from onLayout, it doesn't apply interpolated styles which results
                  * in an awkward glitch as all layers appear on top of each other.
                  *
                  * We hide the opacity of the entire "middle" section until its
                  * dimensions have been resolved.
                  */
                 let initialOpacity =
                   Style.(
                     style(
                       self.state.leftWidths
                       |> StringMap.hasKey(screen.key)
                       && self.state.titleWidths
                       |> StringMap.hasKey(screen.key) ?
                         [] : [opacity(Float(0.0))],
                     )
                   );
                 /* Render a header for two last routes to improve performance */
                 if (lastIdx - idx > 2) {
                   ReasonReact.null;
                 } else {
                   <MaskedViewIOS
                     key=screen.key
                     maskElement=mask
                     style=(Style.concat([Styles.fill, initialOpacity]))
                     pointerEvents=(activeScreen == idx ? `boxNone : `none)>
                     (renderCenter(screenProps))
                     (renderLeft(screenProps))
                     (renderRight(screenProps))
                   </MaskedViewIOS>;
                 };
               })
            |> ReasonReact.array
          )
        </View>
      </SafeAreaView>;
    },
  };
};

module IOS = {
  let component = ReasonReact.statelessComponent("IOSHeader");
  let make = (~headerProps as p: props, _children) => {
    ...component,
    render: _self => <IOSImpl headerProps=p />,
  };
};

module Android = {
  module Styles = {
    open Style;
    let header =
      style([
        backgroundColor(String("#FFF")),
        shadowColor(String("black")),
        shadowOpacity(0.1),
        shadowRadius(StyleSheet.hairlineWidth),
        shadowOffset(~width=0.0, ~height=StyleSheet.hairlineWidth),
        elevation(4.0),
        height(Pt(56.0)),
        alignItems(Center),
        flexDirection(Row),
      ]);
    let title =
      style([
        justifyContent(FlexStart),
        fontSize(Float(20.0)),
        fontWeight(`_500),
        color(String("rgba(0, 0, 0, 0.9)")),
        marginHorizontal(Pt(16.0)),
      ]);
    let icon =
      style([
        height(Pt(24.0)),
        width(Pt(24.0)),
        margin(Pt(16.0)),
        marginRight(Pt(0.0)),
        resizeMode(Contain),
      ]);
  };
  let component = ReasonReact.statelessComponent("AndroidHeader");
  let renderTitle = p =>
    switch (scr(p).header.center) {
    | Some(func) => func(p)
    | None =>
      <Text style=Styles.title>
        (
          ReasonReact.string(
            scr(p).header.title |> Js.Option.getWithDefault(""),
          )
        )
      </Text>
    };
  let renderLeft = p =>
    switch (scr(p).header.left) {
    | Some(func) => func(p)
    | None =>
      p.activeScreen > 0 ?
        <TouchableItem onPress=(_e => p.pop(scr(p).key))>
          <Image
            style=Styles.icon
            source=(Required(Packager.require("./assets/back-icon.png")))
          />
        </TouchableItem> :
        <View />
    };
  let renderRight = p =>
    switch (scr(p).header.right) {
    | Some(func) => func(p)
    | None => ReasonReact.null
    };
  let make = (~headerProps as p: props, _children) => {
    ...component,
    render: _self =>
      <View
        style=Style.(
                concat([
                  Styles.header,
                  scr(p).header.style |> Js.Option.getWithDefault(style([])),
                ])
              )>
        (renderLeft(p))
        (renderTitle(p))
        (renderRight(p))
      </View>,
  };
};