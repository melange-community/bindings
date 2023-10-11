let concat: RxObservable.t(RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable which concatenates elements of each provided Observable
 * into a single sequence of elements without interleaving them.
 */
let concatList:
  (~scheduler: RxScheduler.t=?, list(RxObservable.t('a))) =>
  RxObservable.t('a);

let concatMap:
  ('a => RxObservable.t('b), RxObservable.t('a)) => RxObservable.t('b);

let concatMap1:
  (('ctx0, 'a) => RxObservable.t('b), 'ctx0, RxObservable.t('a)) =>
  RxObservable.t('b);

let concatMap2:
  (
    ('ctx0, 'ctx1, 'a) => RxObservable.t('b),
    'ctx0,
    'ctx1,
    RxObservable.t('a)
  ) =>
  RxObservable.t('b);

let concatMap3:
  (
    ('ctx0, 'ctx1, 'ctx2, 'a) => RxObservable.t('b),
    'ctx0,
    'ctx1,
    'ctx2,
    RxObservable.t('a)
  ) =>
  RxObservable.t('b);

let combineLatest2:
  (~selector: ('a, 'b) => 'c, RxObservable.t('a), RxObservable.t('b)) =>
  RxObservable.t('c);

/**
 * Returns an Observable which drops items from the source that
 * are followed by another item within a debounce duration
 * determined by the scheduler.
 */
let debounceTime:
  (~scheduler: RxScheduler.t, float, RxObservable.t('a)) =>
  RxObservable.t('a);

/**
 * Returns an Observable which emits a default value if the
 * source completes without producing any values.
 */
let defaultIfEmpty: ('a, RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable that calls an Observable factory to
 * create a new Observable for each subscription.
 */
let defer: (unit => RxObservable.t('a)) => RxObservable.t('a);
let defer1: ('ctx0 => RxObservable.t('a), 'ctx0) => RxObservable.t('a);
let defer2:
  (('ctx0, 'ctx1) => RxObservable.t('a), 'ctx0, 'ctx1) => RxObservable.t('a);
let defer3:
  (('ctx0, 'ctx1, 'ctx2) => RxObservable.t('a), 'ctx0, 'ctx1, 'ctx2) =>
  RxObservable.t('a);

let delay:
  (~scheduler: RxScheduler.t, float, RxObservable.t('a)) =>
  RxObservable.t('a);

let dematerialize:
  RxObservable.t(RxNotification.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable which emits items that are distinct from
 * their immediate predecessors based upon the provided
 * equality function. By default, reference equality is
 * used.
 */
let distinctUntilChanged:
  (~equals: ('a, 'a) => bool=?, RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable that emits no items and immediately completes.
 */
let empty: (~scheduler: RxScheduler.t=?, unit) => RxObservable.t('a);

/**
 * Returns an Observable that emits a single true value if all
 * items emitted by the source satisfy the predicate.
 *
 * Note: If the source completes before emitting any values,
 * completes with true.
 */
let every: ('a => bool, RxObservable.t('a)) => RxObservable.t(bool);

/**
 * Returns an Observable that flattens Observable items,
 * dropping inner Observables until the current inner
 * Observable completes. Also see: switch_
 */
let exhaust: RxObservable.t(RxObservable.t('a)) => RxObservable.t('a);

let exhaustMap:
  ('a => RxObservable.t('b), RxObservable.t('a)) => RxObservable.t('b);

let exhaustMap1:
  (('ctx0, 'a) => RxObservable.t('b), 'ctx0, RxObservable.t('a)) =>
  RxObservable.t('b);

let exhaustMap2:
  (
    ('ctx0, 'ctx1, 'a) => RxObservable.t('b),
    'ctx0,
    'ctx1,
    RxObservable.t('a)
  ) =>
  RxObservable.t('b);

let exhaustMap3:
  (
    ('ctx0, 'ctx1, 'ctx2, 'a) => RxObservable.t('b),
    'ctx0,
    'ctx1,
    'ctx2,
    RxObservable.t('a)
  ) =>
  RxObservable.t('b);

/**
 * Returns an Observable which emits the first observed item
 * from the source which satisfies the predicate.
 */
let find: ('a => bool, RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable which emits the first observed item
 * from the source or completes with EmptyException.
 */
let first: RxObservable.t('a) => RxObservable.t('a);

/**
 * Returns an Observable which emits Some of the first observed
 * item from the source or emits None.
 */
let firstOrNone: RxObservable.t('a) => RxObservable.t(option('a));

/**
 * Returns an Observable which drops all items from the source.
 */
let ignoreElements: RxObservable.t('a) => RxObservable.t('b);

/**
 * Returns an Observable which emits true if the source emits
 * no items. Otherwise it emits false.
 */
let isEmpty: RxObservable.t('a) => RxObservable.t(bool);

/**
 * Returns an Observable which only emits items from the source
 * which satisfy the predicate.
 */
let keep: ('a => bool, RxObservable.t('a)) => RxObservable.t('a);
let keep1:
  (('ctx0, 'a) => bool, 'ctx0, RxObservable.t('a)) => RxObservable.t('a);
let keep2:
  (('ctx0, 'ctx1, 'a) => bool, 'ctx0, 'ctx1, RxObservable.t('a)) =>
  RxObservable.t('a);
let keep3:
  (
    ('ctx0, 'ctx1, 'ctx2, 'a) => bool,
    'ctx0,
    'ctx1,
    'ctx2,
    RxObservable.t('a)
  ) =>
  RxObservable.t('a);

/**
 * Returns an Observable which emits the last observed item or
 * completes with EmptyException.
 */
let last: RxObservable.t('a) => RxObservable.t('a);

/**
 * Returns an Observable which emits Some of the last observed
 * item or emits None.
 */
let lastOrNone: RxObservable.t('a) => RxObservable.t(option('a));

/**
 * Returns an Observable which applies the specified function to
 * each item observed, emitting the result of the function application.
 */
let map: ('a => 'b, RxObservable.t('a)) => RxObservable.t('b);

let map1:
  (('ctx0, 'a) => 'b, 'ctx0, RxObservable.t('a)) => RxObservable.t('b);

let map2:
  (('ctx0, 'ctx1, 'a) => 'b, 'ctx0, 'ctx1, RxObservable.t('a)) =>
  RxObservable.t('b);

let map3:
  (
    ('ctx0, 'ctx1, 'ctx2, 'a) => 'b,
    'ctx0,
    'ctx1,
    'ctx2,
    RxObservable.t('a)
  ) =>
  RxObservable.t('b);

/**
 * Returns an Observable which emits the specified value for
 * each item emitted by the source.
 */
let mapTo: ('b, RxObservable.t('a)) => RxObservable.t('b);

/**
 * Returns an Observable which emits all notifications
 * as Notification instances.
 */
let materialize: RxObservable.t('a) => RxObservable.t(RxNotification.t('a));

/**
 * Returns an Observable which emits the first observed item, if present, and
 * completes.
 */
let maybeFirst: RxObservable.t('a) => RxObservable.t('a);

/**
 * Returns an Observable which emits the last observed item, if present, and
 * completes.
 */
let maybeLast: RxObservable.t('a) => RxObservable.t('a);

let merge:
  (
    ~maxBufferSize: int=?,
    ~maxConcurrency: int=?,
    RxObservable.t(RxObservable.t('a))
  ) =>
  RxObservable.t('a);

/**
 * Returns an Observable that merges items emitted by the source Observables,
 * interleaving the items emitted by each Observable.
 */
let mergeList:
  (
    ~scheduler: RxScheduler.t=?,
    ~maxConcurrency: int=?,
    list(RxObservable.t('a))
  ) =>
  RxObservable.t('a);

let mergeMap:
  (
    ~maxBufferSize: int=?,
    ~maxConcurrency: int=?,
    'a => RxObservable.t('b),
    RxObservable.t('a)
  ) =>
  RxObservable.t('b);

let mergeMap1:
  (
    ~maxBufferSize: int=?,
    ~maxConcurrency: int=?,
    ('ctx0, 'a) => RxObservable.t('b),
    'ctx0,
    RxObservable.t('a)
  ) =>
  RxObservable.t('b);

let mergeMap2:
  (
    ~maxBufferSize: int=?,
    ~maxConcurrency: int=?,
    ('ctx0, 'ctx1, 'a) => RxObservable.t('b),
    'ctx0,
    'ctx1,
    RxObservable.t('a)
  ) =>
  RxObservable.t('b);

let mergeMap3:
  (
    ~maxBufferSize: int=?,
    ~maxConcurrency: int=?,
    ('ctx0, 'ctx1, 'ctx2, 'a) => RxObservable.t('b),
    'ctx0,
    'ctx1,
    'ctx2,
    RxObservable.t('a)
  ) =>
  RxObservable.t('b);

/**
 * Returns an Observable which invokes side-effect functions on each
 * observed event and on completion.
 */
let observe:
  (
    ~onNext: 'a => unit,
    ~onComplete: option(exn) => unit,
    RxObservable.t('a)
  ) =>
  RxObservable.t('a);

/**
 * Returns an Observable which invokes side-effect functions on each
 * observed event and on completion.
 */
let observe1:
  (
    ~onNext: ('ctx0, 'a) => unit,
    ~onComplete: ('ctx0, option(exn)) => unit,
    'ctx0,
    RxObservable.t('a)
  ) =>
  RxObservable.t('a);

/**
 * Returns an Observable which invokes side-effect functions on each
 * observed event and on completion.
 */
let observe2:
  (
    ~onNext: ('ctx0, 'ctx1, 'a) => unit,
    ~onComplete: ('ctx0, 'ctx1, option(exn)) => unit,
    'ctx0,
    'ctx1,
    RxObservable.t('a)
  ) =>
  RxObservable.t('a);

/**
 * Returns an Observable which invokes side-effect functions on each
 * observed event and on completion.
 */
let observe3:
  (
    ~onNext: ('ctx0, 'ctx1, 'ctx2, 'a) => unit,
    ~onComplete: ('ctx0, 'ctx1, 'ctx2, option(exn)) => unit,
    'ctx0,
    'ctx1,
    'ctx2,
    RxObservable.t('a)
  ) =>
  RxObservable.t('a);

/**
 * Returns an Observable that emits a single true value if every
 * observed item fails to satisfy the predicate.
 *
 * Note: If the source completes before observing any values,
 * completes with true.
 */
let none: ('a => bool, RxObservable.t('a)) => RxObservable.t(bool);

/**
 * Returns an Observable which emits notifications on the specified scheduler. The default
 * buffer strategy is to throw, and default buffer size is unbound.
 */
let observeOn: (RxScheduler.t, RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable that emits the given items and then completes.
 */
let ofList: (~scheduler: RxScheduler.t=?, list('a)) => RxObservable.t('a);

/**
 * Returns an Observable which emits the specified notifications
 * using the supplied scheduler.
 */
let ofNotifications:
  (~scheduler: RxScheduler.t=?, list(RxNotification.t('a))) =>
  RxObservable.t('a);

/**
  * Returns an Observable that emits the given item and then completes.
  */
let ofValue: (~scheduler: RxScheduler.t=?, 'a) => RxObservable.t('a);

/**
 * Returns an Observable which invokes the side-effect function when it completes.
 */
let onComplete:
  (option(exn) => unit, RxObservable.t('a)) => RxObservable.t('a);
let onComplete1:
  (('ctx0, option(exn)) => unit, 'ctx0, RxObservable.t('a)) =>
  RxObservable.t('a);
let onComplete2:
  (('ctx0, 'ctx1, option(exn)) => unit, 'ctx0, 'ctx1, RxObservable.t('a)) =>
  RxObservable.t('a);

let onComplete3:
  (
    ('ctx0, 'ctx1, 'ctx2, option(exn)) => unit,
    'ctx0,
    'ctx1,
    'ctx2,
    RxObservable.t('a)
  ) =>
  RxObservable.t('a);

/**
 * Returns an Observable that mirrors the source Observable,
 * calling the specified function when subscribed to, and
 * disposing the returned Disposable when disposed.
 */
let onConnect:
  (unit => RxDisposable.t, RxObservable.t('a)) => RxObservable.t('a);

let onConnect1:
  ('ctx0 => RxDisposable.t, 'ctx0, RxObservable.t('a)) => RxObservable.t('a);

let onConnect2:
  (('ctx0, 'ctx1) => RxDisposable.t, 'ctx0, 'ctx1, RxObservable.t('a)) =>
  RxObservable.t('a);

let onConnect3:
  (
    ('ctx0, 'ctx1, 'ctx2) => RxDisposable.t,
    'ctx0,
    'ctx1,
    'ctx2,
    RxObservable.t('a)
  ) =>
  RxObservable.t('a);

/**
 * Returns an Observable which invokes the side-effect function
 * with each observed item.
 */
let onNext: ('a => unit, RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable which invokes the side-effect function
 * with each observed item.
 */
let onNext1:
  (('ctx0, 'a) => unit, 'ctx0, RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable which invokes the side-effect function
 * with each observed item.
 */
let onNext2:
  (('ctx0, 'ctx1, 'a) => unit, 'ctx0, 'ctx1, RxObservable.t('a)) =>
  RxObservable.t('a);

let onNext3:
  (
    ('ctx0, 'ctx1, 'ctx2, 'a) => unit,
    'ctx0,
    'ctx1,
    'ctx2,
    RxObservable.t('a)
  ) =>
  RxObservable.t('a);

/**
 * Returns an Observable which invokes the side-effect function
 * when an exception occurs.
 */
let onExn: (exn => unit, RxObservable.t('a)) => RxObservable.t('a);

let onExn1:
  (('ctx0, exn) => unit, 'ctx0, RxObservable.t('a)) => RxObservable.t('a);

let onExn2:
  (('ctx0, 'ctx1, exn) => unit, 'ctx0, 'ctx1, RxObservable.t('a)) =>
  RxObservable.t('a);

let onExn3:
  (
    ('ctx0, 'ctx1, 'ctx2, exn) => unit,
    'ctx0,
    'ctx1,
    'ctx2,
    RxObservable.t('a)
  ) =>
  RxObservable.t('a);

let publishToSubject:
  (RxSubject.t('a), RxObservable.t('a)) => RxObservable.t('a);

let publishToSubscriber:
  (RxSubscriber.t('a), RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable that completes with the specified exception
 * when subscribed to.
 */
let raise: (~scheduler: RxScheduler.t=?, exn) => RxObservable.t('a);

/**
 * Returns an Observable that mirrors the source Observable,
 * resubscribing to it if it completes and
 * the predicate returns true for that specific.
 */
let repeat:
  (~predicate: unit => bool=?, RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable that mirrors the source Observable,
 * resubscribing to it if it completes with an exception and
 * the predicate returns true for that specific exception.
 */
let retry:
  (~predicate: exn => bool=?, RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable which invokes the accumulator function
 * for each item observed from the source, emitting the intermediate
 * accumulated values. The first item emitted is the initial value.
 */
let scan:
  (('acc, 'a) => 'acc, 'acc, RxObservable.t('a)) => RxObservable.t('acc);

let skip: (int, RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable that emits a single true value if any
 * observed item satisfies the predicate.
 *
 * Note: If the source Observable complete before producing any values,
 * completes with false.
 */
let some: ('a => bool, RxObservable.t('a)) => RxObservable.t(bool);

/**
 * Returns a new MulticastObservable that shares a single subscription to the provided source Observable.
 */
let share: RxObservable.t('a) => RxObservable.t('a);

/**
 * Returns a new MulticastObservable that shares a single subscription to the provided source Observable.
 * In addition, it replays the last observed event each time it is subscribed to.
 */
let shareReplayLast: RxObservable.t('a) => RxObservable.t('a);

/**
 * Returns a new MulticastObservable that shares a single subscription to the provided source Observable.
 * In addition, it replays the last n events each time it is subscribed to.
 */
let shareReplayBuffer: (int, RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable that emits the specified items before it
 * begins to emit items emitted by the source Observable.
 */
let startWithList:
  (~scheduler: RxScheduler.t=?, list('a), RxObservable.t('a)) =>
  RxObservable.t('a);

/**
 * Returns an Observable that emits a specified item before it
 * begins to emit items emitted by the source Observable.
 */
let startWithValue:
  (~scheduler: RxScheduler.t=?, 'a, RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable which subscribes to the provided source Observable
 * on the specified scheduler.
 */
let subscribeOn:
  (~delay: float=?, RxScheduler.t, RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable that flattens Observable items,
 * unsubscribing from the observed inner Observable when the
 * next one is observed. Also see: exhaust.
 */
let switch_: RxObservable.t(RxObservable.t('a)) => RxObservable.t('a);

let switchMap:
  ('a => RxObservable.t('b), RxObservable.t('a)) => RxObservable.t('b);

let switchMap1:
  (('ctx0, 'a) => RxObservable.t('b), 'ctx0, RxObservable.t('a)) =>
  RxObservable.t('b);

let switchMap2:
  (
    ('ctx0, 'ctx1, 'a) => RxObservable.t('b),
    'ctx0,
    'ctx1,
    RxObservable.t('a)
  ) =>
  RxObservable.t('b);

let switchMap3:
  (
    ('ctx0, 'ctx1, 'ctx2, 'a) => RxObservable.t('b),
    'ctx0,
    'ctx1,
    'ctx2,
    RxObservable.t('a)
  ) =>
  RxObservable.t('b);

let take: (int, RxObservable.t('a)) => RxObservable.t('a);

let takeUntil:
  (RxObservable.t('b), RxObservable.t('a)) => RxObservable.t('a);

/**
 * Returns an Observable which completes with a TimeoutException if
 * no notifications are observed before a duration determined
 * by the scheduler.
 */
let timeout:
  (~scheduler: RxScheduler.t, float, RxObservable.t('a)) =>
  RxObservable.t('a);

let using:
  (
    ~createResource: unit => 'b,
    ~disposeResource: 'b => unit,
    'b => RxObservable.t('a)
  ) =>
  RxObservable.t('a);

let using1:
  (
    ~createResource: 'c => 'b,
    ~disposeResource: 'b => unit,
    'c,
    'b => RxObservable.t('a)
  ) =>
  RxObservable.t('a);

let using2:
  (
    ~createResource: ('c, 'd) => 'b,
    ~disposeResource: 'b => unit,
    'c,
    'd,
    'b => RxObservable.t('a)
  ) =>
  RxObservable.t('a);

/**
 * Returns an Observable that combines each observed item from the source with
 * the last observed item from the other Observable using the selector function.
 *
 * Note: Observed items from the source are ignored, if the other Observable
 * has not yet produced any values.
 */
let withLatestFrom:
  (~selector: ('a, 'b) => 'c, RxObservable.t('b), RxObservable.t('a)) =>
  RxObservable.t('c);