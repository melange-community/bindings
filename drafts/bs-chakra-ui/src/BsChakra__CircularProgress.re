open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~value: float=?,
    ~min: float=?,
    ~max: float=?,
    ~children: React.element=?,
    ~isIndeterminate: bool=?,
    ~capIsRound: bool=?,
    ~thickness: float=?,
    ~color: 'a=?,
    ~trackColor: 'b=?
  ) =>
  React.element =
  "CircularProgress";

let makeProps = (~color: option(color)=?, ~trackColor: option(color)=?) =>
  makeProps(
    ~color=?color->Belt.Option.map(c => colorToJs(c)),
    ~trackColor=?trackColor->Belt.Option.map(c => colorToJs(c)),
  );

module CircularProgressLabel = {
  [@bs.module "@chakra-ui/core"] [@react.component]
  external make: (~children: React.element) => React.element =
    "CircularProgressLabel";
};