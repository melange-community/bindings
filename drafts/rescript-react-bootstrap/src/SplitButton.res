open Types

@module("react-bootstrap") @react.component
external make: (
  ~align: [#start | #end]=?,
  ~disabled: bool=?,
  ~href: string=?,
  ~id: string,
  ~menuRole: string=?,
  ~onClick: ReactEvent.Form.t => unit=?,
  ~rootCloseEvent: string=?,
  ~size: size=?,
  ~target: string=?,
  ~title: string,
  ~toggleLabel: string=?,
  ~_type: string=?,
  ~variant: variant=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "SplitButton"
