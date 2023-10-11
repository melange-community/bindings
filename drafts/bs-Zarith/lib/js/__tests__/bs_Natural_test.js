'use strict';

var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");
var Natural = require("../src/Natural.js");
var Caml_int64 = require("rescript/lib/js/caml_int64.js");

Jest.describe("Natural", (function (param) {
        Jest.test("zero equal to (Natural.ofInt 0)", (function (param) {
                return Jest.Expect.toEqual(Natural.ofInt(0), Jest.Expect.expect(Natural.zero));
              }));
        Jest.test("one equal to (Natural.ofInt 1)", (function (param) {
                return Jest.Expect.toEqual(Natural.ofInt(1), Jest.Expect.expect(Natural.one));
              }));
        Jest.test("zero equal to (Natural.ofInt 0)", (function (param) {
                return Jest.Expect.toEqual(Natural.unsafeOfString("0"), Jest.Expect.expect(Natural.zero));
              }));
        Jest.test("ofInt on a negative number should throw an error", (function (param) {
                return Jest.Expect.toEqual(undefined, Jest.Expect.expect(Natural.ofInt(-1)));
              }));
        Jest.test("ofInt64 on a negative number should throw an error", (function (param) {
                return Jest.Expect.toEqual(undefined, Jest.Expect.expect(Natural.ofInt64(Caml_int64.neg_one)));
              }));
        Jest.test("ofString on a negative number should throw an error", (function (param) {
                return Jest.Expect.toEqual(undefined, Jest.Expect.expect(Natural.ofString("-100")));
              }));
        Jest.test("unsafeOfInt on a negative number should throw an error", (function (param) {
                return Jest.Expect.toThrowException({
                            RE_EXN_ID: Natural.Underflow
                          }, Jest.Expect.expect(function (param) {
                                return Natural.unsafeOfInt(-1);
                              }));
              }));
        Jest.test("one equal to (Natural.ofInt 1)", (function (param) {
                return Jest.Expect.toEqual(Natural.unsafeOfString("1"), Jest.Expect.expect(Natural.one));
              }));
        Jest.test("2 + 1 = 3", (function (param) {
                return Jest.Expect.toEqual(Natural.unsafeOfInt(3), Jest.Expect.expect(Natural.add(Natural.unsafeOfInt(1), Natural.unsafeOfInt(2))));
              }));
        Jest.test("0 + 0 = 0", (function (param) {
                return Jest.Expect.toEqual(Natural.zero, Jest.Expect.expect(Natural.add(Natural.zero, Natural.zero)));
              }));
        Jest.test("unsafeOfString: 2 + 1 = 3", (function (param) {
                return Jest.Expect.toEqual(Natural.unsafeOfInt(3), Jest.Expect.expect(Natural.add(Natural.unsafeOfString("1"), Natural.unsafeOfString("2"))));
              }));
        Jest.test("div", (function (param) {
                return Jest.Expect.toEqual(Natural.unsafeOfInt(2), Jest.Expect.expect(Natural.fdiv(Natural.unsafeOfInt(100), Natural.unsafeOfInt(40))));
              }));
      }));

/*  Not a pure module */
