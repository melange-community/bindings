open Jest
open Expect

let () =
  describe "Intl.PluralRules.supportedLocalesOf" (fun () ->
    test "it shows all the supported locales for the given list" (fun () ->
      expect (Intl.PluralRules.supportedLocalesOf [|"ban"; "id-u-co-pinyin"; "de-ID"|] ())
      |> toEqual [|"id-u-co-pinyin"; "de-ID"|]));

  describe "Intl.PluralRules.select" (fun () ->
    test "it builds a formatted number" (fun () ->
      let pr = Intl.PluralRules.make ~locales:[|"ar"|] () in
      expect (Intl.PluralRules.select pr 5.0) |> toEqual "few"));