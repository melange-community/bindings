module Utils = {
  [@bs.module "web3"] [@bs.scope "utils"]
  external randomHex : int => string = "randomHex";
  [@bs.module "web3"] [@bs.scope "utils"]
  external sha3 : string => string = "sha3";
  [@bs.module "web3"] [@bs.scope "utils"]
  external keccak256 : string => string = "keccak256";
};

[@bs.module "web3"] [@bs.val] external version : string = "version";

type web3;

type provider;

[@bs.module "web3"] [@bs.val] [@bs.return nullable]
external givenProvider : option(provider) = "givenProvider";

[@bs.new] external create : option(provider) => web3 = "Web3";
