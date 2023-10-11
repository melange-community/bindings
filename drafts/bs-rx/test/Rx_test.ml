open Jest

open Rx
open Operators

external makeObs : 'any -> 'a observer = "%identity"

let oneObs = create (fun obs ->
  next obs 10;
  complete obs
)

let twoObs = create (fun obs ->
  next obs 100;
  next obs 200;
  complete obs
)

let _ = describe "Static function: create" begin fun () ->
  let open Expect in

  test "Sample test" (fun ()  -> expect (1 + 2) |> (toBe 3));

  testAsync "Rx.create - Create observable using static method" begin fun finish  ->
    let obs = create (fun obs ->
      next obs 20;
      complete obs
    ) in

    subscribe obs (fun value -> expect value |> toBe 20 |> finish) |> ignore
  end;
end

let _ = describe "Static operator: combineLatest" begin fun () ->
  let open Expect in

  testAsync "combineLatest2" begin fun finish ->
    let testObs = combineLatest2 twoObs oneObs in

    subscribe testObs (fun value ->
      expect value |> toEqual (200, 10) |> finish) |> ignore
  end;

  testAsync "combineLatest6" begin fun finish ->
    let testObs = combineLatest6 oneObs oneObs oneObs oneObs oneObs oneObs in

    subscribe testObs (fun value ->
      expect value |> toEqual (10, 10, 10, 10, 10, 10) |> finish) |> ignore
  end;

end

let _ = describe "Static operator: forkJoin" begin fun () ->
  let open Expect in

  testAsync "forkJoin2" begin fun finish ->

    let testObs = forkJoin2 oneObs twoObs in

    subscribe testObs (fun value ->
      expect value |> toEqual (10, 200) |> finish) |> ignore
  end;

  testAsync "forkJoin4" (fun finish ->

    let testObs = forkJoin4 twoObs twoObs twoObs twoObs in

    subscribe testObs (fun value ->
      expect value |> toEqual (200, 200, 200, 200) |> finish) |> ignore
  );

end

let _ = describe "Static operator: zip" begin fun () ->

  let open Expect in

  testAsync "zip2" begin fun finish ->

    let testObs = zip2 oneObs twoObs in

    let _sub = subscribe testObs (fun value ->
      expect value |> toEqual (10, 100) |> finish) in

    ignore()
  end;

  testAsync "zip5" begin fun finish ->

    let testObs = zip5 twoObs twoObs twoObs twoObs twoObs |> takeLast 1 in

    let _sub = subscribe testObs (fun value ->
      expect value |> toEqual (200, 200, 200, 200, 200) |> finish) in

    ignore()
  end;

end

let _ = describe "Static operators" begin fun () ->
  let open Expect in

  let test_fromArray finish =
    let array = [| 10; 20 |] in
    let testObs = array
      |> fromArray |> reduce (fun acc next _i -> Array.append acc [| next |]) [||] in

    subscribe testObs (fun value ->
      Expect.expect value |> Expect.toEqual array |> finish) |> ignore in

  testAsync "concat" begin fun finish ->
    let testObs = concat [| oneObs; twoObs; oneObs |]
      |> reduce (fun acc n _i -> Array.append acc [| n |]) [||] in

    subscribe testObs (fun value ->
      expect value |> toEqual [| 10; 100; 200; 10 |] |> finish) |> ignore
  end;

  testAsync "defer" ~timeout:100 begin fun finish ->
    let testObs = defer (fun () -> oneObs) in

    subscribe testObs (fun value ->
      expect value |> toBe 10 |> finish) |> ignore
  end;

  testAsync "deferArray" ~timeout:100 begin fun finish ->
    let testObs = deferArray (fun () -> [| 20 |]) in

    subscribe testObs (fun value ->
      expect value |> toBe 20 |> finish) |> ignore
  end;

  testAsync "empty" begin fun finish ->

    let observer = makeObs([%bs.obj {
      next = (fun _val -> finish (fail "Should expect no value") |> ignore);
      complete = (fun () -> ignore(finish pass))
    }]) in

    subscribeObs empty observer |> ignore
  end;

  testAsync "fromArray" test_fromArray;

  testAsync "interval" ~timeout:1000 begin fun finish ->

    let testObs = interval 100 |> take 1 in

    subscribe testObs (fun value ->
      expect value |> toBe 0 |> finish) |> ignore
  end;

  testAsync "merge" begin fun finish ->

    let testObs = merge [| oneObs; twoObs |]
      |> reduce (fun acc next _i -> next :: acc) [] in

    subscribe testObs (fun value ->
      expect value |> toEqual [ 200; 100; 10] |> finish) |> ignore
  end;

  testAsync "never" ~timeout:1000 begin fun finish ->

    let observer = makeObs([%bs.obj {
      next = (fun _val -> finish (fail "Should expect no value"));
      error = (fun () -> finish pass)
    }]) in
    let testObs = never |> timeout 100 in

    subscribeObs testObs observer |> ignore
  end;

  testAsync "off" begin fun finish ->

    let testObs = off [| 10 |] in

    subscribe testObs (fun value ->
      expect value |> toBe 10 |> finish) |> ignore
  end;

  testAsync "race" begin fun finish ->

    let delayedObs = delay 100 oneObs in
    let testObs = race [| delayedObs; twoObs |] |> take 1 in

    subscribe testObs (fun value ->
      expect value |> toBe 100 |> finish) |> ignore
  end;

  (* Range not working without count *)
  testAsync "range" begin fun finish ->

    let testObs = range 10 ~count:1 () () in

    subscribe testObs (fun value ->
      expect value |> toBe 10 |> finish) |> ignore
  end;

  testAsync "timer" ~timeout:1000 begin fun finish ->

    let testObs = timer 100 100 |> take 2 |> takeLast 1 in

    subscribe testObs (fun value ->
      expect value |> toBe 1 |> finish) |> ignore
  end;

end

