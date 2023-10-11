# Lazy Sequences for ReScript

A _sequence_ is a list whose elements are computed only on demand, similar to [JavaScript iterables](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Iteration_protocols). Sequences are produced and transformed lazily (one element at a time) rather than eagerly (all at once). This allows constructing conceptually infinite sequences. When your data is an `array`, call `fromArray` to create a sequence, which is just a lightweight function that iterates over its values. And then you can use the sequence functions to analyze and transform it with far more flexibility and power than what is possible with the built-in array functions. Sequences can sometimes provide better performance than an `array` when not all elements are used.

Sequences are in the **standard libraries** of [F#](https://fsharp.github.io/fsharp-core-docs/reference/fsharp-collections-seqmodule.html), [OCaml](https://v2.ocaml.org/api/Seq.html), [Rust](https://doc.rust-lang.org/std/iter/trait.Iterator.html), [.net](https://learn.microsoft.com/en-us/dotnet/api/system.collections.generic.ienumerable-1?view=net-8.0), [Haskell](https://hackage.haskell.org/package/base-4.18.0.0/docs/Data-List.html), and [Python](https://docs.python.org/3/library/itertools.html). There are [JavaScript libraries](https://www.npmjs.com/package/itertools) to consume iterables, and a [Stage 3 TC39 proposal](https://github.com/tc39/proposal-iterator-helpers) to add iterator helpers.

**This is a full-featured package to create and consume sequences in ReScript.** Highlights:

- Enables more elegant and concise solutions than using imperative code and arrays
- [100+ functions](#functions), chosen by researching the best from other libraries
- API documentation
- Comprehensive test suite
- Written 100% in ReScript; look at the code and tests to see how it works.
- **Create sequences** with `fromArray`, `range`, `unfold`, `cycle`, `permutations`, `replicate`, ...
- **Transform** with `map`, `filter`, `split`, `takeUntil`, `scan`, `tap`, `pairwise`...
- **Combine** with `zip`, `map3`, `allPairs`, `sortedMerge`, `interleave`...
- **Calculate** with `reduceUntil`, `maxBy`, `every`, `findMap`, `isSortedBy`, `toArray`...

See [code examples](src/Seq__SeqSamples.res).

## To install

```sh
npm install @jmagaram/rescript-seq
```

Add to your `bsconfig.json`...

```diff
{
  ...
+ "bs-dependencies": ["@jmagaram/rescript-seq"]
}
```

All functions are in the `Seq` module. See other [examples](src/Seq__SeqSamples.res).

```rescript
  ["a", "b", "c", "d"]
  ->Seq.fromArray
  ->Seq.combinations(3)
  ->Seq.map(((_, combo)) => combo->Seq.join(""))
  ->Seq.join(", ")
  ->Js.log // a, b, ba, c, ca, cb, cba, d, da, db, dba, dc, dca, dcb
```

## Functions

```rescript
type t<'a> // A lazy sequence of 'a

// Construct

let combinations: (t<'a>, int) => t<(int, t<'a>)>
let cons: ('a, t<'a>) => t<'a>
let cycle: t<'a> => t<'a>
let delay: (unit => t<'a>) => t<'a>
let empty: t<'a>
let forever: 'a => t<'a>
let foreverWith: (unit => 'a) => t<'a>
let fromArray: (~start: int=?, ~end: int=?, array<'a>) => t<'a>
let fromList: list<'a> => t<'a>
let init: (int, int => 'a) => t<'a>
let iterate: ('a, 'a => 'a) => t<'a>
let once: 'a => t<'a>
let onceWith: (unit => 'a) => t<'a>
let permutations: (t<'a>, int) => t<(int, t<'a>)>
let range: (int, int) => t<int>
let rangeMap: (int, int, int => 'a) => t<'a>
let replicate: ('a, int) => t<'a>
let replicateWith: (unit => 'a, int) => t<'a>
let unfold: ('a, 'a => option<('b, 'a)>) => t<'b>

// Transform

let cache: t<'a> => t<'a>
let chunkBySize: (t<'a>, int) => t<array<'a>>
let drop: (t<'a>, int) => t<'a>
let dropLast: (t<'a>, int) => t<'a>
let dropUntil: (t<'a>, 'a => bool) => t<'a>
let dropWhile: (t<'a>, 'a => bool) => t<'a>
let filter: (t<'a>, 'a => bool) => t<'a>
let filteri: (t<'a>, ('a, int) => bool) => t<'a>
let filterMap: (t<'a>, 'a => option<'b>) => t<'b>
let filterMapi: (t<'a>, ('a, int) => option<'b>) => t<'b>
let filterOk: t<result<'a, 'b>> => t<'a>
let filterSome: t<option<'a>> => t<'a>
let flatMap: (t<'a>, 'a => t<'b>) => t<'b>
let flatten: t<t<'a>> => t<'a>
let indexed: t<'a> => t<('a, int)>
let intersperse: (t<'a>, 'a) => t<'a>
let intersperseWith: (t<'a>, unit => 'a) => t<'a>
let map: (t<'a>, 'a => 'b) => t<'b>
let mapi: (t<'a>, ('a, int) => 'b) => t<'b>
let neighbors: t<'a> => t<(option<'a>, 'a, option<'a>)>
let pairAhead: t<'a> => t<('a, option<'a>)>
let pairBehind: t<'a> => t<(option<'a>, 'a)>
let pairwise: t<'a> => t<('a, 'a)>
let prefixSum: (t<'a>, ('a, 'a) => 'a) => t<'a>
let reverse: t<'a> => t<'a>
let scan: (t<'a>, 'b, ('b, 'a) => 'b) => t<'b>
let sortBy: (t<'a>, ('a, 'a) => int) => t<'a>
let split: (t<'a>, 'a => 'b, ('b, 'a) => option<'b>) => t<'b>
let tail: t<'a> => t<'a>
let tails: t<'a> => t<t<'a>>
let take: (t<'a>, int) => t<'a>
let takeUntil: (t<'a>, 'a => bool) => t<'a>
let takeWhile: (t<'a>, 'a => bool) => t<'a>
let tap: (t<'a>, 'a => unit) => t<'a>
let window: (t<'a>, int) => t<array<'a>>

// Combine

let allPairs: (t<'a>, t<'b>) => t<('a, 'b)>
let append: (t<'a>, t<'a>) => t<'a>
let concat: (t<'a>, t<'a>) => t<'a>
let interleave: (t<'a>, t<'a>) => t<'a>
let map2: (t<'a>, t<'b>, ('a, 'b) => 'c) => t<'c>
let map3: (t<'a>, t<'b>, t<'c>, ('a, 'b, 'c) => 'd) => t<'d>
let map4: (t<'a>, t<'b>, t<'c>, t<'d>, ('a, 'b, 'c, 'd) => 'e) => t<'e>
let map5: (t<'a>, t<'b>, t<'c>, t<'d>, t<'e>, ('a, 'b, 'c, 'd, 'e) => 'f) => t<'f>
let orElse: (t<'a>, t<'a>) => t<'a>
let prepend: (t<'a>, t<'a>) => t<'a>
let sortedMerge: (t<'a>, t<'a>, ('a, 'a) => int) => t<'a>
let zip: (t<'a>, t<'b>) => t<('a, 'b)>
let zip3: (t<'a>, t<'b>, t<'c>) => t<('a, 'b, 'c)>
let zip4: (t<'a>, t<'b>, t<'c>, t<'d>) => t<('a, 'b, 'c, 'd)>
let zip5: (t<'a>, t<'b>, t<'c>, t<'d>, t<'e>) => t<('a, 'b, 'c, 'd, 'e)>

// Reduce, consume, and calculate

let compare: (t<'a>, t<'b>, ('a, 'b) => int) => int
let consume: t<'a> => unit
let equals: (t<'a>, t<'b>, ('a, 'b) => bool) => bool
let every: (t<'a>, 'a => bool) => bool
let everyOk: t<result<'a, 'b>> => result<t<'a>, 'b>
let everySome: t<option<'a>> => option<t<'a>>
let exactlyOne: t<'a> => option<'a>
let find: (t<'a>, 'a => bool) => option<'a>
let findLast: (t<'a>, 'a => bool) => option<'a>
let findMap: (t<'a>, 'a => option<'b>) => option<'b>
let findMapLast: (t<'a>, 'a => option<'b>) => option<'b>
let forEach: (t<'a>, 'a => unit) => unit
let forEachi: (t<'a>, ('a, int) => unit) => unit
let head: t<'a> => option<'a>
let isEmpty: t<'a> => bool
let isSortedBy: (t<'a>, ('a, 'a) => int) => bool
let join: t<string> => string
let last: t<'a> => option<'a>
let length: t<'a> => int
let maxBy: (t<'a>, ('a, 'a) => int) => option<'a>
let minBy: (t<'a>, ('a, 'a) => int) => option<'a>
let reduce: (t<'a>, 'b, ('b, 'a) => 'b) => 'b
let reduceUntil: (t<'a>, 'b, ('b, 'a) => 'b, 'b => bool) => 'b
let reduceWhile: (t<'a>, 'b, ('b, 'a) => 'b, 'b => bool) => option<'b>
let some: (t<'a>, 'a => bool) => bool
let sumBy: (t<'a>, ('a, 'a) => 'a) => option<'a>
let toArray: t<'a> => array<'a>
let toList: t<'a> => list<'a>
let toOption: t<'a> => option<t<'a>>
let uncons: t<'a> => option<('a, t<'a>)>
```
