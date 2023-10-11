module type PresenceModule = {type t;};

module MakeModule = (Presence: PresenceModule) => {
  type t;

  type presence = {metas: array(Presence.t)};

  type presences = Js.Dict.t(presence);

  type diff = {
    joins: presences,
    leaves: presences,
  };

  type presenceCallback =
    (~id: string, ~currentPresence: presence, ~newPresence: presence) => unit;

  type presenceOpts = {
    state: string,
    diff: string,
  };

  [@bs.module "phoenix"] [@bs.new]
  external make: (Channel.t, option(presenceOpts)) => t = "Presence";

  [@bs.module "phoenix"] [@bs.scope "Presence"]
  external syncDiff:
    (
      ~currentState: presences,
      ~diff: diff,
      ~onJoin: presenceCallback=?,
      ~onLeave: presenceCallback=?,
      unit
    ) =>
    presences =
    "syncDiff";

  [@bs.module "phoenix"] [@bs.scope "Presence"]
  external syncState:
    (
      ~currentState: presences,
      ~newState: presences,
      ~onJoin: presenceCallback=?,
      ~onLeave: presenceCallback=?,
      unit
    ) =>
    presences =
    "syncState";

  [@bs.set] external onLeave: (t, presenceCallback) => unit = "onLeave";
  [@bs.set] external onJoin: (t, presenceCallback) => unit = "onJoin";

  let unwrap = presence => {
    presence.metas->Belt.Array.get(0);
  };
};
