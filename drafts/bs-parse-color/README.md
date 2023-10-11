# bs-parse-color
[![License: MIT](https://img.shields.io/github/license/mashape/apistatus.svg?style=flat)](https://opensource.org/licenses/MIT)
[![CircleCI](https://circleci.com/gh/theatlasroom/bs-parse-color.svg?style=svg)](https://circleci.com/gh/theatlasroom/bs-parse-color)

Pretty naive BuckleScript bindings for [parse-color](https://github.com/substack/parse-color)

I'm very new to Reason, so i do not recommend using this for anything more than a toy, please open an issue / leave comments if you have a better ideas on some of the parts.

## Installation
With yarn
```
yarn add bs-parse-color
```

Or with npm
```
npm install bs-parse-color
```

Then add `bs-parse-color` to your `bsconfig.json` file as a dependency
```
{
  ...
  "bs-dependencies": [ "bs-parse-color" ]
  ...
}
```

## Usage
```
/* call .parse with an argument of any color type */
let col = "orange" | "#FF6600" | "rgb(10,20,30)" | "rgba(10,20,20,0.5)" ...
let parsed = ParseColor.parse(col);

/* convert the parsed color into another type */
parsed |> asHex;
parsed |> asRgba;
parsed |> asCmkya;

/* access a color mode */
parsed.rgba
```