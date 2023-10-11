Examples from [official docs](https://reactcommunity.org/react-transition-group) translated to [reason-react](https://github.com/reasonml/reason-react) using [bs-css](https://github.com/SentiaAnalytics/bs-css).

## Transition

```reason
open ReasonTransitionGroup;

type state = {
  show: bool,
};
type action =
  | Toggle

let component = ReasonReact.reducerComponent("Component1");


let make = _children => {
  ...component,
  initialState: () => {show: false},
  reducer: (action, state) =>
    switch (action) {
    | Toggle => ReasonReact.Update({show: !state.show})
    },
  render: self =>
    <div
      style={ReactDOMRe.Style.make(
        ~display="flex",
        ~flexDirection="column",
        (),
      )}>
      <button onClick={_event => self.send(Toggle)}>
        {"Toggle" |> ReasonReact.string}
      </button>
      <Transition
        _in={self.state.show}
        unmountOnExit=true
        timeout={`obj(Transition.timeoutFull(~enter=500, ~exit=1500, ()))}>
        ...{state =>
          switch (state) {
          | "entering" => "Entering..." |> ReasonReact.string
          | "entered" => "Entered!" |> ReasonReact.string
          | "exiting" => "Exiting..." |> ReasonReact.string
          | "exited" => "Exited!" |> ReasonReact.string
          | _ => "" |> ReasonReact.string
          }
        }
      </Transition>
    </div>,
};
```

## CSSTransition

```reason
open ReasonTransitionGroup;

type state = {
  show: bool,
};
type action =
  | Toggle

let component = ReasonReact.reducerComponent("Component1");

module Styles = {
  open Css;

  let messageEnter =
    style([
      opacity(0.1),
      label("msg-enter"),
      transforms([scale(0.9, 0.9), translateY(`percent(50.))]),
    ]);
  let messageEnterActive =
    style([
      opacity(1.),
      label("msg-enter-active"),
      transforms([scale(1., 1.), translateY(`percent(0.))]),
      transition(~duration=300, ~timingFunction=`easeOut, "all"),
    ]);
  let messageExit =
    style([
      opacity(1.),
      label("msg-exit"),
      transforms([scale(1., 1.), translateY(`percent(0.))]),
    ]);
  let messageExitActive =
    style([
      opacity(0.01),
      label("msg-exit-active"),
      transforms([scale(0.9, 0.9), translateY(`percent(50.))]),
      transition(~duration=300, ~timingFunction=`easeOut, "all"),
    ]);
  let star =
    style([
      label("star"),
      display(`inlineBlock),
      marginLeft(`rem(0.5)),
      transform(`scale((1.25, 1.25))),
    ]);
  let starEnter =
    style([
      label("star-enter-active"),
      opacity(0.1),
      transforms([translateY(`percent(-100.)), scale(0.75, 0.75)]),
    ]);
  let starEnterActive =
    style([
      label("star-enter-active"),
      opacity(1.),
      transforms([translateY(`percent(0.)), scale(1.25, 1.25)]),
      transition(~duration=300, ~timingFunction=`easeOut, "all"),
    ]);
  let starExit =
    style([
      label("star-exit"),
      opacity(1.),
      transform(scale(1.25, 1.25)),
    ]);
  let starExitActive =
    style([
      opacity(0.),
      transform(scale(4., 4.)),
      transition(~duration=300, ~timingFunction=`easeOut, "all"),
    ]);
};

let make = _children => {
  ...component,
  initialState: () => {show: false},
  reducer: (action, state) =>
    switch (action) {
    | Toggle => ReasonReact.Update({show: !state.show})
    },
  render: self =>
    <div
      style={ReactDOMRe.Style.make(
        ~display="flex",
        ~flexDirection="column",
        (),
      )}>
      <button onClick={_event => self.send(Toggle)}>
        {"Toggle" |> ReasonReact.string}
      </button>
      <CSSTransition
        _in={self.state.show}
        unmountOnExit=true
        timeout={`int(300)}
        classNames={
                     `obj(
                       CSSTransition.classFull(
                         ~enter=Styles.messageEnter,
                         ~enterActive=Styles.messageEnterActive,
                         ~exit=Styles.messageExit,
                         ~exitActive=Styles.messageExitActive,
                         (),
                       ),
                     )
                   }>
        ...{state => {
          let isIn = state === "entered";
          <div className="msg">
            {"Your name rocks!" |> ReasonReact.string}
            <CSSTransition
              _in=isIn
              timeout={`int(300)}
              classNames={
                           `obj(
                             CSSTransition.classFull(
                               ~enter=Styles.starEnter,
                               ~enterActive=Styles.starEnterActive,
                               ~exit=Styles.starExit,
                               ~exitActive=Styles.starExitActive,
                               (),
                             ),
                           )
                         }
              unmountOnExit=true>
              ...{_state =>
                <div className=Styles.star> {"X" |> ReasonReact.string} </div>
              }
            </CSSTransition>
          </div>;
        }}
      </CSSTransition>
    </div>,
};
```
