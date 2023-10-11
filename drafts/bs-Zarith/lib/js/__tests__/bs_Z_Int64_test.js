'use strict';

var Z = require("../src/Z.js");
var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");

Jest.describe("Z.Int64", (function (param) {
        Jest.test("add", (function (param) {
                var x = Z.Int64.of_string("230000232323322323");
                var y = Z.Int64.of_int(3);
                var z = Z.Int64.sub(x, y);
                return Jest.Expect.toEqual(Z.Int64.of_string("230000232323322320"), Jest.Expect.expect(z));
              }));
      }));

/*  Not a pure module */
