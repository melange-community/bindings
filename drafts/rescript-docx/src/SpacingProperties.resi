/** @see https://docx.js.org/api/enums/LineRuleType.html */
module LineRuleType: {
  type t
  let at_least: t
  let exactly: t
  let auto: t
}

/** @see https://docx.js.org/api/interfaces/ISpacingProperties.html */
type t = {
  after?: float,
  afterAutoSpacing?: bool,
  before?: float,
  beforeAutoSpacing?: bool,
  line?: float,
  lineRule?: LineRuleType.t,
}
