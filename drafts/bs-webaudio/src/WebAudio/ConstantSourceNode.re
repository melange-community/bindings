type constantSourceNode_tag;
type constantSourceNode = AudioNode.audioNode_like(constantSourceNode_tag);

type t = constantSourceNode;

[@bs.get] external offset: t => AudioParam.t = "offset";

include AudioNode.Impl({
  type nonrec t = t;
});
