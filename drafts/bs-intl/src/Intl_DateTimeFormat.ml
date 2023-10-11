open Belt.Option

type t

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

exception InvalidWeekday of string
exception InvalidEra of string
exception InvalidYear of string
exception InvalidMonth of string
exception InvalidDay of string
exception InvalidHour of string
exception InvalidMinute of string
exception InvalidSecond of string
exception InvalidTimeZoneName of string

let weekdayFromString s: weekday =
  match s with
  | "narrow" -> Narrow
  | "short" -> Short
  | "long" -> Long
  | _ -> raise (InvalidEra s)

let eraFromString s: era =
  match s with
  | "narrow" -> Narrow
  | "short" -> Short
  | "long" -> Long
  | _ -> raise (InvalidEra s)

let yearFromString s: year =
  match s with
  | "2-digit" -> TwoDigit
  | "numeric" -> Numeric
  | _ -> raise (InvalidYear s)

let monthFromString s: month =
  match s with
  | "2-digit" -> TwoDigit
  | "numeric" -> Numeric
  | "narrow" -> Narrow
  | "short" -> Short
  | "long" -> Long
  | _ -> raise (InvalidMonth s)

let dayFromString s: day =
  match s with
  | "2-digit" -> TwoDigit
  | "numeric" -> Numeric
  | _ -> raise (InvalidDay s)

let hourFromString s: hour =
  match s with
  | "2-digit" -> TwoDigit
  | "numeric" -> Numeric
  | _ -> raise (InvalidHour s)

let minuteFromString s: minute =
  match s with
  | "2-digit" -> TwoDigit
  | "numeric" -> Numeric
  | _ -> raise (InvalidMinute s)

let secondFromString s: second =
  match s with
  | "2-digit" -> TwoDigit
  | "numeric" -> Numeric
  | _ -> raise (InvalidSecond s)

let timeZoneNameFromString s: timeZoneName =
  match s with
  | "short" -> Short
  | "long" -> Long
  | _ -> raise (InvalidTimeZoneName s)

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

external rawResolvedOptions: t -> rawResolvedOptionsResp = "resolvedOptions" [@@bs.send]

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

let resolvedOptions self =
  let rawResp = rawResolvedOptions(self) in
  {
    locale = localeGet rawResp;
    calendar = calendarGet rawResp;
    numberingSystem = numberingSystemGet rawResp;
    timeZone = flatMap (timeZoneGet rawResp) Js.Nullable.toOption;
    hour12 = hour12Get rawResp;
    weekday = map (weekdayGet rawResp) weekdayFromString;
    era = map (eraGet rawResp) eraFromString;
    year = map (yearGet rawResp) yearFromString;
    month = map (monthGet rawResp) monthFromString;
    day = map (dayGet rawResp) dayFromString;
    hour = map (hourGet rawResp) hourFromString;
    minute = map (minuteGet rawResp) minuteFromString;
    second = map (secondGet rawResp) secondFromString;
    timeZoneName = map (timeZoneNameGet rawResp) timeZoneNameFromString;
  }

external format: t -> Js.Date.t -> string = "format" [@@bs.send]

type rawPart = {
  type_: string [@bs.as "type"];
  value: string;
} [@@bs.deriving abstract]

external formatToParts_: t -> Js.Date.t -> rawPart array = "formatToParts" [@@bs.send]

type partType = Day | DayPeriod | Era | Hour | Literal | Minute | Month | Second | TimeZoneName | Weekday | Year

type part = {
  type_: partType;
  value: string;
}

exception InvalidPart of rawPart

let formatToParts self date =
  Belt.Array.map (formatToParts_ self date) (fun rp ->
    let type_ = match (type_Get rp) with
    | "day" -> Day
    | "dayPeriod" -> DayPeriod
    | "era" -> Era
    | "hour" -> Hour
    | "literal" -> Literal
    | "minute" -> Minute
    | "month" -> Month
    | "second" -> Second
    | "timeZoneName" -> TimeZoneName
    | "weekday" -> Weekday
    | "year" -> Year
    | _ -> raise (InvalidPart rp) in
    {
      type_ = type_;
      value = (valueGet rp);
    })

type supportedLocalesOfOptions = {
  mutable localeMatcher: string [@bs.optional];
} [@@bs.deriving abstract]

external supportedLocalesOf_: string array -> supportedLocalesOfOptions -> string array = "supportedLocalesOf" [@@bs.val][@@bs.scope "Intl.DateTimeFormat"]

let supportedLocalesOf locales ?localeMatcher () =
  let opts = supportedLocalesOfOptions () in
  let localeMatcher' = map localeMatcher (fun (lm: localeMatcher) -> match lm with
  | Lookup -> "lookup"
  | BestFit -> "best fit") in
    if isSome localeMatcher' then localeMatcherSet opts (getExn localeMatcher');
    supportedLocalesOf_ locales opts

type newDateTimeFormatOptions = {
  mutable day_: string [@bs.optional][@bs.as "day"];
  mutable era_: string [@bs.optional][@bs.as "era"];
  mutable formatMatcher: string [@bs.optional];
  mutable hour_: string [@bs.optional][@bs.as "hour"];
  mutable hour12_: bool [@bs.optional][@bs.as "hour12"];
  mutable hourCycle: string [@bs.optional];
  mutable localeMatcher: string [@bs.optional];
  mutable minute_: string [@bs.optional][@bs.as "minute"];
  mutable month_: string [@bs.optional][@bs.as "month"];
  mutable second_: string [@bs.optional][@bs.as "second"];
  mutable timeZone_: string [@bs.optional][@bs.as "timeZone"];
  mutable timeZoneName_: string [@bs.optional][@bs.as "timeZoneName"];
  mutable weekday_: string [@bs.optional][@bs.as "weekday"];
  mutable year_: string [@bs.optional][@bs.as "year"];
} [@@bs.deriving abstract]

external newJSDateTimeFormat: string array -> newDateTimeFormatOptions -> t = "DateTimeFormat" [@@bs.new][@@bs.scope "Intl"]

let make ~locales ?day ?era ?formatMatcher ?hour ?hour12 ?hourCycle ?localeMatcher ?minute ?month ?second ?timeZone ?timeZoneName ?weekday ?year () =
  let day' = map day (fun (d: day) -> match d with
  | Numeric -> "numeric"
  | TwoDigit -> "2-digit") in
  let era' = map era (fun (e: era) -> match e with
  | Long -> "long"
  | Short -> "short"
  | Narrow -> "narrow") in
  let formatMatcher' = map formatMatcher (fun (fm: formatMatcher) -> match fm with
  | Basic -> "basic"
  | BestFit -> "best fit") in
  let hour' = map hour (fun (h: hour) -> match h with
  | Numeric -> "numeric"
  | TwoDigit -> "2-digit") in
  let hourCycle' = map hourCycle (fun (hc: hourCycle) -> match hc with
  | H11 -> "h11"
  | H12 -> "h12"
  | H23 -> "h23"
  | H24 -> "h24") in
  let localeMatcher' = map localeMatcher (fun (lm: localeMatcher) -> match lm with
  | Lookup -> "lookup"
  | BestFit -> "best fit") in
  let minute' = map minute (fun (m: minute) -> match m with
  | Numeric -> "numeric"
  | TwoDigit -> "2-digit") in
  let month' = map month (fun (m: month) -> match m with
  | Numeric -> "numeric"
  | TwoDigit -> "2-digit"
  | Long -> "long"
  | Short -> "short"
  | Narrow -> "narrow") in
  let second' = map second (fun (s: second) -> match s with
  | Numeric -> "numeric"
  | TwoDigit -> "2-digit") in
  let timeZoneName' = map timeZoneName (fun (tzn: timeZoneName) -> match tzn with
  | Long -> "long"
  | Short -> "short") in
  let weekday' = map weekday (fun (w: weekday) -> match w with
  | Long -> "long"
  | Short -> "short"
  | Narrow -> "narrow") in
  let year' = map year (fun (y: year) -> match y with
  | Numeric -> "numeric"
  | TwoDigit -> "2-digit") in
  let opts = newDateTimeFormatOptions () in
    if isSome day' then day_Set opts (getExn day');
    if isSome era' then era_Set opts (getExn era');
    if isSome formatMatcher' then formatMatcherSet opts (getExn formatMatcher');
    if isSome hour' then hour_Set opts (getExn hour');
    if isSome hour12 then hour12_Set opts (getExn hour12);
    if isSome hourCycle' then hourCycleSet opts (getExn hourCycle');
    if isSome localeMatcher' then localeMatcherSet opts (getExn localeMatcher');
    if isSome minute' then minute_Set opts (getExn minute');
    if isSome month' then month_Set opts (getExn month');
    if isSome second' then second_Set opts (getExn second');
    if isSome timeZone then timeZone_Set opts (getExn timeZone);
    if isSome timeZoneName' then timeZoneName_Set opts (getExn timeZoneName');
    if isSome weekday' then weekday_Set opts (getExn weekday');
    if isSome year' then year_Set opts (getExn year');
    newJSDateTimeFormat locales opts