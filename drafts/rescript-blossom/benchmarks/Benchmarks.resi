@@text("
Copyright (c) 2021 John Jackson

This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
")
module JsBlossom: {
  type t = (. array<(int, int, float)>) => array<int>
  @module external make: t = "edmonds-blossom"
}
module BenchmarkJs: {
  type t
  @module("benchmark") @new external make: string => t = "Suite"
}
let make: (BenchmarkJs.t, JsBlossom.t) => unit
let default: (BenchmarkJs.t, JsBlossom.t) => unit
