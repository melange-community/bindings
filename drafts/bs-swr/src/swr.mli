module Options : sig
  type t = Swr_options.t = {
    errorRetryInterval: int option;
    errorRetryCount: int option;
    loadingTimeout: int option;
    focusThrottleInterval: int option;
    dedupingInterval: int option;
    refreshInterval: int option;
    refreshWhenHidden: bool option;
    refreshWhenOffline: bool option;
    revalidateOnFocus: bool option;
    revalidateOnMount: bool option;
    revalidateOnReconnect: bool option;
    shouldRetryOnError: bool option;
    suspense: bool option;
  }

  val make :
    ?suspense:bool ->
    ?revalidateOnFocus:bool ->
    ?revalidateOnReconnect:bool ->
    ?revalidateOnMount:bool ->
    ?refreshInterval:int ->
    ?refreshWhenHidden:bool ->
    ?refreshWhenOffline:bool ->
    ?shouldRetryOnError:bool ->
    ?dedupingInterval:int ->
    ?focusThrottleInterval:int ->
    ?loadingTimeout:int ->
    ?errorRetryInterval:int ->
    ?errorRetryCount:int ->
    unit ->
    t

  val default : t

  val to_configInterface :
    ?initialData:'a ->
    ?onLoadingSlow:('b -> ('b, 'a) Swr_raw.configInterface -> unit) ->
    ?onSuccess:('a -> 'b -> ('b, 'a) Swr_raw.configInterface -> unit) ->
    ?onError:
      (Js.Promise.error -> 'b -> ('b, 'a) Swr_raw.configInterface -> unit) ->
    ?onErrorRetry:
      (Js.Promise.error ->
      'b ->
      ('b, 'a) Swr_raw.configInterface ->
      Swr_raw.revalidateType ->
      Swr_raw.revalidateOptionInterface ->
      unit) ->
    ?compare:('a option -> 'a option -> bool) ->
    t ->
    ('b, 'a) Swr_raw.configInterface
end

type 'data bound_mutate =
  ?data:'data -> ?shouldRevalidate:bool -> unit -> 'data option Js.Promise.t

type 'data responseInterface = {
  data: 'data option;
  error: Js.Promise.error;
  revalidate: unit -> bool Js.Promise.t;
  mutate: 'data bound_mutate;
  isValidating: bool;
}

val useSWR :
  ?config:Options.t ->
  'key ->
  ('key -> 'data Js.Promise.t) ->
  'data responseInterface

val useSWR_string :
  string -> (string -> 'data Js.Promise.t) -> 'data responseInterface

val mutate :
  ?f:('key -> 'data Js.Promise.t) -> 'key -> 'data option Js.Promise.t
