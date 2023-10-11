type t

@new external create: unit => t = "AudioContext"
@get external getDestination: t => Audio__AudioNode.t = "destination"
@get external getCurrentTime: t => float = "currentTime"
@send external createGain: t => Audio__AudioNode.t = "createGain"
@send external createOscillator: t => Audio__AudioNode.t = "create"
@send
external createMediaElementSource: (t, Dom.element) => Audio__AudioNode.t =
  "createMediaElementSource"

// AudioNode
@get external fromAudioNode: Audio__AudioNode.t => t = "context"
