# rescript-geojson

Simple GeoJSON decoder library for ReScript based on @glennsl/rescript-json-combinators.


## Example

```rescript
let json = %raw(`{
    type: 'Feature',
    geometry: {
        type: 'Polygon',
        coordinates: [
            [
                [-180.0, 10.0],
                [20.0, 90.0],
                [180.0, -5.0],
                [-30.0, -90.0],
            ],
        ],
    },
    properties: null,
}`)

switch json->Json.decode(GeoJSON.Decode.object) {
| Ok(Feature({geometry: Polygon({coordinates})})) => Js.log2("Polygon coordinates: ", coordinates)
| Ok(_) => Js.log("not a feature with polygon?!")
| Error(err) => Js.log(err)
}
```


## Installation

```sh
npm install --save @glennsl/rescript-geojson
```

Then add `@glennsl/rescript-geosjon` to `bs-dependencies` in your `bsconfig.json`:

```diff
 {
   "bs-dependencies": [
+    "@glennsl/rescript-geojson"
   ]
 }
```


## License

This work is dual-licensed under [LGPL 3.0](https://choosealicense.com/licenses/lgpl-3.0/) and 
[MPL 2.0](https://choosealicense.com/licenses/mpl-2.0/). You can choose between one of them if you use this work.

Please see [LICENSE.LGPL-3.0](https://github.com/glennsl/rescript-json-combinators/blob/master/LICENSE.LGPL-3.0) and 
[LICENSE.MPL-2.0](https://github.com/glennsl/rescript-json-combinators/blob/master/LICENSE.MPL-2.0) for the full text of each license.

`SPDX-License-Identifier: LGPL-3.0 OR MPL-2.0`


## Changes

### 1.0.0
Initial release
