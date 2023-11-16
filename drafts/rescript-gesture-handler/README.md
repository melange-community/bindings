# `rescript-gesture-handler`

ReScript bindings for `react-native-gesture-handler`.

`rescript-gesture-handler` `x.y.*` means it's compatible with `react-native-gesture-handler` `x.y.*`

**NOTE:** `v2` isn't backwards compatible with `v1`, even though original `react-native-gesture-handler` is. Mainly because I believe they will be dropping support for it in the near future (they already warn you if you are using `v1` API).

## Status

Work in progress.

### v1 (See `v1.10.0` branch)

**NOTE:** There won't be any progress with `v1` until `v2` is finished.

- [x] `FlingGestureHandler`
- [ ] `PanGestureHandler`
- [ ] ...

### v2

- [x] `Fling`
- [x] `Pan`
- [ ] `Pinch`
- [ ] `Force`
- [ ] ...

## Installation

### v1

```
npm install rescript-gesture-handler@1.10.0
# or
yarn add rescript-gesture-handler@1.10.0
```

### v2

```
npm install rescript-gesture-handler
# or
yarn add rescript-gesture-handler
```

## Example (v2)

### Fling

```res
open Directions
let flingGesture =
    Gesture.makeFling()
    ->Fling.direction(Direction.make(directions.left))
    ->Fling.onEnd((_event, _success) => ResAnimated.runOnJS(__someFunction__)(.))
```
