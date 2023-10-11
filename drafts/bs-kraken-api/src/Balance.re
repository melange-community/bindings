open Currency;

type balanceJs = {
  .
  "error": array(string),
  "result": Js.Dict.t(string),
};

type amount = float;

type balance = {
  currency,
  amount,
};

type balances = list(balance);

let toBalance = (code, amount) => {
  currency: fromCode(code),
  amount: float_of_string(amount),
};

let toBalances = balanceJs => {
  let keys = Js.Dict.keys(balanceJs##result) |> Array.to_list;
  let values = Js.Dict.values(balanceJs##result) |> Array.to_list;
  List.map2(toBalance, keys, values);
};