/** @see https://docx.js.org/api/enums/AlignmentType.html */
type t = [
  | /** Align Start */ #start
  | /** Align Center */ #center
  | /** End */ #end
  | /** Justified */ #both
  | /** Medium Kashida Length */ #mediumKashida
  | /** Distribute All Characters Equally */ #distribute
  | /** Align to List Tab */ #numTab
  | /** Widest Kashida Length */ #highKashida
  | /** Low Kashida Length */ #lowKashida
  | /** Thai Language Justification */ #thaiDistribute
  | /** Align Left */ #left
  | /** Align Right */ #right
  | /** Justified */ #both
]
