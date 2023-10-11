let make:
  (~style: ReactPdfStyleSheet.t({..})=?, array(ReasonReact.reactElement)) =>
  ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps, ReasonReact.actionless);
