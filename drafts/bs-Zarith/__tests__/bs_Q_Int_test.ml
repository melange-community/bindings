open Jest
open Expect

let () = 

describe "Q.Int" (fun () ->
  test "1/2 - 1/4 is 1/2" (fun () ->
    expect @@ Q.Int.(sub (make (Z.Int.one) (Z.Int.of_int 2)) (make (Z.Int.of_int 1) (Z.Int.of_int 4)) ) |> toEqual (Q.Int.(make (Z.Int.of_int 1) (Z.Int.of_int 4))));

  )
