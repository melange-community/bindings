type any;

external toAny : 'a => any = "%identity";

external toJsObj : any => Js.t({..}) = "%identity";

type item = any;

type otherStateToSet = Js.Dict.t(string);

type cb = unit => unit;

type itemToString = item => string;

type selectedItemChanged = (item, item) => bool;

type a11yStatusMessageOptions = {
  .
  "highlightedIndex": option(int),
  "highlightedValue": any,
  "inputValue": string,
  "isOpen": bool,
  "itemToString": itemToString,
  "previousResultCount": int,
  "resultCount": int,
  "selectedItem": item
};

type getA11yStatusMessage = a11yStatusMessageOptions => string;

type rootPropsOptions = {. "refKey": string};

type itemPropsOptions = {
  .
  "index": Js.Nullable.t(int),
  "item": any
};

module ControllerStateAndHelpers: {
  type t;
  [@bs.send] external getRootProps : (t, rootPropsOptions) => any = "";
  [@bs.send]
  external getButtonProps :
    (t, ~options: ReactDOMRe.reactDOMProps=?, unit) => any =
    "";
  [@bs.send]
  external getLabelProps :
    (t, ~options: ReactDOMRe.reactDOMProps=?, unit) => any =
    "";
  [@bs.send]
  external getInputProps :
    (t, ~options: ReactDOMRe.reactDOMProps=?, unit) => any =
    "";
  [@bs.send] external extGetItemProps : (t, itemPropsOptions) => any = "getItemProps";
  [@bs.send]
  external itemPropsOptions : (t, ~options: itemPropsOptions) => any = "";
  [@bs.send] external openMenu : (t, ~cb: cb=?, unit) => unit = "";
  [@bs.send] external closeMenu : (t, ~cb: cb=?, unit) => unit = "";
  [@bs.send]
  external toggleMenu :
    (t, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) => unit =
    "";
  [@bs.send]
  external reset :
    (t, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) => unit =
    "";
  [@bs.send]
  external selectItem :
    (t, ~item: item, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) =>
    unit =
    "";
  [@bs.send]
  external selectItemAtIndex :
    (t, ~index: int, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) =>
    unit =
    "";
  [@bs.send]
  external selectHighlightedItem :
    (t, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) => unit =
    "";
  [@bs.send]
  external setHighlightedIndex :
    (t, ~index: int, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) =>
    unit =
    "";
  [@bs.send] external clearSelection : (t, ~cb: cb=?, unit) => unit = "";
  [@bs.send] external clearItems : (t, unit) => unit = "";
  [@bs.send] external itemToString : (t, item) => unit = "";
  [@bs.get] external highlightedIndex : t => Js.Nullable.t(int) = "";
  [@bs.get] external inputValue : t => Js.Nullable.t(string) = "";
  [@bs.get] external isOpen : t => bool = "";
  [@bs.get] external selectedItem : t => item = "";
  let getItemProps: (t, ~item: any, ~index: int=?, unit) => any;
};

type stateChangeOptions = {
  .
  "type": string,
  "highlightedIndex": int,
  "inputValue": string,
  "isOpen": bool,
  "selectedItem": item
};

type onChange = (any, ControllerStateAndHelpers.t) => unit;

type onSelect = (any, ControllerStateAndHelpers.t) => unit;

type onStateChange = (stateChangeOptions, ControllerStateAndHelpers.t) => unit;

type onInputValueChange = (string, ControllerStateAndHelpers.t) => unit;

type renderFunc = ControllerStateAndHelpers.t => ReasonReact.reactElement;

let make:
  (
    ~defaultSelectedItem: any=?,
    ~defaultHighlightedIndex: int=?,
    ~defaultInputValue: string=?,
    ~defaultIsOpen: bool=?,
    ~itemToString: itemToString=?,
    ~selectedItemChanged: selectedItemChanged=?,
    ~getA11yStatusMessage: getA11yStatusMessage=?,
    ~onChange: onChange=?,
    ~onSelect: onSelect=?,
    ~onStateChange: onStateChange=?,
    ~onInputValueChange: onInputValueChange=?,
    ~itemCount: int=?,
    ~highlightedIndex: int=?,
    ~inputValue: string=?,
    ~isOpen: bool=?,
    ~selectedItem: any=?,
    ~render: renderFunc,
    ~id: string=?,
    ~environment: Dom.window=?,
    ~onOuterClick: unit => unit=?,
    'a
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless
  );

[@bs.module "downshift"]
external resetIdCounter : unit => unit = "resetIdCounter";