type audioDestinationNode_tag;
type audioDestinationNode =
  AudioNode.audioNode_like(audioDestinationNode_tag);
type t = audioDestinationNode;

include AudioNode.Impl({
  type nonrec t = t;
});

external asAudioNodeLike: t => AudioNode.audioNode_like('a) = "%identity";
