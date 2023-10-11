open Types

@module("react-bootstrap") @react.component
external make: (
  ~container: reactNode=?,
  ~onEnter: unit => unit=?,
  ~onEntered: unit => unit=?,
  ~onEntering: unit => unit=?,
  ~onExit: unit => unit=?,
  ~onExited: unit => unit=?,
  ~onExiting: unit => unit=?,
  ~onHide: unit => unit=?,
  ~placement: placement=?,
  ~popperConfig: {.}=?,
  ~rootClose: bool=?,
  ~rootCloseEvent: [#click | #mousedown]=?,
  ~show: bool=?,
  ~target: reactNode=?,
  ~transition: React.element=?,
  ~className: string=?,
  ~children: React.element,
) => React.element = "Overlay"
