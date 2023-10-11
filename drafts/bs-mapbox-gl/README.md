# bs-mapbox-gl

[![Build Status](https://img.shields.io/circleci/project/github/stepankuzmin/bs-mapbox-gl.svg?style=popout)](https://circleci.com/gh/stepankuzmin/bs-mapbox-gl)
![npm](https://img.shields.io/npm/v/bs-mapbox-gl.svg)

[BuckleScript](https://github.com/bloomberg/bucklescript) bindings for [Mapbox GL JS](https://github.com/mapbox/mapbox-gl-js).

[Mapbox GL JS](https://github.com/mapbox/mapbox-gl-js) is a JavaScript library that renders interactive maps from vector tiles and Mapbox styles using WebGL.

[<img width="981" alt="Mapbox GL gallery" src="https://raw.githubusercontent.com/mapbox/mapbox-gl-js/master/docs/pages/assets/gallery.png">](https://www.mapbox.com/gallery/)

## Status

This package is 🚧 WIP 🚧.

Feel free to create an issue or PR if you find anything missing.

## Installation

```sh
npm install --save mapbox-gl bs-mapbox-gl
```

Then add `bs-mapbox-gl` to `bs-dependencies` in your `bsconfig.json`:

```json
{
  "bs-dependencies": ["bs-mapbox-gl"]
}
```

## Usage

To use any of Mapbox’s tools, APIs, or SDKs, you’ll need a Mapbox [access token](https://www.mapbox.com/help/define-access-token/). Mapbox uses access tokens to associate requests to API resources with your account. You can find all your access tokens, create new ones, or delete existing ones on your [API access tokens page](https://www.mapbox.com/studio/account/tokens/).

```reason
open MapboxGL;

// set the mapbox access token
setAccessToken(mapboxGL, accessToken);

// get map container
let container = Option.getExn(getElementById("map", document));

// set map options
let map_options = {
  "container": container,
  "style": "mapbox://styles/mapbox/streets-v9",
  "center": LngLat.make(~lng=-74.50, ~lat=40.),
  "zoom": 9.,
};

// create and display map
let map = MapGL.make(map_options);
```

You can find more examples [here](https://github.com/stepankuzmin/bs-mapbox-gl/tree/master/debug).

## Contributing

Clone and install dependencies

```shell
git clone https://github.com/stepankuzmin/bs-mapbox-gl.git
cd bs-mapbox-gl
npm install
```

Start the debug server

```shell
MAPBOX_ACCESS_TOKEN={YOUR MAPBOX ACCESS TOKEN} npm start
```

Open the debug page at <http://localhost:1234>
