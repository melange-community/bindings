class type typedInstance =
  [@bs]
  {
    pub toggle: unit => unit;
    pub stop: unit => unit;
    pub start: unit => unit;
    pub destroy: unit => unit;
    pub reset: bool => unit;
  };

type t = Js.t(typedInstance);

type selector = string;

[@bs.deriving abstract]
type options = {
  [@bs.optional]
  strings: array(string),
  typeSpeed: int,
  [@bs.optional]
  typeDelay: int,
  [@bs.optional]
  stringsElement: string,
  [@bs.optional]
  backSpeed: int,
  [@bs.optional]
  smartBackspace: bool,
  [@bs.optional]
  shuffle: bool,
  [@bs.optional]
  backDelay: int,
  [@bs.optional]
  fadeOut: bool,
  [@bs.optional]
  fadeOutClass: string,
  [@bs.optional]
  fadeOutDelay: int,
  [@bs.optional]
  loop: bool,
  [@bs.optional]
  loopCount: float,
  [@bs.optional]
  showCursor: bool,
  [@bs.optional]
  cursorChar: string,
  [@bs.optional]
  autoInsertCss: bool,
  [@bs.optional]
  attr: string,
  [@bs.optional]
  bindInputFocusEvents: bool,
  [@bs.optional]
  contentType: string,
  [@bs.optional]
  onComplete: t => unit,
  [@bs.optional]
  preStringTyped: (int, t) => unit,
  [@bs.optional]
  onStringTyped: (int, t) => unit,
  [@bs.optional]
  onLastStringBackspaced: t => unit,
  [@bs.optional]
  onTypingPaused: (int, t) => unit,
  [@bs.optional]
  onTypingResumed: (int, t) => unit,
  [@bs.optional]
  onReset: t => unit,
  [@bs.optional]
  onStop: (int, t) => unit,
  [@bs.optional]
  onStart: (int, t) => unit,
  [@bs.optional]
  onDestroy: t => unit,
};

[@bs.module "typed.js"] [@bs.new]
external make: (selector, options) => t = "default";
