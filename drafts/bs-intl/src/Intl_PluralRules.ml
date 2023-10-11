open Belt.Option

type t

type localeMatcher = Lookup | BestFit
type type_ = Cardinal | Ordinal

external select: t -> float -> string = "select" [@@bs.send]

type supportedLocalesOfOptions = {
  mutable localeMatcher: string [@bs.optional];
} [@@bs.deriving abstract]

external supportedLocalesOf_: string array -> supportedLocalesOfOptions -> string array = "supportedLocalesOf" [@@bs.val][@@bs.scope "Intl.PluralRules"]

let supportedLocalesOf locales ?localeMatcher () =
  let opts = supportedLocalesOfOptions () in
  let localeMatcher' = map localeMatcher (fun (lm: localeMatcher) -> match lm with
  | Lookup -> "lookup"
  | BestFit -> "best fit") in
    if isSome localeMatcher' then localeMatcherSet opts (getExn localeMatcher');
    supportedLocalesOf_ locales opts

type newPluralRulesOptions = {
  mutable localeMatcher: string [@bs.optional];
  mutable type_: string [@bs.optional];
} [@@bs.deriving abstract]

external newJSPluralRules: string array -> newPluralRulesOptions -> t = "PluralRules" [@@bs.new][@@bs.scope "Intl"]

let make ~locales ?localeMatcher ?type_ () =
  let localeMatcher' = map localeMatcher (fun lm -> match lm with
  | Lookup -> "lookup"
  | BestFit -> "best fit") in
  let type_' = map type_ (fun t -> match t with
  | Cardinal -> "cardinal"
  | Ordinal -> "ordinal") in
  let opts = newPluralRulesOptions () in
    if isSome localeMatcher' then localeMatcherSet opts (getExn localeMatcher');
    if isSome type_' then type_Set opts (getExn type_');
    newJSPluralRules locales opts