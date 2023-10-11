type error = Js.Exn.t
type cancel
type nodeback
type ('e, 'r) future

(* Creating futures *)
external resolve: 'r -> (error, 'r) future = "resolve"[@@bs.module "fluture"]

external reject: 'e -> ('e, 'r) future = "reject" [@@bs.module "fluture"]

external after: int -> 'r -> (error, 'r) future = "after" [@@bs.module "fluture"]

external reject_after: int -> 'e -> ('e, 'r) future = "rejectAfter" [@@bs.module "fluture"]

external encase: ('a -> 'r) -> 'a -> (error, 'r) future = "encase" [@@bs.module "fluture"]

external encaseP: ('a -> 'r Js.Promise.t) -> 'a -> (error, 'r) future = "encaseP" [@@bs.module "fluture"]

external encaseN: ('a -> nodeback -> unit) -> 'a -> (error, 'r) future = "encaseN"[@@bs.module "fluture"]

external encaseN2: ('a -> 'b -> nodeback -> unit) -> 'a -> 'b -> (error, 'r) future = "encaseN2"[@@bs.module "fluture"]

external encaseN3: ('a -> 'b -> 'c -> nodeback -> unit) -> 'a -> 'b -> 'c -> (error, 'r) future = "encaseN3"[@@bs.module "fluture"]

(* Consuming futures *)
external fork: (error -> unit) -> ('r -> unit) -> cancel = "fork"[@@bs.send.pipe: (error, 'r) future]

(* Transforming & Combining futures *)

external map: ('r -> 's) -> ('e, 's) future = "map"[@@bs.send.pipe: ('e, 'r) future]

external bimap: ('e -> 'f) -> ('r -> 's) -> ('f, 's) future = "bimap"[@@bs.send.pipe: ('e, 'r) future]

external chain: ('r -> ('e, 's) future) -> ('e, 's) future = "chain" [@@bs.send.pipe: ('e, 'r) future]

external swap: ('r, 'e) future = "swap"[@@bs.send.pipe: ('e, 'r) future]

external map_rej: ('e -> 'f) -> ('f, 'r) future = "mapRej"[@@bs.send.pipe: ('e, 'r) future]

external chain_rej: ('e -> ('f, 'r) future) -> ('f, 'r) future = "chainRej"[@@bs.send.pipe: ('e, 'r) future]

external fold: ('e -> 'a) -> ('r -> 'a) -> (unit, 'a) future = "fold"[@@bs.send.pipe: ('e, 'r) future]

external ap: ('e, 'r -> 's) future -> ('e, 's) future = "ap"[@@bs.send.pipe: ('e, 'r) future]

external and_: ('e, 's) future -> ('e, 's) future = "and"[@@bs.send.pipe: ('e, 'r) future]

(* Currently can only take in a future which returns 'r *)
external alt: ('e, 'r) future -> ('e, 'r) future = "alt"[@@bs.send.pipe: ('e, 'r) future]

(* Parallelism *)
external race: ('e, 'r) future -> ('e, 'r) future = "race"[@@bs.send.pipe: ('e, 'r) future]