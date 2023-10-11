/*
 Bindings for the npm package `js-cookie`. It provides a convinent interface
 for setting and getting cookies including storing JSON in cookies. Also it makes
 it cross browser compatible, even for older browsers.
 */
/*
 This is the config that gets passed to JS
 */
type config;

[@bs.obj]
external makeConfig : (~expires: int=?, ~path: string=?, unit) => config = "";

/*
  sets a cookie by a name to JSON
 */
[@bs.module "js-cookie"]
external setJson : (string, Js.Json.t) => unit = "set";

/*
   sets a cookie by a name to JSON with config
 */
[@bs.module "js-cookie"]
external setJsonConfig : (string, Js.Json.t, config) => unit = "set";

/*
  sets a cookie by a name to a string
 */
[@bs.module "js-cookie"] external setString : (string, string) => unit = "set";

/*
  sets a cookie by a name to a string with config
 */
[@bs.module "js-cookie"] external setStringConfig : (string, string, config) => unit = "set";

/*
  removes a cookie
 */
[@bs.module "js-cookie"] external remove : string => unit = "remove";

/*
  get a cookie's contents as a string
 */
[@bs.module "js-cookie"] [@bs.return nullable]
external getAsString : string => option(string) = "get";

/*
  get a cookie's contents as JSON
 */
[@bs.module "js-cookie"] [@bs.return nullable]
external getAsJson : string => option(Js.Json.t) = "getJSON";