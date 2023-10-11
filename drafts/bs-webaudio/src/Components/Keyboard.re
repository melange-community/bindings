[@react.component]
let make = () => {
  let appContext = React.useContext(AppContextProvider.appContext);
  let (_, setKeyPress) = React.useState(() => false);

  let trigger = (e: Webapi.Dom.KeyboardEvent.t) =>
    if (Webapi.Dom.KeyboardEvent.key(e) == "a") {
      setKeyPress(key =>
        if (key == false) {
          appContext.triggerTargets
          |> List.iter(env => env |> Envelope.trigger);
          true;
        } else {
          true;
        }
      );
    };

  let endTrigger = (e: Webapi.Dom.KeyboardEvent.t) =>
    if (Webapi.Dom.KeyboardEvent.key(e) == "a") {
      setKeyPress(_ => {
        appContext.triggerTargets
        |> List.iter(env => env |> Envelope.endTrigger);
        false;
      });
    };

  React.useEffect1(
    () => {
      Webapi.Dom.document
      |> Webapi.Dom.Document.addKeyDownEventListener(trigger);
      Webapi.Dom.document
      |> Webapi.Dom.Document.addKeyUpEventListener(endTrigger);
      Some(
        () => {
          Webapi.Dom.document
          |> Webapi.Dom.Document.removeKeyDownEventListener(trigger);
          Webapi.Dom.document
          |> Webapi.Dom.Document.removeKeyDownEventListener(endTrigger);
        },
      );
    },
    [|appContext.triggerTargets|],
  );

  ReasonReact.null;
};
