(** Bindings to the [Intl] object, containing internationalization functions for Javascript.

 Note that nodejs does {b not} come with the necessary internationalization files by default.  If this library isn't working for you in a nodejs context, that's likely the reason.  You'll need to roll your own node, or use something like {{:https://github.com/unicode-org/full-icu-npm} https://github.com/unicode-org/full-icu-npm}
 *)

(** Handles functions related to the {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/DateTimeFormat} [Intl.DateTimeFormat]} object.
 *)
module DateTimeFormat = Intl_DateTimeFormat

(** Handles functions related to the {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/NumberFormat} [Intl.NumberFormat]} object.
 *)
module NumberFormat = Intl_NumberFormat

(** Handles functions related to the {{:https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/PluralRules} [Intl.PluralRules]} object.
 *)
module PluralRules = Intl_PluralRules