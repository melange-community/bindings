open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (~bg: 'bg=?, ~size: 'size=?, ~children: React.element=?) => React.element =
  "AvatarBadge";

let makeProps =
    (
      ~size: option(responsiveValue(string))=?,
      ~bg: option(responsiveValue(color))=?,
    ) =>
  makeProps(
    ~size=?size->extractProps(v => v),
    ~bg=?bg->extractProps(colorToJs),
  );