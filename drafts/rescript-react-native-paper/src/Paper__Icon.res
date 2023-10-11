type t

external name: string => t = "%identity"
external render: ({"color": string, "size": float, "direction": string} => React.element) => t =
  "%identity"
