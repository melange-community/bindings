open Types

type t

type variant = [#success | #danger | #warning | #info]

@module("react-bootstrap") @react.component
external make: (
  ~animated: bool=?,
  ~children: t=?,
  ~isChild: bool=?,
  ~label: reactNode=?,
  ~max: int=?,
  ~min: int=?,
  ~now: int=?,
  ~striped: bool=?,
  ~variant: variant=?,
  ~visuallyHidden: bool=?,
  ~className: string=?,
  ~bsPrefix: string=?,
) => React.element = "ProgressBar"
