module Utils: {
  let randomHex: int => string;
  let sha3: string => string;
  let keccak256: string => string;
};

let version: string;

type web3;

type provider;

let create: option(provider) => web3;

let givenProvider: option(provider);
