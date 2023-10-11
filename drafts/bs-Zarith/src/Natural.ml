(* 
 * Module:     Natural
 * Copyright:  Plow Technologies, 2020
 * Maintainer: james.haver@plowtech.net 
 *
 * Support arbitrary precision Natural numbers in OCaml.
 *)

exception Underflow
exception DecodeError

type t = Natural of Bigint.t

let zero = Natural Bigint.zero
let one = Natural Bigint.one

(* of conversion *)

let ofInt x =
  let r = Bigint.of_int x in
  if Bigint.lt r Bigint.zero
  then None
  else Some (Natural r)

let ofInt32 x =
  let r = Bigint.of_int32 x in
  if Bigint.lt r Bigint.zero
  then None
  else Some (Natural r)

let ofInt64 x =
  let r = Bigint.of_int64 x in
  if Bigint.lt r Bigint.zero
  then None
  else Some (Natural r)

let ofFloat x =
  let r = Bigint.of_float x in
  if Bigint.lt r Bigint.zero
  then None
  else Some (Natural r)
  
let ofString x =
  let r = Bigint.of_string_opt x in
  match r with
  | None -> None
  | Some r ->
     if Bigint.lt r Bigint.zero
     then None
     else Some (Natural r)

let unsafeOfInt x =
  match ofInt x with
  | Some x -> x
  | None -> raise Underflow

let unsafeOfInt32 x =
  match ofInt32 x with
  | Some x -> x
  | None -> raise Underflow

let unsafeOfInt64 x =
  match ofInt64 x with
  | Some x -> x
  | None -> raise Underflow

let unsafeOfFloat x =
  match ofFloat x with
  | Some x -> x
  | None -> raise Underflow

let unsafeOfString x =
  match ofString x with
  | Some x -> x
  | None -> raise DecodeError
          
(* to conversion *)

let toInt x =
  match x with
  | Natural x -> Bigint.to_int x

let toInt32 x =
  match x with
  | Natural x -> Bigint.to_int32 x

let toInt64 x =
  match x with
  | Natural x -> Bigint.to_int64 x

let toFloat x =
  match x with
  | Natural x -> Bigint.to_float x

let toString x =
  match x with
  | Natural x -> Bigint.to_string x
               
(* Arithmetic *)        
let succ x =
  match x with
  | Natural x -> Natural (Bigint.add x Bigint.one)

let pred x =
  match x with
  | Natural x ->
     let r = Bigint.sub x Bigint.one in
     if Bigint.lt r Bigint.zero
     then raise Underflow
     else Natural r

let predSafe x =
  match pred x with
  | x -> Some x
  | exception Underflow -> None
     
let add x y =
  match (x,y) with
  | (Natural x, Natural y) -> Natural (Bigint.add x y)

let sub x y =
  match (x,y) with
  | (Natural x, Natural y) ->
     let r = Bigint.sub x y in
     if Bigint.lt r Bigint.zero
     then raise Underflow
     else Natural r

let subSafe x y =
  match sub x y with
  | r -> Some r
  | exception Underflow -> None
     
let mul x y =
  match (x,y) with
  | (Natural x, Natural y) -> Natural (Bigint.mul x y)

let div x y =
  match (x,y) with
  | (Natural x, Natural y) -> Natural (Bigint.div x y)

let rem x y =
  match (x,y) with
  | (Natural x, Natural y) -> Natural (Bigint.rem x y)

let divRem x y =
  match (x,y) with
  | (Natural x, Natural y) ->
     let (r1,r2) = (Bigint.div_rem x y) in
     (Natural r1, Natural r2)
                            
let cdiv x y =
  match (x,y) with
  | (Natural x, Natural y) -> Natural (Bigint.cdiv x y)

let fdiv x y =
  match (x,y) with
  | (Natural x, Natural y) -> Natural (Bigint.fdiv x y)
                            
let edivRem x y =
  match (x,y) with
  | (Natural x, Natural y) ->
     let (r1,r2) = (Bigint.ediv_rem x y) in
     (Natural r1, Natural r2)

let ediv x y =
  match (x,y) with
  | (Natural x, Natural y) -> Natural (Bigint.ediv x y)

let erem x y =
  match (x,y) with
  | (Natural x, Natural y) -> Natural (Bigint.erem x y)

let divexact x y =
  match (x,y) with
  | (Natural x, Natural y) -> Natural (Bigint.divexact x y)
