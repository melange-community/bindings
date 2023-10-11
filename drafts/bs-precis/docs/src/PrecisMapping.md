# Precis Mapping

This module includes all the necessary maps for Precis.
```
let stripSpaces:
  list(BsPrecis.PrecisUtils.codePoint) =>
  list(BsPrecis.PrecisUtils.codePoint);
let mapWidth:
  list(BsPrecis.PrecisUtils.codePoint) =>
  list(BsPrecis.PrecisUtils.codePoint);
let spaceMap:
  list(BsPrecis.PrecisUtils.codePoint) =>
  list(BsPrecis.PrecisUtils.codePoint);
let additionalMapping:
  list(BsPrecis.PrecisUtils.codePoint) =>
  list(BsPrecis.PrecisUtils.codePoint);
let trim:
  list(BsPrecis.PrecisUtils.codePoint) =>
  list(BsPrecis.PrecisUtils.codePoint);
let lastLetterMap:
  BsPrecis.PrecisUtils.codePoint => BsPrecis.PrecisUtils.codePoint;
let lowerCaseMap:
  BsPrecis.PrecisUtils.codePoint => BsPrecis.PrecisUtils.codePoint;
let replaceTrailers:
  (list(BsPrecis.PrecisUtils.codePoint),
  list(BsPrecis.PrecisUtils.codePoint)) =>
  list(BsPrecis.PrecisUtils.codePoint);
let toLower:
  list(BsPrecis.PrecisUtils.codePoint) =>
  list(BsPrecis.PrecisUtils.codePoint);
```
