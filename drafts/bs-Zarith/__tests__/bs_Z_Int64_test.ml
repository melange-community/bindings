open Jest
open Expect

let () = 

describe "Z.Int64" (fun () ->
    test "add" (fun () ->
        let x = Z.Int64.of_string "230000232323322323" in
        let y = Z.Int64.of_int 3 in
        let z = Z.Int64.(sub x y) in

        expect @@ z |> toEqual (Z.Int64.of_string "230000232323322320"));

  )
