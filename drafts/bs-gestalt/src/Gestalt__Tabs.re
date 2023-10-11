[@bs.deriving abstract]
type t = {
  text: React.element,
  href: string,
};

[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~activeTabIndex: int,
    ~onChange: Gestalt__Event.t(ReactEvent.Mouse.t) => unit,
    ~tabs: array(t),
    ~wrap: bool=?,
    unit
  ) =>
  React.element =
  "Tabs";
