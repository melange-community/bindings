open Types

type pause = Hover([#hover]) | False(bool)

@module("react-bootstrap") @react.component
external make: (
  ~activeIndex: int=?,
  ~_as: string=?,
  ~controls: bool=?,
  ~fade: bool=?,
  ~indicatorLabels: array<'a>=?,
  ~indicators: bool=?,
  ~interval: bool=?,
  ~keyboard: bool=?,
  ~nextIcon: reactNode=?,
  ~nextLabel: string=?,
  ~onSelect: (~eventKey: int, ~event: option<ReactEvent.Selection.t>) => unit,
  ~onSlid: (~eventKey: int, ~direction: [#start | #end]) => unit,
  ~onSlide: (~eventKey: int, ~direction: [#start | #end]) => unit,
  ~pause: [#hover],
  ~prevIcon: reactNode=?,
  ~prevLabel: string=?,
  ~slide: bool=?,
  ~touch: bool=?,
  ~variant: [#dark]=?,
  ~wrap: bool=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Carousel"

module Item = {
  @module("react-bootstrap") @scope("Carousel") @react.component
  external make: (
    ~_as: string=?,
    ~interval: int=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Item"
}

module Caption = {
  @module("react-bootstrap") @scope("Carousel") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Caption"
}
