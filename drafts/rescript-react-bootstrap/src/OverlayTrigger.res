open Types

type triggers = [#hover | #click | #focus]
type trigger = One(triggers) | Many(array<triggers>)

@module("react-bootstrap") @react.component
external make: (
  ~children: React.element,
  ~defaultShow: bool=?,
  ~delay: int=?,
  ~flip: bool=?,
  ~onHide: unit => unit=?,
  ~onToggle: unit => unit=?,
  ~overlay: React.element=?,
  ~placement: placement=?,
  ~popperConfig: {.}=?,
  ~show: bool=?,
  ~target: reactNode=?,
  ~trigger: trigger=?,
  ~className: string=?,
) => React.element = "OverlayTrigger"
