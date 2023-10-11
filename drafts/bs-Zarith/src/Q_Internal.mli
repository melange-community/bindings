module Q (Z: Z.Z) : sig
  (** {1 Types} *)


  type t = {
      num: Z.t; (** Numerator. *)
      den: Z.t; (** Denominator, >= 0 *)
    }
  (** A rational is represented as a pair numerator/denominator, reduced to
    have a non-negative denominator and no common factor.
    This form is canonical (enabling polymorphic equality and hashing).
    The representation allows three special numbers: [inf] (1/0), [-inf] (-1/0)
    and [undef] (0/0).
   *)

  (** {1 Construction} *)

  val make: Z.t -> Z.t -> t
  (** [make num den] constructs a new rational equal to [num]/[den].
    It takes care of putting the rational in canonical form.
   *)

  val zero: t
  val one: t
  val minus_one:t
  (** 0, 1, -1. *)

  val inf: t
  (** 1/0. *)

  val minus_inf: t
  (** -1/0. *)

  val undef: t
  (** 0/0. *)

  val of_bigint: Bigint.t -> t
  val of_int: int -> t
  val of_int32: int32 -> t
  val of_int64: int64 -> t
  (** Conversions from various integer types. *)

  val of_ints: int -> int -> t
  (** Conversion from an [int] numerator and an [int] denominator. *)

  val of_float: float -> t
  (** Conversion from a [float].
    The conversion is exact, and maps NaN to [undef].
   *)


  val of_string: string -> t
  (** Converts a string to a rational.
    Plain integers, and [/] separated integer ratios (with optional sign) are
    understood.
    Additionally, the special [inf], [-inf], and [undef] are recognized
    (they can also be typeset respectively as [1/0], [-1/0], [0/0]).
   *)


  (** {1 Inspection} *)

  val num: t -> Z.t
  (** Get the numerator. *)

  val den: t -> Z.t
  (** Get the denominator. *)


  (** {1 Testing} *)

  type kind =
    | ZERO   (** 0 *)
    | INF    (** infinity, i.e. 1/0 *)
    | MINF   (** minus infinity, i.e. -1/0 *)
    | UNDEF  (** undefined, i.e., 0/0 *)
    | NZERO  (** well-defined, non-infinity, non-zero number *)
  (** Rationals can be categorized into different kinds, depending mainly on
    whether the numerator and/or denominator is null.
   *)

  val classify: t -> kind
  (** Determines the kind of a rational. *)

  val is_real: t -> bool
  (** Whether the argument is non-infinity and non-undefined. *)

  val sign: t -> int
  (** Returns 1 if the argument is positive (including inf), -1 if it is
    negative (including -inf), and 0 if it is null or undefined.
   *)

  val compare: t -> t -> int
  (** [compare x y] compares [x] to [y] and returns 1 if [x] is strictly
    greater that [y], -1 if it is strictly smaller, and 0 if they are
    equal.
    This is a total ordering.
    Infinities are ordered in the natural way, while undefined is considered
    the smallest of all: undef = undef < -inf <= -inf < x < inf <= inf.
    This is consistent with OCaml's handling of floating-point infinities
    and NaN.

    OCaml's polymorphic comparison will NOT return a result consistent with
    the ordering of rationals.
   *)

  val equal: t -> t -> bool
  (** Equality testing.
    This is consistent with [compare]; in particular, [undef]=[undef].
   *)

  val min: t -> t -> t
  (** Returns the smallest of its arguments. *)

  val max: t -> t -> t
  (** Returns the largest of its arguments. *)

  val leq: t -> t -> bool
  (** Less than or equal. *)

  val geq: t -> t -> bool
  (** Greater than or equal. *)

  val lt: t -> t -> bool
  (** Less than (not equal). *)

  val gt: t -> t -> bool
  (** Greater than (not equal). *)


  (** {1 Conversions} *)

  val to_bigint: t -> Bigint.t
  val to_int: t -> int
  val to_int32: t -> int32
  val to_int64: t -> int64
  (** Convert to integer by truncation.
    Raises a [Divide_by_zero] if the argument is an infinity or undefined.
    Raises a [Z.Overflow] if the result does not fit in the destination
    type.
   *)

  val to_string: t -> string
  (** Converts to human-readable, base-10, [/]-separated rational. *)

  val to_float: t -> float
  (** Converts to a floating-point number, using the current
    floating-point rounding mode.  With the default rounding mode,
    the result is the floating-point number closest to the given
    rational; ties break to even mantissa. *)

  (** {1 Arithmetic operations} *)

  (**
   In all operations, the result is [undef] if one argument is [undef].
   Other operations can return [undef]: such as [inf]-[inf], [inf]*0, 0/0.
   *)

  val neg: t -> t
  (** Negation. *)

  val abs: t -> t
  (** Absolute value. *)

  val add: t -> t -> t
  (** Addition. *)

  val sub: t -> t -> t
  (** Subtraction. We have [sub x y] = [add x (neg y)]. *)

  val mul: t -> t -> t
  (** Multiplication. *)

  val inv: t -> t
  (** Inverse.
    Note that [inv 0] is defined, and equals [inf].
   *)

  val div: t -> t -> t
  (** Division.
    We have [div x y] = [mul x (inv y)], and [inv x] = [div one x].
   *)

  val mul_2exp: t -> int -> t
  (** [mul_2exp x n] multiplies [x] by 2 to the power of [n]. *)

  val div_2exp: t -> int -> t
  (** [div_2exp x n] divides [x] by 2 to the power of [n]. *)

  (** {1 Prefix and infix operators} *)

  (**
   Classic prefix and infix [int] operators are redefined on [t].
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
  (** Division [div]. *)

  val (lsl): t -> int -> t
  (** Multiplication by a power of two [mul_2exp]. *)

  val (asr): t -> int -> t
  (** Division by a power of two [shift_right]. *)

  val (~$): int -> t
  (** Conversion from [int]. *)

  val (//): int -> int -> t
  (** Creates a rational from two [int]s. *)

  val (~$$): Z.t -> t
  (** Conversion from [Z.t]. *)

  val (///): Z.t -> Z.t -> t
  (** Creates a rational from two [Z.t]. *)

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
end

module QInt : sig
  module M : sig
    type t = Q(Z.Int).t = { num : Z.Int.t; den : Z.Int.t; }
    val mk : Z.Int.t -> Z.Int.t -> t
    val make_real : Z.Int.t -> Z.Int.t -> t
    val make : Z.Int.t -> Z.Int.t -> t
    val of_bigint : Bigint.t -> t
    val of_int : int -> t
    val of_int32 : Int32.t -> t
    val of_int64 : Int64.t -> t
    val of_ints : int -> int -> t
    val zero : t
    val one : t
    val minus_one : t
    val inf : t
    val minus_inf : t
    val undef : t
    val of_float : float -> t
    val of_string : string -> t
    type kind = Q(Z.Int).kind = ZERO | INF | MINF | UNDEF | NZERO
    val classify : t -> kind
    val is_real : t -> bool
    val num : t -> Z.Int.t
    val den : t -> Z.Int.t
    val sign : t -> int
    val equal : t -> t -> bool
    val compare : t -> t -> int
    val min : t -> t -> t
    val max : t -> t -> t
    val leq : t -> t -> bool
    val geq : t -> t -> bool
    val lt : t -> t -> bool
    val gt : t -> t -> bool
    val to_string : t -> string
    val to_bigint: t -> Bigint.t
    val to_int : t -> int
    val to_int32 : t -> int32
    val to_int64 : t -> int64
    val to_float : t -> float
    val neg : t -> t
    val abs : t -> t
    val aors : (Z.Int.t -> Z.Int.t -> Z.Int.t) -> t -> t -> t
    val add : t -> t -> t
    val sub : t -> t -> t
    val mul : t -> t -> t
    val inv : t -> t
    val div : t -> t -> t
    val mul_2exp : t -> int -> t
    val div_2exp : t -> int -> t
    val ( ~- ) : t -> t
    val ( ~+ ) : 'a -> 'a
    val ( + ) : t -> t -> t
    val ( - ) : t -> t -> t
    val ( * ) : t -> t -> t
    val ( / ) : t -> t -> t
    val ( lsl ) : t -> int -> t
    val ( asr ) : t -> int -> t
    val ( ~$ ) : int -> t
    val ( // ) : int -> int -> t
    val ( ~$$ ) : Z.Int.t -> t
    val ( /// ) : Z.Int.t -> Z.Int.t -> t
    val ( = ) : t -> t -> bool
    val ( < ) : t -> t -> bool
    val ( > ) : t -> t -> bool
    val ( <= ) : t -> t -> bool
    val ( >= ) : t -> t -> bool
    val ( <> ) : t -> t -> bool
  end
end
module QInt32 : sig
  module M : sig
    type t = Q(Z.Int32).t = { num : Z.Int32.t; den : Z.Int32.t; }
    val mk : Z.Int32.t -> Z.Int32.t -> t
    val make_real : Z.Int32.t -> Z.Int32.t -> t
    val make : Z.Int32.t -> Z.Int32.t -> t
    val of_bigint : Bigint.t -> t
    val of_int : int -> t
    val of_int32 : Int32.t -> t
    val of_int64 : Int64.t -> t
    val of_ints : int -> int -> t
    val zero : t
    val one : t
    val minus_one : t
    val inf : t
    val minus_inf : t
    val undef : t
    val of_float : float -> t
    val of_string : string -> t
    type kind = Q(Z.Int32).kind = ZERO | INF | MINF | UNDEF | NZERO
    val classify : t -> kind
    val is_real : t -> bool
    val num : t -> Z.Int32.t
    val den : t -> Z.Int32.t
    val sign : t -> int
    val equal : t -> t -> bool
    val compare : t -> t -> int
    val min : t -> t -> t
    val max : t -> t -> t
    val leq : t -> t -> bool
    val geq : t -> t -> bool
    val lt : t -> t -> bool
    val gt : t -> t -> bool
    val to_string : t -> string
    val to_bigint: t -> Bigint.t
    val to_int : t -> int
    val to_int32 : t -> int32
    val to_int64 : t -> int64
    val to_float : t -> float
    val neg : t -> t
    val abs : t -> t
    val aors : (Z.Int32.t -> Z.Int32.t -> Z.Int32.t) -> t -> t -> t
    val add : t -> t -> t
    val sub : t -> t -> t
    val mul : t -> t -> t
    val inv : t -> t
    val div : t -> t -> t
    val mul_2exp : t -> int -> t
    val div_2exp : t -> int -> t
    val ( ~- ) : t -> t
    val ( ~+ ) : 'a -> 'a
    val ( + ) : t -> t -> t
    val ( - ) : t -> t -> t
    val ( * ) : t -> t -> t
    val ( / ) : t -> t -> t
    val ( lsl ) : t -> int -> t
    val ( asr ) : t -> int -> t
    val ( ~$ ) : int -> t
    val ( // ) : int -> int -> t
    val ( ~$$ ) : Z.Int32.t -> t
    val ( /// ) : Z.Int32.t -> Z.Int32.t -> t
    val ( = ) : t -> t -> bool
    val ( < ) : t -> t -> bool
    val ( > ) : t -> t -> bool
    val ( <= ) : t -> t -> bool
    val ( >= ) : t -> t -> bool
    val ( <> ) : t -> t -> bool
  end
end
module QInt64 : sig
  module M : sig
    type t = Q(Z.Int64).t = { num : Z.Int64.t; den : Z.Int64.t; }
    val mk : Z.Int64.t -> Z.Int64.t -> t
    val make_real : Z.Int64.t -> Z.Int64.t -> t
    val make : Z.Int64.t -> Z.Int64.t -> t
    val of_bigint : Bigint.t -> t
    val of_int : int -> t
    val of_int32 : Int32.t -> t
    val of_int64 : Int64.t -> t
    val of_ints : int -> int -> t
    val zero : t
    val one : t
    val minus_one : t
    val inf : t
    val minus_inf : t
    val undef : t
    val of_float : float -> t
    val of_string : string -> t
    type kind = Q(Z.Int64).kind = ZERO | INF | MINF | UNDEF | NZERO
    val classify : t -> kind
    val is_real : t -> bool
    val num : t -> Z.Int64.t
    val den : t -> Z.Int64.t
    val sign : t -> int
    val equal : t -> t -> bool
    val compare : t -> t -> int
    val min : t -> t -> t
    val max : t -> t -> t
    val leq : t -> t -> bool
    val geq : t -> t -> bool
    val lt : t -> t -> bool
    val gt : t -> t -> bool
    val to_string : t -> string
    val to_bigint: t -> Bigint.t
    val to_int : t -> int
    val to_int32 : t -> int32
    val to_int64 : t -> int64
    val to_float : t -> float
    val neg : t -> t
    val abs : t -> t
    val aors : (Z.Int64.t -> Z.Int64.t -> Z.Int64.t) -> t -> t -> t
    val add : t -> t -> t
    val sub : t -> t -> t
    val mul : t -> t -> t
    val inv : t -> t
    val div : t -> t -> t
    val mul_2exp : t -> int -> t
    val div_2exp : t -> int -> t
    val ( ~- ) : t -> t
    val ( ~+ ) : 'a -> 'a
    val ( + ) : t -> t -> t
    val ( - ) : t -> t -> t
    val ( * ) : t -> t -> t
    val ( / ) : t -> t -> t
    val ( lsl ) : t -> int -> t
    val ( asr ) : t -> int -> t
    val ( ~$ ) : int -> t
    val ( // ) : int -> int -> t
    val ( ~$$ ) : Z.Int64.t -> t
    val ( /// ) : Z.Int64.t -> Z.Int64.t -> t
    val ( = ) : t -> t -> bool
    val ( < ) : t -> t -> bool
    val ( > ) : t -> t -> bool
    val ( <= ) : t -> t -> bool
    val ( >= ) : t -> t -> bool
    val ( <> ) : t -> t -> bool
  end
end
module QBigint : sig
  module M : sig
    type t =
           Q(Z.Bigint).t = {
        num : Z.Bigint.t;
        den : Z.Bigint.t;
      }
    val mk : Z.Bigint.t -> Z.Bigint.t -> t
    val make_real : Z.Bigint.t -> Z.Bigint.t -> t
    val make : Z.Bigint.t -> Z.Bigint.t -> t
    val of_bigint : Bigint.t -> t
    val of_int : int -> t
    val of_int32 : Int32.t -> t
    val of_int64 : Int64.t -> t
    val of_ints : int -> int -> t
    val zero : t
    val one : t
    val minus_one : t
    val inf : t
    val minus_inf : t
    val undef : t
    val of_float : float -> t
    val of_string : string -> t
    type kind = Q(Z.Bigint).kind = ZERO | INF | MINF | UNDEF | NZERO
    val classify : t -> kind
    val is_real : t -> bool
    val num : t -> Z.Bigint.t
    val den : t -> Z.Bigint.t
    val sign : t -> int
    val equal : t -> t -> bool
    val compare : t -> t -> int
    val min : t -> t -> t
    val max : t -> t -> t
    val leq : t -> t -> bool
    val geq : t -> t -> bool
    val lt : t -> t -> bool
    val gt : t -> t -> bool
    val to_string : t -> string
    val to_bigint: t -> Bigint.t
    val to_int : t -> int
    val to_int32 : t -> int32
    val to_int64 : t -> int64
    val to_float : t -> float
    val neg : t -> t
    val abs : t -> t
    val aors : (Z.Bigint.t -> Z.Bigint.t -> Z.Bigint.t) -> t -> t -> t
    val add : t -> t -> t
    val sub : t -> t -> t
    val mul : t -> t -> t
    val inv : t -> t
    val div : t -> t -> t
    val mul_2exp : t -> int -> t
    val div_2exp : t -> int -> t
    val ( ~- ) : t -> t
    val ( ~+ ) : 'a -> 'a
    val ( + ) : t -> t -> t
    val ( - ) : t -> t -> t
    val ( * ) : t -> t -> t
    val ( / ) : t -> t -> t
    val ( lsl ) : t -> int -> t
    val ( asr ) : t -> int -> t
    val ( ~$ ) : int -> t
    val ( // ) : int -> int -> t
    val ( ~$$ ) : Z.Bigint.t -> t
    val ( /// ) : Z.Bigint.t -> Z.Bigint.t -> t
    val ( = ) : t -> t -> bool
    val ( < ) : t -> t -> bool
    val ( > ) : t -> t -> bool
    val ( <= ) : t -> t -> bool
    val ( >= ) : t -> t -> bool
    val ( <> ) : t -> t -> bool
  end
end
