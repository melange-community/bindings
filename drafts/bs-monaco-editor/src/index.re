Utils.require("./index.css");

module App = {
  [@react.component]
  let make = _ => {
    let (code, setCode) = React.useState(_ => "");
    let handleChange = value => {
      Js.log(value);
      setCode(_ => value);
    };

    <Monaco value=code onChange=handleChange />;
  };
};

ReactDOMRe.renderToElementWithId(<App />, "root");