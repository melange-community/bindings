[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~href: string,
    ~children: React.element=?,
    ~inline: bool=?,
    ~onClick: Gestalt__Event.t(ReactEvent.Mouse.t) => unit=?,
    ~target: [@bs.string] [ | `null | `self | `blank]=?,
    unit
  ) =>
  React.element =
  "Link";
