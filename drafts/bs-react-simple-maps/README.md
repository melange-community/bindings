# bs-react-simple-maps

[BuckleScript](https://github.com/bucklescript/bucklescript) bindings for [react-simple-maps](https://github.com/zcreativelabs/react-simple-maps)

[![npm](https://img.shields.io/npm/v/bs-simple-maps.svg)](https://www.npmjs.com/package/bs-simple-maps)

## Installation

```sh
npm install --save bs-simple-maps
```

In your `bsconfig.json`, include `"bs-simple-maps"` in the `bs-dependencies`.

## Examples

```reason
<ComposableMap
  projectionConfig=(ComposableMap.projectionConfig(~scale=200, ()))
  width=1000
  height=600>
  <ZoomableGroup center=(0., 0.)>
    <Geographies geography="/examples/world-50m.json">
      (
        (geographies, projection) =>
          Array.map(
            geography =>
              <Geography
                key=(Geography.id(geography))
                geography
                projection
                style=(
                  Types.style(
                    ~default=ReactDOMRe.Style.make(~fill="#ECEFF1", ()),
                    (),
                  )
                )
              />,
            geographies,
          )
      )
    </Geographies>
  </ZoomableGroup>
</ComposableMap>
```

To run other examples:

```sh
npm run start
# and in a separate tab
npm run examples
# then open localhost:3000
```

* [Basic map](./examples/basic-map/basic_map.re)
* [Simple markers](./examples/simple-markers/simple_markers.re)

## Usage

The API follows [react-simple-maps](https://github.com/zcreativelabs/react-simple-maps) rather closely, with a few exceptions:

* `Marker` takes a prop `coordinates` instead of a nested `{marker: {coordinates}}` object.
* `Line` takes props `start` and `stop` instead of a nested `{line: {coordinates: {start, end}}}` object.

## Limitations

* `Geographies` only supports a `string` for its `geographies` (i.e. a JSON file path).
* `Geography` and `Marker` don't support any events yet.
* `ZoomableGlobe` is not supported yet.

## Development

```sh
npm run start
```

### Tests

There will be some tests using [bs-jest](https://github.com/BuckleTypes/bs-jest).

```sh
npm run test
```

For now, we just test by looking at the [examples](./examples).

## Thanks

These bindings started as a [joint effort](https://github.com/poeschko/dojo-europe) of [Ali](https://twitter.com/sharifsbeat), [Jan](https://twitter.com/poeschko), [Patrick](https://twitter.com/ryyppy), and [Timo](https://twitter.com/defuex) at the [Reason-Dojo](https://twitter.com/search?src=typd&q=%23ReasonDojo) organized by [Ben](https://twitter.com/bsansouci) and [Sean](https://twitter.com/sgrove).

Right now, there are similar (yet less complete) bindings published as [bs-react-simple-maps](https://www.npmjs.com/package/bs-react-simple-maps) maintained at [DeFuex's repo](https://github.com/defuex/bs-react-simple-maps). We will try to unify these in the future.
