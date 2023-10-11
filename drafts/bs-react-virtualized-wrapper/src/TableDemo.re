/* Table.re */
let str = ReasonReact.stringToElement;

module MyRows: Table.TypeSpec = {
  type t = {
    .
    "a": string,
    "b": string
  };
  let rows = [|{"a": "11", "b": "12"}, {"a": "21", "b": "22"}|];
};

let component = ReasonReact.statelessComponent("DemoTable");

let make = _children => {
  ...component,
  render: _self => {
    module MyTable = Table.Make(MyRows);
    let spec: MyTable.Table.t = {
      headerHeight: 20,
      columnWidth: 200,
      height: 300,
      rowHeight: 30,
      columnSpecs: [
        {label: "a", dataKey: "a", width: 80},
        {label: "b", dataKey: "b", width: 80}
      ]
    };
    <MyTable.Table spec />;
  }
};