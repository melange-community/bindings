[@bs.module "enzyme"]
external shallow: (Enzyme.node, Js.t({..})) => Enzyme.shallowWrapper = "";

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

%raw
"window.matchMedia = function() {return {matches: false}};";

%raw
{|global.localStorage = {
  setItem() {}
};|};

let setup = component =>
  shallow(
    component,
    {
      "context": {
        "styles": {
          "components": {
            "heading": {
              "h1": Js.Obj.empty(),
            },
            "s": Js.Obj.empty(),
          },
          "colors": Js.Obj.empty(),
          "fonts": Js.Obj.empty(),
          "prism": Js.Obj.empty(),
        },
        "store": {
          "getState": () => {
            "style": Js.Obj.empty(),
            "route": {
              "slide": 0,
            },
          },
          "subscribe": () => (),
          "dispatch": () => (),
        },
      },
    },
  );

module type TestBlueprint = {
  let name: string;
  let element: ReasonReact.reactElement;
};

module MakeTest = (Blueprint: TestBlueprint) => {
  open Jest;
  describe(
    Blueprint.name,
    ExpectJs.(
      () =>
        test("with props", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=Js.Obj.empty(),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        })
    ),
  );
};

module MakeBasePropsTest = (Blueprint: TestBlueprint) => {
  open Jest;
  describe(
    Blueprint.name,
    ExpectJs.(
      () => {
        test("without any props", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=Js.Obj.empty(),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("italic", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=BaseProps.extendProps(~italic=true, Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("bold", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=BaseProps.extendProps(~bold=true, Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("caps", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=BaseProps.extendProps(~caps=true, Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("margin", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=BaseProps.extendProps(~margin="10px", Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("padding", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=BaseProps.extendProps(~padding="10px", Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("textColor", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=
                  BaseProps.extendProps(~textColor="#621fe2", Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("textSize", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=
                  BaseProps.extendProps(~textSize="10px", Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("textAlign", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=
                  BaseProps.extendProps(~textAlign="center", Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("textFont", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=
                  BaseProps.extendProps(
                    ~textFont="sans-serif",
                    Js.Obj.empty(),
                  ),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("bgColor", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=
                  BaseProps.extendProps(~bgColor="#ffee65", Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("bgImage", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=
                  BaseProps.extendProps(~bgImage="img.jpg", Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("bgSize", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=BaseProps.extendProps(~bgSize="100%", Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("bgPosition", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=
                  BaseProps.extendProps(~bgPosition="top", Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("bgRepeat", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=
                  BaseProps.extendProps(~bgRepeat="none", Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("bgDarken", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=BaseProps.extendProps(~bgDarken=0.7, Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("overflow", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=
                  BaseProps.extendProps(~overflow="hidden", Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
        test("height", () => {
          let component =
            setup(
              ReasonReact.cloneElement(
                Blueprint.element,
                ~props=BaseProps.extendProps(~height="10px", Js.Obj.empty()),
                [||],
              ),
            );
          expect(component) |> toMatchSnapshot;
        });
      }
    ),
  );
};