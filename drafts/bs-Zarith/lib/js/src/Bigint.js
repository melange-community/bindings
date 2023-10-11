'use strict';

var List = require("rescript/lib/js/list.js");
var Int32 = require("rescript/lib/js/int32.js");
var Int64 = require("rescript/lib/js/int64.js");
var $$String = require("rescript/lib/js/string.js");
var Caml_obj = require("rescript/lib/js/caml_obj.js");
var Caml_int64 = require("rescript/lib/js/caml_int64.js");
var Pervasives = require("rescript/lib/js/pervasives.js");
var Belt_Option = require("rescript/lib/js/belt_Option.js");
var Caml_format = require("rescript/lib/js/caml_format.js");
var Caml_string = require("rescript/lib/js/caml_string.js");
var Caml_exceptions = require("rescript/lib/js/caml_exceptions.js");

var Overflow = /* @__PURE__ */Caml_exceptions.create("Bigint.Overflow");

var zero = /* Bigint */{
  _0: /* Pos */0,
  _1: /* [] */0
};

var one = /* Bigint */{
  _0: /* Pos */0,
  _1: {
    hd: 1,
    tl: /* [] */0
  }
};

var two = /* Bigint */{
  _0: /* Pos */0,
  _1: {
    hd: 2,
    tl: /* [] */0
  }
};

function trimzeros(listy) {
  var trimzeros$p = function (listy$p) {
    if (!listy$p) {
      return /* [] */0;
    }
    var car = listy$p.hd;
    if (car === 0 && !listy$p.tl) {
      return /* [] */0;
    }
    var cdr$p = trimzeros$p(listy$p.tl);
    if (car !== 0 || cdr$p) {
      return {
              hd: car,
              tl: cdr$p
            };
    } else {
      return /* [] */0;
    }
  };
  return trimzeros$p(listy);
}

function charlist_of_string(str) {
  var last = str.length - 1 | 0;
  var _pos = last;
  var _result = /* [] */0;
  while(true) {
    var result = _result;
    var pos = _pos;
    if (pos < 0) {
      return result;
    }
    _result = {
      hd: Caml_string.get(str, pos),
      tl: result
    };
    _pos = pos - 1 | 0;
    continue ;
  };
}

function of_string(str) {
  var len = str.length;
  var to_intlist = function (first) {
    var substr = $$String.sub(str, first, len - first | 0);
    var digit = function ($$char) {
      return $$char - /* '0' */48 | 0;
    };
    return trimzeros(List.map(digit, List.rev(charlist_of_string(substr))));
  };
  if (Caml_string.get(str, 0) === /* '-' */45) {
    return /* Bigint */{
            _0: /* Neg */1,
            _1: to_intlist(1)
          };
  } else {
    return /* Bigint */{
            _0: /* Pos */0,
            _1: to_intlist(0)
          };
  }
}

function explode(s) {
  return List.init(s.length, (function (param) {
                return Caml_string.get(s, param);
              }));
}

function is_digit($$char) {
  if ($$char >= 48) {
    return $$char <= 57;
  } else {
    return false;
  }
}

function is_string_of_digits(s) {
  if (s.length === 0) {
    return false;
  }
  var chars = explode(s);
  var chars$1 = List.hd(chars) === /* '-' */45 ? List.tl(chars) : chars;
  return List.fold_right((function (c, x) {
                if (is_digit(c)) {
                  return x;
                } else {
                  return false;
                }
              }), chars$1, true);
}

function of_string_opt(s) {
  if (is_string_of_digits(s)) {
    return of_string(s);
  }
  
}

function of_substring(s, pos, len) {
  return of_string($$String.sub(s, pos, len));
}

function of_int(i) {
  return of_string(String(i));
}

function of_int32(i) {
  return of_string(Int32.to_string(i));
}

function of_int64(i) {
  return of_string(Int64.to_string(i));
}

function of_float(i) {
  return of_string(Int64.to_string(Caml_int64.of_float(i)));
}

function to_string(param) {
  var value = param._1;
  if (!value) {
    return "0";
  }
  var reversed = List.rev(value);
  return $$String.concat("", {
              hd: param._0 === /* Pos */0 ? "" : "-",
              tl: List.map((function (prim) {
                      return String(prim);
                    }), reversed)
            });
}

function cmp(_list1, _list2) {
  while(true) {
    var list2 = _list2;
    var list1 = _list1;
    if (List.length(list1) > List.length(list2)) {
      return 1;
    }
    if (List.length(list1) < List.length(list2)) {
      return -1;
    }
    if (!list1 && !list2) {
      return 0;
    }
    var reverselist1 = List.rev(list1);
    var reverselist2 = List.rev(list2);
    if (Caml_obj.greaterthan(List.hd(reverselist1), List.hd(reverselist2))) {
      return 1;
    }
    if (Caml_obj.lessthan(List.hd(reverselist1), List.hd(reverselist2))) {
      return -1;
    }
    var list1$p = List.rev(List.tl(reverselist1));
    var list2$p = List.rev(List.tl(reverselist2));
    _list2 = list2$p;
    _list1 = list1$p;
    continue ;
  };
}

function add$p(_list1, _list2, _carry) {
  while(true) {
    var carry = _carry;
    var list2 = _list2;
    var list1 = _list1;
    var exit = 0;
    if (list2) {
      exit = 2;
    } else {
      if (carry === 0) {
        return list1;
      }
      exit = 2;
    }
    if (exit === 2 && !list1 && carry === 0) {
      return list2;
    }
    if (list2) {
      if (list1) {
        var sum = (List.hd(list1) + List.hd(list2) | 0) + carry | 0;
        return {
                hd: sum % 10,
                tl: add$p(List.tl(list1), List.tl(list2), sum / 10 | 0)
              };
      }
      _carry = 0;
      _list1 = {
        hd: carry,
        tl: /* [] */0
      };
      continue ;
    }
    _carry = 0;
    _list2 = {
      hd: carry,
      tl: /* [] */0
    };
    continue ;
  };
}

function sub$p(list1, _list2, _carry) {
  while(true) {
    var carry = _carry;
    var list2 = _list2;
    var exit = 0;
    if (list1) {
      exit = 2;
    } else if (!list2) {
      if (carry === 0) {
        return /* [] */0;
      }
      exit = 2;
    }
    if (exit === 2 && !list2) {
      if (carry === 0) {
        return list1;
      }
      _carry = 0;
      _list2 = {
        hd: carry,
        tl: /* [] */0
      };
      continue ;
    }
    var diff = (List.hd(list1) - List.hd(list2) | 0) - carry | 0;
    if (diff >= 0) {
      return {
              hd: diff,
              tl: sub$p(List.tl(list1), List.tl(list2), 0)
            };
    } else {
      return {
              hd: diff + 10 | 0,
              tl: sub$p(List.tl(list1), List.tl(list2), 1)
            };
    }
  };
}

function mul$p(list1, list2$p, powerof2) {
  if (cmp(powerof2, list1) === 1) {
    return [
            list1,
            /* [] */0
          ];
  }
  var match = mul$p(list1, add$p(list2$p, list2$p, 0), add$p(powerof2, powerof2, 0));
  var product = match[1];
  var remainder = match[0];
  if (cmp(remainder, powerof2) === -1) {
    return [
            remainder,
            product
          ];
  } else {
    return [
            trimzeros(sub$p(remainder, powerof2, 0)),
            add$p(product, list2$p, 0)
          ];
  }
}

function add(param, param$1) {
  var value2 = param$1._1;
  var neg2 = param$1._0;
  var value1 = param._1;
  var neg1 = param._0;
  if (neg1 === neg2) {
    return /* Bigint */{
            _0: neg1,
            _1: add$p(value1, value2, 0)
          };
  } else if (cmp(value1, value2) === 1) {
    return /* Bigint */{
            _0: neg1,
            _1: trimzeros(sub$p(value1, value2, 0))
          };
  } else if (cmp(value1, value2) === -1) {
    return /* Bigint */{
            _0: neg2,
            _1: trimzeros(sub$p(value2, value1, 0))
          };
  } else {
    return zero;
  }
}

function sub(param, param$1) {
  var value2 = param$1._1;
  var value1 = param._1;
  var neg1 = param._0;
  if (neg1 === param$1._0) {
    if (cmp(value1, value2) === 1) {
      if (neg1 === /* Neg */1) {
        return /* Bigint */{
                _0: /* Neg */1,
                _1: trimzeros(sub$p(value1, value2, 0))
              };
      } else {
        return /* Bigint */{
                _0: /* Pos */0,
                _1: trimzeros(sub$p(value1, value2, 0))
              };
      }
    } else if (cmp(value1, value2) === -1) {
      if (neg1 === /* Neg */1) {
        return /* Bigint */{
                _0: /* Pos */0,
                _1: trimzeros(sub$p(value2, value1, 0))
              };
      } else {
        return /* Bigint */{
                _0: /* Neg */1,
                _1: trimzeros(sub$p(value2, value1, 0))
              };
      }
    } else {
      return zero;
    }
  } else {
    return /* Bigint */{
            _0: neg1,
            _1: add$p(value1, value2, 0)
          };
  }
}

function mul(param, param$1) {
  var match = mul$p(param._1, param$1._1, {
        hd: 1,
        tl: /* [] */0
      });
  var product = match[1];
  if (param._0 === param$1._0) {
    return /* Bigint */{
            _0: /* Pos */0,
            _1: product
          };
  } else {
    return /* Bigint */{
            _0: /* Neg */1,
            _1: product
          };
  }
}

function div_rem$p(list1, list2$p, powerof2) {
  if (cmp(list2$p, list1) === 1) {
    return [
            /* [] */0,
            list1
          ];
  }
  var match = div_rem$p(list1, add$p(list2$p, list2$p, 0), add$p(powerof2, powerof2, 0));
  var remainder = match[1];
  var quotient = match[0];
  if (cmp(remainder, list2$p) === -1) {
    return [
            quotient,
            remainder
          ];
  } else {
    return [
            add$p(quotient, powerof2, 0),
            trimzeros(sub$p(remainder, list2$p, 0))
          ];
  }
}

function div_rem(param, param$1) {
  var neg1 = param._0;
  var match = div_rem$p(param._1, param$1._1, {
        hd: 1,
        tl: /* [] */0
      });
  var rem = match[1];
  var quotient = match[0];
  var rem$1 = rem === /* [] */0 ? zero : /* Bigint */({
        _0: neg1,
        _1: rem
      });
  if (neg1 === param$1._0) {
    return [
            /* Bigint */{
              _0: /* Pos */0,
              _1: quotient
            },
            rem$1
          ];
  } else {
    return [
            /* Bigint */{
              _0: /* Neg */1,
              _1: quotient
            },
            rem$1
          ];
  }
}

function compare(param, param$1) {
  var v2 = param$1._1;
  var neg2 = param$1._0;
  var v1 = param._1;
  if (param._0) {
    if (neg2) {
      return -cmp(v1, v2) | 0;
    } else {
      return -1;
    }
  } else if (neg2) {
    return 1;
  } else {
    return cmp(v1, v2);
  }
}

function sign(n) {
  if (Caml_obj.equal(n, zero)) {
    return 0;
  } else if (compare(n, zero) < 0) {
    return -1;
  } else {
    return 1;
  }
}

function gt(x, y) {
  return compare(x, y) > 0;
}

function lt(x, y) {
  return compare(x, y) < 0;
}

function div(a, b) {
  return div_rem(a, b)[0];
}

function rem(a, b) {
  return div_rem(a, b)[1];
}

function ediv_rem$p(_t0, _t1, _cum) {
  while(true) {
    var cum = _cum;
    var t1 = _t1;
    var t0 = _t0;
    var v0 = t0._1;
    var t0$p = /* Bigint */{
      _0: /* Pos */0,
      _1: v0
    };
    var v1 = t1._1;
    var t1$p = /* Bigint */{
      _0: /* Pos */0,
      _1: v1
    };
    var r = sub(t0$p, t1$p);
    if (cmp(v0, v1) !== 1) {
      if (cmp(r._1, {
              hd: 0,
              tl: /* [] */0
            }) === 0) {
        return [
                cum,
                r
              ];
      } else {
        return [
                add(cum, one),
                r
              ];
      }
    }
    _cum = add(cum, one);
    _t1 = t1$p;
    _t0 = r;
    continue ;
  };
}

function ediv_rem(a, b) {
  if (Caml_obj.equal(b, zero)) {
    throw {
          RE_EXN_ID: "Division_by_zero",
          Error: new Error()
        };
  }
  if (!a._0) {
    return div_rem(a, b);
  }
  var match = ediv_rem$p(a, b, zero);
  var r = trimzeros(match[1]._1);
  return [
          /* Bigint */{
            _0: /* Neg */1,
            _1: match[0]._1
          },
          /* Bigint */{
            _0: /* Pos */0,
            _1: r
          }
        ];
}

function ediv(a, b) {
  return ediv_rem(a, b)[0];
}

function erem(a, b) {
  return ediv_rem(a, b)[1];
}

function cdiv(a, b) {
  var match = div_rem(a, b);
  var quotient = match[0];
  if (gt(match[1], zero)) {
    return add(quotient, one);
  } else {
    return quotient;
  }
}

function fdiv(a, b) {
  var match = div_rem(a, b);
  var quotient = match[0];
  if (lt(match[1], zero)) {
    return sub(quotient, one);
  } else {
    return quotient;
  }
}

function divexact(a, b) {
  return div_rem(a, b)[0];
}

function is_even(param) {
  var match = div_rem$p(param._1, {
        hd: 2,
        tl: /* [] */0
      }, {
        hd: 1,
        tl: /* [] */0
      });
  var remainder = match[1];
  if (remainder === /* [] */0) {
    return true;
  } else {
    return Caml_obj.equal(remainder, {
                hd: 0,
                tl: /* [] */0
              });
  }
}

function is_odd(a) {
  return !is_even(a);
}

function gcd(x, y) {
  var _a = x;
  var _b = y;
  while(true) {
    var b = _b;
    var a = _a;
    var c = erem(a, b);
    if (Caml_obj.equal(c, zero)) {
      return b;
    }
    _b = c;
    _a = b;
    continue ;
  };
}

function pow(base, exp) {
  if (exp < 0) {
    throw {
          RE_EXN_ID: "Invalid_argument",
          _1: "The exponent must be greater zero or greater.",
          Error: new Error()
        };
  }
  if (exp === 0) {
    return one;
  } else if (exp === 1) {
    return base;
  } else {
    var _exp = exp;
    var _acc = one;
    while(true) {
      var acc = _acc;
      var exp$1 = _exp;
      if (exp$1 <= 0) {
        return acc;
      }
      _acc = mul(acc, base);
      _exp = exp$1 - 1 | 0;
      continue ;
    };
  }
}

function abs(param) {
  return /* Bigint */{
          _0: /* Pos */0,
          _1: param._1
        };
}

function shift_left(x, n) {
  return mul(x, pow(of_string(String(2)), n));
}

function shift_right(x, n) {
  return div(x, pow(of_string(String(2)), n));
}

function neg(param) {
  var n = param._1;
  if (param._0) {
    return /* Bigint */{
            _0: /* Pos */0,
            _1: n
          };
  } else {
    return /* Bigint */{
            _0: /* Neg */1,
            _1: n
          };
  }
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

function succ(x) {
  return add(x, one);
}

function pred(x) {
  return sub(x, one);
}

function numbits(n$p) {
  var result = 0;
  var n = abs(n$p);
  while(gt(n, zero)) {
    result = result + 1 | 0;
    n = div(n, two);
  };
  return result;
}

function logand(n1$p, n2$p) {
  var byte_val = one;
  var result = zero;
  var n1 = n1$p;
  var n2 = n2$p;
  while(gt(n1, zero) || gt(n2, zero)) {
    if (equal(rem(n1, two), one) && equal(rem(n2, two), one)) {
      result = add(result, byte_val);
    }
    n1 = div(n1, two);
    n2 = div(n2, two);
    byte_val = mul(byte_val, two);
  };
  return result;
}

function logor(n1$p, n2$p) {
  var byte_val = one;
  var result = zero;
  var n1 = n1$p;
  var n2 = n2$p;
  while(gt(n1, zero) || gt(n2, zero)) {
    if (equal(rem(n1, two), one) || equal(rem(n2, two), one)) {
      result = add(result, byte_val);
    }
    n1 = div(n1, two);
    n2 = div(n2, two);
    byte_val = mul(byte_val, two);
  };
  return result;
}

function logxor(n1$p, n2$p) {
  var byte_val = one;
  var result = zero;
  var n1 = n1$p;
  var n2 = n2$p;
  while(gt(n1, zero) || gt(n2, zero)) {
    if (!equal(rem(n1, two), rem(n2, two))) {
      result = add(result, byte_val);
    }
    n1 = div(n1, two);
    n2 = div(n2, two);
    byte_val = mul(byte_val, two);
  };
  return result;
}

function lognot(n1) {
  var byte_val = one;
  while(lt(byte_val, n1)) {
    byte_val = mul(byte_val, two);
  };
  return sub(byte_val, n1);
}

function min(x, y) {
  if (leq(x, y)) {
    return x;
  } else {
    return y;
  }
}

function max(x, y) {
  if (geq(x, y)) {
    return x;
  } else {
    return y;
  }
}

function firstNonZero(x) {
  var str = to_string(x);
  var strChars = explode(str);
  return List.fold_right((function (s, param) {
                  var x = param[1];
                  var i = param[0];
                  if (Belt_Option.isNone(x)) {
                    if (s !== /* '0' */48) {
                      return [
                              i,
                              i
                            ];
                    } else {
                      return [
                              i + 1 | 0,
                              x
                            ];
                    }
                  } else {
                    return [
                            i,
                            x
                          ];
                  }
                }), strChars, [
                0,
                undefined
              ])[1];
}

function $tilde$plus(x) {
  return x;
}

function $less$great(x, y) {
  return !equal(x, y);
}

function to_int(i) {
  if (gt(i, of_string(String(Pervasives.max_int))) || lt(i, of_string(String(Pervasives.min_int)))) {
    throw {
          RE_EXN_ID: Overflow,
          Error: new Error()
        };
  }
  return Caml_format.int_of_string(to_string(i));
}

function to_int32(i) {
  if (gt(i, of_string(Int32.to_string(Int32.max_int))) || lt(i, of_string(Int32.to_string(Int32.min_int)))) {
    throw {
          RE_EXN_ID: Overflow,
          Error: new Error()
        };
  }
  return Caml_format.int_of_string(to_string(i));
}

function to_int64(i) {
  if (gt(i, of_string(Int64.to_string(Int64.max_int))) || lt(i, of_string(Int64.to_string(Int64.min_int)))) {
    throw {
          RE_EXN_ID: Overflow,
          Error: new Error()
        };
  }
  return Caml_format.int64_of_string(to_string(i));
}

function to_float(i) {
  return Caml_format.float_of_string(to_string(i));
}

function round_to_float(x, exact) {
  var i = exact ? x : logor(x, one);
  return Caml_format.float_of_string(to_string(i));
}

var minus_one = /* Bigint */{
  _0: /* Neg */1,
  _1: {
    hd: 1,
    tl: /* [] */0
  }
};

var $tilde$neg = neg;

var $plus = add;

var $neg = sub;

var $star = mul;

var $slash = div;

var $slash$great = cdiv;

var $slash$less = fdiv;

var $slash$pipe = divexact;

var mod = rem;

var land = logand;

var lor = logor;

var lxor = logxor;

var $tilde$bang = lognot;

var lsl = shift_left;

var asr = shift_right;

var $tilde$ = of_int;

var $star$star = pow;

var $eq = equal;

var $less = lt;

var $great = gt;

var $less$eq = leq;

var $great$eq = geq;

exports.Overflow = Overflow;
exports.zero = zero;
exports.one = one;
exports.minus_one = minus_one;
exports.of_int = of_int;
exports.of_int32 = of_int32;
exports.of_int64 = of_int64;
exports.of_float = of_float;
exports.of_string = of_string;
exports.of_string_opt = of_string_opt;
exports.of_substring = of_substring;
exports.succ = succ;
exports.pred = pred;
exports.abs = abs;
exports.neg = neg;
exports.add = add;
exports.sub = sub;
exports.mul = mul;
exports.div = div;
exports.rem = rem;
exports.div_rem = div_rem;
exports.cdiv = cdiv;
exports.fdiv = fdiv;
exports.ediv_rem = ediv_rem;
exports.ediv = ediv;
exports.erem = erem;
exports.divexact = divexact;
exports.logand = logand;
exports.logor = logor;
exports.logxor = logxor;
exports.lognot = lognot;
exports.shift_left = shift_left;
exports.shift_right = shift_right;
exports.numbits = numbits;
exports.to_int = to_int;
exports.to_int32 = to_int32;
exports.to_int64 = to_int64;
exports.to_float = to_float;
exports.to_string = to_string;
exports.compare = compare;
exports.equal = equal;
exports.leq = leq;
exports.geq = geq;
exports.lt = lt;
exports.gt = gt;
exports.sign = sign;
exports.min = min;
exports.max = max;
exports.is_even = is_even;
exports.is_odd = is_odd;
exports.gcd = gcd;
exports.pow = pow;
exports.$tilde$neg = $tilde$neg;
exports.$tilde$plus = $tilde$plus;
exports.$plus = $plus;
exports.$neg = $neg;
exports.$star = $star;
exports.$slash = $slash;
exports.$slash$great = $slash$great;
exports.$slash$less = $slash$less;
exports.$slash$pipe = $slash$pipe;
exports.mod = mod;
exports.land = land;
exports.lor = lor;
exports.lxor = lxor;
exports.$tilde$bang = $tilde$bang;
exports.lsl = lsl;
exports.asr = asr;
exports.$tilde$ = $tilde$;
exports.$star$star = $star$star;
exports.$eq = $eq;
exports.$less = $less;
exports.$great = $great;
exports.$less$eq = $less$eq;
exports.$great$eq = $great$eq;
exports.$less$great = $less$great;
exports.round_to_float = round_to_float;
exports.firstNonZero = firstNonZero;
/* No side effect */
