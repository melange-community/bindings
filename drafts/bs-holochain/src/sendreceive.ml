open Constants
(** Implements a send and receive coupling for some particular
    zome and input / output types.
*)

(** Base signature for send and receive functionality *)
module type S0 =
sig
  type input (** the arguments to [send] *)
  type output (** the output returned by [receive] *)

  (** Callback to receive a message via the send / receive protocol.
      The [hashString] is the sender address. The callback must
      implement a value from type [output] derived from type [input].

      It may use other native holochain functions to accomplish, including
      mutating operations.
  *)
  val receive : App0.Agent.hash -> input -> output
end

(** A sender and receiver pair. The [input] and [output] types are fixed
    and scoped to a particular zome.
*)
module type S = sig
  include S0
  val send : App0.Agent.hash -> input -> output
end

(** Makes a sender and receiver pair given the receiver callback module. *)
module Make (T : S0) :
  S with type input = T.input with type output = T.output =
struct
  include T
  external send : App0.Agent.hash -> input -> output = "" [@@bs.val]
end

(** A minimal [SendReceive.S] implementation which accepts unit and returns unit. *)
module Unit : S with type input = unit and type output = unit =
  Make(struct type input = unit type output = unit let receive _ () = () end)
