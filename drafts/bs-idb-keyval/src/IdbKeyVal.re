type t;
[@bs.new] [@bs.module "idb-keyval"]
external createStore: (string, string) => t = "Store";
[@bs.module "idb-keyval"]
external set: (string, string, t) => Js.Promise.t(unit) = "set";
[@bs.module "idb-keyval"]
external get: (string, t) => Js.Promise.t(option(string)) = "get";
[@bs.module "idb-keyval"]
external keys: t => Js.Promise.t(Js.Array.t(string)) = "keys";
[@bs.module "idb-keyval"]
external delete: (string, t) => Js.Promise.t(unit) = "del";
[@bs.module "idb-keyval"] external clear: t => Js.Promise.t(unit) = "clear";