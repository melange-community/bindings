@module("react-bootstrap") @react.component
external make: (
  ~appear: bool=?,
  ~children: React.element,
  ~_in: bool=?,
  ~mountOnEnter: bool=?,
  ~onEnter: unit => unit=?,
  ~onEntered: unit => unit=?,
  ~onEntering: unit => unit=?,
  ~onExit: unit => unit=?,
  ~onExited: unit => unit=?,
  ~onExiting: unit => unit=?,
  ~timeout: int=?,
  ~unmountOnExit: bool=?,
  ~className: string=?,
) => React.element = "Fade"
