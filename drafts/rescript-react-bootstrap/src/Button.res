open Types

type buttonType = [#button | #reset | #submit | #null]

@module("react-bootstrap") @react.component
external make: (
  ~active: bool=?,
  ~_as: string=?,
  ~className: string=?,
  ~disabled: bool=?,
  ~href: string=?,
  ~size: size=?,
  ~_type: buttonType=?,
  ~variant: variant=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Button"
