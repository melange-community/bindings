type t<'store>
type computedFunction

@module("hyperactiv")
external observe: 'a => t<'a> = "observe"
@module("hyperactiv")
external observeWithOptions: ('a, ~options: {..}) => t<'a> = "observe"

@module("hyperactiv")
external computed: (unit => unit) => computedFunction = "computed"
@module("hyperactiv")
external computedWithOptions: (unit => unit, ~options: {..}) => computedFunction = "computed"

@module("hyperactiv")
external dispose: computedFunction => unit = "dispose"

module React = {
  @module("hyperactiv/react")
  external makeStore: 'a => t<'a> = "store"
  @module("hyperactiv/react")
  external watch: React.component<'props> => React.component<'props> = "watch"
}

external unwrap: t<'a> => 'a = "%identity"

module Handlers = {
  type handler

  external make: ((. array<string>, 'value, 'oldValue, 'a) => unit) => handler = "%identity"

  @set external set: (t<'a>, handler) => unit = "__handler"

  @module("hyperactiv/handlers")
  external writer: 'target => handler = "write"
  @module("hyperactiv/handlers")
  external debugger: 'logger => handler = "debug"
  @module("hyperactiv/handlers")
  external compose: array<handler> => handler = "all"
}

module Classes = {
  type t<'store>

  @module("hyperactiv/classes") @new external make: 'a => t<'a> = "Observable"
  @module("hyperactiv/classes") @new
  external makeWithOptions: ('a, ~options: {..}) => t<'a> = "Observable"

  external unwrap: t<'a> => 'a = "%identity"
  @send external computed: (t<'a>, @this ('a => unit)) => unit = "computed"
  @send
  external computedWithOptions: (t<'a>, @this (('a => unit) => unit), ~options: {..}) => unit =
    "computed"
  @send external dispose: t<'a> => unit = "dispose"
  @send external onChange: (t<'a>, Handlers.handler) => unit = "onChange"
}
