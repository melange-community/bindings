open Types

type arrowProps<'a> = {ref: React.ref<'a>, style: {.}}

@module("react-bootstrap") @react.component
external make: (
  ~arrowProps: arrowProps<'a>=?,
  ~body: bool=?,
  ~id: string,
  ~placement: placement=?,
  ~popper: {.}=?,
  ~show: bool=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Popover"

module Body = {
  @module("react-bootstrap") @scope("Popover") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Body"
}

module Header = {
  @module("react-bootstrap") @scope("Popover") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Header"
}
