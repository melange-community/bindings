// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Json = require("./parser/json.cjs");
var Belt_Array = require("rescript/lib/js/belt_Array.js");
var Test_runners = require("../test_runners.cjs");

function decorate(__x) {
  return Belt_Array.map(__x, (function (param) {
                return [
                        param[0],
                        /* Null */0,
                        param[1]
                      ];
              }));
}

Test_runners.runTests(Json.parse, (function (input, param) {
        return "[JSON Null] Valid with \"" + input + "\"";
      }), decorate([
          [
            "null",
            ""
          ],
          [
            "     null",
            ""
          ],
          [
            "     null           ",
            ""
          ],
          [
            "null           ",
            ""
          ]
        ]));

Test_runners.runTests(Json.parse, (function (input, param) {
        return "[JSON Null] Partially valid with \"" + input + "\"";
      }), decorate([
          [
            "nulla",
            "a"
          ],
          [
            "     null   ___",
            "___"
          ],
          [
            "     null}[]",
            "}[]"
          ],
          [
            "null           +",
            "+"
          ]
        ]));

Test_runners.runFailureTests(Json.parse, (function (input) {
        return "[JSON Null] Invalid with \"" + input + "\"";
      }), [
      ".",
      "-null",
      "     ]null}[]",
      "tnull"
    ]);

exports.decorate = decorate;
/*  Not a pure module */