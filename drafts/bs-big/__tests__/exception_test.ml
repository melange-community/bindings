open Jest

(*check that exceptions are wrapped properly in OCaml exceptions*)
let () =
  describe "exception_tests" (fun () ->
  let open Expect in

  let exn_test =
    let count = ref 0 in
    fun f exn ->
      count := !count + 1;
      let passed =
        try
          let _ = f () in
          failwith "f should throw"
        with e -> e = exn
      in
      test ("excn_test" ^ string_of_int !count) (fun () -> expect passed |> toBe true)
  in
  exn_test (fun () -> Big.div (Big.fromInt 1) (Big.fromInt 0)) Big.Div_by_zero;
  exn_test (fun () -> Big.fromString "bad string") Big.Invalid_number;
  exn_test (fun () -> Big.setDP (-1); Big.fromInt 1) Big.Invalid_decimal_places;
  exn_test (fun () -> Big.setRM (-1); Big.fromInt 1) Big.Invalid_rounding_mode;
  exn_test (fun () -> Big.fromInt (-1) |. Big.sqrt) Big.No_square_root;
  exn_test (fun () -> Big.fromInt 1 |. Big.toPrecision ~sd:(-1) () |. Big.fromString) Big.Invalid_precision
)
