@module("react-bootstrap") @react.component
external make: (
  ~id: string=?,
  ~_as: string=?,
  ~children: React.element,
  ~bg: string=?,
  ~expand: [#sm | #md | #lg | #xl | #xxl],
  ~expanded: bool=?,
  ~fixed: [#top | #bottom],
  ~role: string=?,
  ~variant: [#light | #dark],
  ~collapseOnSelect: bool=?,
  ~onSelect: (~eventKey: string, ~event: ReactEvent.Synthetic.t) => unit=?,
  ~onToggle: bool => unit=?,
  ~sticky: [#top]=?,
  ~className: string=?,
  ~bsPrefix: string=?,
) => React.element = "Navbar"

module Brand = {
  @module("react-bootstrap") @scope("Navbar") @react.component
  external make: (
    ~is: string=?,
    ~_as: string=?,
    ~href: string,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Brand"
}

module Collapse = {
  @module("react-bootstrap") @scope("Navbar") @react.component
  external make: (
    ~id: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Collapse"
}

module Toggle = {
  @module("react-bootstrap") @scope("Navbar") @react.component
  external make: (
    ~id: string=?,
    ~_as: string=?,
    ~children: React.element=?,
    ~label: string=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~\"aria-controls": string=?,
    ~className: string=?,
    ~bsPrefix: string=?,
  ) => React.element = "Toggle"
}
