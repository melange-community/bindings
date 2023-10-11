module Span = {
  /**
   * Stores metadata for a part of a change.
   */
  type t('a) = {
    length: int,
    data: 'a,
  };
};

module Change = {
  /**
   * A replaced range with metadata associated with it.
   */
  type t('a) = {
    /** The start of the range deleted/replaced in the old document. */
    fromA: int,
    /** The end of the range in the old document */
    toA: int,
    /** The start of the range inserted in the new document. */
    fromB: int,
    /** The end of the range in the new document. */
    toB: int,
    /** Data associated with the deleted content. The length
     * of these spans adds up to `this.toA - this.fromA`. */
    deleted: array(Span.t('a)),
    /** Data associated with the inserted content.
     * Length adds up to `this.toB - this.toA`. */
    inserted: array(Span.t('a)),
  };
};

module ChangeSet = {
  /**
   * A change set tracks the changes to a document from a given point
   * in the past. It condenses a number of step maps down to a
   * flat sequence of replacements, and simplifies replacements that
   * partially undo themselves by comparing their content.
   */
  type t('a);

  /**
   * changes: [Change]
   * Replaced regions.
   */
  [@bs.get]
  external changes: t('a) => array(Change.t('a)) = "changes";

  /**
   * Computes a new changeset by adding the given step maps and metadata
   * (either as an array, per-map, or as a single value to be associated
   * with all maps) to the current set. Will not mutate the old set.
   *
   * Note that due to simplification that happens after each add,
   * incrementally adding steps might create a different final set
   * than adding all those changes at once, since different document
   * tokens might be matched during simplification depending on the
   * boundaries of the current changed ranges.
   * addSteps(newDoc: Node, maps: [StepMap], data: [any] | any) → ChangeSet
   */
  [@bs.send]
  external addSteps:
    (
      t('a),
      ~newDoc: PM_Types.node,
      ~maps: array(PM_Transform.StepMap.t),
      ~data: [@bs.unwrap] [ | `PerMap(array('a)) | `Common('a)]
    ) =>
    t('a) =
    "addSteps";

  /**
   * The starting document of the change set.
   * startDoc: Node
   */
  [@bs.get]
  external startDoc: t('a) => PM_Types.node = "startDoc";

  /**
   * Map the span's data values in the given set through a function and
   * construct a new set with the resulting data.
   * map(f: fn(range: Change) → any) → ChangeSet
   */
  [@bs.send]
  external map: (t('a), ~f: Change.t('a) => 'b) => t('b) = "map";

  type range = {
    from: int,
    to_: int,
  };

  /**
   * Compare two changesets and return the range in which they are changed,
   * if any. If the document changed between the maps, pass the maps for the
   * steps that changed it as second argument, and make sure the method is
   * called on the old set and passed the new set. The returned positions
   * will be in new document coordinates.
   * changedRange(b: ChangeSet, maps: ?[StepMap]) → ?{from: number, to: number}
   */
  [@bs.send] [@bs.return nullable]
  external changedRange:
    (t('a), ~b: t('b), ~maps: array(PM_Transform.StepMap.t)=?, unit) => option(range) =
    "changedRange";

  /**
   * Create a changeset with the given base object and configuration.
   * The combine function is used to compare and combine metadata
   * —it should return null when metadata isn't compatible, and a
   * combined version for a merged range when it is.
   * Note: in BS bindings, combine returns undefined instead of null
   * because that's how None is translated but it should work anyway
   * since its return is compared with `== null`
   * static create(doc: Node, combine: ?fn(a: any, b: any) → any) → ChangeSet
   */
  [@bs.module "prosemirror-changeset"] [@bs.scope "ChangeSet"]
  external create: (~doc: PM_Types.node, ~combine: ('a, 'a) => option('a)=?, unit) => t('a) =
    "create";

  /**
   * Simplifies a set of changes for presentation. This makes the assumption
   * that having both insertions and deletions within a word is confusing,
   * and, when such changes occur without a word boundary between them, they
   * should be expanded to cover the entire set of words (in the new document)
   * they touch. An exception is made for single-character replacements.
   * simplifyChanges(changes: [Change], doc: Node) → [Change]
   */
  [@bs.module "prosemirror-changeset"]
  external simplifyChanges:
    (~changes: array(Change.t('a)), ~doc: PM_Types.node) => array(Change.t('a)) =
    "simplifyChanges";
};
