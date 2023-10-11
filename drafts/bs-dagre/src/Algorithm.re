[@bs.deriving abstract]
type path = {
  distance: int,
  [@bs.optional]
  predecessor: Node.t,
};

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external components: Graph.t => array(array(Node.t)) = "components";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external dijkstra: (Graph.t, Node.t) => Js.Dict.t(path) = "dijkstra";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external dijkstraWith: (Graph.t, Node.t, Edge.t => int) => Js.Dict.t(path) =
  "dijkstra";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external dijkstraAll: Graph.t => Js.Dict.t(Js.Dict.t(path)) = "dijkstraAll";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external dijkstraAllWith:
  (Graph.t, Edge.t => int) => Js.Dict.t(Js.Dict.t(path)) =
  "dijkstraAll";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external findCycles: Graph.t => array(array(Node.t)) = "findCycles";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external floydWarshall: Graph.t => Js.Dict.t(Js.Dict.t(path)) =
  "floydWarshall";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external floydWarshallWith:
  (Graph.t, Edge.t => int) => Js.Dict.t(Js.Dict.t(path)) =
  "floydWarshall";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external isAcyclic: Graph.t => bool = "isAcyclic";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external postorder: (Graph.t, array(Node.t)) => array(Node.t) = "postorder";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external preorder: (Graph.t, array(Node.t)) => array(Node.t) = "preorder";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external prim: (Graph.t, Edge.t => int) => Graph.t = "prim";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external tarjan: Graph.t => array(array(Node.t)) = "tarjan";

[@bs.val] [@bs.module "dagre"] [@bs.scope ("graphlib", "alg")]
external toopsort: Graph.t => array(array(Node.t)) = "topsort";
