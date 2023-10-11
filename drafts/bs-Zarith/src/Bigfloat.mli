(* 
 * Module:     Bigfloat
 * Copyright:  Plow Technologies, 2020
 * Maintainer: james.haver@plowtech.net 
 * Status:     Experimental
 * 
 * Support arbitrary percision floating point numbers in OCaml.
 * The user declares the level of precision
 *)

type t = {
  value: Bigint.t;
  decimalPos: int;
  }
(** Product type with a Bigint.t value and decimalPos is a non-negative number 
    representing the location of the decimal point 
  *)

val mkBigfloat: Bigint.t -> int -> t
       
val zero: t
(** The number 0 with 0 decimalPos. *)

val one: t
(** The number 1 with 0 decimalPos. *)

val minusOne: t
(** The number -1 with 0 decimalPos. *)


(** of conversions *)


val ofInt: int -> t
(** Converts from a base integer. *)

val ofInt32: Int32.t -> t
(** Converts from a 32-bit integer. *)

val ofInt64: Int64.t -> t
(** Converts from a 64-bit integer. *)

val ofFloat: float -> int -> t
(** Converts from a float. *)
  
val ofString: string -> int -> t option
(** Converts a string to an integer.
    An optional [-] prefix indicates a negative number.
 *)
                                
(** to conversions *)


val toInt: t -> int
(** Converts to a base integer. May raise [Overflow]. *)

val toInt32: t -> int32
(** Converts to a 32-bit integer. May raise [Overflow]. *)

val toInt64: t -> int64
(** Converts to a 64-bit integer. May raise [Overflow]. *)

val toFloat: t -> float
(** String representation of t. *)
  
val toString: t -> string
(** String representation of t. *)

val toStringWithCommas: t -> string
(** String representation of t with commas between every three digits left of the decimal. *)


(** queries *)

val adjustDecimalPos: t -> t -> (t * t)

(** arithmetic *)

val abs: t -> t
(** Absolute value. *)

val neg: t -> t
(** Unary negation. *)
  
val add: t -> t -> t
(** Addition. *)

val sub: t -> t -> t
(** Subtraction. *)

val mul: t -> t -> t
(** Multiplication. *)
  
val div: t -> t -> t
(** Integer division. *)

(** comparison *)
  
val compare : t -> t -> int
(** Comparison.  [compare x y] returns 0 if [x] equals [y],
    -1 if [x] is smaller than [y], and 1 if [x] is greater than [y].
 *)
  
val equal: t -> t -> bool
(** Equality test. *)
  
val leq: t -> t -> bool
(** Less than or equal. *)

val geq: t -> t -> bool
(** Greater than or equal. *)

val lt: t -> t -> bool
(** Less than (and not equal). *)

val gt: t -> t -> bool
(** Greater than (and not equal). *)

val leqZero: t -> bool
(** Less than or equal to zero. *)

val geqZero: t -> bool
(** Greater than or equal to zero. *)

val ltZero: t -> bool
(** Less than (and not equal) to zero. *)

val gtZero: t -> bool
(** Greater than (and not equal) to zero. *)
  
val min: t -> t -> t
(** Returns the minimum of its arguments. *)

val max: t -> t -> t
(** Returns the maximum of its arguments. *)
