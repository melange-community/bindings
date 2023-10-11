type t = {
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
}
