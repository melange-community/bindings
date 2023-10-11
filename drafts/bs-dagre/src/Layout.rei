type t = {
  graph: Graph.t,
  width: int,
  height: int,
};

[@bs.deriving abstract]
type point = {
  x: int,
  y: int,
};

[@bs.val] [@bs.module "dagre"] external makeRaw: Graph.t => unit = "layout";

let make: Graph.t => t;

let size: t => (int, int);

let nodeCoords: (t, Node.t) => option((int, int));
