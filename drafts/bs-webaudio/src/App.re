[@react.component]
let make = () => {
  let (audioContextOn, setAudioContextOn) = React.useState(() => false);
  let (triggerTargets, setTriggerTargets) = React.useState(() => []);
  let (lfoOutputGain, setLfoOutputGain) = React.useState(() => None);
  let audioContext = React.useRef(None);

  let addToTriggerTargets = (envelope: Envelope.t): unit => {
    setTriggerTargets(targets => [envelope, ...targets]);
  };
  let removeFromTriggerTargets = (envelope: Envelope.t): unit => {
    setTriggerTargets(targets => targets |> List.filter(e => e != envelope));
  };

  let toggleAudioContextOn =
    React.useCallback1(
      _ =>
        if (audioContextOn == false) {
          switch (audioContext.current) {
          | Some(audioCtx) =>
            audioCtx
            |> AudioContext.resume
            |> Js.Promise.then_(_ =>
                 Js.Promise.resolve(setAudioContextOn(_ => true))
               )
            |> ignore
          | None =>
            audioContext.current = Some(AudioContext.createAudioContext());
            setAudioContextOn(_ => true);
          };
        } else {
          audioContext.current
          ->Belt.Option.map(AudioContext.suspend)
          ->Belt.Option.map(
              Js.Promise.then_(_ =>
                Js.Promise.resolve(setAudioContextOn(_ => false))
              ),
            )
          |> ignore;
        },
      [|audioContextOn|],
    );

  <AppContextProvider
    value=AppContextProvider.{
      audioContext: audioContext.current,
      triggerTargets,
      addToTriggerTargets,
      removeFromTriggerTargets,
      lfoOutputGain,
      setLfoOutputGain,
    }>
    <div
      style={ReactDOMRe.Style.make(
        ~position="absolute",
        ~top="0",
        ~right="0",
        (),
      )}>
      <div className="unit-container">
        <Switch isOn=audioContextOn toggle=toggleAudioContextOn>
          {React.string("POWER")}
        </Switch>
      </div>
    </div>
    {switch (audioContext.current) {
     | Some(_) => <> <OscillatorRack /> <LFOUnit /> </>
     | None => React.null
     }}
    <Sequencer />
    <Keyboard />
  </AppContextProvider>;
};
