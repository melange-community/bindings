open Types

type horizontal = [#sm | #md | #lg | #xl | #xxl]

@module("react-bootstrap") @react.component
external make: (
  ~_as: string=?,
  ~horizontal: horizontal=?,
  ~variant: [#flush]=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "ListGroup"

module Item = {
  @module("react-bootstrap") @scope("ListGroup") @react.component
  external make: (
    ~action: bool=?,
    ~active: bool=?,
    ~_as: string=?,
    ~disabled: bool=?,
    ~eventKey: string=?,
    ~href: string=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~variant: variant=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Item"
}
