type precisTypes =
    CONTEXTO
  | CONTEXTJ
  | PVALID
  | UNASSIGNED
  | FREEPVAL
  | DISALLOWED;
let fromCodePoint: PrecisUtils.codePoint => precisTypes;
