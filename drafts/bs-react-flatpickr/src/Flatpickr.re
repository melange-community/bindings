open FlatpickrTypes;

[@bs.obj]
external makePropsFlatpickr:
(
  ~className: string=?,
    ~children: React.element=?,
    ~defaultValue: string=?,
    ~inputRef: ReactDOMRe.domRef=?,
    ~onChange: Hook.handler=?,
    ~onClose: Hook.handler=?,
    ~onDayCreate: Hook.handler=?,
    ~onDestroy: Hook.handler=?,
    ~onMonthChange: Hook.handler=?,
    ~onOpen: Hook.handler=?,
    ~onReady: Hook.handler=?,
    ~onValueUpdate: Hook.handler=?,
    ~onYearChange: Hook.handler=?,
    ~options: Js.t({..}) as 'o=?,
    ~render: (renderProps, ReactDOMRe.domRef) => React.element=?,
    ~value: option(Value.t)=?,
  unit
) => _;

let makeProps =
    (
      ~className: option(string)=?,
      ~children: option(React.element)=?,
      ~defaultValue: option(string)=?,
      ~inputRef: option(ReactDOMRe.domRef)=?,
      ~onChange: option(Hook.handler)=?,
      ~onClose: option(Hook.handler)=?,
      ~onDayCreate: option(Hook.handler)=?,
      ~onDestroy: option(Hook.handler)=?,
      ~onMonthChange: option(Hook.handler)=?,
      ~onOpen: option(Hook.handler)=?,
      ~onReady: option(Hook.handler)=?,
      ~onValueUpdate: option(Hook.handler)=?,
      ~onYearChange: option(Hook.handler)=?,
      ~options: option(Js.t({..}) as 'options)=?,
      ~render: option((renderProps, ReactDOMRe.domRef) => React.element)=?,
      ~value: option(Value.case)=?,
      (),
    ) =>
    makePropsFlatpickr(
      ~className?,
      ~children?,
      ~defaultValue?,
      ~inputRef?,
      ~onChange?,
      ~onClose?,
      ~onDayCreate?,
      ~onDestroy?,
      ~onMonthChange?,
      ~onOpen?,
      ~onReady?,
      ~onValueUpdate?,
      ~onYearChange?,
      ~options?,
      ~render?,
      ~value=Belt.Option.map(value, Value.reduce),
      ()
    );

[@bs.module "react-flatpickr"]
external make: React.component('a) = "default";
