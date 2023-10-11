# bs-bn.js
[BuckleScript](https://bucklescript.github.io/) bindings for [bn.js](https://github.com/indutny/bn.js/).

### State

This is a work in progress, so proceed with caution. However, 90% of the tests in the original library have been migrated to Reason, so the coverage is mostly complete.

Constructors, binary ops, arithmetic ops, and reduction ops are available. There are some functions related to prime numbers that have not been bound yet. Feel free to open an issue / PR if you need them.

### Installation

1. Make sure you have `bn.js` installed. If not, run `npm install bn.js --save`
2. Install the bindings: `npm install bs-bn.js --save`
3. Add the bindings to `bsconfig.json`

```json
{
  "bs-dependencies": [
      "bs-bn.js"
  ]
}
```

### Using it

Create new big numbers from float numbers:

```reason
let a = Bn.fromFloat(12345.);
```

You can use `float_of_int` if you prefer to use ints. The main reason why floats were selected is that ints are trimmed to 32 bits in BuckleScript, so float is a safer choice.

You can create big numbers also from other types:

```reason
let s = Bn.fromString(~base=16, ~endian=`le, "1A6B765D8CDF");
let a = Bn.fromArray([|1, 2, 3|]);
let b = Bn.fromBuffer(Node.Buffer.fromString("12345"));
```

Operations always keep the affected big number as the last param to enable piping:

```reason
let a = Bn.fromString(~base=16, "ffffffff");
let b = a |> Bn.abs |> Bn.mul(Bn.fromFloat(3.));
```

### Full API

Check the interface file [`Bn.rei`](https://github.com/jchavarri/bs-bn.js/blob/master/src/Bn.rei).

### TODO

- Explore adding infix operators: `let result = Bn.Infix.(bn1 + bn2);`
