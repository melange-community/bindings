type t = string;

[@bs.deriving abstract]
type attrs = {
  [@bs.optional]
  x: int,
  [@bs.optional]
  y: int,
  label: string,
  width: int,
  height: int,
};

let coords = (attrs): option((int, int)) => {
  switch (xGet(attrs), yGet(attrs)) {
  | (Some(x), Some(y)) => Some((x, y))
  | _ => None
  };
};
