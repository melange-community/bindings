let make:
  (~style: Js.t({..})=?, ~key: string=?, array(ReasonReact.reactElement)) =>
  ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps, ReasonReact.actionless);
