# Precis Code Point Generation

This modules contains the necessary functions for converting the unicode data points, to their IDNA derived property values.

```
type precisTypes =
    CONTEXTO
  | CONTEXTJ
  | PVALID
  | UNASSIGNED
  | FREEPVAL
  | DISALLOWED;
let fromCodePoint: BsPrecis.PrecisUtils.codePoint => precisType
```
