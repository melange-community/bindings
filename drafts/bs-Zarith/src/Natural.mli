(* 
 * Module:     Natural
 * Copyright:  Plow Technologies, 2020
 * Maintainer: james.haver@plowtech.net 
 *
 * Support arbitrary precision Natural numbers in OCaml.
 *)

exception Underflow
(** Raised by conversion and sub functions when the value cannot be represented 
    as a Natural number.
 *)

exception DecodeError
(** Raised by unsafeToString conversion if the string is not a valid 
    Natural number *)        

type t = Natural of Bigint.t
(** Type of Natural, a non-negative arbitrary length integer. *)

val zero: t
(** The number 0. *)

val one: t
(** The number 1. *)

(** of conversion *)

val ofInt: int -> t option
(** Converts from a base integer. *)

val ofInt32: Int32.t -> t option
(** Converts from a 32-bit integer. *)

val ofInt64: Int64.t -> t option
(** Converts from a 64-bit integer. *)

val ofFloat: float -> t option
(** Converts from a float. *)

val ofString: string -> t option
(** Converts from a string. *)

val unsafeOfInt: int -> t
(** Unsafely converts from a base integer. *)

val unsafeOfInt32: Int32.t -> t
(** Unsafely converts from a 32-bit integer. *)

val unsafeOfInt64: Int64.t -> t
(** Unsafely converts from a 64-bit integer. *)

val unsafeOfFloat: float -> t
(** Unsafely converts from a float. *)

val unsafeOfString: string -> t
(** Unsafely converts from a string. *)  
  
(** to conversion *)  

val toInt: t -> int
(** Converts to a base integer. May raise [Overflow]. *)

val toInt32: t -> int32
(** Converts to a 32-bit integer. May raise [Overflow]. *)

val toInt64: t -> int64
(** Converts to a 64-bit integer. May raise [Overflow]. *)

val toFloat: t -> float
(** Converts to a floating-point value. *)

val toString: t -> string
(** Gives a human-readable, decimal string representation of the argument. *)
  
(** arithmetic *)

val succ: t -> t
(** Returns its argument plus one. *)

val pred: t -> t
(** Unsafe returns its argument minus one. *)

val predSafe: t -> t option
(** Safe returns its argument minus one. *)
  
val add: t -> t -> t
(** Addition. *)

val sub: t -> t -> t
(** Unsafe subtraction. *)

val subSafe: t -> t -> t option
(** Safe subtraction. *)
  
val mul: t -> t -> t
(** Multiplication. *)

val div: t -> t -> t
(** Integer division. The result is truncated towards zero
    and obeys the rule of signs.
    Raises [Division_by_zero] if the divisor (second argument) is 0.
 *)

val rem: t -> t -> t
(** Integer remainder. Can raise a [Division_by_zero].
    The result of [rem a b] has the sign of [a], and its absolute value is
    strictly smaller than the absolute value of [b].
    The result satisfies the equality [a = b * div a b + rem a b].
 *)

val divRem: t -> t -> (t * t)
(** Computes both the integer quotient and the remainder.
    [div_rem a b] is equal to [(div a b, rem a b)].
    Raises [Division_by_zero] if [b = 0].
 *)

val cdiv: t -> t -> t
(** Integer division with rounding towards +oo (ceiling).
    Can raise a [Division_by_zero].
 *)

val fdiv: t -> t -> t
(** Integer division with rounding towards -oo (floor).
    Can raise a [Division_by_zero].
 *)

val edivRem: t -> t -> (t * t)
(** Euclidean division and remainder.  [ediv_rem a b] returns a pair [(q, r)]
    such that [a = b * q + r] and [0 <= r < |b|].
    Raises [Division_by_zero] if [b = 0].
 *)

val ediv: t -> t -> t
(** Euclidean division. [ediv a b] is equal to [fst (ediv_rem a b)].
    The result satisfies [0 <= a - b * ediv a b < |b|].
    Raises [Division_by_zero] if [b = 0].
 *)

val erem: t -> t -> t
(** Euclidean remainder.  [erem a b] is equal to [snd (ediv_rem a b)].
    The result satisfies [0 <= erem a b < |b|] and
    [a = b * ediv a b + erem a b].  Raises [Division_by_zero] if [b = 0].
 *)

val divexact: t -> t -> t
(** [divexact a b] divides [a] by [b], only producing correct result when the
    division is exact, i.e., when [b] evenly divides [a].
    It should be faster than general division.
    Can raise a [Division_by_zero].
 *)
                     
