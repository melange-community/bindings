type error

external glob : string -> (error Js.nullable -> string array -> unit) -> unit = "" [@@bs.module]
external sync : string -> string array = "" [@@bs.val] [@@bs.module "glob"]
