[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~isDisabled: bool=?,
    ~role: [@bs.string] [ | `menuitemcheckbox | `menuitemradio | `menuitem]=?
  ) =>
  React.element =
  "MenuItem";