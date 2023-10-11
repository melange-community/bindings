[@react.component]
let make =
    (
      ~name: string,
      ~targetOutput: option(AudioNode.audioNode_like('a)),
      ~alone: bool=false,
      ~remove: unit => unit,
    ) => {
  let appContext = React.useContext(AppContextProvider.appContext);
  let (oscillatorOn, setOscillatorOn) = React.useState(() => false);
  let oscillator = React.useRef(None);
  let envelope = React.useRef(None);

  let cleanUp = (): unit => {
    oscillator.current->Belt.Option.map(Oscillator.cleanUp)->ignore;
    envelope.current
    ->Belt.Option.map(appContext.removeFromTriggerTargets)
    ->ignore;
  };

  let toggleOscillator =
    React.useCallback3(
      _: unit =>
        if (oscillatorOn == false) {
          switch (appContext.audioContext) {
          | Some(audioContext) =>
            let target =
              switch (targetOutput) {
              | Some(target) => target
              | None =>
                audioContext
                ->AudioContext.getDestination
                ->AudioDestinationNode.asAudioNodeLike
              };
            let osc =
              audioContext
              |> Oscillator.make
              |> Oscillator.connect(~target)
              |> Oscillator.start;
            oscillator.current = Some(osc);
            let env =
              audioContext
              |> Envelope.make(~targetParam=Oscillator.getEnvelopeGain(osc));
            env |> appContext.addToTriggerTargets;
            envelope.current = Some(env);
            setOscillatorOn(_ => true);
            ();
          | None => Js.log("Missing Audio Context")
          };
        } else {
          cleanUp();
          setOscillatorOn(_ => false);
        },
      (oscillatorOn, appContext.audioContext, targetOutput),
    );

  React.useEffect0(() => {
    if (alone) {
      toggleOscillator();
    };
    Some(() => cleanUp());
  });

  <div className="unit-group-container">
    <div className="row-group-container">
      <h2 className="unit-label"> {React.string(name)} </h2>
      <div
        style={ReactDOMRe.Style.make(
          ~position="absolute",
          ~left="0",
          ~top="0",
          (),
        )}>
        <button className="unit-container" onClick={_ => remove()}>
          {React.string("X")}
        </button>
      </div>
    </div>
    <div className="row-group-container">
      <div className="unit-container">
        <Switch isOn=oscillatorOn toggle=toggleOscillator>
          {React.string("START")}
        </Switch>
      </div>
      {switch (oscillator.current, envelope.current) {
       | (Some(osc), Some(env)) =>
         <>
           <WaveSampler
             setWaveCallback={wave =>
               Oscillator.setOscillatorType(
                 ~oscillatorType=Custom(wave),
                 osc,
               )
             }
           />
           <div className="unit-container">
             <Knob
               name="FREQUENCY"
               initialParamValue={
                 osc |> Oscillator.getFrequency |> AudioParam.getValue
               }
               setParamValue={frequency =>
                 osc |> Oscillator.setFrequency(~frequency)
               }
               config={
                 minValue: 1.0,
                 maxValue: 18000.0,
                 scale: Logarithmic,
                 size: 120,
               }
             />
             <Slider
               name="GAIN"
               param={osc |> Oscillator.getOscillatorGain}
               config={minValue: epsilon_float, maxValue: 1.0}
             />
           </div>
           <EnvelopeUnit envelope=env />
         </>
       | _ => ReasonReact.null
       }}
    </div>
  </div>;
};
