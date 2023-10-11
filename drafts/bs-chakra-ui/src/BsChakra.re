type theme;

[@bs.module "@chakra-ui/core"] external theme: theme = "theme";

module ThemeProvider = {
  [@bs.module "@chakra-ui/core"] [@react.component]
  external make: (~theme: theme, ~children: React.element) => React.element = "ThemeProvider";
};

module CSSReset = {
  [@bs.module "@chakra-ui/core"] [@react.component] external make: unit => React.element = "CSSReset";
};

module Hooks = {
  [@bs.module "@chakra-ui/core"]
  external useDisclosure:
    unit =>
    {
      .
      "isOpen": bool,
      [@bs.meth] "onClose": unit => unit,
      [@bs.meth] "onOpen": unit => unit,
      [@bs.meth] "onToggle": unit => unit,
    } =
    "useDisclosure";

  [@bs.module "@chakra-ui/core"]
  external useClipboard:
    unit =>
    {
      .
      "value": string,
      [@bs.meth] "onCopy": unit => unit,
      "hasCopied": bool,
    } =
    "useClipboard";

  [@bs.module "@chakra-ui/core"] external useTheme: unit => theme = "useTheme";

  module Toast = {
    [@bs.deriving abstract]
    type config = {
      [@bs.optional]
      title: string,
      [@bs.optional]
      description: string,
      [@bs.optional]
      status: string,
      [@bs.optional]
      duration: int,
      [@bs.optional]
      isClosable: bool,
      [@bs.optional]
      position: string,
      [@bs.optional]
      render: unit => React.element,
      [@bs.optional]
      onClose: unit => unit,
    };

    [@bs.deriving jsConverter]
    type position = [
      | `top
      | [@bs.as "top-left"] `topLeft
      | [@bs.as "top-right"] `topRight
      | [@bs.as "bottom"] `bottom
      | [@bs.as "bottom-left"] `bottomLeft
      | [@bs.as "bottom-right"] `bottomRight
    ];

    [@bs.deriving jsConverter]
    type status = [ | `danger | `warning | `success | `info];
  };

  [@bs.module "@chakra-ui/core"] external _useToast: (Toast.config, unit) => unit = "useToast";

  let useToast =
      (
        ~title=?,
        ~isClosable=?,
        ~description=?,
        ~duration=?,
        ~render=?,
        ~onClose=?,
        ~status: option(Toast.status)=?,
        ~position: option(Toast.position)=?,
        (),
      ) =>
    _useToast(
      Toast.config(
        ~title?,
        ~description?,
        ~isClosable?,
        ~duration?,
        ~render?,
        ~onClose?,
        ~status=?status->Belt.Option.map(v => v->Toast.statusToJs),
        ~position=?position->Belt.Option.map(v => v->Toast.positionToJs),
        (),
      ),
    );
};

module Accordion = BsChakra__Accordion;
module AccordionHeader = BsChakra__AccordionHeader;
module AccordionItem = BsChakra__AccordionItem;
module AccordionPanel = BsChakra__AccordionPanel;
module AccordionIcon = BsChakra__AccordionIcon;
module Button = BsChakra__Button;
module ButtonGroup = BsChakra__ButtonGroup;
module Switch = BsChakra__Switch;
module Stack = BsChakra__Stack;
module FormLabel = BsChakra__FormLabel;
module Box = BsChakra__Box;
module CircularProgress = BsChakra__CircularProgress;
module CircularProgressLabel = BsChakra__CircularProgressLabel;
module Heading = BsChakra__Heading;
module Spinner = BsChakra__Spinner;
module Flex = BsChakra__Flex;
module Input = BsChakra__Input;
module InputGroup = BsChakra__InputGroup;
module InputLeftElement = BsChakra__InputLeftElement;
module InputRightElement = BsChakra__InputRightElement;
module Text = BsChakra__Text;
module FormControl = BsChakra__FormControl;
module FormHelperText = BsChakra__FormHelperText;
module FormErrorMessage = BsChakra__FormErrorMessage;
module Alert = BsChakra__Alert;
module AlertTitle = BsChakra__AlertTitle;
module AlertDescription = BsChakra__AlertDescription;
module AlertIcon = BsChakra__AlertIcon;
module Link = BsChakra__Link;
module Avatar = BsChakra__Avatar;
module AvatarBadge = BsChakra__AvatarBadge;
module AvatarGroup = BsChakra__AvatarGroup;
module NumberInput = BsChakra__NumberInput;
module Image = BsChakra__Image;
module Types = BsChakra__Types;
module Modal = BsChakra__Modal;
module ModalHeader = BsChakra__ModalHeader;
module ModalFooter = BsChakra__ModalFooter;
module ModalBody = BsChakra__ModalBody;
module ModalContent = BsChakra__ModalContent;
module ModalCloseButton = BsChakra__ModalCloseButton;
module ModalOverlay = BsChakra__ModalOverlay;
module Icon = BsChakra__Icon;
module IconButton = BsChakra__IconButton;
module Menu = BsChakra__Menu;
module MenuList = BsChakra__MenuList;
module MenuItem = BsChakra__MenuItem;
module MenuItemOption = BsChakra__MenuItemOption;
module MenuGroup = BsChakra__MenuGroup;
module MenuOptionGroup = BsChakra__MenuOptionGroup;
module MenuButton = BsChakra__MenuButton;
module Textarea = BsChakra__Textarea;
module Select = BsChakra__Select;
module CloseButton = BsChakra__CloseButton;
module AspectRatioBox = BsChakra__AspectRatioBox;
module PopoverArrow = BsChakra__PopoverArrow;
module PopoverBody = BsChakra__PopoverBody;
module PopoverHeader = BsChakra__PopoverHeader;
module PopoverCloseButton = BsChakra__PopoverCloseButton;
module PopoverContent = BsChakra__PopoverContent;
module PopoverTrigger = BsChakra__PopoverTrigger;
module Popover = BsChakra__Popover;