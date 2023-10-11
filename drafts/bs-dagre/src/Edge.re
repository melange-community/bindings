[@bs.deriving abstract]
type t = {
  [@bs.optional]
  name: string,
  v: string,
  w: string,
};

[@bs.deriving abstract]
type point = {
  x: int,
  y: int,
};

let pointToString =
    (p: point, ~correction: option((int, int))=?, ()): string => {
  let (cx, cy) = Belt.Option.getWithDefault(correction, (0, 0));
  let x = xGet(p) + cx;
  let y = yGet(p) + cy;

  string_of_int(x) ++ ", " ++ string_of_int(y);
};

[@bs.deriving abstract]
type attrs = {
  [@bs.optional]
  minlen: int,
  [@bs.optional]
  weight: int,
  [@bs.optional]
  width: int,
  [@bs.optional]
  height: int,
  [@bs.optional]
  labelpos: string,
  [@bs.optional]
  labeloffset: int,
  [@bs.optional]
  points: array(point),
};
