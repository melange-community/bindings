let component = ReasonReact.statelessComponent("App");

let code = "
    print(\"Hello, world!\")
  ";

let make = _children => {
  ...component,
  render: _self => <Highlight className="python"> ...code </Highlight>,
};