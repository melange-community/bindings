open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~size: [@bs.string] [ | `sm | `md | `lg]=?,
    ~isDisabled: bool=?,
    ~color: 'color=?
  ) =>
  React.element =
  "CloseButton";

let makeProps = (~color: option(responsiveValue(color))=?) =>
  makeProps(~color=?color->extractProps(colorToJs));