'use strict';

var Z = require("./Z.js");
var Curry = require("rescript/lib/js/curry.js");
var $$String = require("rescript/lib/js/string.js");
var Caml_float = require("rescript/lib/js/caml_float.js");
var Caml_int64 = require("rescript/lib/js/caml_int64.js");
var Pervasives = require("rescript/lib/js/pervasives.js");
var Caml_js_exceptions = require("rescript/lib/js/caml_js_exceptions.js");

function mk(n, d) {
  return {
          num: n,
          den: d
        };
}

function make_real(n, d) {
  if (n === Z.Int.zero || d === Z.Int.one) {
    return {
            num: n,
            den: Z.Int.one
          };
  }
  var g = Curry._2(Z.Int.gcd, n, d);
  if (g === Z.Int.one) {
    return {
            num: n,
            den: d
          };
  } else {
    return {
            num: Curry._2(Z.Int.divexact, n, g),
            den: Curry._2(Z.Int.divexact, d, g)
          };
  }
}

function make(n, d) {
  var sd = Curry._1(Z.Int.sign, d);
  if (sd === 0) {
    return {
            num: Curry._1(Z.Int.of_int, Curry._1(Z.Int.sign, n)),
            den: Z.Int.zero
          };
  } else if (sd > 0) {
    return make_real(n, d);
  } else {
    return make_real(Curry._1(Z.Int.neg, n), Curry._1(Z.Int.neg, d));
  }
}

function eval_of_int(n) {
  return {
          num: n,
          den: Z.Int.one
        };
}

function of_int(n) {
  var n$1 = Curry._1(Z.Int.of_int, n);
  return {
          num: n$1,
          den: Z.Int.one
        };
}

function of_int32(n) {
  var n$1 = Curry._1(Z.Int.of_int32, n);
  return {
          num: n$1,
          den: Z.Int.one
        };
}

function of_int64(n) {
  var n$1 = Curry._1(Z.Int.of_int64, n);
  return {
          num: n$1,
          den: Z.Int.one
        };
}

function of_bigint(n) {
  var n$1 = Curry._1(Z.Int.of_bigint, n);
  return {
          num: n$1,
          den: Z.Int.one
        };
}

function of_ints(n, d) {
  return make(Curry._1(Z.Int.of_int, n), Curry._1(Z.Int.of_int, d));
}

var zero_num = Z.Int.zero;

var zero_den = Z.Int.one;

var zero = {
  num: zero_num,
  den: zero_den
};

var one_num = Z.Int.one;

var one_den = Z.Int.one;

var one = {
  num: one_num,
  den: one_den
};

var minus_one_num = Z.Int.minus_one;

var minus_one_den = Z.Int.one;

var minus_one = {
  num: minus_one_num,
  den: minus_one_den
};

var inf_num = Z.Int.one;

var inf_den = Z.Int.zero;

var inf = {
  num: inf_num,
  den: inf_den
};

var minus_inf_num = Z.Int.minus_one;

var minus_inf_den = Z.Int.zero;

var minus_inf = {
  num: minus_inf_num,
  den: minus_inf_den
};

var undef_num = Z.Int.zero;

var undef_den = Z.Int.zero;

var undef = {
  num: undef_num,
  den: undef_den
};

function of_float(d) {
  if (d === Pervasives.infinity) {
    return inf;
  }
  if (d === Pervasives.neg_infinity) {
    return minus_inf;
  }
  if (Pervasives.classify_float(d) === /* FP_nan */4) {
    return undef;
  }
  var match = Caml_float.frexp_float(d);
  var m = Curry._1(Z.Int.of_float, Caml_float.ldexp_float(match[0], 53));
  var e = match[1] - 53 | 0;
  if (e < 0) {
    return make_real(m, Curry._2(Z.Int.shift_left, Z.Int.one, -e | 0));
  }
  var n = Curry._2(Z.Int.shift_left, m, e);
  return {
          num: n,
          den: Z.Int.one
        };
}

function of_string(s) {
  try {
    var i = $$String.index(s, /* '/' */47);
    return make(Curry._3(Z.Int.of_substring, s, 0, i), Curry._3(Z.Int.of_substring, s, i + 1 | 0, (s.length - i | 0) - 1 | 0));
  }
  catch (raw_exn){
    var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
    if (exn.RE_EXN_ID === "Not_found") {
      if (s === "inf" || s === "+inf") {
        return inf;
      }
      if (s === "-inf") {
        return minus_inf;
      }
      if (s === "undef") {
        return undef;
      }
      var n = Curry._1(Z.Int.of_string, s);
      return {
              num: n,
              den: Z.Int.one
            };
    }
    throw exn;
  }
}

function classify(n) {
  if (n.den !== Z.Int.zero) {
    if (n.num === Z.Int.zero) {
      return /* ZERO */0;
    } else {
      return /* NZERO */4;
    }
  }
  var match = Curry._1(Z.Int.sign, n.num);
  switch (match) {
    case -1 :
        return /* MINF */2;
    case 0 :
        return /* UNDEF */3;
    case 1 :
        return /* INF */1;
    default:
      return /* UNDEF */3;
  }
}

function is_real(n) {
  return n.den !== Z.Int.zero;
}

function num(x) {
  return x.num;
}

function den(x) {
  return x.den;
}

function sign(x) {
  return Curry._1(Z.Int.sign, x.num);
}

function equal(x, y) {
  if (Curry._2(Z.Int.equal, x.num, y.num)) {
    return Curry._2(Z.Int.equal, x.den, y.den);
  } else {
    return false;
  }
}

function compare(x, y) {
  var match = classify(x);
  var match$1 = classify(y);
  var exit = 0;
  var exit$1 = 0;
  switch (match) {
    case /* INF */1 :
        switch (match$1) {
          case /* INF */1 :
              return 0;
          case /* MINF */2 :
              exit = 2;
              break;
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          default:
            exit = 2;
        }
        break;
    case /* MINF */2 :
        if (match$1 !== 1) {
          if (match$1 !== 0) {
            switch (match$1) {
              case /* MINF */2 :
                  return 0;
              case /* UNDEF */3 :
                  exit$1 = 3;
                  break;
              case /* NZERO */4 :
                  exit = 2;
                  break;
              
            }
          } else {
            exit = 2;
          }
        } else {
          exit$1 = 3;
        }
        break;
    case /* UNDEF */3 :
        if (match$1 !== 3) {
          return -1;
        } else {
          return 0;
        }
    case /* ZERO */0 :
    case /* NZERO */4 :
        exit$1 = 3;
        break;
    
  }
  if (exit$1 === 3) {
    switch (match$1) {
      case /* INF */1 :
          return -1;
      case /* MINF */2 :
          exit = 2;
          break;
      case /* UNDEF */3 :
          return 1;
      default:
        exit = 2;
    }
  }
  if (exit === 2 && match < 4) {
    switch (match) {
      case /* ZERO */0 :
          break;
      case /* INF */1 :
          return 1;
      case /* MINF */2 :
          return -1;
      
    }
  }
  if (match$1 !== 2) {
    if (x.den === y.den) {
      return Curry._2(Z.Int.compare, x.num, y.num);
    } else {
      return Curry._2(Z.Int.compare, Curry._2(Z.Int.mul, x.num, y.den), Curry._2(Z.Int.mul, y.num, x.den));
    }
  } else {
    return 1;
  }
}

function min(a, b) {
  if (compare(a, b) <= 0) {
    return a;
  } else {
    return b;
  }
}

function max(a, b) {
  if (compare(a, b) >= 0) {
    return a;
  } else {
    return b;
  }
}

function leq(a, b) {
  return compare(a, b) <= 0;
}

function geq(a, b) {
  return compare(a, b) >= 0;
}

function lt(a, b) {
  return compare(a, b) < 0;
}

function gt(a, b) {
  return compare(a, b) > 0;
}

function to_string(n) {
  var match = classify(n);
  switch (match) {
    case /* ZERO */0 :
        return "0";
    case /* INF */1 :
        return "+inf";
    case /* MINF */2 :
        return "-inf";
    case /* UNDEF */3 :
        return "undef";
    case /* NZERO */4 :
        if (Curry._2(Z.Int.equal, n.den, Z.Int.one)) {
          return Curry._1(Z.Int.to_string, n.num);
        } else {
          return Curry._1(Z.Int.to_string, n.num) + ("/" + Curry._1(Z.Int.to_string, n.den));
        }
    
  }
}

function eval_to_int(x) {
  return Curry._2(Z.Int.div, x.num, x.den);
}

function to_int(x) {
  return Curry._1(Z.Int.to_int, eval_to_int(x));
}

function to_int32(x) {
  return Curry._1(Z.Int.to_int32, eval_to_int(x));
}

function to_int64(x) {
  return Curry._1(Z.Int.to_int64, eval_to_int(x));
}

function to_bigint(x) {
  return Curry._1(Z.Int.to_bigint, eval_to_int(x));
}

function to_float(x) {
  var match = classify(x);
  switch (match) {
    case /* ZERO */0 :
        return 0.0;
    case /* INF */1 :
        return Pervasives.infinity;
    case /* MINF */2 :
        return Pervasives.neg_infinity;
    case /* UNDEF */3 :
        return Number.NaN;
    case /* NZERO */4 :
        var p = x.num;
        var q = x.den;
        var np = Curry._1(Z.Int.numbits, p);
        var nq = Curry._1(Z.Int.numbits, q);
        if (np <= 53 && nq <= 53) {
          return Caml_int64.to_float(Curry._1(Z.Int.to_int64, p)) / Caml_int64.to_float(Curry._1(Z.Int.to_int64, q));
        }
        var n = 55 - (np - nq | 0) | 0;
        var match$1 = n >= 0 ? [
            Curry._2(Z.Int.shift_left, p, n),
            q
          ] : [
            p,
            Curry._2(Z.Int.shift_left, q, -n | 0)
          ];
        var match$2 = Curry._2(Z.Int.ediv_rem, match$1[0], match$1[1]);
        var f = Curry._2(Z.Int.round_to_float, match$2[0], Curry._1(Z.Int.sign, match$2[1]) === 0);
        return Caml_float.ldexp_float(f, -n | 0);
    
  }
}

function neg(x) {
  return {
          num: Curry._1(Z.Int.neg, x.num),
          den: x.den
        };
}

function abs(x) {
  return {
          num: Curry._1(Z.Int.abs, x.num),
          den: x.den
        };
}

function aors(zaors, x, y) {
  if (x.den === y.den) {
    return make_real(Curry._2(zaors, x.num, y.num), x.den);
  } else {
    return make_real(Curry._2(zaors, Curry._2(Z.Int.mul, x.num, y.den), Curry._2(Z.Int.mul, y.num, x.den)), Curry._2(Z.Int.mul, x.den, y.den));
  }
}

function add(x, y) {
  if (!(x.den === Z.Int.zero || y.den === Z.Int.zero)) {
    return aors(Z.Int.add, x, y);
  }
  var match = classify(x);
  var match$1 = classify(y);
  var exit = 0;
  var exit$1 = 0;
  switch (match) {
    case /* ZERO */0 :
        return y;
    case /* INF */1 :
        switch (match$1) {
          case /* MINF */2 :
              return undef;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* INF */1 :
          case /* NZERO */4 :
              exit = 1;
              break;
          
        }
        break;
    case /* MINF */2 :
        switch (match$1) {
          case /* INF */1 :
              return undef;
          case /* MINF */2 :
              exit = 2;
              break;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return minus_inf;
          
        }
        break;
    case /* UNDEF */3 :
        exit$1 = 3;
        break;
    case /* NZERO */4 :
        switch (match$1) {
          case /* INF */1 :
          case /* MINF */2 :
              exit = 2;
              break;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return Pervasives.failwith("impossible case");
          
        }
        break;
    
  }
  if (exit$1 === 3) {
    if (match$1 === 3) {
      return undef;
    }
    if (match$1 === 0) {
      return x;
    }
    exit = 1;
  }
  switch (exit) {
    case 1 :
        if (match >= 3) {
          return undef;
        } else {
          return inf;
        }
    case 2 :
        if (match$1 >= 2) {
          return minus_inf;
        } else {
          return inf;
        }
    
  }
}

function sub(x, y) {
  if (!(x.den === Z.Int.zero || y.den === Z.Int.zero)) {
    return aors(Z.Int.sub, x, y);
  }
  var match = classify(x);
  var match$1 = classify(y);
  var exit = 0;
  var exit$1 = 0;
  switch (match) {
    case /* ZERO */0 :
        return neg(y);
    case /* INF */1 :
        switch (match$1) {
          case /* INF */1 :
              return undef;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* MINF */2 :
          case /* NZERO */4 :
              exit = 1;
              break;
          
        }
        break;
    case /* MINF */2 :
        switch (match$1) {
          case /* INF */1 :
              exit = 2;
              break;
          case /* MINF */2 :
              return undef;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return minus_inf;
          
        }
        break;
    case /* UNDEF */3 :
        exit$1 = 3;
        break;
    case /* NZERO */4 :
        switch (match$1) {
          case /* INF */1 :
          case /* MINF */2 :
              exit = 2;
              break;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return Pervasives.failwith("impossible case");
          
        }
        break;
    
  }
  if (exit$1 === 3) {
    if (match$1 === 3) {
      return undef;
    }
    if (match$1 === 0) {
      return x;
    }
    exit = 1;
  }
  switch (exit) {
    case 1 :
        if (match >= 3) {
          return undef;
        } else {
          return inf;
        }
    case 2 :
        if (match$1 >= 2) {
          return inf;
        } else {
          return minus_inf;
        }
    
  }
}

function mul(x, y) {
  if (x.den === Z.Int.zero || y.den === Z.Int.zero) {
    return {
            num: Curry._1(Z.Int.of_int, Math.imul(Curry._1(Z.Int.sign, x.num), Curry._1(Z.Int.sign, y.num))),
            den: Z.Int.zero
          };
  } else {
    return make_real(Curry._2(Z.Int.mul, x.num, y.num), Curry._2(Z.Int.mul, x.den, y.den));
  }
}

function inv(x) {
  var match = Curry._1(Z.Int.sign, x.num);
  switch (match) {
    case -1 :
        return {
                num: Curry._1(Z.Int.neg, x.den),
                den: Curry._1(Z.Int.neg, x.num)
              };
    case 0 :
        break;
    case 1 :
        return {
                num: x.den,
                den: x.num
              };
    default:
      
  }
  if (x.den === Z.Int.zero) {
    return undef;
  } else {
    return inf;
  }
}

function div(x, y) {
  if (Curry._1(Z.Int.sign, y.num) >= 0) {
    return mul(x, {
                num: y.den,
                den: y.num
              });
  } else {
    return mul(x, {
                num: Curry._1(Z.Int.neg, y.den),
                den: Curry._1(Z.Int.neg, y.num)
              });
  }
}

function mul_2exp(x, n) {
  if (x.den === Z.Int.zero) {
    return x;
  } else {
    return make_real(Curry._2(Z.Int.shift_left, x.num, n), x.den);
  }
}

function div_2exp(x, n) {
  if (x.den === Z.Int.zero) {
    return x;
  } else {
    return make_real(x.num, Curry._2(Z.Int.shift_left, x.den, n));
  }
}

function $tilde$plus(x) {
  return x;
}

function $less$great(a, b) {
  return !equal(a, b);
}

function mk$1(n, d) {
  return {
          num: n,
          den: d
        };
}

function make_real$1(n, d) {
  if (n === Z.Int32.zero || d === Z.Int32.one) {
    return {
            num: n,
            den: Z.Int32.one
          };
  }
  var g = Curry._2(Z.Int32.gcd, n, d);
  if (g === Z.Int32.one) {
    return {
            num: n,
            den: d
          };
  } else {
    return {
            num: Curry._2(Z.Int32.divexact, n, g),
            den: Curry._2(Z.Int32.divexact, d, g)
          };
  }
}

function make$1(n, d) {
  var sd = Curry._1(Z.Int32.sign, d);
  if (sd === 0) {
    return {
            num: Curry._1(Z.Int32.of_int, Curry._1(Z.Int32.sign, n)),
            den: Z.Int32.zero
          };
  } else if (sd > 0) {
    return make_real$1(n, d);
  } else {
    return make_real$1(Curry._1(Z.Int32.neg, n), Curry._1(Z.Int32.neg, d));
  }
}

function eval_of_int$1(n) {
  return {
          num: n,
          den: Z.Int32.one
        };
}

function of_int$1(n) {
  var n$1 = Curry._1(Z.Int32.of_int, n);
  return {
          num: n$1,
          den: Z.Int32.one
        };
}

function of_int32$1(n) {
  var n$1 = Curry._1(Z.Int32.of_int32, n);
  return {
          num: n$1,
          den: Z.Int32.one
        };
}

function of_int64$1(n) {
  var n$1 = Curry._1(Z.Int32.of_int64, n);
  return {
          num: n$1,
          den: Z.Int32.one
        };
}

function of_bigint$1(n) {
  var n$1 = Curry._1(Z.Int32.of_bigint, n);
  return {
          num: n$1,
          den: Z.Int32.one
        };
}

function of_ints$1(n, d) {
  return make$1(Curry._1(Z.Int32.of_int, n), Curry._1(Z.Int32.of_int, d));
}

var zero_num$1 = Z.Int32.zero;

var zero_den$1 = Z.Int32.one;

var zero$1 = {
  num: zero_num$1,
  den: zero_den$1
};

var one_num$1 = Z.Int32.one;

var one_den$1 = Z.Int32.one;

var one$1 = {
  num: one_num$1,
  den: one_den$1
};

var minus_one_num$1 = Z.Int32.minus_one;

var minus_one_den$1 = Z.Int32.one;

var minus_one$1 = {
  num: minus_one_num$1,
  den: minus_one_den$1
};

var inf_num$1 = Z.Int32.one;

var inf_den$1 = Z.Int32.zero;

var inf$1 = {
  num: inf_num$1,
  den: inf_den$1
};

var minus_inf_num$1 = Z.Int32.minus_one;

var minus_inf_den$1 = Z.Int32.zero;

var minus_inf$1 = {
  num: minus_inf_num$1,
  den: minus_inf_den$1
};

var undef_num$1 = Z.Int32.zero;

var undef_den$1 = Z.Int32.zero;

var undef$1 = {
  num: undef_num$1,
  den: undef_den$1
};

function of_float$1(d) {
  if (d === Pervasives.infinity) {
    return inf$1;
  }
  if (d === Pervasives.neg_infinity) {
    return minus_inf$1;
  }
  if (Pervasives.classify_float(d) === /* FP_nan */4) {
    return undef$1;
  }
  var match = Caml_float.frexp_float(d);
  var m = Curry._1(Z.Int32.of_float, Caml_float.ldexp_float(match[0], 53));
  var e = match[1] - 53 | 0;
  if (e < 0) {
    return make_real$1(m, Curry._2(Z.Int32.shift_left, Z.Int32.one, -e | 0));
  }
  var n = Curry._2(Z.Int32.shift_left, m, e);
  return {
          num: n,
          den: Z.Int32.one
        };
}

function of_string$1(s) {
  try {
    var i = $$String.index(s, /* '/' */47);
    return make$1(Curry._3(Z.Int32.of_substring, s, 0, i), Curry._3(Z.Int32.of_substring, s, i + 1 | 0, (s.length - i | 0) - 1 | 0));
  }
  catch (raw_exn){
    var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
    if (exn.RE_EXN_ID === "Not_found") {
      if (s === "inf" || s === "+inf") {
        return inf$1;
      }
      if (s === "-inf") {
        return minus_inf$1;
      }
      if (s === "undef") {
        return undef$1;
      }
      var n = Curry._1(Z.Int32.of_string, s);
      return {
              num: n,
              den: Z.Int32.one
            };
    }
    throw exn;
  }
}

function classify$1(n) {
  if (n.den !== Z.Int32.zero) {
    if (n.num === Z.Int32.zero) {
      return /* ZERO */0;
    } else {
      return /* NZERO */4;
    }
  }
  var match = Curry._1(Z.Int32.sign, n.num);
  switch (match) {
    case -1 :
        return /* MINF */2;
    case 0 :
        return /* UNDEF */3;
    case 1 :
        return /* INF */1;
    default:
      return /* UNDEF */3;
  }
}

function is_real$1(n) {
  return n.den !== Z.Int32.zero;
}

function num$1(x) {
  return x.num;
}

function den$1(x) {
  return x.den;
}

function sign$1(x) {
  return Curry._1(Z.Int32.sign, x.num);
}

function equal$1(x, y) {
  if (Curry._2(Z.Int32.equal, x.num, y.num)) {
    return Curry._2(Z.Int32.equal, x.den, y.den);
  } else {
    return false;
  }
}

function compare$1(x, y) {
  var match = classify$1(x);
  var match$1 = classify$1(y);
  var exit = 0;
  var exit$1 = 0;
  switch (match) {
    case /* INF */1 :
        switch (match$1) {
          case /* INF */1 :
              return 0;
          case /* MINF */2 :
              exit = 2;
              break;
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          default:
            exit = 2;
        }
        break;
    case /* MINF */2 :
        if (match$1 !== 1) {
          if (match$1 !== 0) {
            switch (match$1) {
              case /* MINF */2 :
                  return 0;
              case /* UNDEF */3 :
                  exit$1 = 3;
                  break;
              case /* NZERO */4 :
                  exit = 2;
                  break;
              
            }
          } else {
            exit = 2;
          }
        } else {
          exit$1 = 3;
        }
        break;
    case /* UNDEF */3 :
        if (match$1 !== 3) {
          return -1;
        } else {
          return 0;
        }
    case /* ZERO */0 :
    case /* NZERO */4 :
        exit$1 = 3;
        break;
    
  }
  if (exit$1 === 3) {
    switch (match$1) {
      case /* INF */1 :
          return -1;
      case /* MINF */2 :
          exit = 2;
          break;
      case /* UNDEF */3 :
          return 1;
      default:
        exit = 2;
    }
  }
  if (exit === 2 && match < 4) {
    switch (match) {
      case /* ZERO */0 :
          break;
      case /* INF */1 :
          return 1;
      case /* MINF */2 :
          return -1;
      
    }
  }
  if (match$1 !== 2) {
    if (x.den === y.den) {
      return Curry._2(Z.Int32.compare, x.num, y.num);
    } else {
      return Curry._2(Z.Int32.compare, Curry._2(Z.Int32.mul, x.num, y.den), Curry._2(Z.Int32.mul, y.num, x.den));
    }
  } else {
    return 1;
  }
}

function min$1(a, b) {
  if (compare$1(a, b) <= 0) {
    return a;
  } else {
    return b;
  }
}

function max$1(a, b) {
  if (compare$1(a, b) >= 0) {
    return a;
  } else {
    return b;
  }
}

function leq$1(a, b) {
  return compare$1(a, b) <= 0;
}

function geq$1(a, b) {
  return compare$1(a, b) >= 0;
}

function lt$1(a, b) {
  return compare$1(a, b) < 0;
}

function gt$1(a, b) {
  return compare$1(a, b) > 0;
}

function to_string$1(n) {
  var match = classify$1(n);
  switch (match) {
    case /* ZERO */0 :
        return "0";
    case /* INF */1 :
        return "+inf";
    case /* MINF */2 :
        return "-inf";
    case /* UNDEF */3 :
        return "undef";
    case /* NZERO */4 :
        if (Curry._2(Z.Int32.equal, n.den, Z.Int32.one)) {
          return Curry._1(Z.Int32.to_string, n.num);
        } else {
          return Curry._1(Z.Int32.to_string, n.num) + ("/" + Curry._1(Z.Int32.to_string, n.den));
        }
    
  }
}

function eval_to_int$1(x) {
  return Curry._2(Z.Int32.div, x.num, x.den);
}

function to_int$1(x) {
  return Curry._1(Z.Int32.to_int, eval_to_int$1(x));
}

function to_int32$1(x) {
  return Curry._1(Z.Int32.to_int32, eval_to_int$1(x));
}

function to_int64$1(x) {
  return Curry._1(Z.Int32.to_int64, eval_to_int$1(x));
}

function to_bigint$1(x) {
  return Curry._1(Z.Int32.to_bigint, eval_to_int$1(x));
}

function to_float$1(x) {
  var match = classify$1(x);
  switch (match) {
    case /* ZERO */0 :
        return 0.0;
    case /* INF */1 :
        return Pervasives.infinity;
    case /* MINF */2 :
        return Pervasives.neg_infinity;
    case /* UNDEF */3 :
        return Number.NaN;
    case /* NZERO */4 :
        var p = x.num;
        var q = x.den;
        var np = Curry._1(Z.Int32.numbits, p);
        var nq = Curry._1(Z.Int32.numbits, q);
        if (np <= 53 && nq <= 53) {
          return Caml_int64.to_float(Curry._1(Z.Int32.to_int64, p)) / Caml_int64.to_float(Curry._1(Z.Int32.to_int64, q));
        }
        var n = 55 - (np - nq | 0) | 0;
        var match$1 = n >= 0 ? [
            Curry._2(Z.Int32.shift_left, p, n),
            q
          ] : [
            p,
            Curry._2(Z.Int32.shift_left, q, -n | 0)
          ];
        var match$2 = Curry._2(Z.Int32.ediv_rem, match$1[0], match$1[1]);
        var f = Curry._2(Z.Int32.round_to_float, match$2[0], Curry._1(Z.Int32.sign, match$2[1]) === 0);
        return Caml_float.ldexp_float(f, -n | 0);
    
  }
}

function neg$1(x) {
  return {
          num: Curry._1(Z.Int32.neg, x.num),
          den: x.den
        };
}

function abs$1(x) {
  return {
          num: Curry._1(Z.Int32.abs, x.num),
          den: x.den
        };
}

function aors$1(zaors, x, y) {
  if (x.den === y.den) {
    return make_real$1(Curry._2(zaors, x.num, y.num), x.den);
  } else {
    return make_real$1(Curry._2(zaors, Curry._2(Z.Int32.mul, x.num, y.den), Curry._2(Z.Int32.mul, y.num, x.den)), Curry._2(Z.Int32.mul, x.den, y.den));
  }
}

function add$1(x, y) {
  if (!(x.den === Z.Int32.zero || y.den === Z.Int32.zero)) {
    return aors$1(Z.Int32.add, x, y);
  }
  var match = classify$1(x);
  var match$1 = classify$1(y);
  var exit = 0;
  var exit$1 = 0;
  switch (match) {
    case /* ZERO */0 :
        return y;
    case /* INF */1 :
        switch (match$1) {
          case /* MINF */2 :
              return undef$1;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* INF */1 :
          case /* NZERO */4 :
              exit = 1;
              break;
          
        }
        break;
    case /* MINF */2 :
        switch (match$1) {
          case /* INF */1 :
              return undef$1;
          case /* MINF */2 :
              exit = 2;
              break;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return minus_inf$1;
          
        }
        break;
    case /* UNDEF */3 :
        exit$1 = 3;
        break;
    case /* NZERO */4 :
        switch (match$1) {
          case /* INF */1 :
          case /* MINF */2 :
              exit = 2;
              break;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return Pervasives.failwith("impossible case");
          
        }
        break;
    
  }
  if (exit$1 === 3) {
    if (match$1 === 3) {
      return undef$1;
    }
    if (match$1 === 0) {
      return x;
    }
    exit = 1;
  }
  switch (exit) {
    case 1 :
        if (match >= 3) {
          return undef$1;
        } else {
          return inf$1;
        }
    case 2 :
        if (match$1 >= 2) {
          return minus_inf$1;
        } else {
          return inf$1;
        }
    
  }
}

function sub$1(x, y) {
  if (!(x.den === Z.Int32.zero || y.den === Z.Int32.zero)) {
    return aors$1(Z.Int32.sub, x, y);
  }
  var match = classify$1(x);
  var match$1 = classify$1(y);
  var exit = 0;
  var exit$1 = 0;
  switch (match) {
    case /* ZERO */0 :
        return neg$1(y);
    case /* INF */1 :
        switch (match$1) {
          case /* INF */1 :
              return undef$1;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* MINF */2 :
          case /* NZERO */4 :
              exit = 1;
              break;
          
        }
        break;
    case /* MINF */2 :
        switch (match$1) {
          case /* INF */1 :
              exit = 2;
              break;
          case /* MINF */2 :
              return undef$1;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return minus_inf$1;
          
        }
        break;
    case /* UNDEF */3 :
        exit$1 = 3;
        break;
    case /* NZERO */4 :
        switch (match$1) {
          case /* INF */1 :
          case /* MINF */2 :
              exit = 2;
              break;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return Pervasives.failwith("impossible case");
          
        }
        break;
    
  }
  if (exit$1 === 3) {
    if (match$1 === 3) {
      return undef$1;
    }
    if (match$1 === 0) {
      return x;
    }
    exit = 1;
  }
  switch (exit) {
    case 1 :
        if (match >= 3) {
          return undef$1;
        } else {
          return inf$1;
        }
    case 2 :
        if (match$1 >= 2) {
          return inf$1;
        } else {
          return minus_inf$1;
        }
    
  }
}

function mul$1(x, y) {
  if (x.den === Z.Int32.zero || y.den === Z.Int32.zero) {
    return {
            num: Curry._1(Z.Int32.of_int, Math.imul(Curry._1(Z.Int32.sign, x.num), Curry._1(Z.Int32.sign, y.num))),
            den: Z.Int32.zero
          };
  } else {
    return make_real$1(Curry._2(Z.Int32.mul, x.num, y.num), Curry._2(Z.Int32.mul, x.den, y.den));
  }
}

function inv$1(x) {
  var match = Curry._1(Z.Int32.sign, x.num);
  switch (match) {
    case -1 :
        return {
                num: Curry._1(Z.Int32.neg, x.den),
                den: Curry._1(Z.Int32.neg, x.num)
              };
    case 0 :
        break;
    case 1 :
        return {
                num: x.den,
                den: x.num
              };
    default:
      
  }
  if (x.den === Z.Int32.zero) {
    return undef$1;
  } else {
    return inf$1;
  }
}

function div$1(x, y) {
  if (Curry._1(Z.Int32.sign, y.num) >= 0) {
    return mul$1(x, {
                num: y.den,
                den: y.num
              });
  } else {
    return mul$1(x, {
                num: Curry._1(Z.Int32.neg, y.den),
                den: Curry._1(Z.Int32.neg, y.num)
              });
  }
}

function mul_2exp$1(x, n) {
  if (x.den === Z.Int32.zero) {
    return x;
  } else {
    return make_real$1(Curry._2(Z.Int32.shift_left, x.num, n), x.den);
  }
}

function div_2exp$1(x, n) {
  if (x.den === Z.Int32.zero) {
    return x;
  } else {
    return make_real$1(x.num, Curry._2(Z.Int32.shift_left, x.den, n));
  }
}

function $tilde$plus$1(x) {
  return x;
}

function $less$great$1(a, b) {
  return !equal$1(a, b);
}

function mk$2(n, d) {
  return {
          num: n,
          den: d
        };
}

function make_real$2(n, d) {
  if (n === Z.Int64.zero || d === Z.Int64.one) {
    return {
            num: n,
            den: Z.Int64.one
          };
  }
  var g = Curry._2(Z.Int64.gcd, n, d);
  if (g === Z.Int64.one) {
    return {
            num: n,
            den: d
          };
  } else {
    return {
            num: Curry._2(Z.Int64.divexact, n, g),
            den: Curry._2(Z.Int64.divexact, d, g)
          };
  }
}

function make$2(n, d) {
  var sd = Curry._1(Z.Int64.sign, d);
  if (sd === 0) {
    return {
            num: Curry._1(Z.Int64.of_int, Curry._1(Z.Int64.sign, n)),
            den: Z.Int64.zero
          };
  } else if (sd > 0) {
    return make_real$2(n, d);
  } else {
    return make_real$2(Curry._1(Z.Int64.neg, n), Curry._1(Z.Int64.neg, d));
  }
}

function eval_of_int$2(n) {
  return {
          num: n,
          den: Z.Int64.one
        };
}

function of_int$2(n) {
  var n$1 = Curry._1(Z.Int64.of_int, n);
  return {
          num: n$1,
          den: Z.Int64.one
        };
}

function of_int32$2(n) {
  var n$1 = Curry._1(Z.Int64.of_int32, n);
  return {
          num: n$1,
          den: Z.Int64.one
        };
}

function of_int64$2(n) {
  var n$1 = Curry._1(Z.Int64.of_int64, n);
  return {
          num: n$1,
          den: Z.Int64.one
        };
}

function of_bigint$2(n) {
  var n$1 = Curry._1(Z.Int64.of_bigint, n);
  return {
          num: n$1,
          den: Z.Int64.one
        };
}

function of_ints$2(n, d) {
  return make$2(Curry._1(Z.Int64.of_int, n), Curry._1(Z.Int64.of_int, d));
}

var zero_num$2 = Z.Int64.zero;

var zero_den$2 = Z.Int64.one;

var zero$2 = {
  num: zero_num$2,
  den: zero_den$2
};

var one_num$2 = Z.Int64.one;

var one_den$2 = Z.Int64.one;

var one$2 = {
  num: one_num$2,
  den: one_den$2
};

var minus_one_num$2 = Z.Int64.minus_one;

var minus_one_den$2 = Z.Int64.one;

var minus_one$2 = {
  num: minus_one_num$2,
  den: minus_one_den$2
};

var inf_num$2 = Z.Int64.one;

var inf_den$2 = Z.Int64.zero;

var inf$2 = {
  num: inf_num$2,
  den: inf_den$2
};

var minus_inf_num$2 = Z.Int64.minus_one;

var minus_inf_den$2 = Z.Int64.zero;

var minus_inf$2 = {
  num: minus_inf_num$2,
  den: minus_inf_den$2
};

var undef_num$2 = Z.Int64.zero;

var undef_den$2 = Z.Int64.zero;

var undef$2 = {
  num: undef_num$2,
  den: undef_den$2
};

function of_float$2(d) {
  if (d === Pervasives.infinity) {
    return inf$2;
  }
  if (d === Pervasives.neg_infinity) {
    return minus_inf$2;
  }
  if (Pervasives.classify_float(d) === /* FP_nan */4) {
    return undef$2;
  }
  var match = Caml_float.frexp_float(d);
  var m = Curry._1(Z.Int64.of_float, Caml_float.ldexp_float(match[0], 53));
  var e = match[1] - 53 | 0;
  if (e < 0) {
    return make_real$2(m, Curry._2(Z.Int64.shift_left, Z.Int64.one, -e | 0));
  }
  var n = Curry._2(Z.Int64.shift_left, m, e);
  return {
          num: n,
          den: Z.Int64.one
        };
}

function of_string$2(s) {
  try {
    var i = $$String.index(s, /* '/' */47);
    return make$2(Curry._3(Z.Int64.of_substring, s, 0, i), Curry._3(Z.Int64.of_substring, s, i + 1 | 0, (s.length - i | 0) - 1 | 0));
  }
  catch (raw_exn){
    var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
    if (exn.RE_EXN_ID === "Not_found") {
      if (s === "inf" || s === "+inf") {
        return inf$2;
      }
      if (s === "-inf") {
        return minus_inf$2;
      }
      if (s === "undef") {
        return undef$2;
      }
      var n = Curry._1(Z.Int64.of_string, s);
      return {
              num: n,
              den: Z.Int64.one
            };
    }
    throw exn;
  }
}

function classify$2(n) {
  if (n.den !== Z.Int64.zero) {
    if (n.num === Z.Int64.zero) {
      return /* ZERO */0;
    } else {
      return /* NZERO */4;
    }
  }
  var match = Curry._1(Z.Int64.sign, n.num);
  switch (match) {
    case -1 :
        return /* MINF */2;
    case 0 :
        return /* UNDEF */3;
    case 1 :
        return /* INF */1;
    default:
      return /* UNDEF */3;
  }
}

function is_real$2(n) {
  return n.den !== Z.Int64.zero;
}

function num$2(x) {
  return x.num;
}

function den$2(x) {
  return x.den;
}

function sign$2(x) {
  return Curry._1(Z.Int64.sign, x.num);
}

function equal$2(x, y) {
  if (Curry._2(Z.Int64.equal, x.num, y.num)) {
    return Curry._2(Z.Int64.equal, x.den, y.den);
  } else {
    return false;
  }
}

function compare$2(x, y) {
  var match = classify$2(x);
  var match$1 = classify$2(y);
  var exit = 0;
  var exit$1 = 0;
  switch (match) {
    case /* INF */1 :
        switch (match$1) {
          case /* INF */1 :
              return 0;
          case /* MINF */2 :
              exit = 2;
              break;
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          default:
            exit = 2;
        }
        break;
    case /* MINF */2 :
        if (match$1 !== 1) {
          if (match$1 !== 0) {
            switch (match$1) {
              case /* MINF */2 :
                  return 0;
              case /* UNDEF */3 :
                  exit$1 = 3;
                  break;
              case /* NZERO */4 :
                  exit = 2;
                  break;
              
            }
          } else {
            exit = 2;
          }
        } else {
          exit$1 = 3;
        }
        break;
    case /* UNDEF */3 :
        if (match$1 !== 3) {
          return -1;
        } else {
          return 0;
        }
    case /* ZERO */0 :
    case /* NZERO */4 :
        exit$1 = 3;
        break;
    
  }
  if (exit$1 === 3) {
    switch (match$1) {
      case /* INF */1 :
          return -1;
      case /* MINF */2 :
          exit = 2;
          break;
      case /* UNDEF */3 :
          return 1;
      default:
        exit = 2;
    }
  }
  if (exit === 2 && match < 4) {
    switch (match) {
      case /* ZERO */0 :
          break;
      case /* INF */1 :
          return 1;
      case /* MINF */2 :
          return -1;
      
    }
  }
  if (match$1 !== 2) {
    if (x.den === y.den) {
      return Curry._2(Z.Int64.compare, x.num, y.num);
    } else {
      return Curry._2(Z.Int64.compare, Curry._2(Z.Int64.mul, x.num, y.den), Curry._2(Z.Int64.mul, y.num, x.den));
    }
  } else {
    return 1;
  }
}

function min$2(a, b) {
  if (compare$2(a, b) <= 0) {
    return a;
  } else {
    return b;
  }
}

function max$2(a, b) {
  if (compare$2(a, b) >= 0) {
    return a;
  } else {
    return b;
  }
}

function leq$2(a, b) {
  return compare$2(a, b) <= 0;
}

function geq$2(a, b) {
  return compare$2(a, b) >= 0;
}

function lt$2(a, b) {
  return compare$2(a, b) < 0;
}

function gt$2(a, b) {
  return compare$2(a, b) > 0;
}

function to_string$2(n) {
  var match = classify$2(n);
  switch (match) {
    case /* ZERO */0 :
        return "0";
    case /* INF */1 :
        return "+inf";
    case /* MINF */2 :
        return "-inf";
    case /* UNDEF */3 :
        return "undef";
    case /* NZERO */4 :
        if (Curry._2(Z.Int64.equal, n.den, Z.Int64.one)) {
          return Curry._1(Z.Int64.to_string, n.num);
        } else {
          return Curry._1(Z.Int64.to_string, n.num) + ("/" + Curry._1(Z.Int64.to_string, n.den));
        }
    
  }
}

function eval_to_int$2(x) {
  return Curry._2(Z.Int64.div, x.num, x.den);
}

function to_int$2(x) {
  return Curry._1(Z.Int64.to_int, eval_to_int$2(x));
}

function to_int32$2(x) {
  return Curry._1(Z.Int64.to_int32, eval_to_int$2(x));
}

function to_int64$2(x) {
  return Curry._1(Z.Int64.to_int64, eval_to_int$2(x));
}

function to_bigint$2(x) {
  return Curry._1(Z.Int64.to_bigint, eval_to_int$2(x));
}

function to_float$2(x) {
  var match = classify$2(x);
  switch (match) {
    case /* ZERO */0 :
        return 0.0;
    case /* INF */1 :
        return Pervasives.infinity;
    case /* MINF */2 :
        return Pervasives.neg_infinity;
    case /* UNDEF */3 :
        return Number.NaN;
    case /* NZERO */4 :
        var p = x.num;
        var q = x.den;
        var np = Curry._1(Z.Int64.numbits, p);
        var nq = Curry._1(Z.Int64.numbits, q);
        if (np <= 53 && nq <= 53) {
          return Caml_int64.to_float(Curry._1(Z.Int64.to_int64, p)) / Caml_int64.to_float(Curry._1(Z.Int64.to_int64, q));
        }
        var n = 55 - (np - nq | 0) | 0;
        var match$1 = n >= 0 ? [
            Curry._2(Z.Int64.shift_left, p, n),
            q
          ] : [
            p,
            Curry._2(Z.Int64.shift_left, q, -n | 0)
          ];
        var match$2 = Curry._2(Z.Int64.ediv_rem, match$1[0], match$1[1]);
        var f = Curry._2(Z.Int64.round_to_float, match$2[0], Curry._1(Z.Int64.sign, match$2[1]) === 0);
        return Caml_float.ldexp_float(f, -n | 0);
    
  }
}

function neg$2(x) {
  return {
          num: Curry._1(Z.Int64.neg, x.num),
          den: x.den
        };
}

function abs$2(x) {
  return {
          num: Curry._1(Z.Int64.abs, x.num),
          den: x.den
        };
}

function aors$2(zaors, x, y) {
  if (x.den === y.den) {
    return make_real$2(Curry._2(zaors, x.num, y.num), x.den);
  } else {
    return make_real$2(Curry._2(zaors, Curry._2(Z.Int64.mul, x.num, y.den), Curry._2(Z.Int64.mul, y.num, x.den)), Curry._2(Z.Int64.mul, x.den, y.den));
  }
}

function add$2(x, y) {
  if (!(x.den === Z.Int64.zero || y.den === Z.Int64.zero)) {
    return aors$2(Z.Int64.add, x, y);
  }
  var match = classify$2(x);
  var match$1 = classify$2(y);
  var exit = 0;
  var exit$1 = 0;
  switch (match) {
    case /* ZERO */0 :
        return y;
    case /* INF */1 :
        switch (match$1) {
          case /* MINF */2 :
              return undef$2;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* INF */1 :
          case /* NZERO */4 :
              exit = 1;
              break;
          
        }
        break;
    case /* MINF */2 :
        switch (match$1) {
          case /* INF */1 :
              return undef$2;
          case /* MINF */2 :
              exit = 2;
              break;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return minus_inf$2;
          
        }
        break;
    case /* UNDEF */3 :
        exit$1 = 3;
        break;
    case /* NZERO */4 :
        switch (match$1) {
          case /* INF */1 :
          case /* MINF */2 :
              exit = 2;
              break;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return Pervasives.failwith("impossible case");
          
        }
        break;
    
  }
  if (exit$1 === 3) {
    if (match$1 === 3) {
      return undef$2;
    }
    if (match$1 === 0) {
      return x;
    }
    exit = 1;
  }
  switch (exit) {
    case 1 :
        if (match >= 3) {
          return undef$2;
        } else {
          return inf$2;
        }
    case 2 :
        if (match$1 >= 2) {
          return minus_inf$2;
        } else {
          return inf$2;
        }
    
  }
}

function sub$2(x, y) {
  if (!(x.den === Z.Int64.zero || y.den === Z.Int64.zero)) {
    return aors$2(Z.Int64.sub, x, y);
  }
  var match = classify$2(x);
  var match$1 = classify$2(y);
  var exit = 0;
  var exit$1 = 0;
  switch (match) {
    case /* ZERO */0 :
        return neg$2(y);
    case /* INF */1 :
        switch (match$1) {
          case /* INF */1 :
              return undef$2;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* MINF */2 :
          case /* NZERO */4 :
              exit = 1;
              break;
          
        }
        break;
    case /* MINF */2 :
        switch (match$1) {
          case /* INF */1 :
              exit = 2;
              break;
          case /* MINF */2 :
              return undef$2;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return minus_inf$2;
          
        }
        break;
    case /* UNDEF */3 :
        exit$1 = 3;
        break;
    case /* NZERO */4 :
        switch (match$1) {
          case /* INF */1 :
          case /* MINF */2 :
              exit = 2;
              break;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return Pervasives.failwith("impossible case");
          
        }
        break;
    
  }
  if (exit$1 === 3) {
    if (match$1 === 3) {
      return undef$2;
    }
    if (match$1 === 0) {
      return x;
    }
    exit = 1;
  }
  switch (exit) {
    case 1 :
        if (match >= 3) {
          return undef$2;
        } else {
          return inf$2;
        }
    case 2 :
        if (match$1 >= 2) {
          return inf$2;
        } else {
          return minus_inf$2;
        }
    
  }
}

function mul$2(x, y) {
  if (x.den === Z.Int64.zero || y.den === Z.Int64.zero) {
    return {
            num: Curry._1(Z.Int64.of_int, Math.imul(Curry._1(Z.Int64.sign, x.num), Curry._1(Z.Int64.sign, y.num))),
            den: Z.Int64.zero
          };
  } else {
    return make_real$2(Curry._2(Z.Int64.mul, x.num, y.num), Curry._2(Z.Int64.mul, x.den, y.den));
  }
}

function inv$2(x) {
  var match = Curry._1(Z.Int64.sign, x.num);
  switch (match) {
    case -1 :
        return {
                num: Curry._1(Z.Int64.neg, x.den),
                den: Curry._1(Z.Int64.neg, x.num)
              };
    case 0 :
        break;
    case 1 :
        return {
                num: x.den,
                den: x.num
              };
    default:
      
  }
  if (x.den === Z.Int64.zero) {
    return undef$2;
  } else {
    return inf$2;
  }
}

function div$2(x, y) {
  if (Curry._1(Z.Int64.sign, y.num) >= 0) {
    return mul$2(x, {
                num: y.den,
                den: y.num
              });
  } else {
    return mul$2(x, {
                num: Curry._1(Z.Int64.neg, y.den),
                den: Curry._1(Z.Int64.neg, y.num)
              });
  }
}

function mul_2exp$2(x, n) {
  if (x.den === Z.Int64.zero) {
    return x;
  } else {
    return make_real$2(Curry._2(Z.Int64.shift_left, x.num, n), x.den);
  }
}

function div_2exp$2(x, n) {
  if (x.den === Z.Int64.zero) {
    return x;
  } else {
    return make_real$2(x.num, Curry._2(Z.Int64.shift_left, x.den, n));
  }
}

function $tilde$plus$2(x) {
  return x;
}

function $less$great$2(a, b) {
  return !equal$2(a, b);
}

function mk$3(n, d) {
  return {
          num: n,
          den: d
        };
}

function make_real$3(n, d) {
  if (n === Z.Bigint.zero || d === Z.Bigint.one) {
    return {
            num: n,
            den: Z.Bigint.one
          };
  }
  var g = Curry._2(Z.Bigint.gcd, n, d);
  if (g === Z.Bigint.one) {
    return {
            num: n,
            den: d
          };
  } else {
    return {
            num: Curry._2(Z.Bigint.divexact, n, g),
            den: Curry._2(Z.Bigint.divexact, d, g)
          };
  }
}

function make$3(n, d) {
  var sd = Curry._1(Z.Bigint.sign, d);
  if (sd === 0) {
    return {
            num: Curry._1(Z.Bigint.of_int, Curry._1(Z.Bigint.sign, n)),
            den: Z.Bigint.zero
          };
  } else if (sd > 0) {
    return make_real$3(n, d);
  } else {
    return make_real$3(Curry._1(Z.Bigint.neg, n), Curry._1(Z.Bigint.neg, d));
  }
}

function eval_of_int$3(n) {
  return {
          num: n,
          den: Z.Bigint.one
        };
}

function of_int$3(n) {
  var n$1 = Curry._1(Z.Bigint.of_int, n);
  return {
          num: n$1,
          den: Z.Bigint.one
        };
}

function of_int32$3(n) {
  var n$1 = Curry._1(Z.Bigint.of_int32, n);
  return {
          num: n$1,
          den: Z.Bigint.one
        };
}

function of_int64$3(n) {
  var n$1 = Curry._1(Z.Bigint.of_int64, n);
  return {
          num: n$1,
          den: Z.Bigint.one
        };
}

function of_bigint$3(n) {
  var n$1 = Curry._1(Z.Bigint.of_bigint, n);
  return {
          num: n$1,
          den: Z.Bigint.one
        };
}

function of_ints$3(n, d) {
  return make$3(Curry._1(Z.Bigint.of_int, n), Curry._1(Z.Bigint.of_int, d));
}

var zero_num$3 = Z.Bigint.zero;

var zero_den$3 = Z.Bigint.one;

var zero$3 = {
  num: zero_num$3,
  den: zero_den$3
};

var one_num$3 = Z.Bigint.one;

var one_den$3 = Z.Bigint.one;

var one$3 = {
  num: one_num$3,
  den: one_den$3
};

var minus_one_num$3 = Z.Bigint.minus_one;

var minus_one_den$3 = Z.Bigint.one;

var minus_one$3 = {
  num: minus_one_num$3,
  den: minus_one_den$3
};

var inf_num$3 = Z.Bigint.one;

var inf_den$3 = Z.Bigint.zero;

var inf$3 = {
  num: inf_num$3,
  den: inf_den$3
};

var minus_inf_num$3 = Z.Bigint.minus_one;

var minus_inf_den$3 = Z.Bigint.zero;

var minus_inf$3 = {
  num: minus_inf_num$3,
  den: minus_inf_den$3
};

var undef_num$3 = Z.Bigint.zero;

var undef_den$3 = Z.Bigint.zero;

var undef$3 = {
  num: undef_num$3,
  den: undef_den$3
};

function of_float$3(d) {
  if (d === Pervasives.infinity) {
    return inf$3;
  }
  if (d === Pervasives.neg_infinity) {
    return minus_inf$3;
  }
  if (Pervasives.classify_float(d) === /* FP_nan */4) {
    return undef$3;
  }
  var match = Caml_float.frexp_float(d);
  var m = Curry._1(Z.Bigint.of_float, Caml_float.ldexp_float(match[0], 53));
  var e = match[1] - 53 | 0;
  if (e < 0) {
    return make_real$3(m, Curry._2(Z.Bigint.shift_left, Z.Bigint.one, -e | 0));
  }
  var n = Curry._2(Z.Bigint.shift_left, m, e);
  return {
          num: n,
          den: Z.Bigint.one
        };
}

function of_string$3(s) {
  try {
    var i = $$String.index(s, /* '/' */47);
    return make$3(Curry._3(Z.Bigint.of_substring, s, 0, i), Curry._3(Z.Bigint.of_substring, s, i + 1 | 0, (s.length - i | 0) - 1 | 0));
  }
  catch (raw_exn){
    var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
    if (exn.RE_EXN_ID === "Not_found") {
      if (s === "inf" || s === "+inf") {
        return inf$3;
      }
      if (s === "-inf") {
        return minus_inf$3;
      }
      if (s === "undef") {
        return undef$3;
      }
      var n = Curry._1(Z.Bigint.of_string, s);
      return {
              num: n,
              den: Z.Bigint.one
            };
    }
    throw exn;
  }
}

function classify$3(n) {
  if (n.den !== Z.Bigint.zero) {
    if (n.num === Z.Bigint.zero) {
      return /* ZERO */0;
    } else {
      return /* NZERO */4;
    }
  }
  var match = Curry._1(Z.Bigint.sign, n.num);
  switch (match) {
    case -1 :
        return /* MINF */2;
    case 0 :
        return /* UNDEF */3;
    case 1 :
        return /* INF */1;
    default:
      return /* UNDEF */3;
  }
}

function is_real$3(n) {
  return n.den !== Z.Bigint.zero;
}

function num$3(x) {
  return x.num;
}

function den$3(x) {
  return x.den;
}

function sign$3(x) {
  return Curry._1(Z.Bigint.sign, x.num);
}

function equal$3(x, y) {
  if (Curry._2(Z.Bigint.equal, x.num, y.num)) {
    return Curry._2(Z.Bigint.equal, x.den, y.den);
  } else {
    return false;
  }
}

function compare$3(x, y) {
  var match = classify$3(x);
  var match$1 = classify$3(y);
  var exit = 0;
  var exit$1 = 0;
  switch (match) {
    case /* INF */1 :
        switch (match$1) {
          case /* INF */1 :
              return 0;
          case /* MINF */2 :
              exit = 2;
              break;
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          default:
            exit = 2;
        }
        break;
    case /* MINF */2 :
        if (match$1 !== 1) {
          if (match$1 !== 0) {
            switch (match$1) {
              case /* MINF */2 :
                  return 0;
              case /* UNDEF */3 :
                  exit$1 = 3;
                  break;
              case /* NZERO */4 :
                  exit = 2;
                  break;
              
            }
          } else {
            exit = 2;
          }
        } else {
          exit$1 = 3;
        }
        break;
    case /* UNDEF */3 :
        if (match$1 !== 3) {
          return -1;
        } else {
          return 0;
        }
    case /* ZERO */0 :
    case /* NZERO */4 :
        exit$1 = 3;
        break;
    
  }
  if (exit$1 === 3) {
    switch (match$1) {
      case /* INF */1 :
          return -1;
      case /* MINF */2 :
          exit = 2;
          break;
      case /* UNDEF */3 :
          return 1;
      default:
        exit = 2;
    }
  }
  if (exit === 2 && match < 4) {
    switch (match) {
      case /* ZERO */0 :
          break;
      case /* INF */1 :
          return 1;
      case /* MINF */2 :
          return -1;
      
    }
  }
  if (match$1 !== 2) {
    if (x.den === y.den) {
      return Curry._2(Z.Bigint.compare, x.num, y.num);
    } else {
      return Curry._2(Z.Bigint.compare, Curry._2(Z.Bigint.mul, x.num, y.den), Curry._2(Z.Bigint.mul, y.num, x.den));
    }
  } else {
    return 1;
  }
}

function min$3(a, b) {
  if (compare$3(a, b) <= 0) {
    return a;
  } else {
    return b;
  }
}

function max$3(a, b) {
  if (compare$3(a, b) >= 0) {
    return a;
  } else {
    return b;
  }
}

function leq$3(a, b) {
  return compare$3(a, b) <= 0;
}

function geq$3(a, b) {
  return compare$3(a, b) >= 0;
}

function lt$3(a, b) {
  return compare$3(a, b) < 0;
}

function gt$3(a, b) {
  return compare$3(a, b) > 0;
}

function to_string$3(n) {
  var match = classify$3(n);
  switch (match) {
    case /* ZERO */0 :
        return "0";
    case /* INF */1 :
        return "+inf";
    case /* MINF */2 :
        return "-inf";
    case /* UNDEF */3 :
        return "undef";
    case /* NZERO */4 :
        if (Curry._2(Z.Bigint.equal, n.den, Z.Bigint.one)) {
          return Curry._1(Z.Bigint.to_string, n.num);
        } else {
          return Curry._1(Z.Bigint.to_string, n.num) + ("/" + Curry._1(Z.Bigint.to_string, n.den));
        }
    
  }
}

function eval_to_int$3(x) {
  return Curry._2(Z.Bigint.div, x.num, x.den);
}

function to_int$3(x) {
  return Curry._1(Z.Bigint.to_int, eval_to_int$3(x));
}

function to_int32$3(x) {
  return Curry._1(Z.Bigint.to_int32, eval_to_int$3(x));
}

function to_int64$3(x) {
  return Curry._1(Z.Bigint.to_int64, eval_to_int$3(x));
}

function to_bigint$3(x) {
  return Curry._1(Z.Bigint.to_bigint, eval_to_int$3(x));
}

function to_float$3(x) {
  var match = classify$3(x);
  switch (match) {
    case /* ZERO */0 :
        return 0.0;
    case /* INF */1 :
        return Pervasives.infinity;
    case /* MINF */2 :
        return Pervasives.neg_infinity;
    case /* UNDEF */3 :
        return Number.NaN;
    case /* NZERO */4 :
        var p = x.num;
        var q = x.den;
        var np = Curry._1(Z.Bigint.numbits, p);
        var nq = Curry._1(Z.Bigint.numbits, q);
        if (np <= 53 && nq <= 53) {
          return Caml_int64.to_float(Curry._1(Z.Bigint.to_int64, p)) / Caml_int64.to_float(Curry._1(Z.Bigint.to_int64, q));
        }
        var n = 55 - (np - nq | 0) | 0;
        var match$1 = n >= 0 ? [
            Curry._2(Z.Bigint.shift_left, p, n),
            q
          ] : [
            p,
            Curry._2(Z.Bigint.shift_left, q, -n | 0)
          ];
        var match$2 = Curry._2(Z.Bigint.ediv_rem, match$1[0], match$1[1]);
        var f = Curry._2(Z.Bigint.round_to_float, match$2[0], Curry._1(Z.Bigint.sign, match$2[1]) === 0);
        return Caml_float.ldexp_float(f, -n | 0);
    
  }
}

function neg$3(x) {
  return {
          num: Curry._1(Z.Bigint.neg, x.num),
          den: x.den
        };
}

function abs$3(x) {
  return {
          num: Curry._1(Z.Bigint.abs, x.num),
          den: x.den
        };
}

function aors$3(zaors, x, y) {
  if (x.den === y.den) {
    return make_real$3(Curry._2(zaors, x.num, y.num), x.den);
  } else {
    return make_real$3(Curry._2(zaors, Curry._2(Z.Bigint.mul, x.num, y.den), Curry._2(Z.Bigint.mul, y.num, x.den)), Curry._2(Z.Bigint.mul, x.den, y.den));
  }
}

function add$3(x, y) {
  if (!(x.den === Z.Bigint.zero || y.den === Z.Bigint.zero)) {
    return aors$3(Z.Bigint.add, x, y);
  }
  var match = classify$3(x);
  var match$1 = classify$3(y);
  var exit = 0;
  var exit$1 = 0;
  switch (match) {
    case /* ZERO */0 :
        return y;
    case /* INF */1 :
        switch (match$1) {
          case /* MINF */2 :
              return undef$3;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* INF */1 :
          case /* NZERO */4 :
              exit = 1;
              break;
          
        }
        break;
    case /* MINF */2 :
        switch (match$1) {
          case /* INF */1 :
              return undef$3;
          case /* MINF */2 :
              exit = 2;
              break;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return minus_inf$3;
          
        }
        break;
    case /* UNDEF */3 :
        exit$1 = 3;
        break;
    case /* NZERO */4 :
        switch (match$1) {
          case /* INF */1 :
          case /* MINF */2 :
              exit = 2;
              break;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return Pervasives.failwith("impossible case");
          
        }
        break;
    
  }
  if (exit$1 === 3) {
    if (match$1 === 3) {
      return undef$3;
    }
    if (match$1 === 0) {
      return x;
    }
    exit = 1;
  }
  switch (exit) {
    case 1 :
        if (match >= 3) {
          return undef$3;
        } else {
          return inf$3;
        }
    case 2 :
        if (match$1 >= 2) {
          return minus_inf$3;
        } else {
          return inf$3;
        }
    
  }
}

function sub$3(x, y) {
  if (!(x.den === Z.Bigint.zero || y.den === Z.Bigint.zero)) {
    return aors$3(Z.Bigint.sub, x, y);
  }
  var match = classify$3(x);
  var match$1 = classify$3(y);
  var exit = 0;
  var exit$1 = 0;
  switch (match) {
    case /* ZERO */0 :
        return neg$3(y);
    case /* INF */1 :
        switch (match$1) {
          case /* INF */1 :
              return undef$3;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* MINF */2 :
          case /* NZERO */4 :
              exit = 1;
              break;
          
        }
        break;
    case /* MINF */2 :
        switch (match$1) {
          case /* INF */1 :
              exit = 2;
              break;
          case /* MINF */2 :
              return undef$3;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return minus_inf$3;
          
        }
        break;
    case /* UNDEF */3 :
        exit$1 = 3;
        break;
    case /* NZERO */4 :
        switch (match$1) {
          case /* INF */1 :
          case /* MINF */2 :
              exit = 2;
              break;
          case /* ZERO */0 :
          case /* UNDEF */3 :
              exit$1 = 3;
              break;
          case /* NZERO */4 :
              return Pervasives.failwith("impossible case");
          
        }
        break;
    
  }
  if (exit$1 === 3) {
    if (match$1 === 3) {
      return undef$3;
    }
    if (match$1 === 0) {
      return x;
    }
    exit = 1;
  }
  switch (exit) {
    case 1 :
        if (match >= 3) {
          return undef$3;
        } else {
          return inf$3;
        }
    case 2 :
        if (match$1 >= 2) {
          return inf$3;
        } else {
          return minus_inf$3;
        }
    
  }
}

function mul$3(x, y) {
  if (x.den === Z.Bigint.zero || y.den === Z.Bigint.zero) {
    return {
            num: Curry._1(Z.Bigint.of_int, Math.imul(Curry._1(Z.Bigint.sign, x.num), Curry._1(Z.Bigint.sign, y.num))),
            den: Z.Bigint.zero
          };
  } else {
    return make_real$3(Curry._2(Z.Bigint.mul, x.num, y.num), Curry._2(Z.Bigint.mul, x.den, y.den));
  }
}

function inv$3(x) {
  var match = Curry._1(Z.Bigint.sign, x.num);
  switch (match) {
    case -1 :
        return {
                num: Curry._1(Z.Bigint.neg, x.den),
                den: Curry._1(Z.Bigint.neg, x.num)
              };
    case 0 :
        break;
    case 1 :
        return {
                num: x.den,
                den: x.num
              };
    default:
      
  }
  if (x.den === Z.Bigint.zero) {
    return undef$3;
  } else {
    return inf$3;
  }
}

function div$3(x, y) {
  if (Curry._1(Z.Bigint.sign, y.num) >= 0) {
    return mul$3(x, {
                num: y.den,
                den: y.num
              });
  } else {
    return mul$3(x, {
                num: Curry._1(Z.Bigint.neg, y.den),
                den: Curry._1(Z.Bigint.neg, y.num)
              });
  }
}

function mul_2exp$3(x, n) {
  if (x.den === Z.Bigint.zero) {
    return x;
  } else {
    return make_real$3(Curry._2(Z.Bigint.shift_left, x.num, n), x.den);
  }
}

function div_2exp$3(x, n) {
  if (x.den === Z.Bigint.zero) {
    return x;
  } else {
    return make_real$3(x.num, Curry._2(Z.Bigint.shift_left, x.den, n));
  }
}

function $tilde$plus$3(x) {
  return x;
}

function $less$great$3(a, b) {
  return !equal$3(a, b);
}

function Q(funarg) {
  var make_real = function (n, d) {
    if (n === funarg.zero || d === funarg.one) {
      return {
              num: n,
              den: funarg.one
            };
    }
    var g = Curry._2(funarg.gcd, n, d);
    if (g === funarg.one) {
      return {
              num: n,
              den: d
            };
    } else {
      return {
              num: Curry._2(funarg.divexact, n, g),
              den: Curry._2(funarg.divexact, d, g)
            };
    }
  };
  var make = function (n, d) {
    var sd = Curry._1(funarg.sign, d);
    if (sd === 0) {
      return {
              num: Curry._1(funarg.of_int, Curry._1(funarg.sign, n)),
              den: funarg.zero
            };
    } else if (sd > 0) {
      return make_real(n, d);
    } else {
      return make_real(Curry._1(funarg.neg, n), Curry._1(funarg.neg, d));
    }
  };
  var eval_of_int = function (n) {
    return {
            num: n,
            den: funarg.one
          };
  };
  var of_int = function (n) {
    var n$1 = Curry._1(funarg.of_int, n);
    return {
            num: n$1,
            den: funarg.one
          };
  };
  var of_int32 = function (n) {
    var n$1 = Curry._1(funarg.of_int32, n);
    return {
            num: n$1,
            den: funarg.one
          };
  };
  var of_int64 = function (n) {
    var n$1 = Curry._1(funarg.of_int64, n);
    return {
            num: n$1,
            den: funarg.one
          };
  };
  var of_bigint = function (n) {
    var n$1 = Curry._1(funarg.of_bigint, n);
    return {
            num: n$1,
            den: funarg.one
          };
  };
  var of_ints = function (n, d) {
    return make(Curry._1(funarg.of_int, n), Curry._1(funarg.of_int, d));
  };
  var zero_num = funarg.zero;
  var zero_den = funarg.one;
  var zero = {
    num: zero_num,
    den: zero_den
  };
  var one_num = funarg.one;
  var one_den = funarg.one;
  var one = {
    num: one_num,
    den: one_den
  };
  var minus_one_num = funarg.minus_one;
  var minus_one_den = funarg.one;
  var minus_one = {
    num: minus_one_num,
    den: minus_one_den
  };
  var inf_num = funarg.one;
  var inf_den = funarg.zero;
  var inf = {
    num: inf_num,
    den: inf_den
  };
  var minus_inf_num = funarg.minus_one;
  var minus_inf_den = funarg.zero;
  var minus_inf = {
    num: minus_inf_num,
    den: minus_inf_den
  };
  var undef_num = funarg.zero;
  var undef_den = funarg.zero;
  var undef = {
    num: undef_num,
    den: undef_den
  };
  var of_float = function (d) {
    if (d === Pervasives.infinity) {
      return inf;
    }
    if (d === Pervasives.neg_infinity) {
      return minus_inf;
    }
    if (Pervasives.classify_float(d) === /* FP_nan */4) {
      return undef;
    }
    var match = Caml_float.frexp_float(d);
    var m = Curry._1(funarg.of_float, Caml_float.ldexp_float(match[0], 53));
    var e = match[1] - 53 | 0;
    if (e < 0) {
      return make_real(m, Curry._2(funarg.shift_left, funarg.one, -e | 0));
    }
    var n = Curry._2(funarg.shift_left, m, e);
    return {
            num: n,
            den: funarg.one
          };
  };
  var of_string = function (s) {
    try {
      var i = $$String.index(s, /* '/' */47);
      return make(Curry._3(funarg.of_substring, s, 0, i), Curry._3(funarg.of_substring, s, i + 1 | 0, (s.length - i | 0) - 1 | 0));
    }
    catch (raw_exn){
      var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
      if (exn.RE_EXN_ID === "Not_found") {
        if (s === "inf" || s === "+inf") {
          return inf;
        }
        if (s === "-inf") {
          return minus_inf;
        }
        if (s === "undef") {
          return undef;
        }
        var n = Curry._1(funarg.of_string, s);
        return {
                num: n,
                den: funarg.one
              };
      }
      throw exn;
    }
  };
  var classify = function (n) {
    if (n.den !== funarg.zero) {
      if (n.num === funarg.zero) {
        return /* ZERO */0;
      } else {
        return /* NZERO */4;
      }
    }
    var match = Curry._1(funarg.sign, n.num);
    switch (match) {
      case -1 :
          return /* MINF */2;
      case 0 :
          return /* UNDEF */3;
      case 1 :
          return /* INF */1;
      default:
        return /* UNDEF */3;
    }
  };
  var is_real = function (n) {
    return n.den !== funarg.zero;
  };
  var num = function (x) {
    return x.num;
  };
  var den = function (x) {
    return x.den;
  };
  var sign = function (x) {
    return Curry._1(funarg.sign, x.num);
  };
  var equal = function (x, y) {
    if (Curry._2(funarg.equal, x.num, y.num)) {
      return Curry._2(funarg.equal, x.den, y.den);
    } else {
      return false;
    }
  };
  var compare = function (x, y) {
    var match = classify(x);
    var match$1 = classify(y);
    var exit = 0;
    var exit$1 = 0;
    switch (match) {
      case /* INF */1 :
          switch (match$1) {
            case /* INF */1 :
                return 0;
            case /* MINF */2 :
                exit = 2;
                break;
            case /* UNDEF */3 :
                exit$1 = 3;
                break;
            default:
              exit = 2;
          }
          break;
      case /* MINF */2 :
          if (match$1 !== 1) {
            if (match$1 !== 0) {
              switch (match$1) {
                case /* MINF */2 :
                    return 0;
                case /* UNDEF */3 :
                    exit$1 = 3;
                    break;
                case /* NZERO */4 :
                    exit = 2;
                    break;
                
              }
            } else {
              exit = 2;
            }
          } else {
            exit$1 = 3;
          }
          break;
      case /* UNDEF */3 :
          if (match$1 !== 3) {
            return -1;
          } else {
            return 0;
          }
      case /* ZERO */0 :
      case /* NZERO */4 :
          exit$1 = 3;
          break;
      
    }
    if (exit$1 === 3) {
      switch (match$1) {
        case /* INF */1 :
            return -1;
        case /* MINF */2 :
            exit = 2;
            break;
        case /* UNDEF */3 :
            return 1;
        default:
          exit = 2;
      }
    }
    if (exit === 2 && match < 4) {
      switch (match) {
        case /* ZERO */0 :
            break;
        case /* INF */1 :
            return 1;
        case /* MINF */2 :
            return -1;
        
      }
    }
    if (match$1 !== 2) {
      if (x.den === y.den) {
        return Curry._2(funarg.compare, x.num, y.num);
      } else {
        return Curry._2(funarg.compare, Curry._2(funarg.mul, x.num, y.den), Curry._2(funarg.mul, y.num, x.den));
      }
    } else {
      return 1;
    }
  };
  var min = function (a, b) {
    if (compare(a, b) <= 0) {
      return a;
    } else {
      return b;
    }
  };
  var max = function (a, b) {
    if (compare(a, b) >= 0) {
      return a;
    } else {
      return b;
    }
  };
  var leq = function (a, b) {
    return compare(a, b) <= 0;
  };
  var geq = function (a, b) {
    return compare(a, b) >= 0;
  };
  var lt = function (a, b) {
    return compare(a, b) < 0;
  };
  var gt = function (a, b) {
    return compare(a, b) > 0;
  };
  var to_string = function (n) {
    var match = classify(n);
    switch (match) {
      case /* ZERO */0 :
          return "0";
      case /* INF */1 :
          return "+inf";
      case /* MINF */2 :
          return "-inf";
      case /* UNDEF */3 :
          return "undef";
      case /* NZERO */4 :
          if (Curry._2(funarg.equal, n.den, funarg.one)) {
            return Curry._1(funarg.to_string, n.num);
          } else {
            return Curry._1(funarg.to_string, n.num) + ("/" + Curry._1(funarg.to_string, n.den));
          }
      
    }
  };
  var eval_to_int = function (x) {
    return Curry._2(funarg.div, x.num, x.den);
  };
  var to_int = function (x) {
    return Curry._1(funarg.to_int, eval_to_int(x));
  };
  var to_int32 = function (x) {
    return Curry._1(funarg.to_int32, eval_to_int(x));
  };
  var to_int64 = function (x) {
    return Curry._1(funarg.to_int64, eval_to_int(x));
  };
  var to_bigint = function (x) {
    return Curry._1(funarg.to_bigint, eval_to_int(x));
  };
  var to_float = function (x) {
    var match = classify(x);
    switch (match) {
      case /* ZERO */0 :
          return 0.0;
      case /* INF */1 :
          return Pervasives.infinity;
      case /* MINF */2 :
          return Pervasives.neg_infinity;
      case /* UNDEF */3 :
          return Number.NaN;
      case /* NZERO */4 :
          var p = x.num;
          var q = x.den;
          var np = Curry._1(funarg.numbits, p);
          var nq = Curry._1(funarg.numbits, q);
          if (np <= 53 && nq <= 53) {
            return Caml_int64.to_float(Curry._1(funarg.to_int64, p)) / Caml_int64.to_float(Curry._1(funarg.to_int64, q));
          }
          var n = 55 - (np - nq | 0) | 0;
          var match$1 = n >= 0 ? [
              Curry._2(funarg.shift_left, p, n),
              q
            ] : [
              p,
              Curry._2(funarg.shift_left, q, -n | 0)
            ];
          var match$2 = Curry._2(funarg.ediv_rem, match$1[0], match$1[1]);
          var f = Curry._2(funarg.round_to_float, match$2[0], Curry._1(funarg.sign, match$2[1]) === 0);
          return Caml_float.ldexp_float(f, -n | 0);
      
    }
  };
  var neg = function (x) {
    return {
            num: Curry._1(funarg.neg, x.num),
            den: x.den
          };
  };
  var abs = function (x) {
    return {
            num: Curry._1(funarg.abs, x.num),
            den: x.den
          };
  };
  var aors = function (zaors, x, y) {
    if (x.den === y.den) {
      return make_real(Curry._2(zaors, x.num, y.num), x.den);
    } else {
      return make_real(Curry._2(zaors, Curry._2(funarg.mul, x.num, y.den), Curry._2(funarg.mul, y.num, x.den)), Curry._2(funarg.mul, x.den, y.den));
    }
  };
  var add = function (x, y) {
    if (!(x.den === funarg.zero || y.den === funarg.zero)) {
      return aors(funarg.add, x, y);
    }
    var match = classify(x);
    var match$1 = classify(y);
    var exit = 0;
    var exit$1 = 0;
    switch (match) {
      case /* ZERO */0 :
          return y;
      case /* INF */1 :
          switch (match$1) {
            case /* MINF */2 :
                return undef;
            case /* ZERO */0 :
            case /* UNDEF */3 :
                exit$1 = 3;
                break;
            case /* INF */1 :
            case /* NZERO */4 :
                exit = 1;
                break;
            
          }
          break;
      case /* MINF */2 :
          switch (match$1) {
            case /* INF */1 :
                return undef;
            case /* MINF */2 :
                exit = 2;
                break;
            case /* ZERO */0 :
            case /* UNDEF */3 :
                exit$1 = 3;
                break;
            case /* NZERO */4 :
                return minus_inf;
            
          }
          break;
      case /* UNDEF */3 :
          exit$1 = 3;
          break;
      case /* NZERO */4 :
          switch (match$1) {
            case /* INF */1 :
            case /* MINF */2 :
                exit = 2;
                break;
            case /* ZERO */0 :
            case /* UNDEF */3 :
                exit$1 = 3;
                break;
            case /* NZERO */4 :
                return Pervasives.failwith("impossible case");
            
          }
          break;
      
    }
    if (exit$1 === 3) {
      if (match$1 === 3) {
        return undef;
      }
      if (match$1 === 0) {
        return x;
      }
      exit = 1;
    }
    switch (exit) {
      case 1 :
          if (match >= 3) {
            return undef;
          } else {
            return inf;
          }
      case 2 :
          if (match$1 >= 2) {
            return minus_inf;
          } else {
            return inf;
          }
      
    }
  };
  var sub = function (x, y) {
    if (!(x.den === funarg.zero || y.den === funarg.zero)) {
      return aors(funarg.sub, x, y);
    }
    var match = classify(x);
    var match$1 = classify(y);
    var exit = 0;
    var exit$1 = 0;
    switch (match) {
      case /* ZERO */0 :
          return neg(y);
      case /* INF */1 :
          switch (match$1) {
            case /* INF */1 :
                return undef;
            case /* ZERO */0 :
            case /* UNDEF */3 :
                exit$1 = 3;
                break;
            case /* MINF */2 :
            case /* NZERO */4 :
                exit = 1;
                break;
            
          }
          break;
      case /* MINF */2 :
          switch (match$1) {
            case /* INF */1 :
                exit = 2;
                break;
            case /* MINF */2 :
                return undef;
            case /* ZERO */0 :
            case /* UNDEF */3 :
                exit$1 = 3;
                break;
            case /* NZERO */4 :
                return minus_inf;
            
          }
          break;
      case /* UNDEF */3 :
          exit$1 = 3;
          break;
      case /* NZERO */4 :
          switch (match$1) {
            case /* INF */1 :
            case /* MINF */2 :
                exit = 2;
                break;
            case /* ZERO */0 :
            case /* UNDEF */3 :
                exit$1 = 3;
                break;
            case /* NZERO */4 :
                return Pervasives.failwith("impossible case");
            
          }
          break;
      
    }
    if (exit$1 === 3) {
      if (match$1 === 3) {
        return undef;
      }
      if (match$1 === 0) {
        return x;
      }
      exit = 1;
    }
    switch (exit) {
      case 1 :
          if (match >= 3) {
            return undef;
          } else {
            return inf;
          }
      case 2 :
          if (match$1 >= 2) {
            return inf;
          } else {
            return minus_inf;
          }
      
    }
  };
  var mul = function (x, y) {
    if (x.den === funarg.zero || y.den === funarg.zero) {
      return {
              num: Curry._1(funarg.of_int, Math.imul(Curry._1(funarg.sign, x.num), Curry._1(funarg.sign, y.num))),
              den: funarg.zero
            };
    } else {
      return make_real(Curry._2(funarg.mul, x.num, y.num), Curry._2(funarg.mul, x.den, y.den));
    }
  };
  var inv = function (x) {
    var match = Curry._1(funarg.sign, x.num);
    switch (match) {
      case -1 :
          return {
                  num: Curry._1(funarg.neg, x.den),
                  den: Curry._1(funarg.neg, x.num)
                };
      case 0 :
          break;
      case 1 :
          return {
                  num: x.den,
                  den: x.num
                };
      default:
        
    }
    if (x.den === funarg.zero) {
      return undef;
    } else {
      return inf;
    }
  };
  var div = function (x, y) {
    if (Curry._1(funarg.sign, y.num) >= 0) {
      return mul(x, {
                  num: y.den,
                  den: y.num
                });
    } else {
      return mul(x, {
                  num: Curry._1(funarg.neg, y.den),
                  den: Curry._1(funarg.neg, y.num)
                });
    }
  };
  var mul_2exp = function (x, n) {
    if (x.den === funarg.zero) {
      return x;
    } else {
      return make_real(Curry._2(funarg.shift_left, x.num, n), x.den);
    }
  };
  var div_2exp = function (x, n) {
    if (x.den === funarg.zero) {
      return x;
    } else {
      return make_real(x.num, Curry._2(funarg.shift_left, x.den, n));
    }
  };
  var $tilde$plus = function (x) {
    return x;
  };
  var $less$great = function (a, b) {
    return !equal(a, b);
  };
  return {
          make: make,
          zero: zero,
          one: one,
          minus_one: minus_one,
          inf: inf,
          minus_inf: minus_inf,
          undef: undef,
          of_bigint: of_bigint,
          of_int: of_int,
          of_int32: of_int32,
          of_int64: of_int64,
          of_ints: of_ints,
          of_float: of_float,
          of_string: of_string,
          num: num,
          den: den,
          classify: classify,
          is_real: is_real,
          sign: sign,
          compare: compare,
          equal: equal,
          min: min,
          max: max,
          leq: leq,
          geq: geq,
          lt: lt,
          gt: gt,
          to_bigint: to_bigint,
          to_int: to_int,
          to_int32: to_int32,
          to_int64: to_int64,
          to_string: to_string,
          to_float: to_float,
          neg: neg,
          abs: abs,
          add: add,
          sub: sub,
          mul: mul,
          inv: inv,
          div: div,
          mul_2exp: mul_2exp,
          div_2exp: div_2exp,
          $tilde$neg: neg,
          $tilde$plus: $tilde$plus,
          $plus: add,
          $neg: sub,
          $star: mul,
          $slash: div,
          lsl: mul_2exp,
          asr: div_2exp,
          $tilde$: of_int,
          $slash$slash: of_ints,
          $tilde$$: eval_of_int,
          $slash$slash$slash: make,
          $eq: equal,
          $less: lt,
          $great: gt,
          $less$eq: leq,
          $great$eq: geq,
          $less$great: $less$great
        };
}

var QInt = {
  M: {
    mk: mk,
    make_real: make_real,
    make: make,
    of_bigint: of_bigint,
    of_int: of_int,
    of_int32: of_int32,
    of_int64: of_int64,
    of_ints: of_ints,
    zero: zero,
    one: one,
    minus_one: minus_one,
    inf: inf,
    minus_inf: minus_inf,
    undef: undef,
    of_float: of_float,
    of_string: of_string,
    classify: classify,
    is_real: is_real,
    num: num,
    den: den,
    sign: sign,
    equal: equal,
    compare: compare,
    min: min,
    max: max,
    leq: leq,
    geq: geq,
    lt: lt,
    gt: gt,
    to_string: to_string,
    to_bigint: to_bigint,
    to_int: to_int,
    to_int32: to_int32,
    to_int64: to_int64,
    to_float: to_float,
    neg: neg,
    abs: abs,
    aors: aors,
    add: add,
    sub: sub,
    mul: mul,
    inv: inv,
    div: div,
    mul_2exp: mul_2exp,
    div_2exp: div_2exp,
    $tilde$neg: neg,
    $tilde$plus: $tilde$plus,
    $plus: add,
    $neg: sub,
    $star: mul,
    $slash: div,
    lsl: mul_2exp,
    asr: div_2exp,
    $tilde$: of_int,
    $slash$slash: of_ints,
    $tilde$$: eval_of_int,
    $slash$slash$slash: make,
    $eq: equal,
    $less: lt,
    $great: gt,
    $less$eq: leq,
    $great$eq: geq,
    $less$great: $less$great
  }
};

var QInt32 = {
  M: {
    mk: mk$1,
    make_real: make_real$1,
    make: make$1,
    of_bigint: of_bigint$1,
    of_int: of_int$1,
    of_int32: of_int32$1,
    of_int64: of_int64$1,
    of_ints: of_ints$1,
    zero: zero$1,
    one: one$1,
    minus_one: minus_one$1,
    inf: inf$1,
    minus_inf: minus_inf$1,
    undef: undef$1,
    of_float: of_float$1,
    of_string: of_string$1,
    classify: classify$1,
    is_real: is_real$1,
    num: num$1,
    den: den$1,
    sign: sign$1,
    equal: equal$1,
    compare: compare$1,
    min: min$1,
    max: max$1,
    leq: leq$1,
    geq: geq$1,
    lt: lt$1,
    gt: gt$1,
    to_string: to_string$1,
    to_bigint: to_bigint$1,
    to_int: to_int$1,
    to_int32: to_int32$1,
    to_int64: to_int64$1,
    to_float: to_float$1,
    neg: neg$1,
    abs: abs$1,
    aors: aors$1,
    add: add$1,
    sub: sub$1,
    mul: mul$1,
    inv: inv$1,
    div: div$1,
    mul_2exp: mul_2exp$1,
    div_2exp: div_2exp$1,
    $tilde$neg: neg$1,
    $tilde$plus: $tilde$plus$1,
    $plus: add$1,
    $neg: sub$1,
    $star: mul$1,
    $slash: div$1,
    lsl: mul_2exp$1,
    asr: div_2exp$1,
    $tilde$: of_int$1,
    $slash$slash: of_ints$1,
    $tilde$$: eval_of_int$1,
    $slash$slash$slash: make$1,
    $eq: equal$1,
    $less: lt$1,
    $great: gt$1,
    $less$eq: leq$1,
    $great$eq: geq$1,
    $less$great: $less$great$1
  }
};

var QInt64 = {
  M: {
    mk: mk$2,
    make_real: make_real$2,
    make: make$2,
    of_bigint: of_bigint$2,
    of_int: of_int$2,
    of_int32: of_int32$2,
    of_int64: of_int64$2,
    of_ints: of_ints$2,
    zero: zero$2,
    one: one$2,
    minus_one: minus_one$2,
    inf: inf$2,
    minus_inf: minus_inf$2,
    undef: undef$2,
    of_float: of_float$2,
    of_string: of_string$2,
    classify: classify$2,
    is_real: is_real$2,
    num: num$2,
    den: den$2,
    sign: sign$2,
    equal: equal$2,
    compare: compare$2,
    min: min$2,
    max: max$2,
    leq: leq$2,
    geq: geq$2,
    lt: lt$2,
    gt: gt$2,
    to_string: to_string$2,
    to_bigint: to_bigint$2,
    to_int: to_int$2,
    to_int32: to_int32$2,
    to_int64: to_int64$2,
    to_float: to_float$2,
    neg: neg$2,
    abs: abs$2,
    aors: aors$2,
    add: add$2,
    sub: sub$2,
    mul: mul$2,
    inv: inv$2,
    div: div$2,
    mul_2exp: mul_2exp$2,
    div_2exp: div_2exp$2,
    $tilde$neg: neg$2,
    $tilde$plus: $tilde$plus$2,
    $plus: add$2,
    $neg: sub$2,
    $star: mul$2,
    $slash: div$2,
    lsl: mul_2exp$2,
    asr: div_2exp$2,
    $tilde$: of_int$2,
    $slash$slash: of_ints$2,
    $tilde$$: eval_of_int$2,
    $slash$slash$slash: make$2,
    $eq: equal$2,
    $less: lt$2,
    $great: gt$2,
    $less$eq: leq$2,
    $great$eq: geq$2,
    $less$great: $less$great$2
  }
};

var QBigint = {
  M: {
    mk: mk$3,
    make_real: make_real$3,
    make: make$3,
    of_bigint: of_bigint$3,
    of_int: of_int$3,
    of_int32: of_int32$3,
    of_int64: of_int64$3,
    of_ints: of_ints$3,
    zero: zero$3,
    one: one$3,
    minus_one: minus_one$3,
    inf: inf$3,
    minus_inf: minus_inf$3,
    undef: undef$3,
    of_float: of_float$3,
    of_string: of_string$3,
    classify: classify$3,
    is_real: is_real$3,
    num: num$3,
    den: den$3,
    sign: sign$3,
    equal: equal$3,
    compare: compare$3,
    min: min$3,
    max: max$3,
    leq: leq$3,
    geq: geq$3,
    lt: lt$3,
    gt: gt$3,
    to_string: to_string$3,
    to_bigint: to_bigint$3,
    to_int: to_int$3,
    to_int32: to_int32$3,
    to_int64: to_int64$3,
    to_float: to_float$3,
    neg: neg$3,
    abs: abs$3,
    aors: aors$3,
    add: add$3,
    sub: sub$3,
    mul: mul$3,
    inv: inv$3,
    div: div$3,
    mul_2exp: mul_2exp$3,
    div_2exp: div_2exp$3,
    $tilde$neg: neg$3,
    $tilde$plus: $tilde$plus$3,
    $plus: add$3,
    $neg: sub$3,
    $star: mul$3,
    $slash: div$3,
    lsl: mul_2exp$3,
    asr: div_2exp$3,
    $tilde$: of_int$3,
    $slash$slash: of_ints$3,
    $tilde$$: eval_of_int$3,
    $slash$slash$slash: make$3,
    $eq: equal$3,
    $less: lt$3,
    $great: gt$3,
    $less$eq: leq$3,
    $great$eq: geq$3,
    $less$great: $less$great$3
  }
};

exports.Q = Q;
exports.QInt = QInt;
exports.QInt32 = QInt32;
exports.QInt64 = QInt64;
exports.QBigint = QBigint;
/* No side effect */
