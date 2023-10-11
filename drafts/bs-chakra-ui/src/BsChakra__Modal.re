open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~size: 'size=?,
    ~isOpen: bool,
    ~isCentered: bool=?,
    ~initialFocusRef: ReactDOMRe.Ref.t=?,
    ~onClose: unit => unit,
    ~children: React.element,
    ~blockScrollOnMount: bool=?,
    ~useInert: bool=?
  ) =>
  React.element =
  "Modal";

let makeProps = (~size: option(responsiveValue(modalSize))=?) =>
  makeProps(~size=?size->extractProps(modalSizeToJs));