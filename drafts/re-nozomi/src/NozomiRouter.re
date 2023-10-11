module Basic = {
  type t;
  [@bs.module "express"] external create : unit => t = "Router";
  [@bs.send]
  external use : (t, string, NozomiMiddleware.Basic.t) => unit = "use";
  [@bs.send]
  external all : (t, string, NozomiMiddleware.Basic.t) => unit = "all";
  [@bs.send]
  external get : (t, string, NozomiMiddleware.Basic.t) => unit = "get";
  [@bs.send]
  external post : (t, string, NozomiMiddleware.Basic.t) => unit = "post";
};

include
  NozomiRoutable.Make(
    {
      type router = Basic.t;
      let all = (router: router, path, handler: NozomiMiddleware.t) =>
        Basic.all(router, path, NozomiMiddleware.basic(handler));
      let get = (router: router, path, handler: NozomiMiddleware.t) =>
        Basic.get(router, path, NozomiMiddleware.basic(handler));
      let post = (router: router, path, handler: NozomiMiddleware.t) =>
        Basic.post(router, path, NozomiMiddleware.basic(handler));
    }
  );

let create = Basic.create;

let use = (router, ~path, ~f) => Basic.use(router, path, f);
/*
 let middleware0 =
     (router, ~request: Request.t, ~response: Response.t, ~next: unit => unit)
     : handler =>
   (~request, ~response, ~next) => ();
 let middleware: t => handler = router => middleware0(router);
 */