/**
  Opaque type to represent the graph object in JS land
 */
type t;

module Attrs: {
  type t = {
    rankdir: Rank.Dir.t,
    align: Rank.Align.t,
    nodesep: int,
    edgesep: int,
    ranksep: int,
    marginx: int,
    marginy: int,
    acyclicer: Acyclicer.t,
    ranker: Rank.Strategy.t,
  };

  /**
    See https://github.com/dagrejs/dagre/wiki#configuring-the-layout

    Note that [align] defaults to [UpLeft] instead of [undefined].
   */
  let make:
    (
      ~rankdir: Rank.Dir.t=?,
      ~align: Rank.Align.t=?,
      ~nodesep: int=?,
      ~edgesep: int=?,
      ~ranksep: int=?,
      ~marginx: int=?,
      ~marginy: int=?,
      ~acyclicer: Acyclicer.t=?,
      ~ranker: Rank.Strategy.t=?,
      unit
    ) =>
    t;

  let toDict:
    t =>
    {
      .
      "acyclicer": option(string),
      "align": string,
      "edgesep": int,
      "marginx": int,
      "marginy": int,
      "nodesep": int,
      "rankdir": string,
      "ranker": string,
      "ranksep": int,
    };
};

[@bs.deriving abstract]
type config = {
  directed: bool,
  compound: bool,
  multigraph: bool,
};

/**
  Creates a graph with the given config. It's recommended that you use the
  [Graph.make] function instead.
 */
[@bs.new] [@bs.module "dagre"] [@bs.scope "graphlib"]
external makeWith: config => t = "Graph";

/**
  Sets the graph attributes to the given graph. Use [Graph.setAttrs]
  instead.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#setGraph
 */
[@bs.send]
external setGraph: (t, Js.t('a)) => unit = "setGraph";

/**
  Returns the graph attributes from the given graph. Use [Graph.attrs]
  instead.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#graph
 */
[@bs.send]
external graph: t => Js.t('a) = "graph";

/**
  Adds a node with its layout attributes to the graph.

  Note that the JavaScript version makes the attributes (i.e. [label] in dagre
  parlance) optional. This interface uses two functions: [setNode] and
  [setNodeWith]. If you use the former, make sure the graph has a default set
  of attributes for new nodes with [setDefaultNodeAttrs].

  {[
    let g = Graph.make();

    Graph.setNodeWith(
      g,
      "furelise",
      Node.attrs(~label="Für Elise", ~width=100, ~height=80, ())
    );
  ]}

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#setNode
 */
[@bs.send]
external setNodeWith: (t, Node.t, Node.attrs) => unit = "setNode";
[@bs.send] external setNode: (t, Node.t) => unit = "setNode";

/**
  Returns the attributes for the given node. Returns [None] when the node
  does not exist.

  {[
    let g = Graph.make();
    let nodeAttrs = Node.attrs(~label="Für Elise", ~width=100, ~height=80, ());
    Graph.setNodeWith(g, "furelise", nodeAttrs);

    Graph.node(g, "furelise") == Some(nodeAttrs);
  ]}

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#node
 */
[@bs.send] [@bs.return nullable]
external node: (t, Node.t) => option(Node.attrs) = "node";

/**
  Checks if the graph is directed.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#isDirected
 */
[@bs.send]
external isDirected: t => bool = "isDirected";

/**
  Checks if the graph allows edges to be labelled.

  Note that dagre uses "label" to refer to data associated with graph, nodes
  and edges and "name" for an edge label.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#isMultigraph
 */
[@bs.send]
external isMultigraph: t => bool = "isMultigraph";
[@bs.send] external isLabelled: t => bool = "isMultigraph";

/**
  Checks if the graph allows for subgraphs.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#isCompound
 */
[@bs.send]
external isCompound: t => bool = "isCompound";

/**
  Returns the number of nodes in the graph.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#nodeCount
 */
[@bs.send]
external nodeCount: t => int = "nodeCount";

/**
  Returns the number of edges in the graph.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#edgeCount
 */
[@bs.send]
external edgeCount: t => int = "edgeCount";

/**
  Sets the default attributes for new nodes.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#setDefaultNodeLabel
 */
[@bs.send]
external setDefaultNodeLabel: (t, unit => Js.t('a)) => unit =
  "setDefaultNodeLabel";
[@bs.send]
external setDefaultNodeAttrs: (t, unit => Js.t('a)) => unit =
  "setDefaultNodeLabel";

/**
  Sets the default attributes for new nodes.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#setDefaultNodeLabel
 */
[@bs.send]
external setDefaultEdgeLabel: (t, unit => Js.t('a)) => unit =
  "setDefaultEdgeLabel";
[@bs.send]
external setDefaultEdgeAttrs: (t, unit => Js.t('a)) => unit =
  "setDefaultEdgeLabel";

/**
  Returns the nodes in the graph. Use [Graph.node] to get the node
  attributes.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#nodes
 */
[@bs.send]
external nodes: t => array(Node.t) = "nodes";

/**
  Returns the edges in the graph. Use [Graph.edge] to get the edge
  attributes.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#edges
 */
[@bs.send]
external edges: t => array(Edge.t) = "edges";

/**
  Returns the source nodes in the graph (i.e. nodes with no incoming edges).

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#sources
 */
[@bs.send]
external sources: t => array(Node.t) = "sources";

/**
  Returns the sink nodes in the graph (i.e. nodes with no outgoing edges).

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#sinks
 */
[@bs.send]
external sinks: t => array(Node.t) = "sinks";

/**
  Checks if the node exists in the graph.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#hasNode
 */
[@bs.send]
external hasNode: (t, Node.t) => bool = "hasNode";

/**
  Removes the given node, its attributes, and incident edges. Does nothing
  if the nodes does not exist.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#removeNode
 */
[@bs.send]
external removeNode: (t, Node.t) => unit = "removeNode";

/**
  Returns the predecessor nodes for the given node. Returns [None] if the
  node does not exist.

  Note that undirected graphs have undefined behaviour. Use [Graph.neighbors]
  instead.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#predecessors
 */
[@bs.send] [@bs.return nullable]
external predecessors: (t, Node.t) => option(array(Node.t)) = "predecessors";

/**
  Returns the successor nodes for the given node. Returns [None] if the
  node does not exist.

  Note that undirected graphs have undefined behaviour. Use [Graph.neighbors]
  instead.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#successors
 */
[@bs.send] [@bs.return nullable]
external successors: (t, Node.t) => option(array(Node.t)) = "successors";

/**
  Returns the nodes connected to the given node. Returns [None] if the
  node does not exist.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#successors
 */
[@bs.send] [@bs.return nullable]
external neighbors: (t, Node.t) => option(array(Node.t)) = "neighbors";

/**
  Returns the incoming edges for the given node. When [filter] is provided,
  it returns the subset of incoming edges matching the filter node. Returns
  [None] if the node does not exist.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#inEdges
 */
[@bs.send] [@bs.return nullable]
external inEdges:
  (t, Node.t, ~filter: Node.t=?, unit) => option(array(Edge.t)) =
  "inEdges";

/**
  Returns the outgoing edges for the given node. When [filter] is provided,
  it returns the subset of outgoing edges matching the filter node. Returns
  [None] if the node does not exist.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#outEdges
 */
[@bs.send] [@bs.return nullable]
external outEdges:
  (t, Node.t, ~filter: Node.t=?, unit) => option(array(Edge.t)) =
  "outEdges";

/**
  Returns the edges for the given node. When [filter] is provided, it
  returns the subset of edges matching the filter node. Returns [None] if
  the node does not exist.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#nodeEdges
 */
[@bs.send] [@bs.return nullable]
external nodeEdges:
  (t, Node.t, ~filter: Node.t=?, unit) => option(array(Edge.t)) =
  "nodeEdges";

/**
  Returns the parent node for the given node. Returns [None] if the node
  does not exist or if it has no parent.

  Note that this function is for compound graphs, otherwise no node will
  have a parent.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#parent
 */
[@bs.send] [@bs.return nullable]
external parent: (t, Node.t) => option(Node.t) = "parent";

/**
  Sets the parent for the given node.

  Note that it throws an exception if the graph is not compound.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#setParent
 */
[@bs.send]
external setParent: (t, Node.t, Node.t) => unit = "setParent";

/**
  Removes the parent for the given node.

  Note that this is equivalent to use the [g.setParent] method with a single
  argument in JavaScript.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#setParent
 */
[@bs.send]
external removeParent: (t, Node.t) => unit = "setParent";

/**
  Returns the children nodes for the given node. Returns [None] if the node
  does not exist.

  Note that this function is for compound graphs, otherwise no node will
  have children.

  Prefer [Graph.children] to get [None] instead of an empty array when the
  graph is not compound.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#children
 */
[@bs.send] [@bs.return nullable]
external childrenRaw: (t, Node.t) => option(array(Node.t)) = "children";

/**
  Returns the children for the given node. When the graph is not compound,
  returns [None]. This is aligns with the [Graph.parent] behaviour.

  Use [Graph.childrenRaw] if you need the original behaviour.
 */
let children: (t, Node.t) => option(array(Node.t));

/**
  Checks if the given edge exists.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#hasEdge
 */
[@bs.send]
external hasEdge: (t, Edge.t) => bool = "hasEdge";

/**
  Adds an edge with its layout attributes to the graph.

  Note that the JavaScript version makes the attributes (i.e. [label] in dagre
  parlance) optional. This interface uses two functions: [setEdge] and
  [setEdgeWith]. If you use the former, make sure the graph has a default set
  of attributes for new nodes with [setDefaultNodeAttrs].

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#setEdge
 */
[@bs.send]
external setEdgeWith: (t, Edge.t, Edge.attrs) => unit = "setEdge";
[@bs.send] external setEdge: (t, Edge.t) => unit = "setEdge";

/**
  Returns the layout attributes for the given edge. Returns [None] if the
  edge does not exist.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#edge
 */
[@bs.send] [@bs.return nullable]
external edge: (t, Edge.t) => option(Edge.attrs) = "edge";

/**
  Removes the given edge from the graph.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#removeEdge
 */
[@bs.send]
external removeEdge: (t, Edge.t) => unit = "removeEdge";

/**
  Returns a filtered copy of the graph. The filter is based on the node
  layout attributes.

  See: https://github.com/dagrejs/graphlib/issues/107
 */
[@bs.send]
external filterNodes: (t, Js.t('a) => bool) => t = "filterNodes";

/**
  Serializes the given graph to a dictionary-like data structure.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#json-write
  */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "json")]
external serialize: t => Js.t('a) = "write";

/**
  Deserializes the given dictionary-like data structure into a [Graph.t].

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#json-read
  */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "json")]
external deserialize: Js.t('a) => t = "read";

/**
  Returns the graph attributes. This is a less confusing name than the
  original [Graph.graph].
 */
let attrs: t => Attrs.t;

/**
  Sets the graph layout attributes. This is a less confusing name than the
  original [Graph.setGraph].
 */
let setAttrs: (t, Attrs.t) => unit;

/**
  Creates a new graph with the given attributes. It defaults to a directed
  non-compound non-labelled graph.

  {[
    let attrs = Graph.Attrs.make(~rankdir=Rank.Dir.LeftRight, ());
    let graph = Graph.make(~attrs, ());

    Graph.isDirected(graph) == true;
    Graph.isCompound(graph) == false;
    Graph.isLabelled(graph) == false;
    Graph.attrs(graph) == attrs;
  ]}

 */
let make:
  (
    ~directed: bool=?,
    ~compound: bool=?,
    ~multigraph: bool=?,
    ~attrs: Attrs.t=?,
    unit
  ) =>
  t;

/**
  Makes a deep copy of the given graph.
 */
let copy: t => t;
