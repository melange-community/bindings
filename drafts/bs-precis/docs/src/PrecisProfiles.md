# Precis Profiles

This module is the main exportation from `bs-precis`. It includes, the currently 4 implemented profiles from the precis specifications. All four of them, `usernameCaseMapped`, `usernameCasePreserved`, `opaqueString`, `nickname` have the same type signatures. They are all `string => string`.

```
let bidi: list(BsPrecis.PrecisUtils.codePoint) => bool;
let usernameCaseMapped: string => Js.String.t;
let usernameCasePreserved: string => Js.String.t;
let opaqueString: string => Js.String.t;
let nickname: string => Js.String.t;
```
