module Attrs: {
  type t;

  let make: Js.t({..}) => t;

  let toJs: t => Js.t({..});

  let empty: unit => t;
};

module AttributeSpec: {
  /**
    Used to define attributes on nodes or marks.
   */
  type t;
  /**
    The default value for this attribute, to use when no explicit value is provided. Attributes that have no default must be provided whenever a node or mark of a type that has them is created.
    default: ?⁠any
   */
  let make: (~default: 'a=?, unit) => t;
};

module DOMAttrs: {
  type t;
  let make: Js.Dict.t(string) => t;
  let toDict: t => Js.Dict.t(string);
  let empty: unit => t;
};

module DOMOutputSpec: {
  /**
    A description of a DOM structure. Can be either a string, which is interpreted as a text node,
    a DOM node, which is interpreted as itself, or an array. An array describes a DOM element.
    The first value in the array should be a string—the name of the DOM element.
    If the second element is plain object, it is interpreted as a set of attributes for the element.
    Any elements after that (including the 2nd if it's not an attribute object) are interpreted
    as children of the DOM elements, and must either be valid DOMOutputSpec values, or the number zero.
    The number zero (pronounced “hole”) is used to indicate the place where a node's child
    nodes should be inserted. It it occurs in an output spec, it should be the only child element
    in its parent node.
   */
  type spec =
    | LeafNode(string, DOMAttrs.t): spec
    | Node(string, DOMAttrs.t, spec): spec
    | Text(string): spec
    | Hole: spec;

  type t;
  /**
    Creates text node
   */
  let fromString: string => t;

  /**
    Creates a node from a DOM node
   */
  let fromDomNode: Dom.node => t;
  /**
    Creates a node from a spec
    ```
    Node("div", Attrs.make({ "class": "test" }), Node("span", Attrs.empty, Hole)) |> fromSpec
    // ["div", {class: "test"}, ["span", {}, 0]]
    ```
   */
  let fromSpec: spec => t;
};

module DOMSerializer: {
  /**
    A DOM serializer knows how to convert ProseMirror nodes and marks of various types to DOM nodes.
   */
  type t;

  /**
   Create a serializer. nodes should map node names to functions that take a node
   and return a description of the corresponding DOM. marks does the same for mark names,
   but also gets an argument that tells it whether the mark's content is block
   or inline content (for typical use, it'll always be inline).
   A mark serializer may be null to indicate that marks of that type should not be serialized.
   new DOMSerializer(nodes: Object<fn(node: Node) → DOMOutputSpec>, marks: Object<?⁠fn(mark: Mark, inline: bool) → DOMOutputSpec>)
   */
  let make:
    (
      ~nodes: Js.Dict.t(PM_Types.node => DOMOutputSpec.t),
      ~marks: Js.Dict.t((PM_Types.mark, ~inline: bool) => DOMOutputSpec.t)
    ) =>
    t;

  /**
   The node serialization functions.
   nodes: Object<fn(node: Node) → DOMOutputSpec>
   */
  let nodes: t => Js.Dict.t(PM_Types.node => DOMOutputSpec.t);

  /**
   The mark serialization functions.
   marks: Object<?⁠fn(mark: Mark, inline: bool) → DOMOutputSpec>
   */
  let marks: t => Js.Dict.t((PM_Types.mark, ~inline: bool) => DOMOutputSpec.t);

  /**
   Serialize the content of this fragment to a DOM fragment. When not in the browser, the document option, containing a DOM document, should be passed so that the serializer can create nodes.
   serializeFragment(fragment: Fragment, options: ?⁠Object = {}) → dom.DocumentFragment
   */
  let serializeFragment:
    (t, ~fragment: PM_Types.fragment, ~options: Js.t({..})=?, unit) => Dom.documentFragment;

  /**
   Serialize this node to a DOM node. This can be useful when you need to serialize a part of a document, as opposed to the whole document. To serialize a whole document, use serializeFragment on its content.
   serializeNode(node: Node, options: ?⁠Object = {}) → dom.Node
   */
  let serializeNode: (t, ~node: PM_Types.node, ~options: Js.t({..})=?, unit) => Dom.node;

  /**
   Render an output spec to a DOM node. If the spec has a hole (zero) in it, contentDOM will point at the node with the hole.
   static renderSpec(doc: dom.Document, structure: DOMOutputSpec) → {dom: dom.Node, contentDOM: ?⁠dom.Node}
   */
  let renderSpec:
    (~doc: Dom.document, ~structure: DOMOutputSpec.t) =>
    {
      .
      "contentDOM": Js.Nullable.t(Dom.node),
      "dom": Dom.node,
    };

  /**
   Build a serializer using the toDOM properties in a schema's node and mark specs.
   static fromSchema(schema: Schema) → DOMSerializer
   */
  let fromSpec: PM_Types.schema => t;
};

module ParseRule: {
  /**
   A value that describes how to parse a given DOM node or inline style as a ProseMirror node or mark.

   tag: ?⁠string
   A CSS selector describing the kind of DOM elements to match. A single rule should have either a tag or a style property.

   namespace: ?⁠string
   The namespace to match. This should be used with tag. Nodes are only matched when the namespace matches or this property is null.

   style: ?⁠string
   A CSS property name to match. When given, this rule matches inline styles that list that property. May also have the form "property=value", in which case the rule only matches if the propery's value exactly matches the given value. (For more complicated filters, use getAttrs and return undefined to indicate that the match failed.)

   priority: ?⁠number
   Can be used to change the order in which the parse rules in a schema are tried. Those with higher priority come first. Rules without a priority are counted as having priority 50. This property is only meaningful in a schema—when directly constructing a parser, the order of the rule array is used.

   context: ?⁠string
   When given, restricts this rule to only match when the current context—the parent nodes into which the content is being parsed—matches this expression. Should contain one or more node names or node group names followed by single or double slashes. For example "paragraph/" means the rule only matches when the parent node is a paragraph, "blockquote/paragraph/" restricts it to be in a paragraph that is inside a blockquote, and "section//" matches any position inside a section—a double slash matches any sequence of ancestor nodes. To allow multiple different contexts, they can be separated by a pipe (|) character, as in "blockquote/|list_item/".

   node: ?⁠string
   The name of the node type to create when this rule matches. Only valid for rules with a tag property, not for style rules. Each rule should have one of a node, mark, or ignore property (except when it appears in a node or mark spec, in which case the node or mark property will be derived from its position).

   mark: ?⁠string
   The name of the mark type to wrap the matched content in.

   ignore: ?⁠bool
   When true, ignore content that matches this rule.

   skip: ?⁠bool
   When true, ignore the node that matches this rule, but do parse its content.

   attrs: ?⁠Object
   Attributes for the node or mark created by this rule. When getAttrs is provided, it takes precedence.

   getAttrs: ?⁠fn(dom.Node | string) → ?⁠Object | false
   A function used to compute the attributes for the node or mark created by this rule. Can also be used to describe further conditions the DOM element or style must match. When it returns false, the rule won't match. When it returns null or undefined, that is interpreted as an empty/default set of attributes.

   Called with a DOM Element for tag rules, and with a string (the style's value) for style rules.

   contentElement: ?⁠string | fn(dom.Node) → dom.Node
   For tag rules that produce non-leaf nodes or marks, by default the content of the DOM element is parsed as content of the mark or node. If the child nodes are in a descendent node, this may be a CSS selector string that the parser must use to find the actual content element, or a function that returns the actual content element to the parser.

   getContent: ?⁠fn(dom.Node, schema: Schema) → Fragment
   Can be used to override the content of a matched node. When present, instead of parsing the node's child nodes, the result of this function is used.

   preserveWhitespace: ?⁠bool | "full"
   Controls whether whitespace should be preserved when parsing the content inside the matched element. false means whitespace may be collapsed, true means that whitespace should be preserved but newlines normalized to spaces, and "full" means that newlines should also be preserved.
      */

  module GetAttrsResult: {
    type t;
    let noMatch: unit => t;
    let empty: unit => t;
    let attrs: Attrs.t => t;
  };
  module GetAttrs: {
    type t;
    let fromNodeFn: (Dom.node => GetAttrsResult.t) => t;
    let fromStringFn: (string => GetAttrsResult.t) => t;
  };
  module ContentElement: {
    type t;
    let fromNode: (Dom.node => Dom.node) => t;
    let fromString: string => t;
  };
  module PreserveWhitespace: {
    type t;
    let make: bool => t;
    let full: t;
  };
  type t;
  let t:
    (
      ~tag: string=?,
      ~namespace: string=?,
      ~style: string=?,
      ~priority: int=?,
      ~context: string=?,
      ~node: string=?,
      ~mark: string=?,
      ~ignore: bool=?,
      ~skip: bool=?,
      ~attrs: Attrs.t=?,
      ~getAttrs: GetAttrs.t=?,
      ~contentElement: ContentElement.t=?,
      ~getContent: (Dom.node, PM_Types.schema) => PM_Types.fragment=?,
      ~preserveWhitespace: PreserveWhitespace.t=?,
      unit
    ) =>
    t;
};

module Mark: {
  /**
     A mark is a piece of information that can be attached to a node, such as it being emphasized,
     in code font, or a link. It has a type and optionally a set of attributes that provide
     further information (such as the target of the link). Marks are created through a Schema,
     which controls which types exist and which attributes they have.
   */
  type t = PM_Types.mark;

  /**
    The type of this mark.
    type: MarkType
   */
  let type_: t => PM_Types.markType;

  /**
    The attributes associated with this mark.
    attrs: Object
   */
  let attrs: t => Attrs.t;

  /**
   Given a set of marks, create a new set which contains this one as well,
   in the right position. If this mark is already in the set, the set itself is returned.
   If any marks that are set to be exclusive with this mark are present,
   those are replaced by this one.
   addToSet(set: [Mark]) → [Mark]
   */
  let addToSet: (t, array(t)) => array(t);

  /**
   Remove this mark from the given set, returning a new set.
   If this mark is not in the set, the set itself is returned.
   removeFromSet(set: [Mark]) → [Mark]
   */
  let removeFromSet: (t, array(t)) => array(t);

  /**
   Test whether this mark is in the given set of marks.
   isInSet(set: [Mark]) → bool
   */
  let isInSet: (t, array(t)) => bool;

  /**
   Test whether this mark has the same type and attributes as another mark.
   eq(other: Mark) → bool
   */
  let eq: (t, t) => bool;

  /**
   Convert this mark to a JSON-serializeable representation.
   toJSON() → Object
   */
  let toJSON: t => Js.Json.t;

  /**
    type: MarkType
    The type of this mark.
   */
  let fromJSON: (~schema: PM_Types.schema, ~json: Js.Json.t) => t;

  /**
   Test whether two sets of marks are identical.
   static sameSet(a: [Mark], b: [Mark]) → bool
   */
  let sameSet: (~a: array(t), ~b: array(t)) => bool;

  /**
   Create a properly sorted mark set from null, a single mark, or an unsorted array of marks.
   static setFrom(marks: ?⁠Mark | [Mark]) → [Mark]
   */
  let setFromArray: array(t) => array(t);

  /**
   The empty set of marks.
   static none: [Mark]
   */
  let none: array(t);
};

module Slice: {
  /**
   A slice represents a piece cut out of a larger document.
   It stores not only a fragment, but also the depth up to which nodes on both side are ‘open’
   (cut through). It is not necessary for the content of open nodes to conform to the schema's
   content constraints, though it should be a valid start/end/middle for such a node,
   depending on which sides are open.
   */

  type t;
  /**
    Create a slice. When specifying a non-zero open depth,
    you must make sure that there are nodes of at least that depth
    at the appropriate side of the fragment—i.e. if the fragment is an empty paragraph node,
    openStart and openEnd can't be greater than 1.
    new Slice(content: Fragment, openStart: number, openEnd: number)
   */
  let make: (~content: PM_Types.fragment, ~openStart: int, ~openEnd: int) => t;

  /**
    The slice's content.
    content: Fragment
   */
  let content: t => PM_Types.fragment;

  /**
    The open depth at the start.
    openStart: number
   */
  let openStart: t => int;

  /**
    The open depth at the end.
    openEnd: number
   */
  let openEnd: t => int;

  /**
    The size this slice would add when inserted into a document.
    size: number
   */
  let size: t => int;

  /**
    Tests whether this slice is equal to another slice.
    eq(other: Slice) → bool
   */
  let eq: (t, t) => bool;

  /**
    Convert a slice to a JSON-serializable representation.
    toJSON() → ?⁠Object
   */
  let toJSON: t => Js.Json.t;

  /**
    Deserialize a slice from its JSON representation.
    static fromJSON(schema: Schema, json: ?⁠Object) → Slice
   */
  let fromJSON: (~schema: PM_Types.schema, ~json: Js.Json.t) => t;

  /**
   Create a slice from a fragment by taking the maximum possible
   open value on both side of the fragment.
   static maxOpen(fragment: Fragment, openIsolating: ?⁠bool = true) → Slice
   */
  let maxOpen: (~fragment: PM_Types.fragment, ~openIsolating: bool=?) => t;

  /**
   The empty slice.
   static empty: Slice
   */
  let empty: t;
};

module ContentMatch: {
  /**
   Instances of this class represent a match state of a node type's content expression,
   and can be used to find out whether further content matches here,
   and whether a given position is a valid end of the node.
   */
  type t;

  /**
    True when this match state represents a valid end of the node.
    validEnd: bool
   */
  let validEnd: t => bool;

  /**
    Match a node type, returning a match after that node if successful.
    matchType(type: NodeType) → ?⁠ContentMatch
   */
  let matchType: (t, PM_Types.nodeType) => option(t);

  /**
    Try to match a fragment. Returns the resulting match when successful.
    matchFragment(frag: Fragment, start: ?⁠number = 0, end: ?⁠number = frag.childCount) → ?⁠ContentMatch
   */
  let matchFragment:
    (t, ~frag: PM_Types.fragment, ~start: int=?, ~end_: int=?, unit) => option(t);

  /**
    Get the first matching node type at this match position that can be generated.
    defaultType: ?⁠NodeType
   */
  let defaultType: t => option(PM_Types.nodeType);

  /**
    Try to match the given fragment, and if that fails, see if it can be made to match
    by inserting nodes in front of it. When successful, return a fragment of inserted nodes
    (which may be empty if nothing had to be inserted). When toEnd is true, only return
    a fragment if the resulting match goes to the end of the content expression.
    fillBefore(after: Fragment, toEnd: ?⁠bool = false, startIndex: ?⁠number = 0) → ?⁠Fragment
   */
  let fillBefore:
    (t, ~after: PM_Types.fragment, ~toEnd: bool=?, ~startIndex: int=?, unit) =>
    option(PM_Types.fragment);

  /**
    Find a set of wrapping node types that would allow a node of the given type
    to appear at this position. The result may be empty (when it fits directly) and will be null
    when no such wrapping exists.
    findWrapping(target: NodeType) → ?⁠[NodeType]
   */
  let findWrapping: (t, PM_Types.nodeType) => option(array(PM_Types.nodeType));

  /**
    The number of outgoing edges this node has in the finite automaton
    that describes the content expression.
    edgeCount: number
   */
  let edgeCount: t => int;

  /**
   Get the _n_th outgoing edge from this node in the finite automaton
   that describes the content expression.
   edge(n: number) → {type: NodeType, next: ContentMatch}
   */
  let edge:
    (t, ~n: int) =>
    {
      .
      "_type": PM_Types.nodeType,
      "next": t,
    };
};

module NodeRange: {
  /**
     Represents a flat range of content, i.e. one that starts and ends in the same node.
   */
  type t = PM_Types.nodeRange;

  /**
   Construct a node range.
   $from and $to should point into the same node until at least the given depth,
   since a node range denotes an adjacent set of nodes in a single parent node.
   new NodeRange($from: ResolvedPos, $to: ResolvedPos, depth: number)
   */
  let make:
    (~resolvedFrom: PM_Types.resolvedPos, ~resolvedTo: PM_Types.resolvedPos, ~depth: int) => t;

  /**
   A resolved position along the start of the content.
   May have a depth greater than this object's depth property,
   since these are the positions that were used to compute the range,
   not re-resolved positions directly at its boundaries.
   $from: ResolvedPos
   */
  let resolvedFrom: t => PM_Types.resolvedPos;

  /**
   A position along the end of the content. See caveat for $from.
   $to: ResolvedPos
   */
  let resolvedTo: t => PM_Types.resolvedPos;

  /**
   The depth of the node that this range points into.
   depth: number
   */
  let depth: t => int;

  /**
   The position at the start of the range.
   start: number
   */
  let start: t => int;

  /**
   The position at the end of the range.
   end: number
   */
  let end_: t => int;

  /**
   The parent node that the range points into.
   parent: Node
   */
  let parent: t => PM_Types.node;

  /**
   The start index of the range in the parent node.
   startIndex: number
   */
  let startIndex: t => int;

  /**
   endIndex: number
    The end index of the range in the parent node.
    */
  let endIndex: t => int;
};

module NodeSpec: {
  module Custom: {
    type t;
    let fromJs: Js.t({..}) => t;
    let toJs: t => Js.t({..});
  };
  /**
    marks: ?⁠string
    The marks that are allowed inside of this node. May be a space-separated string referring to mark names or groups, "_" to explicitly allow all marks, or "" to disallow marks. When not given, nodes with inline content default to allowing all marks, other nodes default to not allowing marks.

    group: ?⁠string
    The group or space-separated groups to which this node belongs, which can be referred to in the content expressions for the schema.

    inline: ?⁠bool
    Should be set to true for inline nodes. (Implied for text nodes.)

    atom: ?⁠bool
    Can be set to true to indicate that, though this isn't a leaf node, it doesn't have directly editable content and should be treated as a single unit in the view.

    attrs: ?⁠Object<AttributeSpec>
    The attributes that nodes of this type get.

    selectable: ?⁠bool
    Controls whether nodes of this type can be selected as a node selection. Defaults to true for non-text nodes.

    draggable: ?⁠bool
    Determines whether nodes of this type can be dragged without being selected. Defaults to false.

    code: ?⁠bool
    Can be used to indicate that this node contains code, which causes some commands to behave differently.

    defining: ?⁠bool
    Determines whether this node is considered an important parent node during replace operations (such as paste). Non-defining (the default) nodes get dropped when their entire content is replaced, whereas defining nodes persist and wrap the inserted content. Likewise, in inserted content the defining parents of the content are preserved when possible. Typically, non-default-paragraph textblock types, and possibly list items, are marked as defining.

    isolating: ?⁠bool
    When enabled (default is false), the sides of nodes of this type count as boundaries that regular editing operations, like backspacing or lifting, won't cross. An example of a node that should probably have this enabled is a table cell.

    toDOM: ?⁠fn(node: Node) → DOMOutputSpec
    Defines the default way a node of this type should be serialized to DOM/HTML (as used by DOMSerializer.fromSchema). Should return a DOM node or an array structure that describes one, with an optional number zero (“hole”) in it to indicate where the node's content should be inserted.

    For text nodes, the default is to create a text DOM node. Though it is possible to create a serializer where text is rendered differently, this is not supported inside the editor, so you shouldn't override that in your text node spec.

    parseDOM: ?⁠[ParseRule]
    Associates DOM parser information with this node, which can be used by DOMParser.fromSchema to automatically derive a parser. The node field in the rules is implied (the name of this node will be filled in automatically). If you supply your own parser, you do not need to also specify parsing rules in your schema.

    toDebugString: ?⁠fn(node: Node) → string
    Defines the default way a node of this type should be serialized to a string representation for debugging (e.g. in error messages).
   */
  type t;

  let make:
    (
      ~content: string=?,
      ~marks: string=?,
      ~group: string=?,
      ~inline: bool=?,
      ~atom: bool=?,
      ~attrs: Js.Dict.t(AttributeSpec.t)=?,
      ~selectable: bool=?,
      ~draggable: bool=?,
      ~code: bool=?,
      ~defining: bool=?,
      ~isolating: bool=?,
      ~toDOM: PM_Types.node => DOMOutputSpec.t=?,
      ~parseDOM: array(ParseRule.t)=?,
      ~toDebugString: PM_Types.node => string=?,
      ~custom: Custom.t=?,
      unit
    ) =>
    t;

  [@ocaml.deprecated "Use `NodeSpec.make`"]
  let t:
    (
      ~content: string=?,
      ~marks: string=?,
      ~group: string=?,
      ~inline: bool=?,
      ~atom: bool=?,
      ~attrs: Js.Dict.t(AttributeSpec.t)=?,
      ~selectable: bool=?,
      ~draggable: bool=?,
      ~code: bool=?,
      ~defining: bool=?,
      ~isolating: bool=?,
      ~toDOM: PM_Types.node => DOMOutputSpec.t=?,
      ~parseDOM: array(ParseRule.t)=?,
      ~toDebugString: PM_Types.node => string=?,
      unit
    ) =>
    t;

  let content: t => option(string);

  let marks: t => option(string);

  let inline: t => option(bool);

  let atom: t => option(bool);

  let attrs: t => option(Js.Dict.t(AttributeSpec.t));

  let selectable: t => option(bool);

  let draggable: t => option(bool);

  let code: t => option(bool);

  let defining: t => option(bool);

  let isolating: t => option(bool);

  let toDOM: t => option(PM_Types.node => DOMOutputSpec.t);

  let parseDOM: t => option(array(ParseRule.t));

  let toDebugString: t => option(PM_Types.node => string);

  let custom: t => option(Custom.t);
};

module NodeType: {
  /**
   Node types are objects allocated once per Schema and used to tag Node instances.
   They contain information about the node type,
   such as its name and what kind of node it represents.
   */

  type t = PM_Types.nodeType;

  /**
    The name the node type has in this schema.
    name: string
   */
  let name: t => string;

  /**
   A link back to the Schema the node type belongs to.
   schema: Schema
   */
  let schema: t => PM_Types.schema;

  /**
    The spec that this type is based on
    spec: NodeSpec
   */
  let spec: t => NodeSpec.t;

  /**
   The starting match of the node type's content expression.
   contentMatch: ContentMatch
   */
  let contentMatch: t => ContentMatch.t;

  /**
   True if this node type has inline content.
   `inlineContent` in Prosemirror API
   inlineContent: bool
   */
  let hasInlineContent: t => bool;

  /**
   True if this is a block type
   isBlock: bool
   */
  let isBlock: t => bool;

  /**
   True if this is the text node type
   isText: bool
   */
  let isText: t => bool;

  /**
   True if this is an inline type.
   isInline: bool
   */
  let isInline: t => bool;

  /**
   True if this is a textblock type, a block that contains inline content.
   isTextblock: bool
   */
  let isTextBlock: t => bool;

  /**
   isLeaf: bool
   True for node types that allow no content.
   */
  let isLeaf: t => bool;

  /**
      True when this node is an atom, i.e. when it does not have directly editable content.
      isAtom: bool
   */
  let isAtom: t => bool;

  /**
      Create a Node of this type.
      The given attributes are checked and defaulted
      (you can pass null to use the type's defaults entirely, if no required attributes exist).
      Content may be a Fragment, a node, an array of nodes, or null.
      Similarly marks may be null to default to the empty set of marks.
      create(attrs: ?⁠Object, content: ?⁠Fragment | Node | [Node], marks: ?⁠[Mark]) → Node
   */
  let create:
    (
      t,
      ~attrs: Attrs.t=?,
      ~content: [
                  | `Fragment(PM_Types.fragment)
                  | `Node(PM_Types.node)
                  | `NodeArray(array(PM_Types.node))
                ]
                  =?,
      ~marks: array(PM_Types.mark)=?,
      unit
    ) =>
    PM_Types.node;

  /**
   Like create, but check the given content against the node type's content restrictions,
   and throw an error if it doesn't match.
   createChecked(attrs: ?⁠Object, content: ?⁠Fragment | Node | [Node], marks: ?⁠[Mark]) → Node
   */
  let createCheckedExn:
    (
      t,
      ~attrs: Attrs.t=?,
      ~content: [
                  | `Fragment(PM_Types.fragment)
                  | `Node(PM_Types.node)
                  | `NodeArray(array(PM_Types.node))
                ]
                  =?,
      ~marks: array(PM_Types.mark)=?,
      unit
    ) =>
    PM_Types.node;

  /**
    Like create, but see if it is necessary to add nodes to the start or end
    of the given fragment to make it fit the node. If no fitting wrapping can be found,
    return null. Note that, due to the fact that required nodes can always be created,
    this will always succeed if you pass null or Fragment.empty as content.
    createAndFill(attrs: ?⁠Object, content: ?⁠Fragment | Node | [Node], marks: ?⁠[Mark]) → ?⁠Node
   */
  let createAndFill:
    (
      t,
      ~attrs: Attrs.t=?,
      ~content: [
                  | `Fragment(PM_Types.fragment)
                  | `Node(PM_Types.node)
                  | `NodeArray(array(PM_Types.node))
                ]
                  =?,
      ~marks: array(PM_Types.mark)=?,
      unit
    ) =>
    option(PM_Types.node);

  /**
   Returns true if the given fragment is valid content for this node type with the given attributes.
   validContent(content: Fragment) → bool
   */
  let validContent: (t, ~content: PM_Types.fragment) => bool;

  /**
   Check whether the given mark type is allowed in this node.
   allowsMarkType(markType: MarkType) → bool
   */
  let allowsMarkType: (t, ~markType: PM_Types.markType) => bool;

  /**
    Test whether the given set of marks are allowed in this node.
    allowsMarks(marks: [Mark]) → bool
   */
  let allowsMarks: (t, ~marks: array(PM_Types.mark)) => bool;

  /**
   Removes the marks that are not allowed in this node from the given set.
   allowedMarks(marks: [Mark]) → [Mark]
   */
  let allowedMarks: (t, ~marks: array(PM_Types.mark)) => array(PM_Types.mark);

  /**
   This is not referenced in the Prosemirror documentation however it is used by offical plugins.
   Such as: prosemirror-shema-list, prosemirror-model, prosemirror-commands
   */
  let compatibleContent: (t, t) => bool;
};

module MarkSpec: {
  /**
   attrs: ?⁠Object<AttributeSpec>
   The attributes that marks of this type get.

   inclusive: ?⁠bool
   Whether this mark should be active when the cursor is positioned at its end (or at its start when that is also the start of the parent node). Defaults to true.

   excludes: ?⁠string
   Determines which other marks this mark can coexist with. Should be a space-separated strings naming other marks or groups of marks. When a mark is added to a set, all marks that it excludes are removed in the process. If the set contains any mark that excludes the new mark but is not, itself, excluded by the new mark, the mark can not be added an the set. You can use the value "_" to indicate that the mark excludes all marks in the schema.

   Defaults to only being exclusive with marks of the same type. You can set it to an empty string (or any string not containing the mark's own name) to allow multiple marks of a given type to coexist (as long as they have different attributes).

   group: ?⁠string
   The group or space-separated groups to which this mark belongs.

   spanning: ?⁠bool
   Determines whether marks of this type can span multiple adjacent nodes when serialized to DOM/HTML. Defaults to true.

   toDOM: ?⁠fn(mark: Mark, inline: bool) → DOMOutputSpec
   Defines the default way marks of this type should be serialized to DOM/HTML. When the resulting spec contains a hole, that is where the marked content is placed. Otherwise, it is appended to the top node.

   parseDOM: ?⁠[ParseRule]
   Associates DOM parser information with this mark (see the corresponding node spec field). The mark field in the rules is implied.
     */
  type t;
  let t:
    (
      ~group: string=?,
      ~attrs: Js.Dict.t(AttributeSpec.t)=?,
      ~inclusive: bool=?,
      ~spanning: bool=?,
      ~excludes: string=?,
      ~toDOM: PM_Types.node => DOMOutputSpec.t=?,
      ~parseDOM: array(ParseRule.t)=?,
      unit
    ) =>
    t;
};

module MarkType: {
  /**
   Like nodes, marks (which are associated with nodes to signify things like emphasis
   or being part of a link) are tagged with type objects, which are instantiated once per Schema.
   */
  type t = PM_Types.markType;
  /**
   The name of the mark type.
   name: string
   */
  let name: t => string;

  /**
   The schema that this mark type instance is part of.
   schema: Schema
   */
  let schema: t => PM_Types.schema;

  /**
   The spec on which the type is based.
   spec: MarkSpec
   */
  let spec: t => MarkSpec.t;

  /**
   Create a mark of this type.
   attrs may be null or an object containing only some of the mark's attributes.
   The others, if they have defaults, will be added.
   create(attrs: ?⁠Object) → Mark
   */
  let create: (t, ~attrs: Attrs.t=?, unit) => PM_Types.mark;

  /**
   When there is a mark of this type in the given set, a new set without it is returned.
   Otherwise, the input set is returned.
   removeFromSet(set: [Mark]) → [Mark]
   */
  let removeFromSet: (t, ~set: array(PM_Types.mark)) => array(PM_Types.mark);

  /**
   Tests whether there is a mark of this type in the given set.
   This is a deceptive function. The name suggests that this is a predicate.
   However it gets a mark from the array that corresponds to the MarkType that
   it is called with
   isInSet(set: [Mark]) → ?⁠Mark
   */
  let isInSet: (t, array(PM_Types.mark)) => option(PM_Types.mark);

  /**
   Queries whether a given mark type is excluded by this one.
   excludes(other: MarkType) → bool
   */
  let excludes: (t, ~other: t) => bool;
};

module SchemaSpec: {
  /**
     An object describing a schema, as passed to the Schema constructor.
   */
  type t;
  let t:
    (
      ~nodes: OrderedMap.t(NodeSpec.t),
      ~marks: OrderedMap.t(MarkSpec.t),
      ~topNode: string=?,
      unit
    ) =>
    t;

  /**
     The node types in this schema. Maps names to NodeSpec objects that describe the node type
     associated with that name. Their order is significant—it determines which parse rules take
     precedence by default, and which nodes come first in a given group.
     nodes: Object<NodeSpec> | OrderedMap<NodeSpec>
   */
  let nodes: t => OrderedMap.t(NodeSpec.t);

  /**
     The mark types that exist in this schema. The order in which they are provided determines the
     order in which mark sets are sorted and in which parse rules are tried.
     marks: ?⁠Object<MarkSpec> | OrderedMap<MarkSpec>
   */
  let marks: t => OrderedMap.t(MarkSpec.t);

  /**
     The name of the default top-level node for the schema. Defaults to "doc".
     topNode: ?⁠string
   */
  let topNode: t => option(string);
};

module Schema: {
  /**
     A document schema. Holds node and mark type objects for the nodes and marks that may occur in conforming documents, and provides functionality for creating and deserializing such documents.
   */
  type t = PM_Types.schema;

  /**
   An object mapping the schema's node names to node type objects.
   nodes: Object<NodeType>
   */
  let nodes: t => Js.Dict.t(PM_Types.nodeType);

  /**
   A map from mark names to mark type objects.
   marks: Object<MarkType>
    */
  let marks: t => Js.Dict.t(PM_Types.markType);

  /**
   The spec on which the schema is based, with the added guarantee
   that its nodes and marks properties are OrderedMap instances (not raw objects).
   spec: SchemaSpec
   */
  let spec: t => SchemaSpec.t;

  /**
   The type of the default top node for this schema.
   topNodeType: NodeType
   */
  let topNodeType: t => PM_Types.nodeType;

  /**
   An object for storing whatever values modules may want to compute and cache per schema.
   (If you want to store something in it, try to use property names unlikely to clash.)
   cached: Object
   */
  let cached: t => Attrs.t;

  /**
   Create a node in this schema. The type may be a string or a NodeType instance.
   Attributes will be extended with defaults, content may be a Fragment, null, a Node,
   or an array of nodes.
   node(type: string | NodeType, attrs: ?⁠Object, content: ?⁠Fragment | Node | [Node], marks: ?⁠[Mark]) → Node
   */
  let node:
    (
      t,
      ~type_: [ | `NodeType(PM_Types.nodeType) | `String(string)],
      ~attrs: Attrs.t=?,
      ~content: [
                  | `Fragment(PM_Types.fragment)
                  | `Node(PM_Types.node)
                  | `NodeArray(array(PM_Types.node))
                ]
                  =?,
      unit
    ) =>
    PM_Types.node;

  /**
   Create a text node in the schema. Empty text nodes are not allowed.
   text(text: string, marks: ?⁠[Mark]) → Node
   */
  let text: (t, ~text: string, ~marks: array(PM_Types.mark)=?, unit) => PM_Types.node;

  /**
   Create a mark with the given type and attributes.
   mark(type: string | MarkType, attrs: ?⁠Object) → Mark
   */
  let mark:
    (t, ~type_: [ | `MarkType(PM_Types.markType) | `String(string)], ~attrs: Attrs.t=?, unit) =>
    PM_Types.mark;

  /**
   Deserialize a node from its JSON representation. This method is bound.
   nodeFromJSON(json: Object) → Node
   */
  let nodeFromJSON: (t, Js.Json.t) => PM_Types.node;

  /**
   Deserialize a mark from its JSON representation. This method is bound.
   markFromJSON(json: Object) → Mark
   */
  let markFromJSON: (t, Js.Json.t) => PM_Types.mark;

  /**
   Construct a schema from a schema specification.
   new Schema(spec: SchemaSpec)
   */
  let make: SchemaSpec.t => t;
};

module Node: {
  /**
    This class represents a node in the tree that makes up a ProseMirror document.
    So a document is an instance of Node, with children that are also instances of Node.
    Nodes are persistent data structures. Instead of changing them, you create new ones
    with the content you want. Old ones keep pointing at the old document shape.
    This is made cheaper by sharing structure between the old and new data as much as possible,
    which a tree shape like this (without back pointers) makes easy.
   */
  type t = PM_Types.node;

  /**
     The type of node that this is.
     type: NodeType
   */
  let type_: t => NodeType.t;

  /**
     An object mapping attribute names to values.
     The kind of attributes allowed and required are determined by the node type.
     attrs: Object
   */
  let attrs: t => Attrs.t;

  /**
    A container holding the node's children.
    content: Fragment
   */
  let content: t => PM_Types.fragment;

  /**
    The marks (things like whether it is emphasized or part of a link) applied to this node.
    marks: [Mark]
   */
  let marks: t => array(Mark.t);

  /**
    For text nodes, this contains the node's text content.
    text: ?⁠string
   */
  let text: t => option(string);

  /**
   The size of this node, as defined by the integer-based indexing scheme.
   For text nodes, this is the amount of characters. For other leaf nodes,
   it is one. For non-leaf nodes, it is the size of the _content plus two (the start and end token)_.
   nodeSize: number
   */
  let nodeSize: t => int;

  /**
   The number of children that the node has.
   childCount: number
   */
  let childCount: t => int;

  /**
   Get the child node at the given index.
   Raises an error when the index is out of range.
   child(index: number) → Node
   */
  let childExn: (t, int) => t;

  /**
   Get the child node at the given index, if it exists.
   maybeChild(index: number) → ?⁠Node
   */
  let maybeChild: (t, int) => option(t);

  /**
   Call `f` for every child node, passing the node,
   its offset into this parent node, and its index.
   forEach(f: fn(node: Node, offset: number, index: number))
   */
  let forEach: (t, ~f: (~node: t, ~offset: int, ~index: int) => unit) => unit;

  /**
   Invoke a _callback_ for all descendant nodes recursively
   between the given two positions that are relative to start of this node's content.
   _The callback_ is invoked with the node, its parent-relative position,
   its parent node, and its child index.
   When the callback returns false for a given node, that node's children will not be recursed over.
   The _last parameter_ can be used to specify a starting position to count from.
   nodesBetween(from: number, to: number, f: fn(node: Node, pos: number, parent: Node, index: number) → ?⁠bool, startPos: ?⁠number = 0)
   */
  let nodesBetween:
    (
      t,
      ~from: int,
      ~to_: int,
      ~f: (~node: t, ~pos: int, ~parent: t, ~index: int) => bool,
      ~startPos: int=?,
      unit
    ) =>
    unit;

  /**
   Call the given callback for every descendant node.
   Doesn't descend into a node when the callback returns false.
   descendants(f: fn(node: Node, pos: number, parent: Node) → ?⁠bool)
   */
  let descendants: (t, ~f: (~node: t, ~pos: int, ~parent: t) => bool) => unit;

  /**
    Concatenates all the text nodes found in this fragment and its children.
    textContent: string
   */
  let textContent: t => string;

  /**
    Get all text between positions from and to.
    When blockSeparator is given, it will be inserted whenever a new block node is started.
    When leafText is given, it'll be inserted for every non-text leaf node encountered.
    textBetween(from: number, to: number, blockSeparator: ?⁠string, leafText: ?⁠string) → string
   */
  let textBetween:
    (t, ~from: int, ~to_: int, ~blockSeparator: string=?, ~leafText: string=?, unit) => string;

  /**
    Returns this node's first child, if it has children
    firstChild: ?⁠Node
   */
  let firstChild: t => option(t);

  /**
   lastChild: ?⁠Node
   Returns this node's last child, if it has children
   */
  let lastChild: t => option(t);

  /**
    Test whether two nodes represent the same piece of document.
    eq(other: Node) → bool
   */
  let eq: (t, t) => bool;

  /**
    Compare the markup (type, attributes, and marks) of this node to those of another.
    Returns true if both have the same markup.
    sameMarkup(other: Node) → bool
   */
  let sameMarkUp: (t, t) => bool;

  /**
     Check whether this node's markup correspond to the given type, attributes, and marks.
     hasMarkup(type: NodeType, attrs: ?⁠Object, marks: ?⁠[Mark]) → bool
   */
  let hasMarkup:
    (t, ~type_: NodeType.t, ~attrs: Attrs.t=?, ~marks: array(Mark.t)=?, unit) => bool;

  /**
   Create a new node with the same markup as this node, containing the given content (or empty, if no content is given).
   copy(content: ?⁠Fragment = null) → Node
   */
  let copy: (t, ~content: PM_Types.fragment=?, unit) => t;

  /**
   Create a copy of this node, with the given set of marks instead of the node's own marks.
   mark(marks: [Mark]) → Node
    */
  let mark: (t, ~marks: array(Mark.t)) => t;

  /**
    Create a copy of this node with only the content between the given positions.
    If to is not given, it defaults to the end of the node.
    cut(from: number, to: ?⁠number) → Node
   */
  let cut: (t, ~from: int, ~to_: int=?, unit) => t;

  /**
    Cut out the part of the document between the given positions, and return it as a Slice object.
    slice(from: number, to: ?⁠number = this.content.size) → Slice
   */
  let slice: (t, ~from: int, ~to_: int=?, unit) => Slice.t;

  /**
     Replace the part of the document between the given positions with the given slice.
     The slice must 'fit', meaning its open sides must be able to connect to the surrounding
     content, and its content nodes must be valid children for the node they are placed into.
     If any of this is violated, an error of type ReplaceError is thrown.
     replace(from: number, to: number, slice: Slice) → Node
   */
  let replaceExn: (t, ~from: int, ~to_: int, ~slice: Slice.t) => t;

  /**
    Find the node directly after the given position.
    nodeAt(pos: number) → ?⁠Node
   */
  let nodeAt: (t, ~pos: int) => option(t);

  /**
    Find the (direct) child node after the given offset,
    if any, and return it along with its index and offset relative to this node.
    childAfter(pos: number) → {node: ?⁠Node, index: number, offset: number}
   */
  let childAfter:
    (t, ~pos: int) =>
    {
      .
      "node": Js.Nullable.t(t),
      "index": int,
      "offset": int,
    };

  /**
    Find the (direct) child node before the given offset,
    if any, and return it along with its index and offset relative to this node.
    childBefore(pos: number) → {node: ?⁠Node, index: number, offset: number}
   */
  let childBefore:
    (t, ~pos: int) =>
    {
      .
      "node": Js.Nullable.t(t),
      "index": int,
      "offset": int,
    };

  /**
    Resolve the given position in the document, returning
    an object with information about its context.
    resolve(pos: number) → ResolvedPos
   */
  let resolve: (t, ~pos: int) => PM_Types.resolvedPos;

  /**
    Test whether a mark of the given type occurs in this document between the two given positions.
    rangeHasMark(from: number, to: number, type: MarkType) → bool
   */
  let rangeHasMark: (t, ~from: int, ~to_: int, ~type_: MarkType.t) => bool;

  /**
    True when this is a block (non-inline node)
    isBlock: bool
   */
  let isBlock: t => bool;

  /**
    True when this is a textblock node, a block node with inline content.
    isTextblock: bool
   */
  let isTextblock: t => bool;

  /**
    True when this node allows inline content.
    inlineContent: bool
   */
  let inlineContent: t => bool;

  /** isInline: bool */
  /** True when this is an inline node (a text node or a node that can appear among text). */
  let isInline: t => bool;

  /**
    True when this is a text node.
    isText: bool
   */
  let isText: t => bool;

  /**
    True when this is a leaf node.
    isLeaf: bool
   */
  let isLeaf: t => bool;

  /**
    True when this is an atom, i.e. when it does not have directly editable content.
    This is usually the same as isLeaf, but can be configured with the atom property
    on a node's spec (typically used when the node is displayed as an uneditable node view).
    isAtom: bool
   */
  let isAtom: t => bool;

  /**
    Return a string representation of this node for debugging purposes.
    toString() → string
   */
  let toString: t => string;

  /**
     Get the content match in this node at the given index.
     contentMatchAt(index: number) → ContentMatch
   */
  let contentMatchAt: (t, ~index: int) => ContentMatch.t;

  /**
     Test whether replacing the range between from and to (by child index)
     with the given replacement fragment (which defaults to the empty fragment)
     would leave the node's content valid.
     You can optionally pass start and end indices into the replacement fragment.
    canReplace(from: number, to: number, replacement: ?⁠Fragment = Fragment.empty, start: ?⁠number = 0, end: ?⁠number) → bool
   */
  let canReplace:
    (
      t,
      ~from: int,
      ~to_: int,
      ~replacement: PM_Types.fragment,
      ~start: int=?,
      ~end_: int=?,
      unit
    ) =>
    bool;

  /**
    Test whether replacing the range from to to (by index)
    with a node of the given type would leave the node's content valid.
    canReplaceWith(from: number, to: number, type: NodeType, marks: ?⁠[Mark]) → bool
   */
  let canReplaceWith:
    (t, ~from: int, ~to_: int, ~type_: NodeType.t, ~marks: array(Mark.t)=?, unit) => bool;

  /**
     Test whether the given node's content could be appended to this node.
     If that node is empty, this will only return true if there is at least
     one node type that can appear in both nodes (to avoid merging completely incompatible nodes).
     canAppend(other: Node) → bool
   */
  let canAppend: (t, ~other: t) => bool;

  /**
    Check whether this node and its descendants conform to the schema,
    and raise error when they do not.
    check()
   */
  let checkExn: t => bool;

  /**
    Return a JSON-serializeable representation of this node.
    toJSON() → Object
   */
  let toJSON: t => Js.Json.t;

  /**
    Deserialize a node from its JSON representation.
    static fromJSON(schema: Schema, json: Object) → Node
   */
  let fromJSON: (~schema: Schema.t, ~json: Js.Json.t) => t;
};

module ResolvedPos: {
  /**
    You can resolve a position to get more information about it.
    Objects of this class represent such a resolved position,
    providing various pieces of context information, and some helper methods.
    Throughout this interface, methods that take an optional depth parameter
    will interpret undefined as this.depth and negative numbers as this.depth + value.
   */
  type t = PM_Types.resolvedPos;

  /**
   pos: number
   The position that was resolved.
   */
  let pos: t => int;

  /**
   The number of levels the parent node is from the root.
   If this position points directly into the root node, it is 0.
   If it points into a top-level paragraph, 1, and so on.
   depth: number
   */
  let depth: t => int;

  /**
   The offset this position has into its parent node.
   parentOffset: number
   */
  let parentOffset: t => int;

  /**
   The parent node that the position points into.
   Note that even if a position points into a text node, that node is not considered
   the parent—text nodes are ‘flat’ in this model, and have no content.
   parent: Node
   */
  let parent: t => PM_Types.node;

  /**
   The root node in which the position was resolved.
   doc: Node
   */
  let doc: t => PM_Types.node;

  /**
   The ancestor node at the given level. p.node(p.depth) is the same as p.parent.
   node(depth: ?⁠number) → Node
   */
  let node: (t, ~depth: int=?, unit) => PM_Types.node;

  /**
   The index into the ancestor at the given level.
   If this points at the 3rd node in the 2nd paragraph on the top level,
   for example, p.index(0) is 2 and p.index(1) is 3.
   index(depth: ?⁠number) → number
   */
  let index: (t, ~depth: int=?, unit) => int;

  /**
   The index pointing after this position into the ancestor at the given level.
   indexAfter(depth: ?⁠number) → number
   */
  let indexAfter: (t, ~depth: int=?, unit) => int;

  /**
   The (absolute) position at the start of the node at the given level.
   start(depth: ?⁠number) → number
   */
  let start: (t, ~depth: int=?, unit) => int;

  /**
   The (absolute) position at the end of the node at the given level.
   end(depth: ?⁠number) → number
   */
  let end_: (t, ~depth: int=?, unit) => int;

  /**
   The (absolute) position directly before the wrapping node at the given level,
   or, when level is this.depth + 1, the original position.
   before(depth: ?⁠number) → number
   */
  let before: (t, ~depth: int=?, unit) => int;

  /**
   The (absolute) position directly after the wrapping node at the given level,
   or the original position when level is this.depth + 1.
   after(depth: ?⁠number) → number
   */
  let after: (t, ~depth: int=?, unit) => int;

  /**
   When this position points into a text node,
   this returns the distance between the position and the start of the text node.
   Will be zero for positions that point between nodes.
   textOffset: number
   */
  let textOffset: t => int;

  /**
   Get the node directly after the position, if any.
   If the position points into a text node,
   only the part of that node after the position is returned.
   nodeAfter: ?⁠Node
   */
  let nodeAfter: t => option(PM_Types.node);

  /**
   Get the node directly before the position, if any.
   If the position points into a text node,
   only the part of that node before the position is returned.
   nodeBefore: ?⁠Node
   */
  let nodeBefore: t => option(PM_Types.node);

  /**
   Get the marks at this position, factoring in the surrounding marks' inclusive property.
   If the position is at the start of a non-empty node,
   the marks of the node after it (if any) are returned.
   marks() → [Mark]
   */
  let marks: t => array(PM_Types.mark);

  /**
   Get the marks after the current position, if any,
   except those that are non-inclusive and not present at position $end.
   This is mostly useful for getting the set of marks to preserve after a deletion.
   Will return null if this position is at the end of its parent node or its parent node isn't
   a textblock (in which case no marks should be preserved).
   marksAcross($end: ResolvedPos) → ?⁠[Mark]
   */
  let marksAcross: (t, ~resolvedEnd: t) => option(array(PM_Types.mark));

  /**
   The depth up to which this position
   and the given (non-resolved) position share the same parent nodes.
   sharedDepth(pos: number) → number
   */
  let sharedDepth: (t, ~pos: int) => int;

  /**
   Returns a range based on the place where this position
   and the given position diverge around block content. If both point into the same textblock, for example, a range around that textblock will be returned. If they point into different blocks, the range around those blocks in their shared ancestor is returned. You can pass in an optional predicate that will be called with a parent node to see if a range into that parent is acceptable.
   blockRange(other: ?⁠ResolvedPos = this, pred: ?⁠fn(Node) → bool) → ?⁠NodeRange
   */
  let blockRange:
    (t, ~other: t=?, ~pred: PM_Types.node => bool=?, unit) => option(PM_Types.nodeRange);

  /**
   Query whether the given position shares the same parent node.
   sameParent(other: ResolvedPos) → bool
   */
  let sameParent: (t, ~other: t) => bool;

  /**
   Return the greater of this and the given position.
   max(other: ResolvedPos) → ResolvedPos
   */
  let max: (t, ~other: t) => t;

  /**
   Return the smaller of this and the given position.
   min(other: ResolvedPos) → ResolvedPos
   */
  let min: (t, ~other: t) => t;
};

module Fragment: {
  /**
    A fragment represents a node's collection of child nodes.
    Like nodes, fragments are persistent data structures,
    and you should not mutate them or their content.
    Rather, you create new instances whenever needed.
    The API tries to make this easy.
   */
  type t = PM_Types.fragment;
  /**
    The size of the fragment, which is the total of the size of its content nodes.
    size: number
   */
  let size: t => int;

  /**
   Invoke a callback for all descendant nodes between the given two positions
   (relative to start of this fragment).
   Doesn't descend into a node when the callback returns false.
   nodesBetween(from: number, to: number, f: fn(node: Node, start: number, parent: Node, index: number) → ?⁠bool, nodeStart: ?⁠number = 0)
   */
  let nodesBetween:
    (
      t,
      ~from: int,
      ~to_: int,
      ~f: (~node: Node.t, ~pos: int, ~parent: Node.t, ~index: int) => bool,
      ~startPos: int=?,
      unit
    ) =>
    unit;

  /**
   Call the given callback for every descendant node.
   The callback may return false to prevent traversal of a given node's children.
   descendants(f: fn(node: Node, pos: number, parent: Node) → ?⁠bool)
   */
  let descendants: (t, ~f: (~node: Node.t, ~pos: int, ~parent: Node.t) => bool) => unit;

  /**
   Create a new fragment containing the combined content of this fragment and the other.
   append(other: Fragment) → Fragment
   */
  let append: (t, ~other: t) => t;

  /**
   Cut out the sub-fragment between the two given positions.
   cut(from: number, to: ?⁠number) → Fragment
   */
  let cut: (t, ~from: int, ~to_: int=?, unit) => t;

  /**
   Create a new fragment in which the node at the given index is replaced by the given node.
   replaceChild(index: number, node: Node) → Fragment
   */
  let replaceChild: (t, ~index: int, ~node: Node.t) => t;

  /**
   Compare this fragment to another one.
   eq(other: Fragment) → bool
   */
  let eq: (t, t) => bool;

  /**
   The first child of the fragment, or null if it is empty.
   firstChild: ?⁠Node
   */
  let firstChild: t => option(Node.t);

  /**
   The last child of the fragment, or null if it is empty.
   lastChild: ?⁠Node
   */
  let lastChild: t => option(Node.t);

  /**
   The number of child nodes in this fragment.
   childCount: number
   */
  let childCount: t => int;

  /**
   Get the child node at the given index. Raise an error when the index is out of range.
   child(index: number) → Node
   */
  let childExn: (t, int) => Node.t;

  /**
   Get the child node at the given index, if it exists.
   maybeChild(index: number) → ?⁠Node
   */
  let maybeChild: (t, int) => option(Node.t);

  /**
   Call f for every child node, passing the node, its offset into this parent node, and its index.
   forEach(f: fn(node: Node, offset: number, index: number))
   */
  let forEach: (t, ~f: (~node: Node.t, ~offset: int, ~index: int) => unit) => unit;

  /**
   Find the first position at which this fragment and another fragment differ,
   or null if they are the same.
   findDiffStart(other: Fragment) → ?⁠number
   */
  let findDiffStart: (t, ~other: t) => option(int);

  /**
   Find the first position, searching from the end,
   at which this fragment and the given fragment differ,
   or null if they are the same. Since this position will not be the same in both nodes,
   an object with two separate positions is returned.
   findDiffEnd(other: Fragment) → ?⁠{a: number, b: number}
   */
  let findDiffEnd:
    (t, ~other: t) =>
    option({
      .
      "a": int,
      "b": int,
    });

  /**
   Return a debugging string that describes this fragment.
   toString() → string
   */
  let toString: t => string;

  /**
   Create a JSON-serializeable representation of this fragment.
   toJSON() → ?⁠Object
   */
  let toJSON: t => Js.Json.t;

  /**
   Deserialize a fragment from its JSON representation.
   static fromJSON(schema: Schema, value: ?⁠Object) → Fragment
   */
  let fromJSON: (Schema.t, Js.Json.t) => t;

  /**
   Build a fragment from an array of nodes.
   Ensures that adjacent text nodes with the same marks are joined together.
   static fromArray(array: [Node]) → Fragment
   */
  let fromArray: array(Node.t) => t;

  /**
   Create a fragment from something that can be interpreted as a set of nodes.
   For null, it returns the empty fragment. For a fragment, the fragment itself.
   For a node or array of nodes, a fragment containing those nodes.
   static from(nodes: ?⁠Fragment | Node | [Node]) → Fragment
   */
  let fromNode: Node.t => t;

  /**
   An empty fragment. Intended to be reused whenever a node doesn't contain anything
   (rather than allocating a new empty fragment for each leaf node).
   static empty: Fragment
   */
  let empty: t;
};

module ParseOptions: {
  /**
   These are the options recognized by the parse and parseSlice methods.

   preserveWhitespace: ?⁠bool | "full"
   By default, whitespace is collapsed as per HTML's rules. Pass true to preserve whitespace, but normalize newlines to spaces, and "full" to preserve whitespace entirely.

   findPositions: ?⁠[{node: dom.Node, offset: number}]
   When given, the parser will, beside parsing the content, record the document positions of the given DOM positions. It will do so by writing to the objects, adding a pos property that holds the document position. DOM positions that are not in the parsed content will not be written to.

   from: ?⁠number
   The child node index to start parsing from.

   to: ?⁠number
   The child node index to stop parsing at.

   topNode: ?⁠Node
   By default, the content is parsed into the schema's default top node type. You can pass this option to use the type and attributes from a different node as the top container.

   topMatch: ?⁠ContentMatch
   Provide the starting content match that content parsed into the top node is matched against.

   context: ?⁠ResolvedPos
   A set of additional nodes to count as context when parsing, above the given top node.
   */
  type t;
  module PreserveWhitespace = ParseRule.PreserveWhitespace;
  let t:
    (
      ~preserveWhitespace: PreserveWhitespace.t=?,
      ~findPositions: array({
                        .
                        "node": Dom.node,
                        "offset": int,
                      })
                        =?,
      ~from: int=?,
      ~to_: int=?,
      ~topNode: ContentMatch.t=?,
      ~context: PM_Types.resolvedPos=?,
      unit
    ) =>
    t;
};

module DOMParser: {
  /**

   A DOM parser represents a strategy for parsing DOM content into a ProseMirror document conforming to a given schema. Its behavior is defined by an array of rules.
      */
  type t;

  /**
    Create a parser that targets the given schema, using the given parsing rules.
    new DOMParser(schema: Schema, rules: [ParseRule])
   */
  let make: (~schema: Schema.t, ~rules: array(ParseRule.t)) => t;

  /**
   The schema into which the parser parses.
   schema: Schema
      */
  let schema: t => Schema.t;

  /**
   The set of parse rules that the parser uses, in order of precedence.
   rules: [ParseRule]
      */
  let rules: t => array(ParseRule.t);

  /**
   Parse a document from the content of a DOM node.
   parse(dom: dom.Node, options: ?⁠ParseOptions = {}) → Node
      */
  let parse: (t, ~dom: Dom.node, ~options: ParseOptions.t=?, unit) => Node.t;

  /**
   Parses the content of the given DOM node, like parse, and takes the same set of options. But unlike that method, which produces a whole node, this one returns a slice that is open at the sides, meaning that the schema constraints aren't applied to the start of nodes to the left of the input and the end of nodes at the end.
   parseSlice(dom: dom.Node, options: ?⁠ParseOptions = {}) → Slice
      */
  let parseSlice: (t, ~dom: Dom.node, ~options: ParseOptions.t=?, unit) => Slice.t;

  /**
   Construct a DOM parser using the parsing rules listed in a schema's node specs, reordered by priority.
   static fromSchema(schema: Schema) → DOMParser
      */
  let fromSchema: Schema.t => t;
};
