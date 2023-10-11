let handleReponse = (decoded, message) =>
  switch (decoded) {
  | Belt.Result.Ok(result) => result
  | Belt.Result.Error(actual) =>
    Js.log(actual);
    failwith(message);
  };

module CurrentTrack = {
  [@decco]
  type t = {
    album: option(string),
    [@decco.default ""]
    albumArtURI: string,
    [@decco.default ""]
    albumArtURL: string,
    [@decco.default ""]
    artist: string,
    duration: float,
    position: float,
    queuePosition: float,
    [@decco.default ""]
    title: string,
    uri: option(string),
  };

  let make = json =>
    json->t_decode->handleReponse("Couldn't parse current track");
};

module QueueTrack = {
  [@decco]
  type t = {
    [@decco.key "FirstTrackNumberEnqueued"]
    firstTrackNumberEnqueued: string,
    [@decco.key "NewQueueLength"]
    newQueueLength: string,
    [@decco.key "NumTracksAdded"]
    numTracksAdded: string,
  };

  let make = json =>
    json->t_decode->handleReponse("Couldn't parse current queue");
};

module CurrentQueue = {
  [@decco]
  type queueItem = {
    album: option(string),
    albumArtURI: string,
    artist: string,
    title: string,
    uri: string,
  };

  [@decco]
  type t = {
    returned: string,
    total: string,
    items: array(queueItem),
  };

  let make = json =>
    json->t_decode->handleReponse("Couldn't parse current queue");
};

module CurrentPlayState = {
  type t =
    | Paused
    | Stopped
    | Playing
    | UnknownState;

  let make =
    fun
    | "stopped" => Stopped
    | "paused" => Paused
    | "playing" => Playing
    | _ => UnknownState;
};
