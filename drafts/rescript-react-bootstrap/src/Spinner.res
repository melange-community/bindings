open Types

@module("react-bootstrap") @react.component
external make: (
  ~animation: [#glow | #border],
  ~_as: string=?,
  ~children: React.element=?,
  ~role: string=?,
  ~size: [#sm]=?,
  ~variant: variant=?,
  ~className: string=?,
  ~bsPrefix: string=?,
) => React.element = "Spinner"
