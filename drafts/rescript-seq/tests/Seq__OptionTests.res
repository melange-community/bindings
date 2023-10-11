let expectEq = (~title, ~expectation, ~a, ~b) =>
  Seq__Test.fromPredicate(~category="Option", ~title, ~expectation, () => a() == b)

module T = Seq__Test
module O = Seq__Option

let add = (a, b) => a + b
let add3 = (a, b, c) => a + b + c
let add4 = (a, b, c, d) => a + b + c + d

let tests = [
  expectEq(
    ~title="map2",
    ~expectation="when 0/2 Some => None",
    ~a=() => O.map2(None, None, add),
    ~b=None,
  ),
  expectEq(
    ~title="map2",
    ~expectation="when 2/2 Some => Some with map args",
    ~a=() => O.map2(Some(1), Some(5), add),
    ~b=Some(6),
  ),
  expectEq(
    ~title="map2",
    ~expectation="when 1/2 is Some => None",
    ~a=() => O.map2(Some(1), None, add),
    ~b=None,
  ),
  expectEq(
    ~title="map2",
    ~expectation="when 1/2 is Some => None",
    ~a=() => O.map2(None, Some(1), add),
    ~b=None,
  ),
  expectEq(
    ~title="map3",
    ~expectation="when 3/3 is Some => Some with map args",
    ~a=() => O.map3(Some(1), Some(5), Some(9), add3),
    ~b=Some(15),
  ),
  expectEq(
    ~title="map3",
    ~expectation="when 2/3 is Some => None",
    ~a=() => O.map3(Some(1), None, Some(5), add3),
    ~b=None,
  ),
  expectEq(
    ~title="map3",
    ~expectation="when 1/3 is Some => None",
    ~a=() => O.map3(None, Some(1), None, add3),
    ~b=None,
  ),
  expectEq(
    ~title="map3",
    ~expectation="when 0/3 is Some => None",
    ~a=() => O.map3(None, None, None, add3),
    ~b=None,
  ),
]
