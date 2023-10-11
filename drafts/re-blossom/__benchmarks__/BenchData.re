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
module IntMatch =
  Match.Make({
    type t = int;
    let compare = (a: int, b: int) => compare(a, b);
  });
module Int = {
  let large = [
    (0, 1, 37.333333333333336),
    (0, 2, 52.),
    (0, 3, 41.33333333333333),
    (0, 4, 12.),
    (0, 5, 12.),
    (0, 6, 56.),
    (0, 8, 40.),
    (0, 9, 40.),
    (0, 10, 37.333333333333336),
    (0, 11, 12.),
    (0, 12, 40.),
    (0, 13, 24.),
    (0, 14, 38.4),
    (0, 15, 42.666666666666664),
    (0, 16, 50.66666666666667),
    (0, 17, 42.4),
    (1, 2, 41.33333333333333),
    (1, 3, 60.),
    (1, 4, 12.),
    (1, 5, 44.),
    (1, 6, 41.33333333333333),
    (1, 7, 42.4),
    (1, 8, 8.),
    (1, 9, 12.),
    (1, 10, 48.),
    (1, 11, 44.),
    (1, 12, 40.),
    (1, 13, 5.333333333333333),
    (1, 14, 10.666666666666666),
    (1, 15, 38.4),
    (1, 16, 37.333333333333336),
    (1, 17, 46.666666666666664),
    (2, 3, 37.333333333333336),
    (2, 4, 8.),
    (2, 5, 40.),
    (2, 6, 56.),
    (2, 7, 10.666666666666666),
    (2, 8, 44.),
    (2, 9, 36.),
    (2, 10, 41.33333333333333),
    (2, 11, 40.),
    (2, 12, 12.),
    (2, 13, 56.),
    (2, 14, 42.4),
    (2, 15, 14.666666666666666),
    (2, 16, 56.),
    (2, 17, 6.4),
    (3, 4, 40.),
    (3, 5, 40.),
    (3, 6, 5.333333333333333),
    (3, 7, 38.4),
    (3, 8, 12.),
    (3, 9, 40.),
    (3, 10, 56.),
    (3, 11, 40.),
    (3, 12, 44.),
    (3, 13, 41.33333333333333),
    (3, 14, 14.666666666666666),
    (3, 15, 42.4),
    (3, 16, 9.333333333333332),
    (3, 17, 42.666666666666664),
    (4, 5, 48.),
    (4, 6, 40.),
    (4, 7, 42.666666666666664),
    (4, 8, 54.66666666666667),
    (4, 9, 37.333333333333336),
    (4, 10, 12.),
    (4, 11, 52.),
    (4, 12, 60.),
    (4, 13, 44.),
    (4, 14, 46.666666666666664),
    (4, 15, 46.666666666666664),
    (4, 16, 44.),
    (4, 17, 42.666666666666664),
    (5, 6, 40.),
    (5, 7, 42.666666666666664),
    (5, 8, 24.),
    (5, 9, 37.333333333333336),
    (5, 10, 12.),
    (5, 11, 56.),
    (5, 12, 24.),
    (5, 13, 44.),
    (5, 14, 46.666666666666664),
    (5, 15, 46.666666666666664),
    (5, 16, 12.),
    (5, 17, 42.666666666666664),
    (6, 7, 42.666666666666664),
    (6, 8, 12.),
    (6, 9, 36.),
    (6, 10, 41.33333333333333),
    (6, 11, 40.),
    (6, 12, 12.),
    (6, 13, 52.),
    (6, 14, 42.4),
    (6, 15, 14.666666666666666),
    (6, 16, 52.),
    (6, 17, 38.4),
    (7, 8, 46.666666666666664),
    (7, 9, 4.571428571428571),
    (7, 10, 42.4),
    (7, 11, 42.666666666666664),
    (7, 12, 46.666666666666664),
    (7, 13, 14.666666666666666),
    (7, 14, 44.),
    (7, 15, 28.),
    (7, 16, 14.666666666666666),
    (7, 17, 40.),
    (8, 9, 41.33333333333333),
    (8, 10, 40.),
    (8, 11, 20.),
    (8, 12, 48.),
    (8, 13, 40.),
    (8, 14, 42.666666666666664),
    (8, 15, 42.666666666666664),
    (8, 16, 40.),
    (8, 17, 46.666666666666664),
    (9, 10, 44.),
    (9, 11, 5.333333333333333),
    (9, 12, 41.33333333333333),
    (9, 13, 40.),
    (9, 14, 42.4),
    (9, 15, 40.57142857142857),
    (9, 16, 40.),
    (9, 17, 6.4),
    (10, 11, 12.),
    (10, 12, 40.),
    (10, 13, 5.333333333333333),
    (10, 14, 42.666666666666664),
    (10, 15, 38.4),
    (10, 16, 37.333333333333336),
    (10, 17, 14.666666666666666),
    (11, 12, 52.),
    (11, 13, 44.),
    (11, 14, 46.666666666666664),
    (11, 15, 46.666666666666664),
    (11, 16, 44.),
    (11, 17, 42.666666666666664),
    (12, 13, 40.),
    (12, 14, 10.666666666666666),
    (12, 15, 42.666666666666664),
    (12, 16, 40.),
    (12, 17, 46.666666666666664),
    (13, 14, 38.4),
    (13, 15, 42.666666666666664),
    (13, 16, 48.),
    (13, 17, 42.4),
    (14, 15, 40.),
    (14, 16, 38.4),
    (14, 17, 28.),
    (15, 16, 10.666666666666666),
    (15, 17, 44.),
    (16, 17, 42.4),
  ];

  let nastyCase = [
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
  ];

  let longLabelPath = [
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
  ];

  let fiveChildren = [
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
  ];

  let data = [
    [
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
    ],
    [
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
    ],
    [
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
    ],
    [
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
    ],
    nastyCase,
    large,
    longLabelPath,
    fiveChildren,
  ];
};

module Make = (M: {
                 type t;
                 let ofInt: int => t;
                 let cmp: (t, t) => int;
               }) => {
  type t = M.t;
  let cmp = M.cmp;
  let convertEdge = ((i, j, w)) => (M.ofInt(i), M.ofInt(j), w);
  let data = Belt.List.map(Int.data, l => Belt.List.map(l, convertEdge));
  module Cmp = Belt.Id.MakeComparable(M);
};

module String =
  Make({
    type t = string;
    let ofInt =
      fun
      | 0 => "a"
      | 1 => "b"
      | 2 => "c"
      | 3 => "d"
      | 4 => "e"
      | 5 => "f"
      | 6 => "g"
      | 7 => "h"
      | 8 => "i"
      | 9 => "j"
      | 10 => "k"
      | 11 => "l"
      | 12 => "m"
      | 13 => "n"
      | 14 => "o"
      | 15 => "p"
      | 16 => "q"
      | 17 => "r"
      | _ => "darkness";
    let cmp: (string, string) => int = compare;
  });

/*
 module PersonType = {
   type t =
     | Mary
     | Joseph
     | Michael
     | Gabriel
     | Raphael
     | John
     | Peter
     | Paul
     | Andrew
     | James
     | Thomas
     | Philip
     | Bartholomew
     | Matthew
     | Simon
     | Jude
     | Matthias
     | Barnabas;
   let ofInt =
     fun
     | 0 => Mary
     | 1 => Joseph
     | 2 => Michael
     | 3 => Gabriel
     | 4 => Raphael
     | 5 => John
     | 6 => Peter
     | 7 => Paul
     | 8 => Andrew
     | 9 => James
     | 10 => Thomas
     | 11 => Philip
     | 12 => Bartholomew
     | 13 => Matthew
     | 14 => Simon
     | 15 => Jude
     | 16 => Matthias
     | _ => Barnabas;
   let toInt =
     fun
     | Mary => 0
     | Joseph => 1
     | Michael => 2
     | Gabriel => 3
     | Raphael => 4
     | John => 5
     | Peter => 6
     | Paul => 7
     | Andrew => 8
     | James => 9
     | Thomas => 10
     | Philip => 11
     | Bartholomew => 12
     | Matthew => 13
     | Simon => 14
     | Jude => 15
     | Matthias => 16
     | Barnabas => 17;
   let cmp = (a, b) => compare(toInt(a), toInt(b));
 };

 module Person = Make(PersonType);
 */

let default = () =>
  Belt.List.forEachU(Int.data, (. data) => IntMatch.make(data));
