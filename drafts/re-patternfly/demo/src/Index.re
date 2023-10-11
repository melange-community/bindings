// Use this Reason entrypoint to start the rendering.
// The App component is defined in a dedicated module.
switch (ReactDOM.querySelector("#root")) {
| Some(root) => ReactDOM.render(<App />, root)
| None => Js.log("oops!")
};
