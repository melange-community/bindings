open ReasonTransitionGroup;

module Styles = {
  open Css;
  let alertEnter =
    style([
      opacity(0.),
      transform(`scale((0.9, 0.9))),
      label("alert-enter"),
    ]);
  let alertEnterActive =
    style([
      opacity(1.),
      transform(`translateX(`zero)),
      transition(~duration=300, "all"),
      label("alert-enter-active"),
    ]);
  let alertExit = style([opacity(1.0), label("alert-exit")]);
  let alertExitActive =
    style([
      opacity(0.),
      transform(`scale((0.9, 0.9))),
      transition(~duration=300, "all"),
      label("alert-exit-active"),
    ]);
  let btn =
    style([
      color(`hex("fff")),
      background(`hex("007bff")),
      borderColor(`hex("007bff")),
      borderRadius(`rem(0.3)),
      fontSize(`rem(1.25)),
      padding2(~v=`rem(0.5), ~h=`rem(1.0)),
    ]);
  let modal =
    style([
      height(`px(150)),
      width(`px(200)),
      color(`hex("004085")),
      background(`hex("cce5ff")),
      padding(`px(25)),
    ]);
  let modalHead =
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      paddingBottom(`px(20)),
      label("alert"),
    ]);
  let modalTitle = style([fontSize(`px(18)), fontWeight(`bold)]);
};

let classNames =
  `obj(
    CSSTransition.classFull(
      ~enter=Styles.alertEnter,
      ~enterActive=Styles.alertEnterActive,
      ~exit=Styles.alertExit,
      ~exitActive=Styles.alertExitActive,
      (),
    ),
  );

[@react.component]
let make = () => {
  let (showButton, setShowButton) = React.useState(() => true);
  let (showMessage, setShowMessage) = React.useState(() => false);
  <div>
    {switch (showButton) {
     | true =>
       <button className=Styles.btn onClick={_ => setShowMessage(_ => true)}>
         {"Show Message" |> React.string}
       </button>
     | _ => React.null
     }}
    <CSSTransition
      _in=showMessage
      timeout={`int(300)}
      classNames
      unmountOnExit=true
      onEnter={(_, _) => setShowButton(_ => false)}
      onExited={_ => setShowButton(_ => true)}>
      {_state =>
         <div className=Styles.modal>
           <div className=Styles.modalHead>
             <span className=Styles.modalTitle>
               {"Animated alert message" |> React.string}
             </span>
             <div onClick={_ => setShowMessage(_ => false)}>
               {"x" |> React.string}
             </div>
           </div>
           <span>
             {"This alert message is being transitioned in and out of the DOM."
              |> React.string}
           </span>
         </div>}
    </CSSTransition>
  </div>;
};