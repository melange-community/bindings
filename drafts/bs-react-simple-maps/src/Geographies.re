[@bs.module "react-simple-maps"]
external geographiesClass : ReasonReact.reactClass = "Geographies";

[@bs.deriving abstract]
type jsProps = {
  disableOptimization: bool,
  geography: string,
};

let make = (~disableOptimization=false, ~geography="", children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographiesClass,
    ~props=jsProps(~disableOptimization, ~geography),
    children,
  );
