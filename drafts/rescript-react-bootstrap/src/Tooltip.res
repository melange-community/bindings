open Types

type arrowProps<'a> = {ref: React.ref<'a>, style: {.}}

@module("react-bootstrap") @react.component
external make: (
  ~arrowProps: arrowProps<'a>=?,
  ~id: string,
  ~placement: placement=?,
  ~popper: {.}=?,
  ~show: bool=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Tooltip"
