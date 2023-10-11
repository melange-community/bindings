module Portal = {
  @module("@rmwc/base") @react.component
  external make: unit => React.element = "Portal"
}

module Button = {
  @module("@rmwc/button") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~danger: option<bool>=?,
    ~dense: option<bool>=?,
    ~disabled: option<bool>=?,
    ~icon: option<React.element>=?,
    ~label: option<string>=?,
    ~onClick: option<ReactEvent.Mouse.t => unit>=?,
    ~outlined: option<bool>=?,
    ~raised: option<bool>=?,
    ~ripple: option<Types.Button.rippleProp>=?,
    ~style: option<ReactDOM.style>=?,
    ~trailingIcon: option<React.element>=?,
    ~unelevated: option<bool>=?,
  ) => React.element = "Button"
}

module Elevation = {
  @module("@rmwc/elevation") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~z: option<int>=?,
    ~transition: option<bool>=?,
    ~style: option<ReactDOM.style>=?,
    ~onClick: option<ReactEvent.Mouse.t => unit>=?,
    ~onDoubleClick: option<ReactEvent.Mouse.t => unit>=?,
  ) => React.element = "Elevation"
}

module IconButton = {
  @module("@rmwc/icon-button") @react.component
  external make: (
    ~checked: option<bool>=?,
    ~disabled: option<bool>=?,
    ~icon: string,
    ~label: option<string>=?,
    ~onClick: option<ReactEvent.Mouse.t => unit>=?,
    ~ripple: option<Types.Button.rippleProp>=?,
  ) => React.element = "IconButton"
}

module Card = {
  @module("@rmwc/card") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~outlined: option<bool>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "Card"
}

module CardPrimaryAction = {
  @module("@rmwc/card") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "CardPrimaryAction"
}

module CardMedia = {
  @module("@rmwc/card") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~sixteenByNine: option<bool>=?,
    ~style: option<ReactDOM.style>=?,
    ~square: option<bool>=?,
  ) => React.element = "CardMedia"
}

module CardMediaContent = {
  @module("@rmwc/card") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "CardMediaContent"
}

module CardActions = {
  @module("@rmwc/card") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~fullBleed: option<bool>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "CardActions"
}

module CardActionButtons = {
  @module("@rmwc/card") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "CardActionButtons"
}

module CardActionIcons = {
  @module("@rmwc/card") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "CardActionIcons"
}

module CardActionIcon = {
  @module("@rmwc/card") @react.component
  external make: (
    ~checked: option<bool>=?,
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~disabled: option<bool>=?,
    ~icon: option<React.element>=?,
    ~label: option<string>=?,
    ~onClick: option<ReactEvent.Mouse.t => unit>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "CardActionIcon"
}

module CardActionButton = {
  @module("@rmwc/card") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~danger: option<bool>=?,
    ~dense: option<bool>=?,
    ~disabled: option<bool>=?,
    ~icon: option<React.element>=?,
    ~label: option<string>=?,
    ~onClick: option<unit => unit>=?,
    ~outlined: option<bool>=?,
    ~raised: option<bool>=?,
    ~style: option<ReactDOM.style>=?,
    ~trailingIcon: option<React.element>=?,
    ~unelevated: option<bool>=?,
  ) => React.element = "CardActionButton"
}

module Typography = {
  @module("@rmwc/typography") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~use: string,
    ~style: option<ReactDOM.style>=?,
    ~tag: option<string>=?,
    ~theme: option<string>=?,
  ) => React.element = "Typography"
}

module Dialog = {
  @module("@rmwc/dialog") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~onClose: option<Types.Dialog.onClose => unit>=?,
    ~onClosed: option<Types.Dialog.onClose => unit>=?,
    ~onOpen: option<unit => unit>=?,
    ~onOpened: option<unit => unit>=?,
    ~\"open": option<bool>=?,
    ~preventOutsideDismiss: option<bool>=?,
    ~renderToPortal: option<bool>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "Dialog"
}

module DialogTitle = {
  @module("@rmwc/dialog") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "DialogTitle"
}

module DialogContent = {
  @module("@rmwc/dialog") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "DialogContent"
}

module DialogActions = {
  @module("@rmwc/dialog") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "DialogActions"
}

module DialogButton = {
  @module("@rmwc/dialog") @react.component
  external make: (
    ~action: option<string>=?,
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~danger: option<bool>=?,
    ~dense: option<bool>=?,
    ~disabled: option<bool>=?,
    ~icon: option<React.element>=?,
    ~isDefaultAction: option<bool>=?,
    ~label: option<string>=?,
    ~onClick: option<ReactEvent.Mouse.t => unit>=?,
    ~outlined: option<bool>=?,
    ~raised: option<bool>=?,
    ~style: option<ReactDOM.style>=?,
    ~trailingIcon: option<React.element>=?,
    ~unelevated: option<bool>=?,
  ) => React.element = "DialogButton"
}

module Avatar = {
  @module("@rmwc/avatar") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~contain: option<bool>=?,
    ~interactive: option<bool>=?,
    ~name: option<string>=?,
    ~size: option<string>=?,
    ~style: option<ReactDOM.style>=?,
    ~square: option<bool>=?,
    ~src: option<string>=?,
  ) => React.element = "Avatar"
}

module AvatarGroup = {
  @module("@rmwc/avatar") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~dense: option<bool>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "AvatarGroup"
}

module AvatarCount = {
  @module("@rmwc/avatar") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~interactive: option<bool>=?,
    ~overflow: option<bool>=?,
    ~size: option<string>=?,
    ~style: option<ReactDOM.style>=?,
    ~square: option<bool>=?,
    ~value: int,
  ) => React.element = "AvatarCount"
}

module Icon = {
  @module("@rmwc/icon") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~className: option<string>=?,
    ~icon: string,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "Icon"
}

module LinearProgress = {
  @module("@rmwc/linear-progress") @react.component
  external make: (
    ~className: option<string>=?,
    ~buffer: option<float>=?,
    ~closed: option<bool>=?,
    ~progress: option<float>=?,
    ~reversed: option<bool>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "LinearProgress"
}

module CircularProgress = {
  @module("@rmwc/circular-progress") @react.component
  external make: (
    ~className: option<string>=?,
    ~min: option<float>=?,
    ~max: option<float>=?,
    ~progress: option<float>=?,
    ~size: option<string>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "CircularProgress"
}

module Tooltip = {
  @module("@rmwc/tooltip") @react.component
  external make: (
    ~activateOn: option<array<string>>=?,
    ~align: option<string>=?,
    ~children: React.element,
    ~className: option<string>=?,
    ~content: React.element,
    ~enterDelay: option<float>=?,
    ~leaveDelay: option<float>=?,
    ~\"open": option<bool>=?,
    ~showArrow: option<bool>=?,
    ~style: option<ReactDOM.style>=?,
  ) => React.element = "Tooltip"
}

module TextField = {
  @module("@rmwc/textfield") @react.component
  external make: (
    ~align: option<string>=?,
    ~characterCount: option<bool>=?,
    ~className: option<string>=?,
    ~disabled: option<bool>=?,
    ~floatLabel: option<bool>=?,
    ~fullwidth: option<bool>=?,
    ~helpText: option<React.element>=?,
    ~icon: option<React.element>=?,
    ~invalid: option<bool>=?,
    ~label: option<React.element>=?,
    ~onChange: option<Types.TextField.changeEvent => unit>=?,
    ~outlined: option<bool>=?,
    ~placeholder: option<string>=?,
    ~required: option<bool>=?,
    ~style: option<ReactDOM.style>=?,
    ~textarea: option<bool>=?,
    ~trailingIcon: option<React.element>=?,
    ~\"type": option<string>=?,
    ~value: option<string>=?,
  ) => React.element = "TextField"
}

module ThemeProvider = {
  @module("@rmwc/theme") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~options: option<'whatever>=?,
    ~style: option<ReactDOM.style>=?,
    ~wrap: option<bool>=?,
  ) => React.element = "ThemeProvider"
}

module Theme = {
  @module("@rmwc/theme") @react.component
  external make: (
    ~children: option<React.element>=?,
    ~use: option<array<string>>=?,
    ~wrap: option<bool>=?,
    ~tag: option<string>=?,
    ~className: option<string>=?,
  ) => React.element = "Theme"
}

module Ripple = {
  @module("@rmwc/ripple") @react.component
  external make: (
    ~accent: option<bool>,
    ~disabled: option<bool>,
    ~primary: option<bool>,
    ~surface: option<bool>,
    ~unbound: option<bool>,
  ) => React.element = "Ripple"
}
