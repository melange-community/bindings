let knobSensitivityFactor = 4;
let sizeInPixels = (x: int) => string_of_int(x) ++ "px";

// Range of degrees displayed
let knobMin = 30.0;
let knobMax = 330.0;

type knobScale =
  | Linear
  | Logarithmic;

type knobConfig = {
  minValue: float,
  maxValue: float,
  scale: knobScale,
  size: int,
};

let clamp = (value: float, config: knobConfig) => {
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
let make =
    (
      ~name,
      ~config: knobConfig,
      ~initialParamValue: float,
      ~setParamValue: float => unit,
    ) => {
  let knobDomainInPixels =
    React.useMemo1(
      () => float_of_int(config.size * knobSensitivityFactor),
      [|config.size|],
    );
  let mapParam = mapValue(~from=(config.minValue, config.maxValue));
  let mapToParam = mapValue(~target=(config.minValue, config.maxValue));
  let mapToDegrees = mapValue(~target=(knobMin, knobMax));

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

  let mapValueToDegrees = (value: float): string => {
    let degrees =
      switch (config.scale) {
      | Linear => value |> mapParam(~target=(knobMin, knobMax))
      | Logarithmic =>
        /* log10(1)=0 */
        /* log10(10)=1 */
        value
        |> mapParam(~target=(1.0, 10.0))
        |> log10
        |> mapToDegrees(~from=(0.0, 1.0))
      };
    Js.Float.toString(degrees) ++ "deg";
  };

  let (value, setValue) = React.useState(() => initialParamValue);
  let lastY = React.useRef(0);

  let handleMouseMove = (event: Webapi.Dom.MouseEvent.t): unit => {
    let clientY = Webapi.Dom.MouseEvent.clientY(event);
    setValue(value => {
      let change =
        lastY.current
        |> (x => x - clientY)
        |> float_of_int
        |> mapValue(~from=(0.0, knobDomainInPixels), ~target=(0.0, 1.0));
      let newValue =
        switch (config.scale) {
        | Linear =>
          value
          |> mapParam(~target=(0.0, 1.0))
          |> (+.)(change)
          |> mapToParam(~from=(0.0, 1.0))
        | Logarithmic =>
          /* log10(1)=0  <--> 10**0=1  */
          /* log10(10)=1 <--> 10**1=10 */
          value
          |> mapParam(~target=(1.0, 10.0))
          |> log10
          |> (+.)(change)
          |> (x => 10.0 ** x)
          |> mapToParam(~from=(1.0, 10.0))
        };
      let clampedValue = clamp(newValue, config);
      setParamValue(clampedValue);
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

  <div
    style={ReactDOMRe.Style.make(
      ~width={
        sizeInPixels(config.size + 50);
      },
      (),
    )}
    className="control-container">
    <h4 className="control-label"> {React.string(name)} </h4>
    <div
      onMouseDown=handleMouseDown
      style={ReactDOMRe.Style.make(
        ~backgroundColor=ColorPalette.silver,
        ~width=sizeInPixels(config.size),
        ~height=sizeInPixels(config.size),
        ~margin="0 auto",
        ~borderRadius=sizeInPixels(config.size),
        ~border="1px solid " ++ ColorPalette.white,
        ~display="flex",
        ~justifyContent="center",
        ~transform="rotate(" ++ mapValueToDegrees(value) ++ ")",
        (),
      )}>
      <div
        style={ReactDOMRe.Style.make(
          ~width="0",
          ~height="0",
          ~borderLeft="5px solid transparent",
          ~borderRight="5px solid transparent",
          ~borderBottom="12px solid " ++ ColorPalette.black,
          (),
        )}
      />
    </div>
    <h4 className="control-label">
      {React.string(
         Js.Float.toFixedWithPrecision(value, ~digits=indicatorPrecission),
       )}
    </h4>
  </div>;
};
