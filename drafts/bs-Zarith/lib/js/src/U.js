'use strict';

var Int64 = require("rescript/lib/js/int64.js");
var Bigint = require("./Bigint.js");
var Belt_Int = require("rescript/lib/js/belt_Int.js");
var Caml_obj = require("rescript/lib/js/caml_obj.js");
var Caml_int32 = require("rescript/lib/js/caml_int32.js");
var Caml_int64 = require("rescript/lib/js/caml_int64.js");
var Caml_format = require("rescript/lib/js/caml_format.js");

function add(x, y) {
  return x + y & 255;
}

function sub(x, y) {
  return x - y & 255;
}

function mul(x, y) {
  return Math.imul(x, y) & 255;
}

var div = Caml_int32.div;

var rem = Caml_int32.mod_;

function logand(prim0, prim1) {
  return prim0 & prim1;
}

function logor(prim0, prim1) {
  return prim0 | prim1;
}

function logxor(prim0, prim1) {
  return prim0 ^ prim1;
}

function shiftLeft(x, y) {
  return (x << y) & 255;
}

function shiftRight(prim0, prim1) {
  return (prim0 >>> prim1) | 0;
}

function ofInt(x) {
  return x & 255;
}

function toInt(x) {
  return x;
}

function ofInt64(x) {
  return Caml_int64.to_int32(x) & 255;
}

var toInt64 = Caml_int64.of_int32;

function ofString(x) {
  var x$1 = Belt_Int.fromString(x);
  if (x$1 !== undefined) {
    return x$1 & 255;
  }
  
}

function toString(prim) {
  return String(prim);
}

var zero = 0;

var one = 1;

function succ(n) {
  return add(n, one);
}

function pred(n) {
  return sub(n, one);
}

function lognot(n) {
  return n ^ 255;
}

var compare = Caml_obj.compare;

var equal = Caml_obj.equal;

var max = Caml_obj.max;

var min = Caml_obj.min;

var Infix = {
  $plus: add,
  $neg: sub,
  $star: mul,
  $slash: div,
  mod: rem,
  land: logand,
  lor: logor,
  lxor: logxor,
  lsl: shiftLeft,
  lsr: shiftRight
};

var UInt8 = {
  add: add,
  sub: sub,
  mul: mul,
  div: div,
  rem: rem,
  maxInt: 255,
  logand: logand,
  logor: logor,
  logxor: logxor,
  shiftLeft: shiftLeft,
  shiftRight: shiftRight,
  ofInt: ofInt,
  toInt: toInt,
  ofInt64: ofInt64,
  toInt64: toInt64,
  ofString: ofString,
  toString: toString,
  zero: zero,
  one: one,
  lognot: lognot,
  succ: succ,
  pred: pred,
  compare: compare,
  equal: equal,
  max: max,
  min: min,
  Infix: Infix
};

function add$1(x, y) {
  return x + y & 65535;
}

function sub$1(x, y) {
  return x - y & 65535;
}

function mul$1(x, y) {
  return Math.imul(x, y) & 65535;
}

var div$1 = Caml_int32.div;

var rem$1 = Caml_int32.mod_;

function logand$1(prim0, prim1) {
  return prim0 & prim1;
}

function logor$1(prim0, prim1) {
  return prim0 | prim1;
}

function logxor$1(prim0, prim1) {
  return prim0 ^ prim1;
}

function shiftLeft$1(x, y) {
  return (x << y) & 65535;
}

function shiftRight$1(prim0, prim1) {
  return (prim0 >>> prim1) | 0;
}

function ofInt$1(x) {
  return x & 65535;
}

function toInt$1(x) {
  return x;
}

function ofInt64$1(x) {
  return Caml_int64.to_int32(x) & 65535;
}

var toInt64$1 = Caml_int64.of_int32;

function ofString$1(x) {
  var x$1 = Belt_Int.fromString(x);
  if (x$1 !== undefined) {
    return x$1 & 65535;
  }
  
}

function toString$1(prim) {
  return String(prim);
}

var zero$1 = 0;

var one$1 = 1;

function succ$1(n) {
  return add$1(n, one$1);
}

function pred$1(n) {
  return sub$1(n, one$1);
}

function lognot$1(n) {
  return n ^ 65535;
}

var compare$1 = Caml_obj.compare;

var equal$1 = Caml_obj.equal;

var max$1 = Caml_obj.max;

var min$1 = Caml_obj.min;

var Infix$1 = {
  $plus: add$1,
  $neg: sub$1,
  $star: mul$1,
  $slash: div$1,
  mod: rem$1,
  land: logand$1,
  lor: logor$1,
  lxor: logxor$1,
  lsl: shiftLeft$1,
  lsr: shiftRight$1
};

var UInt16 = {
  add: add$1,
  sub: sub$1,
  mul: mul$1,
  div: div$1,
  rem: rem$1,
  maxInt: 65535,
  logand: logand$1,
  logor: logor$1,
  logxor: logxor$1,
  shiftLeft: shiftLeft$1,
  shiftRight: shiftRight$1,
  ofInt: ofInt$1,
  toInt: toInt$1,
  ofInt64: ofInt64$1,
  toInt64: toInt64$1,
  ofString: ofString$1,
  toString: toString$1,
  zero: zero$1,
  one: one$1,
  lognot: lognot$1,
  succ: succ$1,
  pred: pred$1,
  compare: compare$1,
  equal: equal$1,
  max: max$1,
  min: min$1,
  Infix: Infix$1
};

var maxInt = Caml_format.int64_of_string("4294967295");

var logand$2 = Caml_int64.and_;

function add$2(x, y) {
  return Caml_int64.and_(Caml_int64.add(x, y), maxInt);
}

function sub$2(x, y) {
  return Caml_int64.and_(Caml_int64.sub(x, y), maxInt);
}

function mul$2(x, y) {
  return Caml_int64.and_(Caml_int64.mul(x, y), maxInt);
}

function div$2(x, y) {
  return Caml_int64.and_(Caml_int64.div(x, y), maxInt);
}

function rem$2(x, y) {
  return Caml_int64.sub(x, Caml_int64.mul(y, Caml_int64.div(x, y)));
}

var logor$2 = Caml_int64.or_;

var logxor$2 = Caml_int64.xor;

var shiftLeft$2 = Caml_int64.lsl_;

var shiftRight$2 = Caml_int64.asr_;

function ofInt$2(x) {
  return Caml_int64.and_(Caml_int64.of_int32(x), maxInt);
}

var toInt$2 = Caml_int64.to_int32;

function ofInt64$2(x) {
  return Caml_int64.and_(Caml_int64.of_int32(Caml_int64.to_int32(x)), maxInt);
}

function toInt64$2(x) {
  return Caml_int64.of_int32(Caml_int64.to_int32(x));
}

function ofString$2(x) {
  var x$1 = Belt_Int.fromString(x);
  if (x$1 !== undefined) {
    return Caml_int64.and_(Caml_int64.of_int32(x$1), maxInt);
  }
  
}

var zero$2 = Caml_int64.and_(Caml_int64.zero, maxInt);

var one$2 = Caml_int64.and_(Caml_int64.one, maxInt);

function succ$2(n) {
  return add$2(n, one$2);
}

function pred$2(n) {
  return sub$2(n, one$2);
}

function lognot$2(n) {
  return Caml_int64.xor(n, maxInt);
}

var compare$2 = Caml_obj.compare;

var equal$2 = Caml_obj.equal;

var max$2 = Caml_obj.max;

var min$2 = Caml_obj.min;

var Infix$2 = {
  $plus: add$2,
  $neg: sub$2,
  $star: mul$2,
  $slash: div$2,
  mod: rem$2,
  land: logand$2,
  lor: logor$2,
  lxor: logxor$2,
  lsl: shiftLeft$2,
  lsr: shiftRight$2
};

var UInt32 = {
  add: add$2,
  sub: sub$2,
  mul: mul$2,
  div: div$2,
  rem: rem$2,
  maxInt: maxInt,
  logand: logand$2,
  logor: logor$2,
  logxor: logxor$2,
  shiftLeft: shiftLeft$2,
  shiftRight: shiftRight$2,
  ofInt: ofInt$2,
  toInt: toInt$2,
  ofInt64: ofInt64$2,
  toInt64: toInt64$2,
  ofString: ofString$2,
  toString: Int64.to_string,
  zero: zero$2,
  one: one$2,
  lognot: lognot$2,
  succ: succ$2,
  pred: pred$2,
  compare: compare$2,
  equal: equal$2,
  max: max$2,
  min: min$2,
  Infix: Infix$2
};

var maxInt$1 = Bigint.of_string("18446744073709551616");

function rem$3(x, y) {
  return Bigint.sub(x, Bigint.mul(y, Bigint.div(x, y)));
}

function reduce(x) {
  if (!Bigint.lt(x, Bigint.zero)) {
    if (Bigint.gt(x, maxInt$1)) {
      return Bigint.sub(Bigint.rem(x, maxInt$1), Bigint.one);
    } else {
      return x;
    }
  }
  var r = Bigint.rem(x, maxInt$1);
  return Bigint.add(maxInt$1, Bigint.add(r, Bigint.one));
}

function add$3(x, y) {
  return reduce(Bigint.add(x, y));
}

function sub$3(x, y) {
  return reduce(Bigint.sub(x, y));
}

function mul$3(x, y) {
  return reduce(Bigint.mul(x, y));
}

function div$3(x, y) {
  return reduce(Bigint.div(x, y));
}

function ofInt$3(x) {
  return reduce(Bigint.of_int(x));
}

var toInt$3 = Bigint.to_int;

function ofInt64$3(x) {
  return reduce(Bigint.of_int(Caml_int64.to_int32(x)));
}

function toInt64$3(x) {
  return Caml_int64.of_int32(Bigint.to_int(x));
}

function ofString$3(x) {
  var _x = Belt_Int.fromString(x);
  if (_x !== undefined) {
    return reduce(Bigint.of_string(x));
  }
  
}

var zero$3 = reduce(Bigint.of_int(0));

var one$3 = reduce(Bigint.of_int(1));

function succ$3(n) {
  return reduce(Bigint.add(n, one$3));
}

function pred$3(n) {
  return reduce(Bigint.sub(n, one$3));
}

function lognot$3(n) {
  return Bigint.logxor(n, maxInt$1);
}

var compare$3 = Caml_obj.compare;

var equal$3 = Caml_obj.equal;

var max$3 = Caml_obj.max;

var min$3 = Caml_obj.min;

var Infix$3 = {
  $plus: add$3,
  $neg: sub$3,
  $star: mul$3,
  $slash: div$3,
  mod: rem$3,
  land: Bigint.logand,
  lor: Bigint.logor,
  lxor: Bigint.logxor,
  lsl: Bigint.shift_left,
  lsr: Bigint.shift_right
};

var UInt64 = {
  add: add$3,
  sub: sub$3,
  mul: mul$3,
  div: div$3,
  rem: rem$3,
  maxInt: maxInt$1,
  logand: Bigint.logand,
  logor: Bigint.logor,
  logxor: Bigint.logxor,
  shiftLeft: Bigint.shift_left,
  shiftRight: Bigint.shift_right,
  ofInt: ofInt$3,
  toInt: toInt$3,
  ofInt64: ofInt64$3,
  toInt64: toInt64$3,
  ofString: ofString$3,
  toString: Bigint.to_string,
  zero: zero$3,
  one: one$3,
  lognot: lognot$3,
  succ: succ$3,
  pred: pred$3,
  compare: compare$3,
  equal: equal$3,
  max: max$3,
  min: min$3,
  Infix: Infix$3
};

exports.UInt8 = UInt8;
exports.UInt16 = UInt16;
exports.UInt32 = UInt32;
exports.UInt64 = UInt64;
/* maxInt Not a pure module */
