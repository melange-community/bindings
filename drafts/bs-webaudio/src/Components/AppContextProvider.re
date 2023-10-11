type appContext = {
  audioContext: option(AudioContext.t),
  triggerTargets: list(Envelope.t),
  addToTriggerTargets: Envelope.t => unit,
  removeFromTriggerTargets: Envelope.t => unit,
  setLfoOutputGain: (option(GainNode.t) => option(GainNode.t)) => unit,
  lfoOutputGain: option(GainNode.t),
};

let appContext =
  React.createContext({
    audioContext: None,
    triggerTargets: [],
    addToTriggerTargets: _ => (),
    removeFromTriggerTargets: _ => (),
    setLfoOutputGain: _ => (),
    lfoOutputGain: None,
  });

let makeProps = (~value, ~children, ()) => {
  "value": value,
  "children": children,
};

let make = React.Context.provider(appContext);
