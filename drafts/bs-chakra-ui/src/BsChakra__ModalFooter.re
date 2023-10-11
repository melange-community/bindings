open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~direction: 'direction=?,
    ~align: 'align=?,
    ~justify: 'justify=?
  ) =>
  React.element =
  "ModalFooter";

let makeProps =
    (
      ~align: option(responsiveValue(flexAlignment))=?,
      ~justify: option(responsiveValue(flexAlignment))=?,
      ~direction: option(responsiveValue(flexDirection))=?,
    ) =>
  makeProps(
    ~align=?align->extractProps(flexAlignmentToJs),
    ~justify=?justify->extractProps(flexAlignmentToJs),
    ~direction=?direction->extractProps(flexDirectionToJs),
  );