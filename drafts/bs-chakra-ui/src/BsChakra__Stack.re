open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~isInline: bool=?,
    ~align: 'align=?,
    ~justify: 'justify=?,
    ~spacing: int=?,
    ~children: React.element,
    ~margin: 'margin=?,
    ~marginTop: 'marginTop=?,
    ~marginBottom: 'marginBottom=?,
    ~marginLeft: 'marginLeft=?,
    ~marginRight: 'marginRight=?,
    ~maxWidth: 'maxW=?,
    ~maxHeight: 'maxH=?,
    ~minWidth: 'minW=?,
    ~minHeight: 'minH=?,
    ~width: 'wid=?,
    ~height: 'hei=?,
    ~wrap: 'wrap=?,
    ~position: [@bs.string] [ | `relative | `static | `absolute]=?
  ) =>
  React.element =
  "Stack";

let makeProps =
    (
      ~align: option(responsiveValue(flexAlignment))=?,
      ~justify: option(responsiveValue(flexAlignment))=?,
      ~margin: option(responsiveValue(spaceProps))=?,
      ~marginTop: option(responsiveValue(spaceProps))=?,
      ~marginBottom: option(responsiveValue(spaceProps))=?,
      ~marginLeft: option(responsiveValue(spaceProps))=?,
      ~marginRight: option(responsiveValue(spaceProps))=?,
      ~maxWidth: option(responsiveValue(string))=?,
      ~maxHeight: option(responsiveValue(string))=?,
      ~minWidth: option(responsiveValue(string))=?,
      ~minHeight: option(responsiveValue(string))=?,
      ~width: option(responsiveValue(string))=?,
      ~height: option(responsiveValue(string))=?,
      ~wrap: option(responsiveValue(flexWrap))=?,
    ) =>
  makeProps(
    ~align=?align->extractProps(flexAlignmentToJs),
    ~justify=?justify->extractProps(flexAlignmentToJs),
    ~margin=?margin->extractSpaceProps,
    ~marginTop=?marginTop->extractSpaceProps,
    ~marginBottom=?marginBottom->extractSpaceProps,
    ~marginLeft=?marginLeft->extractSpaceProps,
    ~marginRight=?marginRight->extractSpaceProps,
    ~maxHeight=?maxHeight->extractProps(v => v),
    ~maxWidth=?maxWidth->extractProps(v => v),
    ~minHeight=?minHeight->extractProps(v => v),
    ~minWidth=?minWidth->extractProps(v => v),
    ~height=?height->extractProps(v => v),
    ~width=?width->extractProps(v => v),
    ~wrap=?wrap->extractProps(flexWrapToJs),
  );