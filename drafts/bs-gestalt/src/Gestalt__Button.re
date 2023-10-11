[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~text: string=?,
    ~accessibilityExpanded: bool=?,
    ~accessibilityHaspopup: bool=?,
    ~accessibilityLabel: string=?,
    ~color: [@bs.string] [ | `blue | `gray | `red | `transparent | `white]=?,
    ~disabled: bool=?,
    ~inline: bool=?,
    ~name: string=?,
    ~onClick: Gestalt__Event.t(ReactEvent.Mouse.t) => unit=?,
    ~size: [@bs.string] [ | `sm | `md | `lg]=?,
    ~_type: [@bs.string] [ | `submit | `button]=?,
    unit
  ) =>
  React.element =
  "Button";
