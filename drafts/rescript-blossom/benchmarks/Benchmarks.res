@@text("
Copyright (c) 2021 John Jackson

This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
")
open Belt

module JsBlossom = {
  type t = (. array<(int, int, float)>) => array<int>
  @module external make: t = "edmonds-blossom"

  /* Turn a list of lists into a list of arrays for JS */

  /* Functions to convert non-integer data for use by jsBlossom.
   * These may or may not reflect practical real-world use. They're just a
   * quick-and dirty way to make it work. */

  let makeKeys: (
    list<('v, 'v, float)>,
    Belt.Id.comparable<'v, 'identity>,
  ) => (Map.Int.t<'v>, Map.t<'v, int, 'identity>) = (inputArray, id) => {
    let emptyMap = Map.make(~id)
    let emptySet = Set.make(~id)
    let (intMap, vertexMap, _) = /* Make a set of unique vertices. */
    List.reduceU(inputArray, emptySet, (. acc, (i, j, _w)) => acc->Set.add(i)->Set.add(j))
    /* Map them to integer indices */
    ->Set.reduceU((Map.Int.empty, emptyMap, 0), (. (intMap, strMap, index), x) => (
      Map.Int.set(intMap, index, x),
      Map.set(strMap, x, index),
      succ(index),
    ))
    (intMap, vertexMap)
  }

  let graphToIntGraph: (
    list<('v, 'v, float)>,
    Map.t<'v, int, 'identity>,
  ) => array<(int, int, float)> = (inputArray, strMap) =>
    List.reduceU(inputArray, [], (. acc, (i, j, w)) =>
      Array.concat(acc, [(Map.getExn(strMap, i), Map.getExn(strMap, j), w)])
    )

  let intResultToResult: (array<int>, Map.Int.t<'v>) => list<('v, 'v)> = (inputArray, intMap) =>
    Array.reduceWithIndexU(inputArray, list{}, (. acc, x, y) => list{
      (Map.Int.getExn(intMap, x), Map.Int.getExn(intMap, y)),
      ...acc,
    })
}

module BenchmarkJs = {
  type t
  @module("benchmark") @new external make: string => t = "Suite"

  module Stats = {
    type t = {
      rme: float,
      sample: array<float>,
    }
  }
  module Benchmark = {
    type t = {
      name: string,
      hz: float,
      stats: Stats.t,
    }
  }
  module Suite = {
    type t = Js.Dict.t<Benchmark.t>
    @get external name: t => string = "name"
    @get external length: t => int = "length"
  }
  type event = {
    currentTarget: Suite.t,
    target: Benchmark.t,
  }
  type options = {async: bool}
  @send external add: (t, string, unit => unit) => t = "add"
  @send
  external on: (t, [#cycle | #start | #complete], event => unit) => t = "on"
  @send external run: (t, options) => unit = "run"
}

let percentDiff = (a, b) => floor((b -. a) /. b *. 100.)

let formatResult = ({BenchmarkJs.Benchmark.name: name, hz, _}, maxHz) => (
  percentDiff(hz, maxHz)->Js.String.make ++ "% slower",
  name,
)

let make = (suite, jsBlossom) => {
  open BenchmarkJs
  suite
  ->add("ReScript-Blossom: Integers", () =>
    List.forEachU(BenchData.Int.data, (. x) => Match.Int.make(x))
  )
  ->add("JS Blossom: Integers", () =>
    List.forEachU(BenchData.Int.data, (. x) => jsBlossom(. List.toArray(x)))
  )
  ->add("ReScript-Blossom: Strings ", () =>
    List.forEachU(BenchData.String.data, (. x) => Match.String.make(x))
  )
  ->add("JS Blossom: Strings ", () =>
    List.forEachU(BenchData.String.data, (. x) => {
      let (intMap, vertexMap) = JsBlossom.makeKeys(x, module(BenchData.String.Cmp))
      let y = JsBlossom.graphToIntGraph(x, vertexMap)
      let mates = jsBlossom(. y)
      JsBlossom.intResultToResult(mates, intMap)
    })
  )
  ->on(#start, ({currentTarget, _}) => {
    Js.Console.info("Beginning benchmark")
    Js.Console.info2("name", currentTarget->Suite.name)
    Js.Console.info2("tests", currentTarget->Suite.length)
  })
  ->on(#cycle, ({target, _}) => Js.Console.info(target->Js.String.make))
  ->on(#complete, ({currentTarget, _}) => {
    open Benchmark
    let results =
      currentTarget
      ->Suite.length
      ->List.makeBy(x => Js.String.make(x))
      ->List.keepMap(Js.Dict.get(currentTarget))
      ->List.sort((a, b) => compare(b.hz, a.hz))
    switch results {
    | list{} => Js.Console.info("No results? :(")
    | list{first, second, third, fourth} =>
      Js.Console.info("Percenage comparison")
      Js.Console.info(("Fastest", first.name))
      Js.Console.info(formatResult(second, first.hz))
      Js.Console.info(formatResult(third, first.hz))
      Js.Console.info(formatResult(fourth, first.hz))
    | list{{name, hz: maxHz, _}, ...results} =>
      Js.log("  Fastest  : " ++ name)
      List.forEach(results, result => formatResult(result, maxHz)->Js.log)
    }
    Js.Console.info("Done")
  })
  ->run({async: true})
}
let default = make
