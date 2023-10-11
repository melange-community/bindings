let web3 = Web3.create(Web3.givenProvider);

let coinbase = web3.eth.coinbase;
let balance = web3.eth.getBalance(coinbase);

Js.log(balance);
