# bs-rx
ReasonML/Bucklescript bindings for Rx.js

## Design goals
  - Prefer **reverse-application operator** `|>` over **fast-pipe** `|.`. More about this [here](https://github.com/BuckleScript/bucklescript/issues/2625).
  - Exclude support for deprecated functionality like `ResultSelector` in most higher order function.
  - Favor type-safety over generic functions like tuple based `zip2`, `zip3` instead of array based `zip`.
  - Exclude un-necessary operators which do not make sense in OCaml like `pluck`. Also do not support something like `null` in case of `defaultIfEmpty` operator.
  - There is a good chance that schedulars might be **dropped** or **changed** in future versions of Rx.js. Avoid them. [Read here](https://github.com/ReactiveX/rxjs/issues/2935).
  - Provide support for Promises for most commonly required operators like `switchMap`, `forkJoin`, etc.

## Documentation
Complete documentation coming soon. For now, find examples in `test/` directory.

To understand annotations/extensions in OCaml/ReasonML, [read this note](./Annotations.md).