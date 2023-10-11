open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make: (~height: 'h=?, ~width: 'w=?) => React.element = "AlertIcon";

let makeProps =
    (
      ~width: option(responsiveValue(string))=?,
      ~height: option(responsiveValue(string))=?,
    ) =>
  makeProps(
    ~width=?width->extractProps(v => v),
    ~height=?height->extractProps(v => v),
  );