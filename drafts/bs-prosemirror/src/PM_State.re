module Model = PM_Model;

module ResolvedPos = Model.ResolvedPos;

module Transform = PM_Transform;

module Types = PM_Types;

module EditorProps = PM_EditorProps;

module SelectionRange = {
  type t;

  [@bs.module "prosemirror-state"] [@bs.new]
  external make: (~resolvedFrom: Model.ResolvedPos.t, ~resolvedTo: Model.ResolvedPos.t) => t =
    "SelectionRange";

  [@bs.get] external resolvedFrom: t => Model.ResolvedPos.t = "$from";

  [@bs.get] external resolvedTo: t => Model.ResolvedPos.t = "$to";
};

module SelectionBookmark = {
  type t;

  [@bs.send] external map: (t, ~mapping: Transform.Mapping.t) => t = "map";

  [@bs.send] external resolve: (t, ~doc: Model.Node.t) => Types.selection = "resolve";
};

module SelectionKind = {
  type selectionClass;

  [@bs.module "prosemirror-state"] external nodeSelection: selectionClass = "NodeSelection";

  [@bs.module "prosemirror-state"] external textSelection: selectionClass = "TextSelection";

  [@bs.module "prosemirror-state"] external allSelection: selectionClass = "AllSelection";

  let isKind: (Types.selection, selectionClass) => bool = [%bs.raw
    {|
        function (selection, typ) {
          return selection instanceof typ
        }
      |}
  ];

  let selectionToNodeSelection = a =>
    if (isKind(a, nodeSelection)) {
      let ns: Types.nodeSelection = Obj.magic(a);
      Some(ns);
    } else {
      None;
    };

  let selectionToTextSelection = a =>
    if (isKind(a, textSelection)) {
      let ns: Types.textSelection = Obj.magic(a);
      Some(ns);
    } else {
      None;
    };

  let selectionToAllSelection = a =>
    if (isKind(a, allSelection)) {
      let ns: Types.allSelection = Obj.magic(a);
      Some(ns);
    } else {
      None;
    };

  let nodeSelectionToSelection: Types.nodeSelection => Types.selection = a => Obj.magic(a);

  let textSelectionToSelection: Types.textSelection => Types.selection = a => Obj.magic(a);

  let allSelectionToSelection: Types.allSelection => Types.selection = a => Obj.magic(a);

  type constructor;

  [@bs.get] external constructor: Types.selection => constructor = "constructor";

  [@bs.get] external name: constructor => string = "name";

  let className = selection => selection->constructor->name;

  external toNodeSelection: Types.selection => Types.nodeSelection = "%identity";

  external toTextSelection: Types.selection => Types.textSelection = "%identity";

  external toAllSelection: Types.selection => Types.allSelection = "%identity";

  type t = [
    | `NodeSelection(Types.nodeSelection)
    | `TextSelection(Types.textSelection)
    | `AllSelection(Types.allSelection)
  ];

  let classify = (selection: Types.selection): [> t] =>
    switch (selection->className) {
    | "NodeSelection" => `NodeSelection(selection->toNodeSelection)
    | "TextSelection" => `TextSelection(selection->toTextSelection)
    | "AllSelection" => `AllSelection(selection->toAllSelection)
    | _ => failwith("Unknown PM.State.Selection subclass")
    };

  let classifyCustom =
      (selection: Types.selection, ~custom: (Types.selection, string) => option([> t] as 'a))
      : ([> t] as 'a) =>
    try (classify(selection)) {
    | Failure(_) as f =>
      switch (custom(selection, selection->className)) {
      | Some(selectionSubclass) => selectionSubclass
      | None => raise(f)
      }
    };
};

module Selection = {
  type t = Types.selection;

  module type T = {
    type t;

    let ranges: t => array(SelectionRange.t);

    let resolvedAnchor: t => Model.ResolvedPos.t;

    let resolvedHead: t => Model.ResolvedPos.t;

    let anchor: t => int;

    let head: t => int;

    let from: t => int;

    let to_: t => int;

    let resolvedFrom: t => Model.ResolvedPos.t;

    let resolvedTo: t => Model.ResolvedPos.t;

    let empty: t => bool;

    let eq: (t, t) => bool;

    let map: (t, ~doc: Model.Node.t, ~mapping: Transform.Mapping.t) => t;

    let content: t => Model.Slice.t;

    let replace: (t, ~tr: Types.transaction, ~content: Model.Slice.t=?, unit) => unit;

    let replaceWith: (t, ~tr: Types.transaction, ~node: Model.Node.t) => unit;

    let toJSON: t => Js.Json.t;

    let getBookmark: t => SelectionBookmark.t;

    let visible: t => bool;

    let findFrom:
      (~resolvedPos: Model.ResolvedPos.t, ~dir: int, ~textOnly: bool=?, unit) => option(t);

    let near: (~resolvedPos: Model.ResolvedPos.t, ~bias: int=?, unit) => option(t);

    let atStart: (~doc: Model.Node.t) => t;

    let atEnd: (~doc: Model.Node.t) => t;

    let fromJSON: (~doc: Model.Node.t, ~json: Js.Json.t) => t;

    let jsonID: (~id: string, ~selectionClass: t) => t;
  };

  module Make = (M: {type t;}) : (T with type t := M.t) => {
    type t = M.t;

    [@bs.get] external ranges: t => array(SelectionRange.t) = "ranges";

    [@bs.get] external resolvedAnchor: t => Model.ResolvedPos.t = "$anchor";

    [@bs.get] external resolvedHead: t => Model.ResolvedPos.t = "$head";

    [@bs.get] external anchor: t => int = "anchor";

    [@bs.get] external head: t => int = "head";

    [@bs.get] external from: t => int = "from";

    [@bs.get] external to_: t => int = "to";

    [@bs.get] external resolvedFrom: t => Model.ResolvedPos.t = "$from";

    [@bs.get] external resolvedTo: t => Model.ResolvedPos.t = "$to";

    [@bs.get] external empty: t => bool = "empty";

    [@bs.send] external eq: (t, t) => bool = "eq";

    [@bs.send] external map: (t, ~doc: Model.Node.t, ~mapping: Transform.Mapping.t) => t = "map";

    [@bs.send] external content: t => Model.Slice.t = "content";

    [@bs.send]
    external replace: (t, ~tr: Types.transaction, ~content: Model.Slice.t=?, unit) => unit =
      "replace";

    [@bs.send]
    external replaceWith: (t, ~tr: Types.transaction, ~node: Model.Node.t) => unit = "replaceWith";

    [@bs.send] external toJSON: t => Js.Json.t = "toJSON";

    [@bs.send] external getBookmark: t => SelectionBookmark.t = "getBookmark";

    [@bs.get] external visible: t => bool = "visible";

    [@bs.return nullable] [@bs.module "prosemirror-state"] [@bs.scope "Selection"]
    external findFrom:
      (~resolvedPos: Model.ResolvedPos.t, ~dir: int, ~textOnly: bool=?, unit) => option(t) =
      "findFrom";

    [@bs.return nullable] [@bs.module "prosemirror-state"] [@bs.scope "Selection"]
    external near: (~resolvedPos: Model.ResolvedPos.t, ~bias: int=?, unit) => option(t) = "near";

    [@bs.module "prosemirror-state"] [@bs.scope "Selection"]
    external atStart: (~doc: Model.Node.t) => t = "atStart";

    [@bs.module "prosemirror-state"] [@bs.scope "Selection"]
    external atEnd: (~doc: Model.Node.t) => t = "atEnd";

    [@bs.module "prosemirror-state"] [@bs.scope "Selection"]
    external fromJSON: (~doc: Model.Node.t, ~json: Js.Json.t) => t = "fromJSON";

    /* REMINDER -> The type of stepClass is constructor<Step> however I am not sure how to model that
        Alexey: I checked a couple of "wrappers" for prosemirror. At least at this point I couldn't
        find any usage of this function anywhere. static jsonID(id: string, selectionClass:
        constructor<Selection>)
        To be able to deserialize selections from JSON, custom selection classes must register
        themselves with an ID string, so that they can be disambiguated.
        Try to pick something that's unlikely to clash with classes from other modules.
       */
    [@bs.module "prosemirror-state"] [@bs.scope "Selection"]
    external jsonID: (~id: string, ~selectionClass: t) => t = "jsonID";
  };

  include Make({
    type nonrec t = t;
  });

  [@bs.module "prosemirror-state"] [@bs.new]
  external make:
    (
      ~resolvedAnchor: Model.ResolvedPos.t,
      ~resolvedHead: Model.ResolvedPos.t,
      ~ranges: array(SelectionRange.t)=?,
      unit
    ) =>
    t =
    "Selection";

  let toNodeSelection = SelectionKind.selectionToNodeSelection;

  let toTextSelection = SelectionKind.selectionToTextSelection;

  let toAllSelection = SelectionKind.selectionToAllSelection;

  let fromNodeSelection = SelectionKind.nodeSelectionToSelection;

  let fromTextSelection = SelectionKind.textSelectionToSelection;

  let fromAllSelection = SelectionKind.allSelectionToSelection;

  let classify = SelectionKind.classify;

  let classifyCustom = SelectionKind.classifyCustom;
};

module TextSelection = {
  type t = Types.textSelection;

  include Selection.Make({
    type nonrec t = t;
  });

  [@bs.get] [@bs.return nullable]
  external resolvedCursor: t => option(Model.ResolvedPos.t) = "$cursor";

  [@bs.module "prosemirror-state"] [@bs.new]
  external make:
    (~resolvedAnchor: Model.ResolvedPos.t, ~resolvedHead: Model.ResolvedPos.t=?, unit) => t =
    "TextSelection";

  [@bs.module "prosemirror-state"] [@bs.scope "TextSelection"]
  external create: (~doc: Model.Node.t, ~anchor: int, ~head: int=?, unit) => t = "create";

  [@bs.module "prosemirror-state"] [@bs.scope "TextSelection"]
  external between:
    (
      ~resolvedAnchor: Model.ResolvedPos.t,
      ~resolvedHead: Model.ResolvedPos.t,
      ~bias: int=?,
      unit
    ) =>
    Selection.t =
    "between";

  let fromSelection = SelectionKind.selectionToTextSelection;
};

module NodeSelection = {
  type t = Types.nodeSelection;

  include Selection.Make({
    type nonrec t = t;
  });

  [@bs.module "prosemirror-state"] [@bs.new]
  external make: Model.ResolvedPos.t => t = "NodeSelection";

  [@bs.get] external node: t => Model.Node.t = "node";

  [@bs.module "prosemirror-state"] [@bs.scope "NodeSelection"]
  external create: (~doc: Model.Node.t, ~from: int) => t = "create";

  [@bs.module "prosemirror-state"] [@bs.scope "NodeSelection"]
  external isSelectable: Model.Node.t => bool = "isSelectable";

  let fromSelection = SelectionKind.selectionToNodeSelection;
};

module AllSelection = {
  type t = Types.allSelection;

  include Selection.Make({
    type nonrec t = t;
  });

  [@bs.module "prosemirror-state"] [@bs.new]
  external make: (~doc: Model.Node.t) => t = "AllSelection";

  let fromSelection = SelectionKind.selectionToAllSelection;
};

module EditorState = {
  type t = Types.editorState;

  module Config = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      schema: Model.Schema.t,
      [@bs.optional]
      doc: Model.Node.t,
      [@bs.optional]
      selection: Selection.t,
      [@bs.optional]
      storedMarks: array(Model.Mark.t),
      [@bs.optional]
      plugins: array(Types.untypedPlugin),
    };
    let make = t;
  };

  [@bs.get] external doc: t => Model.Node.t = "doc";

  [@bs.get] external selection: t => Selection.t = "selection";

  [@bs.return nullable] [@bs.get]
  external storedMarks: t => option(array(Model.Mark.t)) = "storedMarks";

  [@bs.get] external schema: t => Model.Schema.t = "schema";

  [@bs.get] external plugins: t => array(Types.untypedPlugin) = "plugins";

  [@bs.send] external apply: (t, Types.transaction) => t = "apply";

  [@bs.send]
  external applyTransaction:
    (t, Types.transaction) =>
    {
      .
      "state": t,
      "transactions": array(Types.transaction),
    } =
    "applyTransaction";

  [@bs.get] external tr: t => Types.transaction = "tr";

  [@bs.send] external reconfigure: (t, Config.t) => t = "reconfigure";

  [@bs.send]
  external toJSONWithPluginFields: (t, Js.Dict.t(Types.untypedPlugin)) => Js.Json.t =
    "toJSONWithPluginFields";

  /**
  The `space` argument is equivalent to the same argument
  in [JSON.stringify](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/JSON/stringify#Syntax)
  */
  [@bs.send]
  external toJSON:
    (t, ~space: [@bs.unwrap] [ | `String(string) | `Int(int)]=?, unit) => Js.Json.t =
    "toJSON";

  [@bs.module "prosemirror-state"] [@bs.scope "EditorState"]
  external create: Config.t => t = "create";

  [@bs.module "prosemirror-state"] [@bs.scope "EditorState"]
  external fromJSON:
    (
      ~config: Config.t,
      ~json: Js.Json.t,
      ~pluginFields: Js.Dict.t(Types.untypedPlugin)=?,
      unit
    ) =>
    t =
    "fromJSON";
};

module PluginKey = {
  type t('a);

  [@bs.module "prosemirror-state"] [@bs.new]
  external make: (~name: string=?, unit) => t('a) = "PluginKey";

  [@bs.return nullable] [@bs.send]
  external get: (t('a), Types.editorState) => option(Types.plugin('a)) = "get";

  [@bs.send] external getState: (t('a), Types.editorState) => option('a) = "getState";
};

module StateField = {
  [@bs.deriving abstract]
  type t('a) = {
    init: (~config: EditorState.Config.t, ~instance: Types.editorState) => 'a,
    apply:
      (
        ~tr: Types.transaction,
        ~value: 'a,
        ~oldState: Types.editorState,
        ~newState: Types.editorState
      ) =>
      'a,
    [@bs.optional]
    toJSON: (~value: 'a) => Js.Json.t,
    [@bs.optional]
    fromJSON: (~config: EditorState.Config.t, ~value: Js.Json.t, ~state: Types.editorState) => 'a,
  };
  let make = t;
};

module PluginSpec = {
  module View = {
    type update = (Types.editorView, Types.editorState) => unit;

    type destroy = unit => unit;

    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      update,
      [@bs.optional]
      destroy,
    };

    let make = t;
  };

  [@bs.deriving abstract]
  type t('a) = {
    [@bs.optional]
    props: EditorProps.t,
    [@bs.optional]
    state: StateField.t('a),
    [@bs.optional]
    key: PluginKey.t('a),
    [@bs.optional]
    view: Types.editorView => View.t,
    [@bs.optional]
    filterTransaction: (Types.transaction, Types.editorState) => bool,
    [@bs.optional]
    appendTransaction:
      (
        ~transanctions: array(Types.transaction),
        ~oldState: Types.editorState,
        ~newState: Types.editorState
      ) =>
      Js.Nullable.t(Types.transaction),
    [@bs.optional]
    historyPreserveItems: bool,
  };

  let make = t;
};

module Plugin = {
  type t('a) = Types.plugin('a);

  [@bs.module "prosemirror-state"] [@bs.new]
  external make: (~spec: PluginSpec.t('a)) => Types.plugin('a) = "Plugin";

  [@bs.module "prosemirror-state"] [@bs.new]
  external makeUntyped: (~spec: PluginSpec.t('a)) => Types.untypedPlugin = "Plugin";

  external toUntyped: t('a) => Types.untypedPlugin = "%identity";

  external fromUntyped: Types.untypedPlugin => t('a) = "%identity";

  [@bs.get] external props: t('a) => EditorProps.t = "props";

  [@bs.get] external spec: t('a) => PluginSpec.t('a) = "spec";

  [@bs.send] external getState: (t('a), ~state: Types.editorState) => 'a = "getState";
};

module Transaction = {
  type t = Types.transaction;

  include PM_Transform.Transform.Make({
    type nonrec t = t;
  });

  [@bs.get] external time: t => float = "time";

  [@bs.return nullable] [@bs.get]
  external storedMarks: t => option(array(Model.Mark.t)) = "storedMarks";

  [@bs.get] external selection: t => Selection.t = "selection";

  [@bs.send] external setSelection: (t, Selection.t) => t = "setSelection";

  [@bs.get] external selectionSet: t => bool = "selectionSet";

  [@bs.send]
  external setStoredMarks: (t, ~marks: array(Model.Mark.t)=?, unit) => t = "setStoredMarks";

  [@bs.send] external addStoredMark: (t, ~mark: Model.Mark.t) => t = "addStoredMark";

  [@bs.send] external ensureMarks: (t, array(PM_Model.Mark.t)) => t = "ensureMarks";

  [@bs.send]
  external removeStoredMark:
    (t, ~markOrMarkType: [@bs.unwrap] [ | `Mark(Model.Mark.t) | `MarkType(Model.MarkType.t)]) =>
    t =
    "removeStoredMark";

  [@bs.get] external storedMarksSet: t => bool = "storedMarksSet";

  [@bs.send] external setTime: (t, int) => t = "setTime";

  [@bs.send] external replaceSelection: (t, Model.Slice.t) => t = "replaceSelection";

  [@bs.send]
  external replaceSelectionWith: (t, ~node: Model.Node.t, ~inheritMarks: bool=?, unit) => t =
    "replaceSelectionWith";

  [@bs.send] external deleteSelection: t => t = "deleteSelection";

  [@bs.send]
  external insertText: (t, ~text: string, ~from: int=?, ~to_: int=?, unit) => t = "insertText";

  [@bs.get] external isGeneric: t => bool = "isGeneric";

  [@bs.send] external scrollIntoView: t => t = "scrollIntoView";

  [@bs.get] external scrolledIntoView: t => bool = "scrolledIntoView";

  module Meta = {
    module type T = {
      type v;

      let set:
        (
          t,
          ~key: [ | `String(string) | `Plugin(Plugin.t('a)) | `PluginKey(PluginKey.t('a))],
          ~value: v
        ) =>
        t;

      let get:
        (
          t,
          ~key: [ | `String(string) | `Plugin(Plugin.t('a)) | `PluginKey(PluginKey.t('a))]
        ) =>
        option(v);
    };

    module Make = (M: {type v;}) : (T with type v := M.v) => {
      type v = M.v;

      [@bs.send]
      external set:
        (
          t,
          ~key: [@bs.unwrap] [
                  | `String(string)
                  | `Plugin(Plugin.t('a))
                  | `PluginKey(PluginKey.t('a))
                ],
          ~value: v
        ) =>
        t =
        "setMeta";

      [@bs.send] [@bs.return nullable]
      external get:
        (
          t,
          ~key: [@bs.unwrap] [
                  | `String(string)
                  | `Plugin(Plugin.t('a))
                  | `PluginKey(PluginKey.t('a))
                ]
        ) =>
        option(v) =
        "getMeta";
    };
  };
};
