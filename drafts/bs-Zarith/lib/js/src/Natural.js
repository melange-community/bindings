'use strict';

var Bigint = require("./Bigint.js");
var Caml_exceptions = require("rescript/lib/js/caml_exceptions.js");
var Caml_js_exceptions = require("rescript/lib/js/caml_js_exceptions.js");

var Underflow = /* @__PURE__ */Caml_exceptions.create("Natural.Underflow");

var DecodeError = /* @__PURE__ */Caml_exceptions.create("Natural.DecodeError");

var zero = /* Natural */{
  _0: Bigint.zero
};

var one = /* Natural */{
  _0: Bigint.one
};

function ofInt(x) {
  var r = Bigint.of_int(x);
  if (Bigint.lt(r, Bigint.zero)) {
    return ;
  } else {
    return /* Natural */{
            _0: r
          };
  }
}

function ofInt32(x) {
  var r = Bigint.of_int32(x);
  if (Bigint.lt(r, Bigint.zero)) {
    return ;
  } else {
    return /* Natural */{
            _0: r
          };
  }
}

function ofInt64(x) {
  var r = Bigint.of_int64(x);
  if (Bigint.lt(r, Bigint.zero)) {
    return ;
  } else {
    return /* Natural */{
            _0: r
          };
  }
}

function ofFloat(x) {
  var r = Bigint.of_float(x);
  if (Bigint.lt(r, Bigint.zero)) {
    return ;
  } else {
    return /* Natural */{
            _0: r
          };
  }
}

function ofString(x) {
  var r = Bigint.of_string_opt(x);
  if (r !== undefined && !Bigint.lt(r, Bigint.zero)) {
    return /* Natural */{
            _0: r
          };
  }
  
}

function unsafeOfInt(x) {
  var x$1 = ofInt(x);
  if (x$1 !== undefined) {
    return x$1;
  }
  throw {
        RE_EXN_ID: Underflow,
        Error: new Error()
      };
}

function unsafeOfInt32(x) {
  var x$1 = ofInt32(x);
  if (x$1 !== undefined) {
    return x$1;
  }
  throw {
        RE_EXN_ID: Underflow,
        Error: new Error()
      };
}

function unsafeOfInt64(x) {
  var x$1 = ofInt64(x);
  if (x$1 !== undefined) {
    return x$1;
  }
  throw {
        RE_EXN_ID: Underflow,
        Error: new Error()
      };
}

function unsafeOfFloat(x) {
  var x$1 = ofFloat(x);
  if (x$1 !== undefined) {
    return x$1;
  }
  throw {
        RE_EXN_ID: Underflow,
        Error: new Error()
      };
}

function unsafeOfString(x) {
  var x$1 = ofString(x);
  if (x$1 !== undefined) {
    return x$1;
  }
  throw {
        RE_EXN_ID: DecodeError,
        Error: new Error()
      };
}

function toInt(x) {
  return Bigint.to_int(x._0);
}

function toInt32(x) {
  return Bigint.to_int32(x._0);
}

function toInt64(x) {
  return Bigint.to_int64(x._0);
}

function toFloat(x) {
  return Bigint.to_float(x._0);
}

function toString(x) {
  return Bigint.to_string(x._0);
}

function succ(x) {
  return /* Natural */{
          _0: Bigint.add(x._0, Bigint.one)
        };
}

function pred(x) {
  var r = Bigint.sub(x._0, Bigint.one);
  if (Bigint.lt(r, Bigint.zero)) {
    throw {
          RE_EXN_ID: Underflow,
          Error: new Error()
        };
  }
  return /* Natural */{
          _0: r
        };
}

function predSafe(x) {
  var x$1;
  try {
    x$1 = pred(x);
  }
  catch (raw_exn){
    var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
    if (exn.RE_EXN_ID === Underflow) {
      return ;
    }
    throw exn;
  }
  return x$1;
}

function add(x, y) {
  return /* Natural */{
          _0: Bigint.add(x._0, y._0)
        };
}

function sub(x, y) {
  var r = Bigint.sub(x._0, y._0);
  if (Bigint.lt(r, Bigint.zero)) {
    throw {
          RE_EXN_ID: Underflow,
          Error: new Error()
        };
  }
  return /* Natural */{
          _0: r
        };
}

function subSafe(x, y) {
  var r;
  try {
    r = sub(x, y);
  }
  catch (raw_exn){
    var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
    if (exn.RE_EXN_ID === Underflow) {
      return ;
    }
    throw exn;
  }
  return r;
}

function mul(x, y) {
  return /* Natural */{
          _0: Bigint.mul(x._0, y._0)
        };
}

function div(x, y) {
  return /* Natural */{
          _0: Bigint.div(x._0, y._0)
        };
}

function rem(x, y) {
  return /* Natural */{
          _0: Bigint.rem(x._0, y._0)
        };
}

function divRem(x, y) {
  var match = Bigint.div_rem(x._0, y._0);
  return [
          /* Natural */{
            _0: match[0]
          },
          /* Natural */{
            _0: match[1]
          }
        ];
}

function cdiv(x, y) {
  return /* Natural */{
          _0: Bigint.cdiv(x._0, y._0)
        };
}

function fdiv(x, y) {
  return /* Natural */{
          _0: Bigint.fdiv(x._0, y._0)
        };
}

function edivRem(x, y) {
  var match = Bigint.ediv_rem(x._0, y._0);
  return [
          /* Natural */{
            _0: match[0]
          },
          /* Natural */{
            _0: match[1]
          }
        ];
}

function ediv(x, y) {
  return /* Natural */{
          _0: Bigint.ediv(x._0, y._0)
        };
}

function erem(x, y) {
  return /* Natural */{
          _0: Bigint.erem(x._0, y._0)
        };
}

function divexact(x, y) {
  return /* Natural */{
          _0: Bigint.divexact(x._0, y._0)
        };
}

exports.Underflow = Underflow;
exports.DecodeError = DecodeError;
exports.zero = zero;
exports.one = one;
exports.ofInt = ofInt;
exports.ofInt32 = ofInt32;
exports.ofInt64 = ofInt64;
exports.ofFloat = ofFloat;
exports.ofString = ofString;
exports.unsafeOfInt = unsafeOfInt;
exports.unsafeOfInt32 = unsafeOfInt32;
exports.unsafeOfInt64 = unsafeOfInt64;
exports.unsafeOfFloat = unsafeOfFloat;
exports.unsafeOfString = unsafeOfString;
exports.toInt = toInt;
exports.toInt32 = toInt32;
exports.toInt64 = toInt64;
exports.toFloat = toFloat;
exports.toString = toString;
exports.succ = succ;
exports.pred = pred;
exports.predSafe = predSafe;
exports.add = add;
exports.sub = sub;
exports.subSafe = subSafe;
exports.mul = mul;
exports.div = div;
exports.rem = rem;
exports.divRem = divRem;
exports.cdiv = cdiv;
exports.fdiv = fdiv;
exports.edivRem = edivRem;
exports.ediv = ediv;
exports.erem = erem;
exports.divexact = divexact;
/* No side effect */
