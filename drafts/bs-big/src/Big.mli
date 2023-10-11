(**The abstract type representing a big number *)
type t

exception Unknown_error

exception Div_by_zero

exception Invalid_number

exception Invalid_decimal_places

exception Invalid_rounding_mode

exception No_square_root

exception Invalid_precision

(**[fromString x] Returns a big number with [x] interpreted as a decimal.

   Raises [Invalid_number] if the string is not a valid number
*)
val fromString: string -> t

(**[fromFloat x] Returns a big number with value [x] *)
val fromFloat: float -> t

(**[fromInt x] Returns a big number with value [x] *)
val fromInt: int -> t

(**[setDP x] Sets the maximum number of decimal places of the results of
   operations involving division to [x]. It is only used by [div], [sqrt], and
   [pow]

   Raises [Invalid_decimal_places] if [x] is negative*)
val setDP: int -> unit

(**[setRM x] Sets the rounding mode used in the above operations and by [round],
   [toExponential], [toFixed] and [toPrecision] to [x]. 0 rounds down, 1 rounds
   half up, 2 rounds half even, and 3 rounds away from 0

   Raises [Invalid_rounding_mode] if [x] is not one of 0,1,2 or 3
   *)
val setRM: int -> unit

(**[setRM x] Sets the negative exponent value at and below which toString returns exponential
   notation to [x]. *)
val setNE: int -> unit

(**[setPE x] Sets the positive exponent at which [toString] returns exponential notation
   to [x]. *)
val setPE: int -> unit

(**Returns the current value of DP.

   Default: 20*)
val getDP: unit -> int

(**Returns the current value of RM.

   Default: 1*)
val getRM: unit -> int

(**Returns the current value of NE.

   Default: -7*)
val getNE: unit -> int

(**Returns the current value of PE.

   Default: 21*)
val getPE: unit -> int

(**[abs x] Returns the absolute value of [x] as a Big number. *)
val abs: t -> t

(**[cmp x y] Returns 1 if [x] > [y], -1 if [x] < [y], and 0 if [x] = [y]*)
val cmp: t -> t -> int

(**[div x y] Returns the Big number represented by x/y.

   Raises [Div_by_zero] if [y] is 0.
*)
val div: t -> t -> t

(**[eq x y] Returns true if the value of x is equal to the value of y. *)
val eq: t -> t -> bool

(**[gt x y] Returns true if the value of x is greater than the value of y. *)
val gt: t -> t -> bool

(**[gte x y] Returns true if the value of x is greater than or equal to the value of y. *)
val gte: t -> t -> bool

(**[lt x y] Returns true if the value of x is less than the value of y. *)
val lt: t -> t -> bool

(**[lte x y] Returns true if the value of x is less than or equal to the value of y. *)
val lte: t -> t -> bool

(**[minus x y] Returns the value of x-y. *)
val minus: t -> t -> t

(**[mod_ x y] Returns [x] modulo [n]. *)
val mod_: t -> t -> t

(**[plus x y] Returns the value of x + y. *)
val plus: t -> t -> t

(**[pow x n] Returns [x] to the power [n]. *)
val pow: t -> int -> t

(**[round x dp rm ()] returns the value [x] with a maximum of [dp] decimal places
   if provided, rounded using rounding mode [rm].

   If [dp] is ommitted, will round to a whole number. If [rm] is ommitted, will
   use rounding mode RM.
   *)
val round: t -> ?dp:int -> ?rm:int -> unit -> t

(**[sqrt x] Returns the square root of x.

   Raises [No_square_root] if the root of x would be imaginary.
*)
val sqrt: t -> t

(**[times x y] Returns the value of x*y *)
val times: t -> t -> t

(**[toExponential x dp ()] Returns a string representing [x] in exponential notation
   to a fixed number of [dp] decimal places.

   If [dp] is ommitted, defaults to the number of digits needed to represent [x]
   exactly*)
val toExponential: t -> ?dp:int -> unit -> string

(**[toFixed x dp ()] Returns a string representing [x] with a fixed number of
   [dp] decimal places.

   If [dp] is ommitted, it is simply the value in normal notation.
   *)
val toFixed: t -> ?dp:int -> unit -> string

(**[toPrecision x sd ()] Returns a string representing [x] with [sd] significant
   digits.

   If [sd] is ommitted, returns the same as [toString].
   *)
val toPrecision: t -> ?sd:int -> unit -> string

(**[toString x] Returns a string representing the value of x*)
val toString: t -> string

(**[valueOf x] Same as [toString] but the sign is included for -0*)
val valueOf: t -> string

(**Same as valueOf*)
val toJson: t -> string

(**[c x] Returns the significand of [x]*)
val c: t -> int array

(**[e x] Returns the exponent of [x]*)
val e: t -> int

(**[s x] Returns the sign of [x]. Either -1 or 1.*)
val s: t -> int
