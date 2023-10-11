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

let make = (g: Graph.t): t => {
  let g' = Graph.copy(g);

  makeRaw(g');

  let attrs = Graph.graph(g');
  let width = attrs##width > 0 ? attrs##width : 0;
  let height = attrs##height > 0 ? attrs##height : 0;

  {graph: g', width, height};
};

let size = (layout: t): (int, int) => (layout.width, layout.height);

let nodeCoords = (layout: t, v: Node.t): option((int, int)) => {
  switch (Graph.node(layout.graph, v)) {
  | None => None
  | Some(attrs) => Node.coords(attrs)
  };
};

/* let edge = (layout: t, e: Edge.t): option(Edge.attrs) => { */
/*   Graph.edge(layout.graph, e); */
/* }; */
