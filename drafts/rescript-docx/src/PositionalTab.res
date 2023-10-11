/** @see https://docx.js.org/api/classes/PositionalTab.html */
type option = {
  alignment: [#left | #center | #right],
  relativeTo: [#margin | #indent],
  leader: LeaderType.t,
}

@module("docx") @new
external make: option => TextRun.children = "PositionalTab"
