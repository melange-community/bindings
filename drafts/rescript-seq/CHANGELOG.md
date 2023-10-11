## Version 2.0.0

- Fixed
  - `Seq.filterMap` didn't work with nested options
  - `Seq.tail` was not completely lazy
  - `Seq.drop` was not completely lazy
  - `Seq.findMap` didn't work with nested options
  - `Seq.replicate` and `Seq.replicateWith` argument order was not data-first
- Add
  - `Seq.append` as synonym for `concat`
  - `Seq.dropLast`
  - `Seq.findLast`
  - `Seq.findMapLast`
  - `Seq.neighbors`
  - `Seq.onceWith`
  - `Seq.pairAhead`
  - `Seq.pairBehind`
  - `Seq.prefixSum` (like `scan` but does not take an initial parameter)
  - `Seq.reduceUntil` to short-circuit a reduce operation
  - `Seq.reduceWhile` to short-circuit a reduce operation
  - `Seq.split` to split adjacent items and then reduce the groups
  - `Seq.sumBy` (like `Seq.reduce` but no initial parameter)
  - `Seq.tails`
  - `Seq.toList`
- Rename
  - `repeat` to `replicate`; more like other Seq libraries
  - `InvalidArgument` exception not `ArgumentOfOfRange` (spelled wrong)
  - `Seq.takeAtMost` to `Seq.take`
  - `Seq.every` not `Seq.everyOrEmpty`; less cumbersome and more like array
  - `Seq.everyOk` not `Seq.allSome` (using `every` not `forAll`)
  - `Seq.everySome` not `Seq.allSome` (using `every` not `forAll`)
  - `Seq.join` like `Array.join` rather than `Seq.joinString`. Also require a separator character.
  - `Seq.uncons` rather than `Seq.headTail`; less cumbersome, more consistent
  - `Seq.once` not `Seq.singleton`; like Rust
  - `Array.exactlyOne` not `Array.exactlyOneValue` like `Seq.exactlyOne`
  - `Array.of1` not `Array.fromOneValue`
- Remove
  - `Seq.windowAhead` and `Seq.windowBehind`; tricky code here. It worked but not sure it is useful enough. `windowAhead` would hang if window size was enormous; fixed that before removing it.
  - `Seq.findMapi`
  - `Seq.fromOption`; not sure this will get used
  - `Seq.characters`; many ways to split a string and with Core it will feel better since you can do `String.split` not `Js.String2.split`.
  - `Seq.startWith` and `Seq.endWith`; use `concat` and `prepend` with `Seq.once`.
  - `Seq.scani`; just call `indexed` beforehand if index is needed.
  - `Seq.reducei`; just call `indexed` beforehand if index is needed.
- Other
  - Cleanup lots of code

## Version 1.1.1

- Fix bug in `Seq.take` where generator function was called 1 too many times; not lazy enough
- `Seq.combinations`
- `Seq.permutations`

## Version 1.1.0

- Fix bug in `allPairs` where sequences are not cached.
- `Seq.reverse`
- `Seq.sortBy`
- `Seq.delay`

## Version 1.0.0

- Add `Seq` module
