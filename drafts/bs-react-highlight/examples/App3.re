let component = ReasonReact.statelessComponent("App");

let code = "
    <h1>Hello, world!</h1>
  ";

let make = _children => {
  ...component,
  render: _self => <Highlight innerHTML=true> ...code </Highlight>,
};