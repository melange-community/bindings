open JsBeautify__Utils;;

type jsOptions =
  { brace_style: string [@bs.optional]
  ; break_chained_methods: bool [@bs.optional]
  ; comma_first: bool [@bs.optional]
  ; e4x: bool [@bs.optional]
  ; editorconfig: bool [@bs.optional]
  ; end_with_newline: bool [@bs.optional]
  ; eol: string [@bs.optional]
  ; indent_char: string [@bs.optional]
  ; indent_empty_lines: bool [@bs.optional]
  ; indent_level: int [@bs.optional]
  ; indent_size: int [@bs.optional]
  ; indent_with_tabs: bool [@bs.optional]
  ; jslint_happy: bool [@bs.optional]
  ; keep_array_indentation: bool [@bs.optional]
  ; max_preserve_newlines: int [@bs.optional]
  ; operator_position: string [@bs.optional]
  ; preserve_newlines: bool [@bs.optional]
  ; space_after_anon_function: bool [@bs.optional]
  ; space_after_named_function: bool [@bs.optional]
  ; space_in_empty_paren: bool [@bs.optional]
  ; space_in_paren: bool [@bs.optional]
  ; templating: string array [@bs.optional]
  ; unescape_strings: bool [@bs.optional]
  ; unindent_chained_methods: bool [@bs.optional]
  ; wrap_line_length: int [@bs.optional]
  } [@@bs.deriving abstract];;

external js : string -> jsOptions -> string = "js" [@@bs.module "js-beautify"];;

let js
  ?brace_style
  ?break_chained_methods
  ?comma_first
  ?e4x
  ?editorconfig
  ?end_with_newline
  ?eol
  ?indent_char
  ?indent_empty_lines
  ?indent_level
  ?indent_size
  ?indent_with_tabs
  ?jslint_happy
  ?keep_array_indentation
  ?max_preserve_newlines
  ?operator_position
  ?preserve_newlines
  ?space_after_anon_function
  ?space_after_named_function
  ?space_in_empty_paren
  ?space_in_paren
  ?templating
  ?unescape_strings
  ?unindent_chained_methods
  ?wrap_line_length
  code =
    js
    code
    (jsOptions
      ?brace_style:(brace_style <$> BraceStyle.toString)
      ?break_chained_methods
      ?comma_first
      ?e4x
      ?editorconfig
      ?end_with_newline
      ?eol
      ?indent_char
      ?indent_empty_lines
      ?indent_level
      ?indent_size
      ?indent_with_tabs
      ?jslint_happy
      ?keep_array_indentation
      ?max_preserve_newlines
      ?operator_position:(operator_position <$> OperatorPosition.toString)
      ?preserve_newlines
      ?space_after_anon_function
      ?space_after_named_function
      ?space_in_empty_paren
      ?space_in_paren
      ?templating:(templating <$> (Array.map Templating.toString))
      ?unescape_strings
      ?unindent_chained_methods
      ?wrap_line_length
      ());;
