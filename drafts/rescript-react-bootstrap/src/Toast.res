open Types

@module("react-bootstrap") @react.component
external make: (
  ~animation: bool=?,
  ~autohide: bool=?,
  ~bg: variant=?,
  ~delay: int=?,
  ~onClose: unit => unit=?,
  ~show: bool=?,
  ~transition: reactNode=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Toast"

module Header = {
  @module("react-bootstrap") @scope("Toast") @react.component
  external make: (
    ~closeButton: bool=?,
    ~closeLabel: string=?,
    ~closeVariant: [#white]=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Header"
}

module Body = {
  @module("react-bootstrap") @scope("Toast") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Body"
}
