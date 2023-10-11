open Jest;

module Helpers = {
  let noOp = (_) => ();
  let combineArray = (coll, el) => Js.Array.push(el, coll) |> noOp;
  let combineList = (collRef, el) => (collRef := [el, ...collRef^]) |> noOp;
  let asyncExpectToEqual = (expected, actual) =>
    Js.Promise.resolve(Expect.(expect(actual) |> toEqual(expected)));
};


/***
 * Stream creation
 **/
testPromise(
  "empty",
  (_) => {
    let empty = Most.empty();
    let success = (_) => Helpers.asyncExpectToEqual(true, true);
    Most.observe((_) => raise(Failure("this shouldn't happen")), empty)
    |> Js.Promise.then_(success)
  }
);

testAsync(
  "just",
  (done_) => {
    open Expect;
    let success = (result) => done_(expect(result) |> toBe("asdf"));
    Most.just("asdf") |> Most.observe(success) |> Helpers.noOp
  }
);

testPromise(
  "from",
  (_) => {
    let result = [||];
    let combine = Helpers.combineArray(result);
    let success = (_) => Helpers.asyncExpectToEqual([|1, 2|], result);
    Most.from([|1, 2|]) |> Most.observe(combine) |> Js.Promise.then_(success)
  }
);

testPromise(
  "fromPromise",
  (_) => {
    let promise = Js.Promise.resolve("OK");
    let result = ref("");
    let success = Helpers.asyncExpectToEqual("OK");
    Most.fromPromise(promise)
    |> Most.observe((res) => result := res)
    |> Js.Promise.then_((_) => success(result^))
  }
);

testPromise("periodic");

testPromise("never");

testPromise("iterate");

testPromise("iteratePromise");

testPromise("fromEvent");

testPromise(
  "concat",
  (_) => {
    let result = [||];
    let combine = Helpers.combineArray(result);
    let s1 = Most.from([|1, 2, 3|]);
    let s2 = Most.from([|4, 5, 6|]);
    let success = (_) => Helpers.asyncExpectToEqual([|1, 2, 3, 4, 5, 6|], result);
    Most.concat(s2, s1) |> Most.observe(combine) |> Js.Promise.then_(success)
  }
);

testPromise(
  "startWith",
  (_) => {
    let result = [||];
    let combine = Helpers.combineArray(result);
    let s = Most.from([|1, 2, 3|]);
    let success = (_) => Helpers.asyncExpectToEqual([|0, 1, 2, 3|], result);
    Most.startWith(0, s) |> Most.observe(combine) |> Js.Promise.then_(success)
  }
);

testPromise(
  "unfold",
  (_) => {
    let result = ref([]);
    let combine = (el) => (result := [el, ...result^]) |> Helpers.noOp;
    let success = (_) => Helpers.asyncExpectToEqual([6, 4, 2], result^);
    Most.unfold(
      (seed) =>
        if (seed < 4) {
          let nextSeed = seed + 1;
          Some((seed * 2, nextSeed))
        } else {
          None
        },
      1
    )
    |> Most.observe(combine)
    |> Js.Promise.then_(success)
  }
);

testPromise(
  "fromList",
  (_) => {
    let result = ref([]);
    let combine = Helpers.combineList(result);
    /* combineList adds them to the list in reverse order */
    let success = (_) => Helpers.asyncExpectToEqual([3, 2, 1], result^);
    Most.fromList([1, 2, 3]) |> Most.observe(combine) |> Js.Promise.then_(success)
  }
);


/***
 * Error handling
 **/
testPromise("recoverWith");

testPromise("throwError");


/***
 * Transforming
 **/
testPromise(
  "map",
  (_) => {
    let result = [||];
    let combineResult = Helpers.combineArray(result);
    let success = (_) => Helpers.asyncExpectToEqual([|2, 4, 6|], result);
    Most.(
      from([|1, 2, 3|]) |> map((n) => n * 2) |> observe(combineResult) |> Js.Promise.then_(success)
    )
  }
);

testPromise(
  "constant",
  (_) => {
    let result = [||];
    let combine = Helpers.combineArray(result);
    let success = (_) => Helpers.asyncExpectToEqual([|10, 10, 10|], result);
    Most.from([|1, 2, 3|])
    |> Most.constant(10)
    |> Most.observe(combine)
    |> Js.Promise.then_(success)
  }
);

testPromise(
  "scan",
  (_) => {
    let result = [||];
    let combine = Helpers.combineArray(result);
    let success = (_) => Helpers.asyncExpectToEqual([|0, 1, 3, 6, 10|], result);
    Most.from([|1, 2, 3, 4|])
    |> Most.scan((accum, n) => accum + n, 0)
    |> Most.observe(combine)
    |> Js.Promise.then_(success)
  }
);

testPromise(
  "flatMap",
  (_) => {
    let result = [||];
    let combine = Helpers.combineArray(result);
    let success = (_) => Helpers.asyncExpectToEqual([|0, 1, 0, 2, 0, 3, 0, 4|], result);
    Most.from([|1, 2, 3, 4|])
    |> Most.flatMap((x) => Most.from([|0, x|]))
    |> Most.observe(combine)
    |> Js.Promise.then_(success)
  }
);

testPromise("continueWith");

testPromise("concatMap");

testPromise("ap");

testPromise("timestamp");

testPromise("tap");


/***
 * Filtering
 **/
testPromise(
  "filter",
  (_) =>
    Most.from([|1, 2, 3, 4, 5, 6|])
    |> Most.filter((n) => n mod 2 === 0)
    |> Most.reduce((acc, n) => [n, ...acc], [])
    |> Js.Promise.then_(
         (result) => Js.Promise.resolve(Expect.(expect(result) |> toEqual([6, 4, 2])))
       )
);

testPromise("skipRepeats");

testPromise("skipRepeatsWith");


/***
 * Slicing
 **/
testPromise(
  "slice",
  (_) =>
    Expect.(
      Most.(fromList([1, 2, 3, 4, 5, 6]) |> slice(2, 5) |> reduce((acc, n) => [n, ...acc], []))
      |> Js.Promise.(then_((result) => resolve(expect(result) |> toEqual([5, 4, 3]))))
    )
);

testPromise(
  "take",
  (_) =>
    Expect.(
      Most.(from([|1, 2, 3, 4, 5, 6|]) |> take(3) |> reduce((acc, n) => [n, ...acc], []))
      |> Js.Promise.(then_((result) => resolve(expect(result) |> toEqual([3, 2, 1]))))
    )
);

testPromise(
  "skip",
  (_) =>
    Expect.(
      Most.(from([|1, 2, 3, 4, 5, 6|]) |> skip(3) |> reduce((acc, n) => [n, ...acc], []))
      |> Js.Promise.(then_((result) => resolve(expect(result) |> toEqual([6, 5, 4]))))
    )
);

testPromise("takeWhile");

testPromise("skipWhile");

testPromise("skipAfter");

testPromise("until");

testPromise("since");

testPromise("during");


/***
 * Combining
 **/
type mT =
  | String(string)
  | Int(int);

testPromise(
  "merge",
  (_) => {
    open Most;
    let s1 = fromList([Int(1), Int(2), Int(3)]);
    let s2 = fromList([String("a"), String("b"), String("c")]);
    merge(s1, s2)
    |> reduce((acc, n) => [n, ...acc], [])
    |> Js.Promise.then_(
         (result) =>
           Js.Promise.resolve(
             Expect.expect(result)
             |> Expect.toEqual([String("c"), Int(3), String("b"), Int(2), String("a"), Int(1)])
           )
       )
  }
);

testPromise(
  "combine",
  (_) => {
    open Most;
    let s1 = fromList([Int(1), Int(2), Int(3)]);
    let s2 = fromList([String("a"), String("b"), String("c")]);
    let toTuple = (a, b) => (a, b);
    combine(toTuple, s1, s2)
    |> reduce((acc, n) => [n, ...acc], [])
    |> Js.Promise.(
         then_(
           (result) =>
             resolve(
               Expect.(
                 expect(result)
                 |> toEqual([
                      (Int(3), String("c")),
                      (Int(3), String("b")),
                      (Int(2), String("b")),
                      (Int(2), String("a")),
                      (Int(1), String("a"))
                    ])
               )
             )
         )
       )
  }
);

testPromise(
  "zip",
  (_) => {
    open Most;
    let s1 = fromList([Int(1), Int(2), Int(3)]);
    let s2 = fromList([String("a"), String("b"), String("c")]);
    let toTuple = (a, b) => (a, b);
    zip(toTuple, s1, s2)
    |> reduce((acc, n) => [n, ...acc], [])
    |> Js.Promise.(
         then_(
           (result) =>
             resolve(
               Expect.(
                 expect(result)
                 |> toEqual([(Int(3), String("c")), (Int(2), String("b")), (Int(1), String("a"))])
               )
             )
         )
       )
  }
);

testPromise(
  "sample1",
  (_) => {
    open Most;
    open Expect;
    let id = (x) => x;
    let sampler = periodic(100) |> take(10);
    let s = periodic(200) |> constant(2) |> startWith(1);
    sample1(id, sampler, s)
    |> reduce((acc, n) => [n, ...acc], [])
    |> Js.Promise.(
         then_((result) => resolve(expect(result) |> toEqual([2, 2, 2, 2, 2, 2, 2, 2, 2, 1])))
       )
  }
);

testPromise(
  "sample2",
  (_) => {
    open Most;
    open Expect;
    let add = (x, y) => x + y;
    let sampler = periodic(100) |> take(10);
    let s1 = periodic(200) |> constant(1) |> startWith(1);
    let s2 = periodic(300) |> constant(2);
    sample2(add, sampler, s1, s2)
    |> reduce((acc, n) => [n, ...acc], [])
    |> Js.Promise.(
         then_((result) => resolve(expect(result) |> toEqual([3, 3, 3, 3, 3, 3, 3, 3, 3, 3])))
       )
  }
);

testPromise("sample3");

testPromise("sample4");

testPromise("sample5");

testPromise("sample6");

testPromise("sampleWith");


/***
 * Combining higher-order streams
 **/
testPromise("switchLatest");

testPromise("join");

testPromise("mergeConcurrently");


/***
 * Awaiting promises
 **/
testPromise("awaitPromises");


/***
 * Rate limiting streams
 */
testPromise("debounce");

testPromise("throttle");


/***
 * Delaying streams
 **/
testPromise("delay");


/***
 * Sharing streams
 **/
testPromise("multicast");


/***
 * Subjects!
 **/
testPromise(
  "basic Subject",
  (_) => {
    open Most;
    open Expect;
    let subj = Subject.make();
    let stream = Subject.asStream(subj);
    let promise =
      reduce((acc, n) => [n, ...acc], [], stream)
      |> Js.Promise.then_((result) => Js.Promise.resolve(expect(result) |> toEqual([3, 2, 1])));
    Subject.next(1, subj);
    Subject.next(2, subj);
    Subject.next(3, subj);
    Subject.complete(subj);
    promise
  }
);
