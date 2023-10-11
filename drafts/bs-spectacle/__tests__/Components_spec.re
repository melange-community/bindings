open Jest;

describe(
  "Appear",
  ExpectJs.(
    () => {
      test("without props", () => {
        let component = TestHelpers.setup(<Appear />);
        expect(component) |> toMatchSnapshot;
      });
      test("with fid", () => {
        let component = TestHelpers.setup(<Appear fid="1" />);
        expect(component) |> toMatchSnapshot;
      });
      test("with order", () => {
        let component = TestHelpers.setup(<Appear order=1 />);
        expect(component) |> toMatchSnapshot;
      });
    }
  ),
);

describe(
  "ComponentPlayground",
  ExpectJs.(
    () => {
      test("without props", () => {
        let component = TestHelpers.setup(<ComponentPlayground />);
        expect(component) |> toMatchSnapshot;
      });
      test("with dark theme", () => {
        let component = TestHelpers.setup(<ComponentPlayground theme=Dark />);
        expect(component) |> toMatchSnapshot;
      });
      test("with light theme", () => {
        let component =
          TestHelpers.setup(<ComponentPlayground theme=Light />);
        expect(component) |> toMatchSnapshot;
      });
      test("with preview background color", () => {
        let component =
          TestHelpers.setup(
            <ComponentPlayground previewBackgroundColor="#7315FF" />,
          );
        expect(component) |> toMatchSnapshot;
      });
      test("with scope", () => {
        let component =
          TestHelpers.setup(
            <ComponentPlayground scope={"logger": Js.Console.log} />,
          );
        expect(component) |> toMatchSnapshot;
      });
      test("with code", () => {
        let component =
          TestHelpers.setup(<ComponentPlayground code="test" />);
        expect(component) |> toMatchSnapshot;
      });
    }
  ),
);

module Deck = {};

module Fill =
  TestHelpers.MakeTest({
    let name = "Fill";
    let element = <Fill />;
  });

module Fit =
  TestHelpers.MakeTest({
    let name = "Fit";
    let element = <Fit />;
  });

module Layout =
  TestHelpers.MakeTest({
    let name = "Layout";
    let element = <Layout />;
  });

module Magic = {};

/* TestHelpers.MakeTest(
     {
       let name = "Magic";
       let element = <Magic> <Text /> </Magic>;
     }
   ); */
module Notes =
  TestHelpers.MakeTest({
    let name = "Notes";
    let element = <Notes> "test" </Notes>;
  });

module SlideSet =
  TestHelpers.MakeTest({
    let name = "SlideSet";
    let element = <SlideSet />;
  });