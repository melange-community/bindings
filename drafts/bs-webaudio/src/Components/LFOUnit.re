[@react.component]
let make = () => {
  let appContext = React.useContext(AppContextProvider.appContext);
  let (lfoOn, setLfoOn) = React.useState(_ => false);
  let lfoRef = React.useRef(None);
  let envelopeRef = React.useRef(None);

  React.useEffect0(() => {
    switch (appContext.audioContext) {
    | Some(audioContext) =>
      let lfo =
        audioContext
        |> LFO.make
        |> LFO.connect(~target=AudioContext.getDestination(audioContext))
        |> LFO.start;
      lfoRef.current = Some(lfo);
      appContext.setLfoOutputGain(_ => Some(lfo.outputGain));
      let envelope =
        audioContext
        |> Envelope.make(
             ~targetValue=lfo |> LFO.getFrequency |> AudioParam.getValue,
             ~targetParam=lfo |> LFO.getFrequency,
           );
      envelope |> appContext.addToTriggerTargets;
      envelopeRef.current = Some(envelope);
      setLfoOn(_ => true);
    | None => Js.log("Missing Audio Context")
    };
    Some(() => Js.log("ToDo: Implement LFO cleanup"));
  });

  <div className="unit-group-container">
    <h2 className="unit-label"> {React.string("LFO")} </h2>
    {switch (lfoOn, envelopeRef.current) {
     | (true, Some(env)) =>
       <div className="row-group-container">
         <div className="unit-container">
           <Knob
             name="FREQUENCY"
             initialParamValue={env.envelopeParams.targetValue}
             setParamValue={value =>
               env |> Envelope.update(~param=TargetValue(value))
             }
             config={
               minValue: epsilon_float,
               maxValue: 30.0,
               scale: Linear,
               size: 80,
             }
           />
         </div>
         <EnvelopeUnit envelope=env />
       </div>
     | _ => ReasonReact.null
     }}
  </div>;
};
