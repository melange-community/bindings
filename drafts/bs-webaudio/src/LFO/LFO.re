/**************************************************************************
 *                                                                        *
 *   +----------------+       +------------------+                        *
 *   | oscillatorNode |       |constantSourceNode|                        *
 *   +----------------+       +------------------+                        *
 *                 |             |                                        *
 *                 |             |                                        *
 *                 v             v       connect                          *
 *             +---------------------+   to gain   +----------------+     *
 *             |                     |    param    |                |     *
 *             |   paramOscillator   |------------>|   outputGain   |     *
 *             |                     |             |                |     *
 *             +---------------------+             +----------------+     *
 *                    gainNode                          gainNode          *
 *                                                                        *
 **************************************************************************/
type lfo = {
  audioContext: AudioContext.t,
  oscillatorNode: Oscillator.t,
  outputGain: GainNode.t,
};

type t = lfo;

let defaultFrequency = 3.0;

let make = (audioCtx: AudioContext.t): t => {
  let paramOscillator = AudioContext.createGain(audioCtx);
  paramOscillator->GainNode.gain->AudioParam.setValue(0.5);

  let oscillatorNode = Oscillator.make(~oscillatorType=Sine, audioCtx);
  oscillatorNode.oscillatorNode
  ->OscillatorNode.frequency
  ->AudioParam.setValue(defaultFrequency);

  let constantSourceNode = AudioContext.createConstantSource(audioCtx);

  oscillatorNode |> Oscillator.connect(~target=paramOscillator) |> ignore;
  constantSourceNode |> ConstantSourceNode.connect(paramOscillator);

  let outputGain = AudioContext.createGain(audioCtx);
  paramOscillator |> GainNode.connectToAudioParam(GainNode.gain(outputGain));

  {outputGain, oscillatorNode, audioContext: audioCtx};
};

let connect = (~target: AudioNode.audioNode_like('a), lfo: t): t => {
  lfo.outputGain |> GainNode.connect(target);
  lfo;
};

let start = (lfo: t): t => {
  Oscillator.start(lfo.oscillatorNode) |> ignore;
  lfo;
};

let setFrequency = (~frequency: float, lfo: t): unit => {
  lfo.oscillatorNode |> Oscillator.setFrequency(~frequency);
};

let getFrequency = (lfo: t): AudioParam.t => {
  lfo.oscillatorNode |> Oscillator.getFrequency;
};
