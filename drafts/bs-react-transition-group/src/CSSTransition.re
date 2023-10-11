[@bs.module "react-transition-group"]
external cssTransition: ReasonReact.reactClass = "CSSTransition";

let make =
    (
      ~in_=false,
      ~timeout: int,
      ~className="",
      ~mountOnEnter=false,
      ~unmountOnExit=false,
      ~appear=false,
      ~enter=true,
      ~exit=true,
      ~classNames: string,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=cssTransition,
    ~props={
      "in": in_,
      "timeout": timeout,
      "classNames": classNames,
      "className": className,
      "mountOnEnter": mountOnEnter,
      "unmountOnExit": unmountOnExit,
      "appear": appear,
      "enter": enter,
      "exit": exit,
    },
    children,
  );