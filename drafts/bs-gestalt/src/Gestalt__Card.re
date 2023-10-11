[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~active: bool=?,
    ~children: React.element=?,
    ~image: React.element=?,
    ~onMouseEnter: Gestalt__Event.t(ReactEvent.Mouse.t) => unit=?,
    ~onMouseLeave: Gestalt__Event.t(ReactEvent.Mouse.t) => unit=?,
    unit
  ) =>
  React.element =
  "Card";
