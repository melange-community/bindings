open Jest
open Expect

module B = Bigfloat
let mk = B.mkBigfloat

let _ =
  describe "Bigfloat.add"
    (fun ()  ->
       test "1 + 1"
         (fun _  ->
            (expect (B.add (mk Bigint.one 0) (mk Bigint.one 0))) |>
              (toEqual (mk (Bigint.of_int 2) 0)));
       test "1.0 + 1.0"
         (fun _  ->
            (expect
               (B.add (mk (Bigint.of_int 10) 1) (mk (Bigint.of_int 10) 1)))
              |> (toEqual (mk (Bigint.of_int 20) 1)));
       test "1.00 + 1"
         (fun _  ->
            (expect
               (B.add (mk (Bigint.of_int 100) 2) (mk (Bigint.of_int 1) 0)))
              |> (toEqual (mk (Bigint.of_int 200) 2)));
       test "0.10 + 1.00"
         (fun _  ->
            (expect
               (B.add (mk (Bigint.of_int 10) 2) (mk (Bigint.of_int 100) 2)))
              |> (toEqual (mk (Bigint.of_int 110) 2)));
       test "1.23 + 0.0354"
         (fun _  ->
            (expect
               (B.add (mk (Bigint.of_int 123) 2) (mk (Bigint.of_int 354) 4)))
              |> (toEqual (mk (Bigint.of_int 12654) 4)));
       test
         "1.000000 + 1.00000000"
         (fun _  ->
            (expect
               (B.add (mk (Bigint.of_int 1000000) 6)
                  (mk (Bigint.of_int 100000000) 8)))
              |> (toEqual (mk (Bigint.of_int 200000000) 8)));
       test "1.500000 + 3.54"
         (fun _  ->
            (expect
               (B.add (mk (Bigint.of_int 1500000) 6)
                  (mk (Bigint.of_int 354) 2)))
              |> (toEqual (mk (Bigint.of_int 5040000) 6)));
       test
         "1.000000 + 9.0000000000"
         (fun _  ->
            (expect
               (B.add (mk (Bigint.of_int 10000000) 6)
                  (mk (Bigint.of_int64 90000000000L) 10)))
              |> (toEqual (mk (Bigint.of_int64 190000000000L) 10))))
let _ =
  describe "Bigfloat.sub"
    (fun ()  ->
       test "1 - 1"
         (fun _  ->
            (expect (B.sub (mk Bigint.one 0) (mk Bigint.one 0))) |>
              (toEqual (mk Bigint.zero 0)));
       test "2 - 1"
         (fun _  ->
            (expect (B.sub (mk (Bigint.of_int 2) 0) (mk Bigint.one 0))) |>
              (toEqual (mk Bigint.one 0)));
       test "10.0 - 5"
         (fun _  ->
            (expect
               (B.sub (mk (Bigint.of_int 100) 1) (mk (Bigint.of_int 5) 0)))
              |> (toEqual (mk (Bigint.of_int 50) 1)));
       test "20.00 - 5.0"
         (fun _  ->
            (expect
               (B.sub (mk (Bigint.of_int 2000) 2) (mk (Bigint.of_int 50) 1)))
              |> (toEqual (mk (Bigint.of_int 1500) 2)));
       test "20.00 - 0.5"
         (fun _  ->
            (expect
               (B.sub (mk (Bigint.of_int 2000) 2) (mk (Bigint.of_int 5) 1)))
              |> (toEqual (mk (Bigint.of_int 1950) 2))))
let _ =
  describe "Bigfloat.mul"
    (fun ()  ->
       test "1 * 1"
         (fun _  ->
            (expect (B.mul (mk Bigint.one 0) (mk Bigint.one 0))) |>
              (toEqual (mk Bigint.one 0)));
       test "2 * 1"
         (fun _  ->
            (expect (B.mul (mk (Bigint.of_int 2) 0) (mk Bigint.one 0))) |>
              (toEqual (mk (Bigint.of_int 2) 0)));
       test "2 * 1.00"
         (fun _  ->
            (expect
               (B.mul (mk (Bigint.of_int 2) 0) (mk (Bigint.of_int 100) 2)))
              |> (toEqual (mk (Bigint.of_int 200) 2)));
       test "5.00 * 2.00"
         (fun _  ->
            (expect
               (B.mul (mk (Bigint.of_int 500) 2) (mk (Bigint.of_int 100) 2)))
              |> (toEqual (mk (Bigint.of_int 50000) 4)));
       test "1.200 * 2.00"
         (fun _  ->
            (expect
               (B.mul (mk (Bigint.of_int 1200) 3) (mk (Bigint.of_int 200) 2)))
              |> (toEqual (mk (Bigint.of_int 240000) 5)));
       test "31.123 * 0.02"
         (fun _  ->
            (expect
               (B.mul (mk (Bigint.of_int 31123) 3) (mk (Bigint.of_int 2) 2)))
              |> (toEqual (mk (Bigint.of_int 62246) 5))))
let _ =
  describe
    "Bigfloat.firstNonZero"
    (fun ()  ->
       test "0"
         (fun _  -> (expect (Bigint.firstNonZero Bigint.zero)) |> (toEqual None));
       test "1"
         (fun _  ->
            (expect (Bigint.firstNonZero Bigint.one)) |>
              (toEqual (Some 0)));
       test "10"
         (fun _  ->
            (expect (Bigint.firstNonZero (Bigint.of_int 10))) |>
              (toEqual (Some 1)));
       test "200"
         (fun _  ->
            (expect (Bigint.firstNonZero (Bigint.of_int 200))) |>
              (toEqual (Some 2)));
       test "90210"
         (fun _  ->
            (expect (Bigint.firstNonZero (Bigint.of_int 90210))) |>
              (toEqual (Some 1)));
       test "90000"
         (fun _  ->
            (expect (Bigint.firstNonZero (Bigint.of_int 90000))) |>
              (toEqual (Some 4))))
let _ =
  describe
    "Bigfloat.adjustDecimalPos"
    (fun ()  ->
       test "0, 0"
         (fun _  ->
            (expect (B.adjustDecimalPos (mk Bigint.one 0) (mk Bigint.one 0)))
              |> (toEqual ((mk Bigint.one 0), (mk Bigint.one 0))));
       test "12.34, 5.6"
         (fun _  ->
            (expect
               (B.adjustDecimalPos (mk (Bigint.of_int 1234) 2)
                  (mk (Bigint.of_int 56) 1)))
              |>
              (toEqual
                 ((mk (Bigint.of_int 1234) 2), (mk (Bigint.of_int 560) 2))));
       test "59.787800, 5"
         (fun _  ->
            (expect
               (B.adjustDecimalPos (mk (Bigint.of_int64 59787800L) 6)
                  (mk (Bigint.of_int 5) 0)))
              |>
              (toEqual
                 ((mk (Bigint.of_int64 59787800L) 6),
                   (mk (Bigint.of_int 5000000) 6)))))
let _ =
  describe "Bigfloat.div"
    (fun ()  ->
       test "1 / 1"
         (fun _  ->
            (expect (B.div (mk Bigint.one 0) (mk Bigint.one 0))) |>
              (toEqual (mk Bigint.one 0)));
       test "2 / 1"
         (fun _  ->
            (expect (B.div (mk (Bigint.of_int 2) 0) (mk Bigint.one 0))) |>
              (toEqual (mk (Bigint.of_int 2) 0)));
       test "4 / 2"
         (fun _  ->
            (expect (B.div (mk (Bigint.of_int 4) 0) (mk (Bigint.of_int 2) 0)))
              |> (toEqual (mk (Bigint.of_int 2) 0)));
       test "10 / 3"
         (fun _  ->
            (expect
               (B.div (mk (Bigint.of_int 10) 0) (mk (Bigint.of_int 3) 0)))
              |> (toEqual (mk (Bigint.of_int 3) 0)));
       test "1 / 0.5"
         (fun _  ->
            (expect (B.div (mk (Bigint.of_int 1) 0) (mk (Bigint.of_int 5) 1)))
              |> (toEqual (mk (Bigint.of_int 20) 1)));
       test "10.0 / 0.5"
         (fun _  ->
            (expect
               (B.div (mk (Bigint.of_int 100) 1) (mk (Bigint.of_int 5) 1)))
              |> (toEqual (mk (Bigint.of_int 200) 1)));
       test "20.0 / 0.02"
         (fun _  ->
            (expect
               (B.div (mk (Bigint.of_int 200) 1) (mk (Bigint.of_int 2) 2)))
              |> (toEqual (mk (Bigint.of_int 100000) 2)));
       test "100.0 / 0.03"
         (fun _  ->
            (expect
               (B.div (mk (Bigint.of_int 1000) 1) (mk (Bigint.of_int 3) 2)))
              |> (toEqual (mk (Bigint.of_int 333300) 2)));
       test
         "43.001234 / 7.00000000"
         (fun _  ->
            (expect
               (B.div (mk (Bigint.of_int 43001234) 6)
                  (mk (Bigint.of_int 700000000) 8)))
              |> (toEqual (mk (Bigint.of_int 600000000) 8)));
       test
         "99.000000 / 2.0000000000"
         (fun _  ->
            (expect
               (B.div (mk (Bigint.of_int64 99000000L) 6)
                  (mk
                     (Bigint.of_string
                        "20000000000")
                     10)))
              |>
              (toEqual
                 (mk
                    (Bigint.of_string
                       "490000000000")
                    10)));
       test
         "99.0 / 2.0000000000"
         (fun _  ->
            (expect
               (B.div (mk (Bigint.of_int64 990L) 1)
                  (mk
                     (Bigint.of_string
                        "20000000000")
                     10)))
              |>
              (toEqual
                 (mk
                    (Bigint.of_string
                       "490000000000")
                    10))))
let _ =
  describe "Bigfloat.ofString"
    (fun ()  ->
       test "'0'"
         (fun _  ->
            (expect (B.ofString "0" 0)) |>
              (toEqual
                 ((Some ((mk Bigint.zero 0))))));
       test "'1'"
         (fun _  ->
            (expect (B.ofString "1" 1)) |>
              (toEqual
                 ((Some ((mk (Bigint.of_int 10) 1))))));
       test "'1.0'"
         (fun _  ->
            (expect (B.ofString "1.0" 1)) |>
              (toEqual
                 ((Some ((mk (Bigint.of_int 10) 1))))));
       test "'1.01'"
         (fun _  ->
            (expect (B.ofString "1.01" 2)) |>
              (toEqual
                 ((Some ((mk (Bigint.of_int 101) 2))))));
       test "'1.023'"
         (fun _  ->
            (expect (B.ofString "1.023" 3))
              |>
              (toEqual
                 ((Some ((mk (Bigint.of_int 1023) 3))))));
       test "'123.456789'"
         (fun _  ->
            (expect
               (B.ofString "123.456789"
                  6))
              |>
              (toEqual
                 ((Some ((mk (Bigint.of_int 123456789) 6)))
                 )));
       test "'0.0089'"
         (fun _  ->
            (expect
               (B.ofString "00.0089" 4))
              |>
              (toEqual
                 ((Some ((mk (Bigint.of_int 89) 4))))));
       test "'984'"
         (fun _  ->
            (expect (B.ofString "984" 6)) |>
              (toEqual
                 ((Some ((mk (Bigint.of_int 984000000) 6))))));
       test "'3,267'"
         (fun _  ->
            (expect (B.ofString "3,267" 6))
              |>
              (toEqual
                 ((Some ((mk (Bigint.of_int64 3267000000L) 6))))));
       test "'3,267.1'"
         (fun _  ->
            (expect
               (B.ofString "3,267.1" 6))
              |>
              (toEqual
                 ((Some ((mk (Bigint.of_int64 3267100000L) 6)))))))
let _ =
  describe "Bigfloat.toString"
    (fun ()  ->
       test "0"
         (fun _  ->
            (expect (B.toString (mk Bigint.zero 0))) |>
              (toEqual "0"));
       test "0.0"
         (fun _  ->
            (expect (B.toString (mk Bigint.zero 1))) |>
              (toEqual "0.0"));
       test "1.0205"
         (fun _  ->
            (expect (B.toString (mk (Bigint.of_int 10205) 4))) |>
              (toEqual "1.0205"));
       test "1.000000"
         (fun _  ->
            (expect (B.toString (mk (Bigint.of_int 1000000) 6))) |>
              (toEqual "1.000000"));
       test "67.004020"
         (fun _  ->
            (expect (B.toString (mk (Bigint.of_int 67004020) 6))) |>
              (toEqual "67.004020")))
let _ =
  describe
    "Bigfloat.toStringWithCommas"
    (fun ()  ->
       test "0"
         (fun _  ->
            (expect (B.toStringWithCommas (mk Bigint.zero 0))) |>
              (toEqual "0"));
       test "1.000000"
         (fun _  ->
            (expect (B.toStringWithCommas (mk (Bigint.of_int 1000000) 6))) |>
              (toEqual "1.000000"));
       test "67.004020"
         (fun _  ->
            (expect (B.toStringWithCommas (mk (Bigint.of_int 67004020) 6)))
              |> (toEqual "67.004020"));
       test "1,267.004020"
         (fun _  ->
            (expect (B.toStringWithCommas (mk (Bigint.of_int 1267004020) 6)))
              |>
              (toEqual "1,267.004020"));
       test "45,657,923.004020"
         (fun _  ->
            (expect
               (B.toStringWithCommas
                  (mk
                     (Bigint.of_string
                        "45657923004020") 6)))
              |>
              (toEqual
                 "45,657,923.004020")))
let _ =
  describe "Bigfloat.compare"
    (fun ()  ->
       test "compare(0,1)"
         (fun _  ->
            (expect (B.compare (mk Bigint.zero 0) (mk Bigint.one 0))) |>
              (toEqual (-1)));
       test "compare(1,0)"
         (fun _  ->
            (expect (B.compare (mk Bigint.one 0) (mk Bigint.zero 0))) |>
              (toEqual 1));
       test "compare(0,0)"
         (fun _  ->
            (expect (B.compare (mk Bigint.zero 0) (mk Bigint.zero 0))) |>
              (toEqual 0));
       test "compare(1.0,0)"
         (fun _  ->
            (expect (B.compare (mk (Bigint.of_int 10) 1) (mk Bigint.zero 0)))
              |> (toEqual 1));
       test
         "compare(1.02,2.03)"
         (fun _  ->
            (expect
               (B.compare (mk (Bigint.of_int 102) 2)
                  (mk (Bigint.of_int 203) 2)))
              |> (toEqual (-1)));
       test "compare(1.02,0.2)"
         (fun _  ->
            (expect
               (B.compare (mk (Bigint.of_int 102) 1) (mk (Bigint.of_int 2) 1)))
              |> (toEqual 1));
       test
         "compare(1.01,1.010)"
         (fun _  ->
            (expect
               (B.compare (mk (Bigint.of_int 101) 2)
                  (mk (Bigint.of_int 1010) 3)))
              |> (toEqual 0));
       test
         "compare(9.234,10.000)"
         (fun _  ->
            (expect
               (B.compare (mk (Bigint.of_int 9234) 3)
                  (mk (Bigint.of_int 10000) 3)))
              |> (toEqual (-1)));
       test "compare(10,9.234)"
         (fun _  ->
            (expect
               (B.compare (mk (Bigint.of_int 10) 0)
                  (mk (Bigint.of_int 9234) 3)))
              |> (toEqual 1)))
