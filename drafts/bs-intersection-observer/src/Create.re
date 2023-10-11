open Types;

[@bs.new]
external newIntersectionObserver:
  (
    ~cb: (JsT.entries, Js.t(JsT.observer)) => unit,
    ~options: JsT.intersectionObserverParam=?,
    unit
  ) =>
  Js.t(JsT.observer) =
  "IntersectionObserver";

let intersectionObserver = (~cb, ~options) => {
  let observer =
    switch (options) {
    | Some(options) =>
      newIntersectionObserver(~cb=T.cbFromJsCb(cb), ~options, ())
    | None => newIntersectionObserver(~cb=T.cbFromJsCb(cb), ())
    };
  T.observerFromJsObserver(observer);
};