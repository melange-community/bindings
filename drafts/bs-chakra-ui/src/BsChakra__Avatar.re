open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~name: string=?,
    ~showBorder: bool=?,
    ~src: string=?,
    ~size: 'size=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Avatar";

let makeProps = (~size: option(responsiveValue(avatarSize))=?) =>
  makeProps(~size=?size->extractProps(avatarSizeToJs));