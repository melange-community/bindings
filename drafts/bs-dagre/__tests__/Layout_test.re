open Jest;
open Expect;

describe("Layout", () => {
  test("empty graph has no size", () => {
    let graph = Graph.make();
    let layout = Layout.make(graph);

    expect(Layout.size(layout)) |> toEqual((0, 0));
  });

  describe("actors graph", () => {
    let attrs = Graph.Attrs.make(~rankdir=Rank.Dir.LeftRight, ());
    let g = Graph.make(~attrs, ());

    Graph.setDefaultEdgeLabel(g, () => {"minlen": 3});

    Graph.setNodeWith(
      g,
      "kspacey",
      Node.attrs(~label="Kevin Spacey", ~width=144, ~height=100, ()),
    );
    Graph.setNodeWith(
      g,
      "swilliams",
      Node.attrs(~label="Saul Williams", ~width=160, ~height=100, ()),
    );
    Graph.setNodeWith(
      g,
      "bpitt",
      Node.attrs(~label="Brad Pitt", ~width=108, ~height=100, ()),
    );
    Graph.setNodeWith(
      g,
      "hford",
      Node.attrs(~label="Harrison Ford", ~width=168, ~height=100, ()),
    );
    Graph.setNodeWith(
      g,
      "lwilson",
      Node.attrs(~label="Luke Wilson", ~width=144, ~height=100, ()),
    );
    Graph.setNodeWith(
      g,
      "kbacon",
      Node.attrs(~label="Kevin Bacon", ~width=121, ~height=100, ()),
    );

    Graph.setEdge(g, Edge.t(~v="kspacey", ~w="swilliams", ()));
    Graph.setEdge(g, Edge.t(~v="swilliams", ~w="kbacon", ()));
    Graph.setEdge(g, Edge.t(~v="bpitt", ~w="kbacon", ()));
    Graph.setEdge(g, Edge.t(~v="hford", ~w="lwilson", ()));
    Graph.setEdge(g, Edge.t(~v="lwilson", ~w="kbacon", ()));

    let layout = Layout.make(g);

    test("layout size", () =>
      expect(Layout.size(layout)) |> toEqual((749, 400))
    );

    test("hford position", () =>
      expect(Layout.nodeCoords(layout, "hford"))
      |> toEqual(Some((84, 350)))
    );
  });
});
