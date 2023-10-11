@module("react-bootstrap") @react.component
external make: (
  ~role: string=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "ButtonToolbar"
