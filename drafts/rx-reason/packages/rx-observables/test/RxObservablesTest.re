open ReUnit.Test;

let test =
  describe(
    "RxObservables",
    [
      CombineLatest2Test.test,
      ConcatListTest.test,
      DebounceTimeTest.test,
      DefaultIfEmptyTest.test,
      DeferTest.test,
      DistinctUntilChangedTest.test,
      EveryTest.test,
      ExhaustTest.test,
      FindTest.test,
      FirstTest.test,
      FirstOrNoneTest.test,
      IgnoreElementsTest.test,
      IsEmptyTest.test,
      KeepTest.test,
      LastTest.test,
      LastOrNoneTest.test,
      MapTest.test,
      MapToTest.test,
      MaybeFirstTest.test,
      MaybeLastTest.test,
      MergeListTest.test,
      OnCompleteTest.test,
      OnNextTest.test,
      RetryTest.test,
      ScanTest.test,
      ShareReplayBufferTest.test,
      SomeTest.test,
      StartWithListTest.test,
      StartWithValueTest.test,
      SwitchTest.test,
      TakeTest.test,
      TakeUntilTest.test,
      TimeoutTest.test,
      WithLatestFromTest.test,
    ],
  );