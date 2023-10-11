/**
  Copyright (c) 2021 John Jackson

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
@@text("
{b ReScript-Blossom} is a {{: https://rescript-lang.org/} ReScript} implementation of
the famous {{: https://en.wikipedia.org/wiki/Blossom_algorithm} blossom algorithm}.
It finds a maximum matching of vertices on general, undirected, weighted graphs.

{{: https://github.com/johnridesabike/rescript-blossom} Browse the source.}
")

@@text("
{1 Installation}

You can add ReScript-Blossom to your project by running:
{[
  npm install rescript-blossom
]}

You will need to edit your project's [bsconfig.json] file and list
ReScript-Blossom in the [bs-dependencies].

{[
{
  \"bs-dependencies\": [
    \"rescript-blossom\"
  ]
}
]}

You can now access this module as [Blossom.Match].

{1 How it works}

Matching along an undirected, weighted graph is notoriously difficult. The
blossom algorithm does the heavy lifting for us in O(n³) time. Let's look at a
simple example.

Suppose you have a list of chess players, [[Mary, Joseph, Matthew, Mark, Luke,
John, Peter, Andrew, James, Philip]], and you want to pair them to compete in a
tournament round.

Your first step is to list all of your possible pairings.

{[
let graph = list{
  (Mary, Joseph),
  (Mary, Matthew),
  (Joseph, Matthew),
  (Joseph, Mark),
  (Matthew, Luke),
  (Mark, Luke),
  (Mary, Andrew),
  (Luke, Peter),
  (Peter, John),
  (Andrew, Philip),
  (Mark, James)
}
]}

(Typically your list will be much longer, but this is just an illustration.)

Next, you will need to determine the {i weight} of each pairing. This is a
floating-point number that indicates how desirable that pairing is.

{[
let graph = list{
  (Mary, Joseph, 40.),
  (Mary, Matthew, 40.),
  (Joseph, Matthew, 60.),
  (Joseph, Mark, 55.),
  (Matthew, Luke, 55.),
  (Mark, Luke, 50.),
  (Mary, Andrew, 15.),
  (Luke, Peter, 30.),
  (Peter, John, 10.),
  (Andrew, Philip, 10.),
  (Mark, James, 10.)
}
]}

In graph theory, each of the people is a \"vertex,\" and each pair of people is
an \"edge.\" We can visualize it in 2D space.

{%html:<pre>
  Andrew ---10--- Philip                  Peter
    |                                    /     \\
   15                                  30       10
    |                                  /         \\
   Mary ---40--- Matthew ---55---- Luke         John
      \\          /                  /
       40      60                 50
        \\      /                  /
         Joseph ------ 55 ----- Mark ----30---- James
</pre>%}

Note that we couldn't use the edge with the highest weight because choosing it
would leave another vertex with no connections. We also have to use the two
edges with the lowest weights because we're committed to matching as many
vertices as possible.

As you can see, finding the {i maximum} weighted matching is often unintuitive.
Imagine how much more difficult this becomes when you have dozens, or hundreds,
of people, and we could potentially match every person with anyone else!

{1:usage Usage}

Your data can be any type, but suppose you're using [string] vertices.

{[
let graph = list{
  (\"Mary\", \"Joseph\", 40.),
  (\"Mary\", \"Michael\", 40.),
  (\"Joseph\", \"Michael\", 60.),
  (\"Joseph\", \"Gabriel\", 55.),
  (\"Michael\", \"Raphael\", 55.),
  (\"Gabriel\", \"Raphael\", 50.),
  (\"Mary\", \"Paul\", 15.),
  (\"Raphael\", \"Peter\", 30.),
  (\"Peter\", \"John\", 10.),
  (\"Paul\", \"James\", 10.),
  (\"Gabriel\", \"Andrew\", 30.),
}
]}

You can match them with {!String.make}.

{[
let result = Blossom.Match.String.make(graph)
]}

You can also use {!Int.make} for integer vertices.

{2 Using the output}

The algorithm returns a bi-directional map of each vertex to its mate vertex.

{[
Blossom.Match.get(result, \"Mary\") == Some(\"Joseph\")
Blossom.Match.get(result, \"Joseph\") == Some(\"Mary\")
]}

It's powered by [Belt.Map] under the hood. You can convert it to a proper
[Belt.Map] with {!toMap}, or a list with {!toList}. {i The output of these will
have each pairing twice.} This is because it treats each order ([(a, b)] vs
[(b, a)]) separately. In practice, this is useful so you can use [Belt.Map.get]
or [Belt.List.getAssoc] to get any vertex's mate.

{2 Maximum cardinality}

The {!make} functions accepts one optional parameter, [cardinality], which can
be the value [#Max]. This enables \"maximum cardinality\" matching, where the
algorithm will only accept solutions that use as many edges as possible, even
extremely undesirable ones (such as ones with negative weights).

{[
let graph = list{
  (1, 2, 2.),
  (1, 3, (-2.)),
  (2, 3, 1.),
  (2, 4, (-1.)),
  (3, 4, (-6.)),
}

let result = Blossom.Match.Int.make(graph)
/* result: (1, 2) */

let result = Blossom.Match.Int.make(~cardinality=#Max, graph)
/* result: (1, 3), (2, 4) */
]}

{2 Your own types}

To use your own type, first you need a module that conforms to the
{!type:comparable} signature. (If you've used the [Belt.Id] module before, this
should be familiar.)

{[
module MyType: {
  type t
  let cmp: (t, t) => int
} = {
  /* implementation goes here */
}

module MyTypeCmp = Blossom.Match.MakeComparable(MyType)
]}

Now you can call {!make} with the  module and your list of edges.

{[
let result = Blossom.Match.make(~id=module(MyTypeCmp), graph)
]}

You can also reuse an existing Belt [Comparable] module by using
{!unsafeComparableFromBelt}. The use case for that is when you need the
[identity] type shared between modules.

{1 Beta warning}

This algorithm passes all of the tests from similar implementations, but hasn't
seen much real-world use. There may still be failure states that have not been
discovered yet. The specific dangers are [Failure] exceptions, infinite loops,
or missing pairings. These should never happen, but, if they do, please
{{: https://github.com/johnridesabike/rescript-blossom/issues} file an issue} with
information about your graph.

{1 Interface}

{2 Types}
")

module Internal: {
  type cmp<'vertex, 'identity>
  type edgeCmp<'v, 'identity, 'vertexIdentity>
}

module type Comparable = {
  type t
  type identity
  type edgeIdentity
  let cmp: Internal.cmp<t, identity>
  let edgeCmp: Internal.edgeCmp<t, edgeIdentity, identity>
  module BeltCmp: Belt.Id.Comparable with type t = t and type identity = identity
}

@ocaml.doc("
  A module of functions with a unique identity type. It is analogous to the
  type [Belt.Id.comparable]. Create one with the {!val:comparable} function or the
  {!MakeComparable} functor. Or create one with an existing [Belt.Id.comparable]
  module with {!unsafeComparableFromBelt}.
 ")
type comparable<'vertex, 'id> = module(Comparable with type identity = 'id and type t = 'vertex)

@ocaml.doc("
  Represents whether or not the algorithm should {i only} accept
  maximum-cardinality solutions.
 ")
type cardinality = [#Max | #NotMax]

@ocaml.doc("
  A bi-directional, read-only mapping of each vertex to its mate vertex.
 ")
type t<'vertex, 'id>

@@text("{2 Functions}")

@ocaml.doc("
  Computes a maximum-weighted matching on a general undirected weighted graph.
  This function takes time O(n³). See {!section:usage} for examples of its use.

  Accepts a list of tuples [(i, j, w)], each describing an undirected edge
  between vertex [i] and vertex [j] with weight [w]. There is at most one edge
  between any two vertices, and no vertex has an edge to itself. Duplicate
  edges are ignored.

  {!Int.make} and {!String.make} are prepackaged versions of this function for
  [int] and [string] vertices, respectively.

  @param cardinality When set to [#Max], only maximum-cardinality matchings are
  considered as solutions. [#NotMax] is the default.

  @param id A first-class module created by {!val:comparable} or
  {!MakeComparable}.
 ")
let make: (
  ~cardinality: cardinality=?,
  list<('vertex, 'vertex, float)>,
  ~id: comparable<'vertex, 'id>,
) => t<'vertex, 'id>

@ocaml.doc("
  Returns [Some(mate)] for a mated vertex, or [None] if none exists.

  {[Blossom.Match.get(result, \"Mary\") == Some(\"Joseph\")]}
 ")
let get: (t<'vertex, 'id>, 'vertex) => option<'vertex>

@ocaml.doc("
  Reduces over the pairs of vertex mates. Each pair is used twice, once in each
  order.

  {[
    let list =
      Blossom.Match.reduce(
        result,
        ~init=list{},
        ~f=(acc, v1, v2) => list{(v1, v2), ...acc}
      )
  ]}
 ")
let reduce: (t<'vertex, 'id>, ~init: 'acc, ~f: ('acc, 'vertex, 'vertex) => 'acc) => 'acc

@ocaml.doc("
  Reduces over the pairs of vertex mates. Each pair is used twice, once in each
  order.

  Takes an uncurried [f] function.

  {[
  let list =
    Blossom.Match.reduce(
      result, 
      ~init=list{}, 
      ~f=(. acc, v1, v2) => list{(v1, v2), ...acc}
    )
  ]}
 ")
let reduceU: (t<'vertex, 'id>, ~init: 'acc, ~f: (. 'acc, 'vertex, 'vertex) => 'acc) => 'acc

@ocaml.doc("
  Iterates over the pairs of vertex mates. Each pair is used twice, once in
  each order.

  {[Blossom.Match.forEach(result, ~f=(v1, v2) => Js.log2(v1, v2))]}
 ")
let forEach: (t<'vertex, 'id>, ~f: ('vertex, 'vertex) => unit) => unit

@ocaml.doc("
  Iterates over the pairs of vertex mates. Each pair is used twice, once in
  order.

  Takes an uncurried [f] function.


  {[Blossom.Match.forEachU(result, ~f=(. v1, v2) => Js.log2(v1, v2))]}
 ")
let forEachU: (t<'vertex, 'id>, ~f: (. 'vertex, 'vertex) => unit) => unit

@ocaml.doc("
  Returns a [Belt.Map.t] where each key is a vertex and each value is its mate.

  {[
  let map = Blossom.Match.toMap(result)
  Belt.Map.get(map, \"Mary\") == Some(\"Joseph\")
  ]}
 ")
let toMap: t<'vertex, 'id> => Belt.Map.t<'vertex, 'vertex, 'id>

@ocaml.doc("
  Returns a list of tuples for each pair of vertex mates. Each pair is used
  twice, once in each order.

  {[
    Blossom.Match.toList(result) == list{
      (\"Raphael\", \"Michael\"),
      (\"Peter\", \"John\"),
      (\"Paul\", \"James\"),
      (\"Michael\", \"Raphael\"),
      (\"Mary\", \"Joseph\"),
      (\"Joseph\", \"Mary\"),
      (\"John\", \"Peter\"),
      (\"James\", \"Paul\"),
      (\"Gabriel\", \"Andrew\"),
      (\"Andrew\", \"Gabriel\"),
    }
  ]}
 ")
let toList: t<'vertex, 'id> => list<('vertex, 'vertex)>

@ocaml.doc("
  Returns [true] if there are no mates, [false] otherwise.

  {[Blossom.Match.isEmpty(result) == false]}
 ")
let isEmpty: t<'vertex, 'id> => bool

@ocaml.doc("
  Returns [true] if the vertex has a mate, [false] otherwise.

  {[Blossom.Match.has(result, \"Mary\") == true]}
 ")
let has: (t<'vertex, 'id>, 'vertex) => bool

@@text("{2 Prepackaged modules}")

@ocaml.doc("
  Prepackaged module for building graphs with [int] vertices.
 ")
module Int: {
  module Cmp: Comparable with type t = int
  type t = t<int, Cmp.identity>
  let make: (~cardinality: cardinality=?, list<(int, int, float)>) => t
}

@ocaml.doc("
  Prepackaged module for building graphs with [string] vertices.
 ")
module String: {
  module Cmp: Comparable with type t = string
  type t = t<string, Cmp.identity>
  let make: (~cardinality: cardinality=?, list<(string, string, float)>) => t
}

@@text("{2 Creating comparables}")

@ocaml.doc("
  Turns a [Belt.Id.comparable] module into {!type:comparable}.
  
  This is unsafe because the compiler can't guarantee the [cmp] value will be
  correct.

  {[
  module MyTypeCmp = Belt.Id.MakeComparable(MyType)
  let blossomCmp =
    Blossom.Match.unsafeComparableFromBelt(
      ~id=module(MyTypeCmp),
      ~cmp=MyType.cmp
    )
  ]}
 ")
let unsafeComparableFromBelt: (
  ~id: Belt.Id.comparable<'vertex, 'id>,
  ~cmp: ('vertex, 'vertex) => int,
) => comparable<'vertex, 'id>

@ocaml.doc("
  Turns a [Belt.Id.comparable] module into a {!type:comparable} with an
  uncurried [cmp] function.
  
  This is unsafe because the compiler can't guarantee the [cmp] value will be
  correct.
 ")
let unsafeComparableFromBeltU: (
  ~id: Belt.Id.comparable<'vertex, 'id>,
  ~cmp: (. 'vertex, 'vertex) => int,
) => comparable<'vertex, 'id>

@ocaml.doc("
  Creates a {!type:comparable}.
  {[
  module IntCmp = Blossom.Match.MakeComparable({
    type t = int
    let cmp: (t, t) => int = compare
  })
  ]}
 ")
module MakeComparable: (
  M: {
    type t
    let cmp: (t, t) => int
  },
) => (Comparable with type t = M.t)

@ocaml.doc("
  Creates a {!type:comparable} with an uncurried [cmp] function.
 ")
module MakeComparableU: (
  M: {
    type t
    let cmp: (. t, t) => int
  },
) => (Comparable with type t = M.t)

@ocaml.doc("
  Creates a {!type:comparable}.
  {[module IntCmp = unpack(Match.comparable(compare: (int, int) => int))]}
 ")
let comparable: (('vertex, 'vertex) => int) => module(Comparable with type t = 'vertex)

@ocaml.doc("
  Creates a {!type:comparable} with an uncurried [cmp] function.
 ")
let comparableU: ((. 'vertex, 'vertex) => int) => module(Comparable with type t = 'vertex)

@ocaml.doc("
 Turns a {!type:comparable} into a [Belt.Id.comparable].
 ")
let comparableToBelt: comparable<'vertex, 'id> => Belt.Id.comparable<'vertex, 'id>

@@text("

{1 Changelog}

{{: https://github.com/johnridesabike/rescript-blossom/blob/master/CHANGELOG.md} See
the CHANGELOG.md file.}

{1 Similar packages}

{2 JavaScript}

The {{: https://www.npmjs.com/package/edmonds-blossom} edmonds-blossom}
package uses the same algorithm. It should return the exact same pairings that
this version does, but it doesn't have the flexibility of using different
types.

{2 Python}

{{: http://jorisvr.nl/article/maximum-matching} Joris van Rantwijk's Python
implementation} was the basis of both the JavaScript version and this ReScript
version.

{1 Credits}

- {{: https://johnridesa.bike/} John} - idea and initial work.
- {{: http://jorisvr.nl/} Joris van Rantwijk} - his Python code was an
invaluable reference.

I can't take any credit for the algorithm itself. It exists thanks to many
people much smarter than me.

{1 License}

Copyright (c) 2021 John Jackson

This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
")
