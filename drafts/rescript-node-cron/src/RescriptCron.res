module CronJob = {
  type t

  @module("cron") @new
  external make: (
    @unwrap [#CronString(string) | #JsDate(Js.Date.t)],
    (unit => unit) => unit,
    unit => unit,
    Js.nullable<bool>,
    Js.nullable<string>,
    Js.nullable<{..}>,
    Js.nullable<bool>,
    Js.nullable<int>,
    Js.nullable<bool>,
  ) => t = "CronJob"

  let make = (
    cronTime: [#CronString(string) | #JsDate(Js.Date.t)],
    onTick: (unit => unit) => unit,
    ~onComplete: unit => unit=_ => (),
    ~start: option<bool>=?,
    ~timezone: option<string>=?,
    ~context: option<{..}>=?,
    ~runOnInit: option<bool>=?,
    ~utcOffset: option<int>=?, // Could also be string, but that complicates
    ~unrefTimeout: option<bool>=?,
    (),
  ) =>
    make(
      cronTime,
      onTick,
      onComplete,
      Js.Nullable.fromOption(start),
      Js.Nullable.fromOption(timezone),
      Js.Nullable.fromOption(context),
      Js.Nullable.fromOption(runOnInit),
      Js.Nullable.fromOption(utcOffset),
      Js.Nullable.fromOption(unrefTimeout),
    )
}

module CronTime = {
  type t

  @module("cron") @new
  external make: (
    @unwrap [#CronString(string) | #JsDate(Js.Date.t)],
    Js.nullable<string>,
    Js.nullable<int>,
  ) => t = "CronTime"

  let make = (
    cronTime: [#CronString(string) | #JsDate(Js.Date.t)],
    ~timezone: option<string>=?,
    ~utcOffset: option<int>=?,
    (),
  ) => make(cronTime, Js.Nullable.fromOption(timezone), Js.Nullable.fromOption(utcOffset))
}

@module("cron") @val
external sendAt: @unwrap [#CronString(string) | #JsDate(Js.Date.t)] => MomentRe.Moment.t = "sendAt"

@module("cron") @val
external timeout: @unwrap [#CronString(string) | #JsDate(Js.Date.t)] => float = "timeout"

@send external start: CronJob.t => unit = "start"
@send external stop: CronJob.t => unit = "stop"
@send external setTime: (CronJob.t, CronTime.t) => unit = "setTime"
@send external lastDate: CronJob.t => Js.Date.t = "lastDate"
@send external nextDates: (CronJob.t, int) => 'a = "nextDates"

let nextDates = (job, numberOfDates): array<MomentRe.Moment.t> => {
  let next = nextDates(job, numberOfDates)
  let convertToArray: 'a => 'b = %raw(
    "possiblyArray => Array.isArray(possiblyArray) ? possiblyArray : [ possiblyArray ]"
  )

  // nextDates can return both an array of Moment's and a single Moment,
  // depending of how to the time field on the CronJob was created.
  // For consistency it is always returning an array here.

  convertToArray(next)
}

let nextMomentDates = (~numberOfDates=1, job: CronJob.t) => nextDates(job, numberOfDates)

let nextJsDates = (~numberOfDates=1, job: CronJob.t) =>
  nextDates(job, numberOfDates)->Belt.Array.map(MomentRe.Moment.toDate)

@send external fireOnTick: CronJob.t => unit = "fireOnTick"

@send
external addCallback: (CronJob.t, (unit => unit) => unit) => unit = "addCallback"
