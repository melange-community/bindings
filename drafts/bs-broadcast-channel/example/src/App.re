open BsBroadcastChannel;

type t =
  | Add(string)
;

[@react.component]
let make = (~channel: BroadcastChannel.t) => {
  let (data, dispatch) = React.useReducer(
    (state: list(string), action: t) => { 
      Js.log(state);
      Js.log(action); 
      switch (action) {
        | Add(value) => [value, ...state];
      }
    },
    [],
  );

  let current: React.Ref.t(string) = React.useRef("");

  React.useEffect1(() => {
    let callback = (data) => {
      Js.log(data);
      let value = MessageEvent.data(data);
      dispatch(Add(value))
    };

    channel->BroadcastChannel.addEventListener("message", callback);

    Some(() => {
      channel->BroadcastChannel.removeEventListener("message", callback);
    });
  }, [| channel |]);

  let submit = React.useCallback0(_ => {
    let value = React.Ref.current(current);
    channel->BroadcastChannel.postMessage(value);
    Js.log(value);
    dispatch(Add(value))
  });
  let onChange = React.useCallback0((event) => {
    let value = ReactEvent.Form.target(event)##value;
    Js.log(value);
    React.Ref.setCurrent(current, value);
    ();
  });

  <div>
    <input
      type_="text"
      onChange=onChange
    />
    <button type_="button" onClick=submit>
      { ReasonReact.string("Send") }
    </button>
    <ul>
      {
        ReasonReact.array(
          Array.of_list(
            data |> List.map((value) => <li>{ ReasonReact.string(value) }</li>)
          )
        )
      }
    </ul>
  </div>
}