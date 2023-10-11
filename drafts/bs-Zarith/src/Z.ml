module type Z = sig
  exception Overflow
  (** Raised by conversion functions when the value cannot be represented in
    the destination type.
   *)

  type t
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

  val of_bigint: Bigint.t -> t
  (** Converts from an arbitrary length integer. *)
    
  val of_float: float -> t
  (** Converts a float to an integer. *)

  val of_string: string -> t
  (** Converts a string to an integer.
    An optional [-] prefix indicates a negative number.
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

  val to_bigint: t -> Bigint.t
  (** Converts to an arbitrary length integer. May raise [Overflow]. *)
    
  val to_float: t -> float
  (** Converts to a floating-point value.
    This function rounds the given integer according to the current
    rounding mode of the processor.  In default mode, it returns
    the floating-point number nearest to the given integer,
    breaking ties by rounding to even. *)

  val round_to_float: t -> bool -> float

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

  (** {1 Powers} *)

  val pow: t -> int -> t
  (** [pow base exp] raises [base] to the [exp] power.
    [exp] must be non-negative.
    Note that only exponents fitting in a machine integer are supported, as
    larger exponents would surely make the result's size overflow the
    address space.
    Raises an [Invalid_argument] on negative [exp].    
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
end


module ZInt : Z = struct
  exception Overflow
  type t = int

  (** Construction *)
  let zero = 0
  let one = 1
  let minus_one = -1

  let of_int x = x
  let of_int32 = Int32.to_int
  let of_int64 = Int64.to_int
  let of_bigint = Bigint.to_int                 
  let of_float = int_of_float
  let of_string = int_of_string
  let of_substring s ~pos ~len = int_of_string (String.sub s pos len)

  (** Basic arithmetic operations *)
  let succ x = x + 1 
  let pred x = x - 1

  let abs = abs
  let neg = (~-)
  let add x y = x + y
  let sub x y = x - y
  let mul x y = x * y

  let div x y = x / y
  let rem x y = x mod y
  let div_rem a b = (a / b, rem a b)

  let sign n =
    if n == 0
    then 0
    else
      if n < 0
      then -1
      else 1

  let rec ediv_rem' a b cum =
    let a = abs a in
    let b = abs b in
    let r = sub a b in
    if (compare a b) = 1
    then ediv_rem' r b (succ cum)
    else (succ cum, r)

  let ediv_rem a b =
    if a > -1
    then div_rem a b
    else
      let q,r = ediv_rem' a b zero in
      (neg q, abs r)

  let ediv a b =
    let quotient, _ = ediv_rem a b
    in quotient

  let erem a b =
    let _, remainder = ediv_rem a b
    in remainder

  let divexact = div

  (** Bit-level operations *)
  let logand x y = x land y
  let logor x y = x lor y
  let logxor x y = x lxor y
  let lognot x = lnot x
  let shift_left = (lsl)
  let shift_right = (asr)

  let numbits n =
    let nref  = ref n in
    let count = ref 0 in
    while (!nref > !count) do
      if (!nref land !count == 1)
      then (count := !count + 1)
      else (nref := !nref lsr 1)
    done;
    !count
    
  (** Conversions *)
  let to_int x = x
  let to_int32 = Int32.of_int
  let to_int64 = Int64.of_int
  let to_bigint = Bigint.of_int
  let to_float = float_of_int
  let round_to_float x exact =
    let m = to_int64 x in
    (* Unless the fractional part is exactly 0, round m to an odd integer *)
    let m = if exact then m else Int64.logor m 1L in
    (* Then convert m to float, with the current rounding mode. *)
    Int64.to_float m
  let to_string = string_of_int

  (** Ordering *)
  let compare = compare
  let equal x y = x = y
  let leq x y = x <= y
  let geq x y = x >= y
  let lt x y = x < y
  let gt x y = x > y
  let sign = sign

  let cdiv a b =
    let quotient, remainder = div_rem a b in
    if gt remainder zero then (add quotient one) else quotient

  let fdiv a b =
    let quotient, remainder = div_rem a b in
    if lt remainder zero then (sub quotient one) else quotient           

  let min = min
  let max = max
  let is_even i = (i mod 2) = 0
  let is_odd i = (i mod 2) <> 0
  (* val hash: t -> int *)

  let rec gcd' a b =
    let c = erem a b
    in if c = zero
       then b
       else gcd' b c

  let gcd x y = gcd' x y

  (** Powers *)
  let rec pow' base exp acc =
    if exp <= 0
    then acc
    else (pow' base (exp - 1) (mul acc base))

  let pow base exp = 
    if exp < 0
    then raise (Invalid_argument "The exponent must be greater zero or greater.")
    else if exp = 0
    then one
    else if exp = 1
    then base
    else pow' base exp one

  (** Prefix and infix operators *)
  let (~-) = neg
  let (~+) x = x
  let (+)  = add
  let (-) = sub
  let ( * ) = mul
  let (/) = div
  let (/>) = cdiv
  let (/<) = fdiv
  let (/|) = div
  let (mod) = (rem)
  let (land) = (land)
  let (lor) = (lor)
  let (lxor) = (lxor)
  let (~!) x = lnot x
  let (lsl) = (lsl)
  let (asr) = (asr)
  let (~$) = of_int
  let ( ** ) a b = pow a b
  let (=) = equal
  let (<) = (<)
  let (>) = (>)
  let (<=) = (<=)
  let (>=) = (>=)
  let (<>) a b = not (equal a b)
end

module ZInt32 : Z = struct
  exception Overflow
  type t = Int32.t

  (** Construction *)
  let zero = Int32.zero
  let one = Int32.one
  let two = Int32.of_int 2
  let minus_one = Int32.minus_one

  let of_int = Int32.of_int
  let of_int32 x = x
  let of_int64 = Int64.to_int32
  let of_bigint = Bigint.to_int32
  let of_float = Int32.of_float
  let of_string = Int32.of_string
  let of_substring s ~pos ~len = Int32.of_string (String.sub s pos len)

  (** Basic arithmetic operations *)
  let succ x = Int32.add x one 
  let pred x = Int32.sub x one

  let abs = Int32.abs
  let neg = Int32.neg
  let add = Int32.add
  let sub = Int32.sub
  let mul = Int32.mul

  let (mod) a n = Int32.sub a (Int32.mul n (Int32.div a n))
  let div = Int32.div
  let rem x y = x mod y
  let div_rem a b = (div a b, rem a b)

  let sign n =
    if n == (Int32.of_int 0)
    then 0
    else
      if (Int32.compare n (Int32.of_int 0)) < 0
      then -1
      else 1

  let rec ediv_rem' a b cum =
    let a = abs a in
    let b = abs b in
    let r = sub a b in
    if (compare a b) = 1
    then ediv_rem' r b (succ cum)
    else (succ cum, r)

  let gt x y = (Int32.compare x y) > 0

  let ediv_rem a b =
    if (gt a minus_one)
    then div_rem a b
    else
      let q,r = ediv_rem' a b zero in
      (neg q, abs r)

  let ediv a b =
    let quotient, _ = ediv_rem a b
    in quotient

  let erem a b =
    let _, remainder = ediv_rem a b
    in remainder

  let divexact = div

  (** Bit-level operations *)
  let logand = Int32.logand
  let logor = Int32.logor
  let logxor = Int32.logxor
  let lognot = Int32.lognot
  let shift_left = Int32.shift_left
  let shift_right = Int32.shift_right

  let numbits n =
    let nref  = ref n in
    let count = ref zero in
    while (!nref > !count) do
      if (Int32.logand !nref !count == one)
      then (count := Int32.add !count one)
      else (nref := Int32.shift_right_logical !nref 1)
    done;
    Int32.to_int !count

  (** Conversions *)
  let to_int = Int32.to_int
  let to_int32 x = x
  let to_int64 = Int64.of_int32
  let to_bigint = Bigint.of_int32
  let to_float x = Int64.to_float (Int64.of_int32 x) (* there is strange parameter required with Int32.to_float that doesn't seem to match the offical OCaml API, so this is an easy work around *)
  let round_to_float x exact =
    let m = to_int64 x in
    (* Unless the fractional part is exactly 0, round m to an odd integer *)
    let m = if exact then m else Int64.logor m 1L in
    (* Then convert m to float, with the current rounding mode. *)
    Int64.to_float m
  let to_string = Int32.to_string

  (** Ordering *)
  let compare = Int32.compare
  let equal x y = x == y
  let leq x y = (compare x y) < 1
  let geq x y = (compare x y) > -1
  let lt x y = (compare x y) < 0

  let sign = sign

  let min x y =
    if leq x y then x else y

  let max x y =
    if geq x y then x else y

  let cdiv a b =
    let quotient, remainder = div_rem a b in
    if gt remainder zero then (add quotient one) else quotient

  let fdiv a b =
    let quotient, remainder = div_rem a b in
    if lt remainder zero then (sub quotient one) else quotient
    
  let is_even i = (i mod two) = zero
  let is_odd i = (i mod two) <> zero

  let rec gcd' a b =
    let c = erem a b
    in if c = zero
       then b
       else gcd' b c

  let gcd x y = gcd' x y

  (** Powers *)
  let rec pow' base exp acc =
    if exp <= 0
    then acc
    else (pow' base (exp - 1) (mul acc base))

  let pow base exp = 
    if exp < 0
    then raise (Invalid_argument "The exponent must be greater zero or greater.")
    else if exp = 0
    then one
    else if exp = 1
    then base
    else pow' base exp one

  (** Prefix and infix operators *)
  let (~-) = neg
  let (~+) x = x
  let (+)  = add
  let (-) = sub
  let ( * ) = mul
  let (/) = div
  let (/>) = cdiv
  let (/<) = fdiv
  let (/|) = div
  (* (mod): t -> t -> t *)
  let (land) = logand
  let (lor) = logor
  let (lxor) = logxor
  let (~!) = lognot
  let (lsl) = (shift_left)
  let (asr) = (shift_right)
  let (~$) = of_int
  let ( ** ) a b = pow a b
  let (=) = equal
  let (<) = (<)
  let (>) = (>)
  let (<=) = (<=)
  let (>=) = (>=)
  let (<>) a b = not (equal a b)
end

module ZInt64 : Z = struct
  exception Overflow
  type t = Int64.t

  (** Construction *)
  let zero = Int64.zero
  let one = Int64.one
  let two = Int64.of_int 2
  let minus_one = Int64.minus_one

  let of_int = Int64.of_int
  let of_int32 = Int64.of_int32
  let of_int64 x = x
  let of_bigint = Bigint.to_int64
  let of_float = Int64.of_float
  let of_string = Int64.of_string
  let of_substring s ~pos ~len = Int64.of_string (String.sub s pos len)

  (** Basic arithmetic operations *)
  let succ x = Int64.add x one 
  let pred x = Int64.sub x one

  let abs = Int64.abs
  let neg = Int64.neg
  let add = Int64.add
  let sub = Int64.sub
  let mul = Int64.mul

  let (mod) a n = Int64.sub a (Int64.mul n (Int64.div a n))
  let div = Int64.div
  let rem x y = x mod y
  let div_rem a b = (div a b, rem a b)

  let sign n =
    if n == (Int64.of_int 0)
    then 0
    else
      if (Int64.compare n (Int64.of_int 0)) < 0
      then -1
      else 1

  let rec ediv_rem' a b cum =
    let a = abs a in
    let b = abs b in
    let r = sub a b in
    if (compare a b) = 1
    then ediv_rem' r b (succ cum)
    else (succ cum, r)

  let gt x y = (Int64.compare x y) > 0

  let ediv_rem a b =
    if (gt a minus_one)
    then div_rem a b
    else
      let q,r = ediv_rem' a b zero in
      (neg q, abs r)

  let ediv a b =
    let quotient, _ = ediv_rem a b
    in quotient

  let erem a b =
    let _, remainder = ediv_rem a b
    in remainder

  let divexact = div

  (** Bit-level operations *)
  let logand = Int64.logand
  let logor = Int64.logor
  let logxor = Int64.logxor
  let lognot = Int64.lognot
  let shift_left = Int64.shift_left
  let shift_right = Int64.shift_right

  let numbits n =
    let nref  = ref n in
    let count = ref zero in
    while (!nref > !count) do
      if (Int64.logand !nref !count == one)
      then (count := Int64.add !count one)
      else (nref := Int64.shift_right_logical !nref 1)
    done;
    Int64.to_int !count

  (** Conversions *)
  let to_int = Int64.to_int
  let to_int32 = Int64.to_int32
  let to_int64 x = x
  let to_bigint = Bigint.of_int64
  let to_float = Int64.to_float
  let round_to_float x exact =
    (* Unless the fractional part is exactly 0, round m to an odd integer *)
    let m = if exact then x else Int64.logor x 1L in
    (* Then convert m to float, with the current rounding mode. *)
    Int64.to_float m
  let to_string = Int64.to_string

  (** Ordering *)
  let compare = Int64.compare
  let equal x y = x == y
  let leq x y = (compare x y) < 1
  let geq x y = (compare x y) > -1
  let lt x y = (compare x y) < 0
  (* let gt x y = (Int64.compare x y) > 0 *)
  let sign = sign
  let min x y =
    if leq x y then x else y

  let max x y =
    if geq x y then x else y

  let cdiv a b =
    let quotient, remainder = div_rem a b in
    if gt remainder zero then (add quotient one) else quotient

  let fdiv a b =
    let quotient, remainder = div_rem a b in
    if lt remainder zero then (sub quotient one) else quotient
    
  let is_even i = (i mod two) = zero
  let is_odd i = (i mod two) <> zero

  let rec gcd' a b =
    let c = erem a b
    in if c = zero
       then b
       else gcd' b c

  let gcd x y = gcd' x y

  (** Powers *)
  let rec pow' base exp acc =
    if exp <= 0
    then acc
    else (pow' base (exp - 1) (mul acc base))

  let pow base exp = 
    if exp < 0
    then raise (Invalid_argument "The exponent must be greater zero or greater.")
    else if exp = 0
    then one
    else if exp = 1
    then base
    else pow' base exp one

  (** Prefix and infix operators *)
  let (~-) = neg
  let (~+) x = x
  let (+)  = add
  let (-) = sub
  let ( * ) = mul
  let (/) = div
  let (/>) = cdiv
  let (/<) = fdiv
  let (/|) = div
  let (land) = logand
  let (lor) = logor
  let (lxor) = logxor
  let (~!) = lognot
  let (lsl) = (shift_left)
  let (asr) = (shift_right)
  let (~$) = of_int
  let ( ** ) a b = pow a b
  let (=) = equal
  let (<) = (<)
  let (>) = (>)
  let (<=) = (<=)
  let (>=) = (>=)
  let (<>) a b = not (equal a b)
end

module ZBigint : Z = struct
  exception Overflow
  type t = Bigint.t

  (** Construction *)
  let zero = Bigint.zero
  let one = Bigint.one
  let minus_one = Bigint.minus_one

  let of_int = Bigint.of_int
  let of_int32 = Bigint.of_int32
  let of_int64 = Bigint.of_int64
  let of_bigint x = x
  let of_float = Bigint.of_float
  let of_string = Bigint.of_string
  let of_substring = Bigint.of_substring

  (** Basic arithmetic operations *)
  let succ = Bigint.succ
  let pred = Bigint.pred

  let abs = Bigint.abs
  let neg = Bigint.neg
  let add = Bigint.add
  let sub = Bigint.sub
  let mul = Bigint.mul

  let div = Bigint.div
  let rem = Bigint.rem
  let div_rem = Bigint.div_rem

  let ediv_rem = Bigint.ediv_rem

  let ediv = Bigint.ediv

  let erem = Bigint.erem

  let cdiv = Bigint.cdiv
  let fdiv = Bigint.fdiv

  let divexact = div

  (** Bit-level operations *)
  let logand = Bigint.logand
  let logor = Bigint.logor
  let logxor = Bigint.logxor
  let lognot = Bigint.lognot
  let shift_left = Bigint.shift_left
  let shift_right = Bigint.shift_right

  let numbits = Bigint.numbits

  (** Conversions *)
  let to_int = Bigint.to_int
  let to_int32 = Bigint.to_int32
  let to_int64 = Bigint.to_int64
  let to_bigint x = x
  let to_float = Bigint.to_float
  let round_to_float = Bigint.round_to_float
  let to_string = Bigint.to_string

  (** Ordering *)
  let compare = Bigint.compare
  let equal = Bigint.equal
  let leq = Bigint.leq
  let geq = Bigint.geq
  let lt = Bigint.lt
  let gt = Bigint.gt
  let sign = Bigint.sign
  let min = Bigint.min
  let max = Bigint.max

  let is_even = Bigint.is_even
  let is_odd = Bigint.is_odd

  let gcd = Bigint.gcd

  (** Powers *)
  let pow = Bigint.pow

  (** Prefix and infix operators *)
  let (~-) = neg
  let (~+) x = x
  let (+)  = add
  let (-) = sub
  let ( * ) = mul
  let (/) = div
  let (/>) = cdiv
  let (/<) = fdiv
  let (/|) = div
  let (mod) = (rem)
  let (land) = logand
  let (lor) = logor
  let (lxor) = logxor
  let (~!) = (lognot)
  let (lsl) = (shift_left)
  let (asr) = (shift_right)
  let (~$) = of_int
  let ( ** ) a b = pow a b
  let (=) = equal
  let (<) = (<)
  let (>) = (>)
  let (<=) = (<=)
  let (>=) = (>=)
  let (<>) a b = not (equal a b)
end

module Int       = ZInt
module Int32     = ZInt32
module Int64     = ZInt64
module Bigint    = ZBigint
