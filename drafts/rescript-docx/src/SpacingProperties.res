module LineRuleType = {
  type t

  @module("docx") @scope("LineRule")
  external at_least: t = "AT_LEAST"

  @module("docx") @scope("LineRule")
  external exactly: t = "EXACTLY"

  @module("docx") @scope("LineRule")
  external auto: t = "AUTO"
}

type t = {
  after?: float,
  afterAutoSpacing?: bool,
  before?: float,
  beforeAutoSpacing?: bool,
  line?: float,
  lineRule?: LineRuleType.t,
}
