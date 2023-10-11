let height = 120;
let width = 30; // Should be power of 5
let buttonHeight = 10;
let sizeInPixels = (x: int) => string_of_int(x) ++ "px";

type sliderConfig = {
  minValue: float,
  maxValue: float,
};

let clamp = (value: float, config: sliderConfig) => {
  let value = value < config.minValue ? config.minValue : value;
  let value = value > config.maxValue ? config.maxValue : value;
  value;
};

let mapValue = (~from: (float, float), ~target: (float, float), value) => {
  let (xmin, xmax) = from;
  let (ymin, ymax) = target;
  (value -. xmin) /. (xmax -. xmin) *. (ymax -. ymin) +. ymin;
};

[@react.component]
let make = (~name, ~param: AudioParam.t, ~config: sliderConfig) => {
  let mapParam = mapValue(~from=(config.minValue, config.maxValue));
  let mapToParam = mapValue(~target=(config.minValue, config.maxValue));

  let indicatorPrecission =
    React.useMemo2(
      (): int => {
        let logRange = log10(config.maxValue -. config.minValue);
        if (logRange > 3.0) {
          0;
        } else if (logRange > 0.8) {
          1;
        } else {
          2;
        };
      },
      (config.minValue, config.maxValue),
    );

  let mapValueToHeight = (value: float): string => {
    let height =
      value |> mapParam(~target=(float_of_int(height - buttonHeight), 0.0));
    Js.Float.toString(height) ++ "px";
  };

  let (value, setValue) = React.useState(() => param->AudioParam.getValue);
  let lastY = React.useRef(0);

  let handleMouseMove = (event: Webapi.Dom.MouseEvent.t): unit => {
    let clientY = Webapi.Dom.MouseEvent.clientY(event);
    setValue(value => {
      let change =
        lastY.current
        |> (x => x - clientY)
        |> float_of_int
        |> mapValue(~from=(0.0, float_of_int(height)), ~target=(0.0, 1.0));
      let newValue =
        value
        |> mapParam(~target=(0.0, 1.0))
        |> (+.)(change)
        |> mapToParam(~from=(0.0, 1.0));
      let clampedValue = clamp(newValue, config);
      param->AudioParam.setValue(clampedValue);
      lastY.current = clientY;
      clampedValue;
    });
    ();
  };

  let handleMouseUp = _: unit => {
    Webapi.Dom.EventTarget.removeMouseMoveEventListener(
      handleMouseMove,
      Webapi.Dom.Document.asEventTarget(Webapi.Dom.document),
    );
    ();
  };

  let handleMouseDown = (event: ReactEvent.Mouse.t): unit => {
    let clientY = ReactEvent.Mouse.clientY(event);
    lastY.current = clientY;
    Webapi.Dom.EventTarget.addMouseMoveEventListener(
      handleMouseMove,
      Webapi.Dom.Document.asEventTarget(Webapi.Dom.document),
    );
    Webapi.Dom.EventTarget.addMouseUpEventListenerWithOptions(
      handleMouseUp,
      {"capture": false, "once": true, "passive": true},
      Webapi.Dom.Document.asEventTarget(Webapi.Dom.document),
    );
    ();
  };

  <div className="control-container">
    <h4 className="control-label"> {React.string(name)} </h4>
    <div
      onMouseDown=handleMouseDown
      style={ReactDOMRe.Style.make(
        ~backgroundColor=ColorPalette.black,
        ~width=sizeInPixels(width / 5),
        ~height=sizeInPixels(height),
        ~margin="0 auto",
        (),
      )}>
      <div
        style={ReactDOMRe.Style.make(
          ~width=sizeInPixels(width),
          ~height=sizeInPixels(buttonHeight),
          ~backgroundColor=ColorPalette.silver,
          ~border="1px solid " ++ ColorPalette.white,
          ~transform=
            "translate("
            ++ sizeInPixels(int_of_float(float_of_int(width) *. (-0.4)))
            ++ ", "
            ++ mapValueToHeight(value)
            ++ ")",
          (),
        )}
      />
    </div>
    <h4 className="control-label">
      {React.string(
         Js.Float.toFixedWithPrecision(~digits=indicatorPrecission, value),
       )}
    </h4>
  </div>;
};
