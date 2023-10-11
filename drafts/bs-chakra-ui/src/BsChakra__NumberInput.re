open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~placeholder: string=?,
    ~id: string=?,
    ~roundedLeft: string=?,
    ~onChange: float => unit=?,
    ~onBlur: 'a => unit=?,
    ~value: string=?,
    ~rounded: string=?,
    ~isRequired: bool=?,
    ~isFullWidth: bool=?,
    ~isReadOnly: bool=?,
    ~isInvalid: bool=?,
    ~isDisabled: bool=?,
    ~variant: [@bs.string] [ | `outline | `unstyled | `flushed | `filled]=?,
    ~focusBorderColor: 'focusBorderColor=?,
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
    ~size: [@bs.string] [ | `sm | `md | `lg]=?,
    ~min: float=?,
    ~max: float=?,
    ~step: float=?
  ) =>
  React.element =
  "NumberInput";

let makeProps =
    (
      ~focusBorderColor: option(color)=?,
      ~margin: option(responsiveValue(int))=?,
      ~marginTop: option(responsiveValue(int))=?,
      ~marginBottom: option(responsiveValue(int))=?,
      ~marginLeft: option(responsiveValue(int))=?,
      ~marginRight: option(responsiveValue(int))=?,
      ~padding: option(responsiveValue(int))=?,
      ~paddingTop: option(responsiveValue(int))=?,
      ~paddingBottom: option(responsiveValue(int))=?,
      ~paddingLeft: option(responsiveValue(int))=?,
      ~paddingRight: option(responsiveValue(int))=?,
      ~px: option(responsiveValue(int))=?,
      ~py: option(responsiveValue(int))=?,
    ) =>
  makeProps(
    ~focusBorderColor=?focusBorderColor->mapToColor,
    ~margin=?margin->extractProps(v => v),
    ~marginTop=?marginTop->extractProps(v => v),
    ~marginBottom=?marginBottom->extractProps(v => v),
    ~marginLeft=?marginLeft->extractProps(v => v),
    ~marginRight=?marginRight->extractProps(v => v),
    ~padding=?padding->extractProps(v => v),
    ~paddingTop=?paddingTop->extractProps(v => v),
    ~paddingBottom=?paddingBottom->extractProps(v => v),
    ~paddingLeft=?paddingLeft->extractProps(v => v),
    ~paddingRight=?paddingRight->extractProps(v => v),
    ~px=?px->extractProps(v => v),
    ~py=?py->extractProps(v => v),
  );