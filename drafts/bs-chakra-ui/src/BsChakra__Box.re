open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~bg: 'bg=?,
    ~color: 'color=?,
    ~margin: 'margin=?,
    ~marginTop: 'marginTop=?,
    ~marginBottom: 'marginBottom=?,
    ~marginLeft: 'marginLeft=?,
    ~marginRight: 'marginRight=?,
    ~padding: 'padding=?,
    ~paddingTop: 'pTop=?,
    ~paddingBottom: 'pBot=?,
    ~paddingLeft: 'pLef=?,
    ~paddingRight: 'pRig=?,
    ~px: 'px=?,
    ~py: 'py=?,
    ~opacity: float=?,
    ~boxShadow: 'box=?,
    ~width: 'wid=?,
    ~height: 'hei=?,
    ~maxWidth: 'maxW=?,
    ~maxHeight: 'maxH=?,
    ~minWidth: 'minW=?,
    ~minHeight: 'minH=?,
    ~overflow: 'overflow=?,
    ~overflowX: 'overflowX=?,
    ~overflowY: 'overflowY=?,
    ~position: [@bs.string] [ | `relative | `static | `absolute]=?,
    ~_as: string=?,
    ~rounded: 'rounded=?,
    ~border: 'border=?,
    ~top: 'top=?,
    ~left: 'left=?,
    ~right: 'right=?,
    ~bottom: 'bottom=?
  ) =>
  React.element =
  "Box";

let makeProps =
    (
      ~bg: option(color)=?,
      ~color: option(color)=?,
      ~overflow: option(responsiveValue(overflow))=?,
      ~overflowX: option(responsiveValue(overflow))=?,
      ~overflowY: option(responsiveValue(overflow))=?,
      ~margin: option(responsiveValue(spaceProps))=?,
      ~marginTop: option(responsiveValue(spaceProps))=?,
      ~marginBottom: option(responsiveValue(spaceProps))=?,
      ~marginLeft: option(responsiveValue(spaceProps))=?,
      ~marginRight: option(responsiveValue(spaceProps))=?,
      ~padding: option(responsiveValue(spaceProps))=?,
      ~paddingTop: option(responsiveValue(spaceProps))=?,
      ~paddingBottom: option(responsiveValue(spaceProps))=?,
      ~paddingLeft: option(responsiveValue(spaceProps))=?,
      ~paddingRight: option(responsiveValue(spaceProps))=?,
      ~px: option(responsiveValue(spaceProps))=?,
      ~py: option(responsiveValue(spaceProps))=?,
      ~maxWidth: option(responsiveValue(string))=?,
      ~maxHeight: option(responsiveValue(string))=?,
      ~minWidth: option(responsiveValue(string))=?,
      ~minHeight: option(responsiveValue(string))=?,
      ~width: option(responsiveValue(string))=?,
      ~height: option(responsiveValue(string))=?,
      ~boxShadow: option(responsiveValue(shadowProps))=?,
      ~rounded: option(responsiveValue(radiiProps))=?,
      ~border: option(responsiveValue(borderProps))=?,
      ~top: option(responsiveValue(string))=?,
      ~bottom: option(responsiveValue(string))=?,
      ~left: option(responsiveValue(string))=?,
      ~right: option(responsiveValue(string))=?,
    ) =>
  makeProps(
    ~bg=?bg->mapToColor,
    ~color=?color->mapToColor,
    ~boxShadow=?boxShadow->extractBoxShadowProps,
    ~margin=?margin->extractSpaceProps,
    ~marginTop=?marginTop->extractSpaceProps,
    ~marginBottom=?marginBottom->extractSpaceProps,
    ~marginLeft=?marginLeft->extractSpaceProps,
    ~marginRight=?marginRight->extractSpaceProps,
    ~padding=?padding->extractSpaceProps,
    ~paddingTop=?paddingTop->extractSpaceProps,
    ~paddingBottom=?paddingBottom->extractSpaceProps,
    ~paddingLeft=?paddingLeft->extractSpaceProps,
    ~paddingRight=?paddingRight->extractSpaceProps,
    ~px=?px->extractSpaceProps,
    ~py=?py->extractSpaceProps,
    ~maxHeight=?maxHeight->extractProps(v => v),
    ~maxWidth=?maxWidth->extractProps(v => v),
    ~minHeight=?minHeight->extractProps(v => v),
    ~minWidth=?minWidth->extractProps(v => v),
    ~height=?height->extractProps(v => v),
    ~width=?width->extractProps(v => v),
    ~overflow=?overflow->extractProps(overflowToJs),
    ~overflowX=?overflowX->extractProps(overflowToJs),
    ~overflowY=?overflowY->extractProps(overflowToJs),
    ~rounded=?rounded->extractProps(radiiPropsToJs),
    ~border=?border->extractBorderProps,
    ~top=?top->extractProps(v => v),
    ~left=?left->extractProps(v => v),
    ~right=?right->extractProps(v => v),
    ~bottom=?bottom->extractProps(v => v),
  );