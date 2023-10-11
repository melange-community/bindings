'use strict';

var Caml = require("rescript/lib/js/caml.js");
var Int32 = require("rescript/lib/js/int32.js");
var Int64 = require("rescript/lib/js/int64.js");
var Bigint = require("./Bigint.js");
var $$String = require("rescript/lib/js/string.js");
var Caml_obj = require("rescript/lib/js/caml_obj.js");
var Caml_int32 = require("rescript/lib/js/caml_int32.js");
var Caml_int64 = require("rescript/lib/js/caml_int64.js");
var Pervasives = require("rescript/lib/js/pervasives.js");
var Caml_format = require("rescript/lib/js/caml_format.js");
var Caml_exceptions = require("rescript/lib/js/caml_exceptions.js");

var Overflow = /* @__PURE__ */Caml_exceptions.create("Z.ZInt.Overflow");

function of_int(x) {
  return x;
}

function of_int32(prim) {
  return prim;
}

var of_int64 = Caml_int64.to_int32;

function of_float(prim) {
  return prim | 0;
}

var of_string = Caml_format.int_of_string;

function of_substring(s, pos, len) {
  return Caml_format.int_of_string($$String.sub(s, pos, len));
}

function succ(x) {
  return x + 1 | 0;
}

function pred(x) {
  return x - 1 | 0;
}

function neg(prim) {
  return -prim | 0;
}

function add(x, y) {
  return x + y | 0;
}

function sub(x, y) {
  return x - y | 0;
}

function mul(x, y) {
  return Math.imul(x, y);
}

var div = Caml_int32.div;

var rem = Caml_int32.mod_;

function div_rem(a, b) {
  return [
          Caml_int32.div(a, b),
          Caml_int32.mod_(a, b)
        ];
}

function sign(n) {
  if (n === 0) {
    return 0;
  } else if (n < 0) {
    return -1;
  } else {
    return 1;
  }
}

function ediv_rem$p(_a, _b, _cum) {
  while(true) {
    var cum = _cum;
    var b = _b;
    var a = _a;
    var a$1 = Pervasives.abs(a);
    var b$1 = Pervasives.abs(b);
    var r = a$1 - b$1 | 0;
    if (Caml.int_compare(a$1, b$1) !== 1) {
      return [
              cum + 1 | 0,
              r
            ];
    }
    _cum = cum + 1 | 0;
    _b = b$1;
    _a = r;
    continue ;
  };
}

function ediv_rem(a, b) {
  if (a > -1) {
    return div_rem(a, b);
  }
  var match = ediv_rem$p(a, b, 0);
  return [
          -match[0] | 0,
          Pervasives.abs(match[1])
        ];
}

function ediv(a, b) {
  return ediv_rem(a, b)[0];
}

function erem(a, b) {
  return ediv_rem(a, b)[1];
}

function logand(x, y) {
  return x & y;
}

function logor(x, y) {
  return x | y;
}

function logxor(x, y) {
  return x ^ y;
}

var lognot = Pervasives.lnot;

function shift_left(prim0, prim1) {
  return (prim0 << prim1);
}

function shift_right(prim0, prim1) {
  return (prim0 >> prim1);
}

function numbits(n) {
  var nref = n;
  var count = 0;
  while(nref > count) {
    if ((nref & count) === 1) {
      count = count + 1 | 0;
    } else {
      nref = (nref >>> 1);
    }
  };
  return count;
}

function to_int(x) {
  return x;
}

function to_int32(prim) {
  return prim;
}

var to_int64 = Caml_int64.of_int32;

function to_float(prim) {
  return prim;
}

function round_to_float(x, exact) {
  var m = Caml_int64.of_int32(x);
  return Caml_int64.to_float(exact ? m : Caml_int64.or_(m, Caml_int64.one));
}

function to_string(prim) {
  return String(prim);
}

var compare = Caml_obj.compare;

var equal = Caml_obj.equal;

var leq = Caml_obj.lessequal;

var geq = Caml_obj.greaterequal;

var lt = Caml_obj.lessthan;

var gt = Caml_obj.greaterthan;

function cdiv(a, b) {
  var match = div_rem(a, b);
  var quotient = match[0];
  if (Caml_obj.greaterthan(match[1], 0)) {
    return quotient + 1 | 0;
  } else {
    return quotient;
  }
}

function fdiv(a, b) {
  var match = div_rem(a, b);
  var quotient = match[0];
  if (Caml_obj.lessthan(match[1], 0)) {
    return quotient - 1 | 0;
  } else {
    return quotient;
  }
}

var min = Caml_obj.min;

var max = Caml_obj.max;

function is_even(i) {
  return i % 2 === 0;
}

function is_odd(i) {
  return i % 2 !== 0;
}

function gcd(x, y) {
  var _a = x;
  var _b = y;
  while(true) {
    var b = _b;
    var a = _a;
    var c = erem(a, b);
    if (c === 0) {
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
    return 1;
  } else if (exp === 1) {
    return base;
  } else {
    var _exp = exp;
    var _acc = 1;
    while(true) {
      var acc = _acc;
      var exp$1 = _exp;
      if (exp$1 <= 0) {
        return acc;
      }
      _acc = Math.imul(acc, base);
      _exp = exp$1 - 1 | 0;
      continue ;
    };
  }
}

function $tilde$plus(x) {
  return x;
}

function land(prim0, prim1) {
  return prim0 & prim1;
}

function lor(prim0, prim1) {
  return prim0 | prim1;
}

function lxor(prim0, prim1) {
  return prim0 ^ prim1;
}

var $tilde$bang = Pervasives.lnot;

function lsl(prim0, prim1) {
  return (prim0 << prim1);
}

function asr(prim0, prim1) {
  return (prim0 >> prim1);
}

var $star$star = pow;

var $less = Caml_obj.lessthan;

var $great = Caml_obj.greaterthan;

var $less$eq = Caml_obj.lessequal;

var $great$eq = Caml_obj.greaterequal;

function $less$great(a, b) {
  return !Caml_obj.equal(a, b);
}

var ZInt = {
  Overflow: Overflow,
  zero: 0,
  one: 1,
  minus_one: -1,
  of_int: of_int,
  of_int32: of_int32,
  of_int64: of_int64,
  of_bigint: Bigint.to_int,
  of_float: of_float,
  of_string: of_string,
  of_substring: of_substring,
  succ: succ,
  pred: pred,
  abs: Pervasives.abs,
  neg: neg,
  add: add,
  sub: sub,
  mul: mul,
  div: div,
  rem: rem,
  div_rem: div_rem,
  cdiv: cdiv,
  fdiv: fdiv,
  ediv_rem: ediv_rem,
  ediv: ediv,
  erem: erem,
  divexact: div,
  logand: logand,
  logor: logor,
  logxor: logxor,
  lognot: lognot,
  shift_left: shift_left,
  shift_right: shift_right,
  numbits: numbits,
  to_int: to_int,
  to_int32: to_int32,
  to_int64: to_int64,
  to_bigint: Bigint.of_int,
  to_float: to_float,
  round_to_float: round_to_float,
  to_string: to_string,
  compare: compare,
  equal: equal,
  leq: leq,
  geq: geq,
  lt: lt,
  gt: gt,
  sign: sign,
  min: min,
  max: max,
  is_even: is_even,
  is_odd: is_odd,
  gcd: gcd,
  pow: pow,
  $tilde$neg: neg,
  $tilde$plus: $tilde$plus,
  $plus: add,
  $neg: sub,
  $star: mul,
  $slash: div,
  $slash$great: cdiv,
  $slash$less: fdiv,
  $slash$pipe: div,
  mod: rem,
  land: land,
  lor: lor,
  lxor: lxor,
  $tilde$bang: $tilde$bang,
  lsl: lsl,
  asr: asr,
  $tilde$: of_int,
  $star$star: $star$star,
  $eq: equal,
  $less: $less,
  $great: $great,
  $less$eq: $less$eq,
  $great$eq: $great$eq,
  $less$great: $less$great
};

var Overflow$1 = /* @__PURE__ */Caml_exceptions.create("Z.ZInt32.Overflow");

function of_int$1(prim) {
  return prim;
}

function of_int32$1(x) {
  return x;
}

var of_int64$1 = Caml_int64.to_int32;

function of_float$1(prim) {
  return prim | 0;
}

var of_string$1 = Caml_format.int_of_string;

function of_substring$1(s, pos, len) {
  return Caml_format.int_of_string($$String.sub(s, pos, len));
}

function succ$1(x) {
  return x + Int32.one | 0;
}

function pred$1(x) {
  return x - Int32.one | 0;
}

function neg$1(prim) {
  return -prim | 0;
}

function add$1(prim0, prim1) {
  return prim0 + prim1 | 0;
}

function sub$1(prim0, prim1) {
  return prim0 - prim1 | 0;
}

function mul$1(prim0, prim1) {
  return Math.imul(prim0, prim1);
}

function mod(a, n) {
  return a - Math.imul(n, Caml_int32.div(a, n)) | 0;
}

var div$1 = Caml_int32.div;

var rem$1 = mod;

function div_rem$1(a, b) {
  return [
          Caml_int32.div(a, b),
          mod(a, b)
        ];
}

function sign$1(n) {
  if (n === 0) {
    return 0;
  } else if (Int32.compare(n, 0) < 0) {
    return -1;
  } else {
    return 1;
  }
}

function ediv_rem$p$1(_a, _b, _cum) {
  while(true) {
    var cum = _cum;
    var b = _b;
    var a = _a;
    var a$1 = Int32.abs(a);
    var b$1 = Int32.abs(b);
    var r = a$1 - b$1 | 0;
    if (Caml.int_compare(a$1, b$1) !== 1) {
      return [
              cum + Int32.one | 0,
              r
            ];
    }
    _cum = cum + Int32.one | 0;
    _b = b$1;
    _a = r;
    continue ;
  };
}

function gt$1(x, y) {
  return Int32.compare(x, y) > 0;
}

function ediv_rem$1(a, b) {
  if (gt$1(a, Int32.minus_one)) {
    return div_rem$1(a, b);
  }
  var match = ediv_rem$p$1(a, b, Int32.zero);
  return [
          -match[0] | 0,
          Int32.abs(match[1])
        ];
}

function ediv$1(a, b) {
  return ediv_rem$1(a, b)[0];
}

function erem$1(a, b) {
  return ediv_rem$1(a, b)[1];
}

function logand$1(prim0, prim1) {
  return prim0 & prim1;
}

function logor$1(prim0, prim1) {
  return prim0 | prim1;
}

function logxor$1(prim0, prim1) {
  return prim0 ^ prim1;
}

function shift_left$1(prim0, prim1) {
  return (prim0 << prim1);
}

function shift_right$1(prim0, prim1) {
  return (prim0 >> prim1);
}

function numbits$1(n) {
  var nref = n;
  var count = Int32.zero;
  while(nref > count) {
    if ((nref & count) === Int32.one) {
      count = count + Int32.one | 0;
    } else {
      nref = (nref >>> 1);
    }
  };
  return count;
}

function to_int$1(prim) {
  return prim;
}

function to_int32$1(x) {
  return x;
}

var to_int64$1 = Caml_int64.of_int32;

function to_float$1(x) {
  return Caml_int64.to_float(Caml_int64.of_int32(x));
}

function round_to_float$1(x, exact) {
  var m = Caml_int64.of_int32(x);
  return Caml_int64.to_float(exact ? m : Caml_int64.or_(m, Caml_int64.one));
}

function equal$1(x, y) {
  return x === y;
}

function leq$1(x, y) {
  return Int32.compare(x, y) < 1;
}

function geq$1(x, y) {
  return Int32.compare(x, y) > -1;
}

function lt$1(x, y) {
  return Int32.compare(x, y) < 0;
}

function min$1(x, y) {
  if (leq$1(x, y)) {
    return x;
  } else {
    return y;
  }
}

function max$1(x, y) {
  if (geq$1(x, y)) {
    return x;
  } else {
    return y;
  }
}

function cdiv$1(a, b) {
  var match = div_rem$1(a, b);
  var quotient = match[0];
  if (gt$1(match[1], Int32.zero)) {
    return quotient + Int32.one | 0;
  } else {
    return quotient;
  }
}

function fdiv$1(a, b) {
  var match = div_rem$1(a, b);
  var quotient = match[0];
  if (lt$1(match[1], Int32.zero)) {
    return quotient - Int32.one | 0;
  } else {
    return quotient;
  }
}

function is_even$1(i) {
  return mod(i, 2) === Int32.zero;
}

function is_odd$1(i) {
  return mod(i, 2) !== Int32.zero;
}

function gcd$1(x, y) {
  var _a = x;
  var _b = y;
  while(true) {
    var b = _b;
    var a = _a;
    var c = erem$1(a, b);
    if (c === Int32.zero) {
      return b;
    }
    _b = c;
    _a = b;
    continue ;
  };
}

function pow$1(base, exp) {
  if (exp < 0) {
    throw {
          RE_EXN_ID: "Invalid_argument",
          _1: "The exponent must be greater zero or greater.",
          Error: new Error()
        };
  }
  if (exp === 0) {
    return Int32.one;
  } else if (exp === 1) {
    return base;
  } else {
    var _exp = exp;
    var _acc = Int32.one;
    while(true) {
      var acc = _acc;
      var exp$1 = _exp;
      if (exp$1 <= 0) {
        return acc;
      }
      _acc = Math.imul(acc, base);
      _exp = exp$1 - 1 | 0;
      continue ;
    };
  }
}

function $tilde$plus$1(x) {
  return x;
}

var $star$star$1 = pow$1;

var $less$1 = Caml_obj.lessthan;

var $great$1 = Caml_obj.greaterthan;

var $less$eq$1 = Caml_obj.lessequal;

var $great$eq$1 = Caml_obj.greaterequal;

function $less$great$1(a, b) {
  return a !== b;
}

var ZInt32 = {
  Overflow: Overflow$1,
  zero: Int32.zero,
  one: Int32.one,
  minus_one: Int32.minus_one,
  of_int: of_int$1,
  of_int32: of_int32$1,
  of_int64: of_int64$1,
  of_bigint: Bigint.to_int32,
  of_float: of_float$1,
  of_string: of_string$1,
  of_substring: of_substring$1,
  succ: succ$1,
  pred: pred$1,
  abs: Int32.abs,
  neg: neg$1,
  add: add$1,
  sub: sub$1,
  mul: mul$1,
  div: div$1,
  rem: rem$1,
  div_rem: div_rem$1,
  cdiv: cdiv$1,
  fdiv: fdiv$1,
  ediv_rem: ediv_rem$1,
  ediv: ediv$1,
  erem: erem$1,
  divexact: div$1,
  logand: logand$1,
  logor: logor$1,
  logxor: logxor$1,
  lognot: Int32.lognot,
  shift_left: shift_left$1,
  shift_right: shift_right$1,
  numbits: numbits$1,
  to_int: to_int$1,
  to_int32: to_int32$1,
  to_int64: to_int64$1,
  to_bigint: Bigint.of_int32,
  to_float: to_float$1,
  round_to_float: round_to_float$1,
  to_string: Int32.to_string,
  compare: Int32.compare,
  equal: equal$1,
  leq: leq$1,
  geq: geq$1,
  lt: lt$1,
  gt: gt$1,
  sign: sign$1,
  min: min$1,
  max: max$1,
  is_even: is_even$1,
  is_odd: is_odd$1,
  gcd: gcd$1,
  pow: pow$1,
  $tilde$neg: neg$1,
  $tilde$plus: $tilde$plus$1,
  $plus: add$1,
  $neg: sub$1,
  $star: mul$1,
  $slash: div$1,
  $slash$great: cdiv$1,
  $slash$less: fdiv$1,
  $slash$pipe: div$1,
  mod: mod,
  land: logand$1,
  lor: logor$1,
  lxor: logxor$1,
  $tilde$bang: Int32.lognot,
  lsl: shift_left$1,
  asr: shift_right$1,
  $tilde$: of_int$1,
  $star$star: $star$star$1,
  $eq: equal$1,
  $less: $less$1,
  $great: $great$1,
  $less$eq: $less$eq$1,
  $great$eq: $great$eq$1,
  $less$great: $less$great$1
};

var Overflow$2 = /* @__PURE__ */Caml_exceptions.create("Z.ZInt64.Overflow");

var two = [
  0,
  2
];

var of_int$2 = Caml_int64.of_int32;

var of_int32$2 = Caml_int64.of_int32;

function of_int64$2(x) {
  return x;
}

var of_float$2 = Caml_int64.of_float;

var of_string$2 = Caml_format.int64_of_string;

function of_substring$2(s, pos, len) {
  return Caml_format.int64_of_string($$String.sub(s, pos, len));
}

function succ$2(x) {
  return Caml_int64.add(x, Int64.one);
}

function pred$2(x) {
  return Caml_int64.sub(x, Int64.one);
}

var neg$2 = Caml_int64.neg;

var add$2 = Caml_int64.add;

var sub$2 = Caml_int64.sub;

var mul$2 = Caml_int64.mul;

function mod$1(a, n) {
  return Caml_int64.sub(a, Caml_int64.mul(n, Caml_int64.div(a, n)));
}

var div$2 = Caml_int64.div;

var rem$2 = mod$1;

function div_rem$2(a, b) {
  return [
          Caml_int64.div(a, b),
          mod$1(a, b)
        ];
}

function sign$2(n) {
  if (n === Caml_int64.zero) {
    return 0;
  } else if (Int64.compare(n, Caml_int64.zero) < 0) {
    return -1;
  } else {
    return 1;
  }
}

function ediv_rem$p$2(_a, _b, _cum) {
  while(true) {
    var cum = _cum;
    var b = _b;
    var a = _a;
    var a$1 = Int64.abs(a);
    var b$1 = Int64.abs(b);
    var r = Caml_int64.sub(a$1, b$1);
    if (Caml_int64.compare(a$1, b$1) !== 1) {
      return [
              Caml_int64.add(cum, Int64.one),
              r
            ];
    }
    _cum = Caml_int64.add(cum, Int64.one);
    _b = b$1;
    _a = r;
    continue ;
  };
}

function gt$2(x, y) {
  return Int64.compare(x, y) > 0;
}

function ediv_rem$2(a, b) {
  if (gt$2(a, Int64.minus_one)) {
    return div_rem$2(a, b);
  }
  var match = ediv_rem$p$2(a, b, Int64.zero);
  return [
          Caml_int64.neg(match[0]),
          Int64.abs(match[1])
        ];
}

function ediv$2(a, b) {
  return ediv_rem$2(a, b)[0];
}

function erem$2(a, b) {
  return ediv_rem$2(a, b)[1];
}

var logand$2 = Caml_int64.and_;

var logor$2 = Caml_int64.or_;

var logxor$2 = Caml_int64.xor;

var shift_left$2 = Caml_int64.lsl_;

var shift_right$2 = Caml_int64.asr_;

function numbits$2(n) {
  var nref = n;
  var count = Int64.zero;
  while(Caml.i64_gt(nref, count)) {
    if (Caml_int64.and_(nref, count) === Int64.one) {
      count = Caml_int64.add(count, Int64.one);
    } else {
      nref = Caml_int64.lsr_(nref, 1);
    }
  };
  return Caml_int64.to_int32(count);
}

var to_int$2 = Caml_int64.to_int32;

var to_int32$2 = Caml_int64.to_int32;

function to_int64$2(x) {
  return x;
}

var to_float$2 = Caml_int64.to_float;

function round_to_float$2(x, exact) {
  return Caml_int64.to_float(exact ? x : Caml_int64.or_(x, Caml_int64.one));
}

function equal$2(x, y) {
  return x === y;
}

function leq$2(x, y) {
  return Int64.compare(x, y) < 1;
}

function geq$2(x, y) {
  return Int64.compare(x, y) > -1;
}

function lt$2(x, y) {
  return Int64.compare(x, y) < 0;
}

function min$2(x, y) {
  if (leq$2(x, y)) {
    return x;
  } else {
    return y;
  }
}

function max$2(x, y) {
  if (geq$2(x, y)) {
    return x;
  } else {
    return y;
  }
}

function cdiv$2(a, b) {
  var match = div_rem$2(a, b);
  var quotient = match[0];
  if (gt$2(match[1], Int64.zero)) {
    return Caml_int64.add(quotient, Int64.one);
  } else {
    return quotient;
  }
}

function fdiv$2(a, b) {
  var match = div_rem$2(a, b);
  var quotient = match[0];
  if (lt$2(match[1], Int64.zero)) {
    return Caml_int64.sub(quotient, Int64.one);
  } else {
    return quotient;
  }
}

function is_even$2(i) {
  return Caml.i64_eq(mod$1(i, two), Int64.zero);
}

function is_odd$2(i) {
  return Caml.i64_neq(mod$1(i, two), Int64.zero);
}

function gcd$2(x, y) {
  var _a = x;
  var _b = y;
  while(true) {
    var b = _b;
    var a = _a;
    var c = erem$2(a, b);
    if (Caml.i64_eq(c, Int64.zero)) {
      return b;
    }
    _b = c;
    _a = b;
    continue ;
  };
}

function pow$2(base, exp) {
  if (exp < 0) {
    throw {
          RE_EXN_ID: "Invalid_argument",
          _1: "The exponent must be greater zero or greater.",
          Error: new Error()
        };
  }
  if (exp === 0) {
    return Int64.one;
  } else if (exp === 1) {
    return base;
  } else {
    var _exp = exp;
    var _acc = Int64.one;
    while(true) {
      var acc = _acc;
      var exp$1 = _exp;
      if (exp$1 <= 0) {
        return acc;
      }
      _acc = Caml_int64.mul(acc, base);
      _exp = exp$1 - 1 | 0;
      continue ;
    };
  }
}

function $tilde$plus$2(x) {
  return x;
}

var $star$star$2 = pow$2;

var $less$2 = Caml_obj.lessthan;

var $great$2 = Caml_obj.greaterthan;

var $less$eq$2 = Caml_obj.lessequal;

var $great$eq$2 = Caml_obj.greaterequal;

function $less$great$2(a, b) {
  return a !== b;
}

var ZInt64 = {
  Overflow: Overflow$2,
  zero: Int64.zero,
  one: Int64.one,
  minus_one: Int64.minus_one,
  of_int: of_int$2,
  of_int32: of_int32$2,
  of_int64: of_int64$2,
  of_bigint: Bigint.to_int64,
  of_float: of_float$2,
  of_string: of_string$2,
  of_substring: of_substring$2,
  succ: succ$2,
  pred: pred$2,
  abs: Int64.abs,
  neg: neg$2,
  add: add$2,
  sub: sub$2,
  mul: mul$2,
  div: div$2,
  rem: rem$2,
  div_rem: div_rem$2,
  cdiv: cdiv$2,
  fdiv: fdiv$2,
  ediv_rem: ediv_rem$2,
  ediv: ediv$2,
  erem: erem$2,
  divexact: div$2,
  logand: logand$2,
  logor: logor$2,
  logxor: logxor$2,
  lognot: Int64.lognot,
  shift_left: shift_left$2,
  shift_right: shift_right$2,
  numbits: numbits$2,
  to_int: to_int$2,
  to_int32: to_int32$2,
  to_int64: to_int64$2,
  to_bigint: Bigint.of_int64,
  to_float: to_float$2,
  round_to_float: round_to_float$2,
  to_string: Int64.to_string,
  compare: Int64.compare,
  equal: equal$2,
  leq: leq$2,
  geq: geq$2,
  lt: lt$2,
  gt: gt$2,
  sign: sign$2,
  min: min$2,
  max: max$2,
  is_even: is_even$2,
  is_odd: is_odd$2,
  gcd: gcd$2,
  pow: pow$2,
  $tilde$neg: neg$2,
  $tilde$plus: $tilde$plus$2,
  $plus: add$2,
  $neg: sub$2,
  $star: mul$2,
  $slash: div$2,
  $slash$great: cdiv$2,
  $slash$less: fdiv$2,
  $slash$pipe: div$2,
  mod: mod$1,
  land: logand$2,
  lor: logor$2,
  lxor: logxor$2,
  $tilde$bang: Int64.lognot,
  lsl: shift_left$2,
  asr: shift_right$2,
  $tilde$: of_int$2,
  $star$star: $star$star$2,
  $eq: equal$2,
  $less: $less$2,
  $great: $great$2,
  $less$eq: $less$eq$2,
  $great$eq: $great$eq$2,
  $less$great: $less$great$2
};

var Overflow$3 = /* @__PURE__ */Caml_exceptions.create("Z.ZBigint.Overflow");

function of_bigint(x) {
  return x;
}

function to_bigint(x) {
  return x;
}

function $tilde$plus$3(x) {
  return x;
}

var $star$star$3 = Bigint.pow;

var $less$3 = Caml_obj.lessthan;

var $great$3 = Caml_obj.greaterthan;

var $less$eq$3 = Caml_obj.lessequal;

var $great$eq$3 = Caml_obj.greaterequal;

function $less$great$3(a, b) {
  return !Bigint.equal(a, b);
}

var ZBigint = {
  Overflow: Overflow$3,
  zero: Bigint.zero,
  one: Bigint.one,
  minus_one: Bigint.minus_one,
  of_int: Bigint.of_int,
  of_int32: Bigint.of_int32,
  of_int64: Bigint.of_int64,
  of_bigint: of_bigint,
  of_float: Bigint.of_float,
  of_string: Bigint.of_string,
  of_substring: Bigint.of_substring,
  succ: Bigint.succ,
  pred: Bigint.pred,
  abs: Bigint.abs,
  neg: Bigint.neg,
  add: Bigint.add,
  sub: Bigint.sub,
  mul: Bigint.mul,
  div: Bigint.div,
  rem: Bigint.rem,
  div_rem: Bigint.div_rem,
  cdiv: Bigint.cdiv,
  fdiv: Bigint.fdiv,
  ediv_rem: Bigint.ediv_rem,
  ediv: Bigint.ediv,
  erem: Bigint.erem,
  divexact: Bigint.div,
  logand: Bigint.logand,
  logor: Bigint.logor,
  logxor: Bigint.logxor,
  lognot: Bigint.lognot,
  shift_left: Bigint.shift_left,
  shift_right: Bigint.shift_right,
  numbits: Bigint.numbits,
  to_int: Bigint.to_int,
  to_int32: Bigint.to_int32,
  to_int64: Bigint.to_int64,
  to_bigint: to_bigint,
  to_float: Bigint.to_float,
  round_to_float: Bigint.round_to_float,
  to_string: Bigint.to_string,
  compare: Bigint.compare,
  equal: Bigint.equal,
  leq: Bigint.leq,
  geq: Bigint.geq,
  lt: Bigint.lt,
  gt: Bigint.gt,
  sign: Bigint.sign,
  min: Bigint.min,
  max: Bigint.max,
  is_even: Bigint.is_even,
  is_odd: Bigint.is_odd,
  gcd: Bigint.gcd,
  pow: Bigint.pow,
  $tilde$neg: Bigint.neg,
  $tilde$plus: $tilde$plus$3,
  $plus: Bigint.add,
  $neg: Bigint.sub,
  $star: Bigint.mul,
  $slash: Bigint.div,
  $slash$great: Bigint.cdiv,
  $slash$less: Bigint.fdiv,
  $slash$pipe: Bigint.div,
  mod: Bigint.rem,
  land: Bigint.logand,
  lor: Bigint.logor,
  lxor: Bigint.logxor,
  $tilde$bang: Bigint.lognot,
  lsl: Bigint.shift_left,
  asr: Bigint.shift_right,
  $tilde$: Bigint.of_int,
  $star$star: $star$star$3,
  $eq: Bigint.equal,
  $less: $less$3,
  $great: $great$3,
  $less$eq: $less$eq$3,
  $great$eq: $great$eq$3,
  $less$great: $less$great$3
};

var Int = ZInt;

var Int32$1 = ZInt32;

var Int64$1 = ZInt64;

var Bigint$1 = ZBigint;

exports.Int = Int;
exports.Int32 = Int32$1;
exports.Int64 = Int64$1;
exports.Bigint = Bigint$1;
/* No side effect */
