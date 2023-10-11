open ReactDropzone__Utils;

[@bs.deriving abstract]
type file = {
  lastModified: int,
  name: string,
  size: int,
  [@bs.as "type"] type_: string,
};

type onClick = ReactEvent.Mouse.t => unit;
type onKeyDown = ReactEvent.Keyboard.t => unit;
type onFocus = ReactEvent.Focus.t => unit;
type onBlur = ReactEvent.Focus.t => unit;
type onDragStart = ReactEvent.Mouse.t => unit;
type onDragEnter = ReactEvent.Mouse.t => unit;
type onDragOver = ReactEvent.Mouse.t => unit;
type onDragLeave = ReactEvent.Mouse.t => unit;
type ref = Js.nullable(Dom.element) => unit;

module Accept = {
  type t = [ | `single(string) | `many(list(string))];

  type js;

  external makeString: string => js = "%identity";
  external makeArray: array(string) => js = "%identity";

  let make =
    fun
    | `single(s) => s |> makeString
    | `many(m) => m |> Array.of_list |> makeArray;
};

module GetInputProps = {
  type onChange = ReactEvent.Form.t => unit;

  module Input = {
    [@bs.deriving abstract]
    type js = {
      [@bs.optional] refKey: string,
      [@bs.optional] onChange: onChange,
      [@bs.optional] onClick: onClick,
    };

    type t = {
      refKey: option(string),
      onChange: option(onChange),
      onClick: option(onClick),
    };
  };

  module Output = {
    [@bs.deriving abstract]
    type js = {
      [@bs.as "type"] type_: string,
      autoComplete: string,
      multiple: bool,
      onChange: onChange,
      onClick: onClick,
      tabIndex: int,
      style: ReactDOMRe.style,
      ref: ref,
    };

    type t = {
      type_: string,
      autoComplete: string,
      multiple: bool,
      onChange: onChange,
      onClick: onClick,
      tabIndex: int,
      style: ReactDOMRe.style,
      ref: ref,
    };

    let make = (js) => {
      type_: js->type_Get,
      autoComplete: js->autoCompleteGet,
      multiple: js->multipleGet,
      onChange: js->onChangeGet,
      onClick: js->onClickGet,
      tabIndex: js->tabIndexGet,
      style: js->styleGet,
      ref: js->refGet,
    };
  };

  type js = Input.js => Output.js;
  type t = (
    ~refKey: string=?,
    ~onChange: onChange=?,
    ~onClick: onClick=?,
    unit
  ) => Output.t;

  let make = (fn) => (
    ~refKey=?,
    ~onChange=?,
    ~onClick=?,
    ()
  ) => Input.js(
    ~refKey?,
    ~onChange?,
    ~onClick?,
    ()
  ) |> fn |> Output.make;
};

module GetRootProps = {
  type onDrop = ReactEvent.Mouse.t => unit;

  module Input = {
    [@bs.deriving abstract]
    type js = {
      [@bs.optional] refKey: string,
      [@bs.optional] onKeyDown: onKeyDown,
      [@bs.optional] onFocus: onFocus,
      [@bs.optional] onBlur: onBlur,
      [@bs.optional] onClick: onClick,
      [@bs.optional] onDragStart: onDragStart,
      [@bs.optional] onDragEnter: onDragEnter,
      [@bs.optional] onDragOver: onDragOver,
      [@bs.optional] onDragLeave: onDragLeave,
      [@bs.optional] onDrop: onDrop,
    };

    type t = {
      refKey: option(string),
      onKeyDown: option(onKeyDown),
      onFocus: option(onFocus),
      onBlur: option(onBlur),
      onClick: option(onClick),
      onDragStart: option(onDragStart),
      onDragEnter: option(onDragEnter),
      onDragOver: option(onDragOver),
      onDragLeave: option(onDragLeave),
      onDrop: option(onDrop),
    };
  };

  module Output = {
    [@bs.deriving abstract]
    type js = {
      onKeyDown: onKeyDown,
      onFocus: onFocus,
      onBlur: onBlur,
      onClick: onClick,
      onDragStart: onDragStart,
      onDragEnter: onDragEnter,
      onDragOver: onDragOver,
      onDragLeave: onDragLeave,
      onDrop: onDrop,
      tabIndex: int,
      ref: ref
    };

    type t = {
      onKeyDown: onKeyDown,
      onFocus: onFocus,
      onBlur: onBlur,
      onClick: onClick,
      onDragStart: onDragStart,
      onDragEnter: onDragEnter,
      onDragOver: onDragOver,
      onDragLeave: onDragLeave,
      onDrop: onDrop,
      tabIndex: int,
      ref: ref
    };

    let make = (js) => {
      onKeyDown: js->onKeyDownGet,
      onFocus: js->onFocusGet,
      onBlur: js->onBlurGet,
      onClick: js->onClickGet,
      onDragStart: js->onDragStartGet,
      onDragEnter: js->onDragEnterGet,
      onDragOver: js->onDragOverGet,
      onDragLeave: js->onDragLeaveGet,
      onDrop: js->onDropGet,
      tabIndex: js->tabIndexGet,
      ref: js->refGet,
    };
  }

  type js = Input.js => Output.js;
  type t = (
    ~refKey: string=?,
    ~onKeyDown: onKeyDown=?,
    ~onFocus: onFocus=?,
    ~onBlur: onBlur=?,
    ~onClick: onClick=?,
    ~onDragStart: onDragStart=?,
    ~onDragEnter: onDragEnter=?,
    ~onDragOver: onDragOver=?,
    ~onDragLeave: onDragLeave=?,
    ~onDrop: onDrop=?,
    unit
  ) => Output.t;

  let make = (fn) => (
    ~refKey=?,
    ~onKeyDown=?,
    ~onFocus=?,
    ~onBlur=?,
    ~onClick=?,
    ~onDragStart=?,
    ~onDragEnter=?,
    ~onDragOver=?,
    ~onDragLeave=?,
    ~onDrop=?,
    ()
  ) => Input.js(
    ~refKey?,
    ~onKeyDown?,
    ~onFocus?,
    ~onBlur?,
    ~onClick?,
    ~onDragStart?,
    ~onDragEnter?,
    ~onDragOver?,
    ~onDragLeave?,
    ~onDrop?,
    ()
  ) |> fn |> Output.make;
};

module Children = {
  module Input = {
    [@bs.deriving abstract]
    type js = {
      getRootProps: GetRootProps.js,
      getInputProps: GetInputProps.js,
      [@bs.as "open"] open_: unit => unit,
      isDragActive: bool,
      isDragAccept: bool,
      isDragReject: bool,
      isFocused: bool,
      acceptedFiles: array(FileReader.File.t),
      rejectedFiles: array(FileReader.File.t),
      draggedFiles: array(FileReader.File.t)
    };

    type t = {
      getRootProps: GetRootProps.t,
      getInputProps: GetInputProps.t,
      open_: unit => unit,
      isDragActive: bool,
      isDragAccept: bool,
      isDragReject: bool,
      isFocused: bool,
      acceptedFiles: array(FileReader.File.t),
      rejectedFiles: array(FileReader.File.t),
      draggedFiles: array(FileReader.File.t),
    };

    let make = (js) => {
      getRootProps: js->getRootPropsGet |> unary |> GetRootProps.make,
      getInputProps: js->getInputPropsGet |> unary |> GetInputProps.make,
      open_: js->open_Get,
      isDragActive: js->isDragActiveGet,
      isDragAccept: js->isDragAcceptGet,
      isDragReject: js->isDragRejectGet,
      isFocused: js->isFocusedGet,
      acceptedFiles: js->acceptedFilesGet,
      rejectedFiles: js->rejectedFilesGet,
      draggedFiles: js->draggedFilesGet,
    };
  };

  type t = Input.t => ReasonReact.reactElement;

  type js = Input.js => ReasonReact.reactElement;

  let make = (||>) (Input.make);
}

[@bs.module "react-dropzone"] [@react.component]
external make:
 (
  ~accept: Accept.js=?,
  ~disabled: bool=?,
  ~maxSize: int=?,
  ~minSize: int=?,
  ~multiple: bool=?,
  ~name: string=?,
  ~onBlur: onBlur=?,
  ~onClick: onClick=?,
  ~onDragEnter: onDragEnter=?,
  ~onDragLeave: onDragLeave=?,
  ~onDragOver: onDragOver=?,
  ~onDragStart: onDragStart=?,
  ~onDrop: (array(FileReader.File.t), array(FileReader.File.t)) => unit=?,
  ~onDropAccepted: ReactEvent.Mouse.t => unit=?,
  ~onDropRejected: ReactEvent.Mouse.t => unit=?,
  ~onFileDialogCancel: ReactEvent.Mouse.t => unit=?,
  ~onFocus: onFocus=?,
  ~onKeyDown: onKeyDown=?,
  ~preventDropOnDocument: bool=?,
  ~children: Children.js
 ) => React.element = "default";


let makeProps = (
  ~accept=?,
  ~disabled=?,
  ~maxSize=?,
  ~minSize=?,
  ~multiple=?,
  ~name=?,
  ~onBlur=?,
  ~onClick=?,
  ~onDragEnter=?,
  ~onDragLeave=?,
  ~onDragOver=?,
  ~onDragStart=?,
  ~onDrop=?,
  ~onDropAccepted=?,
  ~onDropRejected=?,
  ~onFileDialogCancel=?,
  ~onFocus=?,
  ~onKeyDown=?,
  ~preventDropOnDocument=?,
  ~children
) => makeProps(
  ~accept=?accept <$> Accept.make,
  ~disabled?,
  ~maxSize?,
  ~minSize?,
  ~multiple?,
  ~name?,
  ~onBlur?,
  ~onClick?,
  ~onDragEnter?,
  ~onDragLeave?,
  ~onDragOver?,
  ~onDragStart?,
  ~onDrop?,
  ~onDropAccepted?,
  ~onDropRejected?,
  ~onFileDialogCancel?,
  ~onFocus?,
  ~onKeyDown?,
  ~preventDropOnDocument?,
  ~children=Children.make(children)
);
