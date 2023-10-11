open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~src: string,
    ~fallbackSrc: string=?,
    ~alt: string=?,
    ~size: 'size=?,
    ~onLoad: unit => unit=?,
    ~onError: unit => unit=?,
    ~rounded: string=?,
    ~objectFit: string=?
  ) =>
  React.element =
  "Image";

let makeProps = (~size: option(responsiveValue(string))=?) =>
  makeProps(~size=?size->extractProps(v => v));