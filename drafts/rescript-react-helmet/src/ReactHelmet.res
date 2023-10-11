@deriving(abstract)
type htmlAttributes = {lang: string}
type bodyAttributes
type titleAttributes
@deriving(abstract)
type meta = {
  @optional
  name: string,
  @optional
  property: string,
  @optional
  content: string,
}
type base
type link
type style
type script
type noscript

@module("react-helmet") @react.component
external make: (
  ~defer: bool=?,
  ~encodeSpecialCharacters: bool=?,
  ~onChangeClientState: unit => unit=?,
  ~htmlAttributes: htmlAttributes=?,
  ~bodyAttributes: bodyAttributes=?,
  ~titleAttributes: titleAttributes=?,
  ~defaultTitle: string=?,
  ~titleTemplate: string=?,
  ~base: // some <head> tags can be passed as props
  base=?,
  ~title: string=?,
  ~meta: array<meta>=?,
  ~link: array<link>=?,
  ~style: array<style>=?,
  ~script: array<script>=?,
  ~noscript: array<noscript>=?,
  ~children: React.element=?,
) => React.element = "Helmet"

type helmetProp
@send external toComponent: helmetProp => React.element = "toComponent"
@send external toString: helmetProp => string = "toString"
type helmet = {
  base: helmetProp,
  bodyAttributes: helmetProp,
  htmlAttributes: helmetProp,
  link: helmetProp,
  meta: helmetProp,
  noscript: helmetProp,
  script: helmetProp,
  style: helmetProp,
  title: helmetProp,
}
@val @module("react-helmet") @scope("Helmet")
external renderStatic: unit => helmet = "renderStatic"
