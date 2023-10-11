# bs-abort-controller
> ReasonML bindings for Abort Controller

[![NPM](https://img.shields.io/npm/v/bs-abort-controller-2.svg)](https://www.npmjs.com/package/bs-abort-controller-2)

## Install

npm
```bash
npm i --save bs-abort-controller-2
```

yarn
```bash
yarn add bs-abort-controller-2
```

After installing, add it to the dependencies

bsconfig.json
```json
{
  "bs-dependencies": [
    "bs-abort-controller",
  ],
}
```

## Usage

```reason
open BsAbortController;

/**
 * Create an AbortController
 */
let controller = AbortController.make();

/**
 * Get the AbortSignal from the controller
 */
let signal = AbortController.signal(controller);

/**
 * Register a listener to the AbortSignal
 */
signal->AbortSignal.addEventListener("abort", () => {
  Js.log("Aborted");
});

signal->AbortSignal.addEventListener("abort", () => {
  Js.log("Aborted as well");
});

/**
 * Abort the controller
 */
AbortController.abort(controller);
```

## License

MIT © [lxsmnsyc](https://github.com/lxsmnsyc)