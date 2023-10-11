type responsive = Bool(bool) | Size([#xs | #sm | #md | #lg | #xl | #xxl])

@module("react-bootstrap") @react.component
external make: (
  ~bordered: bool=?,
  ~borderless: bool=?,
  ~hover: bool=?,
  ~responsive: responsive=?,
  ~size: string=?,
  ~striped: bool=?,
  ~variant: [#light | #dark]=?,
  ~className: string=?,
  ~children: React.element,
  ~bsPrefix: string=?,
) => React.element = "Table"
