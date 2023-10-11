open Rx

(* OPERATOR: buffer *)
external buffer : 'a observable -> ('b, 'b array) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: bufferTime *)
external bufferTime : int -> 'a observable -> ('a, 'a array) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: bufferCount *)
external bufferCount : int -> ?startBuffer:int -> unit -> ('a , 'a array) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: bufferWhen *)
external bufferWhen : (unit -> 'b observable) -> ('a, 'a array) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: catchError *)
external catchError : ('err -> 'a observable -> 'b observable [@bs.uncurry]) -> ('a, 'b) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: combineAll *)
external combineAll : unit -> ('a observable, 'a array) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: concatAll *)
external concatAll : unit -> ('a observable, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

external concatAllPromises : unit -> ('a Js.Promise.t, 'a) operator = "concatAll"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: concatMap *)
external concatMap : ('a -> int -> 'b observable [@bs.uncurry]) -> ('a, 'b) operator = ""
  [@@bs.module "rxjs/operators"]

external concatMapArray : ('a -> int -> 'b array [@bs.uncurry]) -> ('a, 'b) operator = "concatMap"
  [@@bs.module "rxjs/operators"]

external concatMapPromise : ('a -> int -> 'b Js.Promise.t [@bs.uncurry]) ->  ('a, 'b) operator = "concatMap"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: concatMapTo *)
external concatMapTo : ('a observable) -> ('b, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

external concatMapToPromise : ('a Js.Promise.t) -> ('a, 'b) operator = "concatMapTo"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: count *)
external count : ?predicate:('a -> int -> 'a observable [@bs.uncurry]) -> ('a, int) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: debounce *)
external debounce : ('a -> 'b observable [@bs.uncurry]) -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

external debouncePromise : ('a -> 'b Js.Promise.t [@bs.uncurry]) -> ('a, 'a) operator = "debounce"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: debounceTime *)
external debounceTime : int -> ?scheduler:scheduler -> unit -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: defaultIfEmpty *)
(* Null values are not allowed and hence no default null value *)
external defaultIfEmpty : 'a -> unit -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: delay *)
external delay : int -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

external delayByDate : Js.Date.t -> ('a, 'a) operator = "delay"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: delayWhen *)
external delayWhen : ('a -> int -> 'any observable [@bs.uncurry]) -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

external delayWhenLazy : ('a -> int -> 'any observable [@bs.uncurry]) -> 'any observable -> ('a, 'a) operator = "delayWhen"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: distinct *)
(* Use map |> distinct for keySelector *)
external distinct : unit -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: distinctUntilChanged *)
external distinctUntilChanged : ?compare:('a -> 'a -> bool [@bs.uncurry]) -> unit -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: distinctUntilKeyChanged is not required *)
(* Use map and distinct instead *)

(* OPERATOR: elementAt *)
external elementAt : int -> ?default:'a -> unit -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: endWith *)
external endWith : 'a array -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"] [@@bs.variadic]

(* OPERATOR: every *)
external every : ('a -> int -> bool [@bs.uncurry]) -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: exhaust *)
(* No support for exhausting observable of array or promises *)
external exhaust : unit -> ('a observable, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: exhaustMap *)
external exhaustMap : ('a -> int -> 'b observable [@bs.uncurry]) -> ('a, 'b) operator = ""
  [@@bs.module "rxjs/operators"]

external exhaustMapArray : ('a -> int -> 'b array [@bs.uncurry]) -> ('a, 'b) operator = "exhaustMap"
  [@@bs.module "rxjs/operators"]

external exhaustMapPromise : ('a -> int -> 'b Js.Promise.t [@bs.uncurry]) ->  ('a, 'b) operator = "exhaustMap"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: filter *)
external filter : ('a -> bool [@bs.uncurry]) -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

external filteri : ('a -> int -> bool [@bs.uncurry]) -> ('a, 'a) operator = "filter"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: findIndex *)
external findIndex : ('a -> int -> 'a observable -> bool [@bs.uncurry]) -> ('a, int) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: isEmpty *)
external isEmpty : unit -> ('a, bool) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: map *)
external map : ('a -> 'b [@bs.uncurry]) -> ('a, 'b) operator = ""
  [@@bs.module "rxjs/operators"]

external mapi : ('a -> int -> 'b [@bs.uncurry]) -> ('a, 'b) operator = "map"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: max *)
external max : unit -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

external maxCustom : ('a -> 'a -> bool [@bs.uncurry]) -> ('a, 'a) operator = "max"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: mapTo *)
external mapTo : 'b -> ('a, 'b) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: mergeAll *)
external mergeAll : ?concurrent:int -> unit -> ('a observable, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: mergeMap *)
external mergeMap : ('a -> 'b observable [@bs.uncurry]) -> ('a, 'b) operator = ""
  [@@bs.module "rxjs/operators"]

external mergeMapArray : ('a -> 'b array [@bs.uncurry]) -> ('a, 'b) operator = "mergeMap"
  [@@bs.module "rxjs/operators"]

external mergeMapPromise : ('a -> 'b Js.Promise.t [@bs.uncurry]) ->  ('a, 'b) operator = "mergeMap"
  [@@bs.module "rxjs/operators"]

external mergeMapTo : 'b observable -> ?concurrent:int -> unit -> ('a, 'b) operator = ""
  [@@bs.module "rxjs/operators"]

external mergeMapToPromise : 'b Js.Promise.t -> ?concurrent:int -> unit -> ('a, 'b) operator = "mergeMapTo"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: min *)
external min : unit -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

external minCustom : ('a -> 'a -> bool [@bs.uncurry]) -> ('a, 'a) operator = "min"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: pairwise *)
external pairwise : unit -> ('a, ('a * 'a)) operator = ""
  [@@bs.module "rxjs/operators"]


(* OPERATOR: reduce *)
external reduce : ('acc -> 'a -> int -> 'acc [@bs.uncurry]) -> 'acc -> ('a, 'acc) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: refCount *)
external refCount : unit -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: repeat *)
external _repeat : ?count:int -> unit -> ('a, 'a) operator = "repeat"
  [@@bs.module "rxjs/operators"]

let repeat ?(count = -1) stream = _repeat ~count () stream

(* OPERATOR: retry *)
external retry : ?count:int -> unit -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: retryWhen *)
external retryWhen : (Js.Exn.t observable -> 'b observable) -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: sample *)
external sample : 'any observable -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: sampleTime *)
external sampleTime : int -> ?scheduler:scheduler -> unit -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: scan *)
external scan : ('acc -> 'a -> int -> 'acc [@bs.uncurry]) -> 'acc -> ('a, 'acc) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: share *)
external share : unit -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: skip *)
external skip : int -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: skipLast *)
external skipLast : int -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: skipUntil *)
external skipUntil : 'any observable -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: skipWhile *)
external skipWhile : ('a -> int -> bool [@bs.uncurry]) -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: switchMap *)
external switchMap : ('a -> 'b observable [@bs.uncurry]) -> ('a, 'b) operator = ""
  [@@bs.module "rxjs/operators"]

external switchMapArray : ('a -> 'b array [@bs.uncurry]) -> ('a, 'b) operator = "switchMap"
  [@@bs.module "rxjs/operators"]

external switchMapPromise : ('a -> ('b, 'e) Js.promise [@bs.uncurry]) -> ('a, 'b) operator = "switchMap"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: take *)
external take : int -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: takeLast *)
external takeLast : int -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: takeUntil *)
external takeUntil : 'any observable -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: takeWhite *)
external takeWhile : ('a -> int -> bool [@bs.uncurry]) -> ?inclusive:bool -> unit -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

(* OPERATOR: tap *)
external tap : ('a -> unit) -> ('a, 'a) operator = ""
  [@@bs.module "rxjs/operators"]

external tapO : ('a observer) -> ('a, 'a) operator = "tap"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: timeout *)
external timeout : int -> ('a, 'a) operator = "timeout"
  [@@bs.module "rxjs/operators"]

external timeoutByDate : Js.Date.t -> ('a, 'a) operator = "timeout"
  [@@bs.module "rxjs/operators"]

(* OPERATOR: withLatestFrom *)
external withLatestFrom2 :
  'b observable
    -> ('a, ('a * 'b)) operator = "withLatestFrom"
  [@@bs.module "rxjs/operators"]

external withLatestFrom3 :
  'b observable
    -> 'c observable -> ('a, ('a * 'b * 'c)) operator = "withLatestFrom"
  [@@bs.module "rxjs/operators"]

external withLatestFrom4 :
  'b observable -> 'c observable -> 'd observable
    -> ('a, ('a * 'b * 'c * 'd)) operator = "withLatestFrom"
  [@@bs.module "rxjs/operators"]

external withLatestFrom5 :
  'b observable -> 'c observable -> 'd observable -> 'e observable
    -> ('a, ('a * 'b * 'c * 'd * 'e)) operator = "withLatestFrom"
  [@@bs.module "rxjs/operators"]

external withLatestFrom6 :
  'b observable -> 'c observable -> 'd observable -> 'e observable -> 'f observable
    -> ('a, ('a * 'b * 'c * 'd * 'e * 'f)) operator = "withLatestFrom"
  [@@bs.module "rxjs/operators"]


(* Dependent Operators *)

(* OPERATOR: find *)
(* Find depends on map operator *)
external _find : ('a -> int -> 'a observable -> bool [@bs.uncurry]) -> ('a, 'a Js.Undefined.t) operator = "find"
  [@@bs.module "rxjs/operators"]

let find predicate source = source |> _find predicate |> map Js.Undefined.toOption
