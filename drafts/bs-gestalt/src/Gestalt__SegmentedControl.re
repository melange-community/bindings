[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~items: array(React.element),
    ~onChange: Gestalt__Event.t(ReactEvent.Mouse.t) => unit,
    ~selectedItemIndex: int,
    ~responsive: bool=?,
    ~size: [@bs.string] [ | `md | `lg]=?,
    unit
  ) =>
  React.element =
  "SegmentedControl";
