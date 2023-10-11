type placement = [#start | #end | #top | #bottom]

@module("react-bootstrap") @react.component
external make: (
  ~\"aria-labelledby": string=?,
  ~autoFocus: bool=?,
  ~backdrop: bool=?,
  ~backdropClassName: string=?,
  ~container: React.element=?,
  ~enforceFocus: bool=?,
  ~keyboard: bool=?,
  ~onEnter: unit => unit=?,
  ~onEntering: unit => unit=?,
  ~onEscapeKeyDown: unit => unit=?,
  ~onExit: unit => unit=?,
  ~onExited: unit => unit=?,
  ~onExiting: unit => unit=?,
  ~onHide: unit => unit=?,
  ~onShow: unit => unit=?,
  ~placement: placement=?,
  ~restoreFocus: bool=?,
  ~restoreFocusOptions: {.}=?,
  ~scrool: bool=?,
  ~show: bool=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Offcanvas"

module Header = {
  @module("react-bootstrap") @scope("Offcanvas") @react.component
  external make: (
    ~closeButton: bool=?,
    ~closeLabel: string=?,
    ~closeVariant: [#white]=?,
    ~onHide: unit => unit=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Header"
}

module Title = {
  @module("react-bootstrap") @scope("Offcanvas") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Title"
}

module Body = {
  @module("react-bootstrap") @scope("Offcanvas") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Body"
}
