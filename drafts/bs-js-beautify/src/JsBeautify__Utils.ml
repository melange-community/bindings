module BraceStyle = struct
  type t =
    [ `collapse
    | `expand
    | `endExpand
    | `none
    | `preserveInline
    | `collapsePreserveInline
    ];;

  let toString = function
    | `collapse -> "collapse"
    | `expand -> "expand"
    | `endExpand -> "end-expand"
    | `none -> "none"
    | `preserveInline -> "preserve-inline"
    | `collapsePreserveInline -> "collapse,preserve-inline"
  ;;
end

module Templating = struct
  type t =
    [ `auto
    | `none
    | `django
    | `erb
    | `handlebars
    | `php
    ];;

  let toString = function
    | `auto -> "auto"
    | `none -> "none"
    | `django -> "django"
    | `erb -> "erb"
    | `handlebars -> "handlebars"
    | `php -> "php"
  ;;
end

module OperatorPosition = struct
  type t = [ `beforeNewline  | `afterNewline  | `preserveNewline ];;

  let toString = function
    | `beforeNewline -> "before-newline"
    | `afterNewline -> "after-newline"
    | `preserveNewline -> "preserve-newline"
  ;;
end

let (<$>) option mapper = (
  match option with
  | None -> None
  | Some value -> Some (mapper value)
);;