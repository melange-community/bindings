(** Provides a shim to the Javascript number internationalization APIs.

For a pretty good introduction to the [Intl.NumberFormat] API, see {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/NumberFormat} https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/NumberFormat}

Note that nodejs does {b not} come with the necessary internationalization files by default.  If this library isn't working for you in a nodejs context, that's likely the reason.  You'll need to roll your own node, or use something like {{:https://github.com/unicode-org/full-icu-npm} https://github.com/unicode-org/full-icu-npm} *)

(** The {{:https://www.ecma-international.org/ecma-402/1.0/#sec-11} [Intl.NumberFormat]} type. *)
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

(** Create a new [Intl.NumberFormat] object with the specified options.

 See here for a description of how the arguments are processed and used: {{:https://www.ecma-international.org/ecma-402/1.0/#sec-11.1.3.1} https://www.ecma-international.org/ecma-402/1.0/#sec-11.1.3.1}

 We don't try to match the JS arguments exactly, because OCaml's type system offers some additional safety here.

 In particular, since the spec says that if the style option == "currency", then the currency option must be set with an ISO currency code.  We use the type system to enforce that a valid program must have an ISO code if it represents a currency.

 A similar approach works for the minimumSignificantDigits, minimumIntegerDigits, etc.  Since only one set of bounds may be used, the type system forces you to pick.

 OCaml:

 {[
  let formatter = Intl.NumberFormat.make
    ~locales:[|"fr"|]
    ~style:Percent
    ~digits:(Insignificant { integer = None; fraction = Some { maximum = Some 3; minimum = Some 3 } })
    () in
  let pctStr = Intl.NumberFormat.format formatter 0.984322 in
  Js.Console.log pctStr
 ]}

 Reason:

 {[
  let formatter = Intl.NumberFormat.make(
    ~locales=[|"fr"|],
    ~style=Percent,
    ~digits=Insignificant({integer: None, fraction: Some({maximum: Some(3), minimum: Some(3)})}),
    ());
  let pctStr = Intl.NumberFormat.format(formatter, 0.984322);
  Js.Console.log(pctStr);
 ]}
 *)
val make: locales:string array -> ?localeMatcher:localeMatcher -> ?style:style -> ?useGrouping:bool -> ?digits:digits -> unit -> t

(** Calls {{:https://www.ecma-international.org/ecma-402/1.0/#sec-11.3.2} [Intl.NumberFormat.prototype.format]}.

 OCaml:

 {[
  let formatter = Intl.NumberFormat.make
    ~locales:[|"es-ES"|]
    ~style:(Currency { isoCode = "EUR"; display = Some Symbol })
    ~digits:(Significant { maximum = Some 2; minimum = Some 2 })
    () in
  let moneyStr = Intl.NumberFormat.format formatter 56456.897 in
  Js.Console.log moneyStr
 ]}

 Reason:
 
 {[
  let formatter = Intl.NumberFormat.make(
    ~locales=[|"es-ES"|],
    ~style=Currency({isoCode: "EUR", display: Some(Symbol)}),
    ~digits=Significant({maximum: Some(2), minimum: Some(2)}),
    ());
  let moneyStr = Intl.NumberFormat.format(formatter, 56456.897);
  Js.Console.log(moneyStr);
 ]}
 *)
val format: t -> float -> string

type rawPart = {
  type_: string [@bs.as "type"];
  value: string;
} [@@bs.deriving abstract]

type partType = Currency | Decimal | Fraction | Group | Infinity | Integer | Literal | MinusSign | NaN | PlusSign | PercentSign

type part = {
  type_: partType;
  value: string;
}

exception InvalidPart of rawPart

(** Calls {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/NumberFormat/formatToParts} [Intl.NumberFormat.prototype.formatToParts]}.

 @raise [InvalidPart] if a part type doesn't match the possible types outlined in MDN.

 OCaml:

 {[
  let formatter = Intl.NumberFormat.make
    ~locales:[|"es-ES"|]
    ~style:(Currency { isoCode = "EUR"; display = Some Symbol })
    ~digits:(Significant { maximum = Some 2; minimum = Some 2 })
    () in
  let parts = Intl.NumberFormat.formatToParts formatter 2000000.0 in
  match parts with
  | [||] -> ()
  | { value = value; _ } :: _ -> Js.Console.log value
 ]}

 Reason:

 {[
  let formatter = Intl.NumberFormat.make(
    ~locales=[|"es-ES"|],
    ~style=Currency({isoCode: "EUR", display: Some(Symbol)}),
    ~digits=Significant({maximum: Some(2), minimum: Some(2)}),
    ());
  let parts = Intl.NumberFormat.formatToParts(formatter, 2000000.0);
  switch (parts) {
  | [||] => ()
  | [|{value: value}, ..._|] => Js.Console.log(value)
  }
 ]}
 *)
val formatToParts: t -> float -> part array

(** Calls {{:https://www.ecma-international.org/ecma-402/1.0/#sec-11.2.2} [Intl.NumberFormat.supportedLocalesOf]}.

 OCaml:

 {[
  let supported = Intl.NumberFormat.supportedLocalesOf [|"en-GB"; "ridiculous"|] () in
  Js.Console.log (string_of_int (Belt.Array.length supported))
 ]}

 Reason:

 {[
  let supported = Intl.NumberFormat.supportedLocalesOf([|"en-GB", "ridiculous"|], ());
  Js.Console.log(string_of_int(Belt.Array.length(supported)));
 ]}
 *)
val supportedLocalesOf: string array -> ?localeMatcher:localeMatcher -> unit -> string array