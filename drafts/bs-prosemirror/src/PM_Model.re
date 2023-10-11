module Types = PM_Types;

module Attrs = {
  type t;
  external make: Js.t({..}) => t = "%identity";

  external toJs: t => Js.t({..}) = "%identity";

  let empty: unit => t = () => make(Js.Obj.empty());
};

module AttributeSpec = {
  type t;

  [@bs.obj] external make: (~default: 'a=?, unit) => t = "";
};

module DOMAttrs = {
  type t = Js.Dict.t(string);

  let make: Js.Dict.t(string) => t = a => a;

  let toDict: t => Js.Dict.t(string) = a => a;

  let empty: unit => t = Js.Dict.empty;
};

module DOMOutputSpec = {
  type spec =
    | LeafNode(string, DOMAttrs.t): spec
    | Node(string, DOMAttrs.t, spec): spec
    | Text(string): spec
    | Hole: spec;

  [@unboxed]
  type t =
    | Any('a): t;

  let fromString: string => t = a => Any(a);

  let fromDomNode: Dom.node => t = a => Any(a);

  let fromSpec: spec => t =
    a => {
      let rec run: spec => t =
        a =>
          switch (a) {
          | LeafNode(str, obj) => Any((str, obj))
          | Hole => Any(0)
          | Text(text) => Any(text)
          | Node(str, obj, y) => Any((str, obj, run(y)))
          };
      run(a);
    };
};

module DOMSerializer = {
  type t;

  [@bs.module "prosemirror-model"] [@bs.new]
  external make:
    (
      ~nodes: Js.Dict.t(Types.node => DOMOutputSpec.t),
      ~marks: Js.Dict.t((Types.mark, ~inline: bool) => DOMOutputSpec.t)
    ) =>
    t =
    "DOMSerializer";

  [@bs.get] external nodes: t => Js.Dict.t(Types.node => DOMOutputSpec.t) = "nodes";

  [@bs.get]
  external marks: t => Js.Dict.t((Types.mark, ~inline: bool) => DOMOutputSpec.t) = "marks";

  [@bs.send]
  external serializeFragment:
    (t, ~fragment: Types.fragment, ~options: Js.t({..})=?, unit) => Dom.documentFragment =
    "serializeFragment";

  [@bs.send]
  external serializeNode: (t, ~node: Types.node, ~options: Js.t({..})=?, unit) => Dom.node =
    "serializeNode";

  [@bs.module "prosemirror-model"] [@bs.scope "DOMSerializer"]
  external renderSpec:
    (~doc: Dom.document, ~structure: DOMOutputSpec.t) =>
    {
      .
      "dom": Dom.node,
      "contentDOM": Js.Nullable.t(Dom.node),
    } =
    "renderSpec";

  [@bs.module "prosemirror-model"] [@bs.scope "DOMSerializer"]
  external fromSpec: Types.schema => t = "fromSpec";
};

module ParseRule = {
  module GetAttrsResult = {
    [@unboxed]
    type t =
      | Any('a): t;

    let noMatch = () => Any(false);

    let empty = () => Any(Js.Nullable.null);

    let attrs = attrs => Any(attrs);
  };

  module GetAttrs = {
    [@unboxed]
    type t =
      | Any('a): t;

    let fromNodeFn = fn => Any(fn);

    let fromStringFn = fn => Any(fn);
  };
  module ContentElement = {
    [@unboxed]
    type t =
      | Any('a): t;

    let fromNode = fn => Any(fn);

    let fromString = s => Any(s);
  };
  module PreserveWhitespace = {
    [@unboxed]
    type t =
      | Any('a): t;

    let make = b => Any(b);

    let full = Any("full");
  };

  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    tag: string,
    [@bs.optional]
    namespace: string,
    [@bs.optional]
    style: string,
    [@bs.optional]
    priority: int,
    [@bs.optional]
    context: string,
    [@bs.optional]
    node: string,
    [@bs.optional]
    mark: string,
    [@bs.optional]
    ignore: bool,
    [@bs.optional]
    skip: bool,
    [@bs.optional]
    attrs: Attrs.t,
    [@bs.optional]
    getAttrs: GetAttrs.t,
    [@bs.optional]
    contentElement: ContentElement.t,
    [@bs.optional]
    getContent: (Dom.node, Types.schema) => Types.fragment,
    [@bs.optional]
    preserveWhitespace: PreserveWhitespace.t,
  };
};

module Mark = {
  type t = Types.mark;

  [@bs.get] external type_: t => Types.markType = "type";

  [@bs.get] external attrs: t => Attrs.t = "attrs";

  [@bs.send] external addToSet: (t, array(t)) => array(t) = "addToSet";

  [@bs.send] external removeFromSet: (t, array(t)) => array(t) = "removeFromSet";

  [@bs.send] external isInSet: (t, array(t)) => bool = "isInSet";

  [@bs.send] external eq: (t, t) => bool = "eq";

  [@bs.send] external toJSON: t => Js.Json.t = "toJSON";

  [@bs.module "prosemirror-model"] [@bs.scope "Mark"]
  external fromJSON: (~schema: Types.schema, ~json: Js.Json.t) => t = "fromJSON";

  [@bs.module "prosemirror-model"] [@bs.scope "Mark"]
  external sameSet: (~a: array(t), ~b: array(t)) => bool = "sameSet";

  [@bs.module "prosemirror-model"] [@bs.scope "Mark"]
  external setFromArray: array(t) => array(t) = "setFromArray";

  [@bs.module "prosemirror-model"] [@bs.scope "Mark"] external none: array(t) = "none";
};

module Slice = {
  type t;

  [@bs.module "prosemirror-model"] [@bs.new]
  external make: (~content: Types.fragment, ~openStart: int, ~openEnd: int) => t = "Slice";

  [@bs.get] external content: t => Types.fragment = "content";

  [@bs.get] external openStart: t => int = "openStart";

  [@bs.get] external openEnd: t => int = "openEnd";

  [@bs.get] external size: t => int = "size";

  [@bs.send] external eq: (t, t) => bool = "eq";

  [@bs.send] external toJSON: t => Js.Json.t = "toJSON";

  [@bs.module "prosemirror-model"] [@bs.scope "Slice"]
  external fromJSON: (~schema: Types.schema, ~json: Js.Json.t) => t = "fromJSON";

  [@bs.module "prosemirror-model"] [@bs.scope "Slice"]
  external maxOpen: (~fragment: Types.fragment, ~openIsolating: bool=?) => t = "maxOpen";

  [@bs.module "prosemirror-model"] [@bs.scope "Slice"] external empty: t = "empty";
};

module ContentMatch = {
  type t;

  [@bs.get] external validEnd: t => bool = "validEnd";

  [@bs.return nullable] [@bs.send]
  external matchType: (t, Types.nodeType) => option(t) = "matchType";

  [@bs.return nullable] [@bs.send]
  external matchFragment:
    (t, ~frag: Types.fragment, ~start: int=?, ~end_: int=?, unit) => option(t) =
    "matchFragment";

  [@bs.return nullable] [@bs.get]
  external defaultType: t => option(Types.nodeType) = "defaultType";

  [@bs.return nullable] [@bs.send]
  external fillBefore:
    (t, ~after: Types.fragment, ~toEnd: bool=?, ~startIndex: int=?, unit) =>
    option(Types.fragment) =
    "fillBefore";

  [@bs.return nullable] [@bs.send]
  external findWrapping: (t, Types.nodeType) => option(array(Types.nodeType)) = "findWrapping";

  [@bs.get] external edgeCount: t => int = "edgeCount";

  [@bs.send]
  external edge:
    (t, ~n: int) =>
    {
      .
      "_type": Types.nodeType,
      "next": t,
    } =
    "edge";
};

module NodeRange = {
  type t = Types.nodeRange;

  [@bs.module "prosemirror-model"] [@bs.new]
  external make:
    (~resolvedFrom: Types.resolvedPos, ~resolvedTo: Types.resolvedPos, ~depth: int) => t =
    "NodeRange";

  [@bs.get] external resolvedFrom: t => Types.resolvedPos = "$from";

  [@bs.get] external resolvedTo: t => Types.resolvedPos = "$to";

  [@bs.get] external depth: t => int = "depth";

  [@bs.get] external start: t => int = "start";

  [@bs.get] external end_: t => int = "end";

  [@bs.get] external parent: t => Types.node = "parent";

  [@bs.get] external startIndex: t => int = "startIndex";

  [@bs.get] external endIndex: t => int = "endIndex";
};

module NodeSpec = {
  module Custom = {
    type t;

    external fromJs: Js.t({..}) => t = "%identity";

    external toJs: t => Js.t({..}) = "%identity";
  };

  let toOption = Js.Null_undefined.toOption;

  let fromOption =
    fun
    | Some(a) => Js.Null_undefined.return(a)
    | None => Js.Null_undefined.undefined;

  type t = {
    .
    "content": Js.Null_undefined.t(string),
    "marks": Js.Null_undefined.t(string),
    "group": Js.Null_undefined.t(string),
    "inline": Js.Null_undefined.t(bool),
    "atom": Js.Null_undefined.t(bool),
    "attrs": Js.Null_undefined.t(Js.Dict.t(AttributeSpec.t)),
    "selectable": Js.Null_undefined.t(bool),
    "draggable": Js.Null_undefined.t(bool),
    "code": Js.Null_undefined.t(bool),
    "defining": Js.Null_undefined.t(bool),
    "isolating": Js.Null_undefined.t(bool),
    "toDOM": Js.Null_undefined.t(Types.node => DOMOutputSpec.t),
    "parseDOM": Js.Null_undefined.t(array(ParseRule.t)),
    "toDebugString": Js.Null_undefined.t(Types.node => string),
    "custom": Js.Null_undefined.t(Custom.t),
  };

  let make =
      (
        ~content: option(string)=?,
        ~marks: option(string)=?,
        ~group: option(string)=?,
        ~inline: option(bool)=?,
        ~atom: option(bool)=?,
        ~attrs: option(Js.Dict.t(AttributeSpec.t))=?,
        ~selectable: option(bool)=?,
        ~draggable: option(bool)=?,
        ~code: option(bool)=?,
        ~defining: option(bool)=?,
        ~isolating: option(bool)=?,
        ~toDOM: option(Types.node => DOMOutputSpec.t)=?,
        ~parseDOM: option(array(ParseRule.t))=?,
        ~toDebugString: option(Types.node => string)=?,
        ~custom: option(Custom.t)=?,
        (),
      )
      : t => {
    let base = {
      "content": content->fromOption,
      "marks": marks->fromOption,
      "group": group->fromOption,
      "inline": inline->fromOption,
      "atom": atom->fromOption,
      "attrs": attrs->fromOption,
      "selectable": selectable->fromOption,
      "draggable": draggable->fromOption,
      "code": code->fromOption,
      "defining": defining->fromOption,
      "isolating": isolating->fromOption,
      "toDOM": toDOM->fromOption,
      "parseDOM": parseDOM->fromOption,
      "toDebugString": toDebugString->fromOption,
      "custom": custom->fromOption,
    };
    switch (custom) {
    | Some(c) => Js.Obj.assign(base, c->Custom.toJs)
    | None => base
    };
  };

  let t = make(~custom=?None);

  let content = (a: t) => a##content->toOption;

  let marks = a => a##marks->toOption;

  let inline = a => a##inline->toOption;

  let atom = a => a##atom->toOption;

  let attrs = a => a##attrs->toOption;

  let selectable = a => a##selectable->toOption;

  let draggable = a => a##draggable->toOption;

  let code = a => a##code->toOption;

  let defining = a => a##defining->toOption;

  let isolating = a => a##isolating->toOption;

  let toDOM = a => a##toDOM->toOption;

  let parseDOM = a => a##parseDOM->toOption;

  let toDebugString = a => a##toDebugString->toOption;

  let custom = a => a##custom->toOption;
};

module NodeType = {
  type t = Types.nodeType;

  [@bs.get] external name: t => string = "name";

  [@bs.get] external schema: t => Types.schema = "schema";

  [@bs.get] external spec: t => NodeSpec.t = "spec";

  [@bs.get] external contentMatch: t => ContentMatch.t = "contentMatch";

  [@bs.get] external hasInlineContent: t => bool = "inlineContent";

  [@bs.get] external isBlock: t => bool = "isBlock";

  [@bs.get] external isText: t => bool = "isText";

  [@bs.get] external isInline: t => bool = "isInline";

  [@bs.get] external isTextBlock: t => bool = "isTextBlock";

  [@bs.get] external isLeaf: t => bool = "isLeaf";

  [@bs.get] external isAtom: t => bool = "isAtom";

  [@bs.send]
  external create:
    (
      t,
      ~attrs: Attrs.t=?,
      ~content: [@bs.unwrap] [
                  | `Fragment(Types.fragment)
                  | `Node(Types.node)
                  | `NodeArray(array(Types.node))
                ]
                  =?,
      ~marks: array(Types.mark)=?,
      unit
    ) =>
    Types.node =
    "create";

  [@bs.send]
  external createCheckedExn:
    (
      t,
      ~attrs: Attrs.t=?,
      ~content: [@bs.unwrap] [
                  | `Fragment(Types.fragment)
                  | `Node(Types.node)
                  | `NodeArray(array(Types.node))
                ]
                  =?,
      ~marks: array(Types.mark)=?,
      unit
    ) =>
    Types.node =
    "createChecked";

  [@bs.return nullable] [@bs.send]
  external createAndFill:
    (
      t,
      ~attrs: Attrs.t=?,
      ~content: [@bs.unwrap] [
                  | `Fragment(Types.fragment)
                  | `Node(Types.node)
                  | `NodeArray(array(Types.node))
                ]
                  =?,
      ~marks: array(Types.mark)=?,
      unit
    ) =>
    option(Types.node) =
    "createAndFill";

  [@bs.send] external validContent: (t, ~content: Types.fragment) => bool = "validContent";

  [@bs.send] external allowsMarkType: (t, ~markType: Types.markType) => bool = "allowsMarkType";

  [@bs.send] external allowsMarks: (t, ~marks: array(Types.mark)) => bool = "allowsMarks";

  [@bs.send]
  external allowedMarks: (t, ~marks: array(Types.mark)) => array(Types.mark) = "allowedMarks";

  [@bs.send] external compatibleContent: (t, t) => bool = "compatibleContent";
};

module MarkSpec = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    group: string,
    [@bs.optional]
    attrs: Js.Dict.t(AttributeSpec.t),
    [@bs.optional]
    inclusive: bool,
    [@bs.optional]
    spanning: bool,
    [@bs.optional]
    excludes: string,
    [@bs.optional]
    toDOM: Types.node => DOMOutputSpec.t,
    [@bs.optional]
    parseDOM: array(ParseRule.t),
  };
};

module MarkType = {
  type t = Types.markType;

  [@bs.get] external name: t => string = "name";

  [@bs.get] external schema: t => Types.schema = "schema";

  [@bs.get] external spec: t => MarkSpec.t = "spec";

  [@bs.send] external create: (t, ~attrs: Attrs.t=?, unit) => Types.mark = "create";

  [@bs.send]
  external removeFromSet: (t, ~set: array(Types.mark)) => array(Types.mark) = "removeFromSet";

  [@bs.send] [@bs.return nullable]
  external isInSet: (t, array(Types.mark)) => option(Types.mark) = "isInSet";

  [@bs.send] external excludes: (t, ~other: t) => bool = "excludes";
};

module SchemaSpec = {
  [@bs.deriving {abstract: light}]
  type t = {
    nodes: OrderedMap.t(NodeSpec.t),
    marks: OrderedMap.t(MarkSpec.t),
    [@bs.optional]
    topNode: string,
  };
};

module Schema = {
  type t = Types.schema;
  [@bs.get] external nodes: t => Js.Dict.t(Types.nodeType) = "nodes";

  [@bs.get] external marks: t => Js.Dict.t(Types.markType) = "marks";

  [@bs.get] external spec: t => SchemaSpec.t = "spec";

  [@bs.get] external topNodeType: t => Types.nodeType = "topNodeType";

  [@bs.get] external cached: t => Attrs.t = "cached";

  [@bs.send]
  external node:
    (
      t,
      ~type_: [@bs.unwrap] [ | `String(string) | `NodeType(Types.nodeType)],
      ~attrs: Attrs.t=?,
      ~content: [@bs.unwrap] [
                  | `Fragment(Types.fragment)
                  | `Node(Types.node)
                  | `NodeArray(array(Types.node))
                ]
                  =?,
      unit
    ) =>
    Types.node =
    "node";

  [@bs.send]
  external text: (t, ~text: string, ~marks: array(Types.mark)=?, unit) => Types.node = "text";

  [@bs.send]
  external mark:
    (
      t,
      ~type_: [@bs.unwrap] [ | `String(string) | `MarkType(Types.markType)],
      ~attrs: Attrs.t=?,
      unit
    ) =>
    Types.mark =
    "mark";
  [@bs.send] external nodeFromJSON: (t, Js.Json.t) => Types.node = "nodeFromJSON";

  [@bs.send] external markFromJSON: (t, Js.Json.t) => Types.mark = "markFromJSON";

  [@bs.module "prosemirror-model"] [@bs.new] external make: SchemaSpec.t => t = "Schema";
};

module Node = {
  type t = Types.node;

  [@bs.get] external type_: t => NodeType.t = "type";

  [@bs.get] external attrs: t => Attrs.t = "attrs";

  [@bs.get] external content: t => Types.fragment = "content";

  [@bs.get] external marks: t => array(Mark.t) = "marks";

  [@bs.return nullable] [@bs.get] external text: t => option(string) = "text";

  [@bs.get] external nodeSize: t => int = "nodeSize";

  [@bs.get] external childCount: t => int = "childCount";

  [@bs.send] external childExn: (t, int) => t = "child";

  [@bs.return nullable] [@bs.send] external maybeChild: (t, int) => option(t) = "maybeChild";

  [@bs.send]
  external forEach: (t, ~f: (~node: t, ~offset: int, ~index: int) => unit) => unit = "forEach";

  [@bs.send]
  external nodesBetween:
    (
      t,
      ~from: int,
      ~to_: int,
      ~f: (~node: t, ~pos: int, ~parent: t, ~index: int) => bool,
      ~startPos: int=?,
      unit
    ) =>
    unit =
    "nodesBetween";

  [@bs.send]
  external descendants: (t, ~f: (~node: t, ~pos: int, ~parent: t) => bool) => unit = "descendants";

  [@bs.get] external textContent: t => string = "textContent";

  [@bs.send]
  external textBetween:
    (t, ~from: int, ~to_: int, ~blockSeparator: string=?, ~leafText: string=?, unit) => string =
    "textBetween";

  [@bs.return nullable] [@bs.get] external firstChild: t => option(t) = "firstChild";

  [@bs.return nullable] [@bs.get] external lastChild: t => option(t) = "lastChild";

  [@bs.send] external eq: (t, t) => bool = "eq";

  [@bs.send] external sameMarkUp: (t, t) => bool = "sameMarkUp";

  [@bs.send]
  external hasMarkup:
    (t, ~type_: NodeType.t, ~attrs: Attrs.t=?, ~marks: array(Mark.t)=?, unit) => bool =
    "hasMarkup";

  [@bs.send] external copy: (t, ~content: Types.fragment=?, unit) => t = "copy";

  [@bs.send] external mark: (t, ~marks: array(Mark.t)) => t = "mark";

  [@bs.send] external cut: (t, ~from: int, ~to_: int=?, unit) => t = "cut";

  [@bs.send] external slice: (t, ~from: int, ~to_: int=?, unit) => Slice.t = "slice";

  [@bs.send] external replaceExn: (t, ~from: int, ~to_: int, ~slice: Slice.t) => t = "replace";

  [@bs.return nullable] [@bs.send] external nodeAt: (t, ~pos: int) => option(t) = "nodeAt";

  [@bs.send]
  external childAfter:
    (t, ~pos: int) =>
    {
      .
      "node": Js.Nullable.t(t),
      "index": int,
      "offset": int,
    } =
    "childAfter";

  [@bs.send]
  external childBefore:
    (t, ~pos: int) =>
    {
      .
      "node": Js.Nullable.t(t),
      "index": int,
      "offset": int,
    } =
    "childBefore";

  [@bs.send] external resolve: (t, ~pos: int) => Types.resolvedPos = "resolve";

  [@bs.send]
  external rangeHasMark: (t, ~from: int, ~to_: int, ~type_: MarkType.t) => bool = "rangeHasMark";

  [@bs.get] external isBlock: t => bool = "isBlock";

  [@bs.get] external isTextblock: t => bool = "isTextblock";

  [@bs.get] external inlineContent: t => bool = "inlineContent";

  [@bs.get] external isInline: t => bool = "isInline";

  [@bs.get] external isText: t => bool = "isText";

  [@bs.get] external isLeaf: t => bool = "isLeaf";

  [@bs.get] external isAtom: t => bool = "isAtom";

  [@bs.send] external toString: t => string = "toString";

  [@bs.send] external contentMatchAt: (t, ~index: int) => ContentMatch.t = "contentMatchAt";

  [@bs.send]
  external canReplace:
    (t, ~from: int, ~to_: int, ~replacement: Types.fragment, ~start: int=?, ~end_: int=?, unit) =>
    bool =
    "canReplace";

  [@bs.send]
  external canReplaceWith:
    (t, ~from: int, ~to_: int, ~type_: NodeType.t, ~marks: array(Mark.t)=?, unit) => bool =
    "canReplaceWith";

  [@bs.send] external canAppend: (t, ~other: t) => bool = "canAppend";

  [@bs.send] external checkExn: t => bool = "check";

  [@bs.send] external toJSON: t => Js.Json.t = "toJSON";

  [@bs.module "prosemirror-model"] [@bs.scope "Node"]
  external fromJSON: (~schema: Schema.t, ~json: Js.Json.t) => t = "fromJSON";
};

module ResolvedPos = {
  type t = Types.resolvedPos;

  [@bs.get] external pos: t => int = "pos";

  [@bs.get] external depth: t => int = "depth";

  [@bs.get] external parentOffset: t => int = "parentOffset";

  [@bs.get] external parent: t => Types.node = "parent";

  [@bs.get] external doc: t => Types.node = "doc";

  [@bs.send] external node: (t, ~depth: int=?, unit) => Types.node = "node";

  [@bs.send] external index: (t, ~depth: int=?, unit) => int = "index";

  [@bs.send] external indexAfter: (t, ~depth: int=?, unit) => int = "indexAfter";

  [@bs.send] external start: (t, ~depth: int=?, unit) => int = "start";

  [@bs.send] external end_: (t, ~depth: int=?, unit) => int = "end";

  [@bs.send] external before: (t, ~depth: int=?, unit) => int = "before";

  [@bs.send] external after: (t, ~depth: int=?, unit) => int = "after";

  [@bs.get] external textOffset: t => int = "textOffset";

  [@bs.return nullable] [@bs.get] external nodeAfter: t => option(Types.node) = "nodeAfter";

  [@bs.return nullable] [@bs.get] external nodeBefore: t => option(Types.node) = "nodeBefore";

  [@bs.send] external marks: t => array(Types.mark) = "marks";

  [@bs.return nullable] [@bs.send]
  external marksAcross: (t, ~resolvedEnd: t) => option(array(Types.mark)) = "marksAcross";

  [@bs.send] external sharedDepth: (t, ~pos: int) => int = "sharedDepth";

  [@bs.return nullable] [@bs.send]
  external blockRange:
    (t, ~other: t=?, ~pred: Types.node => bool=?, unit) => option(Types.nodeRange) =
    "blockRange";

  [@bs.send] external sameParent: (t, ~other: t) => bool = "sameParent";

  [@bs.send] external max: (t, ~other: t) => t = "max";

  [@bs.send] external min: (t, ~other: t) => t = "min";
};

module Fragment = {
  type t = Types.fragment;

  [@bs.get] external size: t => int = "size";

  [@bs.send]
  external nodesBetween:
    (
      t,
      ~from: int,
      ~to_: int,
      ~f: (~node: Node.t, ~pos: int, ~parent: Node.t, ~index: int) => bool,
      ~startPos: int=?,
      unit
    ) =>
    unit =
    "nodesBetween";

  [@bs.send]
  external descendants: (t, ~f: (~node: Node.t, ~pos: int, ~parent: Node.t) => bool) => unit =
    "descendants";

  [@bs.send] external append: (t, ~other: t) => t = "append";

  [@bs.send] external cut: (t, ~from: int, ~to_: int=?, unit) => t = "cut";

  [@bs.send] external replaceChild: (t, ~index: int, ~node: Node.t) => t = "replaceChild";

  [@bs.send] external eq: (t, t) => bool = "eq";

  [@bs.return nullable] [@bs.get] external firstChild: t => option(Node.t) = "firstChild";

  [@bs.return nullable] [@bs.get] external lastChild: t => option(Node.t) = "lastChild";

  [@bs.get] external childCount: t => int = "childCount";

  [@bs.send] external childExn: (t, int) => Node.t = "child";

  [@bs.return nullable] [@bs.send] external maybeChild: (t, int) => option(Node.t) = "maybeChild";

  [@bs.send]
  external forEach: (t, ~f: (~node: Node.t, ~offset: int, ~index: int) => unit) => unit =
    "forEach";

  [@bs.return nullable] [@bs.send]
  external findDiffStart: (t, ~other: t) => option(int) = "findDiffStart";

  [@bs.return nullable] [@bs.send]
  external findDiffEnd:
    (t, ~other: t) =>
    option({
      .
      "a": int,
      "b": int,
    }) =
    "findDiffEnd";

  [@bs.send] external toString: t => string = "toString";

  [@bs.send] external toJSON: t => Js.Json.t = "toJSON";

  [@bs.module "prosemirror-model"] [@bs.scope "Fragment"]
  external fromJSON: (Schema.t, Js.Json.t) => t = "fromJSON";

  [@bs.module "prosemirror-model"] [@bs.scope "Fragment"]
  external fromArray: array(Node.t) => t = "fromArray";

  [@bs.module "prosemirror-model"] [@bs.scope "Fragment"] external fromNode: Node.t => t = "from";

  [@bs.module "prosemirror-model"] [@bs.scope "Fragment"] external empty: t = "empty";
};

module ParseOptions = {
  module PreserveWhitespace = ParseRule.PreserveWhitespace;

  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    preserveWhitespace: PreserveWhitespace.t,
    [@bs.optional]
    findPositions:
      array({
        .
        "node": Dom.node,
        "offset": int,
      }),
    [@bs.optional]
    from: int,
    [@bs.optional] [@bs.as "to"]
    to_: int,
    [@bs.optional]
    topNode: ContentMatch.t,
    [@bs.optional]
    context: Types.resolvedPos,
  };
};

module DOMParser = {
  type t;

  [@bs.module "prosemirror-model"] [@bs.new]
  external make: (~schema: Schema.t, ~rules: array(ParseRule.t)) => t = "DOMParser";

  [@bs.get] external schema: t => Schema.t = "schema";

  [@bs.get] external rules: t => array(ParseRule.t) = "rules";

  [@bs.send]
  external parse: (t, ~dom: Dom.node, ~options: ParseOptions.t=?, unit) => Node.t = "parse";

  [@bs.send]
  external parseSlice: (t, ~dom: Dom.node, ~options: ParseOptions.t=?, unit) => Slice.t =
    "parseSlice";

  [@bs.module "prosemirror-model"] [@bs.scope "DOMParser"]
  external fromSchema: Schema.t => t = "fromSchema";
};
