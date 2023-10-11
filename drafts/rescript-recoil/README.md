# rescript-recoil

![Node.js CI](https://github.com/bloodyowl/rescript-recoil/workflows/Node.js%20CI/badge.svg)

> Zero-cost bindings to Facebook's [Recoil](https://recoiljs.org) library

⚠️ These bindings are still in experimental stages, use with caution

## Installation

Run the following command:

```console
$ yarn add recoil rescript-recoil
```

Then add `rescript-recoil` to your `bsconfig.json`'s dependencies:

```diff
 {
   "bs-dependencies": [
+    "rescript-recoil"
   ]
 }
```

## Usage

### Atom

```rescript
let textState = Recoil.atom({
  key: "textState",
  default: "",
})
```

### Selector

A nice feature the OCaml type-system enables is the ability to differenciate Recoil values between the ones that can **only read state** with the ones that can **write state**. This way, you **can't** use hooks with write capabilities with a read-only value.

#### With read only capabilities

```rescript
let textStateSize = Recoil.selector({
  key: "textStateSize",
  get: ({get}) => {
    let textState = get(textState)
    Js.String.length(textState)
  },
})
```

#### With write capabilities

```rescript
let textStateSize = Recoil.selectorWithWrite({
  key: "textStateSize",
  get: ({get}) => {
    let textState = get(textState);
    Js.String.length(textState);
  },
  set: ({set}, newSize) => {
    let currentTextState = get(textState);
    set(textState, currentTextState->Js.String.slice(~from=0, ~to_=newSize));
  }
});
```

#### Async

```rescript
let user = Recoil.asyncSelector({
  key: "user",
  get: ({get}) => {
    fetchUser(get(currentUserId))
  },
})
```

### Hooks

#### `useRecoilState`

```rescript
let (state, setState) = Recoil.useRecoilState(textState);

state // read
setState(textState => newTextState) // write
```

#### `useRecoilValue`

```rescript
let state = Recoil.useRecoilValue(textState)

state // read
```

#### `useSetRecoilState`

```rescript
let setState = Recoil.useSetRecoilState(textState)

setState(textState => newTextState) // write
```

#### `useResetRecoilState`

```rescript
let reset = Recoil.useResetRecoilState(textState)

reset() // write
```

#### `useRecoilCallback`

- Dependency free (reevaluates the callback at every render): `useRecoilCallback(...)`
- Zero-dependency (never reevaluates the callback): `useRecoilCallback0(...)`
- One-dependency (reevaluates when dep changes): `useRecoilCallback1(..., [|dep|])`
- Multiple-dependencies: `useRecoilCallback2(..., (dep1, dep2))` (goes from 2 to 5)

```rescript
let onClick = Recoil.useRecoilCallback(({snapshot: {getPromise}}, event) => {
  let _ = getPromise(myAtom)
    |> Js.Promise.then_(value => {
      Js.log(value)
      Js.Promise.resolve()
    })
})

<button onClick={onClick}>
  {"Click me"->React.string}
</button>
```

#### `useRecoilValueLoadable`

```rescript
let loadable = Recoil.useRecoilValueLoadable(textState)

Js.log(loadable->Recoil.Loadable.state)
Js.log(loadable->Recoil.Loadable.getValue)
```

## Examples

The [Recoil Basic Tutorial](https://recoiljs.org/docs/basic-tutorial/intro) has been made in ReasonReact: [check the source](./examples/TodoList.re)!

You can run it using:

```console
$ yarn examples
```

and going to [http://localhost:8000/TodoList.html](http://localhost:8000/TodoList.html)

### Memoization

```rescript
type t = {
  id: string,
  value: string,
  isCompleted: bool,
}

// For atoms
let todoItemFamily = Recoil.atomFamily({
  key: "todo",
  default: param => {
    id: param,
    value: "",
    isCompleted: false,
  },
})

// For selectors
let todoItemLengthFamily = Recoil.selectorFamily({
  key: "todo",
  // The `Fn` wrapper is needed here so that BuckleScript
  // outputs the correct value
  get: param => Fn(({get}) => {
    get(todoItemFamily(param)).value->Js.String2.length
  }),
})
```

And use it within a React component:

```rescript
[@react.component]
let make = (~todoId) => {
  let (todo, setTodo) = Recoil.useRecoilState(todoItemFamily(id))

  // ...
  <>
    {todo.value->React.string}
  </>
}
```
