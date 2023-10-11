'use strict';

var Z = require("../src/Z.js");
var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");
var Curry = require("rescript/lib/js/curry.js");
var Q_Internal = require("../src/Q_Internal.js");

Jest.describe("Q.Bigint", (function (param) {
        Jest.test("1/2 - 1/4 is 1/2", (function (param) {
                return Jest.Expect.toEqual(Curry._2(Q_Internal.QBigint.M.make, Curry._1(Z.Bigint.of_int, 1), Curry._1(Z.Bigint.of_int, 4)), Jest.Expect.expect(Curry._2(Q_Internal.QBigint.M.sub, Curry._2(Q_Internal.QBigint.M.make, Z.Bigint.one, Curry._1(Z.Bigint.of_int, 2)), Curry._2(Q_Internal.QBigint.M.make, Curry._1(Z.Bigint.of_int, 1), Curry._1(Z.Bigint.of_int, 4)))));
              }));
        Jest.test("1/8 + (-1/8) is 0", (function (param) {
                return Jest.Expect.toEqual(Q_Internal.QBigint.M.zero, Jest.Expect.expect(Curry._2(Q_Internal.QBigint.M.add, Curry._1(Q_Internal.QBigint.M.of_string, "1/8"), Curry._1(Q_Internal.QBigint.M.of_string, "-1/8"))));
              }));
      }));

Jest.test("1/8 + 14/16 is 1", (function (param) {
        return Jest.Expect.toEqual(Q_Internal.QBigint.M.one, Jest.Expect.expect(Curry._2(Q_Internal.QBigint.M.add, Curry._1(Q_Internal.QBigint.M.of_string, "1/8"), Curry._1(Q_Internal.QBigint.M.of_string, "14/16"))));
      }));

Jest.test("3 * 1/2 is 3/2", (function (param) {
        return Jest.Expect.toEqual(Curry._1(Q_Internal.QBigint.M.of_string, "3/2"), Jest.Expect.expect(Curry._2(Q_Internal.QBigint.M.mul, Curry._1(Q_Internal.QBigint.M.of_string, "3/1"), Curry._1(Q_Internal.QBigint.M.of_string, "1/2"))));
      }));

Jest.test("2/3 / 3/4 is 8/9", (function (param) {
        return Jest.Expect.toEqual(Curry._1(Q_Internal.QBigint.M.of_string, "8/9"), Jest.Expect.expect(Curry._2(Q_Internal.QBigint.M.div, Curry._1(Q_Internal.QBigint.M.of_string, "2/3"), Curry._1(Q_Internal.QBigint.M.of_string, "3/4"))));
      }));

Jest.test("zero equal to (Bigint.of_int 0)", (function (param) {
        return Jest.Expect.toEqual(Q_Internal.QBigint.M.zero, Jest.Expect.expect(Q_Internal.QBigint.M.zero));
      }));

/*  Not a pure module */
