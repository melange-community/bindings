@@text("
Copyright (c) 2021 John Jackson

This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
")
open Jest
open Expect

let sortResult = (l, ~compare) => Belt.List.sortU(l, (. (a, _), (b, _)) => compare(a, b))

let sortResultU = (l, ~compare) => Belt.List.sortU(l, (. (a, _), (b, _)) => compare(. a, b))

describe("Trivial cases", () => {
  test("Empty input graph", () =>
    Match.Int.make(list{}) |> Match.toList |> expect |> toEqual(list{})
  )
  test("Single edge", () =>
    Match.Int.make(list{(0, 1, 1.)})
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(0, 1), (1, 0)})
  )
  test("Two edges", () =>
    Match.Int.make(list{(1, 2, 10.), (2, 3, 11.)})
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(2, 3), (3, 2)})
  )
  test("Three edges", () =>
    Match.Int.make(list{(1, 2, 5.), (2, 3, 11.), (3, 4, 5.)})
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(2, 3), (3, 2)})
  )
  test("Three edges again, with IDs ordered differently", () =>
    Match.Int.make(list{(1, 2, 5.), (2, 3, 11.), (4, 3, 5.)})
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(2, 3), (3, 2)})
  )
  test("A simple love triangle", () =>
    Match.Int.make(list{(0, 1, 6.), (0, 2, 10.), (1, 2, 5.)})
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(0, 2), (2, 0)})
  )
  test("Maximum cardinality", () =>
    Match.Int.make(list{(1, 2, 5.), (2, 3, 11.), (3, 4, 5.)}, ~cardinality=#Max)
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(1, 2), (2, 1), (3, 4), (4, 3)})
  )
  test("Floating point weights", () =>
    Match.Int.make(list{
      (1, 2, Js.Math._PI),
      (2, 3, Js.Math.exp(1.)),
      (1, 3, 3.0),
      (1, 4, Js.Math.sqrt(2.0)),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(1, 4), (2, 3), (3, 2), (4, 1)})
  )
  describe("Negative weights", () => {
    test("Negative weights", () =>
      Match.Int.make(list{(1, 2, 2.), (1, 3, -2.), (2, 3, 1.), (2, 4, -1.), (3, 4, -6.)})
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{(1, 2), (2, 1)})
    )

    test("Negative weights with maximum cardinality", () =>
      Match.Int.make(
        ~cardinality=#Max,
        list{(1, 2, 2.), (1, 3, -2.), (2, 3, 1.), (2, 4, -1.), (3, 4, -6.)},
      )
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{(1, 3), (2, 4), (3, 1), (4, 2)})
    )
  })
})
describe("Blossoms", () => {
  describe("create S-blossom and use it for augmentation.", () => {
    test("S-blossom A", () =>
      Match.Int.make(list{(1, 2, 8.), (1, 3, 9.), (2, 3, 10.), (3, 4, 7.)})
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{(1, 2), (2, 1), (3, 4), (4, 3)})
    )
    test("S-blossom B", () =>
      Match.Int.make(list{(1, 2, 8.), (1, 3, 9.), (2, 3, 10.), (3, 4, 7.), (1, 6, 5.), (4, 5, 6.)})
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{(1, 6), (2, 3), (3, 2), (4, 5), (5, 4), (6, 1)})
    )
  })
  describe("Create S-blossom, relabel as T-blossom, use for augmentation.", () => {
    test("S-blossom, relabel as T-blossom: A", () =>
      Match.Int.make(list{(1, 2, 9.), (1, 3, 8.), (2, 3, 10.), (1, 4, 5.), (4, 5, 4.), (1, 6, 3.)})
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{(1, 6), (2, 3), (3, 2), (4, 5), (5, 4), (6, 1)})
    )
    test("S-blossom, relabel as T-blossom: B", () =>
      Match.Int.make(list{(1, 2, 9.), (1, 3, 8.), (2, 3, 10.), (1, 4, 5.), (4, 5, 3.), (1, 6, 4.)})
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{(1, 6), (2, 3), (3, 2), (4, 5), (5, 4), (6, 1)})
    )
    test("S-blossom, relabel as T-blossom: C", () =>
      Match.Int.make(list{(1, 2, 9.), (1, 3, 8.), (2, 3, 10.), (1, 4, 5.), (4, 5, 3.), (3, 6, 4.)})
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{(1, 2), (2, 1), (3, 6), (4, 5), (5, 4), (6, 3)})
    )
  })
  test("Create nested S-blossom, use for augmentation.", () =>
    Match.Int.make(list{
      (1, 2, 9.),
      (1, 3, 9.),
      (2, 3, 10.),
      (2, 4, 8.),
      (3, 5, 8.),
      (4, 5, 10.),
      (5, 6, 6.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(1, 3), (2, 4), (3, 1), (4, 2), (5, 6), (6, 5)})
  )
  test("Create S-blossom, relabel as S, include in nested S-blossom.", () =>
    Match.Int.make(list{
      (1, 2, 10.),
      (1, 7, 10.),
      (2, 3, 12.),
      (3, 4, 20.),
      (3, 5, 20.),
      (4, 5, 25.),
      (5, 6, 10.),
      (6, 7, 10.),
      (7, 8, 8.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(1, 2), (2, 1), (3, 4), (4, 3), (5, 6), (6, 5), (7, 8), (8, 7)})
  )
  test("Create nested S-blossom, augment, expand recursively.", () =>
    Match.Int.make(list{
      (1, 2, 8.),
      (1, 3, 8.),
      (2, 3, 10.),
      (2, 4, 12.),
      (3, 5, 12.),
      (4, 5, 14.),
      (4, 6, 12.),
      (5, 7, 12.),
      (6, 7, 14.),
      (7, 8, 12.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(1, 2), (2, 1), (3, 5), (4, 6), (5, 3), (6, 4), (7, 8), (8, 7)})
  )
  test("Create S-blossom, relabel as T, expand.", () =>
    Match.Int.make(list{
      (1, 2, 23.),
      (1, 5, 22.),
      (1, 6, 15.),
      (2, 3, 25.),
      (3, 4, 22.),
      (4, 5, 25.),
      (4, 8, 14.),
      (5, 7, 13.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(1, 6), (2, 3), (3, 2), (4, 8), (5, 7), (6, 1), (7, 5), (8, 4)})
  )
  test("Create nested S-blossom, relabel as T, expand.", () =>
    Match.Int.make(list{
      (1, 2, 19.),
      (1, 3, 20.),
      (1, 8, 8.),
      (2, 3, 25.),
      (2, 4, 18.),
      (3, 5, 18.),
      (4, 5, 13.),
      (4, 7, 7.),
      (5, 6, 7.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(1, 8), (2, 3), (3, 2), (4, 7), (5, 6), (6, 5), (7, 4), (8, 1)})
  )
})
describe("Nasty cases", () => {
  test("Create blossom, relabel as T in more than one way, expand, augment.", () =>
    Match.Int.make(list{
      (1, 2, 45.),
      (1, 5, 45.),
      (2, 3, 50.),
      (3, 4, 45.),
      (4, 5, 50.),
      (1, 6, 30.),
      (3, 9, 35.),
      (4, 8, 35.),
      (5, 7, 26.),
      (9, 10, 5.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{
      (1, 6),
      (2, 3),
      (3, 2),
      (4, 8),
      (5, 7),
      (6, 1),
      (7, 5),
      (8, 4),
      (9, 10),
      (10, 9),
    })
  )
  test("Again, but slightly different.", () =>
    Match.Int.make(list{
      (1, 2, 45.),
      (1, 5, 45.),
      (2, 3, 50.),
      (3, 4, 45.),
      (4, 5, 50.),
      (1, 6, 30.),
      (3, 9, 35.),
      (4, 8, 26.),
      (5, 7, 40.),
      (9, 10, 5.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{
      (1, 6),
      (2, 3),
      (3, 2),
      (4, 8),
      (5, 7),
      (6, 1),
      (7, 5),
      (8, 4),
      (9, 10),
      (10, 9),
    })
  )
  test(
    "Create blossom, relabel as T, expand such that a new least-slack " ++ "S-to-free edge is produced, augment.",
    () =>
      Match.Int.make(list{
        (1, 2, 45.),
        (1, 5, 45.),
        (2, 3, 50.),
        (3, 4, 45.),
        (4, 5, 50.),
        (1, 6, 30.),
        (3, 9, 35.),
        (4, 8, 28.),
        (5, 7, 26.),
        (9, 10, 5.),
      })
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{
        (1, 6),
        (2, 3),
        (3, 2),
        (4, 8),
        (5, 7),
        (6, 1),
        (7, 5),
        (8, 4),
        (9, 10),
        (10, 9),
      }),
  )
  test(
    "Create nested blossom, relabel as T in more than one way, expand outer " ++ "blossom such that inner blossom ends up on an augmenting path.",
    () =>
      Match.Int.make(list{
        (1, 2, 45.),
        (1, 7, 45.),
        (2, 3, 50.),
        (3, 4, 45.),
        (4, 5, 95.),
        (4, 6, 94.),
        (5, 6, 94.),
        (6, 7, 50.),
        (1, 8, 30.),
        (3, 11, 35.),
        (5, 9, 36.),
        (7, 10, 26.),
        (11, 12, 5.),
      })
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{
        (1, 8),
        (2, 3),
        (3, 2),
        (4, 6),
        (5, 9),
        (6, 4),
        (7, 10),
        (8, 1),
        (9, 5),
        (10, 7),
        (11, 12),
        (12, 11),
      }),
  )
  describe("Create nested S-blossom, relabel as S, expand recursively.", () => {
    test("Create nested S-blossom, relabel as S, expand recursively.", () =>
      Match.Int.make(list{
        (1, 2, 40.),
        (1, 3, 40.),
        (2, 3, 60.),
        (2, 4, 55.),
        (3, 5, 55.),
        (4, 5, 50.),
        (1, 8, 15.),
        (5, 7, 30.),
        (7, 6, 10.),
        (8, 10, 10.),
        (4, 9, 30.),
      })
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{
        (1, 2),
        (2, 1),
        (3, 5),
        (4, 9),
        (5, 3),
        (6, 7),
        (7, 6),
        (8, 10),
        (9, 4),
        (10, 8),
      })
    )
    test("Again, but slightly different. (A)", () =>
      Match.Int.make(list{
        (1, 2, 40.),
        (1, 3, 40.),
        (2, 3, 60.),
        (2, 4, 55.),
        (3, 5, 55.),
        (4, 5, 50.),
        (1, 8, 15.),
        (5, 7, 30.),
        (7, 6, 10.),
        (8, 10, 10.),
        (4, 9, 30.),
        (11, 10, 100.),
      })
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{
        (1, 8),
        (2, 3),
        (3, 2),
        (4, 5),
        (5, 4),
        (6, 7),
        (7, 6),
        (8, 1),
        (10, 11),
        (11, 10),
      })
    )
    test("Again, but slightly different. (B)", () =>
      Match.Int.make(list{
        (1, 2, 40.),
        (1, 3, 40.),
        (2, 3, 60.),
        (2, 4, 55.),
        (3, 5, 55.),
        (4, 5, 50.),
        (1, 8, 15.),
        (5, 7, 30.),
        (7, 6, 10.),
        (8, 10, 10.),
        (4, 9, 30.),
        (3, 6, 36.),
      })
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{
        (1, 2),
        (2, 1),
        (3, 6),
        (4, 9),
        (5, 7),
        (6, 3),
        (7, 5),
        (8, 10),
        (9, 4),
        (10, 8),
      })
    )
  })
})
describe("More nasty cases", () => {
  test("Blossom with five children (A).", () =>
    Match.Int.make(list{
      (9, 8, 30.),
      (9, 5, 55.),
      (9, 3, 6.),
      (9, 1, 50.),
      (8, 3, 18.),
      (8, 4, 10.),
      (7, 3, 15.),
      (7, 6, 10.),
      (5, 3, 40.),
      (5, 2, 60.),
      (3, 2, 40.),
      (3, 4, 16.),
      (2, 1, 55.),
      (1, 0, 43.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(0, 1), (1, 0), (2, 5), (3, 4), (4, 3), (5, 2), (6, 7), (7, 6), (8, 9), (9, 8)})
  )
  test("Blossom with five children (B).", () =>
    Match.Int.make(list{
      (1, 2, 77.),
      (1, 3, 60.),
      (1, 4, 61.),
      (2, 5, 87.),
      (2, 6, 10.),
      (2, 4, 89.),
      (7, 8, 15.),
      (7, 5, 28.),
      (7, 9, 10.),
      (3, 8, 5.),
      (3, 5, 60.),
      (8, 5, 58.),
      (5, 4, 55.),
      (4, 10, 30.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(1, 3), (2, 4), (3, 1), (4, 2), (5, 8), (7, 9), (8, 5), (9, 7)})
  )
  test("Scan along a long label path to create a blossom.", () =>
    Match.Int.make(list{
      (10, 6, 30.),
      (10, 9, 55.),
      (10, 8, 50.),
      (6, 3, 10.),
      (4, 1, 15.),
      (4, 5, 10.),
      (9, 1, 40.),
      (9, 2, 55.),
      (9, 8, 59.),
      (1, 2, 40.),
      (2, 8, 55.),
      (8, 7, 30.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{
      (1, 2),
      (2, 1),
      (3, 6),
      (4, 5),
      (5, 4),
      (6, 3),
      (7, 8),
      (8, 7),
      (9, 10),
      (10, 9),
    })
  )
})
describe("Input tests", () => {
  test("Duplicate edges are ignored.", () =>
    Match.Int.make(list{
      (1, 2, 8.),
      (1, 3, 9.),
      (2, 3, 10.),
      (2, 3, 100.),
      (3, 2, 9000.),
      (3, 1, 9000.),
      (3, 4, 7.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(1, 2), (2, 1), (3, 4), (4, 3)})
  )
  test("Non-sequential and negative integers.", () =>
    Match.Int.make(list{
      (69, -69, 40.),
      (69, 420, 40.),
      (-69, 420, 60.),
      (-69, -420, 55.),
      (420, 5, 55.),
      (-420, 5, 50.),
      (69, 8, 15.),
      (5, 7, 30.),
      (7, 6, 10.),
      (8, 10, 10.),
      (-420, 9, 30.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{
      (-420, 9),
      (-69, 69),
      (5, 420),
      (6, 7),
      (7, 6),
      (8, 10),
      (9, -420),
      (10, 8),
      (69, -69),
      (420, 5),
    })
  )
  describe("Reversed vertices", () => {
    test(
      "(Reversed) Create nested blossom, relabel as T in more than one way, " ++
      ("expand outer blossom such that inner blossom ends up on an " ++
      "augmenting path."),
      () =>
        Match.Int.make(list{
          (-1, -2, 45.),
          (-1, -7, 45.),
          (-2, -3, 50.),
          (-3, -4, 45.),
          (-4, -5, 95.),
          (-4, -6, 94.),
          (-5, -6, 94.),
          (-6, -7, 50.),
          (-1, -8, 30.),
          (-3, -11, 35.),
          (-5, -9, 36.),
          (-7, -10, 26.),
          (-11, -12, 5.),
        })
        |> Match.toList
        |> sortResult(~compare)
        |> expect
        |> toEqual(list{
          (-12, -11),
          (-11, -12),
          (-10, -7),
          (-9, -5),
          (-8, -1),
          (-7, -10),
          (-6, -4),
          (-5, -9),
          (-4, -6),
          (-3, -2),
          (-2, -3),
          (-1, -8),
        }),
    )
    test("(Reversed) Create nested S-blossom, augment, expand recursively.", () =>
      Match.Int.make(list{
        (8, 7, 8.),
        (8, 6, 8.),
        (7, 6, 10.),
        (7, 5, 12.),
        (6, 4, 12.),
        (5, 4, 14.),
        (5, 3, 12.),
        (4, 2, 12.),
        (3, 2, 14.),
        (2, 1, 12.),
      })
      |> Match.toList
      |> sortResult(~compare)
      |> expect
      |> toEqual(list{(1, 2), (2, 1), (3, 5), (4, 6), (5, 3), (6, 4), (7, 8), (8, 7)})
    )
  })
  test("Vertices with edges on themselves are silently ignored.", () =>
    Match.Int.make(list{(0, 1, 1.), (1, 1, 9001.)})
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{(0, 1), (1, 0)})
  )
  test("String vertices", () =>
    Match.String.make(list{
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
      ("Gabriel", "Gabriel", 100.),
      ("Gabriel", "Andrew", 100.),
    })
    |> Match.toList
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{
      ("Andrew", "Gabriel"),
      ("Gabriel", "Andrew"),
      ("James", "Paul"),
      ("John", "Peter"),
      ("Joseph", "Mary"),
      ("Mary", "Joseph"),
      ("Michael", "Raphael"),
      ("Paul", "James"),
      ("Peter", "John"),
      ("Raphael", "Michael"),
    })
  )
  describe("Arbitrary type vertices", () => {
    test("Variants (nested S-blossom, relabel as S)", () => {
      module Person = {
        type t =
          | Mary
          | Joseph
          | Matthew
          | Mark
          | Luke
          | John
          | Peter
          | Andrew
          | James
          | Philip
        let toInt = x =>
          switch x {
          | Mary => 0
          | Joseph => 1
          | Matthew => 2
          | Mark => 3
          | Luke => 4
          | John => 5
          | Peter => 6
          | Andrew => 7
          | James => 8
          | Philip => 9
          }
        let cmp = (a, b) => compare(toInt(a), toInt(b))
      }
      /* ********************************************************
       *  Andrew ---10--- Philip                  Peter        *
       *    |                                    /     \       *
       *   15                                  30       10     *
       *    |                                  /         \     *
       *   Mary ---40--- Matthew ---55---- Luke         John   *
       *      \          /                  /                  *
       *       40      60                 50                   *
       *        \      /                  /                    *
       *         Joseph ------ 55 ----- Mark ----30---- James  *
       ******************************************************* */
      Match.make(
        ~id=module(Match.MakeComparable(Person)),
        list{
          (Person.Mary, Joseph, 40.),
          (Mary, Matthew, 40.),
          (Joseph, Matthew, 60.),
          (Joseph, Mark, 55.),
          (Matthew, Luke, 55.),
          (Mark, Luke, 50.),
          (Mary, Andrew, 15.),
          (Luke, Peter, 30.),
          (Peter, John, 10.),
          (Andrew, Philip, 10.),
          (Mark, James, 30.),
        },
      )
      |> Match.toList
      |> sortResult(~compare=Person.cmp)
      |> expect
      |> toEqual(list{
        (Person.Mary, Person.Joseph),
        (Joseph, Mary),
        (Matthew, Luke),
        (Mark, James),
        (Luke, Matthew),
        (John, Peter),
        (Peter, John),
        (Andrew, Philip),
        (James, Mark),
        (Philip, Andrew),
      })
      /* ********************************************************
       *  Andrew -------- Philip                  Peter        *
       *                                               \       *
       *                                                \      *
       *                                                 \     *
       *   Mary          Matthew --------- Luke         John   *
       *      \                                                *
       *       \                                               *
       *        \                                              *
       *         Joseph                 Mark ---------- James  *
       ******************************************************* */
    })
    test("Again, with a different cmp function.", () => {
      module Person = {
        type t =
          | Mary
          | Joseph
          | Matthew
          | Mark
          | Luke
          | John
        let toString = x =>
          switch x {
          | Mary => "Mary"
          | Joseph => "Joseph"
          | Matthew => "Matthew"
          | Mark => "Mark"
          | Luke => "Luke"
          | John => "John"
          }
        let cmp = (a, b) => compare(toString(a), toString(b))
      }
      Match.make(
        ~id=module(Match.MakeComparable(Person)),
        list{
          (Person.Mary, Joseph, 9.),
          (Mary, Matthew, 9.),
          (Joseph, Matthew, 10.),
          (Joseph, Mark, 8.),
          (Matthew, Luke, 8.),
          (Mark, Luke, 10.),
          (Luke, John, 6.),
          (Luke, Luke, 100.),
          (Luke, John, 100.),
        },
      )
      |> Match.toList
      |> sortResult(~compare=Person.cmp)
      |> expect
      |> toEqual(list{
        (Person.John, Person.Luke),
        (Joseph, Mark),
        (Luke, John),
        (Mark, Joseph),
        (Mary, Matthew),
        (Matthew, Mary),
      })
    })
    test("Variants with an uncurried cmp function.", () => {
      module Person = {
        type t =
          | Mary
          | Joseph
          | Matthew
        let toInt = x =>
          switch x {
          | Mary => 0
          | Joseph => 1
          | Matthew => 2
          }
        let cmp = (. a, b) => compare(toInt(a), toInt(b))
      }
      Match.make(
        ~id=module(Match.MakeComparableU(Person)),
        list{(Person.Mary, Joseph, 40.), (Mary, Matthew, 30.), (Joseph, Matthew, 20.)},
      )
      |> Match.toList
      |> sortResultU(~compare=Person.cmp)
      |> expect
      |> toEqual(list{(Person.Mary, Person.Joseph), (Joseph, Mary)})
    })
    test("Variants and reusing a Belt.Id module.", () => {
      module Person = {
        type t =
          | Mary
          | Joseph
          | Matthew
        let toInt = x =>
          switch x {
          | Mary => 0
          | Joseph => 1
          | Matthew => 2
          }
        let cmp = (a, b) => compare(toInt(a), toInt(b))
      }
      module PersonCmp = Belt.Id.MakeComparable(Person)
      Match.make(
        ~id=Match.unsafeComparableFromBelt(~id=module(PersonCmp), ~cmp=Person.cmp),
        list{(Person.Mary, Joseph, 40.), (Mary, Matthew, 30.), (Joseph, Matthew, 20.)},
      )
      |> Match.toList
      |> sortResult(~compare=Person.cmp)
      |> expect
      |> toEqual(list{(Person.Mary, Person.Joseph), (Joseph, Mary)})
    })
    test("Again, with an uncurried cmp function.", () => {
      module Person = {
        type t =
          | Mary
          | Joseph
          | Matthew
        let toInt = x =>
          switch x {
          | Mary => 0
          | Joseph => 1
          | Matthew => 2
          }
        let cmp = (. a, b) => compare(toInt(a), toInt(b))
      }
      module PersonCmp = Belt.Id.MakeComparableU(Person)
      Match.make(
        ~id=Match.unsafeComparableFromBeltU(~id=module(PersonCmp), ~cmp=Person.cmp),
        list{(Person.Mary, Joseph, 40.), (Mary, Matthew, 30.), (Joseph, Matthew, 20.)},
      )
      |> Match.toList
      |> sortResultU(~compare=Person.cmp)
      |> expect
      |> toEqual(list{(Person.Mary, Person.Joseph), (Joseph, Mary)})
    })
    test("Variant constructors", () => {
      module StringOrInt = {
        type t =
          | String(string)
          | Int(int)
        let cmp = (a, b) =>
          switch (a, b) {
          | (String(a), String(b)) => compare(a, b)
          | (Int(a), Int(b)) => compare(a, b)
          | (String(_), Int(_)) => 1
          | (Int(_), String(_)) => -1
          }
      }
      module Cmp = unpack(Match.comparable(StringOrInt.cmp))
      Match.make(
        ~id=module(Cmp),
        list{
          (StringOrInt.Int(1), Int(2), 40.),
          (Int(1), Int(3), 40.),
          (Int(2), Int(3), 60.),
          (Int(2), Int(4), 55.),
          (Int(3), Int(5), 55.),
          (Int(4), Int(5), 50.),
          (Int(1), String("c"), 15.),
          (Int(5), String("b"), 30.),
          (String("b"), String("a"), 10.),
          (String("c"), String("e"), 10.),
          (Int(4), String("d"), 30.),
        },
      )
      |> Match.toList
      |> sortResult(~compare=StringOrInt.cmp)
      |> expect
      |> toEqual(list{
        (StringOrInt.Int(1), StringOrInt.Int(2)),
        (Int(2), Int(1)),
        (Int(3), Int(5)),
        (Int(4), String("d")),
        (Int(5), Int(3)),
        (String("a"), String("b")),
        (String("b"), String("a")),
        (String("c"), String("e")),
        (String("d"), Int(4)),
        (String("e"), String("c")),
      })
    })
  })
})
describe("Output tests", () => {
  let result = Match.Int.make(list{
    (1, 2, 40.),
    (1, 3, 40.),
    (2, 3, 60.),
    (2, 4, 55.),
    (3, 5, 55.),
    (4, 5, 50.),
    (1, 8, 15.),
    (5, 7, 30.),
    (7, 6, 10.),
    (8, 10, 10.),
    (4, 9, 30.),
  })
  test("get", () => Match.get(result, 5) |> expect |> toBe(Some(3)))
  test("get None", () => Match.get(result, 69) |> expect |> toBe(None))
  test("toList", () =>
    Match.toList(result)
    |> sortResult(~compare)
    |> expect
    |> toEqual(list{
      (1, 2),
      (2, 1),
      (3, 5),
      (4, 9),
      (5, 3),
      (6, 7),
      (7, 6),
      (8, 10),
      (9, 4),
      (10, 8),
    })
  )
  test("toMap", () =>
    Belt.Map.eq(
      Match.toMap(result),
      Belt.Map.fromArray(
        ~id=Match.comparableToBelt(module(Match.Int.Cmp)),
        [(1, 2), (2, 1), (3, 5), (4, 9), (5, 3), (6, 7), (7, 6), (8, 10), (9, 4), (10, 8)],
      ),
      \"=",
    )
    |> expect
    |> toBe(true)
  )
  test("forEach", () => {
    let arr = Array.make(11, -1)
    Match.forEach(result, ~f=(v1, v2) => ignore(arr[v1] = v2))
    expect(arr) |> toEqual([-1, 2, 1, 5, 9, 3, 7, 6, 10, 4, 8])
  })
  test("isEmpty", () => Match.isEmpty(result) |> expect |> toBe(false))
  test("has", () => Match.has(result, 5) |> expect |> toBe(true))
  test("reduce", () =>
    Match.reduce(result, ~init="", ~f=(acc, v1, v2) =>
      "(" ++ (Belt.Int.toString(v1) ++ (", " ++ (Belt.Int.toString(v2) ++ ("), " ++ acc))))
    )
    |> expect
    |> toBe(
      "(10, 8), (9, 4), (8, 10), (7, 6), (6, 7), (5, 3), (4, 9), (3, 5), " ++ "(2, 1), (1, 2), ",
    )
  )
})
describe("Brute force any missed edge cases (slow)", () =>
  test(
    "Generate a large number of random graphs and check that the algorithm " ++ "doesn't crash.",
    () =>
      (
        () =>
          Belt.Range.forEach(0, 1023, _ =>
            Belt.List.makeBy(63, _ => (
              Js.Math.random_int(0, 15),
              Js.Math.random_int(0, 15),
              Js.Math.random() *. 100.,
            ))
            |> Match.Int.make
            |> ignore
          )
      )
      |> expect
      |> not_
      |> toThrow,
  )
)
