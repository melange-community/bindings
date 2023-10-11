(** A zome function with strict input and output type definitions.
    It must be a exported function equal to the [name] field or you
    will experience runtime errors.

    Note that at the moment this module is only useful to dependent
    client libraries since functions can be invoked locally otherwise.
*)

module type S0 =
sig
  module Zome : Named.S
  include Named.S
  type input
  type output
end

module type S = sig
  include Named.S
  type input
  type output

  (** Call invokes a public function of zome Zome]. This may
      or may not be IO intensive depending on the agent invoking
      the call.
  *)
  val call : input -> output
end

module type S_EXPORT = sig
  include Named.S
  type input
  type output

  (** Call invokes a public function of zome Zome]. This may
      or may not be IO intensive depending on the agent invoking
      the call.
  *)
  val call : input -> output

  (** [export] is a function intended to be exported with a
      function alias with symbol equal to [name].

      Note :This must be done by the user of this library manually.
  *) val export : Js.Json.t -> Js.Json.t


  (** [local input] invokes a function locally without
      any marshaling or IO. Useful when you know the
      function is hosted locally and want to speed up
      the invocations.
  *)
 val local : input -> output
end


module Make (T : S0) : S
  with type input = T.input
  with type output = T.output = struct
  include T
  external call :
    zomeName:string -> functionName:string ->
    input -> output = "" [@@bs.val]
  let call args =
    call ~zomeName:T.Zome.name ~functionName:T.name args
end

module type T_BS =
sig
  include S0
  val write_input : input -> Js.Json.t
  val read_output : Js.Json.t -> output
  val read_input : Js.Json.t -> input
  val write_output : output -> Js.Json.t
  val local : input -> output

end

module Make_bs(T : T_BS) :
  S_EXPORT with type input = T.input with type output = T.output =
struct
  include T
  external call :
    zomeName:string -> functionName:string ->
    Js.Json.t -> Js.Json.t = "" [@@bs.val]

  let call args =
    call ~zomeName:T.Zome.name ~functionName:T.name
      (write_input args) |>
    read_output

  let export args =
    local (read_input args) |> write_output

end

(** [call (module T) args] calls function [T] with [args] in the zome as
    described by [T.Zome].
*)
let call
    (type input) (type output)
    (module T:S0 with type input = input and type output = output) =
  let module M = Make(T) in
  M.call

let export
    (type input) (type output)
    (module T:T_BS with type input = input and type output = output) =
  let module M = Make_bs(T) in
  M.export

