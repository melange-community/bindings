module Option = Belt.Option
module OptionEx = Seq__Option
module Result = Belt.Result
module Array = Js.Array2
module String = Js.String2

exception InvalidArgument(string)

/**
This is the type definition of a sequence. It is basically a function that
returns either `End`, meaning there is nothing left in the sequence, or `Next`,
indicating the next item. It uses uncurried mode since the resultant JavaScript
looked a bit simpler to me. This is an abstract type in case we want to change
the implementation later to use an `option` perhaps. Or maybe generate more
performant code for sequences that wrap arrays. Note that the `unfold` function
is nearly identical to this implementation, so not much flexibility is lost by
hiding the implementation.
*/
type rec t<'a> = (. unit) => node<'a>
and node<'a> =
  | End
  | Next('a, t<'a>)

let delay = generator => (. ()) => generator()(.)

let empty = (. ()) => End

let once = x => (. ()) => Next(x, empty)

let onceWith = f => (. ()) => Next(f(), empty)

let cons = (x, xx) => (. ()) => Next(x, xx)

/**
Internal helper function to generate the next node in a sequence. It is
sometimes simpler to use this in pipeline mode because if you put a `(.)` at the
end it latches on to the very last item in the sequence rather than the result
of everything that came before.
*/
@inline
let next = (xx: t<'a>) => xx(.)

let intToString = Belt.Int.toString

let uncons = xx =>
  switch xx->next {
  | End => None
  | Next(x, xx) => Some(x, xx)
  }

let find = (xx, f) => {
  let rec go = xx =>
    switch xx->next {
    | End => None
    | Next(x, xx) =>
      switch f(x) {
      | true => Some(x)
      | false => go(xx)
      }
    }
  go(xx)
}

let findLast = (xx, f) => {
  let rec go = (xx, last) =>
    switch xx->next {
    | End => last
    | Next(x, xx) =>
      switch f(x) {
      | true => go(xx, Some(x))
      | false => go(xx, last)
      }
    }
  go(xx, None)
}

let rec concat = (xx, yy) =>
  (. ()) => {
    switch xx->next {
    | End => yy->next
    | Next(x, xx) => Next(x, concat(xx, yy))
    }
  }

let append = concat

@inline let prepend = (xx, yy) => concat(yy, xx)

let rec flatMap = (xx, f) =>
  (. ()) =>
    switch xx->next {
    | End => End
    | Next(x, xx) => concat(f(x), flatMap(xx, f))(.)
    }

let rec flatten = xxx =>
  (. ()) =>
    switch xxx->next {
    | End => End
    | Next(xx, xxx) => concat(xx, flatten(xxx))->next
    }

let rec map = (xx, f) =>
  (. ()) => {
    switch xx->next {
    | End => End
    | Next(x, xx) => Next(f(x), map(xx, f))
    }
  }

let head = xx =>
  switch xx->next {
  | End => None
  | Next(x, _) => Some(x)
  }

let indexed = xx => {
  let rec go = (xx, index) =>
    (. ()) =>
      switch xx->next {
      | End => End
      | Next(x, xx) => Next((x, index), go(xx, index + 1))
      }
  go(xx, 0)
}

let rec forEach = (xx, f) =>
  switch xx->uncons {
  | None => ()
  | Some(x, xx) => {
      f(x)
      forEach(xx, f)
    }
  }

let forEachi = (xx, f) => xx->indexed->forEach(((x, inx)) => f(x, inx))

let rec unfold = (seed, f) =>
  (. ()) =>
    switch f(seed) {
    | None => End
    | Some(x, seed) => Next(x, unfold(seed, f))
    }

let init = (count, f) => unfold(0, i => i < count ? Some(f(i), i + 1) : None)

let replicate = (value, count) => unfold(0, i => i < count ? Some(value, i + 1) : None)

let replicateWith = (value, count) => unfold(1, i => i <= count ? Some(value(), i + 1) : None)

let rec forever = value => (. ()) => Next(value, forever(value))

let rec foreverWith = f => (. ()) => Next(f(), foreverWith(f))

let iterate = (seed, f) => unfold(seed, i => Some(i, f(i)))

let range = (start, end) => {
  start <= end
    ? unfold(start, i => i <= end ? Some(i, i + 1) : None)
    : unfold(start, i => i >= end ? Some(i, i - 1) : None)
}

let rangeMap = (start, end, f) => range(start, end)->map(f)

let rec tap = (xx, f) =>
  (. ()) =>
    switch xx->next {
    | End => End
    | Next(x, xx) => {
        f(x)
        Next(x, tap(xx, f))
      }
    }

let rec cycleNonEmpty = xx => (. ()) => concat(xx, cycleNonEmpty(xx))->next

let cycle = xx =>
  (. ()) =>
    switch xx->uncons {
    | None => End
    | Some(x, xx') => cons(x, xx')->concat(cycleNonEmpty(xx))->next
    }

let fromArray = (~start=?, ~end=?, xx: array<'a>) => {
  switch xx->Array.length == 0 {
  | true =>
    start
    ->Option.orElse(end)
    ->Option.forEach(_ =>
      InvalidArgument(
        "'fromArray' was invoked with am empty array, but you provided start and/or end indexes.",
      )->raise
    )
    empty
  | false => {
      let len = xx->Array.length
      let start = start->Option.getWithDefault(0)
      let end = end->Option.getWithDefault(len - 1)
      if start < 0 || start > len - 1 {
        InvalidArgument(`The start index ${start->intToString} is outside the array bounds.`)->raise
      }
      if end < 0 || end > len - 1 {
        InvalidArgument(`The end index ${start->intToString} is outside the array bounds.`)->raise
      }
      range(start, end)->map(inx => xx->Array.unsafe_get(inx))
    }
  }
}

let rec fromList = xx => {
  (. ()) =>
    switch xx {
    | list{} => End
    | list{x, ...xx} => Next(x, fromList(xx))
    }
}

let mapi = (xx, f) => xx->indexed->map(((x, inx)) => f(x, inx))

let take = (xx, count) => {
  if count < 0 {
    InvalidArgument(
      `'take' requires a count of 0 or more. You requested ${count->intToString}`,
    )->raise
  }
  let rec go = (xx, count) =>
    (. ()) =>
      switch count {
      | 0 => End
      | count =>
        switch xx->next {
        | End => End
        | Next(x, xx) => Next(x, go(xx, count - 1))
        }
      }
  go(xx, count)
}

let headTails = xx => unfold(xx, xx => xx->uncons->Option.flatMap(((_, xx) as ht) => Some(ht, xx)))

let rec dropEager = (xx, count) =>
  switch count {
  | 0 => xx
  | count =>
    switch xx->uncons {
    | None => empty
    | Some(_, xx) => dropEager(xx, count - 1)
    }
  }

let drop = (xx, count) =>
  switch count {
  | 0 => xx
  | count if count < 0 =>
    InvalidArgument(
      `'drop' requires a count of zero or more but you asked for ${count->intToString}`,
    )->raise
  | count => delay(() => dropEager(xx, count))
  }

let rec filter = (xx, f) =>
  (. ()) => {
    switch xx->next {
    | End => End
    | Next(x, xx) =>
      switch f(x) {
      | true => Next(x, filter(xx, f))
      | false =>
        switch xx->headTails->find(((x, _)) => f(x)) {
        | None => End
        | Some((x, xx)) => Next(x, filter(xx, f))
        }
      }
    }
  }

let filteri = (xx, f) => xx->indexed->filter(((x, inx)) => f(x, inx))->map(((v, _)) => v)

let rec takeWhile = (xx, f) =>
  (. ()) => {
    switch xx->next {
    | End => End
    | Next(x, xx) =>
      switch f(x) {
      | true => Next(x, takeWhile(xx, f))
      | false => End
      }
    }
  }

let rec takeUntil = (xx, f) =>
  (. ()) => {
    switch xx->next {
    | End => End
    | Next(x, xx) =>
      switch f(x) {
      | true => Next(x, empty)
      | false => Next(x, takeUntil(xx, f))
      }
    }
  }

let filterMapi = (xx, f) => {
  let rec go = xx =>
    switch xx->uncons {
    | None => None
    | Some((x, index), xx) =>
      switch f(x, index) {
      | None => go(xx)
      | Some(x) => Some(x, xx)
      }
    }
  unfold(xx->indexed, go)
}

let filterMap = (xx, f) => {
  let rec go = xx =>
    switch xx->uncons {
    | None => None
    | Some(x, xx) =>
      switch f(x) {
      | None => go(xx)
      | Some(x) => Some(x, xx)
      }
    }
  unfold(xx, go)
}

let filterSome = xx => {
  let rec go = xx =>
    switch xx->uncons {
    | None => None
    | Some(x, xx) =>
      switch x {
      | None => go(xx)
      | Some(x) => Some(x, xx)
      }
    }
  unfold(xx, go)
}

let filterOk = xx =>
  xx->filterMap(x =>
    switch x {
    | Ok(ok) => Some(ok)
    | Error(_) => None
    }
  )

let scan = (xx, zero, f) => {
  let rec go = (xx, sum) =>
    (. ()) =>
      switch xx->next {
      | End => End
      | Next(x, xx) => {
          let sum = f(sum, x)
          Next(sum, go(xx, sum))
        }
      }
  concat(once(zero), go(xx, zero))
}

let rec sortedMerge = (xx, yy, cmp) => {
  (. ()) =>
    switch (xx(.), yy(.)) {
    | (End, Next(_, _) as yy) => yy
    | (Next(_, _) as xx, End) => xx
    | (Next(x, xx), Next(y, yy)) => {
        let order = cmp(x, y)
        if order <= 0 {
          Next(x, sortedMerge(xx, concat(y->once, yy), cmp))
        } else {
          Next(y, sortedMerge(concat(x->once, xx), yy, cmp))
        }
      }
    | (End, End) => End
    }
}

let intersperseWith = (xx, separator) => {
  let rec beforeEach = (xx, separator) =>
    (. ()) => {
      switch xx->next {
      | End => End
      | Next(x, xx) => Next(separator(), cons(x, beforeEach(xx, separator)))
      }
    }
  (. ()) =>
    switch xx->next {
    | End => End
    | Next(x, xx) => Next(x, beforeEach(xx, separator))
    }
}

let intersperse = (xx, separator) => xx->intersperseWith(() => separator)

module Cache = {
  type t<'a> = (. unit) => 'a

  type toLazy<'a> = t<'a> => Lazy.t<'a>
  let toLazy: toLazy<'a> = (f: t<'a>) => {
    let g = () => f(.)
    Lazy.from_fun(g)
  }

  type fromLazy<'a> = Lazy.t<'a> => t<'a>
  let fromLazy: fromLazy<'a> = f => (. ()) => Lazy.force(f)

  type make<'a> = t<'a> => t<'a>
  let make: make<'a> = f => f->toLazy->fromLazy
}

let rec cache = xx =>
  Cache.make((. ()) =>
    switch xx->next {
    | End => End
    | Next(x, xx) => Next(x, cache(xx))
    }
  )

let allPairs = (xx, yy) => {
  let yy = yy->cache
  xx->flatMap(x => yy->map(y => (x, y)))
}

let dropUntil = (xx, f) =>
  (. ()) =>
    xx
    ->headTails
    ->find(((x, _)) => f(x))
    ->Option.map(((x, xx)) => Next(x, xx))
    ->Option.getWithDefault(End)

let dropWhile = (xx, f) =>
  (. ()) =>
    xx
    ->headTails
    ->find(((x, _)) => false == f(x))
    ->Option.map(((x, xx)) => Next(x, xx))
    ->Option.getWithDefault(End)

let window = (xx, length) => {
  if length <= 0 {
    InvalidArgument(`'window' requires a length > 0. You asked for ${length->intToString}`)->raise
  }
  xx
  ->scan([], (sum, val) => {
    if Array.length(sum) >= length {
      sum->Array.shift->ignore
    }
    sum->Array.push(val)->ignore
    sum
  })
  ->filter(i => Array.length(i) == length)
}

let reduce = (xx, zero, concat) => {
  let sum = ref(zero)
  xx->forEach(x => sum := concat(sum.contents, x))
  sum.contents
}

let reduceUntil = (xx, zero, concat, predicate) => {
  let rec go = (xx, sum) =>
    switch predicate(sum) {
    | true => sum
    | false =>
      switch xx->uncons {
      | None => sum
      | Some(x, xx) => go(xx, concat(sum, x))
      }
    }
  go(xx, zero)
}

let reduceWhile = (xx, zero, concat, predicate) => {
  let rec go = (xx, sum) =>
    switch xx->uncons {
    | None => Some(sum)
    | Some(x, xx) => {
        let sum' = concat(sum, x)
        switch predicate(sum') {
        | true => go(xx, sum')
        | false => Some(sum)
        }
      }
    }
  switch predicate(zero) {
  | false => None
  | true => go(xx, zero)
  }
}

let sumBy = (xx, concat) =>
  switch xx->uncons {
  | None => None
  | Some(x, xx) => {
      let sum = ref(x)
      xx->forEach(x => sum := concat(sum.contents, x))
      Some(sum.contents)
    }
  }

let prefixSum = (xx, accumulator) =>
  (. ()) => {
    switch xx->uncons {
    | None => End
    | Some(x, xx) =>
      cons(
        x,
        unfold((x, xx), ((sum, xx)) =>
          switch xx->uncons {
          | None => None
          | Some(x, xx) => {
              let sum' = accumulator(sum, x)
              Some(sum', (sum', xx))
            }
          }
        ),
      )->next
    }
  }

let join = (xx, separator) =>
  switch separator->String.length {
  | 0 => xx
  | _ => xx->intersperse(separator)
  }->reduce("", (total, i) => total ++ i)

let last = xx => xx->sumBy((_, i) => i)

let toArray = xx =>
  xx->reduce([], (xx, i) => {
    xx->Array.push(i)->ignore
    xx
  })

let some = (xx, f) => xx->find(f)->Option.isSome

let every = (xx, f) => xx->find(i => !f(i))->Option.isNone

let findMap = (xx, f) => {
  let rec go = xx =>
    switch xx->next {
    | End => None
    | Next(x, xx) =>
      switch f(x) {
      | Some(x) => Some(x)
      | None => go(xx)
      }
    }
  go(xx)
}

let findMapLast = (xx, f) => {
  let rec go = (xx, last) =>
    switch xx->next {
    | End => last
    | Next(x, xx) =>
      switch f(x) {
      | Some(_) as found => go(xx, found)
      | None => go(xx, last)
      }
    }
  go(xx, None)
}

let rec map2 = (xx, yy, f) =>
  (. ()) => {
    let xx = xx->uncons
    let yy = yy->uncons
    OptionEx.map2(xx, yy, ((x, xx), (y, yy)) => Next(
      f(x, y),
      map2(xx, yy, f),
    ))->Option.getWithDefault(End)
  }

let rec map3 = (xx, yy, zz, f) =>
  (. ()) => {
    let xx = xx->uncons
    let yy = yy->uncons
    let zz = zz->uncons
    OptionEx.map3(xx, yy, zz, ((x, xx), (y, yy), (z, zz)) => Next(
      f(x, y, z),
      map3(xx, yy, zz, f),
    ))->Option.getWithDefault(End)
  }

let rec map4 = (xx, yy, zz, qq, f) =>
  (. ()) => {
    let xx = xx->uncons
    let yy = yy->uncons
    let zz = zz->uncons
    let qq = qq->uncons
    OptionEx.map4(xx, yy, zz, qq, ((x, xx), (y, yy), (z, zz), (q, qq)) => Next(
      f(x, y, z, q),
      map4(xx, yy, zz, qq, f),
    ))->Option.getWithDefault(End)
  }

let rec map5 = (xx, yy, zz, qq, mm, f) =>
  (. ()) => {
    let xx = xx->uncons
    let yy = yy->uncons
    let zz = zz->uncons
    let qq = qq->uncons
    let mm = mm->uncons
    OptionEx.map5(xx, yy, zz, qq, mm, ((x, xx), (y, yy), (z, zz), (q, qq), (m, mm)) => Next(
      f(x, y, z, q, m),
      map5(xx, yy, zz, qq, mm, f),
    ))->Option.getWithDefault(End)
  }

let zip = (xx, yy) => map2(xx, yy, (x, y) => (x, y))
let zip3 = (xx, yy, zz) => map3(xx, yy, zz, (x, y, z) => (x, y, z))
let zip4 = (xx, yy, zz, qq) => map4(xx, yy, zz, qq, (x, y, z, q) => (x, y, z, q))
let zip5 = (xx, yy, zz, qq, mm) => map5(xx, yy, zz, qq, mm, (x, y, z, q, m) => (x, y, z, q, m))

let equals = (xx, yy, eq) => {
  let xx = xx->map(x => Some(x))->concat(None->once)
  let yy = yy->map(y => Some(y))->concat(None->once)
  map2(xx, yy, (x, y) =>
    switch (x, y) {
    | (None, None) => true
    | (Some(x), Some(y)) => eq(x, y)
    | _ => false
    }
  )->every(i => i)
}

let compare = (xx, yy, cmp) => {
  let xx = xx->map(x => Some(x))->concat(None->once)
  let yy = yy->map(y => Some(y))->concat(None->once)
  map2(xx, yy, (x, y) =>
    switch (x, y) {
    | (Some(x), Some(y)) => cmp(x, y)
    | (None, Some(_)) => -1
    | (Some(_), None) => 1
    | (None, None) => 0
    }
  )
  ->find(i => i !== 0)
  ->Option.getWithDefault(0)
}

let length = xx => xx->reduce(0, (sum, _) => sum + 1)

let isEmpty = xx =>
  switch xx->next {
  | End => true
  | _ => false
  }

let tail = xx =>
  (. ()) =>
    switch xx->uncons {
    | None => End
    | Some(_, xx) => xx->next
    }

let tails = xx =>
  cons(
    xx,
    unfold(xx, xx =>
      switch xx->next {
      | End => None
      | Next(_, xx) => Some(xx, xx)
      }
    ),
  )

let minBy = (xx, cmp) => xx->sumBy((sum, i) => cmp(i, sum) < 0 ? i : sum)

let maxBy = (xx, cmp) => xx->sumBy((sum, i) => cmp(i, sum) > 0 ? i : sum)

let rec interleave = (xx, yy) => {
  (. ()) => {
    switch xx->next {
    | End => yy->next
    | Next(x, xx) => Next(x, interleave(yy, xx))
    }
  }
}

let exactlyOne = xx =>
  switch xx->uncons {
  | None => None
  | Some(x, xx) =>
    switch xx->isEmpty {
    | true => Some(x)
    | false => None
    }
  }

let pairAhead = xx =>
  (. ()) => {
    switch xx->next {
    | End => End
    | Next(x, xx) =>
      unfold(Some(x, xx), nxt =>
        switch nxt {
        | None => None
        | Some(x, xx) =>
          switch xx->next {
          | End => Some((x, None), None)
          | Next(x', xx) => Some((x, Some(x')), Some(x', xx))
          }
        }
      )->next
    }
  }

let pairBehind = xx =>
  (. ()) => {
    switch xx->next {
    | End => End
    | Next(a, xx) =>
      cons(
        (None, a),
        unfold((a, xx), ((a, xx)) =>
          switch xx->next {
          | End => None
          | Next(b, xx) => Some((Some(a), b), (b, xx))
          }
        ),
      )->next
    }
  }

let pairwise = xx =>
  (. ()) =>
    switch xx->next {
    | End => End
    | Next(a, xx) =>
      switch xx->next {
      | End => End
      | Next(b, xx) =>
        cons(
          (a, b),
          unfold((b, xx), ((b, xx)) =>
            switch xx->next {
            | End => None
            | Next(x, xx) => Some((b, x), (x, xx))
            }
          ),
        )->next
      }
    }

let dropLast = (xx, n) => {
  switch n {
  | 0 => xx
  | n if n < 0 =>
    InvalidArgument(
      `dropLast requires a count of 0 or more. You requested ${n->intToString}`,
    )->raise
  | n =>
    (. ()) =>
      xx
      ->scan([], (sum, i) => {
        switch sum->Array.push(i) {
        | size if size > n + 1 => sum->Array.shift->ignore
        | _ => ()
        }
        sum
      })
      ->dropUntil(i => i->Array.length == n + 1)
      ->takeWhile(i => i->Array.length > n)
      ->map(i => i->Array.unsafe_get(0))
      ->next
  }
}

let neighbors = xx =>
  (. ()) =>
    switch xx->next {
    | End => End
    | Next(a, xx) =>
      switch xx->next {
      | End => Next((None, a, None), empty)
      | Next(b, xx) =>
        switch xx->next {
        | End => Next((None, a, Some(b)), (Some(a), b, None)->once)
        | Next(c, xx) =>
          cons(
            (None, a, Some(b)),
            cons(
              (Some(a), b, Some(c)),
              unfold(Some(b, c, xx), state =>
                switch state {
                | None => None
                | Some(b, c, xx) =>
                  switch xx->next {
                  | End => Some((Some(b), c, None), None)
                  | Next(d, xx) => Some((Some(b), c, Some(d)), Some(c, d, xx))
                  }
                }
              ),
            ),
          )->next
        }
      }
    }

let isSortedBy = (xx, cmp) => xx->pairwise->every(((a, b)) => cmp(a, b) <= 0)

let everyOk = xx => {
  let concat = (sum, i) =>
    switch sum {
    | Error(_) as error => error
    | Ok(oks) =>
      switch i {
      | Error(_) as error => error
      | Ok(ok) => Ok(oks->concat(ok->once))
      }
    }
  xx->reduceUntil(Ok(empty), concat, Result.isError)
}

let everySome = xx => {
  let concat = (sum, i) =>
    switch sum {
    | None => None
    | Some(somes) =>
      switch i {
      | None => None
      | Some(some) => Some(somes->concat(some->once))
      }
    }
  xx->reduceUntil(Some(empty), concat, Option.isNone)
}

let toOption = xx =>
  switch xx->next {
  | End => None
  | Next(x, xx) => Some(cons(x, xx))
  }

let consume = xx => xx->forEach(_ => ())

let orElse = (xx, yy) =>
  (. ()) => {
    switch xx->next {
    | End => yy->next
    | Next(_, _) as nxt => nxt
    }
  }

let reverse = xx =>
  delay(() => {
    let xx = xx->toArray
    switch xx->Array.length {
    | 0 => empty
    | _ => xx->fromArray(~start=xx->Array.length - 1, ~end=0)
    }
  })

let sortBy = (xx, compare) =>
  delay(() => {
    let xx = xx->toArray
    xx->Array.sortInPlaceWith(compare)->ignore
    xx->fromArray
  })

/**
`distribute(source, divider)` iterates through each item in `source` and returns
the sequences that result when `divider` is inserted before that item, and also
after the last item. If `source` is empty, returns a sequence consisting only of
`divider`.

```
[1, 2]->distribute(8) // [[8,1,2], [1,8,2], [1,2,8]]
[1]->distribute(8) // [[8,1], [1,8]]
[]->distribute(8) // [[8]]
```
*/
let distribute = (xx, item) => {
  let go = (pre, suf) =>
    unfold((pre, suf), ((pre, suf)) =>
      switch suf->uncons {
      | None => None
      | Some(x, xx) => {
          let yield = pre->concat(x->once)->concat(item->once)->concat(xx)
          let next = (pre->concat(x->once), xx)
          Some(yield, next)
        }
      }
    )
  go(empty, xx)->concat(cons(item, xx)->once)
}

let (combinations, permutations) = {
  let helper = (xx, maxSize, f) => {
    if maxSize <= 0 {
      InvalidArgument(`Size must be 1 or more. You asked for ${maxSize->intToString}.`)->raise
    }
    unfold((empty, xx), ((sum, xx)) =>
      switch xx->uncons {
      | None => None
      | Some(x, xx) => {
          let next = {
            let xOnly = (1, x->once)
            let xWithSum = sum->flatMap(((size, xx)) =>
              switch size < maxSize {
              | true => f(x, xx)->map(xx => (size + 1, xx))
              | false => empty
              }
            )
            cons(xOnly, xWithSum)
          }
          Some(next, (concat(sum, next), xx))
        }
      }
    )->flatten
  }
  let permutations = (xx, maxSize) => helper(xx, maxSize, (x, xx) => distribute(xx, x))
  let combinations = (xx, maxSize) => helper(xx, maxSize, (x, xx) => once(cons(x, xx)))
  (combinations, permutations)
}

let toList = xx => xx->reverse->reduce(list{}, Belt.List.add)

let split = (xx, init, acc) => {
  let rec unfolder = state =>
    switch state {
    | None => None
    | Some((sum, xx)) =>
      switch xx->uncons {
      | None => Some(sum, None)
      | Some(x, xx) =>
        switch acc(sum, x) {
        | None => Some(sum, Some(init(x), xx))
        | Some(sum) => unfolder(Some(sum, xx))
        }
      }
    }
  (. ()) => {
    switch xx->uncons {
    | None => End
    | Some(x, xx) => unfold(Some(init(x), xx), unfolder)->next
    }
  }
}

let chunkBySize = (xx, length) => {
  if length <= 0 {
    InvalidArgument(
      `chunkBySize requires a length > 0. You asked for ${length->intToString}`,
    )->raise
  }
  xx->split(
    i => [i],
    (sum, i) =>
      switch sum->Array.length == length {
      | true => None
      | false => {
          sum->Array.push(i)->ignore
          Some(sum)
        }
      },
  )
}
