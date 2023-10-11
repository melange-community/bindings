[@react.component]
let make = () => {
  let appContext = React.useContext(AppContextProvider.appContext);
  let (sequencer, setSequencer) = React.useState(_ => Array.make(8, false));
  let (sequencerOn, setSequencerOn) = React.useState(_ => false);
  let (activeStep, setActiveStep) = React.useState(_ => (-1));
  let lastTrigger = React.useRef(None);
  let (bpm, setBpm) = React.useState(_ => 120.0);

  let toggleSequencer = index => {
    setSequencer(s => {
      s->Array.set(index, !s[index]);
      s->Array.copy;
    });
  };

  let toggleSequencerOn = _ => {
    setSequencerOn(isOn =>
      if (isOn == true) {
        setActiveStep(_ => (-1));
        lastTrigger.current = None;
        false;
      } else {
        true;
      }
    );
  };

  let triggerTargets = targets => {
    targets |> List.iter(env => env |> Envelope.trigger);
    Js_global.setTimeout(
      _ =>
        appContext.triggerTargets
        |> List.iter(env => env |> Envelope.endTrigger),
      120,
    )
    |> ignore;
  };

  React.useEffect4(
    () =>
      switch (appContext.audioContext, sequencerOn) {
      | (Some(audioContext), true) =>
        let duration = 60.0 /. bpm *. 250.0;
        let interval =
          Js_global.setInterval(
            _ => {
              let timeStamp =
                audioContext |> AudioContext.getOutputTimestamp();
              lastTrigger.current = Some(timeStamp.performanceTime);
              let sequencerLength = Array.length(sequencer);
              setActiveStep(step => {
                let newStep = step >= sequencerLength - 1 ? 0 : step + 1;
                if (sequencer[newStep] == true) {
                  appContext.triggerTargets |> triggerTargets;
                };
                newStep;
              });
            },
            int_of_float(duration),
          );
        Some(_ => Js_global.clearInterval(interval));
      | _ => None
      },
    (appContext.triggerTargets, sequencerOn, sequencer, bpm),
  );

  let expandSequencer = _ => {
    let currentLength = Array.length(sequencer);
    let newSequence = Array.make(currentLength * 2, false);
    sequencer |> Array.iteri((ind, value) => newSequence[ind] = value);
    setSequencer(_ => newSequence);
    ();
  };

  let shrinkSequencer = _ => {
    let currentLength = Array.length(sequencer);
    if (currentLength === 4) {
      ();
    } else {
      let newSequence = Array.make(currentLength / 2, false);
      newSequence
      |> Array.iteri((ind, _) => newSequence[ind] = sequencer[ind]);
      setSequencer(_ => newSequence);
      ();
    };
  };

  <div className="unit-group-container">
    <h2 className="unit-label"> {React.string("SEQUENCER")} </h2>
    <div className="row-group-container">
      <div>
        <div className="row-group-container">
          <div className="unit-container">
            <Switch isOn=sequencerOn toggle=toggleSequencerOn>
              {React.string("START")}
            </Switch>
          </div>
        </div>
        <div className="row-group-container">
          <div className="unit-container">
            <Knob
              name="BPM"
              initialParamValue=bpm
              setParamValue={value => setBpm(_ => value)}
              config={
                minValue: 10.0,
                maxValue: 400.0,
                scale: Linear,
                size: 30,
              }
            />
          </div>
        </div>
        <div className="row-group-container">
          <div className="unit-container" onClick=expandSequencer>
            <div style={ReactDOMRe.Style.make(~fontWeight="bold", ())}>
              {React.string("x2")}
            </div>
          </div>
          <div className="unit-container" onClick=shrinkSequencer>
            <div style={ReactDOMRe.Style.make(~fontWeight="bold", ())}>
              {React.string("/2")}
            </div>
          </div>
        </div>
      </div>
      <div
        className="unit-container"
        style={ReactDOMRe.Style.make(
          ~display="grid",
          ~gridTemplateColumns="repeat(8, auto)",
          (),
        )}>
        {sequencer
         |> Array.mapi((ind, value) =>
              <div
                key={string_of_int(ind)}
                onClick={_ => toggleSequencer(ind)}
                style={ReactDOMRe.Style.make(
                  ~margin="5px",
                  ~backgroundColor=
                    value ? ColorPalette.black : ColorPalette.white,
                  ~width="40px",
                  ~height="50px",
                  ~display="flex",
                  ~justifyContent="center",
                  ~alignItems="center",
                  (),
                )}>
                {activeStep == ind
                   ? <div
                       style={ReactDOMRe.Style.make(
                         ~backgroundColor=ColorPalette.green,
                         ~width="20px",
                         ~height="20px",
                         ~borderRadius="20px",
                         (),
                       )}
                     />
                   : ReasonReact.null}
              </div>
            )
         |> ReasonReact.array}
      </div>
    </div>
  </div>;
};
