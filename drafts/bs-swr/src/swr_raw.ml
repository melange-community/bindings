type 'data bound_mutate =
  'data option -> bool option -> 'data option Js.Promise.t

type 'data responseInterface = {
  data: 'data option;
  error: Js.Promise.error;
  revalidate: unit -> bool Js.Promise.t;
  mutate: 'data bound_mutate;
  isValidating: bool;
}

type revalidateOptionInterface = { retryCount: int option; dedupe: bool option }

type revalidateType = revalidateOptionInterface -> bool Js.Promise.t

external fast_deep_equal : 'a -> 'a -> bool = "default"
  [@@bs.val] [@@bs.module "fast-deep-equal/es6"]

type ('key, 'data) configInterface = {
  (* Global options *)
  errorRetryInterval: int; [@bs.optional]
  errorRetryCount: int; [@bs.optional]
  loadingTimeout: int; [@bs.optional]
  focusThrottleInterval: int; [@bs.optional]
  dedupingInterval: int; [@bs.optional]
  refreshInterval: int; [@bs.optional]
  refreshWhenHidden: bool; [@bs.optional]
  refreshWhenOffline: bool; [@bs.optional]
  revalidateOnFocus: bool; [@bs.optional]
  revalidateOnMount: bool; [@bs.optional]
  revalidateOnReconnect: bool; [@bs.optional]
  shouldRetryOnError: bool; [@bs.optional]
  suspense: bool; [@bs.optional]
  initialData: 'data; [@bs.optional]
  onLoadingSlow: 'key -> ('key, 'data) configInterface -> unit; [@bs.optional]
  onSuccess: 'data -> 'key -> ('key, 'data) configInterface -> unit;
      [@bs.optional]
  onError: Js.Promise.error -> 'key -> ('key, 'data) configInterface -> unit;
      [@bs.optional]
  onErrorRetry:
    Js.Promise.error ->
    'key ->
    ('key, 'data) configInterface ->
    revalidateType ->
    revalidateOptionInterface ->
    unit;
      [@bs.optional]
  compare: 'data option -> 'data option -> bool; [@bs.optional]
}
[@@bs.deriving abstract]

external useSWR_string :
  string -> (string -> 'data Js.Promise.t) -> 'data responseInterface
  = "default"
  [@@bs.val] [@@bs.module "swr"]

external useSWR_string_config :
  string ->
  (string -> 'data Js.Promise.t) ->
  (string, 'data) configInterface ->
  'data responseInterface = "default"
  [@@bs.val] [@@bs.module "swr"]

(* array must be of length 1 *)
external useSWR1 :
  'param array -> ('param -> 'data Js.Promise.t) -> 'data responseInterface
  = "default"
  [@@bs.val] [@@bs.module "swr"]

(* array must be of length 1 *)
external useSWR1_config :
  'param array ->
  ('param -> 'data Js.Promise.t) ->
  ('param array, 'data) configInterface ->
  'data responseInterface = "default"
  [@@bs.val] [@@bs.module "swr"]

external useSWR2 :
  'a * 'b -> ('a -> 'b -> 'data Js.Promise.t) -> 'data responseInterface
  = "default"
  [@@bs.val] [@@bs.module "swr"]

external useSWR2_config :
  'a * 'b ->
  ('a -> 'b -> 'data Js.Promise.t) ->
  ('a * 'b, 'data) configInterface ->
  'data responseInterface = "default"
  [@@bs.val] [@@bs.module "swr"]

external mutate1_one_item_array : 'param array -> 'data option Js.Promise.t
  = "mutate"
  [@@bs.val] [@@bs.module "swr"]

external mutate2_one_item_array_fetcher :
  'param array -> ('param -> 'data Js.Promise.t) -> 'data option Js.Promise.t
  = "mutate"
  [@@bs.val] [@@bs.module "swr"]

external mutate2_shouldRevalidate : 'key -> bool -> 'data option Js.Promise.t
  = "mutate"
  [@@bs.val] [@@bs.module "swr"]
