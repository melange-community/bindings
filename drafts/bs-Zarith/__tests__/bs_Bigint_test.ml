open Jest
open Expect

let () = 

describe "Bigint" (fun () ->
  test "zero equal to (Bigint.of_int 0)" (fun () ->
    expect @@ Bigint.zero |> toEqual (Bigint.of_int 0));
                       
  test "one equal to (Bigint.of_int 1)" (fun () ->
    expect @@ Bigint.one |> toEqual (Bigint.of_int 1));

  test "minus_one equal to (Bigint.of_int (-1))" (fun () ->
    expect @@ Bigint.minus_one |> toEqual (Bigint.of_int (-1)));

  test "zero equal to (Bigint.of_int 0)" (fun () ->
    expect @@ Bigint.zero |> toEqual (Bigint.of_string "0"));
                       
  test "one equal to (Bigint.of_int 1)" (fun () ->
    expect @@ Bigint.one |> toEqual (Bigint.of_string "1"));

  test "minus_one equal to (Bigint.of_int (-1))" (fun () ->
    expect @@ Bigint.minus_one |> toEqual (Bigint.of_string "-1"));
                       
  test "2 + 1 = 3" (fun () ->                       
    expect @@ (Bigint.add (Bigint.of_int 1) (Bigint.of_int 2)) |> toEqual (Bigint.of_int 3));

  test "(-2) + (-1) = (-3)" (fun () ->    
    expect @@ Bigint.(Bigint.add (of_int (-1)) (of_int (-2))) |> toEqual (Bigint.of_int (-3)));

  test "0 + 0 = 0" (fun () ->    
    expect @@ Bigint.(Bigint.add zero zero) |> toEqual Bigint.zero);

  test "-3 + 3 = 0" (fun () ->    
    expect @@ Bigint.(Bigint.add (of_int (-3)) (of_int 3)) |> toEqual (Bigint.of_int 0));

  test "of_string: 2 + 1 = 3" (fun () ->                       
    expect @@ Bigint.(Bigint.add (of_string "1") (of_string "2")) |> toEqual (Bigint.of_int 3));

  test "addition with numbers larger than int64 can hold" (fun () ->
    let x = Bigint.of_string "1000000000000000000000000000000" in
    let y = Bigint.of_string "1000000000000000000000000000000" in
    let z = Bigint.add x y in

    expect @@ z |> toEqual (Bigint.of_string "2000000000000000000000000000000"));

  test "addition with numbers larger than int64 can hold" (fun () ->
    let x = Bigint.of_string "1000000000000000000000000000000000000000" in
    let y = Bigint.of_int 1 in
    let z = (Bigint.add y x) in
    expect @@ z |> toEqual (Bigint.of_string "1000000000000000000000000000000000000001"));  
  
  test "zero to string" (fun () ->
    expect @@ Bigint.to_string(Bigint.zero) |> toEqual "0");

  test "one to string" (fun () ->
    expect @@ Bigint.to_string(Bigint.one) |> toEqual "1");

  test "minus_one to string" (fun () ->
    expect @@ Bigint.to_string(Bigint.minus_one) |> toEqual "-1");

  test "big to string" (fun () ->
    expect @@ Bigint.to_string(Bigint.of_string "32389176649991293809043094891992939836566132213") |> toEqual "32389176649991293809043094891992939836566132213"));

  test "pow" (fun () ->
    expect @@ Bigint.(pow (of_int 2) 0) |> toEqual (Bigint.of_int 1));

  test "pow" (fun () ->
    expect @@ Bigint.(pow (of_int 2) 1) |> toEqual (Bigint.of_int 2));

  test "pow" (fun () ->
    expect @@ Bigint.(pow (of_int 2) 2) |> toEqual (Bigint.of_int 4));

  test "pow" (fun () ->
    expect @@ Bigint.(pow (of_int 4) 4) |> toEqual (Bigint.of_int 256));

  (* test that multiplications are handled correctly *)
  test "1 * 1 = 1" (fun () ->
    expect @@ Bigint.(mul one one) |> toEqual (Bigint.of_int 1));
  
  test "1 * 0 = 0" (fun () ->
    expect @@ Bigint.(mul one zero) |> toEqual Bigint.zero);
  
  test "0 * 0 = 0" (fun () ->
    expect @@ Bigint.(mul zero zero) |> toEqual Bigint.zero);

  test "-1 * 1 = -1" (fun () ->
    expect @@ Bigint.(mul (of_int (-1)) one) |> toEqual (Bigint.of_int (-1)));

  test "20 * 2 = 40" (fun () ->
    expect @@ Bigint.(mul (of_int 20) (of_int 2)) |> toEqual (Bigint.of_int 40));
  
  test "20 * -1 = -20" (fun () ->
    expect @@ Bigint.(mul (of_int 20) (of_int (-1))) |> toEqual (Bigint.of_int (-20)));

  (* test that div handles signs correctly *)
  test "div" (fun () ->
    expect @@ Bigint.(div (of_int 6) (of_int 3)) |> toEqual (Bigint.of_int 2));

  test "div" (fun () ->
    expect @@ Bigint.(div (of_int (-6)) (of_int 3)) |> toEqual (Bigint.of_int (-2)));

  test "div" (fun () ->
    expect @@ Bigint.(div (of_int 6) (of_int (-3))) |> toEqual (Bigint.of_int (-2)));

  test "div" (fun () ->
    expect @@ Bigint.(div (of_int (-6)) (of_int (-3))) |> toEqual (Bigint.of_int 2));

  test "div" (fun () ->
    expect @@ Bigint.(div (of_int 7) (of_int 3)) |> toEqual (Bigint.of_int 2));

  test "2 - 1 = 1" (fun () ->
    expect @@ Bigint.(Bigint.sub (of_int 2) (of_int 1)) |> toEqual (Bigint.of_int 1));

  test "10 - 7 = 3" (fun () ->
    expect @@ Bigint.(Bigint.sub (of_int 10) (of_int 7)) |> toEqual (Bigint.of_int 3));

  test "7 - 10 = -3" (fun () ->
    expect @@ Bigint.(Bigint.sub (of_int 7) (of_int 10)) |> toEqual (Bigint.of_int (-3)));

  test "rem" (fun () ->
    expect @@ Bigint.(rem (of_int 4) (of_int 25)) |> toEqual (Bigint.of_int 4));

  test "rem" (fun () ->
    expect @@ Bigint.(rem (of_string "18446744073709551617") (of_string "18446744073709551616")) |> toEqual (Bigint.of_int 1));
  
  test "rem" (fun () ->
    expect @@ Bigint.(rem (of_int 26) (of_int 25)) |> toEqual (Bigint.of_int 1));

  test "rem" (fun () ->
    expect @@ Bigint.(rem (of_int 25) (of_int 25)) |> toEqual (Bigint.of_int 0));
  
  test "rem" (fun () ->
    expect @@ Bigint.(rem (of_int 7) (of_int 3)) |> toEqual (Bigint.of_int 1));

  test "rem" (fun () ->
    expect @@ Bigint.(rem (of_int 7) (of_int (-3))) |> toEqual (Bigint.of_int 1));

  test "rem" (fun () ->
    expect @@ Bigint.(rem (of_int (-7)) (of_int 3)) |> toEqual (Bigint.of_int (-1)));

  test "rem" (fun () ->
    expect @@ Bigint.(rem (of_int (-7)) (of_int (-3))) |> toEqual (Bigint.of_int (-1)));

  test "rem proof" (fun () ->
    let a = Bigint.of_int (-7) in
    let b = Bigint.of_int (-3) in
    let c = Bigint.(Bigint.(+) (Bigint.mul b (div a b)) (rem a b)) in
    expect @@ a |> toEqual c);

  test "rem proof" (fun () ->
    let a = Bigint.of_int (21) in
    let b = Bigint.of_int (4) in
    let c = Bigint.(Bigint.(+) (Bigint.mul b (div a b)) (rem a b)) in
    expect @@ a |> toEqual c);

  test "rem proof" (fun () ->
    let a = Bigint.of_int (-21) in
    let b = Bigint.of_int (4) in
    let c = Bigint.(Bigint.(+) (Bigint.mul b (div a b)) (rem a b)) in
    expect @@ a |> toEqual c);

  test "div_rem 7 3" (fun () ->
    expect @@ Bigint.(div_rem (of_int 7) (of_int 3)) |> toEqual (Bigint.(of_int 2, of_int 1)));

  test "div_rem 7 (-3)" (fun () ->
    expect @@ Bigint.(div_rem (of_int 7) (of_int (-3))) |> toEqual (Bigint.(of_int (-2), of_int 1)));

  test "div_rem (-7) 3" (fun () ->
    expect @@ Bigint.(div_rem (of_int (-7)) (of_int 3)) |> toEqual (Bigint.(of_int (-2), of_int (-1))));

  test "div_rem (-7) (-3)" (fun () ->
    expect @@ Bigint.(div_rem (of_int (-7)) (of_int (-3))) |> toEqual (Bigint.(of_int 2, of_int (-1))));

  test "div_rem 9 3" (fun () ->
    expect @@ Bigint.(div_rem (of_int 9) (of_int 3)) |> toEqual (Bigint.(of_int 3, of_int 0)));

  test "div_rem 9 (-3)" (fun () ->
    expect @@ Bigint.(div_rem (of_int 9) (of_int (-3))) |> toEqual (Bigint.(of_int (-3), of_int 0)));
  
  test "div_rem (-9) 3" (fun () ->
    expect @@ Bigint.(div_rem (of_int (-9)) (of_int 3)) |> toEqual (Bigint.(of_int (-3), of_int 0)));

  test "div_rem (-9) (-3)" (fun () ->
    expect @@ Bigint.(div_rem (of_int (-9)) (of_int (-3))) |> toEqual (Bigint.(of_int 3, of_int 0)));

  test "div_rem (1) (2)" (fun () ->
    expect @@ Bigint.(div_rem (of_int (1)) (of_int (2))) |> toEqual (Bigint.(zero, of_int 1)));


  test "ediv_rem 7 3" (fun () ->
    expect @@ Bigint.(ediv_rem (of_int 7) (of_int 3)) |> toEqual (Bigint.(of_int 2, of_int 1)));

  test "ediv_rem 7 (-3)" (fun () ->
    expect @@ Bigint.(ediv_rem (of_int 7) (of_int (-3))) |> toEqual (Bigint.(of_int (-2), of_int 1)));

  test "ediv_rem (-7) 3" (fun () ->
    expect @@ Bigint.(ediv_rem (of_int (-7)) (of_int 3)) |> toEqual (Bigint.(of_int (-3), of_int 2)));

  test "ediv_rem (-7) (-3)" (fun () ->
    expect @@ Bigint.(ediv_rem (of_int (-7)) (of_int (-3))) |> toEqual (Bigint.(of_int (-3), of_int 2)));

  test "ediv_rem (-8) 3" (fun () ->
    expect @@ Bigint.(ediv_rem (of_int (-8)) (of_int 3)) |> toEqual (Bigint.(of_int (-3), of_int 1)));

  test "ediv_rem (-8) (-3)" (fun () ->
    expect @@ Bigint.(ediv_rem (of_int (-8)) (of_int (-3))) |> toEqual (Bigint.(of_int (-3), of_int 1)));

  test "ediv_rem 9 3" (fun () ->
    expect @@ Bigint.(ediv_rem (of_int 9) (of_int 3)) |> toEqual (Bigint.(of_int 3, of_int 0 )));

  test "ediv_rem 9 (-3)" (fun () ->
    expect @@ Bigint.(ediv_rem (of_int 9) (of_int (-3))) |> toEqual (Bigint.(of_int (-3), zero )));
  
  test "ediv_rem (-9) 3" (fun () ->
    expect @@ Bigint.(ediv_rem (of_int (-9)) (of_int 3)) |> toEqual (Bigint.(of_int (-3), of_int 0 )));

  test "ediv_rem (-9) (-3)" (fun () ->
    expect @@ Bigint.(ediv_rem (of_int (-9)) (of_int (-3))) |> toEqual (Bigint.(of_int (-3), zero )));

  test "ediv_rem (1) (2)" (fun () ->
    expect @@ Bigint.(ediv_rem (of_int 1) (of_int 2)) |> toEqual (Bigint.(zero, of_int 1 )));

  test "is_even" (fun () ->
    expect @@ Bigint.(is_even (of_int (8))) |> toEqual true);  

  test "is_even" (fun () ->
    expect @@ Bigint.(is_even (of_int (9))) |> toEqual false);

  test "is_even" (fun () ->
    expect @@ Bigint.(is_even (of_string "839816238764918263491726983776763728736482736846")) |> toEqual true);  

  test "is_even" (fun () ->
    expect @@ Bigint.(is_even (of_string "98382938792846298734695872639470987109877098703")) |> toEqual false);

  test "is_odd" (fun () ->
    expect @@ Bigint.(is_odd (of_string "839816238764918263491726983776763728736482736846")) |> toEqual false);  

  test "is_odd" (fun () ->
    expect @@ Bigint.(is_odd (of_string "98382938792846298734695872639470987109877098703")) |> toEqual true);


  test "sign" (fun () ->
    expect @@ Bigint.(sign (of_string "98382938792846298734695872639470987109877098703")) |> toEqual 1);

  test "sign" (fun () ->
    expect @@ Bigint.(sign (of_string "0")) |> toEqual 0);

  test "sign" (fun () ->
    expect @@ Bigint.(sign (of_string "-2839849727247283728372837287378723")) |> toEqual (-1));

(* comparisons *)

  test "2 = 3" (fun () ->
    expect @@ Bigint.(Bigint.(=) (of_int 2) (of_int 3) ) |> toEqual false);

  test "2 = 2" (fun () ->
    expect @@ Bigint.(Bigint.(=) (of_int 2) (of_int 2) ) |> toEqual true);

  test "0 = 0" (fun () ->
    expect @@ Bigint.(Bigint.(=) (of_int 0) (of_int 0) ) |> toEqual true);

  test "0 = 0" (fun () ->
    expect @@ Bigint.(Bigint.(=) (of_int 0) (of_int 0) ) |> toEqual true);

  test "0 = 0" (fun () ->
    expect @@ Bigint.(Bigint.(=) zero (of_int 0) ) |> toEqual true);

  test "0 = 0" (fun () ->
    expect @@ Bigint.(Bigint.(=) zero (of_string "0") ) |> toEqual true);

  test "0 = 0" (fun () ->
    expect @@ Bigint.(Bigint.(=) (of_int 0) (of_string "0") ) |> toEqual true);

  test "-1 = -1" (fun () ->
    expect @@ Bigint.(Bigint.(=) (of_int (-1)) (of_int (-1)) ) |> toEqual true);

  test "-1 = 1" (fun () ->
    expect @@ Bigint.(Bigint.(=) (of_int (-1)) (of_int 1) ) |> toEqual false);


  test "2 <= 3" (fun () ->
    expect @@ Bigint.(Bigint.(<=) (of_int 2) (of_int 3) ) |> toEqual true);

  test "2 <= 3" (fun () ->
    expect @@ Bigint.(Bigint.(<=) (of_int 2) (of_int 3) ) |> toEqual true);

  test "3 <= 3" (fun () ->
    expect @@ Bigint.(Bigint.(<=) (of_int 3) (of_int 3) ) |> toEqual true);

  test "0 <= 0" (fun () ->
    expect @@ Bigint.(Bigint.(<=) (of_int 0) (of_int 0) ) |> toEqual true);

  test "-1 <= 0" (fun () ->
    expect @@ Bigint.(Bigint.(<=) (of_int (-1)) (of_int 0) ) |> toEqual true);

  test "-3 <= -2" (fun () ->
    expect @@ Bigint.(Bigint.(<=) (of_int (-3)) (of_int (-2)) ) |> toEqual true);

  test "1 <= 0" (fun () ->
    expect @@ Bigint.(Bigint.(<=) (of_int 1) (of_int 0) ) |> toEqual false);

  test "2 < 3" (fun () ->
    expect @@ Bigint.(Bigint.(<) (of_int 2) (of_int 3) ) |> toEqual true);

  test "3 < 3" (fun () ->
    expect @@ Bigint.(Bigint.(<) (of_int 3) (of_int 3) ) |> toEqual false);

  test "-1 < 0" (fun () ->
    expect @@ Bigint.(Bigint.(<) (of_int (-1)) (of_int 0) ) |> toEqual true);

  test "-3 < -2" (fun () ->
    expect @@ Bigint.(Bigint.(<) (of_int (-3)) (of_int (-2)) ) |> toEqual true);

  test "1 < 0" (fun () ->
    expect @@ Bigint.(Bigint.(<) (of_int 1) (of_int 0) ) |> toEqual false);


  test "2 >= 3" (fun () ->
    expect @@ Bigint.(Bigint.(>=) (of_int 2) (of_int 3) ) |> toEqual false);

  test "3 >= 3" (fun () ->
    expect @@ Bigint.(Bigint.(>=) (of_int 3) (of_int 3) ) |> toEqual true);

  test "-1 >= 0" (fun () ->
    expect @@ Bigint.(Bigint.(>=) (of_int (-1)) (of_int 0) ) |> toEqual false);

  test "-3 >= -2" (fun () ->
    expect @@ Bigint.(Bigint.(>=) (of_int (-3)) (of_int (-2)) ) |> toEqual false);

  test "1 >= 0" (fun () ->
    expect @@ Bigint.(Bigint.(>=) (of_int 1) (of_int 0) ) |> toEqual true);

  test "3 >= 2" (fun () ->
    expect @@ Bigint.(Bigint.(>=) (of_int 3) (of_int 2) ) |> toEqual true);

  test "3 >= -2" (fun () ->
    expect @@ Bigint.(Bigint.(>=) (of_int 3) (of_int (-2)) ) |> toEqual true);


  test "2 > 3" (fun () ->
    expect @@ Bigint.(Bigint.(>) (of_int 2) (of_int 3) ) |> toEqual false);

  test "3 > 3" (fun () ->
    expect @@ Bigint.(Bigint.(>) (of_int 3) (of_int 3) ) |> toEqual false);

  test "-1 > 0" (fun () ->
    expect @@ Bigint.(Bigint.(>) (of_int (-1)) (of_int 0) ) |> toEqual false);

  test "-3 > -2" (fun () ->
    expect @@ Bigint.(Bigint.(>) (of_int (-3)) (of_int (-2)) ) |> toEqual false);

  test "1 > 0" (fun () ->
    expect @@ Bigint.(Bigint.(>) (of_int 1) (of_int 0) ) |> toEqual true);

  test "2 > 3" (fun () ->
    expect @@ Bigint.(Bigint.(>) (of_int 2) (of_int 3) ) |> toEqual false);

  test "3 > 2" (fun () ->
    expect @@ (Bigint.(>) (Bigint.of_int 3) (Bigint.of_int 2) ) |> toEqual true);

  test "3 > -2" (fun () ->
    expect @@ (Bigint.(>) (Bigint.of_int 3) (Bigint.of_int (-2))) |> toEqual true);

  test "to_int max_int" (fun () ->
    expect @@ Bigint.(to_int (of_int max_int)) |> toEqual max_int);

  test "to_int min_int" (fun () ->
    expect @@ Bigint.(to_int (of_int min_int)) |> toEqual min_int);

  test "to_int greater than max_int should throw Overflow" (fun () ->
    expect @@ (fun () -> Bigint.(to_int (of_string "21474836478"))) |> toThrowException Bigint.Overflow );

  test "to_int smaller than min_int should throw Overflow" (fun () ->
    expect @@ (fun () -> Bigint.(to_int (of_string "-21474836478"))) |> toThrowException Bigint.Overflow );

  test "to_int32 max_int" (fun () ->
    expect @@ Bigint.(to_int32 (of_int32 Int32.max_int)) |> toEqual Int32.max_int);

  test "to_int32 min_int" (fun () ->
    expect @@ Bigint.(to_int32 (of_int32 Int32.min_int)) |> toEqual Int32.min_int);

  test "to_int32 greater than max_int should throw Overflow" (fun () ->
    expect @@ (fun () -> Bigint.(to_int32 (of_string "21474836478"))) |> toThrowException Bigint.Overflow );

  test "to_int32 smaller than min_int should throw Overflow" (fun () ->
    expect @@ (fun () -> Bigint.(to_int32 (of_string "-21474836478"))) |> toThrowException Bigint.Overflow );


  test "to_int64 max_int" (fun () ->
    expect @@ Bigint.(to_int64 (of_int64 Int64.max_int)) |> toEqual Int64.max_int);

  test "to_int64 min_int" (fun () ->
    expect @@ Bigint.(to_int64 (of_int64 Int64.min_int)) |> toEqual Int64.min_int);

  test "to_int64 greater than max_int should throw Overflow" (fun () ->
    expect @@ (fun () -> Bigint.(to_int64 (of_string "9223372036854775808"))) |> toThrowException Bigint.Overflow );

  test "to_float" (fun () ->
    expect @@ Bigint.(to_float (of_string "9007199254740992")) |> toEqual (9007199254740993.0));

  test "3 <> 2" (fun () ->
    expect @@ ((Bigint.of_int 3) <> (Bigint.of_int 2)) |> toEqual true);

  test "2 <> 2" (fun () ->
    expect @@ ((Bigint.of_int 2) <> (Bigint.of_int 2)) |> toEqual false);

  test "0 <> 1" (fun () ->
    expect @@ ((Bigint.of_int 0) <> (Bigint.of_int 1)) |> toEqual true);

  test "gcd 2 12" (fun () ->
    expect @@ Bigint.(gcd (of_int 2) (of_int 12)) |> toEqual (Bigint.of_int 2));

  test "gcd 12 20" (fun () ->
    expect @@ Bigint.(gcd (of_int 12) (of_int 20)) |> toEqual (Bigint.of_int 4));

  test "gcd 36 60" (fun () ->
    expect @@ Bigint.(gcd (of_int 36) (of_int 60)) |> toEqual (Bigint.of_int 12));

  test "logand" (fun () ->
    expect @@ Bigint.(logand (of_int 198) (of_int 163)) |> toEqual (Bigint.of_int 130));

  test "logand" (fun () ->
    expect @@ Bigint.(logand (of_int 3) (of_int 7)) |> toEqual (Bigint.of_int 3));

  test "logand" (fun () ->
    expect @@ Bigint.(logand (of_int 5) (of_int 3)) |> toEqual (Bigint.of_int 1));

  test "logand" (fun () ->
    expect @@ Bigint.(logand (of_int 3) (of_int 2)) |> toEqual (Bigint.of_int 2));

  test "logand" (fun () ->
    expect @@ Bigint.(logand (of_int 6) (of_int 11)) |> toEqual (Bigint.of_int 2));
(*
 * broken with negative numbers
  test "logand" (fun () ->
    expect @@ Bigint.(logand (of_int 1) (of_int (-1))) |> toEqual (Bigint.of_int 1));

  test "logand" (fun () ->
    expect @@ Bigint.(logand (of_int (-1)) (of_int 1)) |> toEqual (Bigint.of_int 1));
  
  test "logand" (fun () ->
    expect @@ Bigint.(logand (of_int (-1)) (of_int (-1))) |> toEqual (Bigint.of_int (-1)));
  
  test "logand" (fun () ->
    expect @@ Bigint.(logand (of_int 1) (of_int (-2))) |> toEqual (Bigint.of_int 0));

  test "logand" (fun () ->
    expect @@ Bigint.(logand (of_int 1) (of_int (-2))) |> toEqual (Bigint.of_int 0));

  test "logand" (fun () ->
    expect @@ Bigint.(logand (of_int (-3)) (of_int (-7))) |> toEqual (Bigint.of_int (-7)));

  test "logand" (fun () ->
    expect @@ Bigint.(logand (of_int (-3)) (of_int 7)) |> toEqual (Bigint.of_int (5)));
 *)  
  
  test "logor" (fun () ->
    expect @@ Bigint.(logor (of_int 6) (of_int 3)) |> toEqual (Bigint.of_int 7));

  (*
 * broken with negative numbers
  test "logor" (fun () ->
    expect @@ Bigint.(logor (of_int 1) (of_int (-2))) |> toEqual (Bigint.of_int (-1)));

  test "logor" (fun () ->
    expect @@ Bigint.(logor (of_int 1) (of_int (-1))) |> toEqual (Bigint.of_int (-1)));
   *)
  test "logor" (fun () ->
    expect @@ Bigint.(logor (of_int 1) (of_int (0))) |> toEqual (Bigint.of_int 1));
  
  test "div" (fun () ->
    expect @@ Bigint.(div (of_int 1) (of_int 2)) |> toEqual (Bigint.zero));

  test "div" (fun () ->
    expect @@ Bigint.(div (of_int 2) (of_int 2)) |> toEqual (Bigint.one));

  test "div" (fun () ->
    expect @@ Bigint.(div (of_int 3) (of_int 2)) |> toEqual (Bigint.one));

  test "div" (fun () ->
    expect @@ Bigint.(div (of_int 4) (of_int 2)) |> toEqual (Bigint.of_int 2));

  test "div" (fun () ->
    expect @@ Bigint.(div (of_int 9) (of_int 2)) |> toEqual (Bigint.of_int 4));  

  test "numbits" (fun () ->
    expect @@ Bigint.(numbits (of_int (-1))) |> toEqual 1);

  test "numbits" (fun () ->
    expect @@ Bigint.(numbits (of_int 1)) |> toEqual 1);

  test "numbits" (fun () ->
    expect @@ Bigint.(numbits zero) |> toEqual 0);

  test "numbits" (fun () ->
    expect @@ Bigint.(numbits (of_int 6)) |> toEqual 3);

  test "numbits" (fun () ->
    expect @@ Bigint.(numbits (of_int 5)) |> toEqual 3);

  test "numbits" (fun () ->
    expect @@ Bigint.(numbits (of_int 8)) |> toEqual 4);

  test "numbits" (fun () ->
    expect @@ Bigint.(numbits (of_int 16)) |> toEqual 5);

  test "numbits" (fun () ->
    expect @@ Bigint.(numbits (of_int (-8))) |> toEqual 4);

  test "cdiv" (fun () ->
    expect @@ Bigint.(cdiv (of_int 9) (of_int 2)) |> toEqual (Bigint.of_int 5));

  test "cdiv" (fun () ->
    expect @@ Bigint.(cdiv (of_int (-9)) (of_int 2)) |> toEqual (Bigint.of_int (-4)));

  test "cdiv" (fun () ->
    expect @@ Bigint.(cdiv (of_int (-3)) (of_int 2)) |> toEqual (Bigint.of_int (-1)));

  test "cdiv" (fun () ->
    expect @@ Bigint.(cdiv (of_int (100)) (of_int 40)) |> toEqual (Bigint.of_int 3));
  
  test "fdiv" (fun () ->
    expect @@ Bigint.(fdiv (of_int 9) (of_int 2)) |> toEqual (Bigint.of_int 4));

  test "fdiv" (fun () ->
    expect @@ Bigint.(fdiv (of_int (-9)) (of_int 2)) |> toEqual (Bigint.of_int (-5)));

  test "div" (fun () ->
    expect @@ Bigint.(fdiv (of_int (-3)) (of_int 2)) |> toEqual (Bigint.of_int (-2)));

  test "div" (fun () ->
    expect @@ Bigint.(fdiv (of_int (100)) (of_int 40)) |> toEqual (Bigint.of_int 2));
  
  test "pow" (fun () ->
    expect @@ Bigint.(pow (of_int 2) 2) |> toEqual (Bigint.of_int 4))
