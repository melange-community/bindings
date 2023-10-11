@ocaml.doc(
  "`useRef(value)` returns a reference initially containing `value` that will persisit across renders and not trigger a re-render when updated."
)
let useRef: 'value => ref<'value>

@ocaml.doc(
  "`useRefLazy(() => value)` returns a reference initially containing `value` that will persisit across renders and not trigger a re-render when updated."
)
let useRefLazy: (unit => 'value) => ref<'value>

@ocaml.doc(
  "`useState(value)` returns `value` initially and an update function that will change the value returned and trigger a re-render."
)
let useState: 'state => ('state, ('state => 'state) => unit)

@ocaml.doc(
  "`useState(() => value)` returns `value` initially and an update function that will change the value returned and trigger a re-render."
)
let useStateLazy: (unit => 'state) => ('state, ('state => 'state) => unit)

@ocaml.doc(
  "`useReducer(~initial, reducer)` returns `initial` initially and a dispatch function that will call `reducer` to update the state and then trigger a re-render."
)
let useReducer: (~initial: 'state, ('state, 'action) => 'state) => ('state, 'action => unit)

@ocaml.doc(
  "`useReducerLazy(~init=() => value, reducer)` returns `value` initially and a dispatch function that will call `reducer` to update the state and then trigger a re-render."
)
let useReducerLazy: (
  ~init: unit => 'state,
  ('state, 'action) => 'state,
) => ('state, 'action => unit)

@ocaml.doc(`
  \`useEffect(~on=state, f)\` will call \`f\` on first render and then every time \`state\` changes structurally.

  It also takes the following optional arguments:
  - \`~cleanup\` takes a function that will be called before every subsequent call to \`f\` and on unmount.
  - \`~beforeRender\` when set will trigger the effect after render, rather than before.
  - \`~equal\` allows a custom equality function to be used to test whether \`state\` has changed and should re-trigger the effect.
`)
let useEffect: (
  ~on: 'deps,
  ~equal: ('deps, 'deps) => bool=?,
  ~beforeRender: bool=?,
  ~cleanup: unit => unit=?,
  unit => unit,
) => unit
@ocaml.doc(`
  \`useEffectOnce(f)\` will call \`f\` on first render only.

  It also takes the following optional arguments:
  - \`~cleanup\` takes a function that will be called on unmount.
  - \`~beforeRender\` when set will trigger the effect after render, rather than before.
`)
let useEffectOnce: (~beforeRender: bool=?, ~cleanup: unit => unit=?, unit => unit) => unit

@ocaml.doc(`
  \`useEffectAlways(f)\` will call \`f\` on every render.

  It also takes the following optional arguments:
  - \`~cleanup\` takes a function that will be called before every subsequent call to \`f\` and on unmount.
  - \`~beforeRender\` when set will trigger the effect after render, rather than before.
`)
let useEffectAlways: (~beforeRender: bool=?, ~cleanup: unit => unit=?, unit => unit) => unit

@ocaml.doc(`
  \`useResource(~on=state, acquire, ~release)\` will call \`acquire\` on first render and then every time \`state\` changes structurally.
  The value returned by \`acquire\` will be passed to \`release\` before every subsequent call to \`acquire\` and on unmount.

  It also takes the following optional arguments:
  - \`~beforeRender\` when set will trigger the effect after render, rather than before.
  - \`~equal\` allows a custom equality function to be used to test whether \`state\` has changed and should re-trigger the effect.
`)
let useResource: (
  ~on: 'deps,
  ~equal: ('deps, 'deps) => bool=?,
  ~beforeRender: bool=?,
  ~release: 'resource => unit,
  unit => 'resource,
) => unit

@ocaml.doc(`
  \`useMemo(~on=state, () => value)\` will call computer \`value\` on first render and then every time \`state\` changes structurally,
  otherwise returning a memoized (cached) value.

  It also takes the following optional arguments:
  - \`~equal\` allows a custom equality function to be used to test whether \`state\` has changed and should trigger re-computation.
`)
let useMemo: (~on: 'deps, ~equal: ('deps, 'deps) => bool=?, unit => 'value) => 'value
