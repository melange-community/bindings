/* Common types */
type any;

/* Helpers */
external toAny : 'a => any = "%identity";

external toJsObj : any => Js.t({..}) = "%identity";

/* Types for Downshift API */
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
  "selectedItem": item,
};

type getA11yStatusMessage = a11yStatusMessageOptions => string;

type rootPropsOptions = {. "refKey": string};

type itemPropsOptions = {
  .
  "index": Js.Nullable.t(int),
  "item": any,
};

module ControllerStateAndHelpers = {
  type t;
  /* Getters */
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
  /* Actions */
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
  /* State */
  [@bs.get] external highlightedIndex : t => Js.Nullable.t(int) = "";
  [@bs.get] external inputValue : t => Js.Nullable.t(string) = "";
  [@bs.get] external isOpen : t => bool = "";
  [@bs.get] external selectedItem : t => item = "";
  let getItemProps = (t, ~item: any, ~index=?, ()) : any => {
    let itemPropsOpt = {
      "item": item,
      "index": Js.Nullable.fromOption(index),
    };
    extGetItemProps(t, itemPropsOpt);
  };
};

type stateChangeOptions = {
  .
  "type": string,
  "highlightedIndex": int,
  "inputValue": string,
  "isOpen": bool,
  "selectedItem": item,
};

type onChange = (any, ControllerStateAndHelpers.t) => unit;

type onSelect = (any, ControllerStateAndHelpers.t) => unit;

type onStateChange = (stateChangeOptions, ControllerStateAndHelpers.t) => unit;

type onInputValueChange = (string, ControllerStateAndHelpers.t) => unit;

type renderFunc = ControllerStateAndHelpers.t => ReasonReact.reactElement;

/* Expose the React component with the mapped props */
[@bs.module "downshift"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~defaultSelectedItem: option(any)=?,
      ~defaultHighlightedIndex: option(int)=?,
      ~defaultInputValue: option(string)=?,
      ~defaultIsOpen: option(bool)=?,
      ~itemToString: option(itemToString)=?,
      ~selectedItemChanged: option(selectedItemChanged)=?,
      ~getA11yStatusMessage: option(getA11yStatusMessage)=?,
      ~onChange: option(onChange)=?,
      ~onSelect: option(onSelect)=?,
      ~onStateChange: option(onStateChange)=?,
      ~onInputValueChange: option(onInputValueChange)=?,
      ~itemCount: option(int)=?,
      ~highlightedIndex: option(int)=?,
      ~inputValue: option(string)=?,
      ~isOpen: option(bool)=?,
      ~selectedItem: option(any)=?,
      ~render: renderFunc,
      ~id: option(string)=?,
      ~environment: option(Dom.window)=?,
      ~onOuterClick: option(unit => unit)=?,
      _children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "defaultSelectedItem":
        Js.Null_undefined.fromOption(defaultSelectedItem),
      "defaultHighlightedIndex":
        Js.Null_undefined.fromOption(defaultHighlightedIndex),
      "defaultInputValue": Js.Null_undefined.fromOption(defaultInputValue),
      "defaultIsOpen": Js.Null_undefined.fromOption(defaultIsOpen),
      "itemToString": Js.Null_undefined.fromOption(itemToString),
      "selectedItemChanged":
        Js.Null_undefined.fromOption(selectedItemChanged),
      "getA11yStatusMessage":
        Js.Null_undefined.fromOption(getA11yStatusMessage),
      "onChange": Js.Null_undefined.fromOption(onChange),
      "onSelect": Js.Null_undefined.fromOption(onSelect),
      "onStateChange": Js.Null_undefined.fromOption(onStateChange),
      "onInputValueChange": Js.Null_undefined.fromOption(onInputValueChange),
      "itemCount": Js.Null_undefined.fromOption(itemCount),
      "highlightedIndex": Js.Null_undefined.fromOption(highlightedIndex),
      "inputValue": Js.Null_undefined.fromOption(inputValue),
      "isOpen": Js.Null_undefined.fromOption(isOpen),
      "selectedItem": Js.Null_undefined.fromOption(selectedItem),
      "render": render,
      "id": Js.Null_undefined.fromOption(id),
      "environment": Js.Null_undefined.fromOption(environment),
      "onOuterClick": Js.Null_undefined.fromOption(onOuterClick),
    },
    [||],
  );

[@bs.module "downshift"]
external resetIdCounter : unit => unit = "resetIdCounter";