open Jest
open Expect
open U

let () = 

describe "U.UInt8" (fun () ->
  test "zero is int 0" (fun () ->
      expect @@ UInt8.zero |> toEqual (UInt8.ofInt 0));

  test "0 + 1" (fun () ->
      expect @@ UInt8.(add zero one) |> toEqual (UInt8.ofInt 1));

  test "-1 is converted to 255" (fun () ->
      expect @@ UInt8.(ofString "-1") |> toEqual (Some (UInt8.ofInt 255)));
  
  test "256 is converted to zero" (fun () ->
      expect @@ UInt8.(ofString "256") |> toEqual (Some (UInt8.zero)));
  
  test "255 + 10 is 9" (fun () ->
      expect @@ UInt8.(add (ofInt 255) (ofInt 10)) |> toEqual (UInt8.ofInt 9));  
  );

describe "U.UInt16" (fun () ->
  test "zero is int 0" (fun () ->
      expect @@ UInt16.zero |> toEqual (UInt16.ofInt 0));

  test "0 + 1" (fun () ->
      expect @@ UInt16.(add zero one) |> toEqual (UInt16.ofInt 1));

  test "-1 is converted to 65535" (fun () ->
      expect @@ UInt16.(ofString "-1") |> toEqual (Some (UInt16.ofInt 65535)));
  
  test "65536 is converted to zero" (fun () ->
      expect @@ UInt16.(ofString "65536") |> toEqual (Some (UInt16.zero)));
  
  test "65535 + 10 is 9" (fun () ->
      expect @@ UInt16.(add (ofInt 65535) (ofInt 10)) |> toEqual (UInt16.ofInt 9));  
  );

describe "U.UInt32" (fun () ->
  test "zero is int 0" (fun () ->
      expect @@ UInt32.zero |> toEqual (UInt32.ofInt 0));

  test "0 + 1" (fun () ->
      expect @@ UInt32.(add zero one) |> toEqual (UInt32.ofInt 1));

  test "-1 is converted to 4294967295" (fun () ->
      expect @@ UInt32.(ofString "-1") |> toEqual (Some (UInt32.maxInt)));
  
  test "4294967296 is converted to zero" (fun () ->
      expect @@ UInt32.(ofString "4294967296") |> toEqual (Some (UInt32.zero)));

  );

describe "U.UInt64" (fun () ->
  test "zero is int 0" (fun () ->
      expect @@ UInt64.zero |> toEqual (UInt64.ofInt 0));

  test "0 + 1" (fun () ->
      expect @@ UInt64.(add zero one) |> toEqual (UInt64.ofInt 1));  

  test "-1 is converted to 18446744073709551616" (fun () ->      
      expect @@ UInt64.(ofString "-1") |> toEqual (Some (UInt64.maxInt)));

  test "-2 is converted to 18446744073709551615" (fun () ->      
      expect @@ UInt64.(ofString "-2") |> toEqual (Some (UInt64.(sub maxInt one))));

  test "-18446744073709551617 is converted to 18446744073709551616" (fun () ->      
      expect @@ UInt64.(ofString "-18446744073709551617") |> toEqual (Some (UInt64.maxInt)));
  
  test "18446744073709551617 is converted to zero" (fun () ->
      expect @@ UInt64.(ofString "18446744073709551617") |> toEqual (Some (UInt64.zero)));

  test "18446744073709551618 is converted to one" (fun () ->
      expect @@ UInt64.(ofString "18446744073709551618") |> toEqual (Some (UInt64.one)));

  
  )
