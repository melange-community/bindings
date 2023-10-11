type animation = [#glow | #wave]
type size = [#xs | #sm | #lg]

@module("react-bootstrap") @react.component
external make: (
  ~animation: animation=?,
  ~bg: Types.variant=?,
  ~size: size=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Placeholder"

module Button = {
  @module("react-bootstrap") @scope("Placeholder") @react.component
  external make: (
    ~animation: animation=?,
    ~size: size=?,
    ~variant: Types.variant=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Button"
}
