type backdrop = Bool(bool) | Static([#static])
type fullscreen = [#"sm-down" | #"md-down" | #"lg-down" | #"xl-down" | #"xxl-down"]
type size = [#sm | #lg | #xl]

@module("react-bootstrap") @react.component
external make: (
  ~\"aria-labelledby": string=?,
  ~animation: bool=?,
  ~autoFocus: bool=?,
  ~backdrop: backdrop=?,
  ~backdropClassName: string=?,
  ~centered: bool=?,
  ~container: Types.reactNode=?,
  ~contentClassName: string=?,
  ~dialogAs: React.element=?,
  ~dialogClassName: string=?,
  ~enforceFocus: bool=?,
  ~fullscreen: fullscreen=?,
  ~keyboard: bool=?,
  ~manager: {.}=?,
  ~onEnter: unit => unit=?,
  ~onEntered: unit => unit=?,
  ~onEntering: unit => unit=?,
  ~onEscapeKeyDown: unit => unit=?,
  ~onExit: unit => unit=?,
  ~onExited: unit => unit=?,
  ~onExiting: unit => unit=?,
  ~onHide: unit => unit=?,
  ~onShow: unit => unit=?,
  ~restoreFocus: bool=?,
  ~restoreFocusOptions: {.}=?,
  ~scrollable: bool=?,
  ~show: bool=?,
  ~size: size=?,
  ~classname: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Modal"

module Dialog = {
  @module("react-bootstrap") @scope("Modal") @react.component
  external make: (
    ~centered: bool=?,
    ~contentClassName: string=?,
    ~fullscreen: fullscreen=?,
    ~size: size=?,
    ~scrollable: bool=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Dialog"
}

module Header = {
  @module("react-bootstrap") @scope("Modal") @react.component
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
  @module("react-bootstrap") @scope("Modal") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Title"
}

module Body = {
  @module("react-bootstrap") @scope("Modal") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Body"
}

module Footer = {
  @module("react-bootstrap") @scope("Modal") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Footer"
}
