/**
  Represents the expected value from a shortest path algorithm.

  The [distance] holds the sum of the weights for the shortest path from the
  source node to the target node. If there is there is no path between source
  and target it returns [Number.POSITIVE_INFINITY].

  The [predecessor] has the node that precedes the target node. It can be used
  to walk backwards the shortest path.
  */
[@bs.deriving abstract]
type path = {
  distance: int,
  [@bs.optional]
  predecessor: Node.t,
};

/**
  Finds the connected components in a graph and returns an array of these
  components.

  {[
    Graph.components(graph);
    // [|
    //   [| "A", "B", "C", "D" |],
    //   [| "E", "F", "G" |],
    //   [| "H", "I" |]
    // |]
  ]}

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#alg-components
 */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external components: Graph.t => array(array(Node.t)) = "components";

/**
  Finds the shortest path from the given node (source) to all other nodes in
  the given graph.

  This is an implementation of Dijkstra's algorithm.


  Use [dijkstraWith] to provide a custom weight function.

  {[
    Algorithm.dijkstra(graph, "A");
    // { .
    //    "A": { "distance": 0 },
    //    "C": { "distance": 1, "predecessor": 'A' },
    //    "D": { "distance": 1, "predecessor": 'A' },
    //    "B": { "distance": 2, "predecessor": 'C' },
    //    "F": { "distance": 2, "predecessor": 'D' },
    //    "E": { "distance": 3, "predecessor": 'F' },
    // }
  ]}

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#alg-dijkstra
 */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external dijkstra: (Graph.t, Node.t) => Js.Dict.t(path) = "dijkstra";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external dijkstraWith: (Graph.t, Node.t, Edge.t => int) => Js.Dict.t(path) =
  "dijkstra";

/**
  Finds the shortest path between every reachable node.

  Use [dijkstraAllWith] to provide a custom weight function.

  {[
    Algorithm.dijkstraAll(graph);
    // { .
    //   "A": {
    //     "A": { "distance": 0 },
    //     "C": { "distance": 1, "predecessor": 'A' },
    //     "D": { "distance": 2, "predecessor": 'A' },
    //     "B": { "distance": 1, "predecessor": 'C' },
    //     "F": { "distance": 2, "predecessor": 'D' }
    //     "E": { "distance": 3, "predecessor": 'F' },
    //   },
    //   "B": {
    //     "A": { "distance": Infinity },
    //     "C": { "distance": Infinity },
    //     "D": { "distance": Infinity },
    //     "B": { "distance": 0 },
    //     "F": { "distance": Infinity }
    //     "E": { "distance": Infinity },
    //   },
    //   "C": { ... },
    //   "D": { ... },
    //   "E": { ... },
    //   "F": { ... }
    // }
  ]}

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#alg-dijkstraAll
  */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external dijkstraAll: Graph.t => Js.Dict.t(Js.Dict.t(path)) = "dijkstraAll";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external dijkstraAllWith:
  (Graph.t, Edge.t => int) => Js.Dict.t(Js.Dict.t(path)) =
  "dijkstraAll";

/**
  Returns all nodes for the given graph that are part of a cycle.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#alg-findCycles
  */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external findCycles: Graph.t => array(array(Node.t)) = "findCycles";

/**
  Finds the shortest path between every reachable node.

  This is an implementation of the Floyd-Warshall algorithm.

  Use [floydWarshallWith] to provide a custom weight function.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#alg-floydWarshall
  */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external floydWarshall: Graph.t => Js.Dict.t(Js.Dict.t(path)) =
  "floydWarshall";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external floydWarshallWith:
  (Graph.t, Edge.t => int) => Js.Dict.t(Js.Dict.t(path)) =
  "floydWarshall";

/**
  Checks if the given graph has no cycles. Use the slower [Algorithm.findCycles]
  to get the actual list of cycles.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#alg-isAcyclic
  */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external isAcyclic: Graph.t => bool = "isAcyclic";

/**
  Returns the post-order traversal starting at the given nodes.

  {[
    Algorithm.postorder(graph, [|"A"|]);
    // [| "B", "D", "E", C", "A" |]
  ]}

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#alg-postorder
  */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external postorder: (Graph.t, array(Node.t)) => array(Node.t) = "postorder";

/**
  Returns the pre-order traversal starting at the given nodes.

  {[
    Algorithm.preorder(graph, [|"A"|]);
    // [| "A", "C", "E", D", "B" |]
  ]}

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#alg-preorder
  */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external preorder: (Graph.t, array(Node.t)) => array(Node.t) = "preorder";

/**
  Returns the minimum spanning tree (as an undirected graph) for the given
  connected graph. Throws an error if the given graph is not connected.

  This is an implementation of the Prim algorithm.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#alg-prim
  */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external prim: (Graph.t, Edge.t => int) => Graph.t = "prim";

/**
  Finds all strongly connected components for the given directed graph.

  This is an implementation of the Tarjan algorithm.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#alg-tarjan
  */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external tarjan: Graph.t => array(array(Node.t)) = "tarjan";

/**
  Returns an array of nodes for the given graph such that for each edge [(u, v)]
  [u] appears before [v] in the array.

  Throws an error if the given graph has cycles.

  This is an implementation of topological sorting.

  See: https://github.com/dagrejs/graphlib/wiki/API-Reference#alg-topsort
  */
[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external toopsort: Graph.t => array(array(Node.t)) = "topsort";
