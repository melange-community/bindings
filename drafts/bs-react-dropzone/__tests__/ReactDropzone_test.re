open Jest;
open ExpectJs;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let renderReason = (~acceptProp=None, ()) =>
  {
    let children = _ => ReasonReact.null;

    /* react-dropzone uses `forwardRef` and hooks on the root element
     * what causes issues when rendered directly through shallow renderer
     * Using Fragment (</>) triggers another kind of error, so plain old div
     * isn't as bad as you may think
     */
    <div>
      {switch (acceptProp) {
       | None => <ReactDropzone> children </ReactDropzone>
       | Some(accept) => <ReactDropzone accept> children </ReactDropzone>
       }}
    </div>;
  }
  |> Enzyme.shallow
  |> Enzyme.Shallow.childAt(0);

let renderJs = [%bs.raw
  "(accept) => React.createElement(require('react-dropzone').default, { accept }, () => null)"
];

describe("jsx3", () => {
  test("output equal to direct JS rendering", () => {
    let reasonComponent = renderReason();
    let jsComponent = [%bs.raw "renderJs()"];

    expect(Enzyme.Shallow.equals(jsComponent, reasonComponent))
    |> toBe(true);
  });

  describe("accept property", () => {
    test("single", () => {
      let reasonComponent =
        renderReason(~acceptProp=Some(`single("application/json")), ());
      let jsComponent = [%bs.raw "renderJs('application/json')"];

      expect(Enzyme.Shallow.equals(jsComponent, reasonComponent))
      |> toBe(true);
    });

    test("multi", () => {
      let reasonComponent =
        renderReason(
          ~acceptProp=Some(`many(["application/json", "text/json"])),
          (),
        );
      let jsComponent = [%bs.raw "renderJs(['application/json', 'text/json'])"];

      expect(Enzyme.Shallow.equals(jsComponent, reasonComponent))
      |> toBe(true);
    });
  });
});
