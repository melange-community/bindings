/** @see https://docx.js.org/api/classes/Bookmark.html */
type options = {
  id: string,
  children: array<ParagraphChild.t>,
}

@module("docx") @new
external make: options => ParagraphChild.t = "Bookmark"
