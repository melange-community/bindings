open Types

@module("react-bootstrap") @react.component
external make: (
  ~_as: string=?,
  ~role: string=?,
  ~size: size=?,
  ~vertical: bool=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "ButtonGroup"
