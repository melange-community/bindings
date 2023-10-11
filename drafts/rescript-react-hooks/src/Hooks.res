let useRef = initial => {
  let (state, _) = React.useState(() => ref(initial))
  state
}

let useRefLazy = init => {
  let (state, _) = React.useState(() => ref(init()))
  state
}

let useState = initial => React.useState(() => initial)
let useStateLazy = init => React.useState(init)
let useReducer = (~initial, reducer) => React.useReducer(reducer, initial)
let useReducerLazy = (~init, reducer) => React.useReducerWithMapState(reducer, (), init)

let useEffectOnce = (~beforeRender=false, ~cleanup=?, f) => {
  let f = () => {
    f()
    cleanup
  }
  beforeRender ? React.useEffect1(f, []) : React.useLayoutEffect1(f, [])
}

let useEffectAlways = (~beforeRender=false, ~cleanup=?, f) => {
  let f = () => {
    f()
    cleanup
  }
  beforeRender ? React.useEffect(f) : React.useLayoutEffect(f)
}

let useResource = (~on as deps, ~equal=(a, b) => a == b, ~beforeRender=?, ~release, acquire) => {
  let lastDeps = useRef(deps)
  let resource = useRef(None)

  let release = () => resource.contents->Belt.Option.forEach(release)
  let acquire = () => resource := Some(acquire())

  useEffectOnce(~beforeRender?, acquire, ~cleanup=release)

  let update = () => {
    if !equal(deps, lastDeps.contents) {
      lastDeps := deps
      release()
      acquire()
    }
  }

  useEffectAlways(~beforeRender?, update)
}

let useEffect = (~on, ~equal=?, ~beforeRender=?, ~cleanup=() => (), f) =>
  useResource(~beforeRender?, ~on, ~equal?, ~release=cleanup, f)

let useMemo = (~on as deps, ~equal=(a, b) => a == b, f) => {
  let last_deps = useRef(deps)
  let value = useRefLazy(() => f())
  if !equal(deps, last_deps.contents) {
    last_deps := deps
    value := f()
  }
  value.contents
}
