let create = (predicate, observable) =>
  observable |> RxObservable.lift(KeepOperator.create(predicate));

let create1 = (predicate, ctx0, observable) =>
  observable |> RxObservable.lift(KeepOperator.create1(predicate, ctx0));

let create2 = (predicate, ctx0, ctx1, observable) =>
  observable
  |> RxObservable.lift(KeepOperator.create2(predicate, ctx0, ctx1));

let create3 = (predicate, ctx0, ctx1, ctx2, observable) =>
  observable
  |> RxObservable.lift(KeepOperator.create3(predicate, ctx0, ctx1, ctx2));