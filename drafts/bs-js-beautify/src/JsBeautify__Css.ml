type cssOptions =
  { end_with_newline: bool [@bs.optional]
  ; eol: string [@bs.optional]
  ; indent_char: string [@bs.optional]
  ; indent_empty_lines: bool [@bs.optional]
  ; indent_size: int [@bs.optional]
  ; indent_with_tabs: bool [@bs.optional]
  ; newline_between_rules: bool [@bs.optional]
  ; selector_separator_newline: bool [@bs.optional]
  } [@@bs.deriving abstract];;

external css : string -> cssOptions -> string = "css" [@@bs.module "js-beautify"];;

let css
  ?end_with_newline
  ?eol
  ?indent_char
  ?indent_empty_lines
  ?indent_size
  ?indent_with_tabs
  ?newline_between_rules
  ?selector_separator_newline
  code =
    css
    code
    (cssOptions
      ?end_with_newline
      ?eol
      ?indent_char
      ?indent_empty_lines
      ?indent_size
      ?indent_with_tabs
      ?newline_between_rules
      ?selector_separator_newline
      ());;
