open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~max: 'max=?,
    ~size: 'size=?,
    ~spacing: 'spacing=?,
    ~children: React.element
  ) =>
  React.element =
  "AvatarGroup";

let makeProps =
    (
      ~size: option(responsiveValue(avatarSize))=?,
      ~max: option(responsiveValue(int))=?,
      ~spacing: option(responsiveValue(int))=?,
    ) =>
  makeProps(
    ~size=?size->extractProps(avatarSizeToJs),
    ~max=?max->extractProps(v => v),
    ~spacing=?spacing->extractProps(v => v),
  );