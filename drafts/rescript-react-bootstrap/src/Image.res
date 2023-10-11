@module("react-bootstrap") @react.component
external make: (
  ~src: string,
  ~fluid: bool=?,
  ~rounded: bool=?,
  ~roundedCircle: bool=?,
  ~thumbnail: bool=?,
  ~className: string=?,
  ~bsPrefix: string=?,
) => React.element = "Image"
