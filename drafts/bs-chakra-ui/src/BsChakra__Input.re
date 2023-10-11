open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~placeholder: string=?,
    ~name: string=?,
    ~id: string=?,
    ~ref: React.Ref.t('ref)=?,
    ~roundedLeft: string=?,
    ~onChange: 'a => unit=?,
    ~onBlur: 'a => unit=?,
    ~onFocus: 'a => unit=?,
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
    ~_type: [@bs.string] [ | `text | `phone | `password | `number | `date | `checkbox | `radio | `email | `url]
  ) =>
  React.element =
  "Input";

let makeProps =
    (
      ~focusBorderColor: option(color)=?,
      ~margin: option(responsiveValue(spaceProps))=?,
      ~marginTop: option(responsiveValue(spaceProps))=?,
      ~marginBottom: option(responsiveValue(spaceProps))=?,
      ~marginLeft: option(responsiveValue(spaceProps))=?,
      ~marginRight: option(responsiveValue(spaceProps))=?,
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
    ~margin=?margin->extractSpaceProps,
    ~marginTop=?marginTop->extractSpaceProps,
    ~marginBottom=?marginBottom->extractSpaceProps,
    ~marginLeft=?marginLeft->extractSpaceProps,
    ~marginRight=?marginRight->extractSpaceProps,
    ~padding=?padding->extractProps(v => v),
    ~paddingTop=?paddingTop->extractProps(v => v),
    ~paddingBottom=?paddingBottom->extractProps(v => v),
    ~paddingLeft=?paddingLeft->extractProps(v => v),
    ~paddingRight=?paddingRight->extractProps(v => v),
    ~px=?px->extractProps(v => v),
    ~py=?py->extractProps(v => v),
  );