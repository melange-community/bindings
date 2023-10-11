module VO = {
  type intersectionObserverEntry = {. "isIntersecting": bool};

  [@bs.val] [@bs.scope "VisibilityObserver"] [@bs.module "react-is-visible"]
  external unwatch: Dom.element => unit = "unwatch";

  [@bs.val] [@bs.scope "VisibilityObserver"] [@bs.module "react-is-visible"]
  external watch: (Dom.element, intersectionObserverEntry => unit) => unit =
    "watch";

  [@bs.val] [@bs.scope "VisibilityObserver"] [@bs.module "react-is-visible"]
  external getSubscribers: unit => 'subscriberList = "getSubscribers";
};

type options = {once: bool};
let defaultOptions = {once: false};

let useIsVisible = (~options=defaultOptions, ()) => {
  let (isVisible, setIsVisible) = React.useState(() => false);
  let nodeRef = React.useRef(Js.Nullable.null);

  React.useEffect0(() => {
    let handleVisibilityChange = (el, entry) => {
      setIsVisible(_prevIntersecting => entry##isIntersecting);

      if (entry##isIntersecting && options.once) {
        VO.unwatch(el);
      };
    };

    let domElement =
      switch (nodeRef |> React.Ref.current |> Js.Nullable.toOption) {
      | Some(el) =>
        VO.watch(el, entry => handleVisibilityChange(el, entry));
        Some(el);

      | None => None
      };

    switch (domElement) {
    | Some(e) => Some(() => VO.unwatch(e))
    | None => None
    };
  });

  (isVisible, ReactDOMRe.Ref.domRef(nodeRef));
};