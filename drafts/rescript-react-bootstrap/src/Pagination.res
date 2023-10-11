open Types

@module("react-bootstrap") @react.component
external make: (
  ~size: size=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Pagination"

module Item = {
  @module("react-bootstrap") @scope("Pagination") @react.component
  external make: (
    ~active: bool=?,
    ~activeLabel: string=?,
    ~disabled: bool=?,
    ~href: string=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~className: string=?,
    ~children: React.element,
  ) => React.element = "Item"
}

module First = {
  @module("react-bootstrap") @scope("Pagination") @react.component
  external make: (
    ~active: bool=?,
    ~activeLabel: string=?,
    ~disabled: bool=?,
    ~className: string=?,
  ) => React.element = "First"
}

module Prev = {
  @module("react-bootstrap") @scope("Pagination") @react.component
  external make: (
    ~active: bool=?,
    ~activeLabel: string=?,
    ~disabled: bool=?,
    ~className: string=?,
  ) => React.element = "Prev"
}

module Ellipsis = {
  @module("react-bootstrap") @scope("Pagination") @react.component
  external make: (
    ~active: bool=?,
    ~activeLabel: string=?,
    ~disabled: bool=?,
    ~className: string=?,
  ) => React.element = "Ellipsis"
}

module Next = {
  @module("react-bootstrap") @scope("Pagination") @react.component
  external make: (
    ~active: bool=?,
    ~activeLabel: string=?,
    ~disabled: bool=?,
    ~className: string=?,
  ) => React.element = "Next"
}

module Last = {
  @module("react-bootstrap") @scope("Pagination") @react.component
  external make: (
    ~active: bool=?,
    ~activeLabel: string=?,
    ~disabled: bool=?,
    ~className: string=?,
  ) => React.element = "Last"
}
