open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~id: string,
    ~value: bool=?,
    ~isChecked: bool=?,
    ~isDisabled: bool=?,
    ~isInvalid: bool=?,
    ~defaultIsChecked: bool=?,
    ~onChange: unit => unit=?,
    ~size: 'size=?,
    ~color: string=?
  ) =>
  React.element =
  "Switch";

let makeProps =
    (~size: option(responsiveValue(buttonSize))=?, ~color: option(color)=?) =>
  makeProps(
    ~size=?size->extractProps(v => buttonSizeToJs(v)),
    ~color=?color->Belt.Option.map(v => colorToJs(v)),
  );