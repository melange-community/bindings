open RescriptCleanDeep

Js.log("Demo of 'rescript-clean-deep'\n")

let s = %raw(` { emptystring: '', foo: 3, emptyobject: {} } `)

Js.log("No options:")
Js.log(CleanDeep.cleanDeep(s, ()))

Js.log("\nWith empty objects preserved:")
Js.log(s -> CleanDeep.cleanDeep(~emptyObjects=false, ()))

Js.log("\nWith empty objects and strings preserved:")
Js.log(CleanDeep.cleanDeep(s, ~emptyObjects=false, ~emptyStrings=false, ()))
