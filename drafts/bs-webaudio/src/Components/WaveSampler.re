let range = Array.make(256, 0.0);
let sineWave =
  Array.mapi(
    (idx, _) => {float_of_int(idx) /. 256.0 *. 2.0 *. Js.Math._PI |> sin},
    range,
  );
let sawWave =
  Array.mapi((idx, _) => {float_of_int(idx) /. 256.0 *. 2.0 -. 1.0}, range);
let triangleWave =
  Array.mapi(
    (idx, _) => {
      let normalizedIndex = float_of_int(idx) /. 256.0;
      if (normalizedIndex < 0.5) {
        normalizedIndex *. 4.0 -. 1.0;
      } else {
        (1.0 -. normalizedIndex) *. 4.0 -. 1.0;
      };
    },
    range,
  );
let squareWave =
  Array.mapi(
    (idx, _) => {
      let normalizedIndex = float_of_int(idx) /. 256.0;
      if (normalizedIndex < 0.25 || normalizedIndex > 0.75) {
        (-1.0);
      } else {
        1.0;
      };
    },
    range,
  );

[@react.component]
let make = (~setWaveCallback: PeriodicWave.t => unit) => {
  let appContext = React.useContext(AppContextProvider.appContext);
  let (sineFactor, setSineFactor) = React.useState(_ => 1.0);
  let (sawFactor, setSawFactor) = React.useState(_ => 0.0);
  let (triangleFactor, setTriangleFactor) = React.useState(_ => 0.0);
  let (squareFactor, setSquareFactor) = React.useState(_ => 0.0);

  let sampleWave = () => {
    Array.mapi(
      (idx, _) => {
        let si = sineFactor *. sineWave[idx];
        let sa = sawFactor *. sawWave[idx];
        let tr = triangleFactor *. triangleWave[idx];
        let sq = squareFactor *. squareWave[idx];
        si +. sa +. tr +. sq;
      },
      range,
    );
  };

  React.useEffect4(
    () => {
      switch (appContext.audioContext) {
      | Some(audioCtx) =>
        let periodicWave =
          audioCtx |> AudioContext.makePeriodicWave(~samples=sampleWave());
        setWaveCallback(periodicWave);
      | None => Js.log("Audio Context missing")
      };
      None;
    },
    (sineFactor, sawFactor, triangleFactor, squareFactor),
  );

  <div className="unit-container">
    <div>
      <Knob
        name="SINE"
        initialParamValue=sineFactor
        setParamValue={value => setSineFactor(_ => value)}
        config={minValue: 0.0, maxValue: 1.0, scale: Linear, size: 50}
      />
      <Knob
        name="SAW"
        initialParamValue=sawFactor
        setParamValue={value => setSawFactor(_ => value)}
        config={minValue: 0.0, maxValue: 1.0, scale: Linear, size: 50}
      />
    </div>
    <div>
      <Knob
        name="TRIANGLE"
        initialParamValue=triangleFactor
        setParamValue={value => setTriangleFactor(_ => value)}
        config={minValue: 0.0, maxValue: 1.0, scale: Linear, size: 50}
      />
      <Knob
        name="SQUARE"
        initialParamValue=squareFactor
        setParamValue={value => setSquareFactor(_ => value)}
        config={minValue: 0.0, maxValue: 1.0, scale: Linear, size: 50}
      />
    </div>
  </div>;
};
