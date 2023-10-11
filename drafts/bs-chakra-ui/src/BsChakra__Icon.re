open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~size: 'size=?,
    ~name: 'icon=?,
    ~color: 'color=?,
    ~focusable: bool=?,
    ~role: [@bs.string] [ | `presentation | `img]=?
  ) =>
  React.element =
  "Icon";

let makeProps =
    (
      ~size: option(responsiveValue(string))=?,
      ~color: option(responsiveValue(color))=?,
      ~name: option(iconProps)=?,
    ) =>
  makeProps(
    ~size=?size->extractProps(v => v),
    ~color=?color->extractProps(colorToJs),
    ~name=?
      name
      ->Belt.Option.map(v =>
          switch (v) {
          | Theme(v) => returnHack(v->iconToJs)
          | CustomTheme(v) => returnHack(v)
          }
        ),
  );