[@bs.module "gestalt"] [@react.component]
external make:
  (~text: string, ~position: [@bs.string] [ | `middle | `top]=?, unit) =>
  React.element =
  "Badge";
