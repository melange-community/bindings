open Types

type transition = ElemType(React.element) | Bool(bool)

@module("react-bootstrap") @react.component
external make: (
  ~closeLabel: string=?,
  ~closeVariant: [#white]=?,
  ~dismissible: bool=?,
  ~onClose: (~show: bool) => bool,
  ~show: bool=?,
  ~transition: transition=?,
  ~variant: variant=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Alert"

module Heading = {
  @module("react-bootstrap") @scope("Alert") @react.component
  external make: (
    ~_as: string=?,
    ~children: React.element,
    ~className: string=?,
    ~bsPrefix: string,
  ) => React.element = "Heading"
}

module Link = {
  @module("react-bootstrap") @scope("Alert") @react.component
  external make: (
    ~_as: string=?,
    ~children: React.element,
    ~className: string=?,
    ~bsPrefix: string,
  ) => React.element = "Link"
}
