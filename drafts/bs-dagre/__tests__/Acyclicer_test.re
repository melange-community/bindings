open Jest;
open Expect;
open Acyclicer;

describe("Acyclicer", () => {
  test("greedy", () =>
    expect(fromStringExn(toString(Greedy))) |> toEqual(Greedy)
  );

  test("lazy", () =>
    expect(fromStringExn(toString(Lazy))) |> toEqual(Lazy)
  );

  test("other", () =>
    expect(() =>
      fromStringExn(Some("foo"))
    ) |> toThrow
  );
});
