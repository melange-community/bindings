/**
 This module exports a number of commands, which are building block functions that encapsulate an
 editing action. A command function takes an editor state and optionally a dispatch function that it
 can use to dispatch a transaction. It should return a boolean that indicates whether it could
 perform any action. When no dispatch callback is passed, the command should do a 'dry run',
 determining whether it is applicable, but not actually doing anything.

 These are mostly used to bind keys and define menu items.
 */
/**
 Combine a number of command functions into a single function (which calls them one by one until one
 returns true).
 chainPM_Commands(...commands: [fn(EditorState, ?⁠fn(tr: Transaction), ?⁠EditorView) → bool]) → fn(EditorState, ?⁠fn(tr: Transaction), ?⁠EditorView) → bool
 */
let chainCommands: array(PM_Command.t) => PM_Command.t;

/**
 Delete the selection, if there is one.
 deleteSelection(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let deleteSelection: PM_Command.t;

/**
 If the selection is empty and at the start of a textblock, try to reduce the distance between that
 block and the one before it—if there's a block directly before it that can be joined, join them. If
 not, try to move the selected block closer to the next one in the document structure by lifting it
 out of its parent or moving it into a parent of the previous block. Will use the view for accurate
 (bidi-aware) start-of-textblock detection if given.
 joinBackward(state: EditorState, dispatch: ?⁠fn(tr: Transaction), view: ?⁠EditorView) → bool
 */
let joinBackward: PM_Command.t;

/**
 When the selection is empty and at the start of a textblock, select the node before that textblock,
 if possible. This is intended to be bound to keys like backspace, after joinBackward or other
 deleting commands, as a fall-back behavior when the schema doesn't allow deletion at the selected
 point.
 selectNodeBackward(state: EditorState, dispatch: ?⁠fn(tr: Transaction), view: ?⁠EditorView) → bool
 */
let selectNodeBackward: PM_Command.t;

/**
 If the selection is empty and the cursor is at the end of a textblock, try to reduce or remove the
 boundary between that block and the one after it, either by joining them or by moving the other
 block closer to this one in the tree structure. Will use the view for accurate start-of-textblock
 detection if given.
 joinForward(state: EditorState, dispatch: ?⁠fn(tr: Transaction), view: ?⁠EditorView) → bool
 */
let joinForward: PM_Command.t;

/**
 When the selection is empty and at the end of a textblock, select the node coming after that
 textblock, if possible. This is intended to be bound to keys like delete, after joinForward and
 similar deleting commands, to provide a fall-back behavior when the schema doesn't allow deletion
 at the selected point.
 selectNodeForward(state: EditorState, dispatch: ?⁠fn(tr: Transaction), view: ?⁠EditorView) → bool
 */
let selectNodeForward: PM_Command.t;

/**
 Join the selected block or, if there is a text selection, the closest ancestor block of the
 selection that can be joined, with the sibling above it.
 joinUp(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let joinUp: PM_Command.t;

/**
 Join the selected block, or the closest ancestor of the selection that can be joined, with the
 sibling after it.
 joinDown(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let joinDown: PM_Command.t;

/**
 Lift the selected block, or the closest ancestor block of the selection that can be lifted, out of
 its parent node.
 lift(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let lift: PM_Command.t;

/**
 If the selection is in a node whose type has a truthy code property in its spec, replace the
 selection with a newline character.
 newlineInCode(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let newlineInCode: PM_Command.t;

/**
 When the selection is in a node with a truthy code property in its spec, create a default block
 after the code block, and move the cursor there.
 exitCode(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let exitCode: PM_Command.t;

/**
 If a block node is selected, create an empty paragraph before (if it is its parent's first child)
 or after it.
 createParagraphNear(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let createParagraphNear: PM_Command.t;

/**
 If the cursor is in an empty textblock that can be lifted, lift the block.
 liftEmptyBlock(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let liftEmptyBlock: PM_Command.t;

/**
 Split the parent block of the selection. If the selection is a text selection, also delete its
 content.
 splitBlock(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let splitBlock: PM_Command.t;

/**
 Acts like splitBlock, but without resetting the set of active marks at the cursor.
 splitBlockKeepMarks(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let splitBlockKeepMarks: PM_Command.t;

/**
 Move the selection to the node wrapping the current selection, if any. (Will not select the
 document node.)
 selectParentNode(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let selectParentNode: PM_Command.t;

/**
 Select the whole document.
 selectAll(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let selectAll: PM_Command.t;

/**
 Wrap the selection in a node of the given type with the given attributes.
 wrapIn(nodeType: NodeType, attrs: ?⁠Object) → fn(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let wrapIn:
  (
    ~nodeType: PM_Model.NodeType.t,
    ~attrs: PM_Model.Attrs.t,
    ~state: PM_State.EditorState.t,
    ~dispatch: PM_State.Transaction.t => unit=?,
    ~view: PM_View.t=?,
    unit
  ) =>
  bool;

/**
 Returns a command that tries to set the selected textblocks to the given node type with the given
 attributes.
 setBlockType(nodeType: NodeType, attrs: ?⁠Object) → fn(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let setBlockType:
  (
    ~nodeType: PM_Model.NodeType.t,
    ~attrs: PM_Model.Attrs.t,
    ~state: PM_State.EditorState.t,
    ~dispatch: PM_State.Transaction.t => unit=?,
    ~view: PM_View.t=?,
    unit
  ) =>
  bool;

/**
 Create a command function that toggles the given mark with the given attributes. Will return false
 when the current selection doesn't support that mark. This will remove the mark if any marks of that
 type exist in the selection, or add it otherwise. If the selection is empty, this applies to the
 stored marks instead of a range of the document.
 toggleMark(markType: MarkType, attrs: ?⁠Object) → fn(state: EditorState, dispatch: ?⁠fn(tr: Transaction)) → bool
 */
let toggleMark:
  (
    ~markType: PM_Model.MarkType.t,
    ~attrs: PM_Model.Attrs.t,
    ~state: PM_State.EditorState.t,
    ~dispatch: PM_State.Transaction.t => unit=?,
    ~view: PM_View.t=?,
    unit
  ) =>
  bool;

/**
 Wrap a command so that, when it produces a transform that causes two joinable nodes to end up next
 to each other, those are joined. Nodes are considered joinable when they are of the same type and
 when the isJoinable predicate returns true for them or, if an array of strings was passed, if their
 node type name is in that array.
 autoJoin(command: fn(state: EditorState, ?⁠fn(tr: Transaction)) → bool, isJoinable: fn(before: Node, after: Node) → bool | [string]) → fn(state: EditorState, ?⁠fn(tr: Transaction)) → bool
 */
let autoJoin:
  (
    ~command: PM_Command.t,
    ~isJoinable: [
                   | `Predicate((PM_Model.Node.t, PM_Model.Node.t) => bool)
                   | `NodeTypeNames(array(string))
                 ]
  ) =>
  PM_Command.t;

/**
 Depending on the detected platform, this will hold pcBasekeymap or macBaseKeymap.
 baseKeymap: Object
 */
let baseKeymap: Js.Dict.t(PM_Command.t);

/**
 A basic keymap containing bindings not specific to any schema. Binds the following keys (when multiple commands are listed, they are chained with chainPM_Commands):

 - Enter to newlineInCode, createParagraphNear, liftEmptyBlock, splitBlock
 - Mod-Enter to exitCode
 - Backspace and Mod-Backspace to deleteSelection, joinBackward, selectNodeBackward
 - Delete and Mod-Delete to deleteSelection, joinForward, selectNodeForward
 - Mod-Delete to deleteSelection, joinForward, selectNodeForward
 - Mod-a to selectAll

 pcBaseKeymap: Object
 */
let pcBaseKeymap: Js.Dict.t(PM_Command.t);

/**
 A copy of pcBaseKeymap that also binds Ctrl-h like Backspace, Ctrl-d like Delete, Alt-Backspace like
 Ctrl-Backspace, and Ctrl-Alt-Backspace, Alt-Delete, and Alt-d like Ctrl-Delete.
 macBaseKeymap: Object
 */
let macBaseKeymap: Js.Dict.t(PM_Command.t);
