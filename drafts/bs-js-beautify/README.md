# bs-js-beautify
[![Build Status](https://travis-ci.com/erykpiast/bs-js-beautify.svg?branch=master)](https://travis-ci.com/erykpiast/bs-js-beautify)
[![dependencies Status](https://david-dm.org/erykpiast/bs-js-beautify/status.svg)](https://david-dm.org/erykpiast/bs-js-beautify)
[![devDependencies Status](https://david-dm.org/erykpiast/bs-js-beautify/dev-status.svg)](https://david-dm.org/erykpiast/bs-js-beautify?type=dev)
[![peerDependencies Status](https://david-dm.org/erykpiast/bs-js-beautify/peer-status.svg)](https://david-dm.org/erykpiast/bs-js-beautify?type=peer)
[![Greenkeeper badge](https://badges.greenkeeper.io/erykpiast/bs-js-beautify.svg)](https://greenkeeper.io/)

BuckleScript bindings for [js-beautify](https://github.com/beautify-web/js-beautify) library.

## Installation

```
npm i --save bs-js-beautify js-beautify
```

Then add `bs-js-beautify` as a dependency to `bsconfig.json`.

## Usage

```ocaml
let uglyCode = "if(window.x){console.log('It is x');}else{console.log('It is not');}"
in let prettyCode = JsBeautify.beautify ~indent_size:2 uglyCode
in Js.log prettyCode;;
```
```javascript
if (window.x) {
  console.log('It is x');
} else {
  console.log('It is not');
}
```
