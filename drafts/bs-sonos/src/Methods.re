type sonos;

/* Create device */
module Speaker = {
  [@bs.new] [@bs.module "sonos"] external make: string => sonos = "Sonos";
};

module Device = {
  let make = ip => Speaker.make(ip);
};

module Group = {
  [@bs.deriving abstract]
  type groupReqArgs = {
    [@bs.as "InstanceID"]
    instanceId: int,
    [@bs.as "DesiredVolume"]
    volume: string,
  };

  type group = {
    .
    [@bs.meth] "_request": (string, groupReqArgs) => Js.Promise.t(Js.Json.t),
  };

  [@bs.new] [@bs.module "sonos"] [@bs.scope "Services"]
  external renderingControl: string => group = "GroupRenderingControl";
};

module SpotifyRegion = {
  type t;

  [@bs.module "sonos"] [@bs.scope "SpotifyRegion"] external europe: t = "EU";
  [@bs.send] external set: (sonos, t) => unit = "setSpotifyRegion";
};

module PlayerControl = {
  [@bs.send] external play: (sonos, unit) => Js.Promise.t(bool) = "play";
  [@bs.send] external pause: (sonos, unit) => Js.Promise.t(bool) = "pause";
  [@bs.send] external next: (sonos, unit) => Js.Promise.t(bool) = "next";
  [@bs.send]
  external previous: (sonos, unit) => Js.Promise.t(bool) = "previous";

  module State = {
    [@bs.send]
    external get: (sonos, unit) => Js.Promise.t(string) = "getCurrentState";
  };

  module Volume = {
    [@bs.send]
    external get: (sonos, unit) => Js.Promise.t(float) = "getVolume";
    [@bs.send] external set: (sonos, float) => Js.Promise.t('a) = "setVolume";
    [@bs.send]
    external mute: (sonos, bool) => Js.Promise.t(bool) = "setMuted";
  };
};

module Search = {
  [@bs.send]
  external musicLibrary: (sonos, string, string) => Js.Promise.t('a) =
    "searchMusicLibrary";
};

module Queue = {
  [@bs.send] external clear: (sonos, unit) => Js.Promise.t(bool) = "flush";
  [@bs.send] external removeMultipleTracks: (sonos, int, int) => Js.Promise.t('a) = "removeTracksFromQueue";
  [@bs.send] external get: (sonos, unit) => Js.Promise.t('a) = "getQueue";
  [@bs.send] external asLast: (sonos, string) => Js.Promise.t('a) = "queue";
  [@bs.send]
  external atPosition: (sonos, string, int) => Js.Promise.t('a) = "queue";

  /* Select queue is needed when the queue is being displayed as "not in use".
   * This might have if someone adds songs using the Sonos app */
  [@bs.send]
  external select: (sonos, unit) => Js.Promise.t(bool) = "selectQueue";
};

module Track = {
  [@bs.send]
  external current: (sonos, unit) => Js.Promise.t('a) = "currentTrack";
  [@bs.send]
  external select: (sonos, int) => Js.Promise.t(bool) = "selectTrack";
};
