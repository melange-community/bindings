exception UnknownCurrency;

type currency =
  | XBT
  | LTC
  | XDG
  | REP
  | XRP
  | XLM
  | ETH
  | ETC
  | ICN
  | USDT
  | DASH
  | ZEC
  | XMR
  | GNO
  | EOS
  | BCH
  | EUR
  | USD
  | JPY
  | CAD;

let toString = currency =>
  switch (currency) {
  | XBT => "Bitcoin"
  | LTC => "Litecoin"
  | XDG => "Dogecoin"
  | REP => "Augur"
  | XRP => "Ripple"
  | XLM => "Stellar"
  | ETH => "Ether"
  | ETC => "Ether Classic"
  | ICN => "Iconomi"
  | USDT => "Tether"
  | DASH => "Dash"
  | ZEC => "Zcash"
  | XMR => "Monero"
  | GNO => "Gnosis"
  | EOS => "Eos"
  | BCH => "Bitcoin Cash"
  | EUR => "Euro"
  | USD => "US Dollar"
  | JPY => "Japanese Yen"
  | CAD => "Canadian Dollar"
  };

let fromCode = code =>
  switch (code) {
  | "XXBT" => XBT
  | "XXRP" => XRP
  | "XLTC" => LTC
  | "XETH" => ETH
  | "XXMR" => XMR
  | "EOS" => EOS
  | "BCH" => BCH
  | "ZEUR" => EUR
  | "ZUSD" => USD
  | "ZJPY" => JPY
  | "ZCAD" => CAD
  | _ => raise(UnknownCurrency)
  };