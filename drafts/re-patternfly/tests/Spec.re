open Jest;
open Expect;
open ReactTestUtils;
open Patternfly;
open Patternfly.Layout;

let assertDom = (container, component, expectFunc) => {
  let container = getContainer(container);

  act(() => {ReactDOM.render(component, container)});

  expectFunc(container);
};

let assertDomSelector = (container, component, (selector, value)) => {
  assertDom(container, component, container => {
    expect(
      container
      ->DOM.findBySelectorAndTextContent(selector, value)
      ->Belt.Option.isSome,
    )
    |> toBe(true)
  });
};
let assertDomJustSelector = (container, component, selector) => {
  assertDom(container, component, container => {
    expect(container->DOM.findBySelector(selector)->isDOMComponent)
    |> toBe(true)
  });
};

describe("Module quality", () => {
  let getName = line =>
    Js.String.split(" ", line)->Belt.Array.get(1)->Belt.Option.getExn;
  let getModulesNames = src =>
    Js.String.split("\n", src)
    ->Belt.List.fromArray
    ->Belt.List.keep(l => Js.String.startsWith("module ", l))
    ->Belt.List.map(getName)
    ->Belt.List.keep(l
        // l not in ["Icons", "Layout"]
        => !["Icons", "Layout"]->Belt.List.has(l, (a, b) => a == b));
  let listSort = xs =>
    xs->Belt.List.sort((a, b) =>
      Js.String.localeCompare(a, b)->Belt.Int.fromFloat * (-1)
    );

  let testOrder = fn => {
    let names = fn->Node.Fs.readFileSync(`utf8)->getModulesNames;
    () => expect(names) |> toEqual(names->listSort);
  };

  test("Patternfly names are in order", testOrder("src/Patternfly.re"));
  test("Layout names are in order", testOrder("src/PFLayouts.re"));
});

describe("Dom rendering test", () => {
  let container = ref(None);
  beforeEach(prepareContainer(container));
  afterEach(cleanupContainer(container));
  let doAssertDom = assertDom(container);
  let doAssertDomSelector = assertDomSelector(container);
  let doAssertDomJustSelector = assertDomJustSelector(container);

  test("can render List", () => {
    doAssertDomSelector(
      <List> <ListItem> {"Hello world!" |> React.string} </ListItem> </List>,
      ("li", "Hello world!"),
    )
  });

  test("can render Card", () => {
    let titleStyle =
      ReactDOM.Style.make(~color="#444444", ~fontSize="68px", ());
    doAssertDom(
      <Card isSelectable=true className="pf-c-card pf-m-compact">
        <CardTitle style=titleStyle> {"title" |> React.string} </CardTitle>
        <CardBody> {"body" |> React.string} </CardBody>
        <CardFooter> {"footer" |> React.string} </CardFooter>
      </Card>,
      container => {
        let createAsserts = (strs: list(string)) => {
          let createAssert = (str: string) => {
            container
            ->DOM.findBySelectorAndTextContent("div", str)
            ->Belt.Option.isSome;
          };
          Belt.List.map(strs, createAssert);
        };

        expect(createAsserts(["title", "body", "footer"]))
        |> toEqual([true, true, true]);
      },
    );
  });

  test("can render Page", () => {
    doAssertDomSelector(
      <Page header={<PageHeader logo={"logo" |> React.string} />}>
        <PageSection variant=`Darker />
      </Page>,
      ("a", "logo"),
    )
  });

  test("can render Nav", () => {
    doAssertDomSelector(
      <Nav>
        <NavList>
          <NavItem isActive=false> {"Gerrit" |> React.string} </NavItem>
        </NavList>
      </Nav>,
      ("a", "Gerrit"),
    )
  });

  test("can render Brand", () => {
    doAssertDomJustSelector(<Brand alt="BrandText" src="src" />, "img")
  });

  test("can render Grid and GridItem", () => {
    doAssertDomSelector(
      <Grid md=Column._12 hasGutter=true>
        <GridItem md=Column._6> {"Item1" |> React.string} </GridItem>
        <GridItem md=Column._6> {"Item2" |> React.string} </GridItem>
      </Grid>,
      ("div", "Item1"),
    )
  });

  test("can render Icons", () => {
    doAssertDomJustSelector(<Icons.Topology />, "svg")
  });

  test("can render Alert", () => {
    doAssertDomSelector(
      <Alert title="Gogo" variant=`Success />,
      ("span", "Success alert:"),
    )
  });

  test("can render AlertGroup", () => {
    doAssertDomJustSelector(
      <AlertGroup> <Alert title="Ok" /> </AlertGroup>,
      "li",
    )
  });

  test("can render Badge", () =>
    doAssertDomSelector(
      <Badge isRead=false> {42 |> React.int} </Badge>,
      ("span", "42"),
    )
  );

  test("can render Banner", () =>
    doAssertDomSelector(
      <Banner variant=`Info> {"Good" |> React.string} </Banner>,
      ("div", "Good"),
    )
  );

  test("can show Breadcrum", () =>
    doAssertDomSelector(
      <Breadcrumb>
        <BreadcrumbItem _to="#"> {"Home" |> React.string} </BreadcrumbItem>
        <BreadcrumbHeading _to="#">
          {"Project" |> React.string}
        </BreadcrumbHeading>
      </Breadcrumb>,
      ("a", "Home"),
    )
  );

  test("can render Checkbox", () =>
    doAssertDomJustSelector(<Checkbox id="test" />, "input")
  );
});
