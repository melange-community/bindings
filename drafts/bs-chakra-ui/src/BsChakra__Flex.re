open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~boxShadow: 'boxShadow=?,
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
    ~direction: 'direction=?,
    ~width: 'wid=?,
    ~height: 'hei=?,
    ~maxWidth: 'maxW=?,
    ~maxHeight: 'maxH=?,
    ~flex: 'maxH=?,
    ~wrap: 'wrap=?,
    ~align: 'align=?,
    ~justify: 'justify=?,
    ~overflow: 'overflow=?,
    ~overflowX: 'overflowX=?,
    ~overflowY: 'overflowY=?,
    ~rounded: 'rounded=?,
    ~border: 'border=?
  ) =>
  React.element =
  "Flex";

let makeProps =
    (
      ~bg: option(color)=?,
      ~color: option(color)=?,
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
      ~width: option(responsiveValue(string))=?,
      ~height: option(responsiveValue(string))=?,
      ~flex: option(responsiveValue(string))=?,
      ~align: option(responsiveValue(flexAlignment))=?,
      ~justify: option(responsiveValue(flexAlignment))=?,
      ~direction: option(responsiveValue(flexDirection))=?,
      ~wrap: option(responsiveValue(flexWrap))=?,
      ~boxShadow: option(responsiveValue(shadowProps))=?,
      ~overflow: option(responsiveValue(overflow))=?,
      ~overflowX: option(responsiveValue(overflow))=?,
      ~overflowY: option(responsiveValue(overflow))=?,
      ~rounded: option(responsiveValue(radiiProps))=?,
      ~border: option(responsiveValue(borderProps))=?,
    ) =>
  makeProps(
    ~bg=?bg->mapToColor,
    ~color=?color->mapToColor,
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
    ~height=?height->extractProps(v => v),
    ~width=?width->extractProps(v => v),
    ~flex=?flex->extractProps(v => v),
    ~align=?align->extractProps(flexAlignmentToJs),
    ~justify=?justify->extractProps(flexAlignmentToJs),
    ~direction=?direction->extractProps(flexDirectionToJs),
    ~wrap=?wrap->extractProps(flexWrapToJs),
    ~overflow=?overflow->extractProps(overflowToJs),
    ~overflowX=?overflowX->extractProps(overflowToJs),
    ~overflowY=?overflowY->extractProps(overflowToJs),
    ~boxShadow=?
      boxShadow->Belt.Option.map(p =>
        switch (p) {
        | All(v) =>
          returnHack(
            switch (v) {
            | Theme(value) => shadowToJs(value)
            | Custom(value) => value
            },
          )
        | Responsive(v) =>
          returnHack(
            v->Belt.Array.map(value =>
              switch (value) {
              | Theme(value) => shadowToJs(value)
              | Custom(value) => value
              }
            ),
          )
        }
      ),
    ~rounded=?rounded->extractProps(radiiPropsToJs),
    ~border=?border->extractBorderProps,
  );