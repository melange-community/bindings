'use strict';

var Z = require("../src/Z.js");
var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");
var Curry = require("rescript/lib/js/curry.js");
var Q_Internal = require("../src/Q_Internal.js");

Jest.describe("Q.Int", (function (param) {
        Jest.test("1/2 - 1/4 is 1/2", (function (param) {
                return Jest.Expect.toEqual(Curry._2(Q_Internal.QInt.M.make, Z.Int.of_int(1), Z.Int.of_int(4)), Jest.Expect.expect(Curry._2(Q_Internal.QInt.M.sub, Curry._2(Q_Internal.QInt.M.make, Z.Int.one, Z.Int.of_int(2)), Curry._2(Q_Internal.QInt.M.make, Z.Int.of_int(1), Z.Int.of_int(4)))));
              }));
      }));

/*  Not a pure module */
