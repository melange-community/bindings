[@bs.module "react-highlight/lib/index.js"]
external highlight: ReasonReact.reactClass = "default";

[@bs.deriving abstract]
type jsProps = {
  className: option(string),
  innerHTML: bool,
};

let make = (~className: option(string)=?, ~innerHTML=false, children: string) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=highlight,
    ~props=jsProps(~className, ~innerHTML),
    children,
  );