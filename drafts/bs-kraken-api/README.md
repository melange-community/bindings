# [ReasonML](https://reasonml.github.io/) bindings for [Kraken API](https://github.com/nothingisdead/npm-kraken-api)

Fully typed Kraken API, a wrapper of [`nothingisdead/npm-kraken-api`](https://github.com/nothingisdead/npm-kraken-api). Take full advantage of algebraic types and pattern matching on currencies, tickers, etc.

## This is work in progress
This is work in progress, and as of now is not ready for production. If you want to contribute continue reading.

## How to use
### Install
```
$ npm install bs-kraken-api
```

### Sample code
```
module Creds = {
  let key = "kraken-key";
  let secret = "kraken-secret";
};

module KrakenClient = Kraken.Make(Creds);

open Js.Promise;

open Balance;

open Currency;

let balanceToString = (balance: balance) =>
  toString(balance.currency)
  ++ ": "
  ++ string_of_float(balance.amount)
  ++ "\n";

let balancesToString =
  List.fold_left((acc, bal) => acc ++ balanceToString(bal), "");

KrakenClient.balance()
|> then_(balances => resolve(Js.log(balancesToString(balances))));
```

this should give an output similar to this one
```
Euro: 50.0
Bitcoin: 50.0 //whoa, I wish I had that figure when running with my credentials :)
Ripple: 120.0
Litecoin: 10.5
Ether: 0.12
Monero: 10.5
Eos: 1.1
Bitcoin Cash: 4.01e-06
```

## Contribute

### ReasonML
If you know ReasonML please submit PR's. At the moment only a few methods from underlying library have their corresponfing bindings.

### Crypto
Bitcoin: `181xNteGrvve17sy2NFqZfsUWocfMWpTLP`

Ethereum and Tokens : `0xab44959106f190920fd490fcb1bdee7c84ce92ea`
