open Kanae;

type handler = (~error: NozomiError.t, ~html: string) => unit;

/* avoid duplicating name in locals */
type t = {path: string};

module type Locals = {type locals;};

module type S = {
  type locals;
  let create: string => t;
  let render:
    (t, ~response: NozomiResponse.t, ~locals: Js.t(locals), ~f: handler) =>
    unit;
};

module Make = (L: Locals) : (S with type locals := L.locals) => {
  type locals = L.locals;
  let create = path => {path: path};
  let render = (view, ~response, ~locals: Js.t(locals), ~f) =>
    NozomiResponse.render(response, ~view=view.path, ~locals, ~f);
};