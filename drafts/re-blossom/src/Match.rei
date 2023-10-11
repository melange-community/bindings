/*******************************************************************************
  MIT License

  Copyright (c) 2020 John Jackson

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
 ******************************************************************************/
[@text
  {|
{b Re-Blossom} is a {{: https://reasonml.github.io/} Reason} implementation of
the famous {{: https://en.wikipedia.org/wiki/Blossom_algorithm} blossom algorithm}.
It finds a maximum matching of vertices on general, undirected, weighted graphs.

{{: https://github.com/johnridesabike/re-blossom} Browse the source.}
|}
];

[@text
  {|

{1 Notice}

If you're using {{: https://rescript-lang.org} ReScript}, check out {{:
https://github.com/johnridesabike/rescript-blossom} ReScript-Blossom}. It's
the same algorithm, but optimized for a JavaScript environment.

This package originally had similar optimizations, but I've reworked it to be
more compatible with native-Reason. This package currently still relies on
[bs-platform] to compile to JavaScript, but that's only for testing. All of
the core modules should be native-compatible.

I'm not currently using this package in a native environment, so I haven't
fully converted it yet. If you think you will find this useful, I encourage
you to fork it and make the modifications you need.

This algorithm passes all of the tests from similar implementations, but hasn't
seen much real-world use. There may still be failure states that have not been
discovered yet. The specific dangers are [Failure] exceptions, infinite loops,
or missing pairings. These should never happen, but, if they do, please
{{: https://github.com/johnridesabike/re-blossom/issues} file an issue} with
information about your graph.

{1 How it works}

Matching along an undirected, weighted graph is notoriously difficult. The
blossom algorithm does the heavy lifting for us in O(n³) time. Let's look at a
simple example.

Suppose you have a list of chess players, [[Mary, Joseph, Matthew, Mark, Luke,
John, Peter, Andrew, James, Philip]], and you want to pair them to compete in a
tournament round.

Your first step is to list all of your possible pairings.

{[
let graph = [
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
];
]}

(Typically your list will be much longer, but this is just an illustration.)

Next, you will need to determine the {i weight} of each pairing. This is a
floating-point number that indicates how desirable that pairing is.

{[
let graph = [
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
];
]}

In graph theory, each of the people is a "vertex," and each pair of people is an
"edge." We can visualize it in 2D space.

{%html:<pre>
  Andrew ---10--- Philip                  Peter
    |                                    /     \
   15                                  30       10
    |                                  /         \
   Mary ---40--- Matthew ---55---- Luke         John
      \          /                  /
       40      60                 50
        \      /                  /
         Joseph ------ 55 ----- Mark ----30---- James
</pre>%}

Now we let the algorithm work its magic. It will find a series of edges that
have the highest possible combined weight, where no vertex is listed twice, and
where no vertex is without a mate. In this example, the result is:

{[
let result = [
  (Mary, Joseph),
  (Matthew, Luke),
  (Mark, James),
  (John, Peter),
  (Andrew, Philip)
];
]}

Or when we visualize it:

{%html:<pre>
  Andrew -------- Philip                  Peter
                                               \
                                                \
                                                 \
   Mary          Matthew --------- Luke         John
      \
       \
        \
         Joseph                 Mark ---------- James
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
let graph = [
  ("Mary", "Joseph", 40.),
  ("Mary", "Michael", 40.),
  ("Joseph", "Michael", 60.),
  ("Joseph", "Gabriel", 55.),
  ("Michael", "Raphael", 55.),
  ("Gabriel", "Raphael", 50.),
  ("Mary", "Paul", 15.),
  ("Raphael", "Peter", 30.),
  ("Peter", "John", 10.),
  ("Paul", "James", 10.),
  ("Gabriel", "Andrew", 30.),
];
]}

First, build an implementation with {!Make}.

{[
module StringMatch = Blossom.Match.Make(String);
]}

Then, use your implementation's {!S.make} function to produce a result.

{[
let result = StringMatch.make(graph);
]}

{2 Using the output}

The algorithm returns a bi-directional map of each vertex to its mate vertex.

{[
StringMatch.find(result, "Mary") == "Joseph";
StringMatch.find(result, "Joseph") == "Mary";
]}

You can convert it to a list with {!S.to_list}. {i The output of these will
have each pairing twice.} This is because it treats each order ([(a, b)] vs
[(b, a)]) separately.

{2 Maximum cardinality}

The {!make} function accepts one optional parameter, [cardinality], which can
be the value [`Max]. This enables "maximum cardinality" matching, where the
algorithm will only accept solutions that use as many edges as possible, even
extremely undesirable ones (such as ones with negative weights).

{[
let graph = [
  (1, 2, 2.),
  (1, 3, (-2.)),
  (2, 3, 1.),
  (2, 4, (-1.)),
  (3, 4, (-6.)),
];

module IntMatch = Blossom.Match.Make(Int);

let result = IntMatch.make(graph);
/* result: (1, 2) */

let result = IntMatch.make(~cardinality=`Max, graph);
/* result: (1, 3), (2, 4) */
]}

{1 Interface}

{2 Types}
|}
];

/**
  Represents whether or not the algorithm should {i only} accept
  maximum-cardinality solutions.
 */
type cardinality = [ | `Max | `NotMax];

/** Input signature of the functor {!Make}. */
module type OrderedType = {
  /** The type of the vertices. */
  type t;
  let compare: (t, t) => int;
};

/** Output signature of the functor {!Make}. */
module type S = {
  type vertex;
  /**
   A bi-directional, read-only mapping of each vertex to its mate vertex.
  */
  type t;

  [@text {|{2 Functions}|}];

  /**
   Computes a maximum-weighted matching on a general undirected weighted graph.
   This function takes time O(n³). See {!section:usage} for examples of its use.

   Accepts a list of tuples [(i, j, w)], each describing an undirected edge
   between vertex [i] and vertex [j] with weight [w]. There is at most one edge
   between any two vertices, and no vertex has an edge to itself. Duplicate
   edges are ignored.

   @param cardinality When set to [`Max], only maximum-cardinality matchings are
   considered as solutions. [`NotMax] is the default.
  */
  let make:
    (~cardinality: cardinality=?, list((vertex, vertex, float))) => t;

  /**
   Returns [mate] for a mated vertex, or raises [Not_found] if no such binding
   exists.
  */
  let find: (t, vertex) => vertex;

  /** Returns [Some(mate)] for a mated vertex, or [None] if none exists. */
  let find_opt: (t, vertex) => option(vertex);

  /**
   Folds over the pairs of vertex mates. Each pair is used twice, once in each
   order.
  */
  let fold: (t, ~init: 'acc, ~f: ('acc, vertex, vertex) => 'acc) => 'acc;

  /**
   Iterates over the pairs of vertex mates. Each pair is used twice, once in
   each order.
  */
  let iter: (t, ~f: (vertex, vertex) => unit) => unit;

  /**
   Returns a list of tuples for each pair of vertex mates. Each pair is used
   twice, once in each order.
  */
  let to_list: t => list((vertex, vertex));

  /** Returns [true] if there are no mates, [false] otherwise. */
  let is_empty: t => bool;

  /** Returns [true] if the vertex has a mate, [false] otherwise. */
  let mem: (vertex, t) => bool;

  /**
   Calling this with a [show] or [to_string] function will enable debug logging.
  */
  let enable_debug: (vertex => string) => unit;
  let disable_debug: unit => unit;
};

/**
 Functor building an implementation of the blossom algorithmstructure given a
 totally ordered type.
*/
module Make: (Ord: OrderedType) => S with type vertex = Ord.t;

[@text
  {|

{1 Changelog}

{{: https://github.com/johnridesabike/re-blossom/blob/master/CHANGELOG.md} See
the CHANGELOG.md file.}

{1 Similar packages}

{2 JavaScript}

The {{: https://www.npmjs.com/package/edmonds-blossom} edmonds-blossom}
package uses the same algorithm. It should return the exact same pairings that
this version does, but it doesn't have the flexibility of using different
types.

{2 Python}

{{: http://jorisvr.nl/article/maximum-matching} Joris van Rantwijk's Python
implementation} was the basis of both the JavaScript version and this Reason
version.

{1 Credits}

- {{: https://johnridesa.bike/} John} - idea and initial work.
- {{: http://jorisvr.nl/} Joris van Rantwijk} - his Python code was an
invaluable reference.

I can't take any credit for the algorithm itself. It exists thanks to many
people much smarter than me.
|}
];
