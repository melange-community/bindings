(** Provides a shim to the Javascript number pluralization internationalization APIs.

For a pretty good introduction to the [Intl.PluralRules] API, see {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/PluralRules} https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/PluralRules}

Note that nodejs does {b not} come with the necessary internationalization files by default.  If this library isn't working for you in a nodejs context, that's likely the reason.  You'll need to roll your own node, or use something like {{:https://github.com/unicode-org/full-icu-npm} https://github.com/unicode-org/full-icu-npm} *)

(** The {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/PluralRules} [Intl.PluralRules]} type. *)
type t

type localeMatcher = Lookup | BestFit
type type_ = Cardinal | Ordinal

(** Create a new [Intl.PluralRules] object with the specified options.

 See here for a description of how the arguments are processed and used: {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/PluralRules} https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/PluralRules}

 OCaml:

 {[
  let formatter = Intl.PluralRules.make ~locales:[|"fr"|] ~type_:Ordinal () in
  let asStr = Intl.PluralRules.select formatter 4.0 in
  Js.Console.log asStr
 ]}

 Reason:

 {[
  let formatter = Intl.PluralRules.make(~locales=[|"fr"|], ~type_=Ordinal, ());
  let asStr = Intl.PluralRules.select(formatter, 4.0);
  Js.Console.log(asStr);
 ]}
 *)
val make: locales:string array -> ?localeMatcher:localeMatcher -> ?type_:type_ -> unit -> t

(** Calls {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/PluralRules/select} [Intl.PluralRules.prototype.select]}.

 OCaml:

 {[
  let formatter = Intl.PluralRules.make ~locales:[|"fr"|] ~type_:Ordinal () in
  let asStr = Intl.PluralRules.select formatter 4.0 in
  Js.Console.log asStr
 ]}

 Reason:
 
 {[
  let formatter = Intl.PluralRules.make(~locales=[|"fr"|], ~type_=Ordinal, ());
  let asStr = Intl.PluralRules.select(formatter, 4.0);
  Js.Console.log(asStr);
 ]}
 *)
val select: t -> float -> string

(** Calls {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/PluralRules/supportedLocalesOf} [Intl.PluralRules.supportedLocalesOf]}.

 OCaml:

 {[
  let supported = Intl.PluralRules.supportedLocalesOf [|"en-GB"; "ridiculous"|] () in
  Js.Console.log (string_of_int (Belt.Array.length supported))
 ]}

 Reason:

 {[
  let supported = Intl.PluralRules.supportedLocalesOf([|"en-GB", "ridiculous"|], ());
  Js.Console.log(string_of_int(Belt.Array.length(supported)));
 ]}
 *)
val supportedLocalesOf: string array -> ?localeMatcher:localeMatcher -> unit -> string array