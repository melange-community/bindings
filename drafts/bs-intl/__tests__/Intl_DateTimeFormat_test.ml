open Jest
open Expect

let () =
  describe "Intl.DateTimeFormat.supportedLocalesOf" (fun () ->
    test "it shows all the supported locales for the given list" (fun () ->
      expect (Intl.DateTimeFormat.supportedLocalesOf [|"ban"; "id-u-co-pinyin"; "de-ID"|] ())
      |> toEqual [|"id-u-co-pinyin"; "de-ID"|]));

  describe "Intl.DateTimeFormat.resolvedOptions" (fun () ->
    test "it shows all the configured options for the given formatter" (fun () ->
      let dt = Intl.DateTimeFormat.make ~locales:[|"de-DE"|] ~localeMatcher:BestFit ~weekday:Long () in
      match Intl.DateTimeFormat.resolvedOptions dt with
      | { calendar = calendar; _ } -> expect calendar |> toEqual (Some "gregory")));

  describe "Intl.DateTimeFormat.format" (fun () ->
    test "it builds a formatted date string" (fun () ->
      let dt = Intl.DateTimeFormat.make ~locales:[|"fr"|] ~day:Numeric ~month:Long () in
      expect (Intl.DateTimeFormat.format dt (Js.Date.makeWithYMD ~year:2019.0 ~month:6.0 ~date:22.0 ()))
      |> toEqual "22 juillet"));

  describe "Intl.DateTimeFormat.formatToParts" (fun () ->
    test "it builds an array of parts to make a formatted date string" (fun () ->
      let dt = Intl.DateTimeFormat.make ~locales:[|"zh-CN"|] ~era:Long ~year:Numeric () in
      let expected: Intl.DateTimeFormat.part array = [|
        { type_ = Era; value = {js|公元|js}; };
        { type_ = Year; value = "2019"; };
        { type_ = Literal; value = {js|年|js}; };
      |] in
      expect (Intl.DateTimeFormat.formatToParts dt (Js.Date.makeWithYMD ~year:2019.0 ~month:6.0 ~date:22.0 ()))
      |> toEqual expected))