/** @see https://docx.js.org/api/enums/VerticalMergeType.html */
type t = [
  | /** Cell that is merged with upper one. */ #continue
  | /** Cell that is starting the vertical merge. */ #restart
]
