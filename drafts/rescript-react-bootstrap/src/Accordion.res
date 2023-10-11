@module("react-bootstrap") @react.component
external make: (
  ~activeKey: string=?,
  ~_as: string=?,
  ~defaultActiveKey: string=?,
  ~flush: bool=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Accordion"

module Item = {
  @module("react-bootstrap") @scope("Accordion") @react.component
  external make: (
    ~_as: string=?,
    ~eventKey: string,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Item"
}

module Header = {
  @module("react-bootstrap") @scope("Accordion") @react.component
  external make: (
    ~_as: string=?,
    ~onClick: ReactEvent.Mouse.t => unit,
    ~bsPrefix: string=?,
  ) => React.element = "Header"
}

module Body = {
  @module("react-bootstrap") @scope("Accordion") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Body"
}

module Button = {
  @module("react-bootstrap") @scope("Accordion") @react.component
  external make: (
    ~_as: string=?,
    ~onClick: ReactEvent.Mouse.t => unit,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Button"

  @module("react-bootstrap") @scope("AccordionButton") @val
  external useAccordionButton: (
    ~eventKey: string,
    ~onClick: unit => unit,
    ReactEvent.Mouse.t,
  ) => unit = "useAccordionButton"
}

module Collapse = {
  @module("react-bootstrap") @scope("Accordion") @react.component
  external make: (
    ~_as: string=?,
    ~children: React.element,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Collapse"
}
