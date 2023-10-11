(* 
 * Module:     U
 * Copyright:  Plow Technologies, 2020
 * Maintainer: james.haver@plowtech.net 
 *
 * Support unsigned integers in OCaml.
 *)

(** Types and operations for unsigned integers. *)

module type Infix = sig
  type t

  val (+) : t -> t -> t
  (** Addition.  See {!add}. *)

  val (-) : t -> t -> t
  (** Subtraction.  See {!sub}.*)

  val ( * ) : t -> t -> t
  (** Multiplication.  See {!mul}.*)

  val (/) : t -> t -> t
  (** Division.  See {!div}.*)

  val (mod) : t -> t -> t
  (** Integer remainder.  See {!rem}. *)

  val (land) : t -> t -> t
  (** Bitwise logical and.  See {!logand}. *)

  val (lor) : t -> t -> t
  (** Bitwise logical or.  See {!logor}. *)

  val (lxor) : t -> t -> t
  (** Bitwise logical exclusive or.  See {!logxor}. *)

  val (lsl) : t -> int -> t
  (** [x lsl y] shifts [x] to the left by [y] bits.  See {!shiftLeft}. *)

  val (lsr) : t -> int -> t
  (** [x lsr y] shifts [x] to the right by [y] bits.  See {!shiftRight}. *)
end
(** Infix names for the unsigned integer operations. *)


module type S = sig
  type t

  val add : t -> t -> t
  (** Addition. *)

  val sub : t -> t -> t
  (** Subtraction. *)

  val mul : t -> t -> t
  (** Multiplication. *)

  val div : t -> t -> t
  (** Division.  Raise {!Division_by_zero} if the second argument is zero. *)

  val rem : t -> t -> t
  (** Integer remainder.  Raise {!Division_by_zero} if the second argument is
      zero. *)

  val maxInt : t
  (** The greatest representable integer. *)

  val logand : t -> t -> t
  (** Bitwise logical and. *)

  val logor : t -> t -> t
  (** Bitwise logical or. *)

  val logxor : t -> t -> t
  (** Bitwise logical exclusive or. *)

  val shiftLeft : t -> int -> t
  (** {!shiftLeft} [x] [y] shifts [x] to the left by [y] bits. *)

  val shiftRight : t -> int -> t
  (** {!shiftRight} [x] [y] shifts [x] to the right by [y] bits. *)

  val ofInt : int -> t
  (** Convert the given int value to an unsigned integer. *)

  val toInt : t -> int
  (** Convert the given unsigned integer value to an int. *)

  val ofInt64 : int64 -> t
  (** Convert the given int64 value to an unsigned integer. *)

  val toInt64 : t -> int64
  (** Convert the given unsigned integer value to an int64. *)

  val ofString : string -> t option
  (** Convert the given string to an unsigned integer.  Raise {!Failure}
      ["int_ofString"] if the given string is not a valid representation of
      an unsigned integer. *)

  val toString : t -> string
  (** Return the string representation of its argument. *)

  val zero : t
  (** The integer 0. *)

  val one : t
  (** The integer 1. *)

  val lognot : t -> t
  (** Bitwise logical negation. *)

  val succ : t -> t
  (** Successor. *)

  val pred : t -> t
  (** Predecessor. *)

  val compare : t -> t -> int
  (** The comparison function for unsigned integers, with the same
      specification as {!Pervasives.compare}. *)

  val equal : t -> t -> bool
  (** Tests for equality, with the same specification as {!Pervasives.(=)}. *)

  val max : t -> t -> t
  (** [max x y] is the greater of [x] and [y] *)

  val min : t -> t -> t
  (** [min x y] is the lesser of [x] and [y] *)

  module Infix : Infix with type t := t
end

module UInt8 : S with type t = private int
(** Unsigned 8-bit integer type and operations. *)

module UInt16 : S with type t = private int
(** Unsigned 16-bit integer type and operations. *)

module UInt32 : S with type t = Int64.t
(** Unsigned 32-bit integer type and operations. *)

module UInt64 : S with type t = Bigint.t
(** Unsigned 64-bit integer type and operations. *)
