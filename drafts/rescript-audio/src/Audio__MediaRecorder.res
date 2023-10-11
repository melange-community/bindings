type event
type blobEvent = {data: Audio__AudioBlob.t}
type t = {@set "ondataavailable": blobEvent => unit}

@new external create: Audio__MediaStream.t => t = "MediaRecorder"
@get external getState: t => string = "state"
@send external requestData: (t, unit) => Audio__AudioBlob.t = "requestData"
@send external _start: t => unit = "start"
let start = (mediaRecorder, ~onDataAvailable) => {
  mediaRecorder["ondataavailable"] = onDataAvailable
  mediaRecorder->_start
}
@send external stop: t => unit = "stop"
@send external pause: t => unit = "pause"
@send external resume: t => unit = "resume"
