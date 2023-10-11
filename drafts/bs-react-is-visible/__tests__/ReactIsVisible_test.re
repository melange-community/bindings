open Jest;
open Expect;
open ReactTestingLibrary;

[%bs.raw {| require("intersection-observer") |}];

module App = {
  [@react.component]
  let make = () => {
    let (isVisible, ref) = ReactIsVisible.useIsVisible();

    <div style={ReactDOMRe.Style.make(~height="200vh", ())}>
      <h1 ref>
        {(isVisible ? "I'm visible!" : "I'm not visible!") |> React.string}
      </h1>
    </div>;
  };
};

describe("ReactIsVisible", () => {
  afterEach(cleanup);

  test("renders", () =>
    <App /> |> render |> container |> expect |> toMatchSnapshot
  );

  test("adds element to subscribers on mount", () => {
    let subscribers = ReactIsVisible.VO.getSubscribers();
    let hasDomNode = (_subscribers, _element) => [%bs.raw
      {| _subscribers.has(_element) |}
    ];

    let component = <App /> |> render;

    let el = component |> getByText(~matcher=`Str("I'm not visible!"));

    expect(hasDomNode(subscribers, el)) |> toEqual(true);
  });

  test("unsubscribes element on unmount", () => {
    let subscribers = ReactIsVisible.VO.getSubscribers();
    let hasDomNode = (_subscribers, _element) => [%bs.raw
      {| _subscribers.has(_element) |}
    ];

    let component = <App /> |> render;

    let el = component |> getByText(~matcher=`Str("I'm not visible!"));

    expect(hasDomNode(subscribers, el)) |> toEqual(true) |> ignore;

    component |> unmount() |> ignore;

    expect(hasDomNode(subscribers, el)) |> toEqual(false);
  });
});
