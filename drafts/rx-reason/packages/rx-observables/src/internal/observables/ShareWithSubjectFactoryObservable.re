type multicastState('a) = {
  createSubject: unit => RxSubject.t('a),
  mutable refCount: int,
  source: RxObservable.t('a),
  mutable subject: RxSubject.t('a),
  subscription: RxSerialDisposable.t,
};

let teardown = state => {
  state.refCount = state.refCount - 1;

  if (state.refCount === 0) {
    state.subscription
    |> RxSerialDisposable.setInnerDisposable(RxDisposable.disposed);
    state.subject |> RxSubject.dispose;
    state.subject = RxSubject.disposed;
  };
};

let source = (state, subscriber) => {
  if (state.refCount === 0) {
    state.subject = state.createSubject();
  };

  state.refCount = state.refCount + 1;

  let innerSubscription =
    state.subject
    |> RxSubject.asObservable
    |> PublishToSubscriberObservable.create(subscriber)
    |> RxObservable.connect;

  subscriber
  |> RxSubscriber.addDisposable(RxDisposable.create1(teardown, state))
  |> RxSubscriber.addDisposable(innerSubscription)
  |> ignore;

  if (state.refCount === 1) {
    let subscriber =
      state.source
      |> PublishToSubjectObservable.create(state.subject)
      |> RxObservable.connect;

    state.subscription |> RxSerialDisposable.setInnerDisposable(subscriber);
  };
};

let create = (createSubject, observable) => {
  let state = {
    createSubject,
    refCount: 0,
    source: observable,
    subscription: RxSerialDisposable.create(),
    subject: RxSubject.disposed,
  };

  RxObservable.create1(source, state);
};