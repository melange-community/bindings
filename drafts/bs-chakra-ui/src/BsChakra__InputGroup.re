[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (~size: [@bs.string] [ | `sm | `md | `lg]=?, ~children: React.element) =>
  React.element =
  "InputGroup";