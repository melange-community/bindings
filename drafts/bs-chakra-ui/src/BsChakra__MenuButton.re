[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~variantColor: string=?,
    ~size: 'size=?,
    ~variant: [@bs.string] [ | `solid | `ghost | `outline | `link]=?,
    ~_type: [@bs.string] [ | `submit | `button]=?,
    ~leftIcon: string=?,
    ~rightIcon: string=?,
    ~isLoading: bool=?,
    ~isDisabled: bool=?,
    ~loadingText: string=?,
    ~ariaLabel: string=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~width: 'w=?,
    ~height: 'h=?
  ) =>
  React.element =
  "MenuButton";