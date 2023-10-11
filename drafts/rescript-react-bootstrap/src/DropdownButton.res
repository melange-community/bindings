open Types

@module("react-bootstrap") @react.component
external make: (
  ~align: [#start | #end]=?,
  ~disabled: bool=?,
  ~href: string=?,
  ~id: string=?,
  ~menuRole: string=?,
  ~menuVariant: [#dark]=?,
  ~onClick: ReactEvent.Form.t => unit=?,
  ~renderMenuOnMount: bool=?,
  ~rootCloseEvent: string=?,
  ~size: string=?,
  ~title: string,
  ~variant: variant=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "DropdownButton"
