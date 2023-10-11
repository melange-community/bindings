[@bs.module "gestalt"] [@react.component]
external make:
  (~children: React.element, ~text: string, ~inline: bool=?, unit) =>
  React.element =
  "Tooltip";
