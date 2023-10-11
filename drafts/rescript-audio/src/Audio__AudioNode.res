type t

@send external connect: (t, t) => t = "connect"
@send external disconnect: t => unit = "disconnect"
@get external getNumberOfInputs: t => int = "numberOfInputs"

@get external getGain: t => Audio__AudioParam.t = "gain"
let setGainValue = (gainNode, ~value, ~startTime) =>
  gainNode->getGain->Audio__AudioParam.setValueAtTime(~value, ~startTime)
