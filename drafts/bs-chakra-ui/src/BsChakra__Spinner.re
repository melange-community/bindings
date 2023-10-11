open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~color: 'a=?,
    ~emptyColor: 'a=?,
    ~thickness: string=?,
    ~speed: string=?,
    ~label: string=?,
    ~size: [@bs.string] [ | `xs | `sm | `md | `lg | `xl]=?
  ) =>
  React.element =
  "Spinner";

let makeProps = (~color: option(color)=?, ~emptyColor: option(color)=?) =>
  makeProps(~color=?color->mapToColor, ~emptyColor=?emptyColor->mapToColor);