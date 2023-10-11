[@bs.module "react-transition-group/cjs/index"] [@react.component]
external make:
  (~appear: bool=?, ~enter: bool=?, ~exit: bool=?, ~className: string=?, ~children: React.element) =>
  React.element =
  "TransitionGroup";

let make = make;