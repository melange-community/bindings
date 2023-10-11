module type Credentials = {let key: string; let secret: string;};

module type KrakenApi = {
  let balance: unit => Js.Promise.t(Balance.balances);
};

module Make = (Creds: Credentials) : KrakenApi => {
  open Js.Promise;
  type kraken;
  [@bs.new] [@bs.module]
  external krakenApi : (string, string) => kraken = "kraken-api";
  let krakenInstance = krakenApi(Creds.key, Creds.secret);
  [@bs.send] external api : (kraken, string) => Js.Promise.t('result) = "";
  let balance = () =>
    api(krakenInstance, "Balance")
    |> then_(json => resolve(Balance.toBalances(json)));
};