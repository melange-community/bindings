type t = {
  alignment?: AlignmentType.t,
  thematicBreak?: bool,
  contextualSpacing?: bool,
  rightTabStop?: float,
  leftTabStop?: float,
  indent?: IndentAttributesProperties.t,
  /**
   * Specifies that the paragraph (or at least part of it) should be rendered on the same page as the next paragraph when possible. If multiple paragraphs are to be kept together but they exceed a page, then the set of paragraphs begin on a new page and page breaks are used thereafter as needed.
   */
  spacing?: SpacingProperties.t,
  keepNext?: bool,
  /**
   * Specifies that all lines of the paragraph are to be kept on a single page when possible.
   */
  keepLines?: bool,
  outlineLevel?: float,
}
