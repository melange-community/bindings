From rescript-tinycolor

# rescript-tinycolor

[![NPM version](http://img.shields.io/npm/v/rescript-tinycolor.svg)](https://www.npmjs.org/package/rescript-tinycolor)
[![Build Status](https://travis-ci.com/mikaello/rescript-tinycolor.svg?branch=master)](https://travis-ci.com/mikaello/rescript-tinycolor)

ReScript bindings for [TinyColor](https://github.com/scttcper/tinycolor): fast, small color manipulation and conversion. See also <https://tinycolor.vercel.app>

## Getting started

```
yarn add rescript-tinycolor
```

Then add `rescript-tinycolor` as a dependency to `bsconfig.json`:

```diff
"bs-dependencies": [
+  "rescript-tinycolor"
]
```

## Example

```reason
open RescriptTinycolor;

let redString = TinyColor.makeFromString("red");
/* New instance made by name 'red' */

let blueRgb = TinyColor.makeFromRgb({r: 0, g: 0, b: 255});
/* New instance made with RGB values */

let yellowHsl = TinyColor.makeFromHsl({h: 60, s: 0.94, l: 0.5});
/* New instance made with HSL values (saturation and lightness must be given as percent fractions) */

let darkGreenHsv = TinyColor.makeFromHsv({h: 100, s: 1.0, v: 0.3});
/* New instance made with HSV values (saturation and value must be given as percent fractions) */

let blueRgbWithAlpha = Belt.Option.map(blueRgb, TinyColor.setAlpha(0.2));
/* New instance with changed alpha */

let brightness = Belt.Option.map(redString, TinyColor.getBrightness);
/* Some(76.245) */

let hexString = Belt.Option.map(blueRgb, TinyColor.toHexString);
/* Some("#0000ff") */

let shadedBlue = Belt.Option.map(blueRgb, TinyColor.shade(~value=50));
/* New instanced with color shaded 50% */

let isReadableInCombination = switch(redString, blueRgb) {
    | (Some(red), Some(blue)) => TinyColor.isReadable(red, blue);
    | _ => false;
};
/* returns a bool telling whether these colors can be used for background/text */
```

See all available functions in the [original TinyColor repo](https://github.com/scttcper/tinycolor) and example usage of all functions in [the tests](https://github.com/mikaello/rescript-tinycolor/blob/master/__tests__/Tinycolor_tests.re).

## Differences from original

- It is not possible to create an invalid tinycolor instance, it will either return `Some(t)` if it is valid, or `None` if it is invalid. E.g. an invalid instance can occur if you create a color with a string not corresponding to a valid color (`beautifulRed` is not a valid color) or you provide RGB values outside the valid range (0-255).
- When creating instances with HSL and HSV values: saturation, lightness and value must be given as fractions instead of percent (`0.2 == 20%`).
- All functions accept only TinyColor-instances created by one of the `make-`-functions (or `random()`), it is not possible to pass in a string or RGB-record for the functions (which is possible in the original library).
- `setAlpha(val)` is immutable, it will return a new instance with changed alpha value (the other methods that modify a color (`spin`, `lighten`, etc.) is immutable from the original library).
- `toName()` returns an option, either `Some(string)` if a name could be deduced (e.g. _red_) or `None` if not.
- To get multiple random colors with the `count` parameter, the function `randomMultiple()` must be used (which is the same as `random()` only that it returns an array with length `count` instead of a single color).

## Contribute

If you find bugs or there are updates in [TinyColor](https://github.com/bgrins/TinyColor), feel free to open an issue or PR. If you are upgrading any dependencies, please use yarn so `yarn.lock` is updated.

If you add, remove or change bindings, remember to update the tests as well. It should be at least one test for every binding. Run the tests with `yarn test` from project root.

## Alternatives / related

- [bs-parse-color](https://redex.github.io/package/unpublished/theatlasroom/bs-parse-color/) - bindings for [parse-color](https://github.com/substack/parse-color)
- [bs-randomcolor](https://github.com/ktrzos/bs-randomColor) - bindings for [randomColor](https://github.com/davidmerfield/randomColor/) (which is the same implementation as `random()` in this library)
- [re-color-contrast](https://github.com/mikaello/re-color-contrast) - ReasonML implementation of color-contrast calculation (which is the same as `readability(..)` in this library).
