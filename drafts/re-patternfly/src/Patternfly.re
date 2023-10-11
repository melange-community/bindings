// Most components are generated with https://softwarefactory-project.io/cgit/software-factory/re-cli/
// The list entrypoint is GeneratePatternflyComponentBindings.re
// Translation from typescript to reason is PatternflyBindings.re
// Typescript parser is Typescript.re
include PFComponents;

include PFTypes;

// https://www.patternfly.org/v4/guidelines/icons/
//   generated using re-cli
module Icons = {
  include PFIcons;
};

module Layout = {
  include PFLayouts;
};

// https://www.patternfly.org/v4/components/table
// See the demo for a SortableTable usage
// -> https://github.com/softwarefactory-project/re-patternfly/blob/master/demo/src/App.res

// Columns
type transformers;
type pfCell = {
  title: string,
  transforms: array(transformers),
};
type pfcells = array(pfCell);

// Rows
type null;
type pfFormatterData('a) = {props: 'a};
type pfFormatterValue('a) = {rowData: pfFormatterData('a)};
type pfFormatter('a) = (null, pfFormatterValue('a)) => React.element;
type pfRowCell('a) = {formatters: array(pfFormatter('a))};

let mkFormatter: ('a => React.element) => pfRowCell('a) =
  mkElement => {
    formatters: [|(_, value) => mkElement(value.rowData.props)|],
  };

type pfRow('a) = {
  cells: array(pfRowCell('a)),
  props: 'a,
};
type pfrows('a) = array(pfRow('a));

// Use this function to create tables rows
let mkRows =
    (xs: list('a), formatters: list('a => React.element)): pfrows('a) => {
  let cells = formatters->Belt.List.map(mkFormatter)->Belt.List.toArray;
  xs->Belt.List.map(props => {cells, props})->Belt.List.toArray;
};

[@bs.module "@patternfly/react-table"] [@bs.val]
external sortable: transformers = "sortable";

type sortByDirection = [ | `asc | `desc];

type variantType = [ | `compact | `default];

type sortBy = {
  index: int,
  direction: sortByDirection,
};

let sortRows =
    (
      rows: pfrows('a),
      isOrdered: ('a, 'a, int) => bool,
      index: int,
      direction: sortByDirection,
    ) =>
  rows
  |> Js.Array.sortInPlaceWith((a, b) => {
       let (first, second) =
         switch (direction) {
         | `desc => (a.props, b.props)
         | `asc => (b.props, a.props)
         };
       isOrdered(first, second, index) ? (-1) : first == second ? 0 : 1;
     });

module Table = {
  [@react.component] [@bs.module "@patternfly/react-table"]
  external make:
    (
      ~rows: pfrows('a),
      ~cells: pfcells,
      ~sortBy: sortBy,
      ~onSort: (ReactEvent.Mouse.t, int, sortByDirection) => unit=?,
      ~caption: string=?,
      ~variant: variantType=?,
      ~children: 'children=?
    ) =>
    React.element =
    "Table";
};

module TableBody = {
  [@react.component] [@bs.module "@patternfly/react-table"]
  external make: (~children: 'children=?) => React.element = "TableBody";
};

module TableHeader = {
  [@react.component] [@bs.module "@patternfly/react-table"]
  external make: (~children: 'children=?) => React.element = "TableHeader";
};
