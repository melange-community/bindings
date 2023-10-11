module Make = (Messages: Messages.S) => {
  type t;

  /*** Getters */
  [@bs.get] external getName : t => string = "name";
  [@bs.get] external getAdapter : t => 'a = "adapter";
  /* Returns a JS object with socket IDs as keys. */
  [@bs.get] external getConnected : t => Js.t('a) = "connected";
  [@bs.send]
  external clients : (t, ('a, list(string)) => unit) => unit = "clients";

  /*** */
  [@bs.send]
  external use : (t, (Server.socketT, unit => unit) => unit) => unit = "use";

  /*** */
  [@bs.send] external default : Server.serverT => t = "sockets";

  /*** This is "of" in socket.io. */
  [@bs.send] external of_ : (Server.serverT, string) => t = "of";

  /*** This is "to" in socket.io or the "in" (they're synonyms apparently) */
  [@bs.send] external to_ : (t, string) => t = "to";

  /*** */
  [@bs.send] external _emit : (t, string, 'a) => unit = "emit";
  let emit = (server: t, obj: Messages.serverToClient) : unit =>
    _emit(server, "message", Json.toValidJson(obj));

  /*** Volatile */
  type volatileT;
  [@bs.get] external getVolatile : t => volatileT = "volatile";
  [@bs.send] external _volatileEmit : (volatileT, string, 'a) => unit = "emit";
  let volatileEmit = (server: t, obj: Messages.serverToClient) : unit =>
    _volatileEmit(getVolatile(server), "message", Json.toValidJson(obj));

  /*** Local */
  type localT;
  [@bs.get] external getLocal : t => localT = "local";
  [@bs.send] external _localEmit : (localT, string, 'a) => unit = "emit";
  let localEmit = (server: t, obj: Messages.serverToClient) : unit =>
    _localEmit(getLocal(server), "message", Json.toValidJson(obj));
};
