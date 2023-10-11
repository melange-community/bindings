open Jest
open Expect

let () = 

describe "Z.Int" (fun () ->
  test "rem" (fun () ->
    expect @@ Z.Int.(rem (of_int 7) (of_int 3)) |> toEqual (Z.Int.of_int 1));

  test "rem" (fun () ->
    expect @@ Z.Int.(rem (of_int 7) (of_int (-3))) |> toEqual (Z.Int.of_int 1));

  test "rem" (fun () ->
    expect @@ Z.Int.(rem (of_int (-7)) (of_int 3)) |> toEqual (Z.Int.of_int (-1)));

  test "rem" (fun () ->
    expect @@ Z.Int.(rem (of_int (-7)) (of_int (-3))) |> toEqual (Z.Int.of_int (-1)));


  test "ediv_rem 7 3" (fun () ->
    expect @@ Z.Int.(ediv_rem (of_int 7) (of_int 3)) |> toEqual (Z.Int.(of_int 2, of_int 1)));

  test "ediv_rem 7 (-3)" (fun () ->
    expect @@ Z.Int.(ediv_rem (of_int 7) (of_int (-3))) |> toEqual (Z.Int.(of_int (-2), of_int 1)));

  test "ediv_rem (-7) 3" (fun () ->
    expect @@ Z.Int.(ediv_rem (of_int (-7)) (of_int 3)) |> toEqual (Z.Int.(of_int (-3), of_int 2)));

  test "ediv_rem (-7) (-3)" (fun () ->
    expect @@ Z.Int.(ediv_rem (of_int (-7)) (of_int (-3))) |> toEqual (Z.Int.(of_int (-3), of_int 2)));

  test "ediv_rem (-8) 3" (fun () ->
    expect @@ Z.Int.(ediv_rem (of_int (-8)) (of_int 3)) |> toEqual (Z.Int.(of_int (-3), of_int 1)));

  test "ediv_rem (-8) (-3)" (fun () ->
    expect @@ Z.Int.(ediv_rem (of_int (-8)) (of_int (-3))) |> toEqual (Z.Int.(of_int (-3), of_int 1)));

  test "ediv_rem 9 3" (fun () ->
    expect @@ Z.Int.(ediv_rem (of_int 9) (of_int 3)) |> toEqual (Z.Int.(of_int 3, of_int 0 )));

  test "ediv_rem 9 (-3)" (fun () ->
    expect @@ Z.Int.(ediv_rem (of_int 9) (of_int (-3))) |> toEqual (Z.Int.(of_int (-3), zero )));

  test "ediv_rem (-9) 3" (fun () ->
    expect @@ Z.Int.(ediv_rem (of_int (-9)) (of_int 3)) |> toEqual (Z.Int.(of_int (-3), of_int 0 )));

  test "ediv_rem (-9) (-3)" (fun () ->
    expect @@ Z.Int.(ediv_rem (of_int (-9)) (of_int (-3))) |> toEqual (Z.Int.(of_int (-3), zero )));


  test "is_even" (fun () ->
    expect @@ Z.Int.(is_even (of_int (8))) |> toEqual true);  

  test "is_even" (fun () ->
    expect @@ Z.Int.(is_even (of_int (9))) |> toEqual false);

  test "is_odd" (fun () ->
    expect @@ Z.Int.(is_odd (of_int (8))) |> toEqual false);  

  test "is_odd" (fun () ->
    expect @@ Z.Int.(is_odd (of_int (9))) |> toEqual true);

  
  test "gcd 2 12" (fun () ->
    expect @@ Z.Int.(gcd (of_int 2) (of_int 12)) |> toEqual (Z.Int.of_int 2));

  test "gcd 12 20" (fun () ->
    expect @@ Z.Int.(gcd (of_int 12) (of_int 20)) |> toEqual (Z.Int.of_int 4));

  test "gcd 36 60" (fun () ->
    expect @@ Z.Int.(gcd (of_int 36) (of_int 60)) |> toEqual (Z.Int.of_int 12));

  
  )
