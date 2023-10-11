@module("react-bootstrap") @react.component
external make: (
  ~aspectRatio: float=?,
  ~classNmae: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Ratio"
