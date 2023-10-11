type datum = {
  id: int,
  date: string,
  value: int,
};

type data = array(datum);

let data: data = [|
  {id: 1, date: "9/19/2018", value: 1},
  {id: 2, date: "11/23/2018", value: 33},
  {id: 3, date: "10/13/2018", value: 55},
  {id: 4, date: "5/24/2018", value: 23},
  {id: 5, date: "7/26/2018", value: 37},
  {id: 7, date: "11/23/2018", value: 73},
  {id: 8, date: "10/7/2018", value: 67},
  {id: 9, date: "5/26/2018", value: 69},
  {id: 10, date: "12/13/2018", value: 41},
  {id: 11, date: "6/26/2018", value: 7},
  {id: 12, date: "4/23/2018", value: 79},
  {id: 13, date: "7/25/2018", value: 99},
  {id: 14, date: "1/4/2019", value: 19},
  {id: 15, date: "2/22/2019", value: 4},
  {id: 16, date: "2/3/2019", value: 46},
  {id: 17, date: "4/20/2018", value: 20},
  {id: 18, date: "2/27/2018", value: 96},
  {id: 19, date: "5/6/2018", value: 24},
  {id: 20, date: "12/8/2018", value: 72},
  {id: 21, date: "12/25/2018", value: 7},
  {id: 22, date: "7/23/2018", value: 78},
  {id: 23, date: "6/17/2018", value: 13},
  {id: 24, date: "1/10/2019", value: 74},
  {id: 25, date: "9/15/2018", value: 86},
  {id: 26, date: "1/20/2019", value: 21},
  {id: 27, date: "3/4/2018", value: 85},
  {id: 28, date: "7/23/2018", value: 4},
  {id: 29, date: "9/28/2018", value: 57},
  {id: 30, date: "4/15/2018", value: 76},
  {id: 31, date: "12/31/2018", value: 9},
  {id: 32, date: "3/7/2018", value: 4},
  {id: 33, date: "10/9/2018", value: 75},
  {id: 34, date: "12/8/2018", value: 69},
  {id: 35, date: "8/6/2018", value: 69},
  {id: 36, date: "11/9/2018", value: 19},
  {id: 37, date: "7/8/2018", value: 42},
  {id: 38, date: "3/8/2018", value: 46},
  {id: 39, date: "3/14/2018", value: 74},
  {id: 40, date: "9/6/2018", value: 60},
  {id: 41, date: "10/29/2018", value: 44},
  {id: 42, date: "5/7/2018", value: 83},
  {id: 43, date: "5/6/2018", value: 97},
  {id: 44, date: "7/16/2018", value: 11},
  {id: 45, date: "7/17/2018", value: 36},
  {id: 46, date: "4/5/2018", value: 16},
  {id: 47, date: "2/8/2019", value: 79},
  {id: 48, date: "9/4/2018", value: 85},
  {id: 49, date: "1/1/2019", value: 20},
  {id: 50, date: "6/8/2018", value: 25},
|];

[@bs.val] [@bs.scope "Math"] external random: unit => float = "random";

let getData: unit => data =
  () => {
    [
      {id: 6, date: "12/11/2018", value: 24},
      ...data
         ->Array.keep(_ => floor(random() *. 100.0) > 75.0)
         ->List.fromArray,
    ]
    ->List.toArray;
  };
