# bs-web3

[Web3](https://github.com/ethereum/web3.js) bindings for [BuckleScript](https://github.com/bloomberg/bucklescript) in [Reason](https://github.com/facebook/reason).

[![npm](https://img.shields.io/npm/v/bs-web3.svg)](https://www.npmjs.com/package/bs-web3) ![license](https://img.shields.io/github/license/figitaki/bs-web3.svg) [![Travis](https://img.shields.io/travis/figitaki/bs-web3.svg)](https://travis-ci.org/figitaki/bs-web3) ![David](https://img.shields.io/david/figitaki/bs-web3.svg) ![David](https://img.shields.io/david/dev/figitaki/bs-web3.svg) ![Coveralls github](https://img.shields.io/coveralls/github/figitaki/web3-svg.svg)

This package is currently under development, and not suited for production.

## Installation

Install bs-web3 using npm:

```
npm install bs-web3
```

Alternatively, using yarn:

```
yarn add bs-web3
```

Then add `bs-web3` as a dependency to `bsconfig.json`

```
{
  ...
  "bs-dependencies": ["bs-web3"]
}
```

## Usage

This package implements the majority of functionality provided by Web3. Here's a basic example.

```
Js.log(Web3.version);
Js.log(Web3.Utils.randomHex(32));
```

For more examples see the `example/` folder. 

