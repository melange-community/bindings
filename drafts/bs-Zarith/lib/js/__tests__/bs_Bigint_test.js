'use strict';

var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");
var Int32 = require("rescript/lib/js/int32.js");
var Int64 = require("rescript/lib/js/int64.js");
var Bigint = require("../src/Bigint.js");
var Caml_obj = require("rescript/lib/js/caml_obj.js");
var Pervasives = require("rescript/lib/js/pervasives.js");

Jest.describe("Bigint", (function (param) {
        Jest.test("zero equal to (Bigint.of_int 0)", (function (param) {
                return Jest.Expect.toEqual(Bigint.of_int(0), Jest.Expect.expect(Bigint.zero));
              }));
        Jest.test("one equal to (Bigint.of_int 1)", (function (param) {
                return Jest.Expect.toEqual(Bigint.of_int(1), Jest.Expect.expect(Bigint.one));
              }));
        Jest.test("minus_one equal to (Bigint.of_int (-1))", (function (param) {
                return Jest.Expect.toEqual(Bigint.of_int(-1), Jest.Expect.expect(Bigint.minus_one));
              }));
        Jest.test("zero equal to (Bigint.of_int 0)", (function (param) {
                return Jest.Expect.toEqual(Bigint.of_string("0"), Jest.Expect.expect(Bigint.zero));
              }));
        Jest.test("one equal to (Bigint.of_int 1)", (function (param) {
                return Jest.Expect.toEqual(Bigint.of_string("1"), Jest.Expect.expect(Bigint.one));
              }));
        Jest.test("minus_one equal to (Bigint.of_int (-1))", (function (param) {
                return Jest.Expect.toEqual(Bigint.of_string("-1"), Jest.Expect.expect(Bigint.minus_one));
              }));
        Jest.test("2 + 1 = 3", (function (param) {
                return Jest.Expect.toEqual(Bigint.of_int(3), Jest.Expect.expect(Bigint.add(Bigint.of_int(1), Bigint.of_int(2))));
              }));
        Jest.test("(-2) + (-1) = (-3)", (function (param) {
                return Jest.Expect.toEqual(Bigint.of_int(-3), Jest.Expect.expect(Bigint.add(Bigint.of_int(-1), Bigint.of_int(-2))));
              }));
        Jest.test("0 + 0 = 0", (function (param) {
                return Jest.Expect.toEqual(Bigint.zero, Jest.Expect.expect(Bigint.add(Bigint.zero, Bigint.zero)));
              }));
        Jest.test("-3 + 3 = 0", (function (param) {
                return Jest.Expect.toEqual(Bigint.of_int(0), Jest.Expect.expect(Bigint.add(Bigint.of_int(-3), Bigint.of_int(3))));
              }));
        Jest.test("of_string: 2 + 1 = 3", (function (param) {
                return Jest.Expect.toEqual(Bigint.of_int(3), Jest.Expect.expect(Bigint.add(Bigint.of_string("1"), Bigint.of_string("2"))));
              }));
        Jest.test("addition with numbers larger than int64 can hold", (function (param) {
                var x = Bigint.of_string("1000000000000000000000000000000");
                var y = Bigint.of_string("1000000000000000000000000000000");
                var z = Bigint.add(x, y);
                return Jest.Expect.toEqual(Bigint.of_string("2000000000000000000000000000000"), Jest.Expect.expect(z));
              }));
        Jest.test("addition with numbers larger than int64 can hold", (function (param) {
                var x = Bigint.of_string("1000000000000000000000000000000000000000");
                var y = Bigint.of_int(1);
                var z = Bigint.add(y, x);
                return Jest.Expect.toEqual(Bigint.of_string("1000000000000000000000000000000000000001"), Jest.Expect.expect(z));
              }));
        Jest.test("zero to string", (function (param) {
                return Jest.Expect.toEqual("0", Jest.Expect.expect(Bigint.to_string(Bigint.zero)));
              }));
        Jest.test("one to string", (function (param) {
                return Jest.Expect.toEqual("1", Jest.Expect.expect(Bigint.to_string(Bigint.one)));
              }));
        Jest.test("minus_one to string", (function (param) {
                return Jest.Expect.toEqual("-1", Jest.Expect.expect(Bigint.to_string(Bigint.minus_one)));
              }));
        Jest.test("big to string", (function (param) {
                return Jest.Expect.toEqual("32389176649991293809043094891992939836566132213", Jest.Expect.expect(Bigint.to_string(Bigint.of_string("32389176649991293809043094891992939836566132213"))));
              }));
      }));

Jest.test("pow", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(1), Jest.Expect.expect(Bigint.pow(Bigint.of_int(2), 0)));
      }));

Jest.test("pow", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(2), Jest.Expect.expect(Bigint.pow(Bigint.of_int(2), 1)));
      }));

Jest.test("pow", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(4), Jest.Expect.expect(Bigint.pow(Bigint.of_int(2), 2)));
      }));

Jest.test("pow", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(256), Jest.Expect.expect(Bigint.pow(Bigint.of_int(4), 4)));
      }));

Jest.test("1 * 1 = 1", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(1), Jest.Expect.expect(Bigint.mul(Bigint.one, Bigint.one)));
      }));

Jest.test("1 * 0 = 0", (function (param) {
        return Jest.Expect.toEqual(Bigint.zero, Jest.Expect.expect(Bigint.mul(Bigint.one, Bigint.zero)));
      }));

Jest.test("0 * 0 = 0", (function (param) {
        return Jest.Expect.toEqual(Bigint.zero, Jest.Expect.expect(Bigint.mul(Bigint.zero, Bigint.zero)));
      }));

Jest.test("-1 * 1 = -1", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(-1), Jest.Expect.expect(Bigint.mul(Bigint.of_int(-1), Bigint.one)));
      }));

Jest.test("20 * 2 = 40", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(40), Jest.Expect.expect(Bigint.mul(Bigint.of_int(20), Bigint.of_int(2))));
      }));

Jest.test("20 * -1 = -20", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(-20), Jest.Expect.expect(Bigint.mul(Bigint.of_int(20), Bigint.of_int(-1))));
      }));

Jest.test("div", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(2), Jest.Expect.expect(Bigint.div(Bigint.of_int(6), Bigint.of_int(3))));
      }));

Jest.test("div", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(-2), Jest.Expect.expect(Bigint.div(Bigint.of_int(-6), Bigint.of_int(3))));
      }));

Jest.test("div", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(-2), Jest.Expect.expect(Bigint.div(Bigint.of_int(6), Bigint.of_int(-3))));
      }));

Jest.test("div", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(2), Jest.Expect.expect(Bigint.div(Bigint.of_int(-6), Bigint.of_int(-3))));
      }));

Jest.test("div", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(2), Jest.Expect.expect(Bigint.div(Bigint.of_int(7), Bigint.of_int(3))));
      }));

Jest.test("2 - 1 = 1", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(1), Jest.Expect.expect(Bigint.sub(Bigint.of_int(2), Bigint.of_int(1))));
      }));

Jest.test("10 - 7 = 3", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(3), Jest.Expect.expect(Bigint.sub(Bigint.of_int(10), Bigint.of_int(7))));
      }));

Jest.test("7 - 10 = -3", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(-3), Jest.Expect.expect(Bigint.sub(Bigint.of_int(7), Bigint.of_int(10))));
      }));

Jest.test("rem", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(4), Jest.Expect.expect(Bigint.rem(Bigint.of_int(4), Bigint.of_int(25))));
      }));

Jest.test("rem", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(1), Jest.Expect.expect(Bigint.rem(Bigint.of_string("18446744073709551617"), Bigint.of_string("18446744073709551616"))));
      }));

Jest.test("rem", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(1), Jest.Expect.expect(Bigint.rem(Bigint.of_int(26), Bigint.of_int(25))));
      }));

Jest.test("rem", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(0), Jest.Expect.expect(Bigint.rem(Bigint.of_int(25), Bigint.of_int(25))));
      }));

Jest.test("rem", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(1), Jest.Expect.expect(Bigint.rem(Bigint.of_int(7), Bigint.of_int(3))));
      }));

Jest.test("rem", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(1), Jest.Expect.expect(Bigint.rem(Bigint.of_int(7), Bigint.of_int(-3))));
      }));

Jest.test("rem", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(-1), Jest.Expect.expect(Bigint.rem(Bigint.of_int(-7), Bigint.of_int(3))));
      }));

Jest.test("rem", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(-1), Jest.Expect.expect(Bigint.rem(Bigint.of_int(-7), Bigint.of_int(-3))));
      }));

Jest.test("rem proof", (function (param) {
        var a = Bigint.of_int(-7);
        var b = Bigint.of_int(-3);
        var c = Bigint.$plus(Bigint.mul(b, Bigint.div(a, b)), Bigint.rem(a, b));
        return Jest.Expect.toEqual(c, Jest.Expect.expect(a));
      }));

Jest.test("rem proof", (function (param) {
        var a = Bigint.of_int(21);
        var b = Bigint.of_int(4);
        var c = Bigint.$plus(Bigint.mul(b, Bigint.div(a, b)), Bigint.rem(a, b));
        return Jest.Expect.toEqual(c, Jest.Expect.expect(a));
      }));

Jest.test("rem proof", (function (param) {
        var a = Bigint.of_int(-21);
        var b = Bigint.of_int(4);
        var c = Bigint.$plus(Bigint.mul(b, Bigint.div(a, b)), Bigint.rem(a, b));
        return Jest.Expect.toEqual(c, Jest.Expect.expect(a));
      }));

Jest.test("div_rem 7 3", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(2),
                    Bigint.of_int(1)
                  ], Jest.Expect.expect(Bigint.div_rem(Bigint.of_int(7), Bigint.of_int(3))));
      }));

Jest.test("div_rem 7 (-3)", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(-2),
                    Bigint.of_int(1)
                  ], Jest.Expect.expect(Bigint.div_rem(Bigint.of_int(7), Bigint.of_int(-3))));
      }));

Jest.test("div_rem (-7) 3", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(-2),
                    Bigint.of_int(-1)
                  ], Jest.Expect.expect(Bigint.div_rem(Bigint.of_int(-7), Bigint.of_int(3))));
      }));

Jest.test("div_rem (-7) (-3)", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(2),
                    Bigint.of_int(-1)
                  ], Jest.Expect.expect(Bigint.div_rem(Bigint.of_int(-7), Bigint.of_int(-3))));
      }));

Jest.test("div_rem 9 3", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(3),
                    Bigint.of_int(0)
                  ], Jest.Expect.expect(Bigint.div_rem(Bigint.of_int(9), Bigint.of_int(3))));
      }));

Jest.test("div_rem 9 (-3)", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(-3),
                    Bigint.of_int(0)
                  ], Jest.Expect.expect(Bigint.div_rem(Bigint.of_int(9), Bigint.of_int(-3))));
      }));

Jest.test("div_rem (-9) 3", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(-3),
                    Bigint.of_int(0)
                  ], Jest.Expect.expect(Bigint.div_rem(Bigint.of_int(-9), Bigint.of_int(3))));
      }));

Jest.test("div_rem (-9) (-3)", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(3),
                    Bigint.of_int(0)
                  ], Jest.Expect.expect(Bigint.div_rem(Bigint.of_int(-9), Bigint.of_int(-3))));
      }));

Jest.test("div_rem (1) (2)", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.zero,
                    Bigint.of_int(1)
                  ], Jest.Expect.expect(Bigint.div_rem(Bigint.of_int(1), Bigint.of_int(2))));
      }));

Jest.test("ediv_rem 7 3", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(2),
                    Bigint.of_int(1)
                  ], Jest.Expect.expect(Bigint.ediv_rem(Bigint.of_int(7), Bigint.of_int(3))));
      }));

Jest.test("ediv_rem 7 (-3)", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(-2),
                    Bigint.of_int(1)
                  ], Jest.Expect.expect(Bigint.ediv_rem(Bigint.of_int(7), Bigint.of_int(-3))));
      }));

Jest.test("ediv_rem (-7) 3", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(-3),
                    Bigint.of_int(2)
                  ], Jest.Expect.expect(Bigint.ediv_rem(Bigint.of_int(-7), Bigint.of_int(3))));
      }));

Jest.test("ediv_rem (-7) (-3)", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(-3),
                    Bigint.of_int(2)
                  ], Jest.Expect.expect(Bigint.ediv_rem(Bigint.of_int(-7), Bigint.of_int(-3))));
      }));

Jest.test("ediv_rem (-8) 3", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(-3),
                    Bigint.of_int(1)
                  ], Jest.Expect.expect(Bigint.ediv_rem(Bigint.of_int(-8), Bigint.of_int(3))));
      }));

Jest.test("ediv_rem (-8) (-3)", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(-3),
                    Bigint.of_int(1)
                  ], Jest.Expect.expect(Bigint.ediv_rem(Bigint.of_int(-8), Bigint.of_int(-3))));
      }));

Jest.test("ediv_rem 9 3", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(3),
                    Bigint.of_int(0)
                  ], Jest.Expect.expect(Bigint.ediv_rem(Bigint.of_int(9), Bigint.of_int(3))));
      }));

Jest.test("ediv_rem 9 (-3)", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(-3),
                    Bigint.zero
                  ], Jest.Expect.expect(Bigint.ediv_rem(Bigint.of_int(9), Bigint.of_int(-3))));
      }));

Jest.test("ediv_rem (-9) 3", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(-3),
                    Bigint.of_int(0)
                  ], Jest.Expect.expect(Bigint.ediv_rem(Bigint.of_int(-9), Bigint.of_int(3))));
      }));

Jest.test("ediv_rem (-9) (-3)", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.of_int(-3),
                    Bigint.zero
                  ], Jest.Expect.expect(Bigint.ediv_rem(Bigint.of_int(-9), Bigint.of_int(-3))));
      }));

Jest.test("ediv_rem (1) (2)", (function (param) {
        return Jest.Expect.toEqual([
                    Bigint.zero,
                    Bigint.of_int(1)
                  ], Jest.Expect.expect(Bigint.ediv_rem(Bigint.of_int(1), Bigint.of_int(2))));
      }));

Jest.test("is_even", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.is_even(Bigint.of_int(8))));
      }));

Jest.test("is_even", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.is_even(Bigint.of_int(9))));
      }));

Jest.test("is_even", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.is_even(Bigint.of_string("839816238764918263491726983776763728736482736846"))));
      }));

Jest.test("is_even", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.is_even(Bigint.of_string("98382938792846298734695872639470987109877098703"))));
      }));

Jest.test("is_odd", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.is_odd(Bigint.of_string("839816238764918263491726983776763728736482736846"))));
      }));

Jest.test("is_odd", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.is_odd(Bigint.of_string("98382938792846298734695872639470987109877098703"))));
      }));

Jest.test("sign", (function (param) {
        return Jest.Expect.toEqual(1, Jest.Expect.expect(Bigint.sign(Bigint.of_string("98382938792846298734695872639470987109877098703"))));
      }));

Jest.test("sign", (function (param) {
        return Jest.Expect.toEqual(0, Jest.Expect.expect(Bigint.sign(Bigint.of_string("0"))));
      }));

Jest.test("sign", (function (param) {
        return Jest.Expect.toEqual(-1, Jest.Expect.expect(Bigint.sign(Bigint.of_string("-2839849727247283728372837287378723"))));
      }));

Jest.test("2 = 3", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$eq(Bigint.of_int(2), Bigint.of_int(3))));
      }));

Jest.test("2 = 2", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$eq(Bigint.of_int(2), Bigint.of_int(2))));
      }));

Jest.test("0 = 0", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$eq(Bigint.of_int(0), Bigint.of_int(0))));
      }));

Jest.test("0 = 0", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$eq(Bigint.of_int(0), Bigint.of_int(0))));
      }));

Jest.test("0 = 0", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$eq(Bigint.zero, Bigint.of_int(0))));
      }));

Jest.test("0 = 0", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$eq(Bigint.zero, Bigint.of_string("0"))));
      }));

Jest.test("0 = 0", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$eq(Bigint.of_int(0), Bigint.of_string("0"))));
      }));

Jest.test("-1 = -1", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$eq(Bigint.of_int(-1), Bigint.of_int(-1))));
      }));

Jest.test("-1 = 1", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$eq(Bigint.of_int(-1), Bigint.of_int(1))));
      }));

Jest.test("2 <= 3", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$less$eq(Bigint.of_int(2), Bigint.of_int(3))));
      }));

Jest.test("2 <= 3", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$less$eq(Bigint.of_int(2), Bigint.of_int(3))));
      }));

Jest.test("3 <= 3", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$less$eq(Bigint.of_int(3), Bigint.of_int(3))));
      }));

Jest.test("0 <= 0", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$less$eq(Bigint.of_int(0), Bigint.of_int(0))));
      }));

Jest.test("-1 <= 0", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$less$eq(Bigint.of_int(-1), Bigint.of_int(0))));
      }));

Jest.test("-3 <= -2", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$less$eq(Bigint.of_int(-3), Bigint.of_int(-2))));
      }));

Jest.test("1 <= 0", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$less$eq(Bigint.of_int(1), Bigint.of_int(0))));
      }));

Jest.test("2 < 3", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$less(Bigint.of_int(2), Bigint.of_int(3))));
      }));

Jest.test("3 < 3", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$less(Bigint.of_int(3), Bigint.of_int(3))));
      }));

Jest.test("-1 < 0", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$less(Bigint.of_int(-1), Bigint.of_int(0))));
      }));

Jest.test("-3 < -2", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$less(Bigint.of_int(-3), Bigint.of_int(-2))));
      }));

Jest.test("1 < 0", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$less(Bigint.of_int(1), Bigint.of_int(0))));
      }));

Jest.test("2 >= 3", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$great$eq(Bigint.of_int(2), Bigint.of_int(3))));
      }));

Jest.test("3 >= 3", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$great$eq(Bigint.of_int(3), Bigint.of_int(3))));
      }));

Jest.test("-1 >= 0", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$great$eq(Bigint.of_int(-1), Bigint.of_int(0))));
      }));

Jest.test("-3 >= -2", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$great$eq(Bigint.of_int(-3), Bigint.of_int(-2))));
      }));

Jest.test("1 >= 0", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$great$eq(Bigint.of_int(1), Bigint.of_int(0))));
      }));

Jest.test("3 >= 2", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$great$eq(Bigint.of_int(3), Bigint.of_int(2))));
      }));

Jest.test("3 >= -2", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$great$eq(Bigint.of_int(3), Bigint.of_int(-2))));
      }));

Jest.test("2 > 3", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$great(Bigint.of_int(2), Bigint.of_int(3))));
      }));

Jest.test("3 > 3", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$great(Bigint.of_int(3), Bigint.of_int(3))));
      }));

Jest.test("-1 > 0", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$great(Bigint.of_int(-1), Bigint.of_int(0))));
      }));

Jest.test("-3 > -2", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$great(Bigint.of_int(-3), Bigint.of_int(-2))));
      }));

Jest.test("1 > 0", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$great(Bigint.of_int(1), Bigint.of_int(0))));
      }));

Jest.test("2 > 3", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Bigint.$great(Bigint.of_int(2), Bigint.of_int(3))));
      }));

Jest.test("3 > 2", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$great(Bigint.of_int(3), Bigint.of_int(2))));
      }));

Jest.test("3 > -2", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Bigint.$great(Bigint.of_int(3), Bigint.of_int(-2))));
      }));

Jest.test("to_int max_int", (function (param) {
        return Jest.Expect.toEqual(Pervasives.max_int, Jest.Expect.expect(Bigint.to_int(Bigint.of_int(Pervasives.max_int))));
      }));

Jest.test("to_int min_int", (function (param) {
        return Jest.Expect.toEqual(Pervasives.min_int, Jest.Expect.expect(Bigint.to_int(Bigint.of_int(Pervasives.min_int))));
      }));

Jest.test("to_int greater than max_int should throw Overflow", (function (param) {
        return Jest.Expect.toThrowException({
                    RE_EXN_ID: Bigint.Overflow
                  }, Jest.Expect.expect(function (param) {
                        return Bigint.to_int(Bigint.of_string("21474836478"));
                      }));
      }));

Jest.test("to_int smaller than min_int should throw Overflow", (function (param) {
        return Jest.Expect.toThrowException({
                    RE_EXN_ID: Bigint.Overflow
                  }, Jest.Expect.expect(function (param) {
                        return Bigint.to_int(Bigint.of_string("-21474836478"));
                      }));
      }));

Jest.test("to_int32 max_int", (function (param) {
        return Jest.Expect.toEqual(Int32.max_int, Jest.Expect.expect(Bigint.to_int32(Bigint.of_int32(Int32.max_int))));
      }));

Jest.test("to_int32 min_int", (function (param) {
        return Jest.Expect.toEqual(Int32.min_int, Jest.Expect.expect(Bigint.to_int32(Bigint.of_int32(Int32.min_int))));
      }));

Jest.test("to_int32 greater than max_int should throw Overflow", (function (param) {
        return Jest.Expect.toThrowException({
                    RE_EXN_ID: Bigint.Overflow
                  }, Jest.Expect.expect(function (param) {
                        return Bigint.to_int32(Bigint.of_string("21474836478"));
                      }));
      }));

Jest.test("to_int32 smaller than min_int should throw Overflow", (function (param) {
        return Jest.Expect.toThrowException({
                    RE_EXN_ID: Bigint.Overflow
                  }, Jest.Expect.expect(function (param) {
                        return Bigint.to_int32(Bigint.of_string("-21474836478"));
                      }));
      }));

Jest.test("to_int64 max_int", (function (param) {
        return Jest.Expect.toEqual(Int64.max_int, Jest.Expect.expect(Bigint.to_int64(Bigint.of_int64(Int64.max_int))));
      }));

Jest.test("to_int64 min_int", (function (param) {
        return Jest.Expect.toEqual(Int64.min_int, Jest.Expect.expect(Bigint.to_int64(Bigint.of_int64(Int64.min_int))));
      }));

Jest.test("to_int64 greater than max_int should throw Overflow", (function (param) {
        return Jest.Expect.toThrowException({
                    RE_EXN_ID: Bigint.Overflow
                  }, Jest.Expect.expect(function (param) {
                        return Bigint.to_int64(Bigint.of_string("9223372036854775808"));
                      }));
      }));

Jest.test("to_float", (function (param) {
        return Jest.Expect.toEqual(9007199254740993.0, Jest.Expect.expect(Bigint.to_float(Bigint.of_string("9007199254740992"))));
      }));

Jest.test("3 <> 2", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Caml_obj.notequal(Bigint.of_int(3), Bigint.of_int(2))));
      }));

Jest.test("2 <> 2", (function (param) {
        return Jest.Expect.toEqual(false, Jest.Expect.expect(Caml_obj.notequal(Bigint.of_int(2), Bigint.of_int(2))));
      }));

Jest.test("0 <> 1", (function (param) {
        return Jest.Expect.toEqual(true, Jest.Expect.expect(Caml_obj.notequal(Bigint.of_int(0), Bigint.of_int(1))));
      }));

Jest.test("gcd 2 12", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(2), Jest.Expect.expect(Bigint.gcd(Bigint.of_int(2), Bigint.of_int(12))));
      }));

Jest.test("gcd 12 20", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(4), Jest.Expect.expect(Bigint.gcd(Bigint.of_int(12), Bigint.of_int(20))));
      }));

Jest.test("gcd 36 60", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(12), Jest.Expect.expect(Bigint.gcd(Bigint.of_int(36), Bigint.of_int(60))));
      }));

Jest.test("logand", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(130), Jest.Expect.expect(Bigint.logand(Bigint.of_int(198), Bigint.of_int(163))));
      }));

Jest.test("logand", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(3), Jest.Expect.expect(Bigint.logand(Bigint.of_int(3), Bigint.of_int(7))));
      }));

Jest.test("logand", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(1), Jest.Expect.expect(Bigint.logand(Bigint.of_int(5), Bigint.of_int(3))));
      }));

Jest.test("logand", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(2), Jest.Expect.expect(Bigint.logand(Bigint.of_int(3), Bigint.of_int(2))));
      }));

Jest.test("logand", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(2), Jest.Expect.expect(Bigint.logand(Bigint.of_int(6), Bigint.of_int(11))));
      }));

Jest.test("logor", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(7), Jest.Expect.expect(Bigint.logor(Bigint.of_int(6), Bigint.of_int(3))));
      }));

Jest.test("logor", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(1), Jest.Expect.expect(Bigint.logor(Bigint.of_int(1), Bigint.of_int(0))));
      }));

Jest.test("div", (function (param) {
        return Jest.Expect.toEqual(Bigint.zero, Jest.Expect.expect(Bigint.div(Bigint.of_int(1), Bigint.of_int(2))));
      }));

Jest.test("div", (function (param) {
        return Jest.Expect.toEqual(Bigint.one, Jest.Expect.expect(Bigint.div(Bigint.of_int(2), Bigint.of_int(2))));
      }));

Jest.test("div", (function (param) {
        return Jest.Expect.toEqual(Bigint.one, Jest.Expect.expect(Bigint.div(Bigint.of_int(3), Bigint.of_int(2))));
      }));

Jest.test("div", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(2), Jest.Expect.expect(Bigint.div(Bigint.of_int(4), Bigint.of_int(2))));
      }));

Jest.test("div", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(4), Jest.Expect.expect(Bigint.div(Bigint.of_int(9), Bigint.of_int(2))));
      }));

Jest.test("numbits", (function (param) {
        return Jest.Expect.toEqual(1, Jest.Expect.expect(Bigint.numbits(Bigint.of_int(-1))));
      }));

Jest.test("numbits", (function (param) {
        return Jest.Expect.toEqual(1, Jest.Expect.expect(Bigint.numbits(Bigint.of_int(1))));
      }));

Jest.test("numbits", (function (param) {
        return Jest.Expect.toEqual(0, Jest.Expect.expect(Bigint.numbits(Bigint.zero)));
      }));

Jest.test("numbits", (function (param) {
        return Jest.Expect.toEqual(3, Jest.Expect.expect(Bigint.numbits(Bigint.of_int(6))));
      }));

Jest.test("numbits", (function (param) {
        return Jest.Expect.toEqual(3, Jest.Expect.expect(Bigint.numbits(Bigint.of_int(5))));
      }));

Jest.test("numbits", (function (param) {
        return Jest.Expect.toEqual(4, Jest.Expect.expect(Bigint.numbits(Bigint.of_int(8))));
      }));

Jest.test("numbits", (function (param) {
        return Jest.Expect.toEqual(5, Jest.Expect.expect(Bigint.numbits(Bigint.of_int(16))));
      }));

Jest.test("numbits", (function (param) {
        return Jest.Expect.toEqual(4, Jest.Expect.expect(Bigint.numbits(Bigint.of_int(-8))));
      }));

Jest.test("cdiv", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(5), Jest.Expect.expect(Bigint.cdiv(Bigint.of_int(9), Bigint.of_int(2))));
      }));

Jest.test("cdiv", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(-4), Jest.Expect.expect(Bigint.cdiv(Bigint.of_int(-9), Bigint.of_int(2))));
      }));

Jest.test("cdiv", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(-1), Jest.Expect.expect(Bigint.cdiv(Bigint.of_int(-3), Bigint.of_int(2))));
      }));

Jest.test("cdiv", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(3), Jest.Expect.expect(Bigint.cdiv(Bigint.of_int(100), Bigint.of_int(40))));
      }));

Jest.test("fdiv", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(4), Jest.Expect.expect(Bigint.fdiv(Bigint.of_int(9), Bigint.of_int(2))));
      }));

Jest.test("fdiv", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(-5), Jest.Expect.expect(Bigint.fdiv(Bigint.of_int(-9), Bigint.of_int(2))));
      }));

Jest.test("div", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(-2), Jest.Expect.expect(Bigint.fdiv(Bigint.of_int(-3), Bigint.of_int(2))));
      }));

Jest.test("div", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(2), Jest.Expect.expect(Bigint.fdiv(Bigint.of_int(100), Bigint.of_int(40))));
      }));

Jest.test("pow", (function (param) {
        return Jest.Expect.toEqual(Bigint.of_int(4), Jest.Expect.expect(Bigint.pow(Bigint.of_int(2), 2)));
      }));

/*  Not a pure module */
