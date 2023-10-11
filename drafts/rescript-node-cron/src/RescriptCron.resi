@ocaml.doc(
  " From {{: https://github.com/kelektiv/node-cron } node-cron GitHub-page }: Cron is a tool that allows you to execute something on a schedule. This is typically done using the cron syntax. We allow you to execute a function whenever your scheduled job triggers. We also allow you to execute a job external to the JavaScript process using [child_process]. Additionally, this library goes beyond the basic cron syntax and allows you to supply a {!val:Js.Date.t} object. This will be used as the trigger for your callback. Cron syntax is still an acceptable cron time format. Although the Cron patterns supported here extend on the standard Unix format to support seconds digits, leaving it off will default to 0 and match the Unix behavior. "
)
@ocaml.doc(" Module for creating new cron jobs ")
module CronJob: {
  type t

  @ocaml.doc(" [make(cronTime, onTickFunction)] returns a cron job that when started will run on the schedule specified by the cron time.

  @param cronTime The syntax of [cronTime] can be in cron format (e.g. [2 * * * * * *]) or as a {!type:Js.Date.t}.
  @param onTick The function that will be run for every job execution (specified by the cron time). It will be passed the function given as [onComplete] parameter as it's parameter.
  @param onComplete A function that will fire when the job is stopped with {!val:stop}, and may also be called by [onTick] at the end of each run (it is passed to [onTick]).
  @param start Specifies whether to start the job just before exiting the constructor. By default this is set to false. If left at default you will need to call {!val:start} in order to start the job (assuming job is the variable you set the cronjob to). This does not immediately fire your [onTick] function, it just gives you more control over the behavior of your jobs.
  @param timezone Specify the timezone for the execution. This will modify the actual time relative to your timezone. If the timezone is invalid, an error is thrown. You can check all timezones available at {{: http://momentjs.com/timezone/ } Moment Timezone website }. Probably don't use both [timezone] and [utcOffset] together or weird things may happen.
  @param context The context within which to execute the [onTick] method. This defaults to the cronjob itself allowing you to call [this.stop()] (this is for JS, uncertain how this is in ReasonML/OCaml). However, if you change this you'll have access to the functions and values within your context object.
  @param runOnInit This will immediately fire your [onTick] function as soon as the requisite initialization has happened. This option is set to [false] by default for backwards compatibility.
  @param utcOffset Set an UTC offset for your timezone instead of using the [timezone] parameter. This is for a Moment-object, so see {{: https://momentjs.com/docs/#/manipulating/utc-offset/ } Moment-documentation } for more info. Do not use [utcOffset] and [timezone] parameter together.
  @param unrefTimeout If you have code that keeps the event loop running and want to stop the node process when that finishes regardless of the state of your cronjob, you can do so making use of this parameter. This is off by default and cron will run as if it needs to control the event loop. For more information take a look at {{: https://nodejs.org/api/timers.html#timers_timeout_unref } timers#timers_timeout_unref } from the NodeJS docs.
  ")
  let make: (
    [#CronString(string) | #JsDate(Js.Date.t)],
    (unit => unit) => unit,
    ~onComplete: unit => unit=?,
    ~start: bool=?,
    ~timezone: string=?,
    ~context: {..}=?,
    ~runOnInit: bool=?,
    ~utcOffset: int=?,
    ~unrefTimeout: bool=?,
    unit,
  ) => t
}

@ocaml.doc(" Module for creating cron times that can be used to alter a cron job ")
module CronTime: {
  type t

  @ocaml.doc(" [make(cronTime, timezone, utcOffset)] will create a new [CronTime]. This can be used with {!val:setTime} to change when a [CronJob] is fired.

  Do not use [timezone] and [utcOffset] together.

  @param cronTime The syntax of [cronTime] can be in cron format (e.g. [2 * * * * * *]) or as a {!type:Js.Date.t}.
  @param timezone Which timezone should be used (e.g. [\"America/Los_Angeles\"]).
  @param utcOffset Set an UTC offset. This is for a Moment-object, so see {{: https://momentjs.com/docs/#/manipulating/utc-offset/} Moment-documentation} for more info.
   ")
  let make: (
    [#CronString(string) | #JsDate(Js.Date.t)],
    ~timezone: string=?,
    ~utcOffset: int=?,
    unit,
  ) => t
}

@ocaml.doc(
  " [sendAt(cronTime)] check for a given [cronTime] (either created with the cron format (e.g. [2 * * * * * *]) or as a {!type:Js.Date.t}) when it will fire next.  "
)
@module("cron")
@val
external sendAt: @unwrap [#CronString(string) | #JsDate(Js.Date.t)] => MomentRe.Moment.t = "sendAt"

@ocaml.doc(
  " [timeout(cronTime)] returns the number of milliseconds in the future at which to fire the next [onTick] (and eventually other callbacks added with {!val:addCallback}). "
)
@module("cron")
@val
external timeout: @unwrap [#CronString(string) | #JsDate(Js.Date.t)] => float = "timeout"

@ocaml.doc(" [start(cronJob)] runs your job ") @send
external start: CronJob.t => unit = "start"

@ocaml.doc(" [stop(cronJob)] stops your job ") @send
external stop: CronJob.t => unit = "stop"

@ocaml.doc(
  " [setTime(cronJob, cronTime)] changes the time of your job. The job will be stopped if it is running (and hence must be started again to be running). "
)
@send
external setTime: (CronJob.t, CronTime.t) => unit = "setTime"

@ocaml.doc(" [lastDate(cronJob)] returns the last date the job was executed ") @send
external lastDate: CronJob.t => Js.Date.t = "lastDate"

@ocaml.doc(
  " [nextMomentDates(n, cronJob)] returns the [n] next {!type:Moment.t} that will trigger an [onTick]  "
)
let nextMomentDates: (~numberOfDates: int=?, CronJob.t) => array<MomentRe.Moment.t>

@ocaml.doc(
  " [nextJsDates(n, cronJob)] returns the [n] next {!type:Js.Date.t} that will trigger an [onTick]  "
)
let nextJsDates: (~numberOfDates: int=?, CronJob.t) => array<Js.Date.t>

@ocaml.doc(
  " [fireOnTick(cronJob)] will fire the [onTick] and all callbacks added with {!val:addCallback} "
)
@send
external fireOnTick: CronJob.t => unit = "fireOnTick"

@ocaml.doc(
  " [addCallback(cronJob)] will add a callback that is fired on every tick. It is possible to add multiple callbacks. "
)
@send
external addCallback: (CronJob.t, (unit => unit) => unit) => unit = "addCallback"
