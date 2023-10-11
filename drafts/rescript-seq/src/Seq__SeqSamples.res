module Option = Belt.Option
let intToString = Belt.Int.toString

// Wrap any array in a sequence and then use 100+ functions to filter, group,
// map, reduce, and analyze it. The sequence does NOT copy the array; it is just
// a lightweight function to iterate through it.

let arr = ["w", "v", "q", "s", "p", "x"]
let s1 = arr->Seq.fromArray
let s2 = arr->Seq.fromArray(~start=2)
let s3 = arr->Seq.fromArray(~end=4)

/**
Create sequences from scratch, like JavaScript generators.
*/
let aa = Seq.range(1, 100)
let bb = Seq.rangeMap(99, 1, i => i * 3)
let cc = Seq.iterate(2, i => i * 2)->Seq.takeWhile(i => i < 1000)
let dd = Seq.foreverWith(() => Js.Math.random())
let ee = Seq.replicate("x", 100)

/**
Pointless number crunching to see how it flows. Unlike arrays, each
transformation does NOT create and allocate memory for the entire thing. The
only time work is done is with the final `forEach`.
*/
let nums =
  Seq.range(1, 999_999)
  ->Seq.drop(33)
  ->Seq.map(n => mod(n * 3, 7))
  ->Seq.pairwise
  ->Seq.dropLast(2)
  ->Seq.filterMap(((a, b)) => a < b ? Some(a + b) : None)
  ->Seq.takeUntil(i => i > 200)
  ->Seq.tap(n => {
    if n == 100 {
      Js.log(`Saw 100; interesting!`)
    }
  })
  ->Seq.flatMap(n => Seq.rangeMap(1, n, i => i * 2))
  ->Seq.filter(n => n > 100)
  ->Seq.forEach(Js.log)

/**
`scan` is similar to `reduce` but returns intermediate results. This computes a
running total. For example, the running total of [1, 2, 3, 4] is
[0, 1, 3, 6, 10] 
*/
let runningTotal = nums => nums->Seq.fromArray->Seq.scan(0, (sum, i) => sum + i)

/**
The `split` function allows you to group adjacent items however you want, and
then reduce each group however you want. This counts adjacent evens and odds. 
*/
let parity = n => mod(n, 2) == 0 ? "even" : "odd"

let evensAndOdds = nums =>
  nums->Seq.split(
    i => {"parity": parity(i), "count": 1},
    (sum, i) =>
      switch parity(i) == sum["parity"] {
      | true => Some({"parity": sum["parity"], "count": sum["count"] + 1})
      | false => None // parity different so start a new group
      },
  )

/**
`pairBehind` groups items into adjacent pairs. This removes sequential duplicates.
*/
let removeDups = xx =>
  xx
  ->Seq.fromArray
  ->Seq.pairBehind
  ->Seq.filter(((a, b)) => a->Option.mapWithDefault(true, a => a != b))
  ->Seq.map(((_, b)) => b)

/**
A fancier usage of `split`. Here it takes an array of sales, and computes the
sale count and total revenue per employee.
*/
type summary = {empId: string, sales: int, revenue: int}

type sale = {empId: string, amount: int}

let sortByEmployee = (a, b) => {
  let a = a.empId
  let b = b.empId
  a < b ? -1 : a > b ? 1 : 0
}

let salesSummary = sales => {
  sales
  ->Js.Array2.sortInPlaceWith(sortByEmployee)
  ->Seq.fromArray
  ->Seq.split(
    i => {empId: i.empId, sales: 1, revenue: i.amount},
    (sum, i) =>
      switch sum.empId == i.empId {
      | false => None
      | true => Some({...sum, sales: sum.sales + 1, revenue: sum.revenue + i.amount})
      },
  )
}

/**
Validates an array of "docs". The `everyOk` function lazily converts an array of
result to a result of array, stopping at the first error.
*/
let validate = (docs, isValidEmail) =>
  switch docs
  ->Seq.fromArray
  ->Seq.map(doc =>
    switch doc["email"]->isValidEmail {
    | false => Error(`The email is invalid for document: ${doc["title"]}`)
    | true => Ok(doc["title"]->Js.String2.trim)
    }
  )
  ->Seq.everyOk {
  | Ok(titles) => titles->Seq.forEach(t => Js.log(`Is valid: ${t}`))
  | Error(title) => Js.log(`Document with title ${title} is not valid.`)
  }

/**
`unfold` creates a new sequence from a seed value, like the opposite of
`reduce`. Here it calculates all the binary digits of a number and the following
one makes the fibonacci.
*/
let binary = n =>
  Seq.unfold(n, value => value > 0 ? Some(mod(value, 2), value / 2) : None)
  ->Seq.toArray
  ->Js.Array2.reverseInPlace

let fibonacci = count =>
  Seq.unfold((0, 1), ((a, b)) => a + b <= 100 ? Some(a + b, (b, a + b)) : None)
  ->Seq.prepend([0, 1]->Seq.fromArray)
  ->Seq.take(count)
  ->Seq.toArray

/**
There is a `zip` function that combines corresponding items from two sequences.
It stops when either input sequences ends. Here is a `zipLongest`. 
*/
let zipLongest = (xx, yy) => {
  let optionForever = ss => ss->Seq.map(x => Some(x))->Seq.concat(None->Seq.forever)
  let xx = xx->optionForever
  let yy = yy->optionForever
  Seq.zip(xx, yy)->Seq.takeWhile(((x, y)) => x->Option.isSome || y->Option.isSome)
}

/**
The `window` function shows sliding overlapping windows of your data. This
calculates the local minimum points in an array, converts each to a string, and
concatenates them with a comma between each.
*/
module Point = {
  type t = (int, int)
  let x = ((x, _)) => x
  let y = ((_, y)) => y
  let toString = ((x, y)) => `(${x->intToString}, ${y->intToString})`
}
let localMinimums = points =>
  points
  ->Seq.fromArray
  ->Seq.window(3)
  ->Seq.filterMap(pp =>
    pp[1]->Point.y < pp[0]->Point.y && pp[1]->Point.y < pp[2]->Point.y ? Some(pp[1]) : None
  )
  ->Seq.map(Point.toString)
  ->Seq.toOption
  ->Option.map(pp => pp->Seq.join(", "))
  ->Option.getWithDefault("There are no local minimums.")

/**
It is super easy to initialize arrays. This creates a 2d array and fills it with
the multiplication table. 
*/
let multiplicationTable = {
  open Seq
  range(0, 10)->map(x => range(0, 10)->map(y => x * y)->toArray)->toArray
}
