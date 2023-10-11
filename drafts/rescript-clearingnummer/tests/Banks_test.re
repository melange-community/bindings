open Jest;
open Expect;

describe("#all", () =>
  test("list all banks", () =>
    expect(Banks.all) |> toMatchSnapshot
  )
);
