type 'a t

(* Creation functions *)
external lst   : 'a array -> 'a t             = "list"   [@@bs.module "list"] [@@bs.variadic]

external empty : unit -> 'a t                 = "empty"  [@@bs.module "list"]

external of_   : 'a -> 'a t                   = "of"     [@@bs.module "list"]

external pair  : 'a -> 'a -> 'a t             = "pair"   [@@bs.module "list"]

external range : int -> int -> int list       = "range"  [@@bs.module "list"]

external repeat: 'a -> int -> 'a t            = "repeat" [@@bs.module "list"]

external init  : f:(int -> 'a) -> int -> 'a t = "times"  [@@bs.module "list"]

(* Accessors , this is where we sorely miss pattern matching *)
external head: 'a t -> 'a option        = "head" [@@bs.module "list"]

external tail: 'a t -> 'a t             = "tail" [@@bs.module "list"]

external last: 'a t -> 'a option        = "last" [@@bs.module "list"]

external nth : int -> 'a t -> 'a option = "nth"  [@@bs.module "list"]

(* Basics *)
external length    : 'a t -> int                                  = "length"     [@@bs.module "list"]

external equal     : 'a t -> 'a t -> bool                         = "equals"     [@@bs.module "list"]

external equal_with: f:('a -> 'a -> bool) -> 'a t -> 'a t -> bool = "equalsWith" [@@bs.module "list"]

external to_array  : 'a t -> 'a Js.Array.t                        = "toArray"    [@@bs.module "list"]

(* Folds *)
external foldl: f:('a -> 'b -> 'b) -> 'b -> 'a t -> 'b   = "foldl" [@@bs.module "list"]
let reduce                                               = foldl

external foldr: f:('a -> 'b -> 'b) -> 'a t -> 'b         = "foldr" [@@bs.module "list"]
let reduce_right                                         = foldr

external scan : f:('a -> 'b -> 'b) -> 'b -> 'a t -> 'b t = "scan"  [@@bs.module "list"]

(* Searching *)
external find       : f:('a -> bool) -> 'a t -> 'a option = "find"      [@@bs.module "list"]

external find_last  : f:('a -> bool) -> 'a t -> 'a option = "findLast"  [@@bs.module "list"]

external _find_index: f:('a -> bool) -> 'a t -> int       = "findIndex" [@@bs.module "list"]
let find_index: f:('a -> bool) -> 'a t -> int option = 
  fun ~f l -> let i = _find_index f l in if i <> -1 then Some i else None

(* Misc *)
external contains: 'a -> 'a t -> bool = "contains" [@@bs.module "list"]
let includes = contains


(* Transforming/Updating lists *)
external concat     : 'a t -> 'a t -> 'a t         = "concat"      [@@bs.module "list"]

external flatten    : ('a t) t -> 'a t             = "flatten"     [@@bs.module "list"]

external prepend    : 'a -> 'a t -> 'a t           = "prepend"     [@@bs.module "list"]

external append     : 'a -> 'a t -> 'a t           = "append"      [@@bs.module "list"]

external intersperse: 'a -> 'a t -> 'a t           = "intersperse" [@@bs.module "list"]

external map        : f:('a -> 'b) -> 'a t -> 'b t = "map"         [@@bs.module "list"]

(* pluck *)

(* Need to throw if Index out of bounds *)
external update           : int -> 'a -> 'a t -> 'a t                  = "update"          [@@bs.module "list"]

external adjust           : int -> f:('a -> 'a) -> 'a t -> 'a t        = "adjust"          [@@bs.module "list"]

external slice            : int -> int -> 'a t -> 'a t                 = "slice"           [@@bs.module "list"]

external take             : int -> 'a t -> 'a t                        = "take"            [@@bs.module "list"]

external take_while       : f:('a -> bool) -> 'a t -> 'a t             = "takeWhile"       [@@bs.module "list"]

external take_last        : int -> 'a t -> 'a t                        = "takeLast"        [@@bs.module "list"]

external take_last_while  : f:('a -> bool) -> 'a t -> 'a t             = "takeLastWhile"   [@@bs.module "list"]

external split_at         : int -> 'a t -> 'a t * 'a t                 = "splitAt"         [@@bs.module "list"]

external split_when       : f:('a -> bool) -> 'a t -> 'a t * 'a t      = "splitWhen"       [@@bs.module "list"]

external remove           : int -> int -> 'a t -> 'a t                 = "remove"          [@@bs.module "list"]

external drop             : int -> 'a t -> 'a t                        = "drop"            [@@bs.module "list"]

external drop_while       : f:('a -> bool) -> 'a t -> 'a t             = "dropWhile"       [@@bs.module "list"]

external drop_last        : int -> 'a t -> 'a t                        = "dropLast"        [@@bs.module "list"]

external drop_repeats     : 'a t -> 'a t                               = "dropRepeats"     [@@bs.module "list"]

external drop_repeats_with: f:('a -> 'a -> bool) -> 'a t -> 'a t       = "dropRepeatsWith" [@@bs.module "list"]


external pop              : 'a t -> 'a t                               = "pop"             [@@bs.module "list"]

external filter           : f:('a -> bool) -> 'a t -> 'a t             = "filter"          [@@bs.module "list"]

external reject           : f:('a -> bool) -> 'a t -> 'a t             = "reject"          [@@bs.module "list"]

external reverse          : 'a t -> 'a t                               = "reverse"         [@@bs.module "list"]

external ap               : ('a -> 'b) t -> 'a t -> 'b t               = "ap"              [@@bs.module "list"]

external chain            : ('a -> 'b t) t -> 'a t -> 'b t             = "chain"           [@@bs.module "list"]

external partition        : f:('a -> bool) -> 'a t -> 'a t * 'a t      = "partition"       [@@bs.module "list"]

external insert           : int -> 'a -> 'a t -> 'a t                  = "insert"          [@@bs.module "list"]

external insert_all       : int -> 'a t -> 'a t -> 'a t                = "insert_all"      [@@bs.module "list"]

external zip_with         : f:('a -> 'b -> 'c) -> 'a t -> 'b t -> 'c t = "zipWith"         [@@bs.module "list"]

external zip              : 'a t -> 'b t -> ('a * 'b) t                = "zip"             [@@bs.module "list"]

(* Be careful with this one, cannot sort arbitraty values. 'a should be comparable with '<' in JS world*)
external sort: 'a t -> 'a t = "sort" [@@bs.module "list"]

(* 'b should be comparable with '<' in JS world *)
external sort_by: f:('a -> 'b) -> 'a t -> 'a t = "sortBy" [@@bs.module "list"]

(* f should return either -1, 0 or 1, this is the safest to use among the sorting functions *)
external sort_with: f:('a -> 'a -> int) -> 'a t -> 'a t = "sortWith" [@@bs.module "list"]