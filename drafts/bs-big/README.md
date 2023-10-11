# bs-big.js
Bucklescript bindings to [big.js](https://github.com/MikeMcl/big.js/), a library for arbitrary-precision decimal arithmetic. All methods are supported.

## Installation
1. Make sure big.js is installed: `npm install big.js`
2. Install the bindings: `npm install bs-big.js`
3. Add the bindings to bs-config.json:
```
{
  "bs-dependencies": [
      "bs-big.js"
  ]
}
```

## Usage
Big numbers of type `Big.t` can be created using `Big.fromInt`, `Big.fromString` or `Big.fromFloat`. Arithmetic can
then be done using the pipe-first `|.` syntax. For example:

```Reason
Big.setDP(10); //set decimal places
Big.setRM(1); //set rounding mode
let x = Big.fromInt(2);
let y = Big.fromInt(3);
let z = x |. Big.div(y);
let _ = z |. Big.toString // "0.6666666667"
let _ = z |. Big.sqrt |. Big.toString // "0.8164965809"
let _ = z |. Big.pow(-3) |. Big.toString // "3.3749999995"
let _ = z |. Big.times(z) |. Big.toString // "0.44444444448888888889"
let _ = z |. Big.times(z) |. Big.round(~dp=10, ()) |. Big.toString // "0.4444444445"
```


## Documentation
See [Big.mli](https://github.com/alexchang8/bs-big.js/blob/master/src/Big.mli) and the [big.js documentation](http://mikemcl.github.io/big.js/)


## Testing
Very extensive testing was done by porting most of the tests from big.js. To run the tests:
```
npm test
```
## Things to note

 - The method`Big.mod_` has an underscore because `mod` is a reserved keyword in OCaml/Reason
 - The last parameter of all methods with optional parameters is `unit`. This is because the last parameter would be optional, [which don't work properly in OCaml](https://ocaml.org/learn/tutorials/labels.html#quot-Warning-This-optional-argument-cannot-be-erased-quot). Keeping the parameter order allows consistent use of the pipe-first syntax `|.`, so it is better to end with `unit` than swap order.
 - OCaml does not have `-0` but Javascript does
