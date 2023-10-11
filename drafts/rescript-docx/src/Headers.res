/** @see https://docx.js.org/api/interfaces/IHeaderOptions.html */
type headerOptions = {children: array<FileChild.t>}

type headerFooterGroup<'a> = {
  default?: 'a,
  first?: 'a,
  even?: 'a,
}

/** @see https://docx.js.org/api/classes/Header.html */
module Header = {
  type t

  @module("docx") @new
  external make: headerOptions => t = "Header"
}

module HeaderWrapper = {
  type t

  @module("docx") @new
  external make: headerOptions => t = "HeaderWrapper"
}

module FooterWrapper = {
  type t

  @module("docx") @new
  external make: headerOptions => t = "FooterWrapper"
}

/** @see https://docx.js.org/api/classes/Footer.html */
module Footer = {
  type t

  @module("docx") @new
  external make: headerOptions => t = "Footer"
}
