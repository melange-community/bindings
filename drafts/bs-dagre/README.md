# bs-dagre

[BuckleScript](https://bucklescript.github.io) bindings for [dagre](https://github.com/dagrejs/dagre).


## Status

* [x] Bindings for [graphlib](https://github.com/dagrejs/graphlib) public interface.
* [x] Bindings for [dagre](https://github.com/dagrejs/dagre) public interface.


## Naming and organisation

Although most names come straight from the original library, there are a few
changes to adapt to Reason and a few aliases for my own benefit.

* Bindings for `graphlib` ara under the [`Dagre.Graph`](src/Graph.rei)
  module.
* Bindings for `dagre` are under the [`Dagre.Layout`](src/Layout.re) module.
* `graphlib` uses "label" to refer to data associated with graph, nodes and
  edges. `bs-dagre` uses "attributes" instead. For example, instead of
  `setDefaultNodeLabel` you have `setDefaultNodeAttrs`.


## Usage

The steps to compute a graph layout are: create a graph, add nodes and edges
and finally create a layout.

### Crate a graph

```reason
open Dagre;

let graph = Graph.make();
Graph.setDefaultEdgeAttrs(graph, () => {"minlen": 2});
```

The snippet above creates a graph with default attributes,
if you need to tweak them, use [`Graph.Attrs.make`](src/Graph.re#L16).

### Add nodes and edges

```reason
Graph.setNodeWith(graph, "a", Node.attrs(~label="first", ~width=20, ~height=20), ());
Graph.setNodeWith(graph, "b", Node.attrs(~label="second", ~width=20, ~height=20), ());

Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
```

### Create a layout

```reason
let layout = Layout.make(graph);

// Use the layout to render the graph.
```

Check the [`examples`](examples) for more.


## License

bs-dagre is licensed under the terms of the MIT License. See the LICENSE file
for details.
