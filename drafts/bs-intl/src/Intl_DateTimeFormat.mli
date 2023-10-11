(** Provides a shim to the Javascript datetime internationalization APIs.

For a pretty good introduction to the Intl.DateTimeFormat API, see {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/DateTimeFormat} https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/DateTimeFormat}

Note that nodejs does {b not} come with the necessary internationalization files by default.  If this library isn't working for you in a nodejs context, that's likely the reason.  You'll need to roll your own node, or use something like {{:https://github.com/unicode-org/full-icu-npm} https://github.com/unicode-org/full-icu-npm} *)

(** The {{:https://www.ecma-international.org/ecma-402/1.0/#sec-12} [Intl.DateTimeFormat]} type. *)
type t

(** @see <https://www.ecma-international.org/ecma-402/1.0/#table-3> See this table for an overview of what strings these types match with.
 *)

type day = Numeric | TwoDigit
type era = Long | Short | Narrow
type formatMatcher = Basic | BestFit
type hour = Numeric | TwoDigit
type hourCycle = H11 | H12 | H23 | H24
type localeMatcher = Lookup | BestFit
type minute = Numeric | TwoDigit
type month = Numeric | TwoDigit | Long | Short | Narrow
type second = Numeric | TwoDigit
type timeZoneName = Long | Short
type weekday = Long | Short | Narrow
type year = Numeric | TwoDigit

(** Create a new [Intl.DateTimeFormat] object with the specified options.
 
 See here for a description of how the arguments are processed and used: {{:https://www.ecma-international.org/ecma-402/1.0/#sec-12.1.3.1} https://www.ecma-international.org/ecma-402/1.0/#sec-12.1.3.1}

 OCaml:

 {[
  let formatter = Intl.DateTimeFormat.make ~locales:[|"en-GB"|] ~month:TwoDigit () in
  let dateStr = Intl.DateTimeFormat.format formatter (Js.Date.makeWithYMD ~year:2019.0 ~month:6.0 ~date:22.0 ()) in
  Js.Console.log dateStr
 ]}

 Reason:

 {[
  let formatter = Intl.DateTimeFormat.make(~locales=[|"en-GB"|], ~month=TwoDigit, ());
  let dateStr = Intl.DateTimeFormat.format(formatter, Js.Date.makeWithYMD(~year=2019.0, ~month=6.0, ~date=22.0, ()));
  Js.Console.log(dateStr);
 ]}
 *)
val make: locales:string array -> ?day:day -> ?era:era -> ?formatMatcher:formatMatcher -> ?hour:hour -> ?hour12:bool -> ?hourCycle:hourCycle -> ?localeMatcher:localeMatcher -> ?minute:minute -> ?month:month -> ?second:second -> ?timeZone:string -> ?timeZoneName:timeZoneName -> ?weekday:weekday -> ?year:year -> unit -> t

(** A type representing the un-ocaml-ified response from [Intl.DateTimeFormat.prototype.resolvedOptions].

 Only use if you have reason to believe that your JS environment is returning results from that method that don't conform to the spec here: {{:https://www.ecma-international.org/ecma-402/1.0/#sec-12.3.3} https://www.ecma-international.org/ecma-402/1.0/#sec-12.3.3}
 *)
type rawResolvedOptionsResp = {
  locale: string [@bs.optional];
  calendar: string [@bs.optional];
  numberingSystem: string [@bs.optional];
  timeZone: string Js.Nullable.t [@bs.optional];
  hour12: bool [@bs.optional];
  weekday: string [@bs.optional];
  era: string [@bs.optional];
  year: string [@bs.optional];
  month: string [@bs.optional];
  day: string [@bs.optional];
  hour: string [@bs.optional];
  minute: string [@bs.optional];
  second: string [@bs.optional];
  timeZoneName: string [@bs.optional];
} [@@bs.deriving abstract]

(** Get the un-ocaml-ified response from [Intl.DateTimeFormat.prototype.resolvedOptions].

 Only use if you have reason to believe that your JS environment is returning results from that method that don't conform to the spec here: {{:https://www.ecma-international.org/ecma-402/1.0/#sec-12.3.3} https://www.ecma-international.org/ecma-402/1.0/#sec-12.3.3}

 Otherwise, [resolvedOptions] is preferable.
 *)
val rawResolvedOptions: t -> rawResolvedOptionsResp

exception InvalidWeekday of string
exception InvalidEra of string
exception InvalidYear of string
exception InvalidMonth of string
exception InvalidDay of string
exception InvalidHour of string
exception InvalidMinute of string
exception InvalidSecond of string
exception InvalidTimeZoneName of string

(** A type representing a strongly-typed response from [Intl.DateTimeFormat.prototype.resolvedOptions].

 @see <https://www.ecma-international.org/ecma-402/1.0/#sec-12.3.3> See the response spec here.

 @see <https://www.ecma-international.org/ecma-402/1.0/#table-3> The table of valid options is also helpful.
 *)
type resolvedOptionsResp = {
  locale: string option;
  calendar: string option;
  numberingSystem: string option;
  timeZone: string option;
  hour12: bool option;
  weekday: weekday option;
  era: era option;
  year: year option;
  month: month option;
  day: day option;
  hour: hour option;
  minute: minute option;
  second: second option;
  timeZoneName: timeZoneName option;
}

(** Calls {{:https://www.ecma-international.org/ecma-402/1.0/#sec-12.3.3} [Intl.DateTimeFormat.prototype.resolvedOptions]}.
 
 Output is not stringly-typed, like the original.

 @raise [InvalidWeekday] if the returned weekday doesn't match a value in the spec
 @raise [InvalidEra] if the returned era doesn't match a value in the spec
 @raise [InvalidYear] if the returned year doesn't match a value in the spec
 @raise [InvalidMonth] if the returned month doesn't match a value in the spec
 @raise [InvalidDay] if the returned day doesn't match a value in the spec
 @raise [InvalidHour] if the returned hour doesn't match a value in the spec
 @raise [InvalidMinute] if the returned minute doesn't match a value in the spec
 @raise [InvalidSecond] if the returned second doesn't match a value in the spec
 @raise [InvalidTimeZoneName] if the returned time zone name doesn't match a value in the spec

 OCaml:

 {[
  let formatter = Intl.DateTimeFormat.make ~locales:[|"en-GB"|] ~month:TwoDigit () in
  match Intl.DateTimeFormat.resolvedOptions formatter with
  | { category = category; _ } -> Js.Console.log category
 ]}

 Reason:

 {[
  let formatter = Intl.DateTimeFormat.make(~locales=[|"en-GB"|], ~month=TwoDigit, ());
  switch (Intl.DateTimeFormat.resolvedOptions(formatter)) {
  | {category: category} => Js.Console.log(category)
  }
 ]}
 *)
val resolvedOptions: t -> resolvedOptionsResp

(** Calls {{:https://www.ecma-international.org/ecma-402/1.0/#sec-12.3.2} [Intl.DateTimeFormat.prototype.format]}.

 OCaml:

 {[
  let formatter = Intl.DateTimeFormat.make ~locales:[|"en-GB"|] ~month:TwoDigit () in
  let dateStr = Intl.DateTimeFormat.format formatter (Js.Date.makeWithYMD ~year:2019.0 ~month:6.0 ~date:22.0 ()) in
  Js.Console.log dateStr
 ]}

 Reason:

 {[
  let formatter = Intl.DateTimeFormat.make(~locales=[|"en-GB"|], ~month=TwoDigit, ());
  let dateStr = Intl.DateTimeFormat.format(formatter, Js.Date.makeWithYMD(~year=2019.0, ~month=6.0, ~date=22.0, ()));
  Js.Console.log(dateStr);
 ]}
 *)
val format: t -> Js.Date.t -> string

type rawPart = {
  type_: string [@bs.as "type"];
  value: string;
} [@@bs.deriving abstract]

type partType = Day | DayPeriod | Era | Hour | Literal | Minute | Month | Second | TimeZoneName | Weekday | Year

type part = {
  type_: partType;
  value: string;
}

exception InvalidPart of rawPart

(** Calls {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/DateTimeFormat/formatToParts} [Intl.DateTimeFormat.prototype.formatToParts]}.

 @raise [InvalidPart] if a part type doesn't match the possible types outlined in MDN.

 OCaml:

 {[
  let formatter = Intl.DateTimeFormat.make ~locales:[|"zh-CN"|] ~era:Long ~year:Numeric () in
  let parts = Intl.DateTimeFormat.formatToParts formatter (Js.Date.makeWithYMD ~year:2019.0 ~month:6.0 ~date:22.0 ()) in
  match parts with
  | [||] -> ()
  | { value = value; _ } :: _ -> Js.Console.log value
 ]}

 Reason:

 {[
  let formatter = Intl.DateTimeFormat.make(~locales=[|"zh-CN"|], ~era=Long, ~year=Numeric, ());
  let parts = Intl.DateTimeFormat.formatToParts(formatter, Js.Date.makeWithYMD(~year=2019.0, ~month=6.0, ~date=22.0, ()));
  switch (parts) {
  | [||] => ()
  | [|{value: value}, ..._|] => Js.Console.log(value)
  };
 ]}
 *)
val formatToParts: t -> Js.Date.t -> part array

(** Calls {{:https://www.ecma-international.org/ecma-402/1.0/#sec-12.2.2} [Intl.DateTimeFormat.supportedLocalesOf]}.

 OCaml:

 {[
  let supported = Intl.DateTimeFormat.supportedLocalesOf [|"en-GB"; "ridiculous"|] () in
  Js.Console.log (string_of_int (Belt.Array.length supported))
 ]}

 Reason:

 {[
  let supported = Intl.DateTimeFormat.supportedLocalesOf([|"en-GB", "ridiculous"|], ());
  Js.Console.log(string_of_int(Belt.Array.length(supported)));
 ]}
 *)
val supportedLocalesOf: string array -> ?localeMatcher:localeMatcher -> unit -> string array