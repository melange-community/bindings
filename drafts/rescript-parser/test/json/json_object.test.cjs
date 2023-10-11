// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Json = require("./parser/json.cjs");
var Belt_Array = require("rescript/lib/js/belt_Array.js");
var Test_runners = require("../test_runners.cjs");

function decorate(__x) {
  return Belt_Array.map(__x, (function (param) {
                return [
                        param[0],
                        param[1],
                        ""
                      ];
              }));
}

Test_runners.runTests(Json.parse, (function (input, param) {
        return "[JSON Object] Run with \"" + input + "\"";
      }), decorate([
          [
            "{}",
            {
              TAG: /* Object */0,
              _0: /* [] */0
            }
          ],
          [
            "    {  }       ",
            {
              TAG: /* Object */0,
              _0: /* [] */0
            }
          ],
          [
            " { \"a\":1  }       ",
            {
              TAG: /* Object */0,
              _0: {
                hd: [
                  "a",
                  {
                    TAG: /* Number */1,
                    _0: "1"
                  }
                ],
                tl: /* [] */0
              }
            }
          ],
          [
            " { \"\":\"\"  }  ",
            {
              TAG: /* Object */0,
              _0: {
                hd: [
                  "",
                  {
                    TAG: /* String */2,
                    _0: ""
                  }
                ],
                tl: /* [] */0
              }
            }
          ],
          [
            " { \"foo\": {\"bar  \"   : { \"baz\":1 }}  }  ",
            {
              TAG: /* Object */0,
              _0: {
                hd: [
                  "foo",
                  {
                    TAG: /* Object */0,
                    _0: {
                      hd: [
                        "bar  ",
                        {
                          TAG: /* Object */0,
                          _0: {
                            hd: [
                              "baz",
                              {
                                TAG: /* Number */1,
                                _0: "1"
                              }
                            ],
                            tl: /* [] */0
                          }
                        }
                      ],
                      tl: /* [] */0
                    }
                  }
                ],
                tl: /* [] */0
              }
            }
          ],
          [
            " { \"foo\": [1]  }  ",
            {
              TAG: /* Object */0,
              _0: {
                hd: [
                  "foo",
                  {
                    TAG: /* Array */3,
                    _0: {
                      hd: {
                        TAG: /* Number */1,
                        _0: "1"
                      },
                      tl: /* [] */0
                    }
                  }
                ],
                tl: /* [] */0
              }
            }
          ],
          [
            " { \"foo\": [1, [[2]]]  }  ",
            {
              TAG: /* Object */0,
              _0: {
                hd: [
                  "foo",
                  {
                    TAG: /* Array */3,
                    _0: {
                      hd: {
                        TAG: /* Number */1,
                        _0: "1"
                      },
                      tl: {
                        hd: {
                          TAG: /* Array */3,
                          _0: {
                            hd: {
                              TAG: /* Array */3,
                              _0: {
                                hd: {
                                  TAG: /* Number */1,
                                  _0: "2"
                                },
                                tl: /* [] */0
                              }
                            },
                            tl: /* [] */0
                          }
                        },
                        tl: /* [] */0
                      }
                    }
                  }
                ],
                tl: /* [] */0
              }
            }
          ],
          [
            " { \"foo\": [1, [[2, 2]]]  }  ",
            {
              TAG: /* Object */0,
              _0: {
                hd: [
                  "foo",
                  {
                    TAG: /* Array */3,
                    _0: {
                      hd: {
                        TAG: /* Number */1,
                        _0: "1"
                      },
                      tl: {
                        hd: {
                          TAG: /* Array */3,
                          _0: {
                            hd: {
                              TAG: /* Array */3,
                              _0: {
                                hd: {
                                  TAG: /* Number */1,
                                  _0: "2"
                                },
                                tl: {
                                  hd: {
                                    TAG: /* Number */1,
                                    _0: "2"
                                  },
                                  tl: /* [] */0
                                }
                              }
                            },
                            tl: /* [] */0
                          }
                        },
                        tl: /* [] */0
                      }
                    }
                  }
                ],
                tl: /* [] */0
              }
            }
          ],
          [
            " { \"foo\": [1, [[2, 2, []]]]  }  ",
            {
              TAG: /* Object */0,
              _0: {
                hd: [
                  "foo",
                  {
                    TAG: /* Array */3,
                    _0: {
                      hd: {
                        TAG: /* Number */1,
                        _0: "1"
                      },
                      tl: {
                        hd: {
                          TAG: /* Array */3,
                          _0: {
                            hd: {
                              TAG: /* Array */3,
                              _0: {
                                hd: {
                                  TAG: /* Number */1,
                                  _0: "2"
                                },
                                tl: {
                                  hd: {
                                    TAG: /* Number */1,
                                    _0: "2"
                                  },
                                  tl: {
                                    hd: {
                                      TAG: /* Array */3,
                                      _0: /* [] */0
                                    },
                                    tl: /* [] */0
                                  }
                                }
                              }
                            },
                            tl: /* [] */0
                          }
                        },
                        tl: /* [] */0
                      }
                    }
                  }
                ],
                tl: /* [] */0
              }
            }
          ],
          [
            " { \"foo\": [1, [[2   ,2,[[3         ]]] ]]  }  ",
            {
              TAG: /* Object */0,
              _0: {
                hd: [
                  "foo",
                  {
                    TAG: /* Array */3,
                    _0: {
                      hd: {
                        TAG: /* Number */1,
                        _0: "1"
                      },
                      tl: {
                        hd: {
                          TAG: /* Array */3,
                          _0: {
                            hd: {
                              TAG: /* Array */3,
                              _0: {
                                hd: {
                                  TAG: /* Number */1,
                                  _0: "2"
                                },
                                tl: {
                                  hd: {
                                    TAG: /* Number */1,
                                    _0: "2"
                                  },
                                  tl: {
                                    hd: {
                                      TAG: /* Array */3,
                                      _0: {
                                        hd: {
                                          TAG: /* Array */3,
                                          _0: {
                                            hd: {
                                              TAG: /* Number */1,
                                              _0: "3"
                                            },
                                            tl: /* [] */0
                                          }
                                        },
                                        tl: /* [] */0
                                      }
                                    },
                                    tl: /* [] */0
                                  }
                                }
                              }
                            },
                            tl: /* [] */0
                          }
                        },
                        tl: /* [] */0
                      }
                    }
                  }
                ],
                tl: /* [] */0
              }
            }
          ],
          [
            " { \"foo\": [1, [[2   ,2,[[3        , {\"b_\": [1234]} ]]] ]]  }  ",
            {
              TAG: /* Object */0,
              _0: {
                hd: [
                  "foo",
                  {
                    TAG: /* Array */3,
                    _0: {
                      hd: {
                        TAG: /* Number */1,
                        _0: "1"
                      },
                      tl: {
                        hd: {
                          TAG: /* Array */3,
                          _0: {
                            hd: {
                              TAG: /* Array */3,
                              _0: {
                                hd: {
                                  TAG: /* Number */1,
                                  _0: "2"
                                },
                                tl: {
                                  hd: {
                                    TAG: /* Number */1,
                                    _0: "2"
                                  },
                                  tl: {
                                    hd: {
                                      TAG: /* Array */3,
                                      _0: {
                                        hd: {
                                          TAG: /* Array */3,
                                          _0: {
                                            hd: {
                                              TAG: /* Number */1,
                                              _0: "3"
                                            },
                                            tl: {
                                              hd: {
                                                TAG: /* Object */0,
                                                _0: {
                                                  hd: [
                                                    "b_",
                                                    {
                                                      TAG: /* Array */3,
                                                      _0: {
                                                        hd: {
                                                          TAG: /* Number */1,
                                                          _0: "1234"
                                                        },
                                                        tl: /* [] */0
                                                      }
                                                    }
                                                  ],
                                                  tl: /* [] */0
                                                }
                                              },
                                              tl: /* [] */0
                                            }
                                          }
                                        },
                                        tl: /* [] */0
                                      }
                                    },
                                    tl: /* [] */0
                                  }
                                }
                              }
                            },
                            tl: /* [] */0
                          }
                        },
                        tl: /* [] */0
                      }
                    }
                  }
                ],
                tl: /* [] */0
              }
            }
          ]
        ]));

Test_runners.runTests(Json.parse, (function (input, param) {
        return "[JSON Object] Run with \"" + input + "\"";
      }), [
      [
        "{}a",
        {
          TAG: /* Object */0,
          _0: /* [] */0
        },
        "a"
      ],
      [
        "{ \"hello\": 1234 }}}",
        {
          TAG: /* Object */0,
          _0: {
            hd: [
              "hello",
              {
                TAG: /* Number */1,
                _0: "1234"
              }
            ],
            tl: /* [] */0
          }
        },
        "}}"
      ],
      [
        "{ \"hello\": 1234 }]]",
        {
          TAG: /* Object */0,
          _0: {
            hd: [
              "hello",
              {
                TAG: /* Number */1,
                _0: "1234"
              }
            ],
            tl: /* [] */0
          }
        },
        "]]"
      ],
      [
        "{ \"hello\": [1234] }-)",
        {
          TAG: /* Object */0,
          _0: {
            hd: [
              "hello",
              {
                TAG: /* Array */3,
                _0: {
                  hd: {
                    TAG: /* Number */1,
                    _0: "1234"
                  },
                  tl: /* [] */0
                }
              }
            ],
            tl: /* [] */0
          }
        },
        "-)"
      ]
    ]);

Test_runners.runFailureTests(Json.parse, (function (input) {
        return "[JSON Object] Run with \"" + input + "\"";
      }), [
      "       +{}",
      "_{}",
      "|{\"hello\": 1}",
      "a{}",
      "~{f}"
    ]);

exports.decorate = decorate;
/*  Not a pure module */
