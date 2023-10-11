[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onBlur: ReactEvent.Mouse.t => unit=?,
    ~placement: string=?
  ) =>
  React.element =
  "MenuList";