type state = string;
type node = Dom.element;
type isAppearing = bool;
type enterMethod = (node, isAppearing) => unit;
type exitMethod = node => unit;

[@bs.deriving abstract]
type timeoutFull = {
  [@bs.optional]
  enter: int,
  [@bs.optional]
  exit: int,
};

type timeout = [ | `int(int) | `obj(timeoutFull)];

module TimeoutValue = {
  type t;
  external int: int => t = "%identity";
  external timeoutFull: timeoutFull => t = "%identity";
};

let setTimeout = (a: timeout) =>
  switch (a) {
  | `int(int) => TimeoutValue.int(int)
  | `obj(timeoutFull) => TimeoutValue.timeoutFull(timeoutFull)
  };

module InternalBind = {
  [@bs.module "react-transition-group/cjs/index"] [@react.component]
  external make:
    (
      ~_in: option(bool),
      ~mountOnEnter: option(bool),
      ~unmountOnExit: option(bool),
      ~appear: option(bool),
      ~enter: option(bool),
      ~exit: option(bool),
      ~timeout: option(TimeoutValue.t),
      ~onEnter: option(enterMethod),
      ~onEntering: option(enterMethod),
      ~onEntered: option(enterMethod),
      ~onExit: option(exitMethod),
      ~onExiting: option(exitMethod),
      ~onExited: option(exitMethod),
      ~children: state => React.element
    ) =>
    React.element =
    "Transition";
};

[@react.component]
let make =
    (
      ~_in=?,
      ~mountOnEnter=?,
      ~unmountOnExit=?,
      ~appear=?,
      ~enter=?,
      ~exit=?,
      ~timeout=?,
      ~onEnter=?,
      ~onEntering=?,
      ~onEntered=?,
      ~onExit=?,
      ~onExiting=?,
      ~onExited=?,
      ~children: state => React.element,
    ) =>
  <InternalBind
    _in
    mountOnEnter
    unmountOnExit
    appear
    enter
    exit
    timeout={
      switch (timeout) {
      | Some(timeout) => Some(setTimeout(timeout))
      | None => None
      }
    }
    onEnter
    onEntering
    onEntered
    onExit
    onExiting
    onExited>
    {state => children(state)}
  </InternalBind>;
