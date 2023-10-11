type t = {
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

let make ?(suspense = false) ?(revalidateOnFocus = true)
    ?(revalidateOnReconnect = true) ?(revalidateOnMount = false)
    ?(refreshInterval = 0) ?(refreshWhenHidden = false)
    ?(refreshWhenOffline = false) ?(shouldRetryOnError = true)
    ?(dedupingInterval = 2000) ?(focusThrottleInterval = 5000)
    ?(loadingTimeout = 3000) ?(errorRetryInterval = 5000)
    ?errorRetryCount () =
  {
    errorRetryInterval = Some errorRetryInterval;
    errorRetryCount;
    loadingTimeout = Some loadingTimeout;
    focusThrottleInterval = Some focusThrottleInterval;
    dedupingInterval = Some dedupingInterval;
    refreshInterval = Some refreshInterval;
    refreshWhenHidden = Some refreshWhenHidden;
    refreshWhenOffline = Some refreshWhenOffline;
    revalidateOnFocus = Some revalidateOnFocus;
    revalidateOnMount= Some revalidateOnMount;
    revalidateOnReconnect = Some revalidateOnReconnect;
    shouldRetryOnError = Some shouldRetryOnError;
    suspense = Some suspense;
  }

let default = make ()

let to_configInterface ?initialData ?onLoadingSlow ?onSuccess ?onError
    ?onErrorRetry ?compare
    {
      errorRetryInterval;
      errorRetryCount;
      loadingTimeout;
      focusThrottleInterval;
      dedupingInterval;
      refreshInterval;
      refreshWhenHidden;
      refreshWhenOffline;
      revalidateOnFocus;
      revalidateOnMount;
      revalidateOnReconnect;
      shouldRetryOnError;
      suspense;
    } =
  Swr_raw.configInterface ?errorRetryInterval ?errorRetryCount ?loadingTimeout
    ?focusThrottleInterval ?dedupingInterval ?refreshInterval ?refreshWhenHidden
    ?refreshWhenOffline ?revalidateOnFocus ?revalidateOnReconnect ?revalidateOnMount
    ?shouldRetryOnError ?suspense ?initialData ?onLoadingSlow ?onSuccess
    ?onError ?onErrorRetry ?compare ()
