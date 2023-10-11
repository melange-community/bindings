type t;

[@bs.deriving abstract]
type instOptions = {
  [@bs.optional]
  aip: string, /* anonymize ip */
  [@bs.optional]
  an: string, /* application name */
  [@bs.optional]
  aid: string, /* application identifier */
  [@bs.optional]
  aiid: string, /* application installer identifier */
  [@bs.optional]
  av: string, /* application version */
  [@bs.optional]
  ds: string /* data source */
};

[@bs.val] [@bs.module "ganalytics"]
external make: (string, Js.Nullable.t(instOptions), bool) => t = "default";

[@bs.deriving jsConverter]
type eventType = [ | [@bs.as "event"] `Event | [@bs.as "pageview"] `Pageview];

[@bs.deriving abstract]
type eventOptions = {
  [@bs.optional]
  ec: string, /* event category */
  [@bs.optional]
  ea: string, /* event action */
  [@bs.optional]
  ev: string, /* event label */
  [@bs.optional]
  el: string, /* event value */
  [@bs.optional]
  dt: string, /* document title */
  [@bs.optional]
  dl: string, /* document url */
  [@bs.optional]
  dh: string, /* document host */
  [@bs.optional]
  dp: string, /* document path */
  [@bs.optional]
  uid: string, /* user id */
  [@bs.optional]
  an: string, /* application name */
  [@bs.optional]
  aid: string, /* application id */
  [@bs.optional]
  av: string /* application version */
};

[@bs.send.pipe: t] external send: (string, eventOptions) => unit = "";

let send = (eventType, opts) => send(eventTypeToJs(eventType), opts);
