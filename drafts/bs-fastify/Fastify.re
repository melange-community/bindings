open BsNode;
open Belt;
type t;

module Schema = {
  [@bs.deriving abstract]
  type property = {
    [@bs.as "type"]
    type_: string,
  };

  [@bs.deriving abstract]
  type bodySchemaConfig = {
    [@bs.as "type"]
    type_: string,
    [@bs.optional]
    required: array(string),
    properties: Js.Dict.t(property),
  };

  [@bs.deriving abstract]
  type schemaType = {
    [@bs.optional]
    body: bodySchemaConfig,
  };

  [@bs.deriving abstract]
  type t = {schema: schemaType};

  let createBodySchema =
      (
        ~required: option(array(string))=?,
        ~properties: Js.Dict.t(property),
      ) =>
    t(
      ~schema=
        schemaType(
          ~body=
            bodySchemaConfig(
              ~type_="object",
              ~required=required->Option.getWithDefault([||]),
              ~properties,
              (),
            ),
          (),
        ),
    );
};

module Request = {
  type t;
  type log;

  module Headers = {
    type t;

    [@bs.get] external range: t => Js.Nullable.t(string) = "range";
  };

  module Log = {
    type t;

    [@bs.send] external info: (t, string) => unit = "info";
  };

  [@bs.get] external body: t => 'a = "body";
  [@bs.get] external params: t => 'a = "params";
  [@bs.get] external log: t => Log.t = "log";
  [@bs.get] external headers: t => Headers.t = "headers";

  [@bs.send]
  external multipart:
    (
      t,
      (string, Fs.Stream.t, string, string, string) => unit,
      Js.Nullable.t(Js.Exn.t) => unit
    ) =>
    unit =
    "multipart";
};

module Response = {
  type t;

  [@bs.send] external sendString: (t, string) => unit = "send";

  [@bs.send] external sendObject: (t, Js.t('a)) => unit = "send";

  [@bs.send] external sendUnit: (t, unit) => unit = "send";

  [@bs.send] external sendStream: (t, Fs.Stream.t) => unit = "send";

  [@bs.send] external code: (t, int) => unit = "code";

  [@bs.send] external header: (t, string, string) => unit = "header";

  [@bs.send] external getHeader: (t, string) => option(string) = "getHeader";

  [@bs.send] external hasHeader: (t, string) => bool = "hasHeader";
};

module AppOptions = {
  type t;

  [@bs.obj]
  external make:
    (
      ~logger: bool=?,
      ~ignoreTrailingSlash: bool=?,
      ~https: bool=?,
      ~http2: bool=?,
      ~maxParamLength: int=?,
      ~bodyLimit: int=?,
      ~onProtoPoisoning: [@bs.string] [ | `error | `remove | `ignore]=?,
      ~onConstructorPoisoning: [@bs.string] [ | `error | `remove | `ignore]=?,
      unit
    ) =>
    t =
    "";
};

[@bs.module] external createApp: AppOptions.t => t = "fastify";

[@bs.send] external register: (t, 'a) => unit = "register";

[@bs.send] external use1: (t, 'a) => unit = "use";

[@bs.send] external use2: (t, 'a, 'b) => unit = "use";

[@bs.send]
external get: (t, string, (Request.t, Response.t) => unit) => unit = "get";

[@bs.send]
external post: (t, string, (Request.t, Response.t) => unit) => unit = "post";

[@bs.send]
external put: (t, string, (Request.t, Response.t) => unit) => unit = "put";

[@bs.send]
external delete: (t, string, (Request.t, Response.t) => unit) => unit =
  "delete";

[@bs.send]
external postWithSchema:
  (t, string, Schema.t, (Request.t, Response.t) => unit) => unit =
  "post";

[@bs.send]
external deleteWithSchema:
  (t, string, Schema.t, (Request.t, Response.t) => unit) => unit =
  "delete";

[@bs.send]
external listen: (t, int, (Js.Nullable.t(Js.Exn.t), string) => unit) => unit =
  "listen";
