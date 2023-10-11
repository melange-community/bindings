# rescript-picomatch

ReScript bindings for [picomatch](https://github.com/micromatch/picomatch)

## Installation

```sh
npm i rescript-picomatch
```

In your `bsconfig.json` add it to `bs-dependencies`

```
{
  ...,
  "bs-dependencies": [..., "rescript-picomatch"],
}
```

## Example

```rescript
let isMatch = Picomatch.match("*.js")

Js.log(isMatch("abcd")) //=> false
Js.log(isMatch("a.js")) //=> true
Js.log(isMatch("a.md")) //=> false
Js.log(isMatch("a/b.js")) //=> false
```
