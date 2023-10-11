// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Spectacle = require("spectacle");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

function make(order, fid, children) {
  var tmp = { };
  if (order !== undefined) {
    tmp.order = Js_primitive.valFromOption(order);
  }
  if (fid !== undefined) {
    tmp.fid = Js_primitive.valFromOption(fid);
  }
  return ReasonReact.wrapJsForReason(Spectacle.Appear, tmp, children);
}

exports.make = make;
/* spectacle Not a pure module */