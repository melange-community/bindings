open Belt
module Promise = Js.Promise2
module String = Js.String2

type t = {
  category: string,
  title: string,
  expectation: option<string>,
  predicate: unit => promise<result<unit, string>>,
}

let category = i => i.category
let title = i => i.title
let expectation = i => i.expectation

let hasKeyword = (i, word) => {
  let match = (~text, ~word) => {
    let text = text->String.trim->String.toLocaleLowerCase
    let keyword = word->String.trim->String.toLocaleLowerCase
    text->Js.String2.includes(keyword)
  }
  match(~text=i->category, ~word) ||
  match(~text=i->title, ~word) ||
  i->expectation->Option.mapWithDefault(false, expectation => match(~text=expectation, ~word))
}

type summary = {
  pass: int,
  fail: int,
  ran: int,
}

let stringCmp = (x: string, y: string) => x < y ? -1 : x > y ? 1 : 0
let cmp = (a, b) => stringCmp(a.category ++ a.title, b.category ++ b.title)

let fromResult = (~category, ~title, ~expectation=?, predicate) => {
  category,
  title,
  expectation,
  predicate: () =>
    try {
      predicate()
    } catch {
    | _ => Error("An exception was raised and not caught by the test itself.")
    }->Promise.resolve,
}

let fromPredicate = (~category, ~title, ~expectation=?, predicate) =>
  fromResult(~category, ~title, ~expectation?, () =>
    try {
      switch predicate() {
      | true => Ok()
      | false => Error("")
      }
    } catch {
    | _ => Error("An exception was raised and not caught by the test itself.")
    }
  )

let expectThrow = (~category, ~title, ~expectation=?, f) =>
  fromPredicate(~category, ~title, ~expectation?, () => {
    try {
      f()->ignore
      false
    } catch {
    | _ => true
    }
  })

let expectNotThrow = (~category, ~title, ~expectation=?, f) =>
  fromPredicate(~category, ~title, ~expectation?, () => {
    try {
      f()->ignore
      true
    } catch {
    | _ => false
    }
  })

let fromResultAsync = (~category, ~title, ~expectation=?, predicate) => {
  category,
  title,
  expectation,
  predicate,
}

let fromPredicateAsync = (~category, ~title, ~expectation=?, predicate) =>
  fromResultAsync(~category, ~title, ~expectation?, () =>
    predicate()->Promise.then(success => Promise.resolve(success ? Ok() : Error("")))
  )

let run = async i => {
  try {
    let succeed = await i.predicate()
    (succeed, i)
  } catch {
  | _ => (Error("An exception was raised and not caught by the test itself."), i)
  }
}

let toSummaryString = i => {
  let expectation = switch i->expectation {
  | None => ""
  | Some(expectation) => `| ${expectation}`
  }
  `${i.category} | ${i.title} ${expectation}`
}

let toDetailString = (i, message) => {
  let message = message == "" ? "" : `\n${message}`
  let expectation = switch i->expectation {
  | None => ""
  | Some(expectation) => `| ${expectation}`
  }
  `\n==== FAIL ${i.category} | ${i.title} ${expectation} ====${message}`
}

let runSuite = async (~filter=_ => true, ~onlyShowFailures=false, tests) => {
  let log = Js.Console.log
  let logSection = n => {
    log("")
    log(`==== ${n} ====`)
  }
  let results =
    await tests
    ->Array.keep(filter)
    ->SortArray.stableSortBy(cmp)
    ->Array.map(i => i->run)
    ->Promise.all
  let succeeded = results->Array.keepMap(((r, t)) =>
    switch r {
    | Ok(_) => Some(t)
    | Error(_) => None
    }
  )
  let failed = results->Array.keepMap(((r, t)) =>
    switch r {
    | Ok(_) => None
    | Error(message) => Some(t, message)
    }
  )
  if succeeded->Array.length > 0 && !onlyShowFailures {
    logSection("SUCCEEDED")
    succeeded->Array.forEach(t => `PASS ${t->toSummaryString}`->log)
  }
  if failed->Array.length > 0 {
    failed->Array.forEach(((t, message)) => toDetailString(t, message)->log)
    logSection("FAILURE SUMMARY")
    failed->Array.forEach(((t, _)) => `FAIL  ${t->toSummaryString}`->log)
  }
  logSection("SUMMARY")
  let summary = {
    pass: succeeded->Array.length,
    fail: failed->Array.length,
    ran: succeeded->Array.length + failed->Array.length,
  }
  log(`PASS : ${summary.pass->Int.toString}`)
  log(`FAIL : ${summary.fail->Int.toString}`)
  log(`RAN  : ${summary.ran->Int.toString}`)
  log("")
  summary
}
