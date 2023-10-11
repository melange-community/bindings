open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~status: [@bs.string] [ | `error | `success | `warning | `info]=?,
    ~variant: [@bs.string] [
                | `subtle
                | [@bs.as "left-accent"] `leftAccent
                | [@bs.as "top-accent"] `topAccent
              ]
                =?,
    ~direction: [@bs.string] [ | `row | `column]=?,
    ~justifyContent: [@bs.string] [
                       | [@bs.as "flex-start"] `flexStart
                       | `center
                       | [@bs.as "flex-end"] `flexEnd
                       | [@bs.as "space-around"] `spaceAround
                       | [@bs.as "space-between"] `spaceBetween
                     ]
                       =?,
    ~alignItems: [@bs.string] [
                   | [@bs.as "flex-start"] `flexStart
                   | `center
                   | [@bs.as "flex-end"] `flexEnd
                   | [@bs.as "space-around"] `spaceAround
                   | [@bs.as "space-between"] `spaceBetween
                 ]
                   =?,
    ~textAlign: 'text=?,
    ~height: 'h=?,
    ~width: 'w=?
  ) =>
  React.element =
  "Alert";

let makeProps =
    (
      ~textAlign: option(responsiveValue(string))=?,
      ~width: option(responsiveValue(string))=?,
      ~height: option(responsiveValue(string))=?,
    ) =>
  makeProps(
    ~textAlign=?textAlign->extractProps(v => v),
    ~width=?width->extractProps(v => v),
    ~height=?height->extractProps(v => v),
  );