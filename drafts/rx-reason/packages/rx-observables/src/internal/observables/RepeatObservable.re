let defaultPredicate =
  fun
  | None => true
  | Some(_) => false;

let create = (~predicate=RxFunctions.alwaysTrue1) => {
  let predicate =
    predicate === RxFunctions.alwaysTrue1 ?
      defaultPredicate :
      (
        fun
        | None => predicate()
        | Some(_) => false
      );

  observable =>
    observable
    |> RxObservable.lift(RepeatOperator.create(predicate, observable));
};