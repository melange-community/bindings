open Types

type value<'a> = Value('a) | Values(array<'a>)

@module("react-bootstrap") @react.component
external make: (
  ~name: string=?,
  ~onChange: (value<'a>, ReactEvent.Form.t) => unit,
  ~size: size=?,
  ~_type: [#checkbox | #radio]=?,
  ~value: 'a,
  ~vertical: bool=?,
  ~className: string=?,
  ~children: React.element=?,
) => React.element = "ToggleButtonGroup"
