type dimension = [#height | #width]

@module("react-bootstrap") @react.component
external make: (
  ~appear: bool=?,
  ~children: React.element,
  ~dimension: dimension=?,
  ~getDimensionValue: (~dimension: dimension, ~element: Dom.htmlElement) => int=?,
  ~_in: bool=?,
  ~mountOnEnter: bool=?,
  ~onEnter: unit => unit=?,
  ~onEntered: unit => unit=?,
  ~onEntering: unit => unit=?,
  ~onExit: unit => unit=?,
  ~onExited: unit => unit=?,
  ~onExiting: unit => unit=?,
  ~role: string=?,
  ~timeout: int=?,
  ~unmountOnExit: bool=?,
  ~className: string=?,
) => React.element = "Collapse"
