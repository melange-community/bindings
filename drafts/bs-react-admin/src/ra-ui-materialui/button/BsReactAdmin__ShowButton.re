[@bs.module "react-admin"]
external showButton : ReasonReact.reactClass = "ShowButton";

[@bs.deriving abstract]
type props('a, 'b) = {
  [@bs.optional]
  basePath: string,
  [@bs.optional]
  label: string,
  [@bs.optional]
  record: 'b,
};

let make = (~basePath=?, ~label=?, ~record=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=showButton,
    ~props=props(~basePath?, ~label?, ~record?, ()),
    children,
  );
