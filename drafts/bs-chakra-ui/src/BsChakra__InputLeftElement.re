open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~width: string=?,
    ~color: 'color=?,
    ~fontSize: string=?
  ) =>
  React.element =
  "InputLeftElement";

let makeProps = (~color: option(color)=?) =>
  makeProps(~color=?color->mapToColor);