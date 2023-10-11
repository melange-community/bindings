[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~anchor: Js.Nullable.t(Dom.element),
    ~onDismiss: unit => unit,
    ~children: React.element=?,
    ~color: [@bs.string] [ | `blue | `orange | `white | `darkGray]=?,
    ~idealDirection: [@bs.string] [ | `up | `right | `down | `left]=?,
    ~positionRelativeToAnchor: bool=?,
    ~shouldFocus: bool=?,
    ~size: [@bs.string] [ | `xs | `sm | `md | `lg | `xl]=?,
    unit
  ) =>
  React.element =
  "Flyout";
