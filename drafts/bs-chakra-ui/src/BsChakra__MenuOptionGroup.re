open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element=?,
    ~title: string,
    ~_type: [@bs.string] [ | `radio | `checkbox]=?,
    ~defaultValue: 'defaultValue=?,
    ~onChange: 'a => unit=?
  ) =>
  React.element =
  "MenuOptionGroup";

type defaultValue =
  | Single(string)
  | Array(array(string));

let makeProps = (~defaultValue: option(defaultValue)=?) =>
  makeProps(
    ~defaultValue=?
      defaultValue
      ->Belt.Option.map(v =>
          switch (v) {
          | Single(v) => returnHack(v)
          | Array(v) => returnHack(v)
          }
        ),
  );