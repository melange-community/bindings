[@bs.deriving abstract]
type user = {
  authentication: string,
  token: string,
};

[@bs.deriving abstract]
type options = {
  [@bs.optional]
  mutable headers: Fetch.Headers.t,
  [@bs.optional]
  mutable body: Fetch.Body.t,
  [@bs.optional]
  mutable user,
  [@bs.optional] [@bs.as "method"]
  mutable method_: string,
};

type util;

[@bs.module "react-admin"] external fetchUtils : util = "";
[@bs.send]
external fetchJson : (util, string, options) => Js.Promise.t(Fetch.Response.t) =
  "";

let fetchJson = (url, options) => fetchJson(fetchUtils, url, options);
