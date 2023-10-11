[@bs.module "victory"]
external victoryStack: ReasonReact.reactClass = "VictoryStack";

let make = (~colorScale=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=victoryStack,
    ~props={"colorScale": Js.Undefined.fromOption(colorScale)},
    children,
  );
