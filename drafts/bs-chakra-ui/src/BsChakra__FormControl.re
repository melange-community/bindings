[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~isRequired: bool=?,
    ~isInvalid: bool=?,
    ~isDisabled: bool=?,
    ~isReadOnly: bool=?
  ) =>
  React.element =
  "FormControl";