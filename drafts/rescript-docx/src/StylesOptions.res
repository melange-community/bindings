type paragraphStylesPropertiesOptions = {
  alignment?: AlignmentType.t,
  contextualSpacing?: bool,
  indent?: IndentAttributesProperties.t,
  /** Specifies that all lines of the paragraph are to be kept on a single page when possible.*/
  keepLines?: bool,
  /** Specifies that the paragraph (or at least part of it) should be rendered on the same page as the next paragraph when possible. If multiple paragraphs are to be kept together but they exceed a page, then the set of paragraphs begin on a new page and page breaks are used thereafter as needed.*/
  keepNext?: bool,
  leftTabStop?: float,
  numbering?: Util.Types.numbering,
}

type baseCharacterStyleOptions = {
  /* -> to factorizes with the v11 record type spread notation */
  name?: string,
  /**
   * Specifies the style upon which the current style is based-that is, the style from which the current style inherits. It is the mechanism for implementing style inheritance.
   * Note that if the type of the current style must match the type of the style upon which it is based or the basedOn element will be ignored.
   * However, if the current style is a floating style, then the `basedOn` element is ignored.
   *
   * **WARNING**: You cannot set `basedOn` to be the same as `name`. This is akin to inheriting from itself. This creates a cyclic dependency and cause undesirable behavior.
   */
  basedOn?: string,
  next?: string,
  link?: string,
  uiPriority?: float,
  semiHidden?: bool,
  unhideWhenUsed?: bool,
  quickFormat?: bool,
  /* <- */
  run?: RunStylePropertiesOptions.t,
}

type baseParagraphStyleOptions = {
  /* -> to factorizes with the v11 record type spread notation */
  name?: string,
  /**
   * Specifies the style upon which the current style is based-that is, the style from which the current style inherits. It is the mechanism for implementing style inheritance.
   * Note that if the type of the current style must match the type of the style upon which it is based or the basedOn element will be ignored.
   * However, if the current style is a floating style, then the `basedOn` element is ignored.
   *
   * **WARNING**: You cannot set `basedOn` to be the same as `name`. This is akin to inheriting from itself. This creates a cyclic dependency and cause undesirable behavior.
   */
  basedOn?: string,
  next?: string,
  link?: string,
  uiPriority?: float,
  semiHidden?: bool,
  unhideWhenUsed?: bool,
  quickFormat?: bool,
  /* <- */
  paragraph?: paragraphStylesPropertiesOptions,
  run?: RunStylePropertiesOptions.t,
}

type documentDefaultOptions = {
  paragraph?: paragraphStylesPropertiesOptions,
  run?: RunStylePropertiesOptions.t,
}

type defaultStylesOptions = {
  document?: documentDefaultOptions,
  title?: baseParagraphStyleOptions,
  heading1?: baseParagraphStyleOptions,
  heading2?: baseParagraphStyleOptions,
  heading3?: baseParagraphStyleOptions,
  heading4?: baseParagraphStyleOptions,
  heading5?: baseParagraphStyleOptions,
  heading6?: baseParagraphStyleOptions,
  strong?: baseParagraphStyleOptions,
  listParagraph?: baseParagraphStyleOptions,
  hyperlink?: baseCharacterStyleOptions,
  footnoteReference?: baseCharacterStyleOptions,
  footnoteText?: baseParagraphStyleOptions,
  footnoteTextChar?: baseCharacterStyleOptions,
}

type characterStyleOptions = {
  /* -> to factorizes with the v11 record type spread notation */
  name?: string,
  /**
   * Specifies the style upon which the current style is based-that is, the style from which the current style inherits. It is the mechanism for implementing style inheritance.
   * Note that if the type of the current style must match the type of the style upon which it is based or the basedOn element will be ignored.
   * However, if the current style is a floating style, then the `basedOn` element is ignored.
   *
   * **WARNING**: You cannot set `basedOn` to be the same as `name`. This is akin to inheriting from itself. This creates a cyclic dependency and cause undesirable behavior.
   */
  basedOn?: string,
  next?: string,
  link?: string,
  uiPriority?: float,
  semiHidden?: bool,
  unhideWhenUsed?: bool,
  quickFormat?: bool,
  run?: RunStylePropertiesOptions.t,
  /* <- */
  id: string,
}

type paragraphStyleOptions = {
  /* -> to factorizes with the v11 record type spread notation */
  name?: string,
  /**
   * Specifies the style upon which the current style is based-that is, the style from which the current style inherits. It is the mechanism for implementing style inheritance.
   * Note that if the type of the current style must match the type of the style upon which it is based or the basedOn element will be ignored.
   * However, if the current style is a floating style, then the `basedOn` element is ignored.
   *
   * **WARNING**: You cannot set `basedOn` to be the same as `name`. This is akin to inheriting from itself. This creates a cyclic dependency and cause undesirable behavior.
   */
  basedOn?: string,
  next?: string,
  link?: string,
  uiPriority?: float,
  semiHidden?: bool,
  unhideWhenUsed?: bool,
  quickFormat?: bool,
  paragraph?: paragraphStylesPropertiesOptions,
  run?: RunStylePropertiesOptions.t,
  /* <- */
  id: string,
}

type t = {
  default?: defaultStylesOptions,
  characterStyles?: array<characterStyleOptions>,
  paragraphStyles?: array<paragraphStyleOptions>,
  // TODO:
  // initialStyles?:
  // importedStyles?:
}
