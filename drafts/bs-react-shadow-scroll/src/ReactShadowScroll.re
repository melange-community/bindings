[@bs.module "react-shadow-scroll"]
external shadowScroll: ReasonReact.reactClass = "default";

[@bs.obj]
external makeProps:
  (
    ~scrollColor: string=?,
    ~scrollColorHover: string=?,
    ~scrollWidth: int=?,
    ~scrollPadding: int=?,
    ~isShadow: bool=?,
    ~shadow: string=?,
    ~styleSubcontainer: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let make =
    (
      ~scrollColor: option(string)=?,
      ~scrollColorHover: option(string)=?,
      ~scrollWidth: option(int)=?,
      ~scrollPadding: option(int)=?,
      ~isShadow: option(bool)=?,
      ~shadow: option(string)=?,
      ~styleSubcontainer: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=shadowScroll,
    ~props=
      makeProps(
        ~scrollColor?,
        ~scrollColorHover?,
        ~scrollWidth?,
        ~scrollPadding?,
        ~isShadow?,
        ~shadow?,
        ~styleSubcontainer?,
        (),
      ),
    children,
  );