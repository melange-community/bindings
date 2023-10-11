[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~accessibilityCloseLabel: string,
    ~accessibilityModalLabel: string,
    ~heading: React.element,
    ~onDismiss: unit => unit,
    ~children: React.element=?,
    ~footer: React.element=?,
    ~role: [@bs.string] [ | `alertdialog | `dialog]=?,
    ~size: [@bs.string] [ | `sm | `md | `lg]=?,
    unit
  ) =>
  React.element =
  "Modal";
