open Jest;
open Expect;

describe("Graph", () => {
  test("configure graph with default attributes", () => {
    let attrs = Graph.Attrs.make();
    let graph = Graph.make(~attrs, ());

    expect(Graph.attrs(graph)) |> toEqual(attrs);
  });

  test("make a directed graph", () => {
    let graph = Graph.make();

    expect(Graph.isDirected(graph)) |> toEqual(true);
  });

  test("make an undirected graph", () => {
    let graph = Graph.make(~directed=false, ());

    expect(Graph.isDirected(graph)) |> toEqual(false);
  });

  test("make a directed compound multigraph", () => {
    let graph = Graph.make(~compound=true, ~multigraph=true, ());

    expect((Graph.isCompound(graph), Graph.isMultigraph(graph)))
    |> toEqual((true, true));
  });

  test("A graph with a node", () => {
    let graph = Graph.make();
    let attrs = Node.attrs(~width=20, ~height=20, ~label="a", ());
    Graph.setNodeWith(graph, "a", attrs);

    expect(Graph.node(graph, "a")) |> toEqual(Some(attrs));
  });

  test("A graph without a node", () => {
    let graph = Graph.make();

    expect(Graph.node(graph, "a")) |> toEqual(None);
  });

  test("A graph with an edge", () => {
    let graph = Graph.make();
    let edge = Edge.t(~v="a", ~w="b", ());

    Graph.setEdge(graph, edge);

    expect(Graph.hasEdge(graph, edge)) |> toEqual(true);
  });

  test("A graph without an edge", () => {
    let graph = Graph.make();

    expect(Graph.hasEdge(graph, Edge.t(~v="a", ~w="b", ())))
    |> toEqual(false);
  });

  test("An edge with custom attributes", () => {
    let graph = Graph.make();
    let edge = Edge.t(~v="a", ~w="b", ());
    let attrs = Edge.attrs(~minlen=3, ());

    Graph.setEdgeWith(graph, edge, attrs);

    expect(Graph.edge(graph, edge)) |> toEqual(Some(attrs));
  });

  test("A graph with two nodes", () => {
    let graph = Graph.make();
    Graph.setNodeWith(
      graph,
      "a",
      Node.attrs(~width=20, ~height=20, ~label="first", ()),
    );
    Graph.setNodeWith(
      graph,
      "b",
      Node.attrs(~width=20, ~height=20, ~label="second", ()),
    );

    expect(Graph.nodeCount(graph)) |> toEqual(2);
  });

  test("A graph with two edges", () => {
    let graph = Graph.make();
    Graph.setEdgeWith(
      graph,
      Edge.t(~v="a", ~w="b", ()),
      Edge.attrs(~minlen=2, ()),
    );
    Graph.setEdge(graph, Edge.t(~v="b", ~w="a", ()));

    expect(Graph.edgeCount(graph)) |> toEqual(2);
  });

  test("Returns the list of node ids", () => {
    let graph = Graph.make();
    Graph.setNodeWith(
      graph,
      "a",
      Node.attrs(~width=20, ~height=20, ~label="first", ()),
    );
    Graph.setNodeWith(
      graph,
      "b",
      Node.attrs(~width=20, ~height=20, ~label="second", ()),
    );

    let expected = [|"a", "b"|];

    expect(Graph.nodes(graph)) |> toEqual(expected);
  });

  test("Returns the list of edge values", () => {
    let graph = Graph.make();
    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));

    let expected = [|
      Edge.t(~v="a", ~w="b", ()),
      Edge.t(~v="b", ~w="c", ()),
    |];

    expect(Graph.edges(graph)) |> toEqual(expected);
  });

  test("Returns the list of edge values for a multigraph", () => {
    let graph = Graph.make(~multigraph=true, ());
    let e1 = Edge.t(~name="first", ~v="a", ~w="b", ());
    let e2 = Edge.t(~name="last", ~v="b", ~w="c", ());

    Graph.setEdge(graph, e1);
    Graph.setEdge(graph, e2);

    expect(Graph.edges(graph)) |> toEqual([|e1, e2|]);
  });

  test("Returns the list of source nodes", () => {
    let graph = Graph.make();
    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));
    Graph.setEdge(graph, Edge.t(~v="d", ~w="e", ()));

    expect(Graph.sources(graph)) |> toEqual([|"a", "d"|]);
  });

  test("Returns the list of sink nodes", () => {
    let graph = Graph.make();

    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));
    Graph.setEdge(graph, Edge.t(~v="d", ~w="e", ()));

    expect(Graph.sinks(graph)) |> toEqual([|"c", "e"|]);
  });

  test("Checks if a node exists", () => {
    let graph = Graph.make();
    Graph.setNodeWith(
      graph,
      "a",
      Node.attrs(~width=20, ~height=20, ~label="x", ()),
    );
    expect((Graph.hasNode(graph, "a"), Graph.hasNode(graph, "b")))
    |> toEqual((true, false));
  });

  test("Removes a node", () => {
    let graph = Graph.make();
    Graph.setNodeWith(
      graph,
      "a",
      Node.attrs(~width=20, ~height=20, ~label="second", ()),
    );
    let before = Graph.hasNode(graph, "a");
    Graph.removeNode(graph, "a");
    let after = Graph.hasNode(graph, "a");
    expect((before, after)) |> toEqual((true, false));
  });

  test("Returns the node predecessors", () => {
    let graph = Graph.make();
    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));
    Graph.setEdge(graph, Edge.t(~v="d", ~w="e", ()));
    Graph.setEdge(graph, Edge.t(~v="a", ~w="e", ()));
    expect(Graph.predecessors(graph, "e")) |> toEqual(Some([|"d", "a"|]));
  });

  test("Returns the node successors", () => {
    let graph = Graph.make();

    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));
    Graph.setEdge(graph, Edge.t(~v="d", ~w="e", ()));
    Graph.setEdge(graph, Edge.t(~v="a", ~w="e", ()));

    expect(Graph.successors(graph, "a")) |> toEqual(Some([|"b", "e"|]));
  });

  test("Returns the node neighbors", () => {
    let graph = Graph.make();

    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));
    Graph.setEdge(graph, Edge.t(~v="d", ~w="e", ()));
    Graph.setEdge(graph, Edge.t(~v="a", ~w="e", ()));

    expect(Graph.neighbors(graph, "b")) |> toEqual(Some([|"a", "c"|]));
  });

  test("Returns the node in-edges", () => {
    let graph = Graph.make();

    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));
    Graph.setEdge(graph, Edge.t(~v="d", ~w="e", ()));
    Graph.setEdge(graph, Edge.t(~v="a", ~w="e", ()));

    expect(Graph.inEdges(graph, "b", ()))
    |> toEqual(Some([|Edge.t(~v="a", ~w="b", ())|]));
  });

  test("Returns the node in-edges filtered", () => {
    let graph = Graph.make();

    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));
    Graph.setEdge(graph, Edge.t(~v="c", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="d", ~w="b", ()));

    expect(Graph.inEdges(graph, "b", ~filter="c", ()))
    |> toEqual(Some([|Edge.t(~v="c", ~w="b", ())|]));
  });

  test("Returns the node out-edges", () => {
    let graph = Graph.make();

    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));
    Graph.setEdge(graph, Edge.t(~v="c", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="d", ()));

    expect(Graph.outEdges(graph, "b", ()))
    |> toEqual(
         Some([|Edge.t(~v="b", ~w="c", ()), Edge.t(~v="b", ~w="d", ())|]),
       );
  });

  test("Returns the node out-edges filtered", () => {
    let graph = Graph.make();

    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));
    Graph.setEdge(graph, Edge.t(~v="c", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="d", ~w="b", ()));

    expect(Graph.outEdges(graph, "b", ~filter="c", ()))
    |> toEqual(Some([|Edge.t(~v="b", ~w="c", ())|]));
  });

  test("Returns the node edges", () => {
    let graph = Graph.make();

    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));
    Graph.setEdge(graph, Edge.t(~v="c", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="d", ()));

    expect(Graph.nodeEdges(graph, "b", ()))
    |> toEqual(
         Some([|
           Edge.t(~v="a", ~w="b", ()),
           Edge.t(~v="c", ~w="b", ()),
           Edge.t(~v="b", ~w="c", ()),
           Edge.t(~v="b", ~w="d", ()),
         |]),
       );
  });

  test("Returns the node out-edges filtered", () => {
    let graph = Graph.make();
    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));
    Graph.setEdge(graph, Edge.t(~v="c", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="d", ~w="b", ()));
    expect(Graph.nodeEdges(graph, "b", ~filter="c", ()))
    |> toEqual(
         Some([|Edge.t(~v="c", ~w="b", ()), Edge.t(~v="b", ~w="c", ())|]),
       );
  });

  test("Returns nothing for non-compound graphs", () => {
    let graph = Graph.make();
    Graph.setEdge(graph, Edge.t(~v="a", ~w="b", ()));
    Graph.setEdge(graph, Edge.t(~v="b", ~w="c", ()));

    expect(Graph.parent(graph, "b")) |> toEqual(None);
  });

  test("Returns the parent of a node", () => {
    let graph = Graph.make(~compound=true, ());
    Graph.setNodeWith(
      graph,
      "a",
      Node.attrs(~width=20, ~height=20, ~label="first", ()),
    );
    Graph.setNodeWith(
      graph,
      "b",
      Node.attrs(~width=20, ~height=20, ~label="second", ()),
    );
    Graph.setParent(graph, "b", "a");

    expect(Graph.parent(graph, "b")) |> toEqual(Some("a"));
  });

  test("Returns an empty list for non-compound graphs", () => {
    let graph = Graph.make();
    Graph.setNodeWith(
      graph,
      "a",
      Node.attrs(~width=20, ~height=20, ~label="first", ()),
    );
    Graph.setNodeWith(
      graph,
      "b",
      Node.attrs(~width=20, ~height=20, ~label="second", ()),
    );

    expect(Graph.children(graph, "a")) |> toEqual(None);
  });

  test("Returns the children of a node", () => {
    let graph = Graph.make(~compound=true, ());
    Graph.setNodeWith(
      graph,
      "a",
      Node.attrs(~width=20, ~height=20, ~label="first", ()),
    );
    Graph.setNodeWith(
      graph,
      "b",
      Node.attrs(~width=20, ~height=20, ~label="second", ()),
    );
    Graph.setParent(graph, "b", "a");

    expect(Graph.children(graph, "a")) |> toEqual(Some([|"b"|]));
  });

  test("Checks if an edge exists", () => {
    let graph = Graph.make(~multigraph=true, ());
    let edge = Edge.t(~v="a", ~w="b", ~name="foo", ());
    Graph.setEdge(graph, edge);

    expect(Graph.hasEdge(graph, edge)) |> toEqual(true);
  });

  test("Removes an edge", () => {
    let graph = Graph.make();
    let edge = Edge.t(~v="a", ~w="b", ());
    Graph.setEdge(graph, edge);
    Graph.removeEdge(graph, edge);

    expect(Graph.hasEdge(graph, edge)) |> toEqual(false);
  });

  test("Copies a graph", () => {
    let g = Graph.make();
    Graph.setEdge(g, Edge.t(~v="a", ~w="b", ()));

    let h = Graph.copy(g);

    expect(Graph.attrs(h)) |> toEqual(Graph.attrs(g));
  });

  test("Serializes a graph", () => {
    let g = Graph.make();

    Graph.setNodeWith(
      g,
      "a",
      Node.attrs(~label="node a", ~width=10, ~height=10, ()),
    );
    Graph.setNodeWith(
      g,
      "b",
      Node.attrs(~label="node b", ~width=10, ~height=10, ()),
    );
    Graph.setEdgeWith(
      g,
      Edge.t(~v="a", ~w="b", ()),
      Edge.attrs(~weight=2, ()),
    );

    let actual = Graph.serialize(g);
    let expected = [%raw
      {|
    {
      "options": {
        "directed": true,
        "multigraph": false,
        "compound": false
      },
      "value": {
        "acyclicer": undefined,
        "align": "UL",
        "edgesep": 10,
        "marginx": 0,
        "marginy": 0,
        "nodesep": 50,
        "rankdir": "TB",
        "ranker": "network-simplex",
        "ranksep": 50,
      },
      "nodes": [
        { "v": "a", "value": { "label": "node a", "height": 10, "width": 10 } },
        { "v": "b", "value": { "label": "node b", "height": 10, "width": 10 } }
      ],
      "edges": [
        { "v": "a", "w": "b", "value": { "weight": 2 } }
      ]
    }
    |}
    ];

    expect(actual) |> toEqual(expected);
  });

  test("Deserialize a graph", () => {
    let g = Graph.make();

    Graph.setNodeWith(
      g,
      "a",
      Node.attrs(~label="node a", ~width=10, ~height=10, ()),
    );
    Graph.setNodeWith(
      g,
      "b",
      Node.attrs(~label="node b", ~width=10, ~height=10, ()),
    );
    Graph.setEdgeWith(
      g,
      Edge.t(~v="a", ~w="b", ()),
      Edge.attrs(~weight=2, ()),
    );

    let raw = [%raw
      {| {
      "options": {
        "directed": true,
        "multigraph": false,
        "compound": false
      },
      "value": {
        "acyclicer": undefined,
        "align": "UL",
        "edgesep": 10,
        "marginx": 0,
        "marginy": 0,
        "nodesep": 50,
        "rankdir": "TB",
        "ranker": "network-simplex",
        "ranksep": 50,
      },
      "nodes": [
        { "v": "a", "value": { "label": "node a", "height": 10, "width": 10 } },
        { "v": "b", "value": { "label": "node b", "height": 10, "width": 10 } }
      ],
      "edges": [
        { "v": "a", "w": "b", "value": { "weight": 2 } }
      ]
    } |}
    ];
    let actual = Graph.deserialize(raw)->Graph.serialize;

    expect(actual) |> toEqual(raw);
  });
});
