open Jest

open Rx
open Operators

let oneObs = create (fun obs ->
  next obs 10;
  complete obs
)

let twoObs = create (fun obs ->
  next obs 100;
  next obs 200;
  complete obs
)

let _ = describe "Operators" begin fun () ->

  let open Expect in

  testAsync "map" begin fun finish ->

    let testObs = oneObs |> map (fun x -> x + 10) in

    subscribe testObs (fun value ->
      expect value |> toBe 20 |> finish) |> ignore
  end;

  testAsync "mapTo" begin fun finish ->

    let testObs = oneObs |> mapTo 20 in

    subscribe testObs (fun value ->
      expect value |> toBe 20 |> finish) |> ignore;
  end;

end