type audioNode_like('a);

type audioNode_tag;
type t = audioNode_like(audioNode_tag);

module Impl = (T: {type t;}) => {
  [@bs.send.pipe: T.t]
  external connect: audioNode_like('a) => unit = "connect";
  [@bs.send.pipe: T.t]
  external connectToAudioParam: AudioParam.t => unit = "connect";
  [@bs.send.pipe: T.t] external disconnect: unit => unit = "disconnect";
};

include Impl({
  type nonrec t = t;
});
