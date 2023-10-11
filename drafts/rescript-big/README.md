# rescript-big

[![Actions Status](https://github.com/winoteam/rescript-big/workflows/rescript-big/badge.svg)](https://github.com/winoteam/rescript-big/actions)

**Zero-cost bindings to [Big.js](https://github.com/MikeMcl/big.js/) library.**

In this version only these methods are supported: `toFixed`, `plus`, `minus`, `div`, `times`, `valueOf`, `round`, `eq`, `gt`, `gte`, `lt` and `lte`

It also have some converters and shortcuts for converting an existing value or making a Big value, such as: `fromFloat`or `toFloat`.

It's accompanied with an `Operators` module which override some operators like `+.`, `*.`, `/.` and `-.`

## 📦 Installation

Run the following command:

```bash
$ yarn add rescript-big
```

Then add `rescript-big` to your `bsconfig.json`'s dependencies:

```diff
 {
   "bs-dependencies": [
+    "rescript-big"
   ]
 }
```

## 💻 Usage

```rescript
open! Big.Operators

let a = 201.57512->Big.fromFloat
Js.log(a->Big.toFixed(2)) // 201.58

// Compiler error: 1. is a float, wanted Big.t
let c = a *. 1.

// OK
let b = 1.->Big.fromFloat
let c = a *. b
Js.log(Big.valueOf(c)) // 201.57512
```

## 🕺 Contribute

### 🚀 Want to hack on `rescript-big`? Follow the next instructions

1. Fork this repository to your own GitHub account and then clone it to your local device
2. Install dependencies using Yarn: `yarn`
3. Ensure that the tests are passing using `yarn test`
4. Send a pull request 🙌

Remember to add tests for your change if possible.

## 👋 Questions

If you have any questions, feel free to open an issue. Please check the [Big.js docs](https://github.com/MikeMcl/big.js/) before submitting an issue.
