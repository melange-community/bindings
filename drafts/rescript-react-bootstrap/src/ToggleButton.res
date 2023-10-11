type value<'a> = Text(string) | Int(int) | Float(float) | Arr(array<'a>)

@module("react-bootstrap") @react.component
external make: (
  ~checked: bool=?,
  ~disabled: bool=?,
  ~id: string,
  ~inputRef: ReactDOM.Ref.t=?,
  ~name: string=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~_type: [#checkbox | #radio]=?,
  ~value: value<'a>,
  ~bsPrefix: string=?,
  ~className: string=?,
  ~children: React.element,
) => React.element = "ToggleButton"
