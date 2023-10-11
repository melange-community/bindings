@module("react-bootstrap") @react.component
external make: (
  ~id: string=?,
  ~activeKey: string=?,
  ~className: string=?,
  ~navbarScroll: bool=?,
  ~_as: string=?,
  ~fill: bool=?,
  ~justify: bool=?,
  ~navbar: bool=?,
  ~navbarBsPrefix: string=?,
  ~cardHeaderBsPrefix: string=?,
  ~role: string=?,
  ~onSelect: (~eventKey: string, ~event: ReactEvent.Synthetic.t) => unit=?,
  ~onKeyDown: unit => unit=?,
  ~variant: [#tabs | #pills],
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Nav"

module Item = {
  @module("react-bootstrap") @scope("Nav") @react.component
  external make: (
    ~id: string=?,
    ~className: string=?,
    ~children: React.element,
    ~_as: string=?,
    ~bsPrefix: string,
  ) => React.element = "Item"
}

module Link = {
  @module("react-bootstrap") @scope("Nav") @react.component
  external make: (
    ~id: string=?,
    ~children: React.element,
    ~_as: string=?,
    ~active: bool=?,
    ~disabled: bool=?,
    ~href: string,
    ~className: string=?,
    ~eventKey: string=?,
    ~role: string=?,
    ~bsPrefix: string=?,
  ) => React.element = "Link"
}
