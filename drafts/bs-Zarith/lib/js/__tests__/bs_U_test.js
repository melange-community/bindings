'use strict';

var U = require("../src/U.js");
var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");

Jest.describe("U.UInt8", (function (param) {
        Jest.test("zero is int 0", (function (param) {
                return Jest.Expect.toEqual(U.UInt8.ofInt(0), Jest.Expect.expect(U.UInt8.zero));
              }));
        Jest.test("0 + 1", (function (param) {
                return Jest.Expect.toEqual(U.UInt8.ofInt(1), Jest.Expect.expect(U.UInt8.add(U.UInt8.zero, U.UInt8.one)));
              }));
        Jest.test("-1 is converted to 255", (function (param) {
                return Jest.Expect.toEqual(U.UInt8.ofInt(255), Jest.Expect.expect(U.UInt8.ofString("-1")));
              }));
        Jest.test("256 is converted to zero", (function (param) {
                return Jest.Expect.toEqual(U.UInt8.zero, Jest.Expect.expect(U.UInt8.ofString("256")));
              }));
        Jest.test("255 + 10 is 9", (function (param) {
                return Jest.Expect.toEqual(U.UInt8.ofInt(9), Jest.Expect.expect(U.UInt8.add(U.UInt8.ofInt(255), U.UInt8.ofInt(10))));
              }));
      }));

Jest.describe("U.UInt16", (function (param) {
        Jest.test("zero is int 0", (function (param) {
                return Jest.Expect.toEqual(U.UInt16.ofInt(0), Jest.Expect.expect(U.UInt16.zero));
              }));
        Jest.test("0 + 1", (function (param) {
                return Jest.Expect.toEqual(U.UInt16.ofInt(1), Jest.Expect.expect(U.UInt16.add(U.UInt16.zero, U.UInt16.one)));
              }));
        Jest.test("-1 is converted to 65535", (function (param) {
                return Jest.Expect.toEqual(U.UInt16.ofInt(65535), Jest.Expect.expect(U.UInt16.ofString("-1")));
              }));
        Jest.test("65536 is converted to zero", (function (param) {
                return Jest.Expect.toEqual(U.UInt16.zero, Jest.Expect.expect(U.UInt16.ofString("65536")));
              }));
        Jest.test("65535 + 10 is 9", (function (param) {
                return Jest.Expect.toEqual(U.UInt16.ofInt(9), Jest.Expect.expect(U.UInt16.add(U.UInt16.ofInt(65535), U.UInt16.ofInt(10))));
              }));
      }));

Jest.describe("U.UInt32", (function (param) {
        Jest.test("zero is int 0", (function (param) {
                return Jest.Expect.toEqual(U.UInt32.ofInt(0), Jest.Expect.expect(U.UInt32.zero));
              }));
        Jest.test("0 + 1", (function (param) {
                return Jest.Expect.toEqual(U.UInt32.ofInt(1), Jest.Expect.expect(U.UInt32.add(U.UInt32.zero, U.UInt32.one)));
              }));
        Jest.test("-1 is converted to 4294967295", (function (param) {
                return Jest.Expect.toEqual(U.UInt32.maxInt, Jest.Expect.expect(U.UInt32.ofString("-1")));
              }));
        Jest.test("4294967296 is converted to zero", (function (param) {
                return Jest.Expect.toEqual(U.UInt32.zero, Jest.Expect.expect(U.UInt32.ofString("4294967296")));
              }));
      }));

Jest.describe("U.UInt64", (function (param) {
        Jest.test("zero is int 0", (function (param) {
                return Jest.Expect.toEqual(U.UInt64.ofInt(0), Jest.Expect.expect(U.UInt64.zero));
              }));
        Jest.test("0 + 1", (function (param) {
                return Jest.Expect.toEqual(U.UInt64.ofInt(1), Jest.Expect.expect(U.UInt64.add(U.UInt64.zero, U.UInt64.one)));
              }));
        Jest.test("-1 is converted to 18446744073709551616", (function (param) {
                return Jest.Expect.toEqual(U.UInt64.maxInt, Jest.Expect.expect(U.UInt64.ofString("-1")));
              }));
        Jest.test("-2 is converted to 18446744073709551615", (function (param) {
                return Jest.Expect.toEqual(U.UInt64.sub(U.UInt64.maxInt, U.UInt64.one), Jest.Expect.expect(U.UInt64.ofString("-2")));
              }));
        Jest.test("-18446744073709551617 is converted to 18446744073709551616", (function (param) {
                return Jest.Expect.toEqual(U.UInt64.maxInt, Jest.Expect.expect(U.UInt64.ofString("-18446744073709551617")));
              }));
        Jest.test("18446744073709551617 is converted to zero", (function (param) {
                return Jest.Expect.toEqual(U.UInt64.zero, Jest.Expect.expect(U.UInt64.ofString("18446744073709551617")));
              }));
        Jest.test("18446744073709551618 is converted to one", (function (param) {
                return Jest.Expect.toEqual(U.UInt64.one, Jest.Expect.expect(U.UInt64.ofString("18446744073709551618")));
              }));
      }));

/*  Not a pure module */
