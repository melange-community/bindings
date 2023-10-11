@module("react-bootstrap") @react.component
external make: (
  ~active: bool=?,
  ~disabled: bool=?,
  ~id: string=?,
  ~menuRole: string=?,
  ~menuVariant: [#dark]=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~renderMenuOnMount: bool=?,
  ~rootCloseEvent: string=?,
  ~title: string,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "NavDropdown"
