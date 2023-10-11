open BsBroadcastChannel;

// Entry point
[@bs.val] external document: Js.t({..}) = "document";

let channel = BroadcastChannel.make("My App");

// All 4 examples.
ReactDOMRe.render(
  <App channel/>,
  document##body,
);

