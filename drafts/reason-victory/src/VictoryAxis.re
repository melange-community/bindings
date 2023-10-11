[@bs.module "victory"]
external victoryAxis: ReasonReact.reactClass = "VictoryAxis";

let make =
    (
      ~tickValues=?,
      ~tickFormat: option('a => string)=?,
      ~dependentAxis: option(bool)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=victoryAxis,
    ~props={
      "tickValues": Js.Undefined.fromOption(tickValues),
      "tickFormat": Js.Undefined.fromOption(tickFormat),
      "dependentAxis": Js.Undefined.fromOption(dependentAxis),
    },
    children,
  );
