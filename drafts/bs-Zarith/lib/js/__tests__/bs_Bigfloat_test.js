'use strict';

var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");
var Bigint = require("../src/Bigint.js");
var Bigfloat = require("../src/Bigfloat.js");

Jest.describe("Bigfloat.add", (function (param) {
        Jest.test("1 + 1", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(2), 0), Jest.Expect.expect(Bigfloat.add(Bigfloat.mkBigfloat(Bigint.one, 0), Bigfloat.mkBigfloat(Bigint.one, 0))));
              }));
        Jest.test("1.0 + 1.0", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(20), 1), Jest.Expect.expect(Bigfloat.add(Bigfloat.mkBigfloat(Bigint.of_int(10), 1), Bigfloat.mkBigfloat(Bigint.of_int(10), 1))));
              }));
        Jest.test("1.00 + 1", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(200), 2), Jest.Expect.expect(Bigfloat.add(Bigfloat.mkBigfloat(Bigint.of_int(100), 2), Bigfloat.mkBigfloat(Bigint.of_int(1), 0))));
              }));
        Jest.test("0.10 + 1.00", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(110), 2), Jest.Expect.expect(Bigfloat.add(Bigfloat.mkBigfloat(Bigint.of_int(10), 2), Bigfloat.mkBigfloat(Bigint.of_int(100), 2))));
              }));
        Jest.test("1.23 + 0.0354", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(12654), 4), Jest.Expect.expect(Bigfloat.add(Bigfloat.mkBigfloat(Bigint.of_int(123), 2), Bigfloat.mkBigfloat(Bigint.of_int(354), 4))));
              }));
        Jest.test("1.000000 + 1.00000000", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(200000000), 8), Jest.Expect.expect(Bigfloat.add(Bigfloat.mkBigfloat(Bigint.of_int(1000000), 6), Bigfloat.mkBigfloat(Bigint.of_int(100000000), 8))));
              }));
        Jest.test("1.500000 + 3.54", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(5040000), 6), Jest.Expect.expect(Bigfloat.add(Bigfloat.mkBigfloat(Bigint.of_int(1500000), 6), Bigfloat.mkBigfloat(Bigint.of_int(354), 2))));
              }));
        Jest.test("1.000000 + 9.0000000000", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int64([
                                    44,
                                    1021438976
                                  ]), 10), Jest.Expect.expect(Bigfloat.add(Bigfloat.mkBigfloat(Bigint.of_int(10000000), 6), Bigfloat.mkBigfloat(Bigint.of_int64([
                                            20,
                                            4100654080
                                          ]), 10))));
              }));
      }));

Jest.describe("Bigfloat.sub", (function (param) {
        Jest.test("1 - 1", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.zero, 0), Jest.Expect.expect(Bigfloat.sub(Bigfloat.mkBigfloat(Bigint.one, 0), Bigfloat.mkBigfloat(Bigint.one, 0))));
              }));
        Jest.test("2 - 1", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.one, 0), Jest.Expect.expect(Bigfloat.sub(Bigfloat.mkBigfloat(Bigint.of_int(2), 0), Bigfloat.mkBigfloat(Bigint.one, 0))));
              }));
        Jest.test("10.0 - 5", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(50), 1), Jest.Expect.expect(Bigfloat.sub(Bigfloat.mkBigfloat(Bigint.of_int(100), 1), Bigfloat.mkBigfloat(Bigint.of_int(5), 0))));
              }));
        Jest.test("20.00 - 5.0", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(1500), 2), Jest.Expect.expect(Bigfloat.sub(Bigfloat.mkBigfloat(Bigint.of_int(2000), 2), Bigfloat.mkBigfloat(Bigint.of_int(50), 1))));
              }));
        Jest.test("20.00 - 0.5", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(1950), 2), Jest.Expect.expect(Bigfloat.sub(Bigfloat.mkBigfloat(Bigint.of_int(2000), 2), Bigfloat.mkBigfloat(Bigint.of_int(5), 1))));
              }));
      }));

Jest.describe("Bigfloat.mul", (function (param) {
        Jest.test("1 * 1", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.one, 0), Jest.Expect.expect(Bigfloat.mul(Bigfloat.mkBigfloat(Bigint.one, 0), Bigfloat.mkBigfloat(Bigint.one, 0))));
              }));
        Jest.test("2 * 1", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(2), 0), Jest.Expect.expect(Bigfloat.mul(Bigfloat.mkBigfloat(Bigint.of_int(2), 0), Bigfloat.mkBigfloat(Bigint.one, 0))));
              }));
        Jest.test("2 * 1.00", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(200), 2), Jest.Expect.expect(Bigfloat.mul(Bigfloat.mkBigfloat(Bigint.of_int(2), 0), Bigfloat.mkBigfloat(Bigint.of_int(100), 2))));
              }));
        Jest.test("5.00 * 2.00", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(50000), 4), Jest.Expect.expect(Bigfloat.mul(Bigfloat.mkBigfloat(Bigint.of_int(500), 2), Bigfloat.mkBigfloat(Bigint.of_int(100), 2))));
              }));
        Jest.test("1.200 * 2.00", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(240000), 5), Jest.Expect.expect(Bigfloat.mul(Bigfloat.mkBigfloat(Bigint.of_int(1200), 3), Bigfloat.mkBigfloat(Bigint.of_int(200), 2))));
              }));
        Jest.test("31.123 * 0.02", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(62246), 5), Jest.Expect.expect(Bigfloat.mul(Bigfloat.mkBigfloat(Bigint.of_int(31123), 3), Bigfloat.mkBigfloat(Bigint.of_int(2), 2))));
              }));
      }));

Jest.describe("Bigfloat.firstNonZero", (function (param) {
        Jest.test("0", (function (param) {
                return Jest.Expect.toEqual(undefined, Jest.Expect.expect(Bigint.firstNonZero(Bigint.zero)));
              }));
        Jest.test("1", (function (param) {
                return Jest.Expect.toEqual(0, Jest.Expect.expect(Bigint.firstNonZero(Bigint.one)));
              }));
        Jest.test("10", (function (param) {
                return Jest.Expect.toEqual(1, Jest.Expect.expect(Bigint.firstNonZero(Bigint.of_int(10))));
              }));
        Jest.test("200", (function (param) {
                return Jest.Expect.toEqual(2, Jest.Expect.expect(Bigint.firstNonZero(Bigint.of_int(200))));
              }));
        Jest.test("90210", (function (param) {
                return Jest.Expect.toEqual(1, Jest.Expect.expect(Bigint.firstNonZero(Bigint.of_int(90210))));
              }));
        Jest.test("90000", (function (param) {
                return Jest.Expect.toEqual(4, Jest.Expect.expect(Bigint.firstNonZero(Bigint.of_int(90000))));
              }));
      }));

Jest.describe("Bigfloat.adjustDecimalPos", (function (param) {
        Jest.test("0, 0", (function (param) {
                return Jest.Expect.toEqual([
                            Bigfloat.mkBigfloat(Bigint.one, 0),
                            Bigfloat.mkBigfloat(Bigint.one, 0)
                          ], Jest.Expect.expect(Bigfloat.adjustDecimalPos(Bigfloat.mkBigfloat(Bigint.one, 0), Bigfloat.mkBigfloat(Bigint.one, 0))));
              }));
        Jest.test("12.34, 5.6", (function (param) {
                return Jest.Expect.toEqual([
                            Bigfloat.mkBigfloat(Bigint.of_int(1234), 2),
                            Bigfloat.mkBigfloat(Bigint.of_int(560), 2)
                          ], Jest.Expect.expect(Bigfloat.adjustDecimalPos(Bigfloat.mkBigfloat(Bigint.of_int(1234), 2), Bigfloat.mkBigfloat(Bigint.of_int(56), 1))));
              }));
        Jest.test("59.787800, 5", (function (param) {
                return Jest.Expect.toEqual([
                            Bigfloat.mkBigfloat(Bigint.of_int64([
                                      0,
                                      59787800
                                    ]), 6),
                            Bigfloat.mkBigfloat(Bigint.of_int(5000000), 6)
                          ], Jest.Expect.expect(Bigfloat.adjustDecimalPos(Bigfloat.mkBigfloat(Bigint.of_int64([
                                            0,
                                            59787800
                                          ]), 6), Bigfloat.mkBigfloat(Bigint.of_int(5), 0))));
              }));
      }));

Jest.describe("Bigfloat.div", (function (param) {
        Jest.test("1 / 1", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.one, 0), Jest.Expect.expect(Bigfloat.div(Bigfloat.mkBigfloat(Bigint.one, 0), Bigfloat.mkBigfloat(Bigint.one, 0))));
              }));
        Jest.test("2 / 1", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(2), 0), Jest.Expect.expect(Bigfloat.div(Bigfloat.mkBigfloat(Bigint.of_int(2), 0), Bigfloat.mkBigfloat(Bigint.one, 0))));
              }));
        Jest.test("4 / 2", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(2), 0), Jest.Expect.expect(Bigfloat.div(Bigfloat.mkBigfloat(Bigint.of_int(4), 0), Bigfloat.mkBigfloat(Bigint.of_int(2), 0))));
              }));
        Jest.test("10 / 3", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(3), 0), Jest.Expect.expect(Bigfloat.div(Bigfloat.mkBigfloat(Bigint.of_int(10), 0), Bigfloat.mkBigfloat(Bigint.of_int(3), 0))));
              }));
        Jest.test("1 / 0.5", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(20), 1), Jest.Expect.expect(Bigfloat.div(Bigfloat.mkBigfloat(Bigint.of_int(1), 0), Bigfloat.mkBigfloat(Bigint.of_int(5), 1))));
              }));
        Jest.test("10.0 / 0.5", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(200), 1), Jest.Expect.expect(Bigfloat.div(Bigfloat.mkBigfloat(Bigint.of_int(100), 1), Bigfloat.mkBigfloat(Bigint.of_int(5), 1))));
              }));
        Jest.test("20.0 / 0.02", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(100000), 2), Jest.Expect.expect(Bigfloat.div(Bigfloat.mkBigfloat(Bigint.of_int(200), 1), Bigfloat.mkBigfloat(Bigint.of_int(2), 2))));
              }));
        Jest.test("100.0 / 0.03", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(333300), 2), Jest.Expect.expect(Bigfloat.div(Bigfloat.mkBigfloat(Bigint.of_int(1000), 1), Bigfloat.mkBigfloat(Bigint.of_int(3), 2))));
              }));
        Jest.test("43.001234 / 7.00000000", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(600000000), 8), Jest.Expect.expect(Bigfloat.div(Bigfloat.mkBigfloat(Bigint.of_int(43001234), 6), Bigfloat.mkBigfloat(Bigint.of_int(700000000), 8))));
              }));
        Jest.test("99.000000 / 2.0000000000", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_string("490000000000"), 10), Jest.Expect.expect(Bigfloat.div(Bigfloat.mkBigfloat(Bigint.of_int64([
                                            0,
                                            99000000
                                          ]), 6), Bigfloat.mkBigfloat(Bigint.of_string("20000000000"), 10))));
              }));
        Jest.test("99.0 / 2.0000000000", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_string("490000000000"), 10), Jest.Expect.expect(Bigfloat.div(Bigfloat.mkBigfloat(Bigint.of_int64([
                                            0,
                                            990
                                          ]), 1), Bigfloat.mkBigfloat(Bigint.of_string("20000000000"), 10))));
              }));
      }));

Jest.describe("Bigfloat.ofString", (function (param) {
        Jest.test("'0'", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.zero, 0), Jest.Expect.expect(Bigfloat.ofString("0", 0)));
              }));
        Jest.test("'1'", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(10), 1), Jest.Expect.expect(Bigfloat.ofString("1", 1)));
              }));
        Jest.test("'1.0'", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(10), 1), Jest.Expect.expect(Bigfloat.ofString("1.0", 1)));
              }));
        Jest.test("'1.01'", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(101), 2), Jest.Expect.expect(Bigfloat.ofString("1.01", 2)));
              }));
        Jest.test("'1.023'", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(1023), 3), Jest.Expect.expect(Bigfloat.ofString("1.023", 3)));
              }));
        Jest.test("'123.456789'", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(123456789), 6), Jest.Expect.expect(Bigfloat.ofString("123.456789", 6)));
              }));
        Jest.test("'0.0089'", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(89), 4), Jest.Expect.expect(Bigfloat.ofString("00.0089", 4)));
              }));
        Jest.test("'984'", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int(984000000), 6), Jest.Expect.expect(Bigfloat.ofString("984", 6)));
              }));
        Jest.test("'3,267'", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int64([
                                    0,
                                    3267000000
                                  ]), 6), Jest.Expect.expect(Bigfloat.ofString("3,267", 6)));
              }));
        Jest.test("'3,267.1'", (function (param) {
                return Jest.Expect.toEqual(Bigfloat.mkBigfloat(Bigint.of_int64([
                                    0,
                                    3267100000
                                  ]), 6), Jest.Expect.expect(Bigfloat.ofString("3,267.1", 6)));
              }));
      }));

Jest.describe("Bigfloat.toString", (function (param) {
        Jest.test("0", (function (param) {
                return Jest.Expect.toEqual("0", Jest.Expect.expect(Bigfloat.toString(Bigfloat.mkBigfloat(Bigint.zero, 0))));
              }));
        Jest.test("0.0", (function (param) {
                return Jest.Expect.toEqual("0.0", Jest.Expect.expect(Bigfloat.toString(Bigfloat.mkBigfloat(Bigint.zero, 1))));
              }));
        Jest.test("1.0205", (function (param) {
                return Jest.Expect.toEqual("1.0205", Jest.Expect.expect(Bigfloat.toString(Bigfloat.mkBigfloat(Bigint.of_int(10205), 4))));
              }));
        Jest.test("1.000000", (function (param) {
                return Jest.Expect.toEqual("1.000000", Jest.Expect.expect(Bigfloat.toString(Bigfloat.mkBigfloat(Bigint.of_int(1000000), 6))));
              }));
        Jest.test("67.004020", (function (param) {
                return Jest.Expect.toEqual("67.004020", Jest.Expect.expect(Bigfloat.toString(Bigfloat.mkBigfloat(Bigint.of_int(67004020), 6))));
              }));
      }));

Jest.describe("Bigfloat.toStringWithCommas", (function (param) {
        Jest.test("0", (function (param) {
                return Jest.Expect.toEqual("0", Jest.Expect.expect(Bigfloat.toStringWithCommas(Bigfloat.mkBigfloat(Bigint.zero, 0))));
              }));
        Jest.test("1.000000", (function (param) {
                return Jest.Expect.toEqual("1.000000", Jest.Expect.expect(Bigfloat.toStringWithCommas(Bigfloat.mkBigfloat(Bigint.of_int(1000000), 6))));
              }));
        Jest.test("67.004020", (function (param) {
                return Jest.Expect.toEqual("67.004020", Jest.Expect.expect(Bigfloat.toStringWithCommas(Bigfloat.mkBigfloat(Bigint.of_int(67004020), 6))));
              }));
        Jest.test("1,267.004020", (function (param) {
                return Jest.Expect.toEqual("1,267.004020", Jest.Expect.expect(Bigfloat.toStringWithCommas(Bigfloat.mkBigfloat(Bigint.of_int(1267004020), 6))));
              }));
        Jest.test("45,657,923.004020", (function (param) {
                return Jest.Expect.toEqual("45,657,923.004020", Jest.Expect.expect(Bigfloat.toStringWithCommas(Bigfloat.mkBigfloat(Bigint.of_string("45657923004020"), 6))));
              }));
      }));

Jest.describe("Bigfloat.compare", (function (param) {
        Jest.test("compare(0,1)", (function (param) {
                return Jest.Expect.toEqual(-1, Jest.Expect.expect(Bigfloat.compare(Bigfloat.mkBigfloat(Bigint.zero, 0), Bigfloat.mkBigfloat(Bigint.one, 0))));
              }));
        Jest.test("compare(1,0)", (function (param) {
                return Jest.Expect.toEqual(1, Jest.Expect.expect(Bigfloat.compare(Bigfloat.mkBigfloat(Bigint.one, 0), Bigfloat.mkBigfloat(Bigint.zero, 0))));
              }));
        Jest.test("compare(0,0)", (function (param) {
                return Jest.Expect.toEqual(0, Jest.Expect.expect(Bigfloat.compare(Bigfloat.mkBigfloat(Bigint.zero, 0), Bigfloat.mkBigfloat(Bigint.zero, 0))));
              }));
        Jest.test("compare(1.0,0)", (function (param) {
                return Jest.Expect.toEqual(1, Jest.Expect.expect(Bigfloat.compare(Bigfloat.mkBigfloat(Bigint.of_int(10), 1), Bigfloat.mkBigfloat(Bigint.zero, 0))));
              }));
        Jest.test("compare(1.02,2.03)", (function (param) {
                return Jest.Expect.toEqual(-1, Jest.Expect.expect(Bigfloat.compare(Bigfloat.mkBigfloat(Bigint.of_int(102), 2), Bigfloat.mkBigfloat(Bigint.of_int(203), 2))));
              }));
        Jest.test("compare(1.02,0.2)", (function (param) {
                return Jest.Expect.toEqual(1, Jest.Expect.expect(Bigfloat.compare(Bigfloat.mkBigfloat(Bigint.of_int(102), 1), Bigfloat.mkBigfloat(Bigint.of_int(2), 1))));
              }));
        Jest.test("compare(1.01,1.010)", (function (param) {
                return Jest.Expect.toEqual(0, Jest.Expect.expect(Bigfloat.compare(Bigfloat.mkBigfloat(Bigint.of_int(101), 2), Bigfloat.mkBigfloat(Bigint.of_int(1010), 3))));
              }));
        Jest.test("compare(9.234,10.000)", (function (param) {
                return Jest.Expect.toEqual(-1, Jest.Expect.expect(Bigfloat.compare(Bigfloat.mkBigfloat(Bigint.of_int(9234), 3), Bigfloat.mkBigfloat(Bigint.of_int(10000), 3))));
              }));
        Jest.test("compare(10,9.234)", (function (param) {
                return Jest.Expect.toEqual(1, Jest.Expect.expect(Bigfloat.compare(Bigfloat.mkBigfloat(Bigint.of_int(10), 0), Bigfloat.mkBigfloat(Bigint.of_int(9234), 3))));
              }));
      }));

var B;

var mk = Bigfloat.mkBigfloat;

exports.B = B;
exports.mk = mk;
/*  Not a pure module */
