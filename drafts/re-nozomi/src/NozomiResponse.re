open Kanae;

module Basic = {
  type t;
  [@bs.send]
  external render :
    (t, string, Js.t('locals), ('error, string) => [@bs.uncurry] unit) => unit =
    "render";
  [@bs.send] external append : (t, string, string) => string = "append";
  [@bs.send] external get : t => string = "get";
  [@bs.send] external location : (t, string) => unit = "location";
  [@bs.send] external send : (t, string) => unit = "send";
  [@bs.send] external status : (t, int) => t = "status";
  [@bs.send] external type_ : (t, string) => string = "type";
};

type t = Basic.t;

let from = (js: Basic.t) : t => js;

let basic = (req: t) : Basic.t => req;

let append = Basic.append;

let location = Basic.location;

let get = Basic.get;

let render =
    (
      res,
      ~view,
      ~locals,
      ~f: (~error: 'error, ~html: string) => [@bs.uncurry] unit
    ) =>
  Basic.render(res, view, locals, (error, html) => f(~error, ~html));

let send = Basic.send;

let status = Basic.status;

let type_ = Basic.type_;