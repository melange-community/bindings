module JsT = {
  type boundingClientRect = {
    .
    "x": float,
    "y": float,
    "left": float,
    "right": float,
    "top": float,
    "bottom": float,
    "width": float,
    "height": float,
  };

  type entry = {
    .
    boundingClientRect: boundingClientRect,
    intersectionRect: boundingClientRect,
    rootBounds: boundingClientRect,
    intersectionRatio: float,
    isIntersecting: bool,
    isVisible: bool,
    target: Dom.element,
    time: float,
  };
  type entries = array(Js.t(entry));

  type observer = {
    .
    [@bs.meth] observe: Dom.element => unit,
    [@bs.meth] unobserve: Dom.element => unit,
    [@bs.meth] disconnect: unit => unit,
    [@bs.meth] takeRecords: unit => entries,
    delay: int,
    root: option(Dom.element),
    rootMargin: string,
    thresholds: array(float),
    trackVisibility: bool,
  };

  type intersectionObserverParam = {
    .
    threshold: option(float),
    rootMargin: option(string),
    root: option(Dom.element),
  };
};

module T = {
  type boundingClientRect = {
    x: float,
    y: float,
    left: float,
    right: float,
    top: float,
    bottom: float,
    width: float,
    height: float,
  };

  type entry = {
    boundingClientRect,
    intersectionRect: boundingClientRect,
    rootBounds: boundingClientRect,
    intersectionRatio: float,
    isIntersecting: bool,
    isVisible: bool,
    target: Dom.element,
    time: float,
  };
  type entries = array(entry);

  type intersectionObserverParam = {
    threshold: option(float),
    rootMargin: option(string),
    root: option(Dom.element),
  };

  type observer = {
    observe: Dom.element => unit,
    unobserve: Dom.element => unit,
    disconnect: unit => unit,
    takeRecords: unit => entries,
    delay: int,
    root: option(Dom.element),
    rootMargin: string,
    thresholds: array(float),
    trackVisibility: bool,
  };

  let clientRectFromjsClientRect = boundingClientRect => {
    {
      x: boundingClientRect##x,
      y: boundingClientRect##y,
      left: boundingClientRect##left,
      right: boundingClientRect##right,
      top: boundingClientRect##top,
      bottom: boundingClientRect##bottom,
      width: boundingClientRect##width,
      height: boundingClientRect##height,
    };
  };

  let entriesFromJsEntries = entries => {
    Belt.Array.map(entries, entry =>
      {
        boundingClientRect:
          clientRectFromjsClientRect(entry##boundingClientRect),
        intersectionRect: clientRectFromjsClientRect(entry##intersectionRect),
        rootBounds: clientRectFromjsClientRect(entry##rootBounds),
        intersectionRatio: entry##intersectionRatio,
        isIntersecting: entry##isIntersecting,
        isVisible: entry##isVisible,
        target: entry##target,
        time: entry##time,
      }
    );
  };

  let observerFromJsObserver = (observer: Js.t(JsT.observer)) => {
    {
      observe: el => observer##observe(el),
      unobserve: el => observer##unobserve(el),
      disconnect: () => observer##disconnect(),
      takeRecords: () => observer##takeRecords()->entriesFromJsEntries,
      delay: observer##delay,
      root: observer##root,
      rootMargin: observer##rootMargin,
      thresholds: observer##thresholds,
      trackVisibility: observer##trackVisibility,
    };
  };

  let cbFromJsCb = (cb, entries: JsT.entries, observer) => {
    let formattedEntries = entriesFromJsEntries(entries);

    cb(formattedEntries, observerFromJsObserver(observer));
  };
};