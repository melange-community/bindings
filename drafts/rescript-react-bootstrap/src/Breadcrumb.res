open Types

@module("react-bootstrap") @react.component
external make: (
  ~_as: string=?,
  ~label: string=?,
  ~listProps: {.}=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Breadcrumb"

module Item = {
  @module("react-bootstrap") @scope("Breadcrumb") @react.component
  external make: (
    ~active: bool=?,
    ~_as: string=?,
    ~href: string=?,
    ~linkAs: string=?,
    ~linkProps: {.}=?,
    ~target: string=?,
    ~title: reactNode=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Item"
}
