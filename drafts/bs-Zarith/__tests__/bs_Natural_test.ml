open Jest
open Expect

let () = 

describe "Natural" (fun () ->
  test "zero equal to (Natural.ofInt 0)" (fun () ->
    expect @@ Some Natural.zero |> toEqual (Natural.ofInt 0));
                       
  test "one equal to (Natural.ofInt 1)" (fun () ->
    expect @@ Some Natural.one |> toEqual (Natural.ofInt 1));

  test "zero equal to (Natural.ofInt 0)" (fun () ->
    expect @@ Natural.zero |> toEqual (Natural.unsafeOfString "0"));

  test "ofInt on a negative number should throw an error" (fun () ->
    expect @@ Natural.ofInt (-1) |> toEqual None);

  test "ofInt64 on a negative number should throw an error" (fun () ->
    expect @@ Natural.ofInt64 (-1L) |> toEqual None);

  test "ofString on a negative number should throw an error" (fun () ->
    expect @@ Natural.ofString ("-100") |> toEqual None);
  
  test "unsafeOfInt on a negative number should throw an error" (fun () ->
    expect @@ (fun () -> Natural.(unsafeOfInt (-1))) |> toThrowException Natural.Underflow );
  
  test "one equal to (Natural.ofInt 1)" (fun () ->
    expect @@ Natural.one |> toEqual (Natural.unsafeOfString "1"));
                       
  test "2 + 1 = 3" (fun () ->                       
    expect @@ (Natural.add (Natural.unsafeOfInt 1) (Natural.unsafeOfInt 2)) |> toEqual (Natural.unsafeOfInt 3));
  
  test "0 + 0 = 0" (fun () ->    
    expect @@ Natural.(Natural.add zero zero) |> toEqual Natural.zero);
  
  test "unsafeOfString: 2 + 1 = 3" (fun () ->                       
      expect @@ Natural.(Natural.add (unsafeOfString "1") (unsafeOfString "2")) |> toEqual (Natural.unsafeOfInt 3));

  test "div" (fun () ->
    expect @@ Natural.(fdiv (unsafeOfInt (100)) (unsafeOfInt 40)) |> toEqual (Natural.unsafeOfInt 2));
  
  )
