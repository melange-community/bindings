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

[@bs.deriving abstract]
type classFull = {
  [@bs.optional]
  appear: string,
  [@bs.optional]
  appearActive: string,
  [@bs.optional]
  enter: string,
  [@bs.optional]
  enterActive: string,
  [@bs.optional]
  enterDone: string,
  [@bs.optional]
  exit: string,
  [@bs.optional]
  exitActive: string,
  [@bs.optional]
  exitDone: string,
};

module ClassValue = {
  type t;
  external string: string => t = "%identity";
  external classFull: classFull => t = "%identity";
};

type classNames = [ | `string(string) | `obj(classFull)];

let setClassName =
  fun
  | `string(string) => ClassValue.string(string)
  | `obj(classFull) => ClassValue.classFull(classFull);

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
      ~classNames: option(ClassValue.t),
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
    "CSSTransition";
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
      ~classNames=?,
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
    classNames={
      switch (classNames) {
      | Some(classNames) => Some(setClassName(classNames))
      | None => None
      }
    }
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
