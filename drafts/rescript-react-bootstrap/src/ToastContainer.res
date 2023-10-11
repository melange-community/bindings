type position = [
  | #"top-start"
  | #"top-center"
  | #"top-end"
  | #"middle-start"
  | #"middle-center"
  | #"middle-end"
  | #"bottom-start"
  | #"bottom-center"
  | #"bottom-end"
]

@module("react-bootstrap") @react.component
external make: (
  ~position: position=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "ToastContainer"
