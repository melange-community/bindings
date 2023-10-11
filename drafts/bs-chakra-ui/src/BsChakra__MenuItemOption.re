open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element=?,
    ~isDisabled: bool=?,
    ~_type: [@bs.string] [ | `radio | `checkbox]=?,
    ~value: 'value=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?
  ) =>
  React.element =
  "MenuItemOption";

type value =
  | Int(int)
  | String(string);

let makeProps = (~value: option(value)=?) =>
  makeProps(
    ~value=?
      value
      ->Belt.Option.map(v =>
          switch (v) {
          | Int(v) => returnHack(v)
          | String(v) => returnHack(v)
          }
        ),
  );