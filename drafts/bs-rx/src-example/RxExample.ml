open Rx
open Operators

let stream1 = create (fun obs -> ignore(next obs 20))
let stream2 = create (fun obs -> ignore(next obs "Hello world"))

let subscription1 = subscribe stream1 begin
    fun myVal -> ignore(myVal)
  end

let x = map (fun item -> item + 20) stream1

let b1 = bufferCount 4 ~startBuffer:10 () stream1
let b2 = bufferCount 4 () stream1

let s1 = scan (fun _acc nextVal _index -> nextVal) 10 stream1

let wLF1 = withLatestFrom2 stream1 stream2

external scheduler : scheduler = "" [@@bs.val]
(* external observer1 : 'any observer = "" [@@bs.val]
let subscription2 = subscribeObs stream1 observer1 *)

(* let _ = unsubscribe subscription1 *)


let mapped = map (fun item -> item + 4)

let opr1 = map (fun item -> item + 5)
let _ = catchError (fun _err _caught -> stream1)

type data = [ `Int of int  | `Str of string ]

let stream11 : data observable = map (fun x -> `Int x) stream1
let stream22 : data observable = stream2 |> map (fun x -> `Str x)

let combined = combineLatest2 stream1 stream2

let merged2 = merge [| stream1; empty; |]

let merged = merge [| stream11; stream22 |]
  |> map begin
      fun x -> match x with
        | `Int v -> v
        | `Str v -> int_of_string(v)
    end

let mergedAll = off [| stream1 |] |> mergeAll ~concurrent:10 ()

let y1 = opr1 stream1
  |> mapi (fun item index -> item + index + 4)
  |> map begin fun x -> x + 5 end
  |> switchMap (fun _x -> stream1)
  |> switchMapArray (fun _ -> [| 10 |])
  |> filteri (fun _x _y -> false)
  |> debounceTime 1000 ~scheduler ()
  |> debounceTime 100 ()
  |> catchError (fun _err _caught -> stream1)
  |> take 100
  |> withLatestFrom2 stream1
  |> withLatestFrom3 stream1 stream1
  |> withLatestFrom4 stream1 stream1 stream1
  |> withLatestFrom5 stream1 stream1 stream1 stream1
  |> mergeMap (fun _x -> stream1)
  |> mergeMapArray (fun _x -> [| 10; 20 |])
  |> distinctUntilChanged ()
  |> distinctUntilChanged ~compare:(fun _x _y -> true) ()
  |> elementAt 0 ()
  |> elementAt 100 ~default:10 ()
  |> scan (fun _acc nextVal _index -> nextVal) 10
  |> map begin fun _x -> stream1 end
  |> takeLast 5
  |> takeWhile (fun _x _i -> true) ()
  |> combineAll ()
  |> takeUntil stream1
  |> repeat ~count:10
  |> repeat
  |> tap (fun x -> ignore(x))
  |> retryWhen (fun _err -> stream1)
  |> retry ~count:10 ()
  |> sampleTime 100 ~scheduler:scheduler ()
  |> sample stream1

let y2 = stream1 |> mapTo 10

let range1 = range 1 () ()
let range2 = range 0 ~count:10 () ()
