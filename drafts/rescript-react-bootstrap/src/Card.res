open Types

@module("react-bootstrap") @react.component
external make: (
  ~_as: string=?,
  ~bg: variant=?,
  ~body: bool=?,
  ~border: variant=?,
  ~text: variant=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Card"

module Body = {
  @module("react-bootstrap") @scope("Card") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Body"
}

module Footer = {
  @module("react-bootstrap") @scope("Card") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Footer"
}

module Header = {
  @module("react-bootstrap") @scope("Card") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Header"
}

module Img = {
  @module("react-bootstrap") @scope("Card") @react.component
  external make: (
    ~_as: string=?,
    ~src: string,
    ~variant: [#top | #bottom]=?,
    ~className: string=?,
    ~bsPrefix: string=?,
  ) => React.element = "Img"
}

module ImgOverlay = {
  @module("react-bootstrap") @scope("Card") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "ImgOverlay"
}

module Link = {
  @module("react-bootstrap") @scope("Card") @react.component
  external make: (
    ~_as: string=?,
    ~href: string,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Link"
}

module Subtitle = {
  @module("react-bootstrap") @scope("Card") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Subtitle"
}

module Text = {
  @module("react-bootstrap") @scope("Card") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Text"
}

module Title = {
  @module("react-bootstrap") @scope("Card") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Title"
}

module CardGroup = {
  @module("react-bootstrap") @scope("Card") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "CardGroup"
}

module CardColumns = {
  @module("react-bootstrap") @scope("Card") @react.component
  external make: (
    ~_as: string=?,
    ~className: string,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "CardColumns"
}
