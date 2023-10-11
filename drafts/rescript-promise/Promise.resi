type t<+'a> = Js.Promise.t<'a>

let resolve: 'a => t<'a>

let makeJsError: string => Js.Exn.t

let reject: Js.Exn.t => t<'a>

let race: array<t<'a>> => t<'a>

let all: array<t<'a>> => t<array<'a>>
let all2: ((t<'a>, t<'b>)) => t<('a, 'b)>
let all3: ((t<'a>, t<'b>, t<'c>)) => t<('a, 'b, 'c)>
let all4: ((t<'a>, t<'b>, t<'c>, t<'d>)) => t<('a, 'b, 'c, 'd)>
let all5: ((t<'a>, t<'b>, t<'c>, t<'d>, t<'e>)) => t<('a, 'b, 'c, 'd, 'e)>
let all6: ((t<'a>, t<'b>, t<'c>, t<'d>, t<'e>, t<'f>)) => t<('a, 'b, 'c, 'd, 'e, 'f)>

@ocaml.doc(
  "The reject callback is not provided by design.\nResolve with a `result`'s `Error` instead or use `Js.Promise.make`"
)
let make: (('a => unit) => unit) => t<'a>

let catch: (t<'a>, exn => 'b) => t<result<'a, 'b>>

let chain: (t<'a>, 'a => t<'b>) => t<'b>
let map: (t<'a>, 'a => 'b) => t<'b>

@ocaml.doc(
  "Will crash the node process if the promise is rejected or if the callback throws an error.\nMake sure to catch the errors if that is undesirable, or use `chain` instead."
)
let done: (t<'a>, 'a => unit) => unit

let chainOk: (t<result<'a, 'b>>, 'a => t<result<'c, 'b>>) => t<result<'c, 'b>>
let mapOk: (t<result<'a, 'b>>, 'a => result<'c, 'b>) => t<result<'c, 'b>>

let sequence: array<unit => t<'a>> => t<array<'a>>
