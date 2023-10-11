// Generated by ReScript, PLEASE EDIT WITH CARE

import * as Zora from "@dusty-phillips/rescript-zora/src/Zora.mjs";
import * as Zora$1 from "zora";
import * as Deque from "../src/Deque.mjs";
import * as Caml_obj from "@rescript/std/lib/es6/caml_obj.js";
import * as Belt_Array from "@rescript/std/lib/es6/belt_Array.js";
import * as Caml_int32 from "@rescript/std/lib/es6/caml_int32.js";
import * as Belt_MapInt from "@rescript/std/lib/es6/belt_MapInt.js";
import * as Caml_option from "@rescript/std/lib/es6/caml_option.js";
import * as Belt_SortArrayInt from "@rescript/std/lib/es6/belt_SortArrayInt.js";

Zora$1.test("emptyness", (function (t) {
        t.test("remove", (function (t) {
                t.is(Deque.empty, Deque.popFront(Deque.empty), "");
                t.is(Deque.empty, Deque.popBack(Deque.empty), "");
                return Zora.done(undefined);
              }));
        t.test("get", (function (t) {
                t.is(undefined, Deque.peekFront(Deque.empty), "");
                t.is(undefined, Deque.peekBack(Deque.empty), "");
                t.is(Deque.empty, Deque.popFront(Deque.empty), "");
                t.is(Deque.empty, Deque.popFront(Deque.empty), "");
                return Zora.done(undefined);
              }));
        return Zora.done(undefined);
      }));

Zora$1.test("toArray", (function (t) {
        var dq = Deque.toArray(Deque.pushFront(Deque.pushFront(Deque.pushFront(Deque.pushFront(Deque.pushFront(Deque.pushFront(Deque.pushFront(Deque.pushFront(Deque.pushBack(Deque.pushBack(Deque.empty, 0), 1), 2), 3), 4), 5), 6), 7), 8), 9));
        t.is(true, Caml_obj.equal(dq, [
                  9,
                  8,
                  7,
                  6,
                  5,
                  4,
                  3,
                  2,
                  0,
                  1
                ]), "");
        return Zora.done(undefined);
      }));

Zora$1.test("adventofcode 2018-9", (function (t) {
        var ccw = function (circle) {
          var v = Deque.peekBack(circle);
          if (v !== undefined) {
            return Deque.pushFront(Deque.popBack(circle), Caml_option.valFromOption(v));
          }
          throw {
                RE_EXN_ID: "Assert_failure",
                _1: [
                  "deque_test.res",
                  51,
                  16
                ],
                Error: new Error()
              };
        };
        var cw = function (circle) {
          var v = Deque.peekFront(circle);
          if (v !== undefined) {
            return Deque.pushBack(Deque.popFront(circle), Caml_option.valFromOption(v));
          }
          throw {
                RE_EXN_ID: "Assert_failure",
                _1: [
                  "deque_test.res",
                  57,
                  16
                ],
                Error: new Error()
              };
        };
        var peek = function (circle) {
          var v = Deque.peekBack(circle);
          if (v !== undefined) {
            return Caml_option.valFromOption(v);
          }
          throw {
                RE_EXN_ID: "Assert_failure",
                _1: [
                  "deque_test.res",
                  65,
                  16
                ],
                Error: new Error()
              };
        };
        var place = function (circle, nextNum) {
          if (nextNum % 23 !== 0) {
            return [
                    Deque.pushBack(cw(circle), nextNum),
                    0
                  ];
          }
          var circle$1 = ccw(ccw(ccw(ccw(ccw(ccw(ccw(circle)))))));
          var scoreAt = peek(circle$1);
          return [
                  cw(Deque.popBack(circle$1)),
                  scoreAt + nextNum | 0
                ];
        };
        var play = function (circle, numPlayers, lastMarble) {
          var _circle = circle;
          var _marble = 1;
          var _scoreMap;
          while(true) {
            var scoreMap = _scoreMap;
            var marble = _marble;
            var circle$1 = _circle;
            if (marble > lastMarble) {
              var scores = Belt_SortArrayInt.stableSort(Belt_MapInt.valuesToArray(scoreMap));
              return Belt_Array.getExn(scores, scores.length - 1 | 0);
            }
            var match = place(circle$1, marble);
            var score = match[1];
            var player = Caml_int32.mod_(marble, numPlayers);
            var scoreMap$1 = Belt_MapInt.update(scoreMap, player, (function(score){
                return function (v) {
                  return v !== undefined ? v + score | 0 : score;
                }
                }(score)));
            _scoreMap = scoreMap$1;
            _marble = marble + 1 | 0;
            _circle = match[0];
            continue ;
          };
        };
        t.is(play(Deque.pushFront(Deque.empty, 0), 9, 25), 32, "");
        t.is(play(Deque.pushFront(Deque.empty, 0), 459, 71790), 386151, "");
        t.is(play(Deque.pushFront(Deque.empty, 0), 459, 717900), 32700280, "");
        return Zora.done(undefined);
      }));

export {
  
}
/*  Not a pure module */