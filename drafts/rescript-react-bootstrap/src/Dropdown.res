open Types

type autoClose = Bool(bool) | Side([#outside | #inside])
type drop = [#up | #start | #end | #down]
type focus = Bool(bool) | Keyboard([#keyboard])

type toggleMetadata = {source: [#select | #click | #rootClose | #keydown]}

@module("react-bootstrap") @react.component
external make: (
  ~align: [#start | #end]=?,
  ~_as: string=?,
  ~autoClose: autoClose=?,
  ~drop: drop=?,
  ~flip: bool=?,
  ~focusFirstItemOnShow: focus=?,
  ~navbar: bool=?,
  ~onSelect: (~eventKey: string, ~event: ReactEvent.Selection.t) => unit=?,
  ~onToggle: (~isOpen: bool, ~event: ReactEvent.Synthetic.t, ~metadata: toggleMetadata) => unit=?,
  ~show: bool=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Dropdown"

module Toggle = {
  @module("react-bootstrap") @scope("Dropdown") @react.component
  external make: (
    ~_as: string=?,
    ~childBsPrefix: string=?,
    ~id: string=?,
    ~split: bool=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Toggle"
}

module Menu = {
  @module("react-bootstrap") @scope("Dropdown") @react.component
  external make: (
    ~align: [#start | #end]=?,
    ~_as: string=?,
    ~flip: bool=?,
    ~onSelect: (~eventKey: string, ~event: ReactEvent.Selection.t) => unit=?,
    ~popperConfig: {.}=?,
    ~renderOnMount: bool=?,
    ~rootCloseEvent: [#click | #mousedown]=?,
    ~show: bool=?,
    ~variant: variant=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Menu"
}

module Item = {
  @module("react-bootstrap") @scope("Dropdown") @react.component
  external make: (
    ~active: bool=?,
    ~_as: string=?,
    ~disabled: bool=?,
    ~eventKey: string=?,
    ~href: string=?,
    ~onClick: ReactEvent.Mouse.t,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Item"
}

module Header = {
  @module("react-bootstrap") @scope("Dropdown") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Header"
}

module Divider = {
  @module("react-bootstrap") @scope("Dropdown") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Divider"
}
