[@bs.module "react-transition-group"]
external transitionGroup: ReasonReact.reactClass = "TransitionGroup";
let make =
    (
      ~className="", 
      ~component="div", 
      children
      ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=transitionGroup,
    ~props={
      "component": component,
      "className": className,
    },
    children,
  );