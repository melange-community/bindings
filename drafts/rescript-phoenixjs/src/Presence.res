module type PresenceModule = {type t;};

module MakeModule = (Presence: PresenceModule) => {
  type t;

  type presence = {metas: array<Presence.t>};

  type presences = Js.Dict.t<presence>;

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

  @new external make: (Recursive.Channel.t, option<presenceOpts>) => t = "Presence"

  @scope("Presence") @val external syncDiff: 
    (
      ~currentState: presences,
      ~diff: diff,
      ~onJoin: presenceCallback=?,
      ~onLeave: presenceCallback=?,
      unit
    ) =>
    presences =
    "syncDiff";

  @scope("Presence") @val external syncState:
    (
      ~currentState: presences,
      ~newState: presences,
      ~onJoin: presenceCallback=?,
      ~onLeave: presenceCallback=?,
      unit
    ) =>
    presences =
    "syncState";

  @set external onLeave: (t, presenceCallback) => unit = "onLeave";
  @set external onJoin: (t, presenceCallback) => unit = "onJoin";
  @set external list: (presences, unit => unit) => presences = "list"

  let unwrap = presence => {
    presence.metas->Belt.Array.get(0);
  };
};
