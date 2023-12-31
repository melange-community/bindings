// Generated by ReScript, PLEASE EDIT WITH CARE

import * as Caml from "@rescript/std/lib/es6/caml.js";
import * as Curry from "@rescript/std/lib/es6/curry.js";
import * as React from "react";
import * as Js_dict from "@rescript/std/lib/es6/js_dict.js";
import * as Belt_List from "@rescript/std/lib/es6/belt_List.js";
import * as Benchmark from "benchmark";
import * as Belt_Array from "@rescript/std/lib/es6/belt_Array.js";
import * as Router$Benchmark from "./Router.js";
import * as Suite_Vector$Benchmark from "./Suite_Vector.js";

var Prism = {};

var MyDom = {};

var prefix = "rescript-collection";

function set(title) {
  document.setTitle = prefix + (" - " + title);
}

function reset(param) {
  document.setTitle = prefix;
}

var DocTitle = {
  prefix: prefix,
  set: set,
  reset: reset
};

function reducer(_oldState, newState) {
  return newState;
}

function useState(initialState) {
  var match = React.useReducer(reducer, initialState);
  var dispatch = match[1];
  return [
          match[0],
          Curry.__1(dispatch)
        ];
}

function percentDiff(a, b) {
  return Math.floor((b - a) / b * 100);
}

function speedRank(name, fastest, slowest, hz) {
  if (name === fastest) {
    return /* Fastest */0;
  } else if (name === slowest) {
    return {
            TAG: /* Slowest */1,
            _0: hz
          };
  } else {
    return {
            TAG: /* Slower */0,
            _0: hz
          };
  }
}

function App$Results(Props) {
  var hz = Props.hz;
  var rme = Props.rme;
  var sample = Props.sample;
  var speedRank = Props.speedRank;
  var tmp;
  tmp = typeof speedRank === "number" ? React.createElement("p", {
          className: "fastest speedRank"
        }, "fastest") : (
      speedRank.TAG === /* Slower */0 ? React.createElement("p", {
              className: "speedRank"
            }, window.Benchmark.formatNumber(percentDiff(hz, speedRank._0)) + "% slower") : React.createElement(React.Fragment, undefined, React.createElement("p", {
                  className: "slowest speedRank"
                }, "slowest"), React.createElement("p", {
                  className: "speedRank"
                }, window.Benchmark.formatNumber(percentDiff(hz, speedRank._0)) + "% slower"))
    );
  return React.createElement("div", undefined, tmp, React.createElement("dl", undefined, React.createElement("dt", undefined, "operations per second"), React.createElement("dd", undefined, window.Benchmark.formatNumber(Math.round(hz))), React.createElement("dt", undefined, "relative margin of error"), React.createElement("dd", undefined, "±", window.Benchmark.formatNumber(Math.round(rme)), "%"), React.createElement("dt", undefined, "samples"), React.createElement("dd", undefined, String(sample.length))));
}

var Results = {
  make: App$Results
};

function App$Item(Props) {
  var name = Props.name;
  var code = Props.code;
  var f = Props.f;
  var suite = Props.suite;
  var suiteRunning = Props.suiteRunning;
  var match = useState(/* Queued */0);
  var setResult = match[1];
  var result = match[0];
  React.useEffect((function () {
          window.Prism.highlightAll();
          suite.add(name, f, {
                onComplete: (function (param) {
                    var currentTarget = param.currentTarget;
                    if (!currentTarget.aborted) {
                      return setResult(/* Complete */{
                                  time: Date.now(),
                                  benchmark: currentTarget
                                });
                    }
                    
                  }),
                onStart: (function (param) {
                    if (!param.currentTarget.aborted) {
                      return setResult(/* Running */1);
                    }
                    
                  })
              });
        }), [suite]);
  var tmp;
  var exit = 0;
  if (typeof suiteRunning === "number") {
    exit = 2;
  } else if (suiteRunning.TAG === /* Started */0) {
    var exit$1 = 0;
    if (typeof result === "number") {
      if (result !== 0) {
        exit = 1;
      } else {
        exit$1 = 3;
      }
    } else if (suiteRunning.time < result.time) {
      tmp = React.createElement("p", {
            className: "subtle"
          }, "Done. Waiting for the other tests.");
    } else {
      exit$1 = 3;
    }
    if (exit$1 === 3) {
      tmp = React.createElement("p", {
            className: "subtle"
          }, "Waiting");
    }
    
  } else if (typeof result === "number") {
    exit = result !== 0 ? 1 : 2;
  } else {
    var match$1 = result.benchmark;
    var match$2 = match$1.stats;
    tmp = React.createElement(App$Results, {
          hz: match$1.hz,
          rme: match$2.rme,
          sample: match$2.sample,
          speedRank: speedRank(match$1.name, suiteRunning.fastest, suiteRunning.slowest, suiteRunning.fastestHz)
        });
  }
  switch (exit) {
    case 1 :
        tmp = React.createElement("p", {
              className: "subtle"
            }, "Running...");
        break;
    case 2 :
        tmp = React.createElement("p", {
              className: "subtle"
            }, "Not started");
        break;
    
  }
  return React.createElement("div", {
              className: "item"
            }, React.createElement("div", {
                  className: "item__body"
                }, React.createElement("header", {
                      className: "item__header"
                    }, React.createElement("h2", {
                          className: "item__header_h"
                        }, React.createElement("code", undefined, name))), React.createElement("div", {
                      className: "code item__code"
                    }, React.createElement("pre", undefined, React.createElement("code", {
                              className: "language-reason"
                            }, code)))), React.createElement("div", {
                  className: "item__results"
                }, React.createElement("h3", undefined, "Results"), tmp));
}

var Item = {
  make: App$Item
};

function App$SuiteComponent(Props) {
  var benchmarks = Props.benchmarks;
  var suite = Props.suite;
  var suiteRunning = Props.suiteRunning;
  return React.createElement("div", undefined, Belt_Array.map(benchmarks, (function (param) {
                    var name = param.name;
                    return React.createElement(App$Item, {
                                name: name,
                                code: param.code,
                                f: param.f,
                                suite: suite,
                                suiteRunning: suiteRunning,
                                key: name
                              });
                  })));
}

var SuiteComponent = {
  make: App$SuiteComponent
};

function getStats(param) {
  var currentTarget = param.currentTarget;
  var results = Belt_List.sort(Belt_List.keepMap(Belt_List.makeBy(currentTarget.length, (function (prim) {
                  return String(prim);
                })), (function (param) {
              return Js_dict.get(currentTarget, param);
            })), (function (a, b) {
          return Caml.float_compare(b.hz, a.hz);
        }));
  if (!results) {
    return /* NotStarted */0;
  }
  var rest = results.tl;
  var match = results.hd;
  var hz = match.hz;
  var name = match.name;
  if (!rest) {
    return {
            TAG: /* Stopped */1,
            fastest: name,
            slowest: name,
            fastestHz: hz
          };
  }
  var match$1 = Belt_List.reverse(rest);
  if (match$1) {
    return {
            TAG: /* Stopped */1,
            fastest: name,
            slowest: match$1.hd.name,
            fastestHz: hz
          };
  } else {
    return /* NotStarted */0;
  }
}

function App$Wrapper(Props) {
  var benchmarks = Props.benchmarks;
  var setup = Props.setup;
  var suite = Props.suite;
  var match = useState(/* NotStarted */0);
  var setRunning = match[1];
  var suiteRunning = match[0];
  React.useEffect((function () {
          suite.on("start", (function (param) {
                    if (!param.currentTarget.aborted) {
                      return setRunning({
                                  TAG: /* Started */0,
                                  time: Date.now()
                                });
                    }
                    
                  })).on("complete", (function (e) {
                  if (!e.currentTarget.aborted) {
                    return setRunning(getStats(e));
                  }
                  
                }));
          return (function (param) {
                    suite.abort();
                  });
        }), [suite]);
  React.useEffect((function () {
          set(suite.name);
          return reset;
        }), []);
  var name = window.Benchmark.platform.name;
  var tmp;
  if (name == null) {
    tmp = React.createElement("dd", undefined, "Unknown");
  } else {
    var version = window.Benchmark.platform.version;
    tmp = React.createElement("dd", undefined, name, (version == null) ? null : " " + version);
  }
  var os = window.Benchmark.platform.os;
  var tmp$1;
  tmp$1 = typeof suiteRunning === "number" || suiteRunning.TAG !== /* Started */0 ? false : true;
  var tmp$2;
  tmp$2 = typeof suiteRunning === "number" || suiteRunning.TAG !== /* Started */0 ? "Run" : "Running...";
  return React.createElement("section", undefined, React.createElement("header", undefined, React.createElement("h1", undefined, suite.name)), React.createElement("div", {
                  className: "setup"
                }, React.createElement("div", {
                      className: "setup__body"
                    }, React.createElement("h2", undefined, "Setup"), React.createElement("div", {
                          className: "code"
                        }, React.createElement("pre", undefined, React.createElement("code", {
                                  className: "language-reason"
                                }, setup)))), React.createElement("dl", {
                      className: "setup__platform"
                    }, React.createElement("dt", undefined, "Browser"), tmp, React.createElement("dt", undefined, "Operating system"), (os == null) ? React.createElement("dd", undefined, "Unknown") : React.createElement("dd", undefined, os.toString()))), React.createElement("div", {
                  className: "run"
                }, React.createElement("button", {
                      className: "run__button",
                      disabled: tmp$1,
                      onClick: (function (param) {
                          suite.run({
                                async: true
                              });
                        })
                    }, tmp$2)), React.createElement(App$SuiteComponent, {
                  benchmarks: benchmarks,
                  suite: suite,
                  suiteRunning: suiteRunning
                }));
}

var Wrapper = {
  make: App$Wrapper
};

function App$Tests(Props) {
  var name = Props.name;
  var menu = Props.menu;
  return React.createElement(React.Fragment, undefined, React.createElement("h2", undefined, name), React.createElement("ul", {
                  className: "menu"
                }, Belt_Array.map(menu, (function (route) {
                        return React.createElement("li", {
                                    key: Router$Benchmark.toString(route),
                                    className: "menu__item"
                                  }, React.createElement(Router$Benchmark.HashLink.make, {
                                        children: Router$Benchmark.name(route),
                                        to_: route
                                      }));
                      }))));
}

var Tests = {
  make: App$Tests
};

function App(Props) {
  var url = Router$Benchmark.useUrl(undefined);
  React.useEffect((function () {
          document.setTitle = prefix;
        }), []);
  var tmp;
  if (url) {
    var match = Suite_Vector$Benchmark.Routes.map(url._0).suite;
    var suite = new Benchmark.Suite(match.name);
    tmp = React.createElement(React.Fragment, undefined, React.createElement(Router$Benchmark.HashLink.make, {
              children: null,
              to_: /* Index */0,
              className: "go-home"
            }, "←", Router$Benchmark.name(/* Index */0)), React.createElement(App$Wrapper, {
              benchmarks: match.benchmarks,
              setup: match.setup,
              suite: suite
            }));
  } else {
    tmp = React.createElement(React.Fragment, undefined, React.createElement(App$Tests, {
              name: "rescript-vector",
              menu: Router$Benchmark.vectorMenu
            }));
  }
  return React.createElement("div", {
              className: "smallscreen-padding"
            }, React.createElement("main", {
                  className: "main "
                }, React.createElement("header", undefined, React.createElement("p", {
                          className: "site-title"
                        }, React.createElement(Router$Benchmark.HashLink.make, {
                              children: "rescript-collection",
                              to_: /* Index */0,
                              className: "site-title__link"
                            }))), tmp));
}

var B;

var make = App;

export {
  B ,
  Prism ,
  MyDom ,
  DocTitle ,
  reducer ,
  useState ,
  percentDiff ,
  speedRank ,
  Results ,
  Item ,
  SuiteComponent ,
  getStats ,
  Wrapper ,
  Tests ,
  make ,
}
/* react Not a pure module */
