# `bs-downshift`

[BuckleScript](https://github.com/bucklescript/bucklescript) bindings for [Downshift](https://github.com/paypal/downshift)

[![npm](https://img.shields.io/npm/v/bs-downshift.svg)](https://npmjs.org/bs-downshift)
[![Issues](https://img.shields.io/github/issues/reasonml-community/bs-downshift.svg)](https://github.com/reasonml-community/bs-downshift/issues)
[![Dependencies](https://img.shields.io/david/peer/reasonml-community/bs-downshift.svg)](https://github.com/reasonml-community/bs-downshift/blob/master/package.json)
[![Issues](https://img.shields.io/github/issues/reasonml-community/bs-downshift.svg)](https://github.com/reasonml-community/bs-downshift/issues)
[![Last Commit](https://img.shields.io/github/last-commit/reasonml-community/bs-downshift.svg)]()

## Demo

_Coming soon_

## Compatibility with original `downshift` library

Compatible with `downshift` [v1.25.0](https://github.com/paypal/downshift/releases/tag/v1.25.0).

> Using newer versions of `downshift` might break the bindings as the API might have changed. Use at your own risk.

## Install and setup

#### yarn

```bash
$ yarn add bs-downshift
```

#### bsconfig

Add `bs-downshift` to your `bs-dependencies`: **bsconfig.json**

```json
"bs-dependencies": [
  "bs-downshift",
  "reason-react"
]
```

## Usage

See [examples](./examples) folder.

### Usage of `render` function

The `render` prop is a function that passes an object which contains _methods_ and _values_.

In ReasonML, this object is represented as a module called `ControllerStateAndHelpers`.

To make use of the _methods_ and _values_ within that module, you need to call it by passing the argument type (which is of type `ControllerStateAndHelpers.t` and does effectively the binding to the JS object method) like:

```js
render=(
  t => {
    ControllerStateAndHelpers.toggleMenu(t, ());
    /* ... */
  }
)
```

You can see that in the [examples](./examples) folder.
