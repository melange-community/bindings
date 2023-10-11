open Belt.Option

type t

type localeMatcher = Lookup | BestFit
type currencyDisplay = Symbol | Code | Name
type currency = {
  isoCode: string;
  display: currencyDisplay option;
}
type style = Decimal | Percent | Currency of currency
type significantDigits = {
  minimum: int option;
  maximum: int option;
}
type fractionDigits = {
  minimum: int option;
  maximum: int option;
}
type integerDigits = {
  minimum: int option;
}
type insignificantDigits = {
  integer: integerDigits option;
  fraction: fractionDigits option;
}
type digits = Insignificant of insignificantDigits | Significant of significantDigits

external format: t -> float -> string = "format" [@@bs.send]

type rawPart = {
  type_: string [@bs.as "type"];
  value: string;
} [@@bs.deriving abstract]

external formatToParts_: t -> float -> rawPart array = "formatToParts" [@@bs.send]

type partType = Currency | Decimal | Fraction | Group | Infinity | Integer | Literal | MinusSign | NaN | PlusSign | PercentSign

type part = {
  type_: partType;
  value: string;
}

exception InvalidPart of rawPart

let formatToParts self x =
  Belt.Array.map (formatToParts_ self x) (fun rp ->
    let type_ = match (type_Get rp) with
    | "currency" -> Currency
    | "decimal" -> Decimal
    | "fraction" -> Fraction
    | "group" -> Group
    | "infinity" -> Infinity
    | "integer" -> Integer
    | "literal" -> Literal
    | "minusSign" -> MinusSign
    | "nan" -> NaN
    | "plusSign" -> PlusSign
    | "percentSign" -> PercentSign
    | _ -> raise (InvalidPart rp) in
    {
      type_ = type_;
      value = (valueGet rp);
    })

type supportedLocalesOfOptions = {
  mutable localeMatcher: string [@bs.optional];
} [@@bs.deriving abstract]

external supportedLocalesOf_: string array -> supportedLocalesOfOptions -> string array = "supportedLocalesOf" [@@bs.val][@@bs.scope "Intl.NumberFormat"]

let supportedLocalesOf locales ?localeMatcher () =
  let opts = supportedLocalesOfOptions () in
  let localeMatcher' = map localeMatcher (fun (lm: localeMatcher) -> match lm with
  | Lookup -> "lookup"
  | BestFit -> "best fit") in
    if isSome localeMatcher' then localeMatcherSet opts (getExn localeMatcher');
    supportedLocalesOf_ locales opts

type newNumberFormatOptions = {
  mutable localeMatcher: string [@bs.optional];
  mutable style: string [@bs.optional];
  mutable currency: string [@bs.optional];
  mutable currencyDisplay: string [@bs.optional];
  mutable useGrouping: bool [@bs.optional];
  mutable minimumIntegerDigits: float [@bs.optional];
  mutable minimumFractionDigits: float [@bs.optional];
  mutable maximumFractionDigits: float [@bs.optional];
  mutable minimumSignificantDigits: float [@bs.optional];
  mutable maximumSignificantDigits: float [@bs.optional];
} [@@bs.deriving abstract]

external newJSNumberFormat: string array -> newNumberFormatOptions -> t = "NumberFormat" [@@bs.new][@@bs.scope "Intl"]

let make ~locales ?localeMatcher ?style ?useGrouping ?digits () =
  let localeMatcher' = map localeMatcher (fun lm -> match lm with
  | Lookup -> "lookup"
  | BestFit -> "best fit") in
  let style' = map style (fun (s: style) -> match s with
  | Decimal -> "decimal"
  | Percent -> "percent"
  | Currency _ -> "currency") in
  let currency' = flatMap style (fun (s: style) -> match s with
  | Currency { isoCode = isoCode } -> Some(isoCode)
  | _ -> None) in
  let currencyDisplay' = flatMap style (fun (s: style) -> match s with
  | Currency { display = display } -> map display (fun d -> match d with
    | Symbol -> "symbol"
    | Code -> "code"
    | Name -> "name")
  | _ -> None) in
  let minimumIntegerDigits' = flatMap digits (fun d -> match d with
  | Insignificant(id) -> flatMap id.integer (fun i -> map i.minimum Js.Int.toFloat)
  | _ -> None) in
  let minimumFractionDigits' = flatMap digits (fun d -> match d with
  | Insignificant(id) -> flatMap id.fraction (fun f -> map f.minimum Js.Int.toFloat)
  | _ -> None) in
  let maximumFractionDigits' = flatMap digits (fun d -> match d with
  | Insignificant(id) -> flatMap id.fraction (fun f -> map f.maximum Js.Int.toFloat)
  | _ -> None) in
  let minimumSignificantDigits' = flatMap digits (fun d -> match d with
  | Significant(sd) -> map sd.minimum Js.Int.toFloat
  | _ -> None) in
  let maximumSignificantDigits' = flatMap digits (fun d -> match d with
  | Significant(sd) -> map sd.maximum Js.Int.toFloat
  | _ -> None) in
  let opts = newNumberFormatOptions () in
    if isSome localeMatcher' then localeMatcherSet opts (getExn localeMatcher');
    if isSome style' then styleSet opts (getExn style');
    if isSome currency' then currencySet opts (getExn currency');
    if isSome currencyDisplay' then currencyDisplaySet opts (getExn currencyDisplay');
    if isSome useGrouping then useGroupingSet opts (getExn useGrouping);
    if isSome minimumIntegerDigits' then minimumIntegerDigitsSet opts (getExn minimumIntegerDigits');
    if isSome minimumFractionDigits' then minimumFractionDigitsSet opts (getExn minimumFractionDigits');
    if isSome maximumFractionDigits' then maximumFractionDigitsSet opts (getExn maximumFractionDigits');
    if isSome minimumSignificantDigits' then minimumSignificantDigitsSet opts (getExn minimumSignificantDigits');
    if isSome maximumSignificantDigits' then maximumSignificantDigitsSet opts (getExn maximumSignificantDigits');
    newJSNumberFormat locales opts