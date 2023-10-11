open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (~children: React.element, ~ratio: int=?, ~maxWidth: 'maxW=?) =>
  React.element =
  "AspectRatioBox";

let makeProps = (~maxWidth: option(responsiveValue(string))=?) =>
  makeProps(~maxWidth=?maxWidth->extractProps(v => v));