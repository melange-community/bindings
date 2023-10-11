module Types = PM_Types;

module EditorProps = PM_EditorProps;

module Decoration = PM_Decoration;

module NodeView = PM_NodeView;

type t = PM_Types.editorView;

module DecorationSet = {
  type t = Types.decorationSet;

  [@bs.module "prosemirror-view"] [@bs.scope "DecorationSet"]
  external create: (~doc: PM_Model.Node.t, ~decorations: array(Decoration.t)) => t = "create";

  [@bs.module "prosemirror-view"] [@bs.scope "DecorationSet"] external empty: t = "empty";

  [@bs.send]
  external find:
    (t, ~start: int=?, ~end_: int=?, ~predicate: Decoration.spec => bool=?, unit) =>
    array(Decoration.t) =
    "find";

  [@bs.send]
  external map:
    (
      t,
      ~mapping: PM_Transform.Mapping.t,
      ~doc: PM_Model.Node.t,
      ~option: {. "onRemove": Decoration.spec => unit}=?,
      unit
    ) =>
    t =
    "map";

  [@bs.send]
  external add: (t, ~doc: PM_Model.Node.t, ~decorations: array(Decoration.t)) => t = "add";

  [@bs.send] external remove: (t, ~decorations: array(Decoration.t)) => t = "remove";
};

module DirectEditorProps = {
  type pos = {
    .
    "top": int,
    "right": int,
    "bottom": int,
    "left": int,
  };

  type domEventHandler = (~view: Types.editorView, ~event: Dom.event) => bool;

  type keyboardEventHandler = (~view: Types.editorView, ~event: Dom.keyboardEvent) => bool;

  type mouseEventOnHandler =
    (
      ~view: Types.editorView,
      ~pos: int,
      ~node: PM_Model.Node.t,
      ~nodePos: int,
      ~event: Dom.mouseEvent,
      ~direct: bool
    ) =>
    bool;

  type mouseEventHandler = (~view: Types.editorView, ~pos: int, ~event: Dom.mouseEvent) => bool;

  type dropHandler =
    (~view: Types.editorView, ~event: Dom.event, ~slice: PM_Model.Slice.t, ~moved: bool) => bool;

  type createSelectionBetween =
    (~view: Types.editorView, ~anchor: PM_Model.ResolvedPos.t, ~head: PM_Model.ResolvedPos.t) =>
    option(PM_State.Selection.t);

  type nodeViewInit =
    (
      ~node: PM_Model.Node.t,
      ~view: Types.editorView,
      ~getPos: unit => int,
      ~decorations: array(Decoration.t)
    ) =>
    NodeView.t;

  type pasteHandler =
    (~view: Types.editorView, ~event: Dom.event, ~slice: PM_Model.Slice.t) => bool;

  module Attributes = PM_EditorProps.Attributes;

  module ScrollThreshold = PM_EditorProps.ScrollThreshold;

  module ScrollMargin = PM_EditorProps.ScrollMargin;

  module type DispatchTransaction = {
    type t;
    let make: ((Types.editorView, PM_State.Transaction.t) => unit) => t;
  };

  module DispatchTransaction: DispatchTransaction = {
    [@unboxed]
    type t =
      | Any([@bs.this] ((Types.editorView, PM_State.Transaction.t) => unit)): t;

    let make: ((Types.editorView, PM_State.Transaction.t) => unit) => t =
      fn => Any([@bs.this] (a, b) => fn(a, b));
  };

  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    handleDOMEvents: Js.Dict.t(domEventHandler),
    [@bs.optional]
    handleKeyDown: keyboardEventHandler,
    [@bs.optional]
    handleKeyPress: keyboardEventHandler,
    [@bs.optional]
    handleTextInput: (~view: Types.editorView, ~from: int, ~to_: int, ~text: string) => bool,
    [@bs.optional]
    handleClickOn: mouseEventOnHandler,
    [@bs.optional]
    handleClick: mouseEventHandler,
    [@bs.optional]
    handleDoubleClickOn: mouseEventOnHandler,
    [@bs.optional]
    handleDoubleClick: mouseEventHandler,
    [@bs.optional]
    handleTripleClickOn: mouseEventOnHandler,
    [@bs.optional]
    handleTripleClick: mouseEventHandler,
    [@bs.optional]
    handlePaste: pasteHandler,
    [@bs.optional]
    handleDrop: dropHandler,
    [@bs.optional]
    handleScrollToSelection: Types.editorView => bool,
    [@bs.optional]
    createSelectionBetween,
    [@bs.optional]
    domParser: PM_Model.DOMParser.t,
    [@bs.optional]
    transformPastedHTML: (~html: string) => string,
    [@bs.optional]
    clipboardParser: PM_Model.DOMParser.t,
    [@bs.optional]
    transformPastedText: (~text: string) => string,
    [@bs.optional]
    clipboardTextParser: (~text: string, ~context: PM_Model.ResolvedPos.t) => PM_Model.Slice.t,
    [@bs.optional]
    transformPasted: PM_Model.Slice.t => PM_Model.Slice.t,
    [@bs.optional]
    nodeViews: Js.Dict.t(nodeViewInit),
    [@bs.optional]
    clipboardSerializer: PM_Model.DOMSerializer.t,
    [@bs.optional]
    clipboardTextSerializer: PM_Model.Slice.t => string,
    [@bs.optional]
    decorations: PM_State.EditorState.t => DecorationSet.t,
    [@bs.optional]
    editable: PM_State.EditorState.t => bool,
    [@bs.optional]
    attributes: Attributes.t,
    [@bs.optional]
    scrollThreshold: ScrollThreshold.t,
    [@bs.optional]
    scrollMargin: ScrollMargin.t,
    state: PM_State.EditorState.t,
    [@bs.optional]
    dispatchTransaction: DispatchTransaction.t,
  };

  let make =
      (
        ~state: PM_State.EditorState.t,
        ~handleDOMEvents: option(Js.Dict.t(domEventHandler))=?,
        ~handleKeyDown: option(keyboardEventHandler)=?,
        ~handleKeyPress: option(keyboardEventHandler)=?,
        ~handleTextInput:
           option((~view: Types.editorView, ~from: int, ~to_: int, ~text: string) => bool)=?,
        ~handleClickOn: option(mouseEventOnHandler)=?,
        ~handleClick: option(mouseEventHandler)=?,
        ~handleDoubleClickOn: option(mouseEventOnHandler)=?,
        ~handleDoubleClick: option(mouseEventHandler)=?,
        ~handleTripleClickOn: option(mouseEventOnHandler)=?,
        ~handleTripleClick: option(mouseEventHandler)=?,
        ~handlePaste: option(pasteHandler)=?,
        ~handleDrop: option(dropHandler)=?,
        ~handleScrollToSelection: option(Types.editorView => bool)=?,
        ~createSelectionBetween: option(createSelectionBetween)=?,
        ~domParser: option(PM_Model.DOMParser.t)=?,
        ~transformPastedHTML: option((~html: string) => string)=?,
        ~clipboardParser: option(PM_Model.DOMParser.t)=?,
        ~transformPastedText: option((~text: string) => string)=?,
        ~clipboardTextParser:
           option((~text: string, ~context: PM_Model.ResolvedPos.t) => PM_Model.Slice.t)=?,
        ~transformPasted: option(PM_Model.Slice.t => PM_Model.Slice.t)=?,
        ~nodeViews: option(Js.Dict.t(nodeViewInit))=?,
        ~clipboardSerializer: option(PM_Model.DOMSerializer.t)=?,
        ~clipboardTextSerializer: option(PM_Model.Slice.t => string)=?,
        ~decorations: option(PM_State.EditorState.t => DecorationSet.t)=?,
        ~editable: option(PM_State.EditorState.t => bool)=?,
        ~attributes: option(Attributes.t)=?,
        ~scrollThreshold: option(ScrollThreshold.t)=?,
        ~scrollMargin: option(ScrollMargin.t)=?,
        ~dispatchTransaction: option((Types.editorView, PM_State.Transaction.t) => unit)=?,
        (),
      ) =>
    t(
      ~handleDOMEvents?,
      ~handleKeyDown?,
      ~handleKeyPress?,
      ~handleTextInput?,
      ~handleClickOn?,
      ~handleClick?,
      ~handleDoubleClickOn?,
      ~handleDoubleClick?,
      ~handleTripleClickOn?,
      ~handleTripleClick?,
      ~handlePaste?,
      ~handleDrop?,
      ~handleScrollToSelection?,
      ~createSelectionBetween?,
      ~domParser?,
      ~transformPastedHTML?,
      ~clipboardParser?,
      ~transformPastedText?,
      ~clipboardTextParser?,
      ~transformPasted?,
      ~nodeViews?,
      ~clipboardSerializer?,
      ~clipboardTextSerializer?,
      ~decorations?,
      ~editable?,
      ~attributes?,
      ~scrollThreshold?,
      ~scrollMargin?,
      ~state,
      ~dispatchTransaction=?dispatchTransaction->Belt.Option.map(DispatchTransaction.make),
      (),
    );
};

[@bs.module "prosemirror-view"] [@bs.new]
external make:
  ([@bs.unwrap] [ | `Node(Dom.element) | `Fn(Dom.node => unit)], DirectEditorProps.t) => t =
  "EditorView";

[@bs.module "prosemirror-view"] [@bs.new]
external makeWithNull: ([@bs.as {json|null|json}] _, DirectEditorProps.t) => t = "EditorView";

[@bs.get] external state: t => PM_State.EditorState.t = "state";

[@bs.get] external dom: t => Dom.element = "dom";

[@bs.send] [@bs.return nullable]
external dragging:
  t =>
  option({
    .
    "slice": PM_Model.Slice.t,
    "move": bool,
  }) =
  "dragging";

[@bs.send] external props: t => DirectEditorProps.t = "props";

[@bs.send] external update: (t, DirectEditorProps.t) => unit = "update";

[@bs.send] external setProps: (t, DirectEditorProps.t) => unit = "setProps";

/* TODO: A better solution for props should be found */
[@bs.send] external someProp: (t, ~propName: string, ~f: 'a => 'a) => unit = "someProp";

[@bs.send] external hasFocus: t => bool = "hasFocus";

[@bs.send] external focus: t => unit = "focus";

[@bs.get] external root: t => Dom.document = "root";

[@bs.send] [@bs.return nullable]
external posAtCoords:
  (
    t,
    {
      .
      "left": int,
      "top": int,
    }
  ) =>
  option({
    .
    "pos": int,
    "inside": int,
  }) =
  "posAtCoords";

[@bs.send]
external coordsAtPos:
  (t, int) =>
  {
    .
    "left": int,
    "right": int,
    "top": int,
    "bottom": int,
  } =
  "coordsAtPos";

[@bs.send]
external domAtPos:
  (t, int) =>
  {
    .
    "node": Dom.node,
    "offset": int,
  } =
  "domAtPos";

[@bs.send] [@bs.return nullable] external nodeDOM: (t, int) => option(Dom.node) = "nodeDOM";

[@bs.send]
external posAtDOM: (t, ~node: Dom.element, ~offset: int, ~bias: int=?, unit) => int = "posAtDOM";

[@bs.send]
external endOfTextblock:
  (
    t,
    ~dir: [@bs.string] [ | `up | `down | `left | `right | `forward | `backward],
    ~state: PM_State.EditorState.t=?,
    unit
  ) =>
  bool =
  "endOfTextblock";

/* Update the editor's state prop, without touching any of the other props. */
[@bs.send] external updateState: (t, PM_State.EditorState.t) => unit = "updateState";

/* Removes the editor from the DOM and destroys all node views. */
[@bs.send] external destroy: t => unit = "destroy";

[@bs.send] external dispatch: (t, PM_State.Transaction.t) => unit = "dispatch";
