(* 
 * Module:     Bigint
 * Copyright:  Plow Technologies, 2020
 * Maintainer: james.haver@plowtech.net 
 * Status:     Experimental
 * 
 * Support arbitrary percision integers in OCaml.
 *)

exception Overflow
(** Raised by conversion functions when the value cannot be represented in
    the destination type.
 *)

type sign = Pos | Neg
(** Sum type representing the Bigint's sign. *)

type t    = Bigint of sign * int list
(** Type of Bigint, arbitrary length integer. *)

(** {1 Construction} *)

val zero: t
(** The number 0. *)

val one: t
(** The number 1. *)

val minus_one: t
(** The number -1. *)

val of_int: int -> t
(** Converts from a base integer. *)

val of_int32: Int32.t -> t
(** Converts from a 32-bit integer. *)

val of_int64: Int64.t -> t
(** Converts from a 64-bit integer. *)

val of_float: float -> t
(** Converts from a float. *)

val of_string: string -> t
(** Converts a string to an integer.
    An optional [-] prefix indicates a negative number.
 *)

val of_string_opt: string -> t option
(** Safe version of of_string
 *)
  
val of_substring : string -> pos:int -> len:int -> t
(**

 *)

(** {1 Basic arithmetic operations} *)

val succ: t -> t
(** Returns its argument plus one. *)

val pred: t -> t
(** Returns its argument minus one. *)

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

val div_rem: t -> t -> (t * t)
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

val ediv_rem: t -> t -> (t * t)
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


(** {1 Bit-level operations} *)

(** For all bit-level operations, negative numbers are considered in 2's
    complement representation, starting with a virtual infinite number of
    1s.
 *)

val logand: t -> t -> t
(** Bitwise logical and. *)

val logor: t -> t -> t
(** Bitwise logical or. *)

val logxor: t -> t -> t
(** Bitwise logical exclusive or. *)

val lognot: t -> t
(** Bitwise logical negation.
    The identity [lognot a]=[-a-1] always hold.
 *)

val shift_left : t -> int -> t
(** Shifts to the left.
    Equivalent to a multiplication by a power of 2.
    The second argument must be non-negative.
 *)

val shift_right : t -> int -> t
(** Shifts to the right.
    This is an arithmetic shift,
    equivalent to a division by a power of 2 with rounding towards -oo.
    The second argument must be non-negative.
 *)

(* val shift_right_trunc: t -> int -> t *)
(** Shifts to the right, rounding towards 0.
    This is equivalent to a division by a power of 2, with truncation.
    The second argument must be non-negative.
 *)

val numbits : t -> int
(** Returns the number of significant bits in the given number.
    If [x] is zero, [numbits x] returns 0.  Otherwise,
    [numbits x] returns a positive integer [n] such that
    [2^{n-1} <= |x| < 2^n].  Note that [numbits] is defined
    for negative arguments, and that [numbits (-x) = numbits x]. *)

(* val trailing_zeros: t -> int *)
(** Returns the number of trailing 0 bits in the given number.
    If [x] is zero, [trailing_zeros x] returns [max_int].
    Otherwise, [trailing_zeros x] returns a nonnegative integer [n]
    which is the largest [n] such that [2^n] divides [x] evenly.
    Note that [trailing_zeros] is defined for negative arguments,
    and that [trailing_zeros (-x) = trailing_zeros x]. *)

(* val testbit: t -> int -> bool *)
(** [testbit x n] return the value of bit number [n] in [x]:
    [true] if the bit is 1, [false] if the bit is 0.
    Bits are numbered from 0.  Raise [Invalid_argument] if [n]
    is negative. *)

(* val popcount: t -> int *)
(** Counts the number of bits set.
    Raises [Overflow] for negative arguments, as those have an infinite
    number of bits set.
 *)

(* val hamdist: t -> t -> int *)
(** Counts the number of different bits.
    Raises [Overflow] if the arguments have different signs
    (in which case the distance is infinite).
 *)

(** {1 Conversions} *)

(** Note that, when converting to an integer type that cannot represent the
    converted value, an [Overflow] exception is raised.
 *)

val to_int: t -> int
(** Converts to a base integer. May raise [Overflow]. *)

val to_int32: t -> int32
(** Converts to a 32-bit integer. May raise [Overflow]. *)

val to_int64: t -> int64
(** Converts to a 64-bit integer. May raise [Overflow]. *)

val to_float: t -> float
(** Converts to a floating-point value.
    This function rounds the given integer according to the current
    rounding mode of the processor.  In default mode, it returns
    the floating-point number nearest to the given integer,
    breaking ties by rounding to even. *)

val to_string: t -> string
(** Gives a human-readable, decimal string representation of the argument. *)

(** {1 Ordering} *)

val compare : t -> t -> int
(** Comparison.  [compare x y] returns 0 if [x] equals [y],
    -1 if [x] is smaller than [y], and 1 if [x] is greater than [y].

    Note that Pervasive.compare can be used to compare reliably two integers
    only on OCaml 3.12.1 and later versions.
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

val sign: t -> int
(** Returns -1, 0, or 1 when the argument is respectively negative, null, or
    positive.
 *)

val min: t -> t -> t
(** Returns the minimum of its arguments. *)

val max: t -> t -> t
(** Returns the maximum of its arguments. *)

val is_even: t -> bool
(** Returns true if the argument is even (divisible by 2), false if odd. *)

val is_odd: t -> bool
(** Returns true if the argument is odd, false if even. *)

(* val hash: t -> int *)
(** Hashes a number.
    This functions gives the same result as OCaml's polymorphic hashing
    function.
    The result is consistent with equality: if [a] = [b], then [hash a] =
    [hash b].
 *)

(** {1 Elementary number theory} *)

val gcd: t -> t -> t
(** Greatest common divisor.
    The result is always positive.
    Raises a [Division_by_zero] is either argument is null.
 *)

(* val gcdext: t -> t -> (t * t * t) *)
(** [gcdext u v] returns [(g,s,t)]  where [g] is the greatest common divisor
    and [g=us+vt].
    [g] is always positive.
    Raises a [Division_by_zero] is either argument is null.

    Note: the function is based on the GMP [mpn_gcdext] function. The exact choice of [s] and [t] such that [g=us+vt] is not specified, as it may vary from a version of GMP to another (it has changed notably in GMP 4.3.0 and 4.3.1).
 *)

(* val lcm: t -> t -> t *)
(**
    Least common multiple.
    The result is always positive.
    Raises a [Division_by_zero] is either argument is null.
 *)

(* val powm: t -> t -> t -> t *)
(** [powm base exp mod] computes [base]^[exp] modulo [mod].
    Negative [exp] are supported, in which case ([base]^-1)^(-[exp]) modulo
    [mod] is computed.
    However, if [exp] is negative but [base] has no inverse modulo [mod], then
    a [Division_by_zero] is raised.
 *)

(* val powm_sec: t -> t -> t -> t *)
(** [powm_sec base exp mod] computes [base]^[exp] modulo [mod].
    Unlike [Z.powm], this function is designed to take the same time
    and have the same cache access patterns for any two same-size
    arguments.  Used in cryptographic applications, it provides better
    resistance to side-channel attacks than [Z.powm].
    The exponent [exp] must be positive, and the modulus [mod]
    must be odd.  Otherwise, [Invalid_arg] is raised. *)

(* val invert: t -> t -> t *)
(** [invert base mod] returns the inverse of [base] modulo [mod].
    Raises a [Division_by_zero] if [base] is not invertible modulo [mod].
 *)

(* val probab_prime: t -> int -> int *)
(** [probab_prime x r] returns 0 if [x] is definitely composite,
    1 if [x] is probably prime, and 2 if [x] is definitely prime.
    The [r] argument controls how many Miller-Rabin probabilistic
    primality tests are performed (5 to 10 is a reasonable value).
 *)

(* val nextprime: t -> t *)
(** Returns the next prime greater than the argument.
    The result is only prime with very high probability.
 *)


(** {1 Powers} *)

val pow: t -> int -> t
(** [pow base exp] raises [base] to the [exp] power.
    [exp] must be non-negative.
    Note that only exponents fitting in a machine integer are supported, as
    larger exponents would surely make the result's size overflow the
    address space.
    Raises an [Invalid_argument] on negative [exp].    
 *)

(* val sqrt: t -> t *)
(** Returns the square root. The result is truncated (rounded down
    to an integer).
    Raises an [Invalid_argument] on negative arguments.
 *)

(* val sqrt_rem: t -> (t * t) *)
(** Returns the square root truncated, and the remainder.
    Raises an [Invalid_argument] on negative arguments.
 *)

(* val root: t -> int -> t *)
(** [root base n] computes the [n]-th root of [exp].
    [n] must be non-negative.
 *)

(* val perfect_power: t -> bool *)
(** True if the argument has the form [a^b], with [b>1] *)

(* val perfect_square: t -> bool *)
(** True if the argument has the form [a^2]. *)

(* val log2: t -> int *)
(** Returns the base-2 logarithm of its argument, rounded down to
    an integer.  If [x] is positive, [log2 x] returns the largest [n]
    such that [2^n <= x].  If [x] is negative or zero, [log2 x] raise
    the [Invalid_argument] exception. *)

(* val log2up: t -> int *)
(** Returns the base-2 logarithm of its argument, rounded up to
    an integer.  If [x] is positive, [log2up x] returns the smallest [n]
    such that [x <= 2^n].  If [x] is negative or zero, [log2up x] raise
    the [Invalid_argument] exception. *)


(** {1 Representation} *)

(* val size: t -> int *)
(** Returns the number of machine words used to represent the number. *)

(* val extract: t -> int -> int -> t *)
(** [extract a off len] returns a non-negative number corresponding to bits
    [off] to [off]+[len]-1 of [b].
    Negative [a] are considered in infinite-length 2's complement
    representation.
 *)

(* signed_extract: t -> int -> int -> t *)
(** [signed_extract a off len] extracts bits [off] to [off]+[len]-1 of [b],
    as [extract] does, then sign-extends bit [len-1] of the result
    (that is, bit [off + len - 1] of [a]).  The result is between
    [- 2{^[len]-1}] (included) and [2{^[len]-1}] (excluded),
    and equal to [extract a off len] modulo [2{^len}].
 *)

(* val to_bits: t -> string *)
(** Returns a binary representation of the argument.
    The string result should be interpreted as a sequence of bytes,
    corresponding to the binary representation of the absolute value of
    the argument in little endian ordering.
    The sign is not stored in the string.
 *)

(* val of_bits: string -> t *)
(** Constructs a number from a binary string representation.
    The string is interpreted as a sequence of bytes in little endian order,
    and the result is always positive.
    We have the identity: [of_bits (to_bits x) = abs x].
    However, we can have [to_bits (of_bits s) <> s] due to the presence of
    trailing zeros in s.
 *)


(** {1 Prefix and infix operators} *)

(**
   Classic (and less classic) prefix and infix [int] operators are
   redefined on [t].

   This makes it easy to typeset expressions.
   Using OCaml 3.12's local open, you can simply write
   [Z.(~$2 + ~$5 * ~$10)].
 *)

val (~-): t -> t
(** Negation [neg]. *)

val (~+): t -> t
(** Identity. *)

val (+): t -> t -> t
(** Addition [add]. *)

val (-): t -> t -> t
(** Subtraction [sub]. *)

val ( * ): t -> t -> t
(** Multiplication [mul]. *)

val (/): t -> t -> t
(** Truncated division [div]. *)

val (/>): t -> t -> t
(** Ceiling division [cdiv]. *)

val (/<): t -> t -> t
(** Flooring division [fdiv]. *)

val (/|): t -> t -> t
(** Exact division [divexact]. *)

val (mod): t -> t -> t
(** Remainder [rem]. *)

val (land): t -> t -> t
(** Bit-wise logical and [logand]. *)

val (lor): t -> t -> t
(** Bit-wise logical inclusive or [logor]. *)

val (lxor): t -> t -> t
(** Bit-wise logical exclusive or [logxor]. *)

val (~!): t -> t
(** Bit-wise logical negation [lognot]. *)

val (lsl): t -> int -> t
(** Bit-wise shift to the left [shift_left]. *)

val (asr): t -> int -> t
(** Bit-wise shift to the right [shift_right]. *)

val (~$): int -> t
(** Conversion from [int] [of_int]. *)

val ( ** ): t -> int -> t
(** Power [pow]. *)

val (=): t -> t -> bool
(** Same as [equal]. *)

val (<): t -> t -> bool
(** Same as [lt]. *)

val (>): t -> t -> bool
(** Same as [gt]. *)

val (<=): t -> t -> bool
(** Same as [leq]. *)

val (>=): t -> t -> bool
(** Same as [geq]. *)

val (<>): t -> t -> bool
(** [a <> b] is equivalent to [not (equal a b)]. *)


(** {1 Miscellaneous} *)

(**/**)

(** For internal use in module [Q]. *)
val round_to_float: t -> bool -> float

val firstNonZero: t -> int option                 
