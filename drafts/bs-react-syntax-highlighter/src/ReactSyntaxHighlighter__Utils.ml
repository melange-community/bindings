let (<$>) option mapper = (
  match option with
  | None -> None
  | Some value -> Some (mapper value)
);;

module JsUnsafe = struct
  type t;;

  external make : 'a -> t = "%identity";;
end

module Element = struct
  type t =
    < properties: ReactDOMRe.props
    ; type_: string
    ; tagName: string
    ; value: string
    ; children: t array
    > Js.t
  ;;
end

module LineProps = struct
  type t =
    [ `Factory of int -> ReactDOMRe.props
    | `Plain of ReactDOMRe.props
    ]
  ;;

  let make (value: t) =
    match value with
    | `Factory propsFactory -> JsUnsafe.make propsFactory
    | `Plain plainProps -> JsUnsafe.make plainProps
  ;;
end

module type StyleModule = sig
  type t;;
end

module CommonRenderer (Style: StyleModule) = struct
  module Input = struct
    type t =
      < rows: Element.t array
      ; stylesheet: Style.t
      ; useInlineStyles: bool
      > Js.t
    ;;
  end

  type t = Input.t -> React.element;;
end

module Tag = struct
  type 'a t = [
    | `intrinsic of string
    | `component of 'a
  ];;

  let make = function
  | `intrinsic t -> JsUnsafe.make t
  | `component c -> JsUnsafe.make c
  ;;
end