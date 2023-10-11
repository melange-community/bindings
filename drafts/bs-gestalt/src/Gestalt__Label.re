[@bs.module "gestalt"] [@react.component]
external make:
  (~htmlFor: string, ~children: React.element=?, unit) => React.element =
  "Label";
