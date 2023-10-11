/* Table.re

   This is a (very thin) wrapper around Table.

   For type safety it expects a `TypeSpec` functor. My ocaml-fu failed me at that point so it still expects a matrix of raw-js objects.

   For an example of how to use this checkout `TableDemo.re`.
   */
[%bs.raw {|require('react-virtualized/styles.css')|}];

[@bs.module "react-virtualized"]
external column : ReasonReact.reactClass = "Column";

[@bs.module "react-virtualized"]
external table : ReasonReact.reactClass = "Table";

let str = ReasonReact.stringToElement;

module Column = {
  type t = {
    label: string,
    dataKey: string,
    width: int
  };
  let component = ReasonReact.statelessComponent("Column");
  let make = (~spec: t, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=column,
      ~props={
        "label": spec.label,
        "dataKey": spec.dataKey,
        "width": spec.width
      },
      children
    );
};

/*
 A function whose contents are the concrete type that the table will understand.
 */
module type TypeSpec = {
  /* the abstract type */
  type t;
  /* the complete set of data this table should render */
  let rows: array(t);
};

/*
 Function method to make a concrete type for this Table.
  */
module Make = (RS: TypeSpec) => {
  module Table = {
    /* The configuration for this Table.

       This isn't about the type of the data, only the type of the configuration provided to this Table.
       */
    type t = {
      headerHeight: int,
      columnWidth: int,
      height: int,
      rowHeight: int,
      columnSpecs: list(Column.t)
    };
    let make = (~spec: t, children) => {
      let specs = spec.columnSpecs;
      let columns = List.map(spec => <Column spec />, specs);
      let tableWidth =
        List.fold_left((w, spec: Column.t) => w + spec.width, 0, specs);
      let rowGetter = a => RS.rows[a##index];
      let children = Array.append(children, Array.of_list(columns));
      ReasonReact.wrapJsForReason(
        ~reactClass=table,
        ~props={
          "headerHeight": spec.headerHeight,
          "columnCount": List.length(columns),
          "columnWidth": spec.columnWidth,
          "height": spec.height,
          "rowCount": Array.length(RS.rows),
          "rowHeight": spec.rowHeight,
          "width": tableWidth,
          "rowGetter": rowGetter
        },
        children
      );
    };
  };
};