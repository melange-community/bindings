/********************************************************************************
 *                                                                              *
 *  +--------------------+    +---------------------+    +-------------------+  *
 *  |                    |    |                     |    |                   |  *
 *  |   oscillatorNode   |--->|    envelopeGain     |--->|    outputGain     |  *
 *  |                    |    |                     |    |                   |  *
 *  +--------------------+    +---------------------+    +-------------------+  *
 *                                                                              *
 ********************************************************************************/
type oscillator = {
  audioContext: AudioContext.t,
  oscillatorNode: OscillatorNode.t,
  oscillatorType: OscillatorNode.oscillatorNodeType,
  envelopeGain: GainNode.t,
  outputGain: GainNode.t,
};

type t = oscillator;

let sampleRandomWave = (): array(float) => {
  let samples = Array.make(256, 0.0);
  let previousValue = ref(0.0);
  samples[0] = previousValue^;
  for (x in 1 to 255) {
    let newValue = previousValue^ +. Random.float(0.2) -. 0.1;
    samples[x] = newValue;
    previousValue := newValue;
  };
  samples;
};

let setFrequency = (~frequency: float, oscillator: oscillator): unit => {
  oscillator.oscillatorNode
  ->OscillatorNode.frequency
  ->AudioParam.setValue(frequency);
};

let getFrequency = (oscillator: oscillator): AudioParam.t => {
  oscillator.oscillatorNode->OscillatorNode.frequency;
};

let getOscillatorGain = (oscillator: oscillator): AudioParam.t => {
  oscillator.outputGain |> GainNode.gain;
};

let getEnvelopeGain = (oscillator: oscillator): AudioParam.t => {
  oscillator.envelopeGain |> GainNode.gain;
};

let start = (oscillator: t): oscillator => {
  oscillator.oscillatorNode |> OscillatorNode.start();
  oscillator;
};

let stop = (oscillator: t): oscillator => {
  oscillator.oscillatorNode |> OscillatorNode.stop();
  oscillator;
};

let connect =
    (~target: AudioNode.audioNode_like('a), oscillator: t): oscillator => {
  oscillator.outputGain |> GainNode.connect(target);
  oscillator;
};

let disconnect = (oscillator: t): unit => {
  oscillator.outputGain |> GainNode.disconnect();
};

let cleanUp = (oscillator: t): unit => {
  oscillator.outputGain |> GainNode.disconnect();
  oscillator.envelopeGain |> GainNode.disconnect();
  oscillator.oscillatorNode |> OscillatorNode.disconnect();
  oscillator.oscillatorNode |> OscillatorNode.setOscillatorNodeType(Sine);
  oscillator.oscillatorNode |> OscillatorNode.stop();
};

let setOscillatorType =
    (~oscillatorType: OscillatorNode.oscillatorNodeType, oscillator: t): unit => {
  oscillator.oscillatorNode
  |> OscillatorNode.setOscillatorNodeType(oscillatorType);
};

let make =
    (
      ~oscillatorType: OscillatorNode.oscillatorNodeType=Sine,
      audioCtx: AudioContext.t,
    )
    : oscillator => {
  let oscillatorNode = audioCtx->AudioContext.createOscillator;
  let envelopeGain = audioCtx->AudioContext.createGain;
  oscillatorNode |> OscillatorNode.connect(envelopeGain);
  let outputGain = audioCtx->AudioContext.createGain;
  envelopeGain |> GainNode.connect(outputGain);
  let oscillator = {
    audioContext: audioCtx,
    oscillatorNode,
    oscillatorType,
    outputGain,
    envelopeGain,
  };
  oscillator |> setOscillatorType(~oscillatorType);
  oscillator;
};

let makeFromRandom = (audioCtx: AudioContext.t) => {
  let oscillator = audioCtx->make;
  let periodicWave =
    audioCtx |> AudioContext.makePeriodicWave(~samples=sampleRandomWave());
  oscillator |> setOscillatorType(~oscillatorType=Custom(periodicWave));
  oscillator;
};
