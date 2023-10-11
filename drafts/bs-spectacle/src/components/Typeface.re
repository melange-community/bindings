[@bs.module "spectacle"]
external reactClass: ReasonReact.reactClass = "Typeface";

[@bs.obj]
external makeProps:
  (
    ~font: string=?,
    ~googleFont: string=?,
    ~weight: int=?,
    ~italic: bool=?,
    unit
  ) =>
  _ =
  "";

let make = (~font=?, ~googleFont=?, ~weight=?, ~italic=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~font?, ~googleFont?, ~weight?, ~italic?, ()),
    children,
  );