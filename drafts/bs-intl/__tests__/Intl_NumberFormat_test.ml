open Jest
open Expect

let () =
  describe "Intl.NumberFormat.supportedLocalesOf" (fun () ->
    test "it shows all the supported locales for the given list" (fun () ->
      expect (Intl.NumberFormat.supportedLocalesOf [|"ban"; "id-u-co-pinyin"; "de-ID"|] ())
      |> toEqual [|"id-u-co-pinyin"; "de-ID"|]));

  describe "Intl.NumberFormat.format" (fun () ->
    test "it builds a formatted number" (fun () ->
      let nf = Intl.NumberFormat.make ~locales:[|"ar"|] ~style:(Currency { isoCode = "EGP"; display = None; }) () in
      expect (Intl.NumberFormat.format nf 56.9) |> toEqual {js|٥٦٫٩٠ ج.م.‏|js}));

  describe "Intl.NumberFormat.formatToParts" (fun () ->
    test "it builds an array of parts to make a formatted date string" (fun () ->
      let nf = Intl.NumberFormat.make
        ~locales:[|"es-ES"|]
        ~style:(Currency { isoCode = "EUR"; display = Some Symbol; })
        ~digits:(Insignificant({ integer = None; fraction = Some { minimum = Some 2; maximum = None }; }))
        () in
      let expected: Intl.NumberFormat.part array = [|
        { type_ = Integer; value = "2"; };
        { type_ = Group; value = "."; };
        { type_ = Integer; value = "000"; };
        { type_ = Group; value = "."; };
        { type_ = Integer; value = "000"; };
        { type_ = Decimal; value = ","; };
        { type_ = Fraction; value = "00"; };
        { type_ = Literal; value = {js| |js}; };
        { type_ = Currency; value = {js|€|js}; };
      |] in
      expect (Intl.NumberFormat.formatToParts nf 2000000.0) |> toEqual expected))