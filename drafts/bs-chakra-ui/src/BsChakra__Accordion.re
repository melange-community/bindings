[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~defaultIndex: array(int)=?,
    ~allowMultiple: bool=?,
    ~allowToggle: bool=?,
    ~onChange: array(int) => unit=?
  ) =>
  React.element =
  "Accordion";