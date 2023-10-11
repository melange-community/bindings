'use strict';

var Z = require("../src/Z.js");
var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");

Jest.describe("Z.Int", (function (param) {
        Jest.test("rem", (function (param) {
                return Jest.Expect.toEqual(Z.Int.of_int(1), Jest.Expect.expect(Z.Int.rem(Z.Int.of_int(7), Z.Int.of_int(3))));
              }));
        Jest.test("rem", (function (param) {
                return Jest.Expect.toEqual(Z.Int.of_int(1), Jest.Expect.expect(Z.Int.rem(Z.Int.of_int(7), Z.Int.of_int(-3))));
              }));
        Jest.test("rem", (function (param) {
                return Jest.Expect.toEqual(Z.Int.of_int(-1), Jest.Expect.expect(Z.Int.rem(Z.Int.of_int(-7), Z.Int.of_int(3))));
              }));
        Jest.test("rem", (function (param) {
                return Jest.Expect.toEqual(Z.Int.of_int(-1), Jest.Expect.expect(Z.Int.rem(Z.Int.of_int(-7), Z.Int.of_int(-3))));
              }));
        Jest.test("ediv_rem 7 3", (function (param) {
                return Jest.Expect.toEqual([
                            Z.Int.of_int(2),
                            Z.Int.of_int(1)
                          ], Jest.Expect.expect(Z.Int.ediv_rem(Z.Int.of_int(7), Z.Int.of_int(3))));
              }));
        Jest.test("ediv_rem 7 (-3)", (function (param) {
                return Jest.Expect.toEqual([
                            Z.Int.of_int(-2),
                            Z.Int.of_int(1)
                          ], Jest.Expect.expect(Z.Int.ediv_rem(Z.Int.of_int(7), Z.Int.of_int(-3))));
              }));
        Jest.test("ediv_rem (-7) 3", (function (param) {
                return Jest.Expect.toEqual([
                            Z.Int.of_int(-3),
                            Z.Int.of_int(2)
                          ], Jest.Expect.expect(Z.Int.ediv_rem(Z.Int.of_int(-7), Z.Int.of_int(3))));
              }));
        Jest.test("ediv_rem (-7) (-3)", (function (param) {
                return Jest.Expect.toEqual([
                            Z.Int.of_int(-3),
                            Z.Int.of_int(2)
                          ], Jest.Expect.expect(Z.Int.ediv_rem(Z.Int.of_int(-7), Z.Int.of_int(-3))));
              }));
        Jest.test("ediv_rem (-8) 3", (function (param) {
                return Jest.Expect.toEqual([
                            Z.Int.of_int(-3),
                            Z.Int.of_int(1)
                          ], Jest.Expect.expect(Z.Int.ediv_rem(Z.Int.of_int(-8), Z.Int.of_int(3))));
              }));
        Jest.test("ediv_rem (-8) (-3)", (function (param) {
                return Jest.Expect.toEqual([
                            Z.Int.of_int(-3),
                            Z.Int.of_int(1)
                          ], Jest.Expect.expect(Z.Int.ediv_rem(Z.Int.of_int(-8), Z.Int.of_int(-3))));
              }));
        Jest.test("ediv_rem 9 3", (function (param) {
                return Jest.Expect.toEqual([
                            Z.Int.of_int(3),
                            Z.Int.of_int(0)
                          ], Jest.Expect.expect(Z.Int.ediv_rem(Z.Int.of_int(9), Z.Int.of_int(3))));
              }));
        Jest.test("ediv_rem 9 (-3)", (function (param) {
                return Jest.Expect.toEqual([
                            Z.Int.of_int(-3),
                            Z.Int.zero
                          ], Jest.Expect.expect(Z.Int.ediv_rem(Z.Int.of_int(9), Z.Int.of_int(-3))));
              }));
        Jest.test("ediv_rem (-9) 3", (function (param) {
                return Jest.Expect.toEqual([
                            Z.Int.of_int(-3),
                            Z.Int.of_int(0)
                          ], Jest.Expect.expect(Z.Int.ediv_rem(Z.Int.of_int(-9), Z.Int.of_int(3))));
              }));
        Jest.test("ediv_rem (-9) (-3)", (function (param) {
                return Jest.Expect.toEqual([
                            Z.Int.of_int(-3),
                            Z.Int.zero
                          ], Jest.Expect.expect(Z.Int.ediv_rem(Z.Int.of_int(-9), Z.Int.of_int(-3))));
              }));
        Jest.test("is_even", (function (param) {
                return Jest.Expect.toEqual(true, Jest.Expect.expect(Z.Int.is_even(Z.Int.of_int(8))));
              }));
        Jest.test("is_even", (function (param) {
                return Jest.Expect.toEqual(false, Jest.Expect.expect(Z.Int.is_even(Z.Int.of_int(9))));
              }));
        Jest.test("is_odd", (function (param) {
                return Jest.Expect.toEqual(false, Jest.Expect.expect(Z.Int.is_odd(Z.Int.of_int(8))));
              }));
        Jest.test("is_odd", (function (param) {
                return Jest.Expect.toEqual(true, Jest.Expect.expect(Z.Int.is_odd(Z.Int.of_int(9))));
              }));
        Jest.test("gcd 2 12", (function (param) {
                return Jest.Expect.toEqual(Z.Int.of_int(2), Jest.Expect.expect(Z.Int.gcd(Z.Int.of_int(2), Z.Int.of_int(12))));
              }));
        Jest.test("gcd 12 20", (function (param) {
                return Jest.Expect.toEqual(Z.Int.of_int(4), Jest.Expect.expect(Z.Int.gcd(Z.Int.of_int(12), Z.Int.of_int(20))));
              }));
        Jest.test("gcd 36 60", (function (param) {
                return Jest.Expect.toEqual(Z.Int.of_int(12), Jest.Expect.expect(Z.Int.gcd(Z.Int.of_int(36), Z.Int.of_int(60))));
              }));
      }));

/*  Not a pure module */
