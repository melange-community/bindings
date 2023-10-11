/** @see https://docx.js.org/api/classes/PageReference.html */
type options = {
  /** Creates a hyperlink to the bookmarked paragraph. */
  hyperlink?: bool,
  /**
   * Causes the field to display its position relative to the source
   *  bookmark. If the PAGEREF field is on the same page as the
   *  bookmark, it omits "on page #" and returns "above" or "below"
   *  only. If the PAGEREF field is not on the same page as the
   *  bookmark, the string "on page #" is used.
   */
  useRelativePosition?: bool,
}

@module("docx") @new
external make: string => ParagraphChild.t = "PageReference"

@module("docx") @new
external make': (string, options) => ParagraphChild.t = "PageReference"
