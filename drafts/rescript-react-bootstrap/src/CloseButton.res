@module("react-bootstrap") @react.component
external make: (
  ~\"aria-label": string=?,
  ~onClick: ReactEvent.Form.t => unit=?,
  ~className: string=?,
  ~children: React.element=?,
  ~variant: [#white]=?,
) => React.element = "CloseButton"
