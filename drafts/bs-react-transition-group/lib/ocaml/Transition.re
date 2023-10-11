[@bs.module "react-transition-group"]
external transitionClass: ReasonReact.reactClass = "Transition";

type state =
  | Entering
  | Entered
  | Exiting
  | Exited
  | NotTransitioning;

let stateOfString = str =>
  switch (str) {
  | "entering" => Entering
  | "entered" => Entered
  | "exiting" => Exiting
  | "exited" => Exited
  | _ => NotTransitioning
  };

let stringOfState = str =>
  switch (str) {
  | Entering => "entering"
  | Entered => "entered"
  | Exiting => "exiting"
  | Exited => "exited"
  | _ => "Not"
  };

let make =
    (
      ~in_=false,
      ~timeout: int,
      ~component="div",
      ~className="",
      children: state => ReasonReact.reactElement,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=transitionClass,
    ~props={
      "in": in_,
      "component": component,
      "timeout": timeout,
      "className": className,
    },
    (strState, _childProps) =>
    children(stateOfString(strState))
  );