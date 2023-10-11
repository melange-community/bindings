open Jest
open Expect

let () = 

describe "Q.Bigint" (fun () ->
  test "1/2 - 1/4 is 1/2" (fun () ->
    expect @@ Q.Bigint.(sub (make (Z.Bigint.one) (Z.Bigint.of_int 2)) (make (Z.Bigint.of_int 1) (Z.Bigint.of_int 4)) ) |> toEqual (Q.Bigint.(make (Z.Bigint.of_int 1) (Z.Bigint.of_int 4))));

  test "1/8 + (-1/8) is 0" (fun () ->
    expect @@ Q.Bigint.(add (of_string "1/8") (of_string "-1/8")) |> toEqual Q.Bigint.zero));

  test "1/8 + 14/16 is 1" (fun () ->
    expect @@ Q.Bigint.(add (of_string "1/8") (of_string "14/16")) |> toEqual Q.Bigint.one);

  test "3 * 1/2 is 3/2" (fun () ->
    expect @@ Q.Bigint.(mul (of_string "3/1") (of_string "1/2")) |> toEqual Q.Bigint.(of_string "3/2"));

  test "2/3 / 3/4 is 8/9" (fun () ->
    expect @@ Q.Bigint.(div (of_string "2/3") (of_string "3/4")) |> toEqual Q.Bigint.(of_string "8/9"));
  
  test "zero equal to (Bigint.of_int 0)" (fun () ->
    expect @@ Q.Bigint.zero |> toEqual (Q.Bigint.zero));
