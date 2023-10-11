/**
  The result of applying a step. Contains either a new document or a failure value.
*/
module StepResult: {
  type t;

  /**
  The transformed document.
  doc: ?⁠Node
   */
  let doc: t => option(PM_Types.node);

  /**
   Text providing information about a failed step.
   failed: ?⁠string
   */
  let failed: t => option(string);

  /**
   Create a successful step result.
   static ok(doc: Node) → StepResult
   */
  let ok: (~doc: PM_Types.node) => t;

  /**
   Create a failed step result.
   static fail(message: string) → StepResult
   */
  let fail: (~message: string) => t;

  /**
   Call Node.replace with the given arguments. Create a successful result if it succeeds,
   and a failed one if it throws a ReplaceError.
   static fromReplace(doc: Node, from: number, to: number, slice: Slice) → StepResult
   */
  let fromReplace: (~doc: PM_Types.node, ~from: int, ~to_: int, ~slice: PM_Model.Slice.t) => t;
};

/** An object representing a mapped position with extra information. */
module MapResult: {
  type t;

  /**
  The mapped version of the position.
  pos: number
  */
  let pos: t => int;

  /**
  Tells you whether the position was deleted, that is, whether the step removed its surroundings from the document.
  deleted: bool
  */
  let deleted: t => bool;
};

/**
  There are several things that positions can be mapped through. Such objects conform to this
  interface.
*/
module type MAPPABLE = {
  type t;

  /**
      Map a position through this object. When given, assoc (should be -1 or 1, defaults to 1)
      determines with which side the position is associated, which determines in which direction to move
      when a chunk of content is inserted at the mapped position.
      map(pos: number, assoc: ?⁠number) → number
      */
  let map: (t, ~pos: int, ~assoc: int=?, unit) => int;

  /**
      Map a position, and return an object containing additional information about the mapping. The
      result's deleted field tells you whether the position was deleted (completely enclosed in a
      replaced range) during the mapping. When content on only one side is deleted, the position itself
      is only considered deleted when assoc points in the direction of the deleted content.
      mapResult(pos: number, assoc: ?⁠number) → MapResult
      */
  let mapResult: (t, ~pos: int, ~assoc: int=?, unit) => MapResult.t;
};

module Mappable: {module Make: (M: {type t;}) => MAPPABLE;};

/**
  A map describing the deletions and insertions made by a step, which can be used to find the
  correspondence between positions in the pre-step version of a document and the same position in
  the post-step version.
*/
module StepMap: {
  type t;

  include MAPPABLE with type t := t;

  /**
  represented as an array of numbers, in which each group of three represents a modified chunk as
  [start, oldSize, newSize].
  new StepMap(ranges: [number]) Create a position map. The modifications to the document are
  */
  let make: (~ranges: array(int)) => t;

  /**
  Calls the given function on each of the changed ranges included in this map.
  forEach(f: fn(oldStart: number, oldEnd: number, newStart: number, newEnd: number))
  */
  let forEach:
    (t, ~fn: (~oldStart: int, ~oldEnd: int, ~newStart: int, ~newEnd: int) => unit) => unit;

  /**
  Create an inverted version of this map. The result can be used to map positions
  in the post-step document to the pre-step document.
  invert() → StepMap
  */
  let invert: t => unit;

  /**
  Create a map that moves all positions by offset n (which may be
  negative). This can be useful when applying steps meant for a sub-document to a larger document, or
  vice-versa.
  static offset(n: number) → StepMap
  **/
  let offset: (~n: int) => t;
};

/**
  Mapping positions from one document to another by running through the step maps produced by steps
  is an important operation in ProseMirror. It is used, for example, for updating the selection when
  the document changes.
  A mapping represents a pipeline of zero or more step maps. It has special provisions for
  losslessly handling mapping positions through a series of steps in which some steps are inverted
  versions of earlier steps. (This comes up when ‘rebasing’ steps for collaboration or history
  management.)
*/
module Mapping: {
  type t;

  include MAPPABLE with type t := t;

  /**
    Create a new mapping with the given position maps.
    new Mapping(maps: ?⁠[StepMap])
   */
  let make: (~maps: array(StepMap.t)=?, unit) => t;

  /**
   The step maps in this mapping.
   maps: [StepMap]
  */
  let maps: t => array(StepMap.t);

  /**
   The starting position in the maps array, used when map or mapResult is called.
   from: number
  */
  let from: t => int;

  /**
   The end position in the maps array.
   to: number
  */
  let to_: t => int;

  /**
   Create a mapping that maps only through a part of this one.
   slice(from: ?⁠number = 0, to: ?⁠number = this.maps.length) → Mapping
  */
  let slice: (t, ~from: int=?, ~to_: int=?, unit) => t;

  /**
   Add a step map to the end of this mapping. If mirrors is given, it should be the index of the step map that is the mirror image of this one.
   appendMap(map: StepMap, mirrors: ?⁠number)
  */
  let appendMap: (t, ~map: StepMap.t, ~mirrors: int=?, unit) => unit;

  /**
   Add all the step maps in a given mapping to this one (preserving mirroring information).
   appendMapping(mapping: Mapping)
  */
  let appendMapping: (t, ~mapping: t) => unit;

  /**
   Finds the offset of the step map that mirrors the map at the given offset, in this mapping (as per the second argument to appendMap).
   getMirror(n: number) → ?⁠number
  */
  let getMirror: (t, ~number: int) => option(int);

  /**
   Append the inverse of the given mapping to this one.
   appendMappingInverted(mapping: Mapping)
  */
  let appendMappingInverted: (t, ~mapping: t) => unit;
};

/** ProseMirror libraries rely on reflection (instanceof) for distinguishing a particular Step
  subclass. As we don't have a straightforward reflection mechanism we have to rely on some "dirty"
  tricks to figure out which subclass we are dealing with. It's implemented using a classify function
  that returns the polymorphic variant corresponding to the given subclass using javascript
  classname underneath */
module StepKind: {
  type t = [
    | `ReplaceStep(PM_Types.replaceStep)
    | `ReplaceAroundStep(PM_Types.replaceAroundStep)
    | `AddMarkStep(PM_Types.addMarkStep)
    | `RemoveMarkStep(PM_Types.removeMarkStep)
  ];

  let classify: PM_Types.step => t;

  let classifyCustom:
    (PM_Types.step, ~custom: (PM_Types.step, string) => option([> t] as 'a)) => ([> t] as 'a);

  let replaceStepToStep: PM_Types.replaceStep => PM_Types.step;

  let replaceAroundStepToStep: PM_Types.replaceAroundStep => PM_Types.step;

  let addMarkStepToStep: PM_Types.addMarkStep => PM_Types.step;

  let removeMarkStepToStep: PM_Types.removeMarkStep => PM_Types.step;

  let toStep: t => PM_Types.step;

  let toStepCustom: (~custom: ([> t] as 'a) => PM_Types.step, [> t] as 'a) => PM_Types.step;
};

/**
A step object represents an atomic change.
It generally applies only to the document it was created for, since the positions stored in it
will only make sense for that document. New steps are defined by creating classes that extend Step,
overriding the apply, invert, map, getMap and fromJSON methods, and registering your class
with a unique JSON-serialization identifier using Step.jsonID.
 */
module Step: {
  type t = PM_Types.step;

  module type M = {
    type t;

    type inverted;
  };

  module type T = {
    type t;

    type inverted;

    /**
    Applies this step to the given document, returning a result object that either
    indicates failure, if the step can not be applied to this document, or indicates success
    by containing a transformed document.
    apply(doc: Node) → StepResult
    */
    let apply: (t, ~doc: PM_Types.node) => StepResult.t;

    /**
      Get the step map that represents the changes made by this step,
      and which can be used to transform between positions in the old and the new document.
      getMap() → StepMap
    */
    let getMap: t => StepMap.t;

    /**
      Create an inverted version of this step.
      Needs the document as it was before the step as argument.
      invert(doc: Node) → Step
    */
    let invert: (t, ~doc: PM_Types.node) => inverted;

    /**
      Map this step through a mappable thing, returning either a
      version of that step with its positions adjusted, or null if the step
      was entirely deleted by the mapping.
      map(mapping: Mappable) → ?⁠Step
    */
    let map: (t, ~mapping: Mapping.t) => option(t);

    /**
      Try to merge this step with another one, to be applied directly after it.
      Returns the merged step when possible, null if the steps can't be merged.
      merge(other: Step) → ?⁠Step
    */
    let merge: (t, ~other: t) => option(t);

    /**
      Create a JSON-serializeable representation of this step.
      When defining this for a custom subclass, make sure the result object includes
      the step type's JSON id under the stepType property.
      toJSON() → Object
    */
    let toJSON: t => Js.Json.t;

    /**
      Deserialize a step from its JSON representation.
      Will call through to the step class' own implementation of this method.
      static fromJSON(schema: Schema, json: Object) → Step
    */
    let fromJSON: (PM_Model.Schema.t, Js.Json.t) => t;

    /**
      To be able to serialize steps to JSON, each step needs a string ID to attach
      to its JSON representation. Use this method to register an ID for your step classes.
      Try to pick something that's unlikely to clash with steps from other modules.
      static jsonID(id: string, stepClass: constructor<Step>)
    */
    let jsonID: (~id: string, ~stepClass: t) => t;
  };

  module Make: (M: M) => T with type t := M.t and type inverted := M.inverted;

  module type Subclass = {
    include T;

    let toStep: t => PM_Types.step;
  };

  include T with type t := t and type inverted := t;

  let classify: PM_Types.step => [ StepKind.t];

  let classifyCustom:
    (PM_Types.step, ~custom: (PM_Types.step, string) => option([> StepKind.t] as 'a)) =>
    ([> StepKind.t] as 'a);

  let toStep: StepKind.t => PM_Types.step;

  let toStepCustom:
    (~custom: ([> StepKind.t] as 'a) => PM_Types.step, [> StepKind.t] as 'a) => PM_Types.step;
};

/** Add a mark to all inline content between two positions.*/
module AddMarkStep: {
  type t = PM_Types.addMarkStep;

  type inverted = PM_Types.removeMarkStep;

  include Step.Subclass with type t := t and type inverted := inverted;

  let make: (~from: int, ~to_: int, ~mark: PM_Model.Mark.t) => t;

  let from: t => int;

  let to_: t => int;

  let mark: t => PM_Model.Mark.t;
};

/** Remove a mark from all inline content between two positions. */
module RemoveMarkStep: {
  type t = PM_Types.removeMarkStep;

  type inverted = PM_Types.addMarkStep;

  include Step.Subclass with type t := t and type inverted := inverted;

  let make: (~from: int, ~to_: int, ~mark: PM_Model.Mark.t) => t;

  let from: t => int;

  let to_: t => int;

  let mark: t => PM_Model.Mark.t;
};

/** Replace a part of the document with a slice of new content. */
module ReplaceStep: {
  type t = PM_Types.replaceStep;

  type inverted = t;

  include Step.Subclass with type t := t and type inverted := inverted;

  /**
    The given slice should fit the 'gap' between from and to—the depths must line up, and the
    surrounding nodes must be able to be joined with the open sides of the slice. When structure is
    true, the step will fail if the content between from and to is not just a sequence of closing
    and then opening tokens (this is to guard against rebased replace steps overwriting something
    they weren't supposed to).
    new ReplaceStep(from: number, to: number, slice: Slice, structure: ?⁠bool)
   */
  let make: (~from: int, ~to_: int, ~slice: PM_Model.Slice.t, ~structure: bool=?, unit) => t;

  let from: t => int;

  let to_: t => int;

  let slice: t => PM_Model.Slice.t;

  let structure: t => bool;
};

/** Replace a part of the document with a slice of content, but preserve a range of the replaced
  content by moving it into the slice. */
module ReplaceAroundStep: {
  type t = PM_Types.replaceAroundStep;

  type inverted = t;

  include Step.Subclass with type t := t and type inverted := inverted;

  let make:
    (
      ~from: int,
      ~to_: int,
      ~gapFrom: int,
      ~gapTo: int,
      ~slice: PM_Model.Slice.t,
      ~insert: int,
      ~structure: bool=?,
      unit
    ) =>
    t;

  let from: t => int;

  let to_: t => int;

  let gapFrom: t => int;

  let gapTo: t => int;

  let slice: t => PM_Model.Slice.t;

  let insert: t => int;

  let structure: t => bool;
};

/**
  Because you often need to collect a number of steps together to effect a composite change,
  ProseMirror provides an abstraction to make this easy. State transactions are a subclass of
  transforms. Abstraction to build up and track an array of steps representing a document
  transformation. Most transforming methods return the Transform object itself, so that they can be
  chained.
*/
module Transform: {
  module type T = {
    type t;

    /**
      doc: Node
      The current document (the result of applying the steps in the transform).
     */
    let doc: t => PM_Model.Node.t;

    /**
      The steps in this transform.
      steps: [Step]
     */
    let steps: t => array(Step.t);

    /**
      The documents before each of the steps.
      docs: [Node]
     */
    let docs: t => array(PM_Model.Node.t);

    /**
      A mapping with the maps for each of the steps in this transform.
      mapping: Mapping
     */
    let mapping: t => Mapping.t;

    /**
      The starting document.
      before: Node
     */
    let before: t => PM_Model.Node.t;

    /**
      Apply a new step in this transform, saving the result. Throws an error when the step fails.
      step(step: Step) → this
     */
    let step: (t, ~step: Step.t) => t;

    /**
      Try to apply a step in this transformation, ignoring it if it fails. Returns the step result.
      maybeStep(step: Step) → StepResult
     */
    let maybeStep: (t, ~step: Step.t) => StepResult.t;

    /**
      True when the document has been changed (when there are any steps).
      docChanged: bool
     */
    let docChanged: t => bool;

    /**
      Add the given mark to the inline content between from and to.
      addMark(from: number, to: number, mark: Mark) → this
     */
    let addMark: (t, ~from: int, ~to_: int, ~mark: PM_Model.Mark.t) => t;

    /**
      Remove marks from inline nodes between from and to. When mark is a single mark, remove precisely
      that mark. When it is a mark type, remove all marks of that type. When it is null, remove all
      marks of any type.
      removeMark(from: number, to: number, mark: ?⁠Mark | MarkType = null) → this
     */
    let removeMark:
      (
        t,
        ~from: int,
        ~to_: int,
        ~mark: [ | `Mark(PM_Model.Mark.t) | `MarkType(PM_Model.MarkType.t)]=?,
        unit
      ) =>
      t;

    /**
      Removes all marks and nodes from the content of the node at pos that don't match the given new
      parent node type. Accepts an optional starting content match as third argument.
      clearIncompatible(pos: number, parentType: NodeType, match: ?⁠ContentMatch) → this
     */
    let clearIncompatible:
      (t, ~pos: int, ~parentType: PM_Model.NodeType.t, ~match: PM_Model.ContentMatch.t=?, unit) =>
      t;

    /**
      Replace the part of the document between from and to with the given slice.
      replace(from: number, to: ?⁠number = from, slice: ?⁠Slice = Slice.empty) → this
     */
    let replace: (t, ~from: int, ~to_: int=?, ~slice: PM_Model.Slice.t=?, unit) => t;

    /**
      Replace the given range with the given content, which may be a fragment, node, or array of nodes.
      replaceWith(from: number, to: number, content: Fragment | Node | [Node]) → this
     */
    let replaceWith:
      (
        t,
        ~from: int,
        ~to_: int,
        ~content: [
                    | `Fragment(PM_Model.Fragment.t)
                    | `Node(PM_Model.Node.t)
                    | `NodeArr(array(PM_Model.Node.t))
                  ]
      ) =>
      t;

    /**
      Delete the content between the given positions.
      delete(from: number, to: number) → this
     */
    let delete: (t, ~from: int, ~to_: int) => t;

    /**
      Insert the given content at the given position.
      insert(pos: number, content: Fragment | Node | [Node]) → this
     */
    let insert:
      (
        t,
        ~pos: int,
        ~content: [
                    | `Fragment(PM_Model.Fragment.t)
                    | `Node(PM_Model.Node.t)
                    | `NodeArr(array(PM_Model.Node.t))
                  ]
      ) =>
      t;

    /**
      Replace a range of the document with a given slice, using from, to, and the slice's openStart
      property as hints, rather than fixed start and end points. This method may grow the replaced area
      or close open nodes in the slice in order to get a fit that is more in line with WYSIWYG
      expectations, by dropping fully covered parent nodes of the replaced region when they are marked
      non-defining, or including an open parent node from the slice that is marked as defining. This is
      the method, for example, to handle paste. The similar replace method is a more primitive tool
      which will not move the start and end of its given range, and is useful in situations where you
      need more precise control over what happens.
      replaceRange(from: number, to: number, slice: Slice) → this
     */
    let replaceRange: (t, ~from: int, ~to_: int, ~slice: PM_Model.Slice.t) => t;

    /**
      Replace the given range with a node, but use from and to as hints, rather than precise positions.
      When from and to are the same and are at the start or end of a parent node in which the given node
      doesn't fit, this method may move them out towards a parent that does allow the given node to be
      placed. When the given range completely covers a parent node, this method may completely replace
      that parent node.
      replaceRangeWith(from: number, to: number, node: Node) → this
     */
    let replaceRangeWith: (t, ~from: int, ~to_: int, ~node: PM_Model.Node.t) => t;

    /**
      Delete the given range, expanding it to cover fully covered parent nodes until a valid replace is
      found.
      deleteRange(from: number, to: number) → this
     */
    let deleteRange: (t, ~from: int, ~to_: int) => t;

    /**
      Split the content in the given range off from its parent, if there is sibling content before or
      after it, and move it up the tree to the depth specified by target. You'll probably want to use
      liftTarget to compute target, to make sure the lift is valid.
      lift(range: NodeRange, target: number) → this
     */
    let lift: (t, ~range: PM_Model.NodeRange.t, ~target: int) => t;

    /**
      Wrap the given range in the given set of wrappers. The wrappers are assumed to be valid in this
      position, and should probably be computed with findWrapping.
      wrap(range: NodeRange, wrappers: [{type: NodeType, attrs: ?⁠Object}]) → this
     */
    let wrap:
      (
        t,
        ~range: PM_Model.NodeRange.t,
        ~wrappers: array({
                     .
                     "attrs": PM_Model.Attrs.t,
                     "_type": PM_Model.NodeType.t,
                   })
      ) =>
      t;

    /**
      Set the type of all textblocks (partly) between from and to to the given node type with the given
      attributes.
      setBlockType(from: number, to: ?⁠number = from, type: NodeType, attrs: ?⁠Object) → this
     */
    let setBlockType:
      (
        t,
        ~from: int,
        ~to_: int=?,
        ~type_: PM_Model.NodeType.t,
        ~attrs: PM_Model.Attrs.t=?,
        unit
      ) =>
      t;

    /**
      Change the type, attributes, and/or marks of the node at pos. When type isn't given, the existing
      node type is preserved,
      setNodeMarkup(pos: number, type: ?⁠NodeType, attrs: ?⁠Object, marks: ?⁠[Mark]) → this
     */
    let setNodeMarkup:
      (
        t,
        ~pos: int,
        ~type_: PM_Model.NodeType.t=?,
        ~attrs: PM_Model.Attrs.t=?,
        ~marks: array(PM_Model.Mark.t)=?,
        unit
      ) =>
      t;

    /**
      Split the node at the given position, and optionally, if depth is greater than one, any number of
      nodes above that. By default, the parts split off will inherit the node type of the original node.
      This can be changed by passing an array of types and attributes to use after the split.
      split(pos: number, depth: ?⁠number = 1, typesAfter: ?⁠[?⁠{type: NodeType, attrs: ?⁠Object}]) → this
     */
    let split:
      (
        t,
        ~pos: int,
        ~depth: int=?,
        ~typesAfter: array({
                       .
                       "attrs": PM_Model.Attrs.t,
                       "_type": PM_Model.NodeType.t,
                     })
                       =?,
        unit
      ) =>
      t;

    /**
      Join the blocks around the given position. If depth is 2, their last and first siblings are also
      joined, and so on.
      join(pos: number, depth: ?⁠number = 1) → this
     */
    let join: (t, ~pos: int, ~depth: int=?, unit) => t;

    /** The following helper functions can be useful when creating transformations or determining
      whether they are even possible. */

    /**
      ‘Fit’ a slice into a given position in the document, producing a step that
      inserts it. Will return null if there's no meaningful way to insert the slice
      here, or inserting it would be a no-op (an empty slice over an empty range).
      replaceStep(doc: Node, from: number, to: ?⁠number = from, slice: ?⁠Slice = Slice.empty) → ?⁠Step
     */
    let replaceStep:
      (~doc: PM_Model.Node.t, ~from: int, ~to_: int=?, ~slice: PM_Model.Slice.t=?, unit) =>
      option(Step.t);

    /**
      Try to find a target depth to which the content in the given range can be lifted. Will not go
      across isolating parent nodes.
      liftTarget(range: NodeRange) → ?⁠number
     */
    let liftTarget: (~range: PM_Model.NodeRange.t) => option(int);

    /**
      Try to find a valid way to wrap the content in the given range in a node of the given type. May
      introduce extra nodes around and inside the wrapper node, if necessary. Returns null if no valid
      wrapping could be found. When innerRange is given, that range's content is used as the content to
      fit into the wrapping, instead of the content of range.
      findWrapping(range: NodeRange, nodeType: NodeType, attrs: ?⁠Object, innerRange: ?⁠NodeRange = range) → ?⁠[{type: NodeType, attrs: ?⁠Object}]
     */
    let findWrapping:
      (
        ~range: PM_Model.NodeRange.t,
        ~nodeType: PM_Model.NodeType.t,
        ~attrs: PM_Model.Attrs.t=?,
        ~innerRange: PM_Model.NodeRange.t=?,
        unit
      ) =>
      option(
        array({
          .
          "attrs": PM_Model.Attrs.t,
          "_type": PM_Model.NodeType.t,
        }),
      );

    /**
      Check whether splitting at the given position is allowed.
      canSplit(doc: Node, pos: number, depth: ?⁠number = 1, typesAfter: ?⁠[?⁠{type: NodeType, attrs: ?⁠Object}]) → bool
     */
    let canSplit:
      (
        ~doc: PM_Model.Node.t,
        ~pos: int,
        ~depth: int=?,
        ~typesAfter: array({
                       .
                       "attrs": PM_Model.Attrs.t,
                       "_type": PM_Model.NodeType.t,
                     })
                       =?,
        unit
      ) =>
      bool;

    /**
      Test whether the blocks before and after a given position can be joined.
      canJoin(doc: Node, pos: number) → bool
     */
    let canJoin: (~doc: PM_Model.Node.t, ~pos: int) => bool;

    /**
      Find an ancestor of the given position that can be joined to the block before (or after if dir is positive). Returns the joinable point, if any.
      joinPoint(doc: Node, pos: number, dir: ?⁠number = -1) → ?⁠number
     */
    let joinPoint: (~doc: PM_Model.Node.t, ~pos: int, ~dir: int=?, unit) => option(int);

    /**
      Try to find a point where a node of the given type can be inserted near pos, by searching up the node hierarchy when pos itself isn't a valid place but is at the start or end of a node. Return null if no position was found.
      insertPoint(doc: Node, pos: number, nodeType: NodeType) → ?⁠number
     */
    let insertPoint:
      (~doc: PM_Model.Node.t, ~pos: int, ~nodeType: PM_Model.NodeType.t) => option(int);

    /**
      Finds a position at or around the given position where the given slice can be inserted. Will look at parent nodes' nearest boundary and try there, even if the original position wasn't directly at the start or end of that node. Returns null when no position was found.
      dropPoint(doc: Node, pos: number, slice: Slice) → ?⁠number
     */
    let dropPoint: (~doc: PM_Model.Node.t, ~pos: int, ~silce: PM_Model.Slice.t) => option(int);
  };

  module Make: (M: {type t;}) => T with type t := M.t;

  type t;

  /**
    Create a transform that starts with the given document.
    new Transform(doc: Node)
   */
  let make: (~doc: PM_Model.Node.t) => t;

  include T with type t := t;
};
