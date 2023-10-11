open ReasonTransitionGroup;

[@react.component]
let make = () => {
  let (show, toggleShow) = React.useState(() => false);
  <div
    style={ReactDOMRe.Style.make(
      ~display="flex",
      ~flexDirection="column",
      (),
    )}>
    <button onClick={_event => toggleShow(_ => !show)}>
      {"Toggle" |> React.string}
    </button>
    <Transition
      _in=show
      unmountOnExit=true
      timeout={`obj(Transition.timeoutFull(~enter=500, ~exit=1500, ()))}>
      ...{state =>
        switch (state) {
        | "entering" => "Entering..." |> React.string
        | "entered" => "Entered!" |> React.string
        | "exiting" => "Exiting..." |> React.string
        | "exited" => "Exited!" |> React.string
        | _ => "" |> React.string
        }
      }
    </Transition>
  </div>;
};