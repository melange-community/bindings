[@bs.module "victory"]
external victoryChart: ReasonReact.reactClass = "VictoryChart";

let make =
    (
      ~domainPadding: option(int)=?,
      ~theme: option(VictoryCore.VictoryTheme.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=victoryChart,
    ~props={
      "domainPadding": Js.Undefined.fromOption(domainPadding),
      "theme": Js.Undefined.fromOption(theme),
    },
    children,
  );
