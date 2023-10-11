open JsBeautify__Utils;;

module WrapAttributes = struct
  type t =
    [ `auto
    | `force
    | `forceAligned
    | `forceExpandMultiline
    | `alignedMultiple
    | `preserve
    | `preserveAligned
    ];;

  let toString = function
    | `auto -> "auto"
    | `force -> "force"
    | `forceAligned -> "force-aligned"
    | `forceExpandMultiline -> "force-expand-multiline"
    | `alignedMultiple -> "aligned-multiple"
    | `preserve -> "preserve"
    | `preserveAligned -> "preserve-aligned"
  ;;
end

type htmlOptions =
  { brace_style: string [@bs.optional]
  ; content_unformatted: (string list) [@bs.optional]
  ; editorconfig: bool [@bs.optional]
  ; end_with_newline: bool [@bs.optional]
  ; eol: string [@bs.optional]
  ; extra_liners: (string list) [@bs.optional]
  ; indent_char: string [@bs.optional]
  ; indent_empty_lines: bool [@bs.optional]
  ; indent_inner_html: bool [@bs.optional]
  ; indent_level: int [@bs.optional]
  ; indent_scripts: bool [@bs.optional]
  ; indent_size: int [@bs.optional]
  ; indent_with_tabs: bool [@bs.optional]
  ; inline: (string list) [@bs.optional]
  ; max_preserve_newlines: int [@bs.optional]
  ; preserve_newlines: bool [@bs.optional]
  ; templating: string array [@bs.optional]
  ; unformatted: (string list) [@bs.optional]
  ; unformatted_content_delimiter: string [@bs.optional]
  ; wrap_attributes: string [@bs.optional]
  ; wrap_attributes_indent_size: string [@bs.optional]
  ; wrap_line_length: int [@bs.optional]
  } [@@bs.deriving abstract];;

external html : string -> htmlOptions -> string = "html" [@@bs.module "js-beautify"];;

let html
  ?brace_style
  ?content_unformatted
  ?editorconfig
  ?end_with_newline
  ?eol
  ?extra_liners
  ?indent_char
  ?indent_empty_lines
  ?indent_inner_html
  ?indent_level
  ?indent_scripts
  ?indent_size
  ?indent_with_tabs
  ?inline
  ?max_preserve_newlines
  ?preserve_newlines
  ?templating
  ?unformatted
  ?unformatted_content_delimiter
  ?wrap_attributes
  ?wrap_attributes_indent_size
  ?wrap_line_length
  code =
    html
    code
    (htmlOptions
      ?brace_style:(brace_style <$> BraceStyle.toString)
      ?content_unformatted
      ?editorconfig
      ?end_with_newline
      ?eol
      ?extra_liners
      ?indent_char
      ?indent_empty_lines
      ?indent_inner_html
      ?indent_level
      ?indent_scripts
      ?indent_size
      ?indent_with_tabs
      ?inline
      ?max_preserve_newlines
      ?preserve_newlines
      ?templating:(templating <$> (Array.map Templating.toString))
      ?unformatted
      ?unformatted_content_delimiter
      ?wrap_attributes:(wrap_attributes <$> WrapAttributes.toString)
      ?wrap_attributes_indent_size
      ?wrap_line_length
      ());;
