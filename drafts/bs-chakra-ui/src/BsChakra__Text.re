open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~textAlign: 'textalign=?,
    ~_as: [@bs.string] [ | `p | `span]=?,
    ~fontWeight: [@bs.string] [ | `normal | `bold | `medium]=?,
    ~font: 'f=?,
    ~letterSpacing: 'letter=?,
    ~lineHeight: 'b=?,
    ~fontSize: 'a=?,
    ~color: 'color=?,
    ~isTruncated: bool=?,
  ) =>
  React.element =
  "Text";

let makeProps =
    (
      ~fontSize: option(responsiveValue(fontSize))=?,
      ~lineHeight: option(responsiveValue(lineHeight))=?,
      ~font: option(responsiveValue(font))=?,
      ~letterSpacing: option(responsiveValue(letterSpacing))=?,
      ~textAlign: option(responsiveValue(textAlign))=?,
      ~color: option(color)=?,
    ) =>
  makeProps(
    ~fontSize=?fontSize->extractProps(fontSizeToJs),
    ~lineHeight=?lineHeight->extractProps(lineHeightToJs),
    ~font=?font->extractProps(fontToJs),
    ~letterSpacing=?letterSpacing->extractProps(letterSpacingToJs),
    ~textAlign=?textAlign->extractProps(textAlignToJs),
    ~color=?color->mapToColor,
  );