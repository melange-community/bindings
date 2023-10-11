open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~variantColor: string=?,
    ~size: 'size=?,
    ~variant: [@bs.string] [ | `solid | `ghost | `outline | `link]=?,
    ~_type: [@bs.string] [ | `submit | `button]=?,
    ~isLoading: bool=?,
    ~isDisabled: bool=?,
    ~ariaLabel: string=?,
    ~isRound: bool=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~width: 'w=?,
    ~height: 'h=?,
    ~icon: 'h=?
  ) =>
  React.element =
  "IconButton";

let makeProps =
    (
      ~size: option(responsiveValue(buttonSize))=?,
      ~variantColor: option(variantColor)=?,
      ~width: option(responsiveValue(string))=?,
      ~height: option(responsiveValue(string))=?,
      ~icon: option(iconButtonProps)=?,
    ) =>
  makeProps(
    ~size=?size->extractProps(buttonSizeToJs),
    ~variantColor=?variantColor->mapToVariantColor,
    ~width=?width->extractProps(v => v),
    ~height=?height->extractProps(v => v),
    ~icon=?
      icon
      ->Belt.Option.map(v =>
          switch (v) {
          | Theme(v) => returnHack(v->iconToJs)
          | CustomTheme(v) => returnHack(v)
          | Element(v) => returnHack(v)
          }
        ),
  );