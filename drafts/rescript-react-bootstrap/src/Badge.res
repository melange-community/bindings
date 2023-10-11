open Types

@module("react-bootstrap") @react.component
external make: (
  ~_as: string=?,
  ~bg: variant=?,
  ~pill: bool=?,
  ~text: variant=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Badge"
