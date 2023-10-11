@module("react-bootstrap") @react.component
external make: (
  ~_as: string=?,
  ~xs: int=?,
  ~sm: int=?,
  ~md: int=?,
  ~lg: int=?,
  ~xl: int=?,
  ~xxl: int=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Row"
