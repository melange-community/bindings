(* 
 * Module:     U
 * Copyright:  Plow Technologies, 2020
 * Maintainer: james.haver@plowtech.net 
 *
 * Support unsigned integers in OCaml.
 *)

module type Basics = sig
  type t

  val add : t -> t -> t
  val sub : t -> t -> t
  val mul : t -> t -> t
  val div : t -> t -> t
  val rem : t -> t -> t
  val maxInt : t
  val logand : t -> t -> t
  val logor : t -> t -> t
  val logxor : t -> t -> t
  val shiftLeft : t -> int -> t
  val shiftRight : t -> int -> t
  val ofInt : int -> t
  val toInt : t -> int
  val ofInt64 : int64 -> t
  val toInt64 : t -> int64
  val ofString : string -> t option
  val toString : t -> string
end


module type Extras = sig
  type t

  val zero : t
  val one : t
  val lognot : t -> t
  val succ : t -> t
  val pred : t -> t
  val compare : t -> t -> int
  val equal : t -> t -> bool
  val max : t -> t -> t
  val min : t -> t -> t
end


module type Infix = sig
  type t
  val (+) : t -> t -> t
  val (-) : t -> t -> t
  val ( * ) : t -> t -> t
  val (/) : t -> t -> t
  val (mod) : t -> t -> t
  val (land) : t -> t -> t
  val (lor) : t -> t -> t
  val (lxor) : t -> t -> t
  val (lsl) : t -> int -> t
  val (lsr) : t -> int -> t
end


module type S = sig
  include Basics
  include Extras with type t := t

  module Infix : Infix with type t := t
end


module MakeInfix (B : Basics) =
struct
  open B
  let (+) = add
  let (-) = sub
  let ( * ) = mul
  let (/) = div
  let (mod) = rem
  let (land) = logand
  let (lor) = logor
  let (lxor) = logxor
  let (lsl) = shiftLeft
  let (lsr) = shiftRight
end


module Extras(Basics : Basics) : Extras with type t := Basics.t =
struct
  open Basics
  let zero = ofInt 0
  let one = ofInt 1
  let succ n = add n one
  let pred n = sub n one
  let lognot n = logxor n maxInt
  let compare (x : t) (y : t) = Pervasives.compare x y
  let equal (x : t) (y : t) = Pervasives.(=) x y
  let max (x : t) (y : t) = Pervasives.max x y
  let min (x : t) (y : t) = Pervasives.min x y
end


module UInt8 : S with type t = private int =
struct
  module B =
  struct
    type t = int
    let maxInt = 255
    let add : t -> t -> t = fun x y -> (x + y) land maxInt
    let sub : t -> t -> t = fun x y -> (x - y) land maxInt
    let mul : t -> t -> t = fun x y -> (x * y) land maxInt
    let div : t -> t -> t = (/)
    let rem : t -> t -> t = (mod)
    let logand: t -> t -> t = (land)
    let logor: t -> t -> t = (lor)
    let logxor : t -> t -> t = (lxor)
    let shiftLeft : t -> int -> t = fun x y -> (x lsl y) land maxInt
    let shiftRight : t -> int -> t = (lsr)
    let ofInt (x: int): t = x land maxInt
    let toInt : t -> int = fun x -> x
    let ofInt64 : int64 -> t = fun x -> ofInt (Int64.to_int x)
    let toInt64 : t -> int64 = fun x -> Int64.of_int (toInt x)
    let ofString : string -> t option = fun x ->
      match Belt.Int.fromString x with
      | Some x -> Some (ofInt x)
      | None   -> None
                                                  
    let toString : t -> string = string_of_int
  end
  include B
  include Extras(B)
  module Infix = MakeInfix(B)
end


module UInt16 : S with type t = private int =
struct
  module B =
  struct
    type t = int
    let maxInt = 65535
    let add : t -> t -> t = fun x y -> (x + y) land maxInt
    let sub : t -> t -> t = fun x y -> (x - y) land maxInt
    let mul : t -> t -> t = fun x y -> (x * y) land maxInt
    let div : t -> t -> t = (/)
    let rem : t -> t -> t = (mod)
    let logand: t -> t -> t = (land)
    let logor: t -> t -> t = (lor)
    let logxor : t -> t -> t = (lxor)
    let shiftLeft : t -> int -> t = fun x y -> (x lsl y) land maxInt
    let shiftRight : t -> int -> t = (lsr)
    let ofInt (x: int): t = x land maxInt
    let toInt : t -> int = fun x -> x
    let ofInt64 : int64 -> t = fun x -> Int64.to_int x |> ofInt
    let toInt64 : t -> int64 = fun x -> toInt x |> Int64.of_int
    let ofString : string -> t option = fun x ->
      match Belt.Int.fromString x with
      | Some x -> Some (ofInt x)
      | None   -> None
    let toString : t -> string = string_of_int
  end
  include B
  include Extras(B)
  module Infix = MakeInfix(B)
end
  
module UInt32 : S with type t = Int64.t =
struct
  module B =
  struct
    type t = Int64.t
    let maxInt = Int64.of_string("4294967295")
    let logand: t -> t -> t = (Int64.logand)               
    let add : t -> t -> t = fun x y -> logand (Int64.add x y) maxInt
    let sub : t -> t -> t = fun x y -> logand (Int64.sub x y) maxInt
    let mul : t -> t -> t = fun x y -> logand (Int64.mul x y) maxInt
    let div : t -> t -> t = fun x y -> logand (Int64.div x y) maxInt
    let rem : t -> t -> t = fun x y -> Int64.sub x (Int64.mul y (Int64.div x y))
    let logor: t -> t -> t = (Int64.logor)
    let logxor : t -> t -> t = (Int64.logxor)
    let shiftLeft = Int64.shift_left
    let shiftRight = Int64.shift_right
    let ofInt (x: int): t = logand (Int64.of_int x) maxInt
    let toInt : t -> int = fun x -> Int64.to_int x
    let ofInt64 : int64 -> t = fun x -> Int64.to_int x |> ofInt
    let toInt64 : t -> int64 = fun x -> toInt x |> Int64.of_int
    let ofString : string -> t option = fun x ->
      match Belt.Int.fromString x with
      | Some x -> Some (ofInt x)
      | None   -> None
    let toString : t -> string = Int64.to_string
  end
  include B
  include Extras(B)
  module Infix = MakeInfix(B)
end

module UInt64 : S with type t = Bigint.t =
struct
  module B =
  struct
    type t = Bigint.t
    let maxInt = Bigint.of_string("18446744073709551616")
    let rem : t -> t -> t = fun x y -> Bigint.sub x (Bigint.mul y (Bigint.div x y))               
    let reduce : t -> t = fun x ->
      if Bigint.lt x Bigint.zero
      then
        ( let r = Bigint.rem x maxInt in
          Bigint.add maxInt (Bigint.add r Bigint.one)
        )
      else if Bigint.gt x maxInt
      then
        (
          Bigint.sub (Bigint.rem x maxInt) Bigint.one
        )
      else x
      
    let logand: t -> t -> t = (Bigint.logand)               
    let add : t -> t -> t = fun x y -> reduce (Bigint.add x y)
    let sub : t -> t -> t = fun x y -> reduce (Bigint.sub x y)
    let mul : t -> t -> t = fun x y -> reduce (Bigint.mul x y)
    let div : t -> t -> t = fun x y -> reduce (Bigint.div x y)

    let logor: t -> t -> t = (Bigint.logor)
    let logxor : t -> t -> t = (Bigint.logxor)
    let shiftLeft = Bigint.shift_left
    let shiftRight = Bigint.shift_right
    let ofInt (x: int): t = reduce (Bigint.of_int x)
    let toInt : t -> int = fun x -> Bigint.to_int x
    let ofInt64 : int64 -> t = fun x -> Int64.to_int x |> ofInt
    let toInt64 : t -> int64 = fun x -> toInt x |> Int64.of_int
    let ofString : string -> t option = fun x ->
      match Belt.Int.fromString x with
      | Some _x -> Some (reduce (Bigint.of_string x))
      | None   -> None
    let toString : t -> string = Bigint.to_string
  end
  include B
  include Extras(B)
  module Infix = MakeInfix(B)
end
