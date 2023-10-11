let component = ReasonReact.statelessComponent("App");

let code = "
    function helloWorld() {
      console.log('Hello, world!')
    }
  ";

let make = _children => {
  ...component,
  render: _self => <Highlight> ...code </Highlight>,
};