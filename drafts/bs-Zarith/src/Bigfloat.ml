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

let mkBigfloat v d = { value = v; decimalPos = d } 
       
let zero = { value = Bigint.zero; decimalPos = 0 }

let one = { value = Bigint.one; decimalPos = 0 }

let minusOne = { value = Bigint.minus_one; decimalPos = 0 }

(** Internal utility functions *)             
let rec repeatString n s = if n = 0 then "" else s ^ (repeatString (n - 1) s)

let addCommas: string -> string =
  [%bs.raw
    {|
    function (s) {
      var sp = s.split(".");
      var l = sp[0].replace(/(\d)(?=(\d\d\d)+(?!\d))/g, "$1,");
      if (sp.length > 1) {
        return l.concat(".", sp[1]);
      } else {
        return l;
      }
    }
     |}]

let removeCommas: string -> string =
  [%bs.raw
    {|
    function (s) {
      return s.replace(/,/g, "");
    }
   |}]

(** of conversions *)

let ofInt i =
  { value = (Bigint.of_int i); decimalPos = 0 }
  
let ofInt32 i =
  { value = (Bigint.of_int32 i); decimalPos = 0 }
  
let ofInt64 i =
  { value = (Bigint.of_int64 i); decimalPos = 0 }

let ofString (string : string) decimalPos =
  let s = removeCommas string in
  let a = Js.String.split "." s in
  if Array.length a = 1
  then
    Some
      { value = (Bigint.mul (Bigint.of_string s) (Bigint.pow (Bigint.of_int 10) decimalPos));
        decimalPos }
   else
     if Array.length a = 2
     then
       let leftSide = a.(0) in
       let rightSide = a.(1) in
       let rightSideLength = String.length rightSide in
       let rr =
         (if rightSideLength = decimalPos
          then rightSide
          else
            if rightSideLength < decimalPos
            then
              rightSide ^
                (repeatString (decimalPos - rightSideLength) "0")
            else
              String.sub rightSide 0 decimalPos) in
       Some { value = (Bigint.of_string (leftSide ^ rr)); decimalPos }
     else None
  
let ofFloat (f : float) decimalPos =
  (let s = Js.Float.toString f in
   let a = Js.String.split "." s in
   if (Array.length a) = 1
   then { value = (Bigint.of_float f); decimalPos }
   else
     if (Array.length a) = 2
     then
       let leftSide = a.(0) in
       let rightSide = a.(1) in
       let rightSideLength = String.length rightSide in
       let rr =
         if rightSideLength = decimalPos
         then rightSide
         else
           if rightSideLength < decimalPos
            then
             rightSide ^
               (repeatString (decimalPos - rightSideLength) "0")
           else String.sub rightSide 0 decimalPos in
       { value = (Bigint.of_string (leftSide ^ rr)); decimalPos }
     else { value = Bigint.zero; decimalPos } : t)


(** to conversions *)

let toInt t =
   Bigint.to_int (Bigint.div t.value (Bigint.pow (Bigint.of_int 10) t.decimalPos))
  
let toInt32 t =
   Bigint.to_int32 (Bigint.div t.value (Bigint.pow (Bigint.of_int 10) t.decimalPos))
  
let toInt64 t =
   Bigint.to_int64 (Bigint.div t.value (Bigint.pow (Bigint.of_int 10) t.decimalPos))
  
let toString (t : t) =
  let s = Bigint.to_string t.value in
  let sl = String.length s in
  if t.decimalPos = 0
  then s
  else
    if sl <= t.decimalPos
    then
      "0." ^ (repeatString (t.decimalPos - sl) "0") ^ s
    else
      (let r = Js.String.slice ~from:(sl - t.decimalPos) ~to_:sl s in
       let l = Js.String.slice ~from:0 ~to_:(sl - t.decimalPos) s in
       l ^ "." ^ r)

let toStringWithCommas (t : t) = (addCommas (toString t) : string)
  
let toFloat (t : t) = (float_of_string (toString t) : float)

(** Arithmetic *)

let abs t = {t with value = Bigint.abs t.value}

let neg t = {t with value = Bigint.neg t.value}
  
let add (x : t) (y : t) =
  if x.decimalPos = y.decimalPos
  then { value = (Bigint.add x.value y.value); decimalPos = (x.decimalPos) }
  else
    if x.decimalPos > y.decimalPos
    then
      (let decimalPos = x.decimalPos - y.decimalPos in
       {
         value =
           (let open Bigint in
              add x.value (mul y.value (pow (of_int 10) decimalPos)));
         decimalPos = (x.decimalPos)
       })
    else
      (let decimalPos = y.decimalPos - x.decimalPos in
       {
         value =
           (let open Bigint in
              add y.value (mul x.value (pow (of_int 10) decimalPos)));
         decimalPos = (y.decimalPos)
       })

let sub x y =
  if x.decimalPos = y.decimalPos
  then { value = (Bigint.sub x.value y.value); decimalPos = (x.decimalPos) }
  else
    if x.decimalPos > y.decimalPos
    then
      (let decimalPos = x.decimalPos - y.decimalPos in
       {
         value =
           (let open Bigint in
              sub x.value (mul y.value (pow (of_int 10) decimalPos)));
         decimalPos = (x.decimalPos)
       })
    else
      (let decimalPos = y.decimalPos - x.decimalPos in
       {
         value =
           (let open Bigint in
              sub y.value (mul x.value (pow (of_int 10) decimalPos)));
         decimalPos = (y.decimalPos)
       })

let mul x y =
  {
    value = (Bigint.mul x.value y.value);
    decimalPos = (x.decimalPos + y.decimalPos)
  }

let elongateBy x decimalPos =
  {
    x with
    value =
      (let open Bigint in Bigint.mul x.value (pow (of_int 10) decimalPos))
  }

(* let truncate x decimalPos =
 *   let diff = x.decimalPos - decimalPos in
 *   { value = (let open Bigint in div x.value (pow (of_int 10) diff)); decimalPos
 *   } *)

let adjustDecimalPos (x : t) (y : t) =
  if x.decimalPos = y.decimalPos
  then (x, y)
  else
    if x.decimalPos > y.decimalPos
    then
      (let decimalPos = x.decimalPos - y.decimalPos in
       (x,
         {
           value =
             (Bigint.mul y.value (Bigint.pow (Bigint.of_int 10) decimalPos));
           decimalPos = (x.decimalPos)
         }))
    else
      (let decimalPos = y.decimalPos - x.decimalPos in
       ({
          value = (Bigint.mul x.value (Bigint.pow (Bigint.of_int 10) decimalPos));
          decimalPos = (y.decimalPos)
        }, y))

let div x y =
  if (x.decimalPos = 0) && (y.decimalPos = 0)
  then { value = (Bigint.div x.value y.value); decimalPos = (x.decimalPos) }
  else
    (let (x,y) = adjustDecimalPos x y in
     let xFirstNonZero = Bigint.firstNonZero x.value in
     let yFirstNonZero = Bigint.firstNonZero y.value in
     match (xFirstNonZero, yFirstNonZero) with
     | (((Some (xFirstNonZero))[@explicit_arity ]),((Some
        (yFirstNonZero))[@explicit_arity ])) ->
         if (xFirstNonZero >= x.decimalPos) && (yFirstNonZero >= y.decimalPos)
         then
           elongateBy
             { value = (Bigint.div x.value y.value); decimalPos = (x.decimalPos)
             } x.decimalPos
         else
           (let reposition =
              if xFirstNonZero > yFirstNonZero
              then y.decimalPos - yFirstNonZero
              else x.decimalPos - xFirstNonZero in
            let x = elongateBy x reposition in
            let y = elongateBy y reposition in
            elongateBy
              {
                value = (let open Bigint in div x.value y.value);
                decimalPos = (x.decimalPos)
              } x.decimalPos)
     | _ -> { x with value = Bigint.zero })

(** comparison *)
  
let compare x y =
  let (x,y) = adjustDecimalPos x y in Bigint.compare x.value y.value

let equal x y = (compare x y) = 0

let leq x y = (compare x y) < 1

let geq x y = (compare x y) > -1
            
let lt x y = (compare x y) < 0

let gt x y = (compare x y) > 0
           
let leqZero x = (Bigint.compare x.value Bigint.zero) <= 0

let geqZero x = (Bigint.compare x.value Bigint.zero) >= 0
              
let ltZero x = (Bigint.compare x.value Bigint.zero) < 0

let gtZero x = (Bigint.compare x.value Bigint.zero) > 0

let min x y = (if (compare x y) < 0 then y else x : t)

let max x y = (if (compare x y) < 0 then x else y : t)
