open Jest;
open Expect;

describe("Algorithm", () => {
  test("shortest path with dijkstra", () => {
    let graph = Graph.make();
    Graph.setEdge(graph, Edge.t(~v="A", ~w="C", ()));
    Graph.setEdge(graph, Edge.t(~v="A", ~w="D", ()));
    Graph.setEdge(graph, Edge.t(~v="C", ~w="B", ()));
    Graph.setEdge(graph, Edge.t(~v="D", ~w="F", ()));
    Graph.setEdge(graph, Edge.t(~v="F", ~w="E", ()));

    let actual = Algorithm.dijkstra(graph, "A");
    let expected = [%raw
      {|
      {
         "A": { "distance": 0 },
         "C": { "distance": 1, "predecessor": 'A' },
         "D": { "distance": 1, "predecessor": 'A' },
         "B": { "distance": 2, "predecessor": 'C' },
         "F": { "distance": 2, "predecessor": 'D' },
         "E": { "distance": 3, "predecessor": 'F' },
      }
    |}
    ];

    expect(actual) |> toEqual(expected);
  });

  test("shortest path with dijkstraAll", () => {
    let graph = Graph.make();
    Graph.setEdge(graph, Edge.t(~v="A", ~w="C", ()));
    Graph.setEdge(graph, Edge.t(~v="A", ~w="D", ()));
    Graph.setEdge(graph, Edge.t(~v="C", ~w="B", ()));
    Graph.setEdge(graph, Edge.t(~v="D", ~w="F", ()));
    Graph.setEdge(graph, Edge.t(~v="F", ~w="E", ()));

    let actual = Algorithm.dijkstraAll(graph);
    let expected = [%raw
      {|
      {
        "A": {
           "A": { "distance": 0 },
           "C": { "distance": 1, "predecessor": 'A' },
           "D": { "distance": 1, "predecessor": 'A' },
           "B": { "distance": 2, "predecessor": 'C' },
           "F": { "distance": 2, "predecessor": 'D' },
           "E": { "distance": 3, "predecessor": 'F' },
        },
        "C": {
          "A": { "distance": Infinity },
          "C": { "distance": 0 },
          "D": { "distance": Infinity },
          "B": { "distance": 1, "predecessor": 'C' },
          "F": { "distance": Infinity },
          "E": { "distance": Infinity },
        },
        "D": {
          "A": { "distance": Infinity },
          "C": { "distance": Infinity },
          "D": { "distance": 0 },
          "B": { "distance": Infinity },
          "F": { "distance": 1, "predecessor": 'D' },
          "E": { "distance": 2, "predecessor": 'F' },
        },
        "B": {
          "A": { "distance": Infinity },
          "C": { "distance": Infinity },
          "D": { "distance": Infinity },
          "B": { "distance": 0 },
          "F": { "distance": Infinity },
          "E": { "distance": Infinity },
        },
        "F": {
          "A": { "distance": Infinity },
          "C": { "distance": Infinity },
          "D": { "distance": Infinity },
          "B": { "distance": Infinity },
          "F": { "distance": 0 },
          "E": { "distance": 1, "predecessor": 'F' },
        },
        "E": {
          "A": { "distance": Infinity },
          "C": { "distance": Infinity },
          "D": { "distance": Infinity },
          "B": { "distance": Infinity },
          "F": { "distance": Infinity },
          "E": { "distance": 0 },
        },
      }
    |}
    ];

    expect(actual) |> toEqual(expected);
  });
});
