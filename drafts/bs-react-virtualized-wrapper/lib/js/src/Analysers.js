// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var List       = require("bs-platform/lib/js/list.js");
var Caml_float = require("bs-platform/lib/js/caml_float.js");

function printPatient(patient) {
  return List.iter((function (journey) {
                return List.iter((function (stage) {
                              console.log(stage);
                              return /* () */0;
                            }), journey[/* stages */1]);
              }), patient[/* journeys */1]);
}

function stageProcessor(stage) {
  var match = stage[/* departure */4];
  if (match && stage[/* arrival */3].getTime() >= match[0].getTime()) {
    return /* Failed */[/* :: */[
              stage,
              /* [] */0
            ]];
  } else {
    return /* Ok */0;
  }
}

function processor_001(_, patient) {
  var journeys = patient[/* journeys */1];
  var stages = List.fold_left((function (stages, journey) {
          return List.concat(/* :: */[
                      stages,
                      /* :: */[
                        journey[/* stages */1],
                        /* [] */0
                      ]
                    ]);
        }), /* [] */0, journeys);
  var errors = List.fold_left((function (errors, stage) {
          var match = stageProcessor(stage);
          if (match) {
            return List.concat(/* :: */[
                        errors,
                        /* :: */[
                          match[0],
                          /* [] */0
                        ]
                      ]);
          } else {
            return errors;
          }
        }), /* [] */0, stages);
  var match = +(List.length(errors) === 0);
  if (match !== 0) {
    return /* Ok */0;
  } else {
    return /* Failed */[errors];
  }
}

var processor = /* tuple */[
  "ensure admission before discharge",
  processor_001
];

var EnsureAdmissionBeforeDischarge = /* module */[
  /* stageProcessor */stageProcessor,
  /* processor */processor
];

var nowMs = Date.now();

function stageProcessor$1(stage) {
  var match = Caml_float.caml_float_compare(nowMs, stage[/* arrival */3].getTime());
  if (match !== -1) {
    return /* Ok */0;
  } else {
    return /* Failed */[/* :: */[
              stage,
              /* [] */0
            ]];
  }
}

function processor_001$1(_, patient) {
  var journeys = patient[/* journeys */1];
  var stages = List.fold_left((function (stages, journey) {
          return List.concat(/* :: */[
                      stages,
                      /* :: */[
                        journey[/* stages */1],
                        /* [] */0
                      ]
                    ]);
        }), /* [] */0, journeys);
  var errors = List.fold_left((function (errors, stage) {
          var match = stageProcessor$1(stage);
          if (match) {
            return List.concat(/* :: */[
                        errors,
                        /* :: */[
                          match[0],
                          /* [] */0
                        ]
                      ]);
          } else {
            return errors;
          }
        }), /* [] */0, stages);
  var match = +(List.length(errors) === 0);
  if (match !== 0) {
    return /* Ok */0;
  } else {
    return /* Failed */[errors];
  }
}

var processor$1 = /* tuple */[
  "admissions cannot be after `now`",
  processor_001$1
];

var PreventTimeTravel = /* module */[
  /* nowMs */nowMs,
  /* stageProcessor */stageProcessor$1,
  /* processor */processor$1
];

function journeyProcessor(stages) {
  var stages$1 = List.sort((function (a, b) {
          return Caml_float.caml_float_compare(a[/* arrival */3].getTime(), b[/* arrival */3].getTime());
        }), stages);
  var departures = List.find_all((function (stage) {
            var match = stage[/* departure */4];
            if (match) {
              return /* false */0;
            } else {
              return /* true */1;
            }
          }))(stages$1);
  var match = List.length(departures);
  if (match !== 0) {
    if (match !== 1) {
      return /* Failed */[departures];
    } else {
      var match$1 = +(List.hd(departures) === List.hd(List.rev(stages$1)));
      if (match$1 !== 0) {
        return /* Ok */0;
      } else {
        return /* Failed */[departures];
      }
    }
  } else {
    return /* Ok */0;
  }
}

function processor_001$2(_, patient) {
  var journeys = patient[/* journeys */1];
  var errors = List.fold_left((function (errors, journey) {
          var match = journeyProcessor(journey[/* stages */1]);
          if (match) {
            return List.concat(/* :: */[
                        errors,
                        /* :: */[
                          match[0],
                          /* [] */0
                        ]
                      ]);
          } else {
            return errors;
          }
        }), /* [] */0, journeys);
  var match = +(List.length(errors) === 0);
  if (match !== 0) {
    return /* Ok */0;
  } else {
    return /* Failed */[errors];
  }
}

var processor$2 = /* tuple */[
  "departure is only at the end",
  processor_001$2
];

var TheOnlyDepartureIsAtTheEnd = /* module */[
  /* journeyProcessor */journeyProcessor,
  /* processor */processor$2
];

function journeyProcessor$1(stages) {
  var stages$1 = List.sort((function (a, b) {
          return Caml_float.caml_float_compare(a[/* arrival */3].getTime(), b[/* arrival */3].getTime());
        }), stages);
  var match = List.fold_left((function (param, stage) {
          var lastDeparture = param[1];
          var erroredStages = param[0];
          var valid = lastDeparture ? +(stage[/* arrival */3].getTime() === lastDeparture[0].getTime()) : /* true */1;
          var erroredStages$1 = valid !== 0 ? erroredStages : List.concat(/* :: */[
                  erroredStages,
                  /* :: */[
                    /* :: */[
                      stage,
                      /* [] */0
                    ],
                    /* [] */0
                  ]
                ]);
          return /* tuple */[
                  erroredStages$1,
                  stage[/* departure */4]
                ];
        }), /* tuple */[
        /* [] */0,
        /* None */0
      ], stages$1);
  var errors = match[0];
  var match$1 = +(List.length(errors) === 0);
  if (match$1 !== 0) {
    return /* Ok */0;
  } else {
    return /* Failed */[errors];
  }
}

function processor_001$3(_, patient) {
  var journeys = patient[/* journeys */1];
  var errors = List.fold_left((function (errors, journey) {
          var match = journeyProcessor$1(journey[/* stages */1]);
          if (match) {
            return List.concat(/* :: */[
                        errors,
                        /* :: */[
                          match[0],
                          /* [] */0
                        ]
                      ]);
          } else {
            return errors;
          }
        }), /* [] */0, journeys);
  var match = +(List.length(errors) === 0);
  if (match !== 0) {
    return /* Ok */0;
  } else {
    return /* Failed */[errors];
  }
}

var processor$3 = /* tuple */[
  "stages are contiguous within a journey",
  processor_001$3
];

var StagesAreConsecutiveWithinAJourney = /* module */[
  /* journeyProcessor */journeyProcessor$1,
  /* processor */processor$3
];

function time(prim) {
  return prim.getTime();
}

function isJourneyOverlap(a, b) {
  var aDeparture = List.hd(List.rev(a[/* stages */1]))[/* departure */4];
  var bArrival = List.hd(b[/* stages */1])[/* arrival */3];
  var upperBound = new Date(9999, 12);
  var aDeparture$1 = aDeparture ? aDeparture[0] : upperBound;
  return +(aDeparture$1.getTime() > bArrival.getTime());
}

function journeysProcessor(unsortedJourneys) {
  var journeys = List.sort((function (a, b) {
          return Caml_float.caml_float_compare(List.hd(a[/* stages */1])[/* arrival */3].getTime(), List.hd(b[/* stages */1])[/* arrival */3].getTime());
        }), unsortedJourneys);
  var match = List.fold_left((function (param, journey) {
          var errors = param[0];
          var match = isJourneyOverlap(param[1], journey);
          if (match !== 0) {
            return /* tuple */[
                    List.concat(/* :: */[
                          errors,
                          /* :: */[
                            /* :: */[
                              List.hd(journey[/* stages */1]),
                              /* [] */0
                            ],
                            /* [] */0
                          ]
                        ]),
                    journey
                  ];
          } else {
            return /* tuple */[
                    errors,
                    journey
                  ];
          }
        }), /* tuple */[
        /* [] */0,
        List.hd(journeys)
      ], List.tl(journeys));
  var errors = match[0];
  var match$1 = +(List.length(errors) === 0);
  if (match$1 !== 0) {
    return /* Ok */0;
  } else {
    return /* Failed */[errors];
  }
}

function processor_001$4(_, patient) {
  return journeysProcessor(patient[/* journeys */1]);
}

var processor$4 = /* tuple */[
  "journeys are consecutive",
  processor_001$4
];

var JourneysAreConsecutive = /* module */[
  /* journeysProcessor */journeysProcessor,
  /* processor */processor$4
];

var analysers_001 = /* :: */[
  processor,
  /* :: */[
    processor$2,
    /* :: */[
      processor$4,
      /* :: */[
        processor$3,
        /* :: */[
          /* tuple */[
            "another analyser",
            (function (_, _$1) {
                return /* Ok */0;
              })
          ],
          /* :: */[
            /* tuple */[
              "and another analyser",
              (function (_, _$1) {
                  return /* Ok */0;
                })
            ],
            /* [] */0
          ]
        ]
      ]
    ]
  ]
];

var analysers = /* :: */[
  processor$1,
  analysers_001
];

exports.printPatient                       = printPatient;
exports.EnsureAdmissionBeforeDischarge     = EnsureAdmissionBeforeDischarge;
exports.PreventTimeTravel                  = PreventTimeTravel;
exports.TheOnlyDepartureIsAtTheEnd         = TheOnlyDepartureIsAtTheEnd;
exports.StagesAreConsecutiveWithinAJourney = StagesAreConsecutiveWithinAJourney;
exports.time                               = time;
exports.isJourneyOverlap                   = isJourneyOverlap;
exports.JourneysAreConsecutive             = JourneysAreConsecutive;
exports.analysers                          = analysers;
/* nowMs Not a pure module */