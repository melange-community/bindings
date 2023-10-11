open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~spacing: 's
  ) =>
  React.element =
  "ButtonGroup";

let makeProps =
    (
      ~spacing: option(responsiveValue(spaceProps))=?,
    ) =>
  makeProps(
    ~spacing=?spacing->extractSpaceProps,
  );