type t

@module("phoenix")
@new external make: (unit => unit, ~timerCalc: int => int) => t = "Timer";

@send external scheduleTimeout: t => string = "scheduleTimeout";
@send external reset: t => string = "reset";