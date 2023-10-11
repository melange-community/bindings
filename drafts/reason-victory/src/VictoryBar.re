[@bs.module "victory"]
external victoryBar: ReasonReact.reactClass = "VictoryBar";

let make = (~data: option(array(VictoryCore.dataPoint))=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=victoryBar,
    ~props={"data": Js.Undefined.fromOption(data)},
    children,
  );
