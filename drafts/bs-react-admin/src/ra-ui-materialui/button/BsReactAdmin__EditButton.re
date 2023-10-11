[@bs.module "react-admin"]
external editButton : ReasonReact.reactClass = "EditButton";

[@bs.deriving abstract]
type props('a, 'b) = {
  [@bs.optional]
  basePath: string,
  [@bs.optional]
  className: string,
  [@bs.optional]
  classes: 'a,
  [@bs.optional]
  label: string,
  [@bs.optional]
  record: 'b,
};

let make =
    (~basePath=?, ~className=?, ~classes=?, ~label=?, ~record=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=editButton,
    ~props=props(~basePath?, ~className?, ~classes?, ~label?, ~record?, ()),
    children,
  );
