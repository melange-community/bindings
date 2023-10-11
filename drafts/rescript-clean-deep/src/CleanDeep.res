@deriving(abstract)
type cleanDeepOptions = {
  cleanKeys: array<string>,
  cleanValues: array<string>,
  emptyArrays: bool,
  emptyObjects: bool,
  emptyStrings: bool,
  nullValues: bool,
  undefinedValues: bool,
  @as("NaNValues") naNValues: bool,
}

@module
external cleanDeep: ('dirtyJsObject, cleanDeepOptions) => 'cleanedJsObject = "clean-deep"

let cleanDeep = (
  jsObject: 'dirtyJsObject,
  ~cleanKeys: array<string>=[],
  ~cleanValues: array<string>=[],
  ~emptyArrays: bool=true,
  ~emptyObjects: bool=true,
  ~emptyStrings: bool=true,
  ~nullValues: bool=true,
  ~undefinedValues: bool=true,
  ~naNValues: bool=false,
  (),
): 'cleanedJsObject => {
  let options = cleanDeepOptions(
    ~cleanKeys,
    ~cleanValues,
    ~emptyArrays,
    ~emptyObjects,
    ~emptyStrings,
    ~nullValues,
    ~undefinedValues,
    ~naNValues,
  )

  cleanDeep(jsObject, options)
}
