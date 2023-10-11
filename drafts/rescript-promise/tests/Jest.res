@val external describe: (string, @uncurry (unit => unit)) => unit = "describe"
@val external test: (string, @uncurry (unit => unit)) => unit = "test"
@val external testAsync: (string, @uncurry (((. unit) => unit) => unit)) => unit = "test"
@val external testPromise: (string, @uncurry (unit => Js.Promise.t<unit>)) => unit = "test"

type e<'a>
@val external expect: 'a => e<'a> = "expect"
@send external toBe: (e<'a>, 'a) => unit = "toBe"
@send external toEqual: (e<'a>, 'a) => unit = "toEqual"
@send external toMatchSnapshot: e<'a> => unit = "toMatchSnapshot"

@val external each: (array<'a>, . string, 'a => unit) => unit = "test.each"
let each = (data, title, f) => each(data)(. title, f)

@val external each2: (array<('a, 'b)>, . string, ('a, 'b) => unit) => unit = "test.each"
let each2 = (data, title, f) => each2(data)(. title, f)

@val external each3: (array<('a, 'b, 'c)>, . string, ('a, 'b, 'c) => unit) => unit = "test.each"
let each3 = (data, title, f) => each3(data)(. title, f)

@scope("expect") @val external expectAssertions: int => unit = "assertions"
