[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~usePortal: bool=?,
    ~isOpen: bool=?,
    ~defaultIsOpen: bool=?,
    ~returnFocusOnClose: bool=?,
    ~closeOnBlur: bool=?,
    ~closeOnEsc: bool=?,
    ~gutter: int=?,
    ~onOpen: unit => unit=?,
    ~onClose: unit => unit=?,
    ~trigger: [@bs.string] [ | `click | `hover]=?,
    ~placement: [@bs.string] [ | `bottom | `top | `left | `right]=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Popover";