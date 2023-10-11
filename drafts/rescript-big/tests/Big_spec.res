@val external test: (string, @uncurry (unit => unit)) => unit = "test"
type expect<'a>
@val external expect: 'a => expect<'a> = "expect"
@send external toStrictEqual: (expect<'a>, 'a) => unit = "toStrictEqual"

open! Big.Operators

test("fromFloat(x) is just equals to toFloat(x)", () =>
  expect(2.0->Big.fromFloat->Big.toFloat)->toStrictEqual(2.0)
)

test("should add values", () => {
  expect(2.0->Big.fromFloat +. 5.2->Big.fromFloat +. 0.3->Big.fromFloat)->toStrictEqual(
    7.5->Big.fromFloat,
  )
  expect(2.0->Big.fromFloat->Big.plus(5.2->Big.fromFloat))->toStrictEqual(7.2->Big.fromFloat)
})

test("should multiply values", () => {
  expect(2.0->Big.fromFloat *. 3.0->Big.fromFloat)->toStrictEqual(6.0->Big.fromFloat)
  expect(2.0->Big.fromFloat->Big.times(3.0->Big.fromFloat))->toStrictEqual(6.0->Big.fromFloat)
})

test("should multiply values and fix digits", () =>
  expect(
    (2020.2065->Big.fromFloat *. 3.0->Big.fromFloat)
    ->Big.toFixed(2)
    ->Belt.Float.fromString
    ->Belt.Option.map(Big.fromFloat),
  )->toStrictEqual(Some(6060.62->Big.fromFloat))
)

test("should divide values", () => {
  expect(4.2->Big.fromFloat /. 2.0->Big.fromFloat)->toStrictEqual(2.1->Big.fromFloat)
  expect(4.2->Big.fromFloat->Big.div(2.0->Big.fromFloat))->toStrictEqual(2.1->Big.fromFloat)
})

test("should do substract and return correct value", () => {
  expect(2.2->Big.fromFloat -. 0.2->Big.fromFloat)->toStrictEqual(2.0->Big.fromFloat)
  expect(2.2->Big.fromFloat->Big.minus(0.2->Big.fromFloat))->toStrictEqual(2.0->Big.fromFloat)
})

test("should round decimal value", () =>
  expect(79.116666666666658755->Big.fromFloat->Big.round(4))->toStrictEqual(79.1167->Big.fromFloat)
)

test("should compare with eq", () => {
  expect(79.11->Big.fromFloat->Big.eq(79.10->Big.fromFloat))->toStrictEqual(false)
  expect(0.->Big.fromFloat->Big.eq(0.0000000000001->Big.fromFloat))->toStrictEqual(false)
})

test("should compare with eq after round", () =>
  expect(0.->Big.fromFloat->Big.eq(0.0000000000001->Big.fromFloat->Big.round(1)))->toStrictEqual(
    true,
  )
)

test("should compare with gt", () =>
  expect(79.11->Big.fromFloat->Big.gt(79.10->Big.fromFloat))->toStrictEqual(true)
)

test("should compare with gt", () =>
  expect(79.11->Big.fromFloat->Big.gt(79.11->Big.fromFloat))->toStrictEqual(false)
)

test("should compare with gte", () =>
  expect(79.11->Big.fromFloat->Big.gte(79.11->Big.fromFloat))->toStrictEqual(true)
)

test("should compare with gte", () =>
  expect(79.11->Big.fromFloat->Big.gte(79.12->Big.fromFloat))->toStrictEqual(false)
)

test("should compare with lt", () =>
  expect(79.11->Big.fromFloat->Big.lt(79.12->Big.fromFloat))->toStrictEqual(true)
)

test("should compare with lt", () =>
  expect(79.11->Big.fromFloat->Big.lt(79.11->Big.fromFloat))->toStrictEqual(false)
)

test("should compare with lte", () =>
  expect(79.11->Big.fromFloat->Big.lte(79.12->Big.fromFloat))->toStrictEqual(true)
)

test("should compare with lte", () =>
  expect(79.11->Big.fromFloat->Big.lte(79.0001->Big.fromFloat))->toStrictEqual(false)
)

test("should return the string value of a big float", () =>
  expect(79.11->Big.fromFloat->Big.valueOf)->toStrictEqual("79.11")
)

test("should return the float value of a big float", () =>
  expect(79.11->Big.fromFloat->Big.toFloat)->toStrictEqual(79.11)
)

test("should fix big value", () =>
  expect(79.116666666666658755->Big.fromFloat->Big.toFixed(4))->toStrictEqual("79.1167")
)
