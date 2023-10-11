type t
@new external create: (array<t>, {"type": string}) => t = "Blob"
@scope("URL") @val external createUrl: t => string = "createObjectURL"

let createFromBlob = blob => [blob]->create({"type": "audio/ogg; codecs=opus"})
let createUrlFromBlob = blob => blob->createFromBlob->createUrl
