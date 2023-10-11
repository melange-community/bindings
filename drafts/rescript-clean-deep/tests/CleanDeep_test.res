/*
 These are the same tests as in the original clean-deep package:
 https://github.com/nunofgs/clean-deep/blob/master/test/index_test.js
 */

open Jest
open Expect

describe("cleanDeep()", () => {
  test("should pick defined values from the object", () => {
    let jsObject = %raw(`
      {
        bar: {},
        biz: [],
        foo: {
          bar: undefined,
          baz: true,
          biz: false,
          buz: null,
          net: "",
          qux: 100

        }
      }
      `)

    expect(CleanDeep.cleanDeep(jsObject, ())) |> toEqual(
      %raw(`
            {
              foo: {
                baz: true,
                biz: false,
                qux: 100
              }
            }
           `),
    )
  })

  test("should clean arrays", () => {
    let jsObject = %raw(`
      {
        foo: [{
          bar: undefined,
          baz: "",
          biz: 0
        }]
      }
      `)

    expect(CleanDeep.cleanDeep(jsObject, ())) |> toEqual(
      %raw(`
           {
             foo: [{
               biz: 0
             }]
           }
          `),
    )
  })

  test("should include non plain objects", () => {
    let jsObject = %raw(`
      {
        foo: {
          bar: new Date(0),
          biz: undefined
        }
      }
      `)

    expect(CleanDeep.cleanDeep(jsObject, ())) |> toEqual(
      %raw(`
           {
             foo: {
               bar: new Date(0)
             }
           }
           `),
    )
  })

  test("should include empty objects if `emptyObjects` is `false`", () => {
    let jsObject = %raw(`
      {
        biz: {
          baz: 123
        },
        foo: {
          bar: {}
        }
      }
      `)

    expect(CleanDeep.cleanDeep(jsObject, ~emptyObjects=false, ())) |> toEqual(
      %raw(`
           {
             biz: {
               baz: 123
             },
             foo: {
               bar: {}
             }
           }
           `),
    )
  })

  test("should include empty arrays if `emptyArrays` is `false`", () => {
    let jsObject = %raw(`
      {
        biz: {
          bar: [],
          baz: 123
        },
        foo: []
      }
      `)

    expect(CleanDeep.cleanDeep(jsObject, ~emptyArrays=false, ())) |> toEqual(
      %raw(`
           {
             biz: {
               bar: [],
               baz: 123
             },
             foo: []
           }
           `),
    )
  })

  test("should include empty strings if `emptyStrings` is `false`", () => {
    let jsObject = %raw(`
      {
        foo: {
          bar: "",
          biz: 123
        }
      }
      `)

    expect(jsObject->CleanDeep.cleanDeep(~emptyStrings=false, ())) |> toEqual(
      %raw(`
           {
             foo: {
               bar: "",
               biz: 123
             }
           }
           `),
    )
  })

  test("should include null values if `nullValues` is `false`", () => {
    let jsObject = %raw(`
      {
        foo: {
          bar: null,
          biz: 123
        }
      }
      `)

    expect(jsObject->CleanDeep.cleanDeep(~nullValues=false, ())) |> toEqual(
      %raw(`
           {
             foo: {
               bar: null,
               biz: 123
             }
           }
           `),
    )
  })

  test("should include undefined values if `undefinedValues` is `false`", () => {
    let jsObject = %raw(`
      {
        foo: {
          bar: undefined,
          biz: 123,
          qux: [
            undefined,
            {},
            true
          ]
        }
      }
      `)

    expect(jsObject->CleanDeep.cleanDeep(~undefinedValues=false, ())) |> toEqual(
      %raw(`
           {
             foo: {
               bar: undefined,
               biz: 123,
               qux: [
                 undefined,
                 true
               ]
             }
           }
           `),
    )
  })

  test("should remove custom values", () => {
    let jsObject = %raw(`
      {
        foo: {
          bar: 'remove-this',
          biz: 123,
          qux: [
            "this-as-well",
            {},
            true
          ]
        }
      }
      `)

    expect(
      jsObject->CleanDeep.cleanDeep(~cleanValues=["remove-this", "this-as-well"], ()),
    ) |> toEqual(
      %raw(`
           {
             foo: {
               biz: 123,
               qux: [
                 true
               ]
             }
           }
           `),
    )
  })

  test("should remove custom keys", () => {
    let jsObject = %raw(`
      {
        foo: {
          remove: 'hi there',
          biz: 123,
          qux: [
            {},
            true
          ],
          andThis: 'hello',
          butNotThis: 'goodbye'
        }
      }
      `)

    expect(jsObject->CleanDeep.cleanDeep(~cleanKeys=["remove", "andThis"], ())) |> toEqual(
      %raw(`
           {
             foo: {
               biz: 123,
               qux: [
                 true
               ],
               butNotThis: 'goodbye'
             }
           }
           `),
    )
  })

  test("should not remove NaN by default", () => {
    let jsObject = %raw(`
      {
        remi: 'hi there',
        biz: NaN,
      }
      `)

    expect(jsObject->CleanDeep.cleanDeep()) |> toEqual(
      %raw(`
           {
             remi: 'hi there',
             biz: NaN,
           }
           `),
    )
  })

  test("should remove NaN", () => {
    let jsObject = %raw(`
      {
        remi: 'hi there',
        biz: NaN,
      }
      `)

    expect(jsObject->CleanDeep.cleanDeep(~naNValues=true, ())) |> toEqual(
      %raw(`
           {
             remi: 'hi there',
           }
           `),
    )
  })
})
