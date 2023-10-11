[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~isOpen: bool=?,
    ~autoSelect: bool=?,
    ~closeOnSelect: bool=?,
    ~closeOnBlur: bool=?,
    ~children: React.element
  ) =>
  React.element =
  "Menu";