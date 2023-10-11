[@bs.module "gestalt"] [@react.component]
external make:
  (~accessibilityLabel: string, ~show: bool, unit) => React.element =
  "Spinner";
