module Transform = PM_Transform;

/** Represents a selected range in a document. */
module SelectionRange: {
  type t;

  let make: (~resolvedFrom: PM_Model.ResolvedPos.t, ~resolvedTo: PM_Model.ResolvedPos.t) => t;

  /** The lower bound of the range. $from */
  let resolvedFrom: t => PM_Model.ResolvedPos.t;

  /** The upper bound of the range. $to */
  let resolvedTo: t => PM_Model.ResolvedPos.t;
};

module SelectionBookmark: {
  /** A lightweight, document-independent representation of a selection. You can define a custom
    bookmark type for a custom selection class to make the history handle it well. */
  type t;

  /** Map the bookmark through a set of changes. */
  let map: (t, ~mapping: Transform.Mapping.t) => t;

  /** Resolve the bookmark to a real selection again. This may need to do some error checking and may
  fall back to a default (usually TextSelection.between) if mapping made the bookmark invalid. */
  let resolve: (t, ~doc: PM_Model.Node.t) => PM_Types.selection;
};

/** ProseMirror libraries rely on reflection (instanceof) for distinguishing a particular Selection
  subclass. As we don't have a straightforward reflection mechanism we have to rely on some "dirty"
  tricks to figure out which subclass we are dealing with. It's implemented using converters that
  return an optional subclass by using javascript reflection underneath */
module SelectionKind: {
  type selectionClass;

  let nodeSelection: selectionClass;

  let textSelection: selectionClass;

  let allSelection: selectionClass;

  let isKind: (PM_Types.selection, selectionClass) => bool;

  let selectionToNodeSelection: PM_Types.selection => option(PM_Types.nodeSelection);

  let selectionToTextSelection: PM_Types.selection => option(PM_Types.textSelection);

  let selectionToAllSelection: PM_Types.selection => option(PM_Types.allSelection);

  let nodeSelectionToSelection: PM_Types.nodeSelection => PM_Types.selection;

  let textSelectionToSelection: PM_Types.textSelection => PM_Types.selection;

  let allSelectionToSelection: PM_Types.allSelection => PM_Types.selection;

  type t = [
    | `NodeSelection(PM_Types.nodeSelection)
    | `TextSelection(PM_Types.textSelection)
    | `AllSelection(PM_Types.allSelection)
  ];

  let classify: PM_Types.selection => t;

  let classifyCustom:
    (PM_Types.selection, ~custom: (PM_Types.selection, string) => option([> t] as 'a)) =>
    ([> t] as 'a);
};

/** A ProseMirror selection can be one of several types. This module defines
types for classical text selections (of which cursors are a special case) and node selections, where
a specific document node is selected. It is possible to extend the editor with custom selection
types.

Superclass for editor selections. Every selection type should extend this. Should not be
instantiated directly.
*/
module Selection: {
  type t = PM_Types.selection;

  module type T = {
    type t;

    /**
      The ranges covered by the selection.
      ranges: [SelectionRange]
    */
    let ranges: t => array(SelectionRange.t);

    /**
    The resolved anchor of the selection (the side that stays in place when the selection
    is modified).
    $anchor: ResolvedPos
    */
    let resolvedAnchor: t => PM_Model.ResolvedPos.t;

    /**
    The resolved head of the selection (the side that moves when the selection is modified).
    $head: ResolvedPos
    */
    let resolvedHead: t => PM_Model.ResolvedPos.t;

    /**
    The selection's anchor, as an unresolved position.
    anchor: number
    */
    let anchor: t => int;

    /**
    The selection's head.
    iead: number
    */
    let head: t => int;

    /**
      The lower bound of the selection's main range.
      from: number
     */
    let from: t => int;

    /**
      The upper bound of the selection's main range.
      to: number
     */
    let to_: t => int;

    /**
      The resolved lower bound of the selection's main range.
      $from: ResolvedPos
     */
    let resolvedFrom: t => PM_Model.ResolvedPos.t;

    /**
      The resolved upper bound of the selection's main range.
      $to: ResolvedPos
     */
    let resolvedTo: t => PM_Model.ResolvedPos.t;

    /**
      Indicates whether the selection contains any content.
      empty: bool
     */
    let empty: t => bool;

    /**
      Test whether the selection is the same as another selection.
      eq(Selection) → bool
     */
    let eq: (t, t) => bool;

    /**
      Map this selection through a mappable thing. doc should be the new document to which we are mapping.
      map(doc: Node, mapping: Mappable) → Selection
     */
    let map: (t, ~doc: PM_Model.Node.t, ~mapping: Transform.Mapping.t) => t;

    /**
      Get the content of this selection as a slice.
      content() → Slice
     */
    let content: t => PM_Model.Slice.t;

    /**
      Replace the selection with a slice or, if no slice is given, delete the selection. Will append to the given transaction.
      replace(tr: Transaction, content: ?⁠Slice = Slice.empty)
     */
    let replace: (t, ~tr: PM_Types.transaction, ~content: PM_Model.Slice.t=?, unit) => unit;

    /**
      Replace the selection with the given node, appending the changes to the given transaction.
      replaceWith(tr: Transaction, node: Node)
     */
    let replaceWith: (t, ~tr: PM_Types.transaction, ~node: PM_Model.Node.t) => unit;

    /**
      Convert the selection to a JSON representation. When implementing this for a custom selection class, make sure to give the object a type property whose value matches the ID under which you registered your class.
      toJSON() → Object
     */
    let toJSON: t => Js.Json.t;

    /**
      Get a bookmark for this selection, which is a value that can be mapped without having access to a current document, and later resolved to a real selection for a given document again. (This is used mostly by the history to track and restore old selections.) The default implementation of this method just converts the selection to a text selection and returns the bookmark for that.
      getBookmark() → SelectionBookmark
     */
    let getBookmark: t => SelectionBookmark.t;

    /**
      Controls whether, when a selection of this type is active in the browser, the selected range should be visible to the user. Defaults to true.
      visible: bool
     */
    let visible: t => bool;

    /**
      Find a valid cursor or leaf node selection starting at the given position and searching back if dir is negative, and forward if positive. When textOnly is true, only consider cursor selections. Will return null when no valid selection position is found.
      static findFrom($pos: ResolvedPos, dir: number, textOnly: ?⁠bool) → ?⁠Selection
     */
    let findFrom:
      (~resolvedPos: PM_Model.ResolvedPos.t, ~dir: int, ~textOnly: bool=?, unit) => option(t);
    /**
      Find a valid cursor or leaf node selection near the given position. Searches forward first by default, but if bias is negative, it will search backwards first.
      static near($pos: ResolvedPos, bias: ?⁠number = 1) → Selection
     */
    let near: (~resolvedPos: PM_Model.ResolvedPos.t, ~bias: int=?, unit) => option(t);

    /**
      Find the cursor or leaf node selection closest to the start of the given document. Will return an AllSelection if no valid position exists.
      static atStart(doc: Node) → Selection
     */
    let atStart: (~doc: PM_Model.Node.t) => t;
    /**
      Find the cursor or leaf node selection closest to the end of the given document.
      static atEnd(doc: Node) → Selection
     */
    let atEnd: (~doc: PM_Model.Node.t) => t;

    /**
      Deserialize the JSON representation of a selection. Must be implemented for custom classes (as a static class method).
      static fromJSON(doc: Node, json: Object) → Selection
     */
    let fromJSON: (~doc: PM_Model.Node.t, ~json: Js.Json.t) => t;

    /**
      To be able to deserialize selections from JSON, custom selection classes must register themselves with an ID string, so that they can be disambiguated. Try to pick something that's unlikely to clash with classes from other modules.<Paste>
      static jsonID(id: string, selectionClass: constructor<Selection>)
     */
    let jsonID: (~id: string, ~selectionClass: t) => t;
  };

  module Make: (M: {type t;}) => T with type t := M.t;

  include T with type t := t;

  /**
    Initialize a selection with the head and anchor and ranges. If no ranges are given, constructs a single range across $anchor and $head.
    new Selection($anchor: ResolvedPos, $head: ResolvedPos, ranges: ?⁠[SelectionRange])
    */
  let make:
    (
      ~resolvedAnchor: PM_Model.ResolvedPos.t,
      ~resolvedHead: PM_Model.ResolvedPos.t,
      ~ranges: array(SelectionRange.t)=?,
      unit
    ) =>
    t;

  let toNodeSelection: PM_Types.selection => option(PM_Types.nodeSelection);

  let toTextSelection: PM_Types.selection => option(PM_Types.textSelection);

  let toAllSelection: PM_Types.selection => option(PM_Types.allSelection);

  let fromNodeSelection: PM_Types.nodeSelection => PM_Types.selection;

  let fromTextSelection: PM_Types.textSelection => PM_Types.selection;

  let fromAllSelection: PM_Types.allSelection => PM_Types.selection;

  let classify: PM_Types.selection => SelectionKind.t;

  let classifyCustom:
    (
      PM_Types.selection,
      ~custom: (PM_Types.selection, string) => option([> SelectionKind.t] as 'a)
    ) =>
    ([> SelectionKind.t] as 'a);
};

/** A text selection represents a classical editor selection, with a head (the moving side) and
  anchor (immobile side), both of which point into textblock nodes. It can be empty (a regular
  cursor position). */
module TextSelection: {
  type t = PM_Types.textSelection;

  include Selection.T with type t := t;

  /**
    Construct a text selection between the given points.
    new TextSelection($anchor: ResolvedPos, $head: ?⁠ResolvedPos = $anchor)
   */
  let make:
    (~resolvedAnchor: PM_Model.ResolvedPos.t, ~resolvedHead: PM_Model.ResolvedPos.t=?, unit) => t;

  /**
    Returns a resolved position if this is a cursor selection (an empty text selection), and null otherwise.
    $cursor: ?⁠ResolvedPos
   */
  let resolvedCursor: t => option(PM_Model.ResolvedPos.t);

  /**
    Construct a text selection between the given points.
    new TextSelection($anchor: ResolvedPos, $head: ?⁠ResolvedPos = $anchor)
   */
  let create: (~doc: PM_Model.Node.t, ~anchor: int, ~head: int=?, unit) => t;

  /**
    Construct a text selection between the given points.
    new TextSelection($anchor: ResolvedPos, $head: ?⁠ResolvedPos = $anchor)
   */
  let between:
    (
      ~resolvedAnchor: PM_Model.ResolvedPos.t,
      ~resolvedHead: PM_Model.ResolvedPos.t,
      ~bias: int=?,
      unit
    ) =>
    Selection.t;

  /**
    Construct a text selection between the given points.
    new TextSelection($anchor: ResolvedPos, $head: ?⁠ResolvedPos = $anchor)
   */
  let fromSelection: PM_Types.selection => option(PM_Types.textSelection);
};

/**
A node selection is a selection that points at a single node. All nodes marked selectable can be
the target of a node selection. In such a selection, from and to point directly before and after
the selected node, anchor equals from, and head equals to..
*/
module NodeSelection: {
  type t = PM_Types.nodeSelection;

  include Selection.T with type t := t;

  /**
    Create a node selection. Does not verify the validity of its argument.
    new NodeSelection($pos: ResolvedPos)
   */
  let make: PM_Model.ResolvedPos.t => t;

  /**
    The selected node.
    node: Node
   */
  let node: t => PM_Model.Node.t;

  /**
    Create a node selection from non-resolved positions.
    static create(doc: Node, from: number) → NodeSelection
   */
  let create: (~doc: PM_Model.Node.t, ~from: int) => t;

  /**
    Determines whether the given node may be selected as a node selection.
    static isSelectable(node: Node) → bool
   */
  let isSelectable: PM_Model.Node.t => bool;

  let fromSelection: PM_Types.selection => option(PM_Types.nodeSelection);
};

/**
A selection type that represents selecting the whole document (which can not necessarily be
expressed with a text selection, when there are for example leaf block nodes at the start or end of
the document).
*/
module AllSelection: {
  type t = PM_Types.allSelection;

  include Selection.T with type t := t;

  /**
    new AllSelection(doc: Node)
    Create an all-selection over the given document.
   */
  let make: (~doc: PM_Model.Node.t) => t;

  let fromSelection: PM_Types.selection => option(PM_Types.allSelection);
};

/** ProseMirror keeps all editor state (the things, basically, that would be required to create an
  editor just like the current one) in a single object. That object is updated (creating a new
  state) by applying transactions to it. The state of a ProseMirror editor is represented by an
  object of this type. A state is a persistent data structure—it isn't updated, but rather a new
  state value is computed from an old one using the apply method.
*/
module EditorState: {
  type t = PM_Types.editorState;

  module Config: {
    type t;
    let make:
      (
        ~schema: PM_Model.Schema.t=?,
        ~doc: PM_Model.Node.t=?,
        ~selection: Selection.t=?,
        ~storedMarks: array(PM_Model.Mark.t)=?,
        ~plugins: array(PM_Types.untypedPlugin)=?,
        unit
      ) =>
      t;
  };

  /**
    The current document.
    doc: Node
   */
  let doc: t => PM_Model.Node.t;

  /**
    The selection.
    selection: Selection
   */
  let selection: t => Selection.t;

  /**
    A set of marks to apply to the next input. Will be null when no explicit marks have been set.
    storedMarks: ?⁠[Mark]
   */
  let storedMarks: t => option(array(PM_Model.Mark.t));

  /**
    The schema of the state's document.
    schema: Schema
   */
  let schema: t => PM_Model.Schema.t;

  /**
    The plugins that are active in this state.
    plugins: [Plugin]
   */
  let plugins: t => array(PM_Types.untypedPlugin);

  /**
    Apply the given transaction to produce a new state.
    apply(tr: Transaction) → EditorState
   */
  let apply: (t, PM_Types.transaction) => t;

  /**
    Verbose variant of apply that returns the precise transactions that were applied (which might be influenced by the transaction hooks of plugins) along with the new state.
    applyTransaction(rootTr: Transaction) → {state: EditorState, transactions: [Transaction]}
   */
  let applyTransaction:
    (t, PM_Types.transaction) =>
    {
      .
      "state": t,
      "transactions": array(PM_Types.transaction),
    };

  /**
    Start a transaction from this state.
    tr: Transaction
   */
  let tr: t => PM_Types.transaction;

  /**
    Create a new state based on this one, but with an adjusted set of active plugins. State fields that
    exist in both sets of plugins are kept unchanged. Those that no longer exist are dropped, and those
    that are new are initialized using their init method, passing in the new configuration object..
    reconfigure(config: Object) → EditorState
   */
  let reconfigure: (t, Config.t) => t;

  /**
    Serialize this state to JSON. If you want to serialize the state of plugins, pass an object mapping property names to use in the resulting JSON object to plugin objects. The argument may also be a string or number, in which case it is ignored, to support the way JSON.stringify calls toString methods.
    toJSON(pluginFields: ?⁠Object<Plugin> | string | number) → Object
   */
  let toJSONWithPluginFields: (t, Js.Dict.t(PM_Types.untypedPlugin)) => Js.Json.t;

  /**
  The `space` argument is equivalent to the same argument
  in [JSON.stringify](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/JSON/stringify#Syntax)
  */
  let toJSON: (t, ~space: [ | `String(string) | `Int(int)]=?, unit) => Js.Json.t;

  /**
    Create a new state.
    static create(config: Object) → EditorState
   */
  let create: Config.t => t;

  /**
    Deserialize a JSON representation of a state. config should have at least a schema field, and should contain array of plugins to initialize the state with. pluginFields can be used to deserialize the state of plugins, by associating plugin instances with the property names they use in the JSON object.
    static fromJSON(config: Object, json: Object, pluginFields: ?⁠Object<Plugin>) → EditorState
   */
  let fromJSON:
    (
      ~config: Config.t,
      ~json: Js.Json.t,
      ~pluginFields: Js.Dict.t(PM_Types.untypedPlugin)=?,
      unit
    ) =>
    t;
};

module PluginKey: {
  type t('a);

  /** Create a plugin key. */
  let make: (~name: string=?, unit) => t('a);

  /** Get the active plugin with this key, if any, from an editor state. */

  let get: (t('a), PM_Types.editorState) => option(PM_Types.plugin('a));

  /** Get the plugin's state from an editor state. */
  let getState: (t('a), PM_Types.editorState) => option('a);
};

/**
A plugin spec may provide a state field (under its state property) of this type, which describes the
state it wants to keep. Functions provided here are always called with the plugin instance as their
this binding. */
module StateField: {
  type t('a);

  /**
    [init] Initialize the value of the field. config will be the object passed to EditorState.create. Note that instance is a half-initialized state instance, and will not have values for plugin fields initialized after this one.
    init(config: Object, instance: EditorState) → T

    [apply] Apply the given transaction to this state field, producing a new field value. Note that the newState argument is again a partially constructed state does not yet contain the state from plugins coming after this one.
    apply(tr: Transaction, value: T, oldState: EditorState, newState: EditorState) → T

    [toJSON] Convert this field to JSON. Optional, can be left off to disable JSON serialization for the field.
    toJSON: ?⁠fn(value: T) → any

    [fromJSON] Deserialize the JSON representation of this field. Note that the state argument is again a half-initialized state.
    fromJSON: ?⁠fn(config: Object, value: any, state: EditorState) → T
   */
  let make:
    (
      ~init: (~config: EditorState.Config.t, ~instance: PM_Types.editorState) => 'a,
      ~apply: (
                ~tr: PM_Types.transaction,
                ~value: 'a,
                ~oldState: PM_Types.editorState,
                ~newState: PM_Types.editorState
              ) =>
              'a,
      ~toJSON: (~value: 'a) => Js.Json.t=?,
      ~fromJSON: (
                   ~config: EditorState.Config.t,
                   ~value: Js.Json.t,
                   ~state: PM_Types.editorState
                 ) =>
                 'a
                   =?,
      unit
    ) =>
    t('a);
};

/** This is the type passed to the Plugin constructor. It provides a definition for a plugin. */
module PluginSpec: {
  module View: {
    /** When the plugin needs to interact with the editor view, or set something up in the DOM, use
      this field. The function will be called when the plugin's state is associated with an editor
      view. */
    type t;

    /** Called whenever the view's state is updated. */
    type update = (PM_Types.editorView, PM_Types.editorState) => unit;

    /** Called when the view is destroyed or receives a state with different plugins. */
    type destroy = unit => unit;

    let make: (~update: update=?, ~destroy: destroy=?, unit) => t;
  };

  type t('a);

  /**
    [props] is the view props added by this plugin. Props that are functions will be bound to have the plugin instance as their this binding.
    props: ?⁠PM_EditorProps

    [state] allows a plugin to define a state field, an extra slot in the state object in which it can keep its own data.
    state: ?⁠StateField<any>

    [key] can be used to make this a keyed plugin. You can have only one plugin with a given key in a given state, but it is possible to access the plugin's configuration and state through the key, without having access to the plugin instance object.
    key: ?⁠PluginKey

    [filterTransaction], when present, this will be called before a transaction is applied by the
    state, allowing the plugin to cancel it (by returning false).

    [appendTransaction] allows the plugin to append another transaction to be applied after the given array of
    transactions. When another plugin appends a transaction after this was called, it is called
    again with the new state and new transactions—but only the new transactions, i.e. it won't be
    passed transactions that it already saw.

    [historyPreserveItems] This is used to notify the history plugin to not merge steps,
    so that the history can be rebased.
    Used in the collab plugin for example
   */
  let make:
    (
      ~props: PM_EditorProps.t=?,
      ~state: StateField.t('a)=?,
      ~key: PluginKey.t('a)=?,
      ~view: PM_Types.editorView => View.t=?,
      ~filterTransaction: (PM_Types.transaction, PM_Types.editorState) => bool=?,
      ~appendTransaction: (
                            ~transanctions: array(PM_Types.transaction),
                            ~oldState: PM_Types.editorState,
                            ~newState: PM_Types.editorState
                          ) =>
                          Js.Nullable.t(PM_Types.transaction)
                            =?,
      ~historyPreserveItems: bool=?,
      unit
    ) =>
    t('a);
};

/** Plugins bundle functionality that can be added to an editor. They are part of the editor state
  and may influence that state and the view that contains it. */
module Plugin: {
  type t('a) = PM_Types.plugin('a);

  let make: (~spec: PluginSpec.t('a)) => t('a);

  let makeUntyped: (~spec: PluginSpec.t('a)) => PM_Types.untypedPlugin;

  let toUntyped: t('a) => PM_Types.untypedPlugin;

  let fromUntyped: PM_Types.untypedPlugin => t('a);

  /** The props exported by this plugin. */
  let props: t('a) => PM_EditorProps.t;

  /** The plugin's spec object */
  let spec: t('a) => PluginSpec.t('a);

  /** Extract the plugin's state field from an editor state */
  let getState: (t('a), ~state: PM_Types.editorState) => 'a;
};

/**
An editor state transaction, which can be applied to a state to create an updated state. Use
EditorState.tr to create an instance.

Transactions track changes to the document (they are a subclass of Transform), but also other state
changes, like selection updates and adjustments of the set of stored marks. In addition, you can
store metadata properties in a transaction, which are extra pieces of information that client code
or plugins can use to describe what a transacion represents, so that they can update their own state
accordingly.

The editor view uses a few metadata properties: it will attach a property "pointer" with the value
true to selection transactions directly caused by mouse or touch input, and a "uiEvent" property of
that may be "paste", "cut", or "drop".
*/
module Transaction: {
  type t = PM_Types.transaction;

  include PM_Transform.Transform.T with type t := t;

  /**
    The timestamp associated with this transaction, in the same format as Date.now().
    time: number
   */
  let time: t => float;

  /**
    The stored marks set by this transaction, if any.
    storedMarks: ?⁠[Mark]
   */
  let storedMarks: t => option(array(PM_Model.Mark.t));

  /**
    The transaction's current selection. This defaults to the editor selection mapped through the steps in the transaction, but can be overwritten with setSelection.
    selection: Selection
   */
  let selection: t => Selection.t;

  /**
    Update the transaction's current selection. Will determine the selection that the editor gets when the transaction is applied.
    setSelection(selection: Selection) → Transaction
   */
  let setSelection: (t, Selection.t) => t;

  /**
    Whether the selection was explicitly updated by this transaction.
    selectionSet: bool
   */
  let selectionSet: t => bool;

  /**
    Set the current stored marks.
    setStoredMarks(marks: ?⁠[Mark]) → Transaction
   */
  let setStoredMarks: (t, ~marks: array(PM_Model.Mark.t)=?, unit) => t;

  /**
    Make sure the current stored marks or, if that is null, the marks at the selection, match the given set of marks. Does nothing if this is already the case.
    ensureMarks(marks: [Mark]) → Transaction
   */
  let ensureMarks: (t, array(PM_Model.Mark.t)) => t;

  /**
    Add a mark to the set of stored marks.
    addStoredMark(mark: Mark) → Transaction
   */
  let addStoredMark: (t, ~mark: PM_Model.Mark.t) => t;

  /**
    Remove a mark or mark type from the set of stored marks.
    removeStoredMark(mark: Mark | MarkType) → Transaction
   */
  let removeStoredMark:
    (t, ~markOrMarkType: [ | `Mark(PM_Model.Mark.t) | `MarkType(PM_Model.MarkType.t)]) => t;

  /**
    Whether the stored marks were explicitly set for this transaction.
    storedMarksSet: bool
  */
  let storedMarksSet: t => bool;

  /**
    Update the timestamp for the transaction.
    setTime(time: number) → Transaction
   */
  let setTime: (t, int) => t;

  /**
    Replace the current selection with the given slice.
    replaceSelection(slice: Slice) → Transaction
   */
  let replaceSelection: (t, PM_Model.Slice.t) => t;

  /**
    Replace the selection with the given node. When inheritMarks is true and the content is inline, it inherits the marks from the place where it is inserted.
    replaceSelectionWith(node: Node, inheritMarks: ?⁠bool) → Transaction
   */
  let replaceSelectionWith: (t, ~node: PM_Model.Node.t, ~inheritMarks: bool=?, unit) => t;

  /**
    Delete the selection.
    deleteSelection() → Transaction
   */
  let deleteSelection: t => t;

  /**
    Replace the given range, or the selection if no range is given, with a text node containing the given string.
    insertText(text: string, from: ?⁠number, to: ?⁠number = from) → Transaction
   */
  let insertText: (t, ~text: string, ~from: int=?, ~to_: int=?, unit) => t;

  /**
    Returns true if this transaction doesn't contain any metadata, and can thus safely be extended.
    isGeneric: bool
   */
  let isGeneric: t => bool;

  /**
    Indicate that the editor should scroll the selection into view when updated to the state
    produced by this transaction.
    scrollIntoView() → Transaction
   */
  let scrollIntoView: t => t;

  /**
    Returns true if the editor should scroll the selection into view
    when updated to the state produced by this transaction.
    scrolledIntoView: bool
   */
  let scrolledIntoView: t => bool;

  module Meta: {
    module type T = {
      type v;

      /**
      Store a metadata property in this transaction, keyed either by name or by plugin.
      setMeta(key: string | Plugin | PluginKey, value: any) → Transaction
      */
      let set:
        (
          t,
          ~key: [ | `String(string) | `Plugin(Plugin.t('a)) | `PluginKey(PluginKey.t('a))],
          ~value: v
        ) =>
        t;

      /**
      Retrieve a metadata property for a given name or plugin.
      getMeta(key: string | Plugin | PluginKey) → any
      */
      let get:
        (
          t,
          ~key: [ | `String(string) | `Plugin(Plugin.t('a)) | `PluginKey(PluginKey.t('a))]
        ) =>
        option(v);
    };

    module Make: (M: {type v;}) => T with type v := M.v;
  };
};
