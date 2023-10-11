open Rebolt;

type t = {
  func:
    (
      ~value: Animated.value(Animated.regular),
      ~toValue: [
                  | `animated(Animated.value(Animated.regular))
                  | `raw(float)
                ]
    ) =>
    Animated.Animation.t,
  forCard: 'a .Animated.value('a) => Style.t,
  forHeader: 'a .Animated.value('a) => Style.t,
};

let slideHorizontal = {
  func:
    Animated.spring(
      ~stiffness=1000.0,
      ~damping=500.0,
      ~mass=3.0,
      ~useNativeDriver=true,
      (),
    ),
  forCard: value => {
    let screenWidth = float(Dimensions.get(`window)##width);
    Style.(
      style([
        opacity(
          Interpolated(
            Animated.Value.interpolate(
              value,
              ~inputRange=[(-1.0), (-0.99), 0.0, 0.99, 1.0],
              ~outputRange=`float([0.0, 1.0, 1.0, 0.85, 0.0]),
              (),
            ),
          ),
        ),
        Transform.makeInterpolated(
          ~translateX=
            Animated.Value.interpolate(
              value,
              ~inputRange=[(-1), 0, 1] |> List.map(float),
              ~outputRange=`float([-. screenWidth *. 0.3, 0.0, screenWidth]),
              (),
            ),
          (),
        ),
      ])
    );
  },
  forHeader: _ => Style.style([]),
};

let fadeVertical = {
  func:
    Animated.timing(
      ~duration=350.0,
      ~easing=Easing.out(Easing.poly(5.0)),
      ~useNativeDriver=true,
      (),
    ),
  forCard: value =>
    Style.(
      style([
        opacity(
          Interpolated(
            Animated.Value.interpolate(
              value,
              ~inputRange=[(-1.0), (-0.99), 0.0, 1.0],
              ~outputRange=`float([0.0, 1.0, 1.0, 0.0]),
              (),
            ),
          ),
        ),
        Transform.makeInterpolated(
          ~translateY=
            Animated.Value.interpolate(
              value,
              ~inputRange=[(-1.0), (-0.99), 0.0, 1.0],
              ~outputRange=`float([0.0, 0.0, 0.0, 50.0]),
              (),
            ),
          (),
        ),
      ])
    ),
  forHeader: _ => Style.style([]),
};

let default =
  switch (Platform.os()) {
  | Platform.Android => fadeVertical
  | _ => slideHorizontal
  };

let none = {
  ...default,
  func: Animated.timing(~duration=0.0, ~useNativeDriver=true, ()),
};