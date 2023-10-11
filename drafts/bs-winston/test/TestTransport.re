[%%bs.raw {|

var WinstonTransportJS = require("winston-transport");

class TestTransportJS extends WinstonTransportJS {
  constructor(cbObj, opts) {
    super(opts);
    this.cbObj = cbObj;
  }

  log(info, callback) {
    setImmediate(() => this.emit('logged', info));
    var MESSAGE = Symbol.for("message");
    this.cbObj.setResult(String(info[MESSAGE]));
    if (callback) {
      callback(); // eslint-disable-line callback-return
    }
  }
};
|}];

[@bs.deriving abstract]
type currentCallback = {
  mutable setResult: string => unit
};

let createTestTransportJS: currentCallback => Transport.t = [%bs.raw {|
  function (cbObj) {
    return new TestTransportJS(cbObj);
  }
|}]

let createFutureWithCb: currentCallback => unit => Future.t(Belt.Result.t(string, exn)) =
  (currentCallback, ()) =>
    Future.make(resolve => {
      let setter = strVal => resolve(Belt.Result.Ok(strVal));
      setResultSet(currentCallback, setter);
    });

let create: unit => (Transport.t, (unit => Future.t(Belt.Result.t(string, exn)))) =
  () => {
    let currentCallback = currentCallback(~setResult=(_ => {()}));
    let createFn = createFutureWithCb(currentCallback);
    let transport = createTestTransportJS(currentCallback);
    (transport, createFn);
  };