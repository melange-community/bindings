type t = {
  c: int array;
  e: int;
  s: int
} [@@bs.deriving abstract]

type big = {
  mutable dp: int [@bs.as "DP"];
  mutable rm: int [@bs.as "RM"];
  mutable ne: int [@bs.as "NE"];
  mutable pe: int [@bs.as "PE"]
} [@@bs.deriving abstract]

exception Unknown_error
exception Div_by_zero
exception Invalid_number
exception Invalid_decimal_places
exception Invalid_rounding_mode
exception No_square_root
exception Invalid_precision

let try_wrap f js_msg exn =
  try f ()
  with Js.Exn.Error e ->
    match Js.Exn.message e with
      | Some m when m = js_msg -> raise exn
      | Some m -> Js.log m; raise Unknown_error
      | None -> raise Unknown_error

external fromStringExn: string -> t = "big.js" [@@bs.new] [@@bs.module]

let fromString s =
  try_wrap (fun () -> fromStringExn s) "[big.js] Invalid number" Invalid_number

external fromFloat: float -> t = "big.js" [@@bs.new] [@@bs.module]

external fromInt: int -> t = "big.js" [@@bs.new] [@@bs.module]

external bigJsObj: big = "big.js" [@@bs.val] [@@bs.module]

let setDP n =
  if n >= 0 then dpSet bigJsObj n else raise Invalid_decimal_places

let setRM n =
  if n >= 0 && n <= 3 then rmSet bigJsObj n else raise Invalid_rounding_mode

let setNE = neSet bigJsObj

let setPE = peSet bigJsObj

let getDP () = dpGet bigJsObj

let getRM () = rmGet bigJsObj

let getNE () = neGet bigJsObj

let getPE () = peGet bigJsObj

external abs: t -> t = "abs"[@@bs.send]

external cmp: t -> t -> int = "cmp"[@@bs.send]

external divExn: t -> t -> t = "div" [@@bs.send]

let div x y =
  try_wrap (fun () -> divExn x y) "[big.js] Division by zero" Div_by_zero

external eq: t -> t -> bool = "eq"[@@bs.send]

external gt: t -> t -> bool = "gt"[@@bs.send]

external gte: t -> t -> bool = "gte"[@@bs.send]

external lt: t -> t -> bool = "lt"[@@bs.send]

external lte: t -> t -> bool = "lte"[@@bs.send]

external minus: t -> t -> t = "minus"[@@bs.send]

external modExn: t -> t -> t = "mod" [@@bs.send]

let mod_ x y =
  try_wrap (fun () -> modExn x y) "[big.js] Division by zero" Div_by_zero

external plus: t -> t -> t = "plus"[@@bs.send]

external pow: t -> int -> t = "pow"[@@bs.send]

external round: t -> ?dp:int -> ?rm:int -> unit -> t = "round"[@@bs.send]

external sqrtExn: t -> t = "sqrt" [@@bs.send]

let sqrt x =
  try_wrap (fun () -> sqrtExn x) "[big.js] No square root" No_square_root

external times: t -> t -> t = "times"[@@bs.send]

external toExponential: t -> ?dp:int -> unit -> string = "toExponential"[@@bs.send]

external toFixed: t -> ?dp:int -> unit -> string = "toFixed"[@@bs.send]

external toPrecisionExn: t -> ?sd:int -> unit -> string = "toPrecision" [@@bs.send]

let toPrecision x ?sd () =
  try_wrap (fun () -> toPrecisionExn x ?sd ()) "[big.js] Invalid precision"
    Invalid_precision

external valueOf: t -> string = "valueOf"[@@bs.send]

external toString: t -> string = "toString"[@@bs.send]

external toJson: t -> string = "toJson"[@@bs.send]

let c = cGet

let e = eGet

let s = sGet
