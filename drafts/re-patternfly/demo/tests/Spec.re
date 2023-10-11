open Jest;
open Expect;
open ReactTestUtils;

describe("Basic test", () => {
  let container = ref(None);
  beforeEach(prepareContainer(container));
  afterEach(cleanupContainer(container));

  test("can render the App", () => {
    let container = getContainer(container);

    act(() => {ReactDOM.render(<App />, container)});

    expect(
      container
      ->DOM.findBySelectorAndTextContent("li", "Hello patternfly!")
      ->Belt.Option.isSome,
    )
    |> toBe(true);
  });
});
