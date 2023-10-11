@module("react-bootstrap") @react.component
external make: (
  ~_as: string=?,
  ~hasValidation: bool=?,
  ~size: [#sm | #lg]=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "InputGroup"
