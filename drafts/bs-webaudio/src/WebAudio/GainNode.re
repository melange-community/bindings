type gainNode_tag;
type gainNode = AudioNode.audioNode_like(gainNode_tag);

type t = gainNode;

module Imp = (T: {type t;}) => {
  [@bs.new] external createGainNode: unit => gainNode = "GainNode";
  [@bs.get] external gain: t => AudioParam.t = "gain";
};

include AudioNode.Impl({
  type nonrec t = gainNode;
});

include Imp({
  type t = gainNode;
});
