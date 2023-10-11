type filter =
  | Lowpass
  | Highpass
  | Bandpass
  | Lowshelf
  | Highself
  | Peaking
  | Notch
  | Allpass;

type biquadFilterNode_tag;
type biquadFilterNode = AudioNode.audioNode_like(biquadFilterNode_tag);

type t = biquadFilterNode;

[@bs.set] external assignfilterType: (t, string) => unit = "type";
[@bs.get] external frequency: t => AudioParam.t = "frequency";

let setType = (filterNode: t, filterType: filter) =>
  switch (filterType) {
  | Lowpass => assignfilterType(filterNode, "lowpass")
  | Highpass => assignfilterType(filterNode, "highpass")
  | Bandpass => assignfilterType(filterNode, "bandpass")
  | _ => Js.log("Filter type not implemented yet")
  };

include AudioNode.Impl({
  type nonrec t = t;
});
