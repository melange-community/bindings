module History = {
  type t;
  module Location = {
    type t;
    external pathname : t => string = "" [@@bs.get];
    external search : t => string = "" [@@bs.get];
    external hash : t => string = "" [@@bs.get];
    external key : t => option string = "" [@@bs.get] [@@bs.return null_undefined_to_opt];
  };
  type action = [ | `PUSH | `REPLACE | `POP] [@@bs.string];
  external length : t => int = "" [@@bs.get];
  external action : t => action = "" [@@bs.get];
  external location : t => string = "" [@@bs.get];
  external listen : t => location::Location.t => action::action => unit => unit = "" [@@bs.send];
  /* TODO: state typing */
  module State = {
    type t;
  };
  external push : t => url::string => state::list State.t => unit = "" [@@bs.send];
  external replace : t => url::string => state::list State.t => unit = "" [@@bs.send];
  external go : t => jumps::int => unit = "" [@@bs.send];
  external goBack : t => unit = "" [@@bs.send];
  external goForward : t => unit = "" [@@bs.send];
};

type getUserConfirmation = path::string => confirmation::bool => unit;

type browserHistoryOpt = {
  basename: string,
  forceRefresh: bool,
  keyLength: int,
  getUserConfirmation
};

external createBrowserHistory : browserHistoryOpt => History.t = "" [@@bs.module];

type memoryHistoryOpt = {initialEntries: list string, initialIndex: int, keyLength: int};

external createMemoryHistory : memoryHistoryOpt => History.t = "" [@@bs.module];

type hashHistoryOpt = {basename: string, hashType: string, getUserConfirmation};

external createHashHistory : hashHistoryOpt => History.t = "" [@@bs.module];
