type mediaDevices
type navigator = {mediaDevices: Js.undefined<mediaDevices>}
type t

type mediaDevicesConstraints = {
  video: bool,
  audio: bool,
}

@send
external getUserMedia: (mediaDevices, mediaDevicesConstraints) => Js.Promise.t<t> = "getUserMedia"
@val external nav: navigator = "navigator"

type streamResult = Ok(t) | Error(exn)

let getStream = () => {
  open Promise
  let maybeMediaDevices = nav.mediaDevices->Js.Undefined.toOption

  switch maybeMediaDevices {
  | Some(mediaDevices) =>
    mediaDevices
    ->getUserMedia({video: false, audio: true})
    ->then(stream => stream->Ok->resolve)
    ->catch(err => err->Error->resolve)
  | None =>
    let msg = "The method getUserMedia is not supported in this environment"
    msg->Js.Exn.raiseError->Error->resolve
  }
}
