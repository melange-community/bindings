type oscillatorNode_tag;
type oscillatorNode = AudioNode.audioNode_like(oscillatorNode_tag);

type t = oscillatorNode;

type oscillatorNodeType =
  | Sine
  | Square
  | Sawtooth
  | Triange
  | Custom(PeriodicWave.t);

module Impl = (T: {type t;}) => {
  [@bs.new] external createOscillator: unit => T.t = "OscillatorNode";
  [@bs.send.pipe: T.t] external start: unit => unit = "start";
  [@bs.send.pipe: T.t] external stop: unit => unit = "stop";
  [@bs.send.pipe: T.t] external stopAt: float => unit = "stop";
  [@bs.get] external getOscillatorType: T.t => string = "type";
  [@bs.set] external setOscillatorType: (T.t, string) => unit = "type";
  [@bs.get] external frequency: T.t => AudioParam.t = "frequency";
  [@bs.send.pipe: T.t]
  external setPeriodicWave: PeriodicWave.t => unit = "setPeriodicWave";
};

include AudioNode.Impl({
  type nonrec t = t;
});

include Impl({
  type nonrec t = t;
});

let setOscillatorNodeType =
    (oscillatorType: oscillatorNodeType, oscillatorNode: t): unit => {
  let setOscillatorNodeType = setOscillatorType(oscillatorNode);
  switch (oscillatorType) {
  | Sine => setOscillatorNodeType("sine")
  | Square => setOscillatorNodeType("square")
  | Sawtooth => setOscillatorNodeType("sawtooth")
  | Triange => setOscillatorNodeType("triangle")
  | Custom(periodicWave) => oscillatorNode |> setPeriodicWave(periodicWave)
  };
};
