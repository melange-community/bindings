open Jest
open Expect

let () = 

describe "Int32" (fun () ->
  test "Int32" (fun () ->
    expect @@ Int32.of_int 1 |> toEqual (Int32.of_int 1));
);
