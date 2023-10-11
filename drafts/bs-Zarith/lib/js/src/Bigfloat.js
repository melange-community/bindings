'use strict';

var Bigint = require("./Bigint.js");
var $$String = require("rescript/lib/js/string.js");
var Js_string = require("rescript/lib/js/js_string.js");
var Caml_array = require("rescript/lib/js/caml_array.js");
var Caml_format = require("rescript/lib/js/caml_format.js");

function mkBigfloat(v, d) {
  return {
          value: v,
          decimalPos: d
        };
}

var zero = {
  value: Bigint.zero,
  decimalPos: 0
};

var one = {
  value: Bigint.one,
  decimalPos: 0
};

var minusOne = {
  value: Bigint.minus_one,
  decimalPos: 0
};

function repeatString(n, s) {
  if (n === 0) {
    return "";
  } else {
    return s + repeatString(n - 1 | 0, s);
  }
}

var addCommas = (function (s) {
      var sp = s.split(".");
      var l = sp[0].replace(/(\d)(?=(\d\d\d)+(?!\d))/g, "$1,");
      if (sp.length > 1) {
        return l.concat(".", sp[1]);
      } else {
        return l;
      }
    });

var removeCommas = (function (s) {
      return s.replace(/,/g, "");
    });

function ofInt(i) {
  return {
          value: Bigint.of_int(i),
          decimalPos: 0
        };
}

function ofInt32(i) {
  return {
          value: Bigint.of_int32(i),
          decimalPos: 0
        };
}

function ofInt64(i) {
  return {
          value: Bigint.of_int64(i),
          decimalPos: 0
        };
}

function ofString(string, decimalPos) {
  var s = removeCommas(string);
  var a = Js_string.split(".", s);
  if (a.length === 1) {
    return {
            value: Bigint.mul(Bigint.of_string(s), Bigint.pow(Bigint.of_int(10), decimalPos)),
            decimalPos: decimalPos
          };
  }
  if (a.length !== 2) {
    return ;
  }
  var leftSide = Caml_array.get(a, 0);
  var rightSide = Caml_array.get(a, 1);
  var rightSideLength = rightSide.length;
  var rr = rightSideLength === decimalPos ? rightSide : (
      rightSideLength < decimalPos ? rightSide + repeatString(decimalPos - rightSideLength | 0, "0") : $$String.sub(rightSide, 0, decimalPos)
    );
  return {
          value: Bigint.of_string(leftSide + rr),
          decimalPos: decimalPos
        };
}

function ofFloat(f, decimalPos) {
  var s = f.toString();
  var a = Js_string.split(".", s);
  if (a.length === 1) {
    return {
            value: Bigint.of_float(f),
            decimalPos: decimalPos
          };
  }
  if (a.length !== 2) {
    return {
            value: Bigint.zero,
            decimalPos: decimalPos
          };
  }
  var leftSide = Caml_array.get(a, 0);
  var rightSide = Caml_array.get(a, 1);
  var rightSideLength = rightSide.length;
  var rr = rightSideLength === decimalPos ? rightSide : (
      rightSideLength < decimalPos ? rightSide + repeatString(decimalPos - rightSideLength | 0, "0") : $$String.sub(rightSide, 0, decimalPos)
    );
  return {
          value: Bigint.of_string(leftSide + rr),
          decimalPos: decimalPos
        };
}

function toInt(t) {
  return Bigint.to_int(Bigint.div(t.value, Bigint.pow(Bigint.of_int(10), t.decimalPos)));
}

function toInt32(t) {
  return Bigint.to_int32(Bigint.div(t.value, Bigint.pow(Bigint.of_int(10), t.decimalPos)));
}

function toInt64(t) {
  return Bigint.to_int64(Bigint.div(t.value, Bigint.pow(Bigint.of_int(10), t.decimalPos)));
}

function toString(t) {
  var s = Bigint.to_string(t.value);
  var sl = s.length;
  if (t.decimalPos === 0) {
    return s;
  }
  if (sl <= t.decimalPos) {
    return "0." + (repeatString(t.decimalPos - sl | 0, "0") + s);
  }
  var r = Js_string.slice(sl - t.decimalPos | 0, sl, s);
  var l = Js_string.slice(0, sl - t.decimalPos | 0, s);
  return l + ("." + r);
}

function toStringWithCommas(t) {
  return addCommas(toString(t));
}

function toFloat(t) {
  return Caml_format.float_of_string(toString(t));
}

function abs(t) {
  return {
          value: Bigint.abs(t.value),
          decimalPos: t.decimalPos
        };
}

function neg(t) {
  return {
          value: Bigint.neg(t.value),
          decimalPos: t.decimalPos
        };
}

function add(x, y) {
  if (x.decimalPos === y.decimalPos) {
    return {
            value: Bigint.add(x.value, y.value),
            decimalPos: x.decimalPos
          };
  }
  if (x.decimalPos > y.decimalPos) {
    var decimalPos = x.decimalPos - y.decimalPos | 0;
    return {
            value: Bigint.add(x.value, Bigint.mul(y.value, Bigint.pow(Bigint.of_int(10), decimalPos))),
            decimalPos: x.decimalPos
          };
  }
  var decimalPos$1 = y.decimalPos - x.decimalPos | 0;
  return {
          value: Bigint.add(y.value, Bigint.mul(x.value, Bigint.pow(Bigint.of_int(10), decimalPos$1))),
          decimalPos: y.decimalPos
        };
}

function sub(x, y) {
  if (x.decimalPos === y.decimalPos) {
    return {
            value: Bigint.sub(x.value, y.value),
            decimalPos: x.decimalPos
          };
  }
  if (x.decimalPos > y.decimalPos) {
    var decimalPos = x.decimalPos - y.decimalPos | 0;
    return {
            value: Bigint.sub(x.value, Bigint.mul(y.value, Bigint.pow(Bigint.of_int(10), decimalPos))),
            decimalPos: x.decimalPos
          };
  }
  var decimalPos$1 = y.decimalPos - x.decimalPos | 0;
  return {
          value: Bigint.sub(y.value, Bigint.mul(x.value, Bigint.pow(Bigint.of_int(10), decimalPos$1))),
          decimalPos: y.decimalPos
        };
}

function mul(x, y) {
  return {
          value: Bigint.mul(x.value, y.value),
          decimalPos: x.decimalPos + y.decimalPos | 0
        };
}

function elongateBy(x, decimalPos) {
  return {
          value: Bigint.mul(x.value, Bigint.pow(Bigint.of_int(10), decimalPos)),
          decimalPos: x.decimalPos
        };
}

function adjustDecimalPos(x, y) {
  if (x.decimalPos === y.decimalPos) {
    return [
            x,
            y
          ];
  }
  if (x.decimalPos > y.decimalPos) {
    var decimalPos = x.decimalPos - y.decimalPos | 0;
    return [
            x,
            {
              value: Bigint.mul(y.value, Bigint.pow(Bigint.of_int(10), decimalPos)),
              decimalPos: x.decimalPos
            }
          ];
  }
  var decimalPos$1 = y.decimalPos - x.decimalPos | 0;
  return [
          {
            value: Bigint.mul(x.value, Bigint.pow(Bigint.of_int(10), decimalPos$1)),
            decimalPos: y.decimalPos
          },
          y
        ];
}

function div(x, y) {
  if (x.decimalPos === 0 && y.decimalPos === 0) {
    return {
            value: Bigint.div(x.value, y.value),
            decimalPos: x.decimalPos
          };
  }
  var match = adjustDecimalPos(x, y);
  var y$1 = match[1];
  var x$1 = match[0];
  var xFirstNonZero = Bigint.firstNonZero(x$1.value);
  var yFirstNonZero = Bigint.firstNonZero(y$1.value);
  if (xFirstNonZero === undefined) {
    return {
            value: Bigint.zero,
            decimalPos: x$1.decimalPos
          };
  }
  if (yFirstNonZero === undefined) {
    return {
            value: Bigint.zero,
            decimalPos: x$1.decimalPos
          };
  }
  if (xFirstNonZero >= x$1.decimalPos && yFirstNonZero >= y$1.decimalPos) {
    return elongateBy({
                value: Bigint.div(x$1.value, y$1.value),
                decimalPos: x$1.decimalPos
              }, x$1.decimalPos);
  }
  var reposition = xFirstNonZero > yFirstNonZero ? y$1.decimalPos - yFirstNonZero | 0 : x$1.decimalPos - xFirstNonZero | 0;
  var x$2 = elongateBy(x$1, reposition);
  var y$2 = elongateBy(y$1, reposition);
  return elongateBy({
              value: Bigint.div(x$2.value, y$2.value),
              decimalPos: x$2.decimalPos
            }, x$2.decimalPos);
}

function compare(x, y) {
  var match = adjustDecimalPos(x, y);
  return Bigint.compare(match[0].value, match[1].value);
}

function equal(x, y) {
  return compare(x, y) === 0;
}

function leq(x, y) {
  return compare(x, y) < 1;
}

function geq(x, y) {
  return compare(x, y) > -1;
}

function lt(x, y) {
  return compare(x, y) < 0;
}

function gt(x, y) {
  return compare(x, y) > 0;
}

function leqZero(x) {
  return Bigint.compare(x.value, Bigint.zero) <= 0;
}

function geqZero(x) {
  return Bigint.compare(x.value, Bigint.zero) >= 0;
}

function ltZero(x) {
  return Bigint.compare(x.value, Bigint.zero) < 0;
}

function gtZero(x) {
  return Bigint.compare(x.value, Bigint.zero) > 0;
}

function min(x, y) {
  if (compare(x, y) < 0) {
    return y;
  } else {
    return x;
  }
}

function max(x, y) {
  if (compare(x, y) < 0) {
    return x;
  } else {
    return y;
  }
}

exports.mkBigfloat = mkBigfloat;
exports.zero = zero;
exports.one = one;
exports.minusOne = minusOne;
exports.ofInt = ofInt;
exports.ofInt32 = ofInt32;
exports.ofInt64 = ofInt64;
exports.ofFloat = ofFloat;
exports.ofString = ofString;
exports.toInt = toInt;
exports.toInt32 = toInt32;
exports.toInt64 = toInt64;
exports.toFloat = toFloat;
exports.toString = toString;
exports.toStringWithCommas = toStringWithCommas;
exports.adjustDecimalPos = adjustDecimalPos;
exports.abs = abs;
exports.neg = neg;
exports.add = add;
exports.sub = sub;
exports.mul = mul;
exports.div = div;
exports.compare = compare;
exports.equal = equal;
exports.leq = leq;
exports.geq = geq;
exports.lt = lt;
exports.gt = gt;
exports.leqZero = leqZero;
exports.geqZero = geqZero;
exports.ltZero = ltZero;
exports.gtZero = gtZero;
exports.min = min;
exports.max = max;
/* No side effect */
