# ⚡️🔗 [Hyperactiv](https://github.com/elbywan/hyperactiv) bindings for [ReScript](https://rescript-lang.org/)

## Installation

```sh
npm i rescript-hyperactiv
```

## Usage

```rescript
type store = {mutable counter: int}

let logHandler = Hyperactiv.Handlers.debugger(%raw("console"))

let store = {
  open Hyperactiv
  let storeRef = React.makeStore({counter: 0})
  let store = storeRef->unwrap
  computed(() => {
    store.counter = store.counter > 0 ? store.counter + 1 : store.counter
  })->ignore
  Handlers.set(storeRef, logHandler)
  store
}

let classStore = {
  open Hyperactiv.Classes
  let storeRef = make({counter: 0})
  storeRef->computed(@this this => this.counter = this.counter * 2)
  storeRef->onChange(logHandler)
  storeRef->unwrap
}

module Root = {
  @react.component
  let make = Hyperactiv.React.watch(() => {
    <>
      <h1> {React.int(store.counter)} </h1>
      <h2> {React.int(classStore.counter)} </h2>
      <button
        onClick={_ => {
          store.counter = store.counter + 1
          classStore.counter = classStore.counter + 1
        }}>
        {React.string("Click me")}
      </button>
    </>
  })
}

switch ReactDOM.querySelector("#root") {
| Some(root) => ReactDOM.render(<Root />, root)
| None => ()
}
```