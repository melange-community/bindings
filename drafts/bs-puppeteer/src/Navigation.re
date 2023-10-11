/* TODO: allow calling makeOptions with waitUntil: array(string), an array of load event */
[@bs.deriving jsConverter]
type loadEvent = [
  | `load
  | `domcontentloaded
  | `networkidle0
  | `networkidle2
];

type loadEvents =
  | LoadEvent(loadEvent)
  | LoadEvents(array(loadEvent));

type options = {
  .
  "referer": Js.Nullable.t(string),
  "timeout": Js.Nullable.t(float),
  "waitUntil": Js.Nullable.t(string),
};

[@bs.obj]
external makeOptions:
  (
    ~referer: string=?,
    ~timeout: float=?,
    ~waitUntil: [@bs.string] [
                  | `load
                  | `domcontentloaded
                  | `networkidle0
                  | `networkidle2
                ]
                  =?,
    unit
  ) =>
  options =
  "";
